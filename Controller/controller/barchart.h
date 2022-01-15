#ifndef BARCHART_H
#define BARCHART_H

#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

#include "mychart.h"

class BarChart : public MyChart
{
private:

    QBarSet *set0;
    QBarSet *set1;
    QBarSet *set2;
protected:
    QBarSeries *series;
    QBarCategoryAxis *axisX;
    QValueAxis *axisY;
    void addSeries() const override;
    void addCategories() const;
    void setRange() const;
public:
    BarChart(Obj* =nullptr, const std::string& ="", bool =false);
    ~BarChart() override;
    BarChart& operator =(const BarChart&);
    //QBarSeries* getSeries() const;
    QChart* show() const override;

};

#endif // BARCHART_H
