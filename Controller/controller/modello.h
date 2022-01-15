#ifndef MODELLO_H
#define MODELLO_H



#include<QDebug>
#include "barchart.h"
#include "piechart.h"
#include "stacked_horizontal_barchart.h"
#include "areachart.h"
#include "xmlfile.h"

class Modello
{
private:
    Obj* obj;
    std::vector<MyChart*> charts;
    std::vector<QString> infos;
public:
    Modello();
    ~Modello();

    std::vector<MyChart*> getChartsByDate(const QString&);

    std::vector<QString> getChartsInfoByDate(const QString&);

    QString submitChart(const std::string&, const std::string&, int, int, int, bool) const;

    void insertFile(const QString) const;
};

#endif // MODEL_H
