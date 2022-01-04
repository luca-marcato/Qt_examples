#ifndef STACKEDHORIZONTALBARCHAR_H
#define STACKEDHORIZONTALBARCHAR_H

#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QHorizontalStackedBarSeries>

#include "chart.h"

class StackedHorizontalBarChart: public Chart
{
private:
    QHorizontalStackedBarSeries *series;
    QBarCategoryAxis *axisY;
    QValueAxis *axisX;
protected:
    void addSeries() const override;
    void customize() const override;
    void addCategories() const;
    void setRange() const;
public:
    StackedHorizontalBarChart(std::shared_ptr<Obj> =nullptr, const std::string& ="", bool =false);
    virtual QHorizontalStackedBarSeries* getSeries() const;
    QChart* show() const override;
};

#endif // STACKEDHORIZONTALBARCHAR_H
