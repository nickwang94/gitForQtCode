#-------------------------------------------------
#
# Project created by QtCreator 2020-08-12T17:38:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 02_ThreadPro
TEMPLATE = app


SOURCES += main.cpp\
        mywidget.cpp \
    mythread.cpp

HEADERS  += mywidget.h \
    mythread.h

FORMS    += mywidget.ui
