#ifndef PIECHART_H
#define PIECHART_H

#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "chart.h"

class PieChart : public Chart
{
private:
    QPieSeries *series;
protected:
    virtual void addSeries() const;
public:
    PieChart(Obj* =nullptr, const std::string& ="");
    QChartView* show() const override;
};

#endif // PIECHART_H
