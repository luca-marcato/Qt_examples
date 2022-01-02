#include "viewer.h"


Viewer::Viewer(QWidget *parent) : QWidget(parent) {

    StackedWidgetSlider* window = new StackedWidgetSlider();

    setLayout(window->Layout());
}


