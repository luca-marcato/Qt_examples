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

    MainWindow w;

    w.setCentralWidget(barChart->show());
    w.resize(420, 300);

    w.show();

    return a.exec();
}
