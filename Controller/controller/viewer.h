#ifndef VIEWER_H
#define VIEWER_H

#include <QWidget>
#include <iostream>

#include "stackedwidgetslider.h"
#include "controller.h"


class Viewer : public QWidget {
    Q_OBJECT
private:
    StackedWidgetSlider* window;
    Controller* controller;
public:
    Viewer(QWidget *parent =nullptr);
    ~Viewer();

public slots:
    void showCharts();
};

#endif // VIEWER_H
