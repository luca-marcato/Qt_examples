#include "viewer.h"
#include "spoiler.h"
#include "slidingstackedwidget.h"

Viewer::Viewer(QWidget *parent) : QWidget(parent) {
    QHBoxLayout* mainLayout = new QHBoxLayout;

    QVBoxLayout* sideBarLayout = new QVBoxLayout;

    sideBarLayout->addWidget(new QPushButton("Add New"));


    sideBarLayout->insertStretch(1);
    sideBarLayout->addStrut(200);

    mainLayout->addLayout(sideBarLayout);

    QVBoxLayout* dashBoardLayout = new QVBoxLayout;

    QHBoxLayout* editButtonsLayout = new QHBoxLayout;
    editButtonsLayout->addWidget(new QPushButton("1"));
    editButtonsLayout->addWidget(new QPushButton("2"));

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

    mainLayout->addLayout(dashBoardLayout);

    setLayout(mainLayout);


}









/**

*/














/**

    QSpinBox *spinBox = new QSpinBox;
    QSlider *slider = new QSlider(Qt::Horizontal);
    spinBox->setRange(0, 130);
    slider->setRange(0, 130);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)),slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)),spinBox, SLOT(setValue(int)));
    spinBox->setValue(35);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(spinBox);
    layout->addWidget(slider);
    sideBarLayout->addLayout(layout);


*/

