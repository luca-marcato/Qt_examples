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
    QValueAxis *axisY;
protected:
    void addSeries() const override;
    void customize() const override;
    void addCategories() const;
    void setRange() const;
public:
    BarChart(Obj* obj =nullptr, const std::string& ="");
    QChartView* show() const override;

};

#endif // BARCHART_H
