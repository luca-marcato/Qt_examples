#ifndef STACKEDWIDGETSLIDER_H
#define STACKEDWIDGETSLIDER_H

#include "slidingstackedwidget.h"
#include "dashboard.h"
#include "addnew.h"

class StackedWidgetSlider : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *sideBar;
    QHBoxLayout *mainLayout;
    QPushButton *dashBoardButton;
    QPushButton *addNewButton;
    SlidingStackedWidget *slidingStacked;
    Dashboard* dashBoardWidget;
    AddNew* addNewWidget;
    int animTime;

    void createGuiControlComponents();
    void createSlidingStackedWidget();
    void createLayout();
    void createConnections();
public:
    StackedWidgetSlider(QWidget *parent = nullptr, int =1000);
    ~StackedWidgetSlider();

    QHBoxLayout* Layout() const;
    void setChartView(std::list<QChart*>);
    void setChartInfo(std::vector<QString>);
public slots:
    QString getChartDate() const;
    std::vector<QString> getAddNewFormData() const;
    std::vector<QString> getUpdateFormData() const;
};

#endif // STACKEDWIDGETSLIDER_H
