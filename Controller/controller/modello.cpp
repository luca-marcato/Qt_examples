#include "modello.h"

Modello::Modello() {}

std::list<Chart*> Modello::getChartsByDate(const QString& date) const {
    std::list<Chart*> charts;
    QString fileName = date + ".xml";
    if(File::Exist(fileName)) {
        File* file = new XmlFile(fileName);
        Obj* obj = file->FromFileToObj();
        std::shared_ptr<Obj> ptr = std::make_shared<Obj>(*obj);
        charts.push_front(new StackedHorizontalBarChart(ptr, date.toStdString()));
        charts.push_front(new PieChart(ptr, date.toStdString()));
        charts.push_front(new BarChart(ptr, date.toStdString()));
    }
    return charts;
}

std::vector<QString> Modello::getChartsInfoByDate(const QString& date) const {
    std::vector<QString> infos;
    QString fileName = date + ".xml";
    if(File::Exist(fileName)) {
        File* file = new XmlFile(fileName);
        Obj* obj = file->FromFileToObj();
        infos.push_back(QString::number(obj->getB2BVal()));
        infos.push_back(QString::number(obj->getB2CVal()));
        infos.push_back(QString::number(obj->getB2GVal()));
        infos.push_back(QString::number(obj->getB2BPercent()));
        infos.push_back(QString::number(obj->getB2CPercent()));
        infos.push_back(QString::number(obj->getB2GPercent()));
        infos.push_back(QString::number(obj->getTotalValue()));
        infos.push_back(QString::number(obj->getTotalPercent()));
        infos.push_back(QString::fromStdString(obj->getDate()));
    }
    return infos;
}

void Modello::submitChart(const std::string& year, const std::string& month, int b2b, int b2c, int b2g) const {
    Obj* obj = new Obj(year, month, b2b, b2c, b2g);
    QString fileName = QString::fromStdString(year) + QString::fromStdString(month) + ".xml";
    File* file = new XmlFile(fileName);
    file->FromObjToFile(obj);
}
