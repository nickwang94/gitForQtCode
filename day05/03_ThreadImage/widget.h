#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include "mythread.h"
#include <QThread>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    // 重写绘图事件
    void paintEvent(QPaintEvent *event);

public slots:
    void getImage(QImage);
    void dealClose();


private:
    Ui::Widget *ui;
    QImage image;
    MyThread *myT; // 自定义线程
    QThread *thread;
};

#endif // WIDGET_H
