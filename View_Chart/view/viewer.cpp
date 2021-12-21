#include "viewer.h"

Viewer::Viewer(QWidget *parent) : QWidget(parent) {
    QHBoxLayout* mainLayout = new QHBoxLayout;

    QVBoxLayout* sideBarLayout = new QVBoxLayout;


    sideBarLayout->addWidget(new QPushButton("DashBoard"));
    sideBarLayout->addWidget(new QPushButton("Add New"));
    sideBarLayout->addWidget(new QPushButton("3"));
    sideBarLayout->addWidget(new QPushButton("4"));

    sideBarLayout->insertStretch(4);
    sideBarLayout->addStrut(200);
    mainLayout->addLayout(sideBarLayout);

    QStackedLayout* pagesLayout = new QStackedLayout;

    QFrame* dashBoardFrame = new QFrame;
    QHBoxLayout* dashBoardLayout = new QHBoxLayout;

    QChartView *chartView;
    for(int i = 0; i < 3; ++i) {
        QVBoxLayout* chartLayout = new QVBoxLayout;
        chartView = new QChartView(new QChart());
        chartLayout->addWidget(chartView);

        QHBoxLayout* buttonsLayout = new QHBoxLayout;
        buttonsLayout->addWidget(new QPushButton("DashBoard"));
        buttonsLayout->addWidget(new QPushButton("Add New"));
        buttonsLayout->addWidget(new QPushButton("3"));
        chartLayout->addLayout(buttonsLayout);

        dashBoardLayout->addLayout(chartLayout);
    }
    dashBoardFrame->setLayout(dashBoardLayout);
    pagesLayout->addWidget(dashBoardFrame);

    mainLayout->addLayout(pagesLayout);

    setLayout(mainLayout);
}

