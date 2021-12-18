#ifndef CHART_H
#define CHART_H

#include <QtCharts/QChartView>
#include <QtCharts/QLegend>

#include "obj.h"

using namespace QtCharts;

class Chart
{
private:
    std::string title;
    bool custom;
protected:
    QChart *chart;
    Obj *obj;
    Chart(Obj*, const std::string&);
    virtual void addSeries() const = 0;
    virtual void customize() const = 0;
public:
    virtual ~Chart();
    void customized(bool =true);
    bool isCustomized() const;
    virtual QChartView* show() const;
};

#endif // CHART_H
