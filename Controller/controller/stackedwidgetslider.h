#ifndef STACKEDWIDGETSLIDER_H
#define STACKEDWIDGETSLIDER_H

#include "slidingstackedwidget.h"
#include "dashboard.h"
#include "addnew.h"

class StackedWidgetSlider : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *sideBar;
    QHBoxLayout *mainLayout;
    QPushButton *dashBoardButton;
    QPushButton *addNewButton;
    SlidingStackedWidget *slidingStacked;
    Dashboard* dashBoardWidget;
    AddNew* addNewWidget;
    int animTime;

    void createGuiControlComponents();
    void createSlidingStackedWidget();
    void createLayout();
    void createConnections();
public:
    StackedWidgetSlider(int =1000, QWidget *parent = 0);
    ~StackedWidgetSlider();

    QHBoxLayout* Layout() const;
};

#endif // STACKEDWIDGETSLIDER_H
