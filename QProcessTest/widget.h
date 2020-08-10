#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT

public slots:
    void slot_onCommandSucedded(QString);
    void slot_onCommandFailed(QString);
    void deleteLater();
public:
    Widget(QWidget *parent = 0);
    ~Widget();
};

#endif // WIDGET_H
