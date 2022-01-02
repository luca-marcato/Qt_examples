#ifndef SLIDINGSTACKEDWIDGET_H
#define SLIDINGSTACKEDWIDGET_H

#include <QtGui>
#include <QWidget>
#include <QEasingCurve>
#include <QStackedWidget>

class SlidingStackedWidget : public QStackedWidget
{
    Q_OBJECT
private:
    QWidget *m_mainwindow;
    int m_speed;
    int m_now;
    int m_next;
    QPoint m_pnow;
    bool m_active;
    enum QEasingCurve::Type m_animationtype;

    void slideInWgt(QWidget * widget);
public:
    SlidingStackedWidget(QWidget *parent =0);
    ~SlidingStackedWidget();
    void setSpeed(int speed);
    void setAnimation(enum QEasingCurve::Type animationtype);

public slots:
    void slideInNext();
    void slideInPrev();
    void slideInIdx(int idx);

signals:
    void animationFinished(void);

private slots:
    void animationDoneSlot(void);
};

#endif // SLIDINGSTACKEDWIDGET_H
