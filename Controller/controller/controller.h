#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "modello.h"

class Viewer;

class Controller
{
private:
    Modello* model;
    Viewer* view;
public:
    Controller(Viewer*);
    ~Controller();

    std::list<QChart*> onGetCharts(const QString&) const;
};

#endif // CONTROLLER_H
