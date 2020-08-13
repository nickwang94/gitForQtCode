#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>


MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // 动态分配空间，不能指定父对象
    myT = new MyThread;

    // 创建子线程
    thread = new QThread(this);

    // 把自定义的线程加入子线程中
    myT->moveToThread(thread);

    connect(myT, &MyThread::mySignal, this, &MyWidget::dealSignal);

    // 多线程连接，为队列连接
    // 如果使用直接连接，则二者在一个线程中
    connect(this, &MyWidget::startThread, myT, &MyThread::myTimeout, Qt::DirectConnection);

    connect(this, &MyWidget::destroyed, this, &MyWidget::onDestroy);

    qDebug() << QStringLiteral("主线程号:") << QThread::currentThread();

    // 线程处理函数内部不允许操作界面控件

    // connect第五个参数只有在多线程的时候才有意义，具体值连接方式
    // 有三种链接方式：默认、队列和直接

}

MyWidget::~MyWidget()
{
    delete ui;
}

/**
 * 处理MyThread每秒发送的信号
 * @brief MyWidget::dealSignal
 */
void MyWidget::dealSignal()
{
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
}

/**
 * 启动定时器
 * @brief MyWidget::on_buttonStart_clicked
 */
void MyWidget::on_buttonStart_clicked()
{
    if (thread->isRunning() == true)
    {
        return;
    }

    // 启动线程，但是没有启动线程处理函数
    thread->start();
    myT->setFlag(false);

    // 不能直接调用线程处理函数，直接调用会导致
    // 线程处理函数和主线程在同一个线程中
    // myT->myTimeout();

    // 只能通过信号和槽的方式调用
    emit startThread();
}

/**
 * 关闭定时器
 * @brief MyWidget::on_buttonStop_clicked
 */
void MyWidget::on_buttonStop_clicked()
{
    if (thread->isRunning() == false)
    {
        return;
    }

    myT->setFlag(true);
    thread->quit();
    thread->wait();
}

/**
 * 点击关闭窗口的槽函数
 * @brief MyWidget::onDestroy
 */
void MyWidget::onDestroy()
{
    on_buttonStop_clicked();
    delete myT;
}






