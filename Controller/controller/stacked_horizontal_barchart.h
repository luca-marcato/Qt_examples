#ifndef STACKEDHORIZONTALBARCHAR_H
#define STACKEDHORIZONTALBARCHAR_H

#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QHorizontalStackedBarSeries>

#include "mychart.h"

class StackedHorizontalBarChart: public MyChart
{
private:

    QBarSet *set0;
    QBarSet *set1;
    QBarSet *set2;
protected:
    QHorizontalStackedBarSeries *series;
    QBarCategoryAxis *axisY;
    QValueAxis *axisX;
    void addSeries() const override;
    void addCategories() const;
    void setRange() const;
public:
    StackedHorizontalBarChart(Obj* =nullptr, const std::string& ="", bool =false);
    ~StackedHorizontalBarChart() override;
    StackedHorizontalBarChart& operator =(const StackedHorizontalBarChart&);
    virtual QHorizontalStackedBarSeries* getSeries() const;
    QChart* show() const override;
};

#endif // STACKEDHORIZONTALBARCHAR_H
