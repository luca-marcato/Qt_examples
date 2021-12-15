#include "stacked_horizontal_barchart.h"

StackedHorizontalBarChart::StackedHorizontalBarChart(Obj* obj, const std::string& title) :
                                                   Chart(obj, title),
                                                   series(new QHorizontalStackedBarSeries()),
                                                   axisY(new QBarCategoryAxis()),
                                                   axisX(new QValueAxis()){}

void StackedHorizontalBarChart::addSeries() const {
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

void StackedHorizontalBarChart::addCategories() const {
    QStringList categories;
    categories << QString::fromStdString(obj->getName());

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


