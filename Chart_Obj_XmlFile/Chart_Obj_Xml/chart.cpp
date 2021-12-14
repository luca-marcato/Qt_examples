#include "chart.h"

Chart::Chart(const Obj& obj, const std::string& title) : title(title), chart(new QChart()), obj(obj) {}

QChartView* Chart::show() const {
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;
}
