#ifndef STACKEDWIDGETSLIDER_H
#define STACKEDWIDGETSLIDER_H

#include <QListWidget>
#include <QPushButton>
#include <QBoxLayout>
#include <QtCharts>
#include <QCalendarWidget>

#include "slidingstackedwidget.h"


class StackedWidgetSlider : QWidget
{
    Q_OBJECT
public:
    StackedWidgetSlider(QWidget *parent = 0);
    virtual ~StackedWidgetSlider();
    void createGuiControlComponents();
    void createSlidingStackedWidget();
    void createLayout();
    void createConnections();
    QHBoxLayout* layout() const;

    QVBoxLayout *sideBar;
    QPushButton *dashBoard;
    QPushButton *addNew;

    SlidingStackedWidget *slidingStacked;
    QHBoxLayout *mainLayout;


    QGridLayout *controlPaneLayout;

    QBoxLayout *slideWidgetLayout1;
    QBoxLayout *slideWidgetLayout2;

    int animTime;
};

#endif // STACKEDWIDGETSLIDER_H
