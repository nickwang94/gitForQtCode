#-------------------------------------------------
#
# Project created by QtCreator 2020-08-13T09:50:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 03_ThreadImage
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mythread.cpp

HEADERS  += widget.h \
    mythread.h

FORMS    += widget.ui
