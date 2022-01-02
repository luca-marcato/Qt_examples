#ifndef VIEWER_H
#define VIEWER_H

#include <QWidget>

#include "stackedwidgetslider.h"

class Viewer : public QWidget {
    Q_OBJECT

public:
    Viewer(QWidget *parent =nullptr);
};

#endif // VIEWER_H
