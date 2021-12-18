#include "mainwindow.h"
#include <QApplication>

#include "obj.h"
#include "xmlfile.h"
#include "barchart.h"
#include "piechart.h"
#include "stacked_horizontal_barchart.h""

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Obj* obj = new Obj("2002", "Gennaio", 1111, 12321, 211);
    BarChart* barChart = new BarChart(obj, "title");
    PieChart* pieChart = new PieChart(obj, "title");
    StackedHorizontalBarChart* shChart = new StackedHorizontalBarChart(obj, "title");

    MainWindow w;

    w.setCentralWidget(pieChart->show());
    w.resize(420, 300);

    w.show();

    return a.exec();
}
