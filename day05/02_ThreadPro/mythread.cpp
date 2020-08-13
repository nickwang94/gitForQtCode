#include "mythread.h"
#include <QThread>
#include <QDebug>

MyThread::MyThread(QObject *parent) : QObject(parent)
{
    isStop = false;
}

/**
 *
 * @brief MyThread::myTimeout
 */
void MyThread::myTimeout()
{
    while (isStop == false)
    {
        // 每隔一秒发送一个信号
        QThread::sleep(1);

        emit mySignal();

        qDebug() << QStringLiteral("子线程号:") << QThread::currentThread();
    }
}

void MyThread::setFlag(bool flag)
{
    isStop = flag;
}
