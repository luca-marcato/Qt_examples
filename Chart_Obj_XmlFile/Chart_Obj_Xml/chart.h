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
    QChart *chart;
protected:
    Obj obj;
    Chart(const Obj&, const std::string& =std::string());
    virtual void addSeries() = 0;
public:
    virtual QChartView* show() const;
};

#endif // CHART_H
