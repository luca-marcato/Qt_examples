#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QHorizontalStackedBarSeries>

#include "barchart.h"
#include "piechart.h"
#include "stacked_horizontal_barchart.h"

QT_CHARTS_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
/*
    Obj* obj = new Obj(100,20,30,"Gennaio");
    BarChart* barChart = new BarChart(obj, "title");

    QMainWindow window;
    window.setCentralWidget(barChart->show());
    window.resize(420, 300);
    window.show();

*/

/* BARCHART
//![1]
    QBarSet *set0 = new QBarSet("Jane");
    QBarSet *set1 = new QBarSet("John");
    QBarSet *set2 = new QBarSet("Axel");

    *set0 << 1;
    *set1 << 5;
    *set2 << 3;
//![1]

//![2]
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    series->append(set1);
    series->append(set2);

//![2]

//![3]
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple barchart example");
    chart->setAnimationOptions(QChart::SeriesAnimations);
//![3]

//![4]
    QStringList categories;
    categories << "Jan";
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setRange(0,5);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
//![4]

//![5]
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
//![5]

//![6]
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
//![6]

//![7]
    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(420, 300);
    window.show();
//![7] */

    /*
    Obj* obj = new Obj(100,20,30,"Gennaio");
    PieChart* pieChart = new PieChart(obj, "title");

    QMainWindow window;
    window.setCentralWidget(pieChart->show());
    window.resize(420, 300);
    window.show();
 //*/
/* PIECHART
    //![1]
    QPieSeries *series = new QPieSeries();
    series->append("Jane", 1);
    series->append("Joe", 2);
    series->append("Andy", 3);
    series->append("Barbara", 4);
    series->append("Axel", 5);

    QPieSlice *slice = series->slices().at(1);
    slice->setExploded();
    slice->setLabelVisible();
    slice->setPen(QPen(Qt::darkGreen, 2));
    slice->setBrush(Qt::green);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Simple piechart example");
    chart->legend()->hide();

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QMainWindow window;
    window.setCentralWidget(chartView);
    window.resize(400, 300);
    window.show();
        // */

    Obj* obj = new Obj(100,20,30,"Gennaio");
    StackedHorizontalBarChart* shBarchart = new StackedHorizontalBarChart(obj, "title");

    QMainWindow window;
    window.setCentralWidget(shBarchart->show());
    window.resize(420, 300);
    window.show();


    /* STACKED HORIZONTAL BARCHAR
    //![1]
        QBarSet *set0 = new QBarSet("Jane");
        QBarSet *set1 = new QBarSet("John");
        QBarSet *set2 = new QBarSet("Axel");
        QBarSet *set3 = new QBarSet("Mary");
        QBarSet *set4 = new QBarSet("Samantha");

        *set0 << 1 << 2 << 3 << 4 << 5 << 6;
        *set1 << 5 << 0 << 0 << 4 << 0 << 7;
        *set2 << 3 << 5 << 8 << 13 << 8 << 5;
        *set3 << 5 << 6 << 7 << 3 << 4 << 5;
        *set4 << 9 << 7 << 5 << 3 << 1 << 2;
    //![1]

    //![2]
        QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
        series->append(set0);
        series->append(set1);
        series->append(set2);
        series->append(set3);
        series->append(set4);

    //![2]

    //![3]
        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Simple horizontal stacked barchart example");
        chart->setAnimationOptions(QChart::SeriesAnimations);
    //![3]

    //![4]
        QStringList categories;
        categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
        QBarCategoryAxis *axisY = new QBarCategoryAxis();
        axisY->append(categories);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);
        QValueAxis *axisX = new QValueAxis();
        series->attachAxis(axisX);
        chart->addAxis(axisX, Qt::AlignBottom);

    //![4]

    //![5]
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
    //![5]

    //![6]
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
    //![6]

    //![7]
        QMainWindow window;
        window.setCentralWidget(chartView);
        window.resize(420, 300);
        window.show();
    //![7] */






    return a.exec();
}
