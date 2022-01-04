#include "controller.h"

Controller::Controller(Viewer* v) : model(new Modello()), view(v)
{}

Controller::~Controller() {
    delete model;
    delete view;
}

std::list<QChart*> Controller::onGetCharts(const QString& date) const {
    std::list<Chart*> aux = model->getChartsByDate(date);
    std::list<QChart*> list;
    for(std::list<Chart*>::const_iterator cit = aux.begin(); cit != aux.end(); ++cit) {
        list.push_back((*cit)->show());
    }
    return list;
}
