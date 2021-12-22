#include "viewer.h"
#include "spoiler.h"

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
        chartView = new QChartView(new QChart());
        chartBoxLayout->addWidget(chartView);

        QVBoxLayout *infoLayout = new QVBoxLayout;
        QLabel *label = new QLabel();
        label->setText("CHARTa");
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

