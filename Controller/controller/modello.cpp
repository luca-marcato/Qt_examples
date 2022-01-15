#include "modello.h"

Modello::Modello() : obj(nullptr) {
    charts.push_back(new BarChart());
    charts.push_back(new AreaChart());
    charts.push_back(new StackedHorizontalBarChart());
}

Modello::~Modello() {
    delete obj;
    while(!charts.empty()) {
        delete charts.back();
        charts.pop_back();
    }
}

std::vector<MyChart*> Modello::getChartsByDate(const QString& date) {
    QString fileName = date + ".xml";

    if(File::Exist(fileName)) {
        XmlFile* file = new XmlFile(fileName);
        file->setFile(fileName);
        try {
            delete obj;
            obj = file->FromFileToObj();
        } catch(XmlFile::XmlFileFormatError e) {
            std::cout<<e.message().toStdString();
            return std::vector<MyChart*>();
        }

        *static_cast<BarChart*>(charts.at(0)) = BarChart(obj, "BAR CHART");
        *static_cast<AreaChart*>(charts.at(1)) = AreaChart(obj, "AREA CHART");
        *static_cast<StackedHorizontalBarChart*>(charts.at(2)) = StackedHorizontalBarChart(obj, "STACKED HORIZONTAL BAR CAHART");

        delete file;
        return charts;
    }
    return std::vector<MyChart*>();
}

std::vector<QString> Modello::getChartsInfoByDate(const QString& date) {
    QString fileName = date + ".xml";

    infos.clear();
    if(File::Exist(fileName)) {
        File* file = new XmlFile(fileName);
        try {
             obj = file->FromFileToObj();
        } catch(XmlFile::XmlFileFormatError e) {
            return infos;
        }
        infos.push_back(QString::number(obj->getB2BValue()));
        infos.push_back(QString::number(obj->getB2CValue()));
        infos.push_back(QString::number(obj->getB2GValue()));
        infos.push_back(QString::number(obj->getB2BPercentage()));
        infos.push_back(QString::number(obj->getB2CPercentage()));
        infos.push_back(QString::number(obj->getB2GPercentage()));
        infos.push_back(QString::number(obj->getTotalValue()));
        infos.push_back(QString::number(obj->getTotalPercentage()));
        infos.push_back(QString::fromStdString(obj->getDate()));
        infos.push_back(QString::fromStdString(obj->getMonth()));
        infos.push_back(QString::fromStdString(obj->getYear()));

        delete file;
    }
    return infos;
}

QString Modello::submitChart(const std::string& year, const std::string& month, int b2b, int b2c, int b2g, bool isNew) const {
    QString fileName = QString::fromStdString(year) + QString::fromStdString(month) + ".xml";

    if((isNew && !File::Exist(fileName)) || (!isNew && File::Exist(fileName))) {
        Obj obj(year, month, b2b, b2c, b2g);
        if(obj.isValid()) {
            File* file = new XmlFile(fileName);
            file->FromObjToFile(&obj);
            delete file;
            return "Chart created.";
        }
    } else {
        return "This Chart already exist.";
    }
    return "Invalid Data - Chart not created.";
}

void Modello::insertFile(const QString path) const {
    File* aux = new XmlFile(path.mid(8));
    try {
        Obj* obj = aux->FromFileToObj();
        if(obj->isValid()) {
            QString fileName = QString::fromStdString(obj->getYear())+QString::fromStdString(obj->getMonth())+".xml";
            File* file = new XmlFile(fileName);
            file->FromObjToFile(obj);
            delete file;
        }
        delete obj;
    } catch(XmlFile::XmlFileFormatError e) {
        qDebug(e.message().toLatin1());
    }
    delete aux;
}
