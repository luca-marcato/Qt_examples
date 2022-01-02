#ifndef MODELLO_H
#define MODELLO_H

#include<list>
#include "barchart.h"
#include "piechart.h"
#include "stacked_horizontal_barchart.h"
#include "xmlfile.h"

class Modello
{
private:
File* file;
Obj* obj;
std::list<Chart*> charts;
public:
    Modello();
    //get Charts by date
    std::list<Chart*> getChartsByDate(const std::string&, const std::string&);
    //add new & update
    std::list<Chart*> submitChart(const std::string&, const std::string&, int, int, int, int);
};

#endif // MODEL_H
