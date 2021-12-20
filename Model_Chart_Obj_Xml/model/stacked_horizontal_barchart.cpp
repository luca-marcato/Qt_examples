#include "stacked_horizontal_barchart.h"

StackedHorizontalBarChart::StackedHorizontalBarChart(std::shared_ptr<Obj> obj, const std::string& title) :
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

void StackedHorizontalBarChart::customize() const {
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

    QFont labelsFont;
    labelsFont.setPixelSize(12);
    axisX->setLabelsFont(labelsFont);
    axisY->setLabelsFont(labelsFont);

    // Customize axis colors
    QPen axisPen(QRgb(0xd18952));
    axisPen.setWidth(2);
    axisX->setLinePen(axisPen);
    axisY->setLinePen(axisPen);

    // Customize axis label colors
    QBrush axisBrush(Qt::white);
    axisX->setLabelsBrush(axisBrush);
    axisY->setLabelsBrush(axisBrush);

    // Customize grid lines and shades
    axisX->setGridLineVisible(false);
    axisY->setGridLineVisible(false);
    axisY->setShadesPen(Qt::NoPen);
    axisY->setShadesBrush(QBrush(QColor(0x99, 0xcc, 0xcc, 0x55)));
    axisY->setShadesVisible(true);
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

    if(isCustomized()) customize();

    chart->addSeries(series);
    chart->addAxis(axisY, Qt::AlignLeft);
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->legend()->setVisible(true);
    return Chart::show();
}


