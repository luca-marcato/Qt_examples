#ifndef STACKEDWIDGETSLIDER_H
#define STACKEDWIDGETSLIDER_H

#include <QListWidget>
#include <QPushButton>
#include <QBoxLayout>

#include "slidingstackedwidget.h"

class StackedWidgetSlider : QWidget
{
    Q_OBJECT
public:
    StackedWidgetSlider(QWidget *parent = 0);
    void createGuiControlComponents();
    void createMainLayout();
    void createSubSlidingWidgets();
    void createConnections();
    void createSlidingStackedWidget();
    SlidingStackedWidget* getSlidingStackedWidget() const;

    QPushButton *dashBoard;
    QPushButton *addNew;

    SlidingStackedWidget *slidingStacked;
    QVBoxLayout *mainLayout;
    QGridLayout *controlPaneLayout;
    QWidget *centralWidget;
    QWidget *slideWidget1;
    QWidget *slideWidget2;

    int animTime;
};

#endif // STACKEDWIDGETSLIDER_H
