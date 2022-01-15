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

void Viewer::showCharts(QString date) {
    if(date.isEmpty()) date = window->getChartDate();
    std::list<QChart*> charts = controller->getChartsView(date);
    std::vector<QString> infos = controller->getChartsInfo(date);
    window->setChartInfo(infos);
    window->setChartView(charts);
}
void Viewer::addNewChart() {
    std::vector<QString> data = window->getAddNewFormData();
    QString text = controller->insertNewChartData(data, true);
    window->setAddNewChartDataMsg(text);
    showCharts(data.at(0)+data.at(1));
}

void Viewer::updateChart() {
    std::vector<QString> data = window->getUpdateFormData();
    controller->insertNewChartData(data, false);
    showCharts();
}

void Viewer::addNewFiles() {
    const QString files = window->getFilesPath();
    controller->insertNewFiles(files);
}
