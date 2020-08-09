#include "widget.h"
#include "ui_widget.h"

#include <QThread>
#include <QDebug>

Widget::Widget()
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

// 真正线程执行的内容
void Widget::run()
{
    qDebug() << QStringLiteral("被线程调用") << QThread::currentThreadId();
}


