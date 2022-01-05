#include "controller.h"

Controller::Controller(Viewer* v) : model(new Modello()), view(v)
{}

Controller::~Controller() {
    delete model;
    delete view;
}

std::list<QChart*> Controller::getChartsView(const QString& date) const {
    std::list<Chart*> aux = model->getChartsByDate(date);
    std::list<QChart*> list;
    for(std::list<Chart*>::const_iterator cit = aux.begin(); cit != aux.end(); ++cit) {
        list.push_back((*cit)->show());
    }
    return list;
}

std::vector<QString> Controller::getChartsInfo(const QString& date) const {
    return model->getChartsInfoByDate(date);
}

void Controller::addNewChart(std::vector<QString> objData) const {
    model->submitChart(objData.at(0).toStdString(), objData.at(1).toStdString(), objData.at(2).toInt(), objData.at(3).toInt(),objData.at(4).toInt());
}
