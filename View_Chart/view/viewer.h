#ifndef VIEWER_H
#define VIEWER_H

#include <QWidget>
#include <QBoxLayout>
#include <QStackedLayout>
#include <QFrame>
#include <QtCharts>
#include <QtCharts>

using namespace QtCharts;


class Viewer : public QWidget {
    Q_OBJECT

public:
    explicit Viewer(QWidget *parent =nullptr);

signals:
};

#endif // VIEWER_H
