#include "barchart.h"

BarChart::BarChart(const Obj& obj) : Chart(obj), series(new QBarSeries()), axisX(new QBarCategoryAxis()) {}

void BarChart::addSeries() {
    QBarSet *set0 = new QBarSet("val1");
    QBarSet *set1 = new QBarSet("val2");
    QBarSet *set2 = new QBarSet("val3");

    *set0 << obj.getVal1();
    *set1 << obj.getVal2();
    *set2 << obj.getVal3();

    series->append(set0);
    series->append(set1);
    series->append(set2);
}

void BarChart::addCategories() {

}
