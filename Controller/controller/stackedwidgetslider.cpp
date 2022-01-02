#include "stackedwidgetslider.h"

StackedWidgetSlider::StackedWidgetSlider(int animTime, QWidget *parent)
    : QWidget(parent), sideBar(new QVBoxLayout()), mainLayout(new QHBoxLayout()),
      dashBoardButton(new QPushButton(tr("DashBoard"))), addNewButton(new QPushButton(tr("Add New"))),
      slidingStacked(new SlidingStackedWidget()), dashBoardWidget(new Dashboard(slidingStacked)),
      addNewWidget(new AddNew()), animTime(animTime)
{
    createGuiControlComponents();
    createSlidingStackedWidget();
    createLayout();
    createConnections();
}

StackedWidgetSlider::~StackedWidgetSlider() {}

void StackedWidgetSlider::createGuiControlComponents() {
    sideBar->addWidget(dashBoardButton);
    sideBar->addWidget(addNewButton);
    sideBar->insertStretch(2);
    sideBar->addStrut(200);
}

void StackedWidgetSlider::createSlidingStackedWidget() {
    QFrame* dashBoardFrame = new QFrame();
    dashBoardFrame->setLayout(dashBoardWidget->Layout());

    QFrame* addNewFrame = new QFrame();
    addNewFrame->setLayout(addNewWidget->Layout());

    slidingStacked->addWidget(dashBoardFrame);
    slidingStacked->addWidget(addNewFrame);
    slidingStacked->setSpeed(animTime);
}

void StackedWidgetSlider::createLayout() {
    mainLayout->addLayout(sideBar);
    mainLayout->addWidget(slidingStacked);
}

void StackedWidgetSlider::createConnections() {
    QObject::connect(dashBoardButton,SIGNAL(pressed()),slidingStacked,SLOT(slideInPrev()));
    QObject::connect(addNewButton,SIGNAL(pressed()),slidingStacked,SLOT(slideInNext()));
}

QHBoxLayout* StackedWidgetSlider::Layout() const {
    return mainLayout;
}

