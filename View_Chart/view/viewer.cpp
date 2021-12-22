#include "viewer.h"
#include "sidebar.h"

Viewer::Viewer(QWidget *parent) : QWidget(parent) {
    QHBoxLayout* mainLayout = new QHBoxLayout;

    QVBoxLayout* sideBarLayout = new QVBoxLayout;

    QStackedLayout* pagesLayout = new QStackedLayout;

    SideBar* sideBarWidget = new SideBar;
    sideBarWidget->addButton(new QPushButton("DashBoard"));
    sideBarWidget->addButton(new QPushButton("Add New"));

    for(int i = 0; i < sideBarWidget->countButton(); ++i) {
        connect(sideBarWidget->buttonAt(i), sideBarWidget->buttonAt(i)->onPressed(),
                    pagesLayout, &QStackedLayout::setCurrentIndex);

        sideBarLayout->addWidget(sideBarWidget->buttonAt(i));
    }

    sideBarLayout->insertStretch(sideBarWidget->countButton());
    sideBarLayout->addStrut(200);

    mainLayout->addLayout(sideBarLayout);

    QFrame* dashBoardFrame = new QFrame;
    QVBoxLayout* dashBoardLayout = new QVBoxLayout;

    QHBoxLayout* editButtonsLayout = new QHBoxLayout;
    editButtonsLayout->addWidget(new QPushButton("1"));
    editButtonsLayout->addWidget(new QPushButton("2"));

    dashBoardLayout->addLayout(editButtonsLayout);

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
        chartButtonsLayout->addStrut(50);
        chartBoxLayout->addLayout(chartButtonsLayout);

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

    dashBoardFrame->setLayout(dashBoardLayout);
    pagesLayout->addWidget(dashBoardFrame);

    mainLayout->addLayout(pagesLayout);

    setLayout(mainLayout);
}

