#ifndef CHART_H
#define CHART_H

#include <memory>
#include <QtCharts/QChartView>
#include <QtCharts/QLegend>

#include "obj.h"
#include <QDebug>

using namespace QtCharts;

class MyChart
{
private:
    std::string title;
    bool custom;
protected:
    QChart *chart;
    Obj* obj;
    MyChart(Obj*, const std::string&, bool);
    MyChart& operator =(const MyChart&);
    virtual void addSeries() const = 0;
public:
    virtual ~MyChart();
    virtual QChart* show() const;

};

#endif // CHART_H
