#ifndef AREACHART_H
#define AREACHART_H

#include <QtCharts/QAreaSeries>
#include <QtCharts/QLineSeries>
#include "mychart.h"

class AreaChart : public MyChart
{
private:
    QLineSeries *seriesb2g0;
    QLineSeries *seriesb2g1;
    QLineSeries *seriesb2c0;
    QLineSeries *seriesb2c1;
    QLineSeries *seriesb2b0;
    QLineSeries *seriesb2b1;

protected:
    QAreaSeries *seriesb2g;
    QAreaSeries *seriesb2c;
    QAreaSeries *seriesb2b;
    void addSeries() const override;
    virtual void setRange() const;
public:
    AreaChart(Obj* =nullptr, const std::string& ="", bool =false);
    ~AreaChart() override;
    AreaChart& operator =(const AreaChart&);
    QChart* show() const override;
};

#endif // AREACHART_H
