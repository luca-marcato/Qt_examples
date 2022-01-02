#include "slidingstackedwidget.h"

SlidingStackedWidget::SlidingStackedWidget(QWidget *parent)
    : QStackedWidget(parent), m_mainwindow(parent != 0 ? parent : this),
      m_speed(1000), m_now(0), m_next(0), m_pnow(QPoint(0,0)),
      m_active(false), m_animationtype(QEasingCurve::OutBack)
{}

SlidingStackedWidget::~SlidingStackedWidget(){}

void SlidingStackedWidget::setSpeed(int speed) {
    m_speed = speed;
}

void SlidingStackedWidget::setAnimation(enum QEasingCurve::Type animationtype) {
    m_animationtype = animationtype;
}

void SlidingStackedWidget::slideInNext() {
    int now = currentIndex();
    if (now<count() - 1) slideInIdx(now + 1);
}

void SlidingStackedWidget::slideInPrev() {
    int now = currentIndex();
    if (now > 0) slideInIdx(now - 1);
}

void SlidingStackedWidget::slideInIdx(int idx) {
    if (idx > count() - 1) {
        idx = idx % count();
    }
    else if (idx < 0) {
        idx = (idx + count()) % count();
    }
    slideInWgt(widget(idx));
}

void SlidingStackedWidget::slideInWgt(QWidget *newWidget) {
    if (m_active) {
        return;
    }
    else {
        m_active = true;
    }

    int now  = currentIndex();
    int next = indexOf(newWidget);
    int offsetx = frameRect().width();
    int offsety = frameRect().height();
    widget(next)->setGeometry (0, 0, offsetx, offsety);
    offsetx = 0;

    QPoint pnext = widget(next)->pos();
    QPoint pnow  = widget(now)->pos();
    m_pnow = pnow;

    widget(next)->move(pnext.x() - offsetx, pnext.y() - offsety);
    widget(next)->show();
    widget(next)->raise();

    QPropertyAnimation *animnow = new QPropertyAnimation(widget(now), "pos");
    animnow->setDuration(m_speed);
    animnow->setEasingCurve(m_animationtype);
    animnow->setStartValue(QPoint(pnow.x(), pnow.y()));
    animnow->setEndValue(QPoint(offsetx + pnow.x(), offsety + pnow.y()));

    QPropertyAnimation *animnext = new QPropertyAnimation(widget(next), "pos");
    animnext->setDuration(m_speed);
    animnext->setEasingCurve(m_animationtype);
    animnext->setStartValue(QPoint(-offsetx + pnext.x(), offsety + pnext.y()));
    animnext->setEndValue(QPoint(pnext.x(), pnext.y()));

    QParallelAnimationGroup *animgroup = new QParallelAnimationGroup;
    animgroup->addAnimation(animnow);
    animgroup->addAnimation(animnext);

    QObject::connect(animgroup, SIGNAL(finished()), this, SLOT(animationDoneSlot()));
    m_next   = next;
    m_now    = now;
    m_active = true;
    animgroup->start();
}

void SlidingStackedWidget::animationDoneSlot(void) {
    setCurrentIndex(m_next);
    widget(m_now)->hide();
    widget(m_now)->move(m_pnow);
    m_active = false;
    emit animationFinished();
}
