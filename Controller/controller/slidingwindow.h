#ifndef SLIDINGWINDOW_H
#define SLIDINGWINDOW_H

#include <QFrame>
#include <QGridLayout>
#include <QParallelAnimationGroup>
#include <QScrollArea>
#include <QToolButton>
#include <QPropertyAnimation>
#include <QWidget>
#include <QDebug>

class SlidingWindow : public QWidget {
    Q_OBJECT
private:
    QGridLayout* mainLayout;
    QToolButton* toggleButton;
    QFrame* headerLine;
    QParallelAnimationGroup* toggleAnimation;
    QScrollArea* contentArea;
    int animationDuration{300};
public:
    explicit SlidingWindow(const QString& ="", int = 300, QWidget *parent = 0);
    ~SlidingWindow();
    void setContentLayout(QLayout*);
};

#endif
