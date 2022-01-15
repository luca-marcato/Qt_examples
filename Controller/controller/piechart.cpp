#include "piechart.h"

PieChart::PieChart(Obj* obj, const std::string& title, bool custom) : MyChart(obj, title, custom), series(new QPieSeries()) {}

PieChart::~PieChart() {
    delete series;
}

PieChart& PieChart::operator =(const PieChart& pc) {
    if(this != &pc) {
        series->clear();
        delete series;
        MyChart::operator =(pc);
        series = new QPieSeries();
    }
    return *this;
}

void PieChart::addSeries() const {
    series->append("B2B", obj->getB2BValue())->setLabelVisible();
    series->append("B2C", obj->getB2CValue())->setLabelVisible();
    series->append("B2G", obj->getB2GValue())->setLabelVisible();
}


QPieSeries* PieChart:: getSeries() const {
    return series;
}

QChart* PieChart::show() const {
    addSeries();

    chart->addSeries(series);
    chart->legend()->setVisible(false);
    return MyChart::show();
}
