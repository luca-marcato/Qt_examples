#include "chart.h"

Chart::Chart(Obj* obj, const std::string& title) : title(title), chart(new QChart()), obj(obj) {}

QChartView* Chart::show() const {
    chart->setTitle(QString::fromStdString(title));
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    return chartView;
}
