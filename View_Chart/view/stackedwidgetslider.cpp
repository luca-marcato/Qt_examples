#include "stackedwidgetslider.h"
#include "spoiler.h"
#include "dropsitewindow.h"

/* The Constructor calls the subfunctions for creation of the sample application */
StackedWidgetSlider::StackedWidgetSlider(QWidget *parent)
    : QWidget(parent)
{
    animTime=500;
    createGuiControlComponents();
    createSlidingStackedWidget();
    createLayout();
    createConnections();
}

StackedWidgetSlider::~StackedWidgetSlider() {}

void StackedWidgetSlider::createGuiControlComponents() {
    int _min=500;
    int _max=1500;
    animTime=(_min+_max)>>1;

    sideBar = new QVBoxLayout;
    dashBoard = new QPushButton(tr("DashBoard"));
    addNew = new QPushButton(tr("Add New"));
    sideBar->addWidget(dashBoard);
    sideBar->addWidget(addNew);
    sideBar->insertStretch(2);
    sideBar->addStrut(200);
}

void StackedWidgetSlider::createSlidingStackedWidget() {
    slidingStacked = new SlidingStackedWidget(this);


    QFrame* dashBoardWidget = new QFrame;
    QVBoxLayout* dashBoardLayout = new QVBoxLayout;

    QHBoxLayout* editButtonsLayout = new QHBoxLayout;
    editButtonsLayout->addWidget(new QPushButton("Modifica"));

    editButtonsLayout->insertStretch(0);
    dashBoardLayout->addLayout(editButtonsLayout);

    QChartView *chartView;
    QHBoxLayout* chartLayout = new QHBoxLayout;
    for(int i = 0; i < 3; ++i) {
        QVBoxLayout* chartBoxLayout = new QVBoxLayout;

        QPieSeries *series = new QPieSeries();
        series->append("Jane", 1);
        series->append("Joe", 2);
        series->append("Andy", 3);
        series->append("Barbara", 4);
        series->append("Axel", 5);
    //![1]

    //![2]
        QPieSlice *slice = series->slices().at(1);
        slice->setExploded();
        slice->setLabelVisible();
        slice->setPen(QPen(Qt::darkGreen, 2));
        slice->setBrush(Qt::green);
    //![2]

    //![3]
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Simple piechart example");
        chart->legend()->hide();



        chartView = new QChartView(chart);
        chartBoxLayout->addWidget(chartView);

        QVBoxLayout *infoLayout = new QVBoxLayout;
        QLabel *label = new QLabel();
        label->setText("CHART");
        label->setAlignment(Qt::AlignHCenter);
        infoLayout->addWidget(label);

        Spoiler* spoiler = new Spoiler("Info:");
        spoiler->setContentLayout(*infoLayout);

        chartBoxLayout->addWidget(spoiler);

        chartBoxLayout->addStrut(350);
        chartLayout->addLayout(chartBoxLayout);
    }

    chartLayout->addStrut(350);
    dashBoardLayout->addLayout(chartLayout);

    QHBoxLayout* controllButtonsLayout = new QHBoxLayout;

    controllButtonsLayout->addWidget(new QPushButton("1"));
    controllButtonsLayout->addWidget(new QPushButton("2"));

    controllButtonsLayout->addStrut(200);
    dashBoardLayout->addLayout(controllButtonsLayout);
    dashBoardWidget->setLayout(dashBoardLayout);



    QFrame* addNewWidget = new QFrame;
    QVBoxLayout* addNewLayout = new QVBoxLayout;

    QVBoxLayout* formLayout = new QVBoxLayout;
    QLabel* title = new QLabel();
    title->setText("Chart Parameters:\n");
    formLayout->addWidget(title);

    QLabel* dateLabel = new QLabel();
    dateLabel->setText("Insert Date");
    formLayout->addWidget(dateLabel);
    QHBoxLayout* formRow1 = new QHBoxLayout;
    QStringList monthValues = { "Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre" };
    QComboBox* months = new QComboBox();
    months->addItems(monthValues);
    QSpinBox* years = new QSpinBox();
    years->setRange(1900, 2300);
    years->setValue(2022);
    formRow1->addWidget(months);
    formRow1->addWidget(years);
    formLayout->addLayout(formRow1);

    QLabel* valuesLabel = new QLabel();
    valuesLabel->setText("Insert Values");
    formLayout->addWidget(valuesLabel);
    QHBoxLayout* formRow2 = new QHBoxLayout;
    QLabel* B2BLabel = new QLabel();
    B2BLabel->setText("B2B: ");
    QSpinBox* b2b = new QSpinBox();
    b2b->setRange(0, 2147483647); // INT max value = +2147483647
    formRow2->addWidget(B2BLabel);
    formRow2->addWidget(b2b);
    formLayout->addLayout(formRow2);

    QHBoxLayout* formRow3 = new QHBoxLayout;
    QLabel* B2CLabel = new QLabel();
    B2CLabel->setText("B2C: ");
    QSpinBox* b2c = new QSpinBox();
    b2c->setRange(0, 2147483647); // INT max value = +2147483647
    formRow3->addWidget(B2CLabel);
    formRow3->addWidget(b2c);
    formLayout->addLayout(formRow3);

    QHBoxLayout* formRow4 = new QHBoxLayout;
    QLabel* B2GLabel = new QLabel();
    B2GLabel->setText("B2G: ");
    QSpinBox* b2g = new QSpinBox();
    b2b->setRange(0, 2147483647); // INT max value = +2147483647
    formRow4->addWidget(B2GLabel);
    formRow4->addWidget(b2g);
    formLayout->addLayout(formRow4);

    QPushButton* sumbit = new QPushButton("Conferma");
    formLayout->addWidget(sumbit, Qt::AlignRight);

    DropSiteWindow* window = new DropSiteWindow();

    formLayout->insertStretch(formLayout->count());
    addNewLayout->addLayout(formLayout);
    addNewLayout->addWidget(window);
    addNewWidget->setLayout(addNewLayout);

    slidingStacked->addWidget(dashBoardWidget);
    slidingStacked->addWidget(addNewWidget);
    slidingStacked->setSpeed(animTime);
    slidingStacked->setWrap(false);
    slidingStacked->setVerticalMode(true);
}

void StackedWidgetSlider::createLayout() {
    mainLayout=new QHBoxLayout();

    mainLayout->addLayout(sideBar);
    mainLayout->addWidget(slidingStacked);
}

void StackedWidgetSlider::createConnections() {
    QObject::connect(dashBoard,SIGNAL(pressed()),slidingStacked,SLOT(slideInPrev()));
    QObject::connect(addNew,SIGNAL(pressed()),slidingStacked,SLOT(slideInNext()));
}

QHBoxLayout* StackedWidgetSlider::layout() const {
    return mainLayout;
}

