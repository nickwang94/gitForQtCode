#include "mythread.h"

MyThread::MyThread(QObject *parent)
    : QThread(parent)
{

}

void MyThread::run()
{
    // 假设这是一个复杂的数据处理
    // 需要耗时5秒
    sleep(5);

    // 发送信号，告诉别人这里做完了
    emit isDone();
}
