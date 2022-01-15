#ifndef PIECHART_H
#define PIECHART_H

#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include "mychart.h"

class PieChart : public MyChart
{
private:
    QPieSeries *series;
protected:
    virtual void addSeries() const;
public:
    PieChart(Obj* =nullptr, const std::string& ="", bool =false);
    ~PieChart() override;
    PieChart& operator =(const PieChart&);
    virtual QPieSeries* getSeries() const;
    QChart* show() const override;
};

#endif // PIECHART_H
