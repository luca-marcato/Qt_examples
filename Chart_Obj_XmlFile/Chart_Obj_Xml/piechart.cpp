#include "piechart.h"

PieChart::PieChart(Obj* obj, const std::string& title) : Chart(obj, title), series(new QPieSeries()) {}

void PieChart::addSeries() const {
    series->append("val1", obj->getVal1())->setLabelVisible();
    series->append("val2", obj->getVal2())->setLabelVisible();
    series->append("val3", obj->getVal3())->setLabelVisible();
}

QChartView* PieChart::show() const {
    addSeries();

    chart->addSeries(series);
    chart->legend()->setVisible(false);
    return Chart::show();
}
