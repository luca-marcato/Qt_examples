#include "dashboard.h"

const QStringList Dashboard::monthValues = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "Dicember"
    };

Dashboard::Dashboard(SlidingStackedWidget* slidingStacked, QWidget* parent) : QWidget(parent),
        slidingStacked(slidingStacked), layout(new QVBoxLayout()), chartLayout(new QHBoxLayout()),
        modifyButton(new QPushButton(tr("Modify"))), controllButtonsLayout(new QHBoxLayout()),
        calendar(new QDateTimeEdit()), searchDate(new QPushButton(tr("Get Chart"))),
        chartViews(std::list<QChartView*>(3)), chartInfo(std::vector<SlidingWindow*>(3))
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
    auto itChart = chartViews.begin();
    auto itInfo = chartInfo.begin();
    for(; itChart != chartViews.end() && itInfo != chartInfo.end(); ++itChart, ++itInfo) {
        QVBoxLayout* chartBoxLayout = new QVBoxLayout();
        *itChart = new QChartView();
        chartBoxLayout->addWidget(*itChart);

        *itInfo = new SlidingWindow("Info:");
        chartBoxLayout->addWidget(*itInfo);
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

void Dashboard::setChartInfoContent(std::vector<QString> content) {
    if(content.size() != 0) {
        QVBoxLayout *info1 = new QVBoxLayout();
        QVBoxLayout *info2 = new QVBoxLayout();
        QVBoxLayout *info3 = new QVBoxLayout();

        QLabel* title1 = new QLabel();
        title1->setText("Chart: "+content.at(8));
        QLabel* title2 = new QLabel();
        title2->setText("Chart: "+content.at(8));
        QLabel* title3 = new QLabel();
        title3->setText("Chart: "+content.at(8));

        QLabel* b2b1 = new QLabel();
        b2b1->setText("B2B: "+content.at(0));
        QLabel* b2c1 = new QLabel();
        b2c1->setText("B2C: "+content.at(1));
        QLabel* b2g1 = new QLabel();
        b2g1->setText("B2G: "+content.at(2));

        QLabel* b2b2 = new QLabel();
        b2b2->setText("B2B: "+content.at(0));
        QLabel* b2c2 = new QLabel();
        b2c2->setText("B2C: "+content.at(1));
        QLabel* b2g2 = new QLabel();
        b2g2->setText("B2G: "+content.at(2));

        QLabel* totalValue1 = new QLabel();
        totalValue1->setText("\nTotal Value: "+content.at(6));
        QLabel* totalValue2 = new QLabel();
        totalValue2->setText("\nTotal Value: "+content.at(7)+"%");
        QLabel* totalValue3 = new QLabel();
        totalValue3->setText("\nTotal Value: "+content.at(6));

        QLabel* b2bPercent = new QLabel();
        b2bPercent->setText("B2B: "+content.at(3)+"%");
        QLabel* b2cPercent = new QLabel();
        b2cPercent->setText("B2C: "+content.at(4)+"%");
        QLabel* b2gPercent = new QLabel();
        b2gPercent->setText("B2G: "+content.at(5)+"%");

        info1->addWidget(title1, Qt::AlignHCenter);
        info1->addWidget(b2b1);
        info1->addWidget(b2c1);
        info1->addWidget(b2g1);
        info1->addWidget(totalValue1);

        info2->addWidget(title2, Qt::AlignHCenter);
        info2->addWidget(b2bPercent);
        info2->addWidget(b2cPercent);
        info2->addWidget(b2gPercent);
        info2->addWidget(totalValue2);

        info3->addWidget(title3, Qt::AlignHCenter);
        info3->addWidget(b2b2);
        info3->addWidget(b2c2);
        info3->addWidget(b2g2);
        info3->addWidget(totalValue3);

        chartInfo.at(0)->setContentLayout(info1);
        chartInfo.at(1)->setContentLayout(info2);
        chartInfo.at(2)->setContentLayout(info3);
    } else {
        QVBoxLayout *noChart1 = new QVBoxLayout();
        QVBoxLayout *noChart2 = new QVBoxLayout();
        QVBoxLayout *noChart3 = new QVBoxLayout();

        QLabel* label1 = new QLabel();
        label1->setText("No Data Aviable");
        noChart1->addWidget(label1, Qt::AlignHCenter);
        QLabel* label2 = new QLabel();
        label2->setText("No Data Aviable");
        noChart2->addWidget(label2, Qt::AlignHCenter);
        QLabel* label3 = new QLabel();
        label3->setText("No Data Aviable");
        noChart3->addWidget(label3, Qt::AlignHCenter);

        chartInfo.at(0)->setContentLayout(noChart1);
        chartInfo.at(1)->setContentLayout(noChart2);
        chartInfo.at(2)->setContentLayout(noChart3);
    }

}
