#include "viewer.h"

Viewer::Viewer(QWidget *parent) : QWidget(parent), window(new StackedWidgetSlider(this)),
        controller(new Controller(this))
{
    setLayout(window->Layout());
}

Viewer::~Viewer() {
    delete window;
    delete controller;
}

void Viewer::showCharts() {
    QString date = window->getChartDate();
    std::list<QChart*> charts = controller->onGetCharts(date);
    window->setChartView(charts);
}
