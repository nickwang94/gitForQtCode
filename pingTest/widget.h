#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProcess>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    QProcess* p;
};

#endif // WIDGET_H
