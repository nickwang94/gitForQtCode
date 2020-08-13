#include "widget.h"
#include "ui_widget.h"
#include <QThread>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    myTimer = new QTimer(this);

    // 给线程创建空间，最好是用完就关闭
    thread = new MyThread(this);

    connect(myTimer, &QTimer::timeout, this, &Widget::onTimeOut);
    connect(thread, &MyThread::isDone, this, &Widget::on_thread_done);

    // 当按窗口右上角的关闭时，触发槽函数
    connect(this, &Widget::destroyed, this, &Widget::stopThread);
}

Widget::~Widget()
{
    delete ui;
}

/**
 * 定时器槽函数
 * @brief Widget::onTimeOut
 */
void Widget::onTimeOut()
{
    static int i = 0;
    i++;

    // 设置lcd的值
    ui->lcdNumber->display(i);
}

/**
 * 按钮槽函数
 * @brief Widget::on_pushButton_clicked
 */
void Widget::on_pushButton_clicked()
{
    // 如果定时器没工作，就启动
    if (myTimer->isActive() == false)
    {
        myTimer->start(100);
    }

    // 启动线程，处理数据
    thread->start();


    // 处理完数据后，关闭定时器
//     myTimer->stop();
    qDebug() << "over";
}

/**
 * 线程结束
 * @brief Widget::on_thread_done
 */
void Widget::on_thread_done()
{
    qDebug() << QStringLiteral("线程结束，关闭定时器");
    myTimer->stop();
}

/**
 * 关闭窗口槽函数
 * @brief Widget::stopThread
 */
void Widget::stopThread()
{
    // 停止线程，不是一调用就立马停止
    thread->quit();

    // 等待线程处理完手头工作
    thread->wait();
}
