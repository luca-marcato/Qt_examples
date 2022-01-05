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
    std::list<QChart*> charts = controller->getChartsView(date);
    std::vector<QString> infos = controller->getChartsInfo(date);
    window->setChartInfo(infos);
    window->setChartView(charts);
}

void Viewer::addNewChart() {
    std::vector<QString> data = window->getFormData();
    controller->addNewChart(data);
}
