#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include "mythread.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void onTimeOut();
    void on_pushButton_clicked();
    void on_thread_done();
    void stopThread();

private:
    Ui::Widget *ui;

    QTimer *myTimer;

    MyThread *thread; // 线程对象
};

#endif // WIDGET_H
