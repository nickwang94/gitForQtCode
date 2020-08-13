#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>


class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);

protected:
    // 线程虚函数，处理函数
    // 不能直接调用，要使用start间接调用
    void run();

signals:
    void isDone();

public slots:
};

#endif // MYTHREAD_H
