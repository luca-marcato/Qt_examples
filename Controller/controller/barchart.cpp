#include "barchart.h"

BarChart::BarChart(Obj* obj, const std::string& title, bool custom) : MyChart(obj, title, custom),
                                                                               series(new QBarSeries()),
                                                                               axisX(new QBarCategoryAxis()),
                                                                               axisY(new QValueAxis()),
                                                                               set0(new QBarSet("B2B")),
                                                                               set1(new QBarSet("B2C")),
                                                                               set2(new QBarSet("B2G")) {}

BarChart::~BarChart() {
    delete set0;
    delete set1;
    delete set2;
    delete axisX;
    delete axisY;
    delete series;
}

BarChart& BarChart::operator =(const BarChart& bc) {
    if(this != &bc) {
        delete set0;
        delete set1;
        delete set2;
        delete axisX;
        delete axisY;
        delete series;
        MyChart::operator =(bc);
        series = (new QBarSeries());
        axisX = (new QBarCategoryAxis());
        axisY = (new QValueAxis());
        set0 = (new QBarSet("B2B"));
        set1 = (new QBarSet("B2C"));
        set2 = (new QBarSet("B2G"));

    }
    return *this;
}

void BarChart::addSeries() const {
    *set0 << obj->getB2BValue();
    *set1 << obj->getB2CValue();
    *set2 << obj->getB2GValue();

    series->append(set0);
    series->append(set1);
    series->append(set2);
}

void BarChart::addCategories() const {}

void BarChart::setRange() const {
    axisY->setRange(0, obj->getMaxValue() != 0 ? obj->getMaxValue() : 1);

    series->attachAxis(axisY);
}

QChart* BarChart::show() const {

    addSeries();
    addCategories();

    chart->addSeries(series);

    chart->addAxis(axisX, Qt::AlignBottom);
    setRange();

    chart->addAxis(axisY, Qt::AlignLeft);

    chart->legend()->setVisible(true);
    return MyChart::show();
}
