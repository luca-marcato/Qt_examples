#include "controller.h"

Controller::Controller(Viewer* v) : model(new Modello()), view(v)
{

}

Controller::~Controller() {
    delete model;
}

std::list<QChart*> Controller::getChartsView(const QString& date) const {
    std::vector<MyChart*> aux = model->getChartsByDate(date);
    std::list<QChart*> list;
    for(std::vector<MyChart*>::const_iterator cit = aux.begin(); cit != aux.end(); ++cit) {
        list.push_back((*cit)->show());
    }
    return list;
}

std::vector<QString> Controller::getChartsInfo(const QString& date) const {
    return model->getChartsInfoByDate(date);
}

QString Controller::insertNewChartData(std::vector<QString> objData, bool isNew) const {
    return model->submitChart(objData.at(0).toStdString(), objData.at(1).toStdString(), objData.at(2).toInt(), objData.at(3).toInt(),objData.at(4).toInt(), isNew);
}

void Controller::insertNewFiles(const QString files) const {
    QStringList pathFiles = files.split("|");
    for(QStringList::const_iterator cit = pathFiles.begin(); cit != pathFiles.end(); ++cit) {
       qDebug() << *cit;
        if(*cit != "") model->insertFile(*cit);
    }
}

