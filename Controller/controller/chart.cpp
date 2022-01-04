#include "chart.h"

Chart::Chart(std::shared_ptr<Obj> obj, const std::string& title, bool custom) : title(title), chart(new QChart()), obj(obj), custom(custom) {}

void Chart::customized(bool custom) {
    custom = custom;
}

bool Chart::isCustomized() const {
    return custom;
}

QChart* Chart::show() const {
    chart->setTitle(QString::fromStdString(title));
    chart->legend()->setAlignment(Qt::AlignBottom);
    return chart;
}

int Chart::getPtr_Count() const {
    return obj.use_count();
}
