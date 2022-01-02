#include "dashboard.h"

Dashboard::Dashboard(SlidingStackedWidget* slidingStacked, QWidget* parent) : QWidget(parent),
        slidingStacked(slidingStacked), layout(new QVBoxLayout()), chartLayout(new QHBoxLayout()),
        modifyButton(new QPushButton(tr("Modify"))), controllButtonsLayout(new QHBoxLayout()),
        calendar(new QDateTimeEdit()), searchDate(new QPushButton(tr("Get Chart")))
{
    CreateChartsView();
    CreateControlGuiComponent();
    CreateLayout();
    CreateConnections();
}

Dashboard::~Dashboard() {}

void Dashboard::CreateChartsView() {
    for(int i = 0; i < 3; ++i) {
        QVBoxLayout* chartBoxLayout = new QVBoxLayout();
        QChartView *chartView = new QChartView();
        chartBoxLayout->addWidget(chartView);

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
}

QVBoxLayout* Dashboard::Layout() const {
    return layout;
}
