#-------------------------------------------------
#
# Project created by QtCreator 2021-12-16T12:19:38
#
#-------------------------------------------------

QT       += core gui
QT       += xml
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = model
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        obj.cpp \
        file.cpp \
        xmlfile.cpp \
        chart.cpp \
        barchart.cpp \
        piechart.cpp \
        stacked_horizontal_barchart.cpp \
    model.cpp


HEADERS += \
        mainwindow.h \
        obj.h \
        file.h \
        xmlfile.h \
        chart.h \
        barchart.h \
        piechart.h \
        stacked_horizontal_barchart.h \
    model.h

FORMS += \
        mainwindow.ui
