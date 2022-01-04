#include "dashboard.h"

QStringList Dashboard::monthValues = {
        "Gennaio",
        "Febbraio",
        "Marzo",
        "Aprile",
        "Maggio",
        "Giugno",
        "Luglio",
        "Agosto",
        "Settembre",
        "Ottobre",
        "Novembre",
        "Dicembre"
    };

Dashboard::Dashboard(SlidingStackedWidget* slidingStacked, QWidget* parent) : QWidget(parent),
        slidingStacked(slidingStacked), layout(new QVBoxLayout()), chartLayout(new QHBoxLayout()),
        modifyButton(new QPushButton(tr("Modify"))), controllButtonsLayout(new QHBoxLayout()),
        calendar(new QDateTimeEdit()), searchDate(new QPushButton(tr("Get Chart"))),
        chartViews(std::list<QChartView*>(3))
{
    CreateChartsView();
    CreateControlGuiComponent();
    CreateLayout();
    CreateConnections();
}

Dashboard::~Dashboard() {
    delete slidingStacked;
}

void Dashboard::CreateChartsView() {

    for(auto it = chartViews.begin(); it != chartViews.end(); ++it) {
        QVBoxLayout* chartBoxLayout = new QVBoxLayout();
        *it = new QChartView();
        chartBoxLayout->addWidget(*it);

        QVBoxLayout *infoLayout = new QVBoxLayout();
        QLabel *label = new QLabel();
        label->setAlignment(Qt::AlignHCenter);
        infoLayout->addWidget(label);

        SlidingWindow* infoText = new SlidingWindow("Info:");
        infoText->setContentLayout(*infoLayout);
        chartBoxLayout->addWidget(infoText);

        chartBoxLayout->addStrut(350);
        chartLayout->addLayout(chartBoxLayout);
    }
    chartLayout->addStrut(350);
}

void Dashboard::CreateControlGuiComponent() {
    calendar->setDisplayFormat("MM-yyyy");
    calendar->setCurrentSection(QDateTimeEdit::MonthSection);
    controllButtonsLayout->addWidget(calendar);
    controllButtonsLayout->addWidget(searchDate);
    controllButtonsLayout->addStrut(200);
}

void Dashboard::CreateLayout() {
    layout->addWidget(modifyButton);
    layout->addLayout(chartLayout);
    layout->addLayout(controllButtonsLayout);
}

void Dashboard::CreateConnections() {
    connect(modifyButton, SIGNAL(pressed()), slidingStacked, SLOT(slideInNext()));
    connect(searchDate, SIGNAL(pressed()), this->parentWidget()->parentWidget(), SLOT(showCharts()));
}

QVBoxLayout* Dashboard::Layout() const {
    return layout;
}

QString Dashboard::getCalendarDate() const {
    QDate date = calendar->date();
    return QString::number(date.year()) + monthValues.at(date.month()-1);
}

void Dashboard::setChartContent(std::list<QChart*> content) {
    std::list<QChartView*>::iterator itView = chartViews.begin();
    if(content.size() == 0) {
        for(; itView != chartViews.end(); ++itView) {
            (*itView)->setChart(new QChart());
        }
    } else {
        std::list<QChart*>::iterator itContent = content.begin();
        for(; itContent != content.end(); ++itView, ++itContent) {
            (*itView)->setChart(*itContent);
        }
    }
}
