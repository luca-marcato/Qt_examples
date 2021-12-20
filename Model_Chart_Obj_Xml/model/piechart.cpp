#include "piechart.h"

PieChart::PieChart(std::shared_ptr<Obj> obj, const std::string& title) : Chart(obj, title), series(new QPieSeries()) {}

void PieChart::addSeries() const {
    series->append("B2B", obj->getB2BVal())->setLabelVisible();
    series->append("B2C", obj->getB2CVal())->setLabelVisible();
    series->append("B2G", obj->getB2GVal())->setLabelVisible();
}

void PieChart::customize() const {
    QFont font;
    font.setPixelSize(18);
    chart->setTitleFont(font);
    chart->setTitleBrush(QBrush(Qt::white));

    // Customize chart background
    QLinearGradient backgroundGradient;
    backgroundGradient.setStart(QPointF(0, 0));
    backgroundGradient.setFinalStop(QPointF(0, 1));
    backgroundGradient.setColorAt(0.0, QRgb(0xd2d0d1));
    backgroundGradient.setColorAt(1.0, QRgb(0x4c4547));
    backgroundGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    chart->setBackgroundBrush(backgroundGradient);

       // Customize plot area background
    QLinearGradient plotAreaGradient;
    plotAreaGradient.setStart(QPointF(0, 1));
    plotAreaGradient.setFinalStop(QPointF(1, 0));
    plotAreaGradient.setColorAt(0.0, QRgb(0x555555));
    plotAreaGradient.setColorAt(1.0, QRgb(0x55aa55));
    plotAreaGradient.setCoordinateMode(QGradient::ObjectBoundingMode);
    chart->setPlotAreaBackgroundBrush(plotAreaGradient);
    chart->setPlotAreaBackgroundVisible(true);
}

QChartView* PieChart::show() const {
    addSeries();

    if(isCustomized()) customize();

    chart->addSeries(series);
    chart->legend()->setVisible(false);
    return Chart::show();
}
