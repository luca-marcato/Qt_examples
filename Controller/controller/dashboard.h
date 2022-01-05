#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QBoxLayout>
#include <QPushButton>
#include <QtCharts>
#include <QDebug>

#include "slidingwindow.h"
#include "slidingstackedwidget.h"

class Dashboard : public QWidget
{
    Q_OBJECT
private:
    SlidingStackedWidget* slidingStacked;
    QVBoxLayout* layout;
    QHBoxLayout* chartLayout;
    QPushButton* modifyButton;
    QHBoxLayout* controllButtonsLayout;
    QDateTimeEdit* calendar;
    QPushButton* searchDate;
    std::list<QChartView*> chartViews;
    std::vector<SlidingWindow*> chartInfo;

    static const QStringList monthValues;

    void CreateChartsView();
    void CreateControlGuiComponent();
    void CreateLayout();
    void CreateConnections();
public:
    Dashboard(SlidingStackedWidget*, QWidget* =0);
    ~Dashboard();

    QVBoxLayout* Layout() const;
    QString getCalendarDate() const;
    void setChartContent(std::list<QChart*>);
    void setChartInfoContent(std::vector<QString>);
};

#endif // DASHBOARD_H
