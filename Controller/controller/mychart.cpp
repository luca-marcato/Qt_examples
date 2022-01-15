#include "mychart.h"

MyChart::MyChart(Obj* obj, const std::string& title, bool custom) : title(title), chart(new QChart()), obj(obj), custom(custom) {}

MyChart::~MyChart() {
    delete chart;
}

MyChart& MyChart::operator =(const MyChart& c) {
    if(this != &c) {
        title = c.title;
        obj = c.obj;
    }
    return *this;
}

QChart* MyChart::show() const {
    chart->setTitle(QString::fromStdString(title));
    chart->legend()->setAlignment(Qt::AlignBottom);
    return chart;
}
