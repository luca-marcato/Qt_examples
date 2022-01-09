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

void Viewer::addNewChart() const {
    std::vector<QString> data = window->getAddNewFormData();
    controller->insertNewChartData(data, true);
}

void Viewer::updateChart() {
    std::vector<QString> data = window->getUpdateFormData();
    controller->insertNewChartData(data, false);
    showCharts();
}
