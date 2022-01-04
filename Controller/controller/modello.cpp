#include "modello.h"

Modello::Modello() {}

std::list<Chart*> Modello::getChartsByDate(const QString& date) const {
    std::list<Chart*> charts;
    QString fileName = date + ".xml";
    if(File::Exist(fileName)) {
        File* file = new XmlFile(fileName);
        Obj* obj = file->FromFileToObj();
        std::shared_ptr<Obj> ptr = std::make_shared<Obj>(*obj);
        charts.push_back(new BarChart(ptr, date.toStdString()));
        charts.push_back(new PieChart(ptr, date.toStdString()));
        charts.push_back(new StackedHorizontalBarChart(ptr, date.toStdString()));
    }
    return charts;
}

std::list<Chart*> Modello::submitChart(const std::string& year, const std::string& month, int b2b, int b2c, int b2g, int cId) const {
    Obj* obj = new Obj(year, month, b2b, b2c, b2g, cId);
    QString fileName = QString::fromStdString(year) + QString::fromStdString(month) + ".xml";
    File* file = new XmlFile(fileName);
    file->FromObjToFile(obj);
    //return getChartsByDate(year, month);
}
