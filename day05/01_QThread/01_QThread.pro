#-------------------------------------------------
#
# Project created by QtCreator 2020-08-12T16:00:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 01_QThread
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mythread.cpp

HEADERS  += widget.h \
    mythread.h

FORMS    += widget.ui
