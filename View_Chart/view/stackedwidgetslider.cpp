#include "stackedwidgetslider.h"


/* The Constructor calls the subfunctions for creation of the sample application */
StackedWidgetSlider::StackedWidgetSlider(QWidget *parent)
    : QWidget(parent)
{
    animTime=500;
    createGuiControlComponents();
    createSubSlidingWidgets();
    createSlidingStackedWidget();
    createMainLayout();
    createConnections();
}

StackedWidgetSlider::~StackedWidgetSlider() {}

void StackedWidgetSlider::createGuiControlComponents() {
    int _min=500;
    int _max=1500;
    animTime=(_min+_max)>>1;

    dashBoard = new QPushButton(tr("DashBoard"));
    addNew = new QPushButton(tr("Add New"));

}

void StackedWidgetSlider::createMainLayout() {
    centralWidget=new QWidget(this);
    mainLayout=new QVBoxLayout();
    centralWidget->setLayout(mainLayout);
    controlPaneLayout=new QGridLayout();
    mainLayout->addWidget(slidingStacked);
    mainLayout->addLayout(controlPaneLayout);
    int row;
    row=1;
    controlPaneLayout->addWidget(dashBoard,row,1,1,1);
    controlPaneLayout->addWidget(addNew,row,2,1,1);

    this->setCentralWidget(centralWidget);
}

void StackedWidgetSlider::createSubSlidingWidgets() {
    slideWidget1 = new QWidget();
    slideWidget2 = new QWidget();
    QVBoxLayout *slideWidget1layout=new QVBoxLayout();
    slideWidget1->setLayout(slideWidget1layout);
    QVBoxLayout *slideWidget2layout=new QVBoxLayout();
    slideWidget2->setLayout(slideWidget2layout);

    QPushButton *b11=new QPushButton("Qt");
    slideWidget1layout->addWidget(b11);
    QPushButton *b12=new QPushButton("is cool !");
    slideWidget1layout->addWidget(b12);

    QPushButton *b21=new QPushButton("Cool");
    slideWidget2layout->addWidget(b21);
    QPushButton *b22=new QPushButton("is Qt !");
    slideWidget2layout->addWidget(b22);
}

void StackedWidgetSlider::createSlidingStackedWidget() {
    slidingStacked = new SlidingStackedWidget(this);
    slidingStacked->addWidget(slideWidget1);
    slidingStacked->addWidget(slideWidget2);
    slidingStacked->setSpeed(animTime);
    slidingStacked->setWrap(true);
    slidingStacked->setVerticalMode(true);
}

void StackedWidgetSlider::createConnections() {
    QObject::connect(dashBoard,SIGNAL(pressed()),slidingStacked,SLOT(slideInPrev()));
    QObject::connect(addNew,SIGNAL(pressed()),slidingStacked,SLOT(slideInNext()));
}
