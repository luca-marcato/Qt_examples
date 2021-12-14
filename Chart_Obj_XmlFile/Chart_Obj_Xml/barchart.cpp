#include "barchart.h"

BarChart::BarChart(Obj* obj) : Chart(obj),
                               series(new QBarSeries()),
                               axisX(new QBarCategoryAxis()),
                               axisY(new QValueAxis()) {}

void BarChart::addSeries() const {
    QBarSet *set0 = new QBarSet("val1");
    QBarSet *set1 = new QBarSet("val2");
    QBarSet *set2 = new QBarSet("val3");

    *set0 << obj->getVal1();
    *set1 << obj->getVal2();
    *set2 << obj->getVal3();

    series->append(set0);
    series->append(set1);
    series->append(set2);
}

void BarChart::addCategories() const {
    QStringList categories;
    categories << QString::fromStdString(obj->getName());
    axisX->append(categories);

    series->attachAxis(axisX);
}

void BarChart::setRange() const {
    axisY->setRange(0, obj->getMaxValue());

    series->attachAxis(axisY);
}

QChartView* BarChart::show() const {
    addSeries();
    addCategories();
    setRange();

    chart->addSeries(series);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);
    return Chart::show();
}
