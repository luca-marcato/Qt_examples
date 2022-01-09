#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QBoxLayout>
#include <QPushButton>
#include <QtCharts>
#include <QDebug>

#include "slidingwindow.h"
#include "slidingstackedwidget.h"
#include "modifydialog.h"

class Dashboard : public QWidget
{
    Q_OBJECT
private:
    SlidingStackedWidget* slidingStacked;
    QVBoxLayout* layout;
    QHBoxLayout* chartLayout;
    QPushButton* modifyButton;
    ModifyDialog* dialog;
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
    std::vector<QString> getDateAndFormContent() const;
};

#endif // DASHBOARD_H
