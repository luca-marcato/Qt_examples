#ifndef BARCHART_H
#define BARCHART_H

#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include "chart.h"

class BarChart : public Chart
{
private:
    QBarSeries *series;
    QBarCategoryAxis *axisX;
protected:
    void addSeries() override;
    virtual void addCategories();
public:
    BarChart(const Obj& =Obj());
    QChartView* show() const override;

};

#endif // BARCHART_H
