#-------------------------------------------------
#
# Project created by QtCreator 2020-07-22T11:09:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 06_Event
TEMPLATE = app

SOURCES += \
        main.cpp \
        widget.cpp \
    mylabel.cpp \
    mybutton.cpp

HEADERS += \
        widget.h \
    mylabel.h \
    mybutton.h

FORMS += \
        widget.ui

CONFIG += c++11
