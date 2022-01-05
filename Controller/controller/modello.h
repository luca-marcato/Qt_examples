#ifndef MODELLO_H
#define MODELLO_H

#include<list>
#include "barchart.h"
#include "piechart.h"
#include "stacked_horizontal_barchart.h"
#include "xmlfile.h"

class Modello
{
public:
    Modello();
    //get Charts by date
    std::list<Chart*> getChartsByDate(const QString&) const;
    //get Charts Info by date
    std::vector<QString> getChartsInfoByDate(const QString&) const;
    //add new & update
    void submitChart(const std::string&, const std::string&, int, int, int) const;
};

#endif // MODEL_H
