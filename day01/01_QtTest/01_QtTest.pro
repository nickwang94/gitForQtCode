#-------------------------------------------------
#
# Project created by QtCreator 2020-07-18T15:35:53
#
#-------------------------------------------------

# 代表模块
QT       += core gui

# 高于4版本，添加 QT += widgets，其目的是为了兼容Qt4
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# 应用程序的名字
TARGET = NickTest
# 指定makefile的类型，app（还可以选lib）
TEMPLATE = app

# 源文件 .cpp文件
SOURCES += main.cpp \
        mywidget.cpp

# 头文件 .h文件
HEADERS += mywidget.h
