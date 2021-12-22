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
    QVBoxLayout* dashBoardLayout = new QVBoxLayout;

    QChartView *chartView;
    QHBoxLayout* chartLayout = new QHBoxLayout;
    for(int i = 0; i < 3; ++i) {
        QVBoxLayout* chartBoxLayout = new QVBoxLayout;
        chartView = new QChartView(new QChart());
        chartBoxLayout->addWidget(chartView);

        QHBoxLayout* chartButtonsLayout = new QHBoxLayout;
        chartButtonsLayout->addWidget(new QPushButton("DashBoard"));
        chartButtonsLayout->addWidget(new QPushButton("Add New"));
        chartButtonsLayout->addWidget(new QPushButton("3"));
        chartBoxLayout->addLayout(chartButtonsLayout);

        chartLayout->addLayout(chartBoxLayout);
    }
    dashBoardLayout->addLayout(chartLayout);

    QHBoxLayout* editButtonsLayout = new QHBoxLayout;
    editButtonsLayout->addWidget(new QPushButton("1"));
    editButtonsLayout->addWidget(new QPushButton("2"));
    editButtonsLayout->insertStretch(0);

    dashBoardLayout->addLayout(editButtonsLayout);

    QHBoxLayout* controllButtonsLayout = new QHBoxLayout;
    controllButtonsLayout->addWidget(new QPushButton("1"));
    controllButtonsLayout->addWidget(new QPushButton("2"));

    dashBoardLayout->addLayout(controllButtonsLayout);

    dashBoardFrame->setLayout(dashBoardLayout);
    pagesLayout->addWidget(dashBoardFrame);

    mainLayout->addLayout(pagesLayout);

    setLayout(mainLayout);
}

