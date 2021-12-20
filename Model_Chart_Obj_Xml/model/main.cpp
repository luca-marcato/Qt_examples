#include "mainwindow.h"
#include <QApplication>

#include "obj.h"
#include "xmlfile.h"
#include "barchart.h"
#include "piechart.h"
#include "stacked_horizontal_barchart.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Obj obj("2021", "Gennaio", 1100, 220, 50);
    std::shared_ptr<Obj> ptr = std::make_shared<Obj>(obj);
    BarChart* bc = new BarChart(ptr);
    PieChart* pc = new PieChart(ptr);
    StackedHorizontalBarChart* shc = new StackedHorizontalBarChart(ptr);
    ptr = nullptr;



    MainWindow w;
    w.setCentralWidget(shc->show());
    w.resize(400,300);
    w.show();

    int val;
    std::cout<<"Inser:";
    std::cin>>val;
    obj.setB2BVal(val);
    return a.exec();



}
