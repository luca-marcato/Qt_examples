#include "areachart.h"

AreaChart::AreaChart(Obj* obj, const std::string& title, bool custom) : MyChart(obj, title, custom),
                                                                        seriesb2g0(new QLineSeries()),
                                                                        seriesb2g1(new QLineSeries()),
                                                                        seriesb2c0(new QLineSeries()),
                                                                        seriesb2c1(new QLineSeries()),
                                                                        seriesb2b0(new QLineSeries()),
                                                                        seriesb2b1(new QLineSeries()),
                                                                        seriesb2g(new QAreaSeries()),
                                                                        seriesb2c(new QAreaSeries()),
                                                                        seriesb2b(new QAreaSeries()) {}

AreaChart::~AreaChart() {
    delete seriesb2g0;
    delete seriesb2g1;
    delete seriesb2c0;
    delete seriesb2c1;
    delete seriesb2b0;
    delete seriesb2b1;
    delete seriesb2g;
    delete seriesb2c;
    delete seriesb2b;
}

AreaChart& AreaChart::operator =(const AreaChart& ac) {
    if(this != &ac) {
        delete seriesb2g0;
        delete seriesb2g1;
        delete seriesb2c0;
        delete seriesb2c1;
        delete seriesb2b0;
        delete seriesb2b1;
        delete seriesb2g;
        delete seriesb2c;
        delete seriesb2b;
        MyChart::operator =(ac);
        seriesb2g0 = new QLineSeries();
        seriesb2g1 = new QLineSeries();
        seriesb2c0 = new QLineSeries();
        seriesb2c1 = new QLineSeries();
        seriesb2b0 = new QLineSeries();
        seriesb2b1 = new QLineSeries();
        seriesb2g = new QAreaSeries();
        seriesb2c = new QAreaSeries();
        seriesb2b = new QAreaSeries();
    }
    return *this;
}

void AreaChart::addSeries() const {
    *seriesb2g0 << QPointF(0,0) << QPointF(10,0);
    *seriesb2g1 << QPointF(0,0)<< QPointF(10,obj->getB2GValue()) << QPointF(10,0);

    *seriesb2c0 << QPointF(0,0) << QPointF(10,0);
    *seriesb2c1 << QPointF(0,0)<< QPointF(10,obj->getB2CValue()) << QPointF(10,0);

    *seriesb2b0 << QPointF(0,0) << QPointF(10,0);
    *seriesb2b1 << QPointF(0,0)<< QPointF(10,obj->getB2BValue()) << QPointF(10,0);

    seriesb2c->setLowerSeries(seriesb2c0);
    seriesb2c->setUpperSeries(seriesb2c1);
    seriesb2c->setName("B2C");

    seriesb2g->setLowerSeries(seriesb2g0);
    seriesb2g->setUpperSeries(seriesb2g1);
    seriesb2g->setName("B2G");

    seriesb2b->setLowerSeries(seriesb2b0);
    seriesb2b->setUpperSeries(seriesb2b1);
    seriesb2b->setName("B2B");
}

void AreaChart::setRange() const {
    chart->createDefaultAxes();
    chart->axes(Qt::Horizontal).first()->setRange(0,10);
    chart->axes(Qt::Vertical).first()->setRange(0, obj->getMaxValue() != 0 ? obj->getMaxValue() : 10);
}

QChart* AreaChart::show() const {
    addSeries();
    chart->addSeries(seriesb2b);
    chart->addSeries(seriesb2c);
    chart->addSeries(seriesb2g);

    setRange();
    chart->legend()->setVisible(true);
    return MyChart::show();
}


