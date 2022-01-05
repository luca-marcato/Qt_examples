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

    std::list<QChart*> getChartsView(const QString&) const;
    std::vector<QString> getChartsInfo(const QString&) const;
    void addNewChart(std::vector<QString>) const;
};

#endif // CONTROLLER_H
