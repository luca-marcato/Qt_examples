#include "modello.h"

Modello::Modello() {}

std::list<Chart*> Modello::getChartsByDate(const std::string& year, const std::string& month) {

    QString fileName = QString::fromStdString(year) + QString::fromStdString(month) + ".xml";
    if(File::SearchFile(fileName)) {
        delete file;
        file = new XmlFile(fileName);
        delete obj;
        obj = file->FromFileToObj();
        for(auto it = charts.begin(); it != charts.end(); ++it) {
            delete *it;
        }
        std::shared_ptr<Obj> ptr = std::make_shared<Obj>(*obj);
        charts.push_back(new BarChart(ptr, month + " " + year));
        charts.push_back(new PieChart(ptr, month + " " + year));
        charts.push_back(new StackedHorizontalBarChart(ptr, month + " " + year));
    }
    return charts;
}

std::list<Chart*> Modello::submitChart(const std::string& year, const std::string& month, int b2b, int b2c, int b2g, int cId) {
    Obj* obj = new Obj(year, month, b2b, b2c, b2g, cId);
    QString fileName = QString::fromStdString(year) + QString::fromStdString(month) + ".xml";
    File* file = new XmlFile(fileName);
    file->FromObjToFile(obj);
    delete obj;
    delete file;
    return getChartsByDate(year, month);
}
