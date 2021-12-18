#include "piechart.h"

PieChart::PieChart(Obj* obj, const std::string& title) : Chart(obj, title), series(new QPieSeries()) {}

void PieChart::addSeries() const {
    series->append("B2B", obj->getB2BVal())->setLabelVisible();
    series->append("B2C", obj->getB2CVal())->setLabelVisible();
    series->append("B2G", obj->getB2GVal())->setLabelVisible();
}

QChartView* PieChart::show() const {
    addSeries();

    chart->addSeries(series);
    chart->legend()->setVisible(false);
    return Chart::show();
}
