#include "barchart.h"

BarChart::BarChart(Obj* obj, const std::string& title) : Chart(obj, title),
                               series(new QBarSeries()),
                               axisX(new QBarCategoryAxis()),
                               axisY(new QValueAxis()) {}

void BarChart::addSeries() const {
    QBarSet *set0 = new QBarSet("B2B");
    QBarSet *set1 = new QBarSet("B2C");
    QBarSet *set2 = new QBarSet("B2G");

    *set0 << obj->getB2BVal();
    *set1 << obj->getB2CVal();
    *set2 << obj->getB2GVal();

    series->append(set0);
    series->append(set1);
    series->append(set2);
}

void BarChart::addCategories() const {
    QStringList categories;
    categories << QString::fromStdString(obj->getMonth());
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
    chart->legend()->setVisible(true);
    return Chart::show();
}
