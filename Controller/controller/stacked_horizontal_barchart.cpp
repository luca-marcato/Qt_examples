#include "stacked_horizontal_barchart.h"

StackedHorizontalBarChart::StackedHorizontalBarChart(Obj* obj, const std::string& title, bool custom) :
                                                   MyChart(obj, title, custom),
                                                   series(new QHorizontalStackedBarSeries()),
                                                   axisY(new QBarCategoryAxis()),
                                                   axisX(new QValueAxis()),
                                                   set0(new QBarSet("B2B")),
                                                   set1(new QBarSet("B2C")),
                                                   set2(new QBarSet("B2G")){}

StackedHorizontalBarChart::~StackedHorizontalBarChart() {
    delete set0;
    delete set1;
    delete set2;
    delete axisX;
    delete axisY;
    delete series;
}

StackedHorizontalBarChart& StackedHorizontalBarChart::operator =(const StackedHorizontalBarChart& shbc) {
    if(this != &shbc) {

            delete set0;
            delete set1;
            delete set2;
            delete axisX;
            delete axisY;
            delete series;

        MyChart::operator =(shbc);
        series = (new QHorizontalStackedBarSeries());
        axisY = (new QBarCategoryAxis());
        axisX = (new QValueAxis());
        set0 = (new QBarSet("B2B"));
        set1 = (new QBarSet("B2C"));
        set2 = (new QBarSet("B2G"));
    }
    return *this;
}

void StackedHorizontalBarChart::addSeries() const {
    *set0 << obj->getB2BValue();
    *set1 << obj->getB2CValue();
    *set2 << obj->getB2GValue();

    series->append(set0);
    series->append(set1);
    series->append(set2);
}

void StackedHorizontalBarChart::addCategories() const {}

void StackedHorizontalBarChart::setRange() const {
    axisX->setRange(0, 100);

    series->attachAxis(axisX);
}

QHorizontalStackedBarSeries* StackedHorizontalBarChart::getSeries() const {
    return series;
}

QChart* StackedHorizontalBarChart::show() const {
    addSeries();
    chart->addSeries(series);
    addCategories();
    setRange();
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    chart->legend()->setVisible(true);
    return MyChart::show();
}


