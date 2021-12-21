#include "viewer.h"



Viewer::Viewer(QWidget *parent) : QWidget(parent) {
    QHBoxLayout* mainLayout = new QHBoxLayout;

    QVBoxLayout* sideBar = new QVBoxLayout();

    sideBar->addWidget(new QPushButton("DashBoard"));
    sideBar->addWidget(new QPushButton("Add New"));
    sideBar->addWidget(new QPushButton("3"));
    sideBar->addWidget(new QPushButton("4"));

    sideBar->insertStretch(4);
    sideBar->addStrut(200);
    mainLayout->addLayout(sideBar);

    QWidget *firstPageWidget = new QWidget;
    QWidget *secondPageWidget = new QWidget;
    QWidget *thirdPageWidget = new QWidget;

    QStackedLayout* pagesLayout = new QStackedLayout;
    pagesLayout->addWidget(firstPageWidget);
    pagesLayout->addWidget(secondPageWidget);
    pagesLayout->addWidget(thirdPageWidget);

    mainLayout->addLayout(pagesLayout);

    setLayout(mainLayout);
}
