#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QBoxLayout>
#include <QPushButton>
#include <QtCharts>

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

    void CreateChartsView();
    void CreateControlGuiComponent();
    void CreateLayout();
    void CreateConnections();
public:
    Dashboard(SlidingStackedWidget*, QWidget* =0);
    ~Dashboard();

    QVBoxLayout* Layout() const;
};

#endif // DASHBOARD_H
