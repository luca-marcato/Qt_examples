#include "stacked_horizontal_barchart.h"

StackedHorizontalBarChart::StackedHorizontalBarChart(Obj* obj, const std::string& title) :
                                                   Chart(obj, title),
                                                   series(new QHorizontalStackedBarSeries()),
                                                   axisY(new QBarCategoryAxis()),
                                                   axisX(new QValueAxis()){}

void StackedHorizontalBarChart::addSeries() const {
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

void StackedHorizontalBarChart::addCategories() const {
    QStringList categories;
    categories << QString::fromStdString(obj->getMonth());

    axisY->append(categories);
}

void StackedHorizontalBarChart::setRange() const {
    axisX->setRange(0, obj->getTotalValue());

    series->attachAxis(axisX);
}

QChartView* StackedHorizontalBarChart::show() const {
    addSeries();
    addCategories();
    setRange();

    chart->addSeries(series);
    chart->addAxis(axisY, Qt::AlignLeft);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->legend()->setVisible(true);
    return Chart::show();
}


