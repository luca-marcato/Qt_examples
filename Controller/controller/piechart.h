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
    void customize() const override;
public:
    PieChart(std::shared_ptr<Obj> =nullptr, const std::string& ="", bool =false);
    virtual QPieSeries* getSeries() const;
    QChart* show() const override;
};

#endif // PIECHART_H
