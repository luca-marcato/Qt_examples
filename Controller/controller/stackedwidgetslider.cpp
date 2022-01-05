#include "stackedwidgetslider.h"

StackedWidgetSlider::StackedWidgetSlider(QWidget *parent, int time)
    : QWidget(parent), sideBar(new QVBoxLayout()), mainLayout(new QHBoxLayout()),
      dashBoardButton(new QPushButton(tr("DashBoard"))), addNewButton(new QPushButton(tr("Add New"))),
      slidingStacked(new SlidingStackedWidget()), dashBoardWidget(new Dashboard(slidingStacked, this)),
      addNewWidget(new AddNew(this)), animTime(time)
{
    createGuiControlComponents();
    createSlidingStackedWidget();
    createLayout();
    createConnections();
}

StackedWidgetSlider::~StackedWidgetSlider() {
    delete slidingStacked;
    delete dashBoardWidget;
    delete addNewWidget;
}

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

QString StackedWidgetSlider::getChartDate() const {
    return dashBoardWidget->getCalendarDate();
}

std::vector<QString> StackedWidgetSlider::getFormData() const {
    return addNewWidget->getFormContent();
}

void StackedWidgetSlider::setChartView(std::list<QChart*> list) {
    dashBoardWidget->setChartContent(list);
}

void StackedWidgetSlider::setChartInfo(std::vector<QString> vector) {
    dashBoardWidget->setChartInfoContent(vector);
}
