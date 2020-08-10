#include "shellprocess.h"

#include <QtCore>
#include <QTcpSocket>

ShellProcess::ShellProcess(QObject *parent)
    : QThread(parent)
{
    m_process = new QProcess(this);
    this->bindEvent();
}

void ShellProcess::bindEvent()
{
    connect(this, SIGNAL(started()),
            this, SLOT(startedThread()));
    connect(m_process, SIGNAL(readyReadStandardOutput()),
            this, SLOT(readResult()));
}

QStringList ShellProcess::getIpRange()
{
    return this->ipRange;
}

void ShellProcess::setIpRange(QStringList ipRang)
{
    this->ipRange = ipRang;
}

// 解析
void ShellProcess::readResult()
{
    QProcess *ping = qobject_cast<QProcess *>(sender());
    if (!ping)
    {
        return;
    }

    QTextCodec *codec = QTextCodec::codecForName("GBK");//指定QString的编码方式
    QString res = codec->toUnicode( ping->readAllStandardOutput() );
    QString ip = ping->arguments().last();

    if (!res.contains('%'))
        return;
    const int percent = res.mid(res.indexOf('('), res.indexOf(')')).section('%', 0, 0).remove('(').toInt();
    qDebug()<<res<<percent;
    if ( percent == 100 ) {
        qDebug() << ip << "host not found.";
        emit commandFailed(ip);
    } else {
        qDebug() << ip << "host found.";
        emit commandSuccess(ip);
    }
}

void ShellProcess::startedThread()
{
    QString ip;
    foreach (ip, ipRange)
    {
       QString strArg = "ping -n 1 -i 2 " + ip;
       m_process->start(strArg); // 异步，才可以看到输出
       m_process->execute(strArg); // 同步，直接打印
    }
}

void ShellProcess::run()
{
    QString ip;
    foreach( ip, ipRange )
    {
        qDebug() << "ping " + ip;
        int exitCode = 0;

        //启动一个ping进程，然后等待该进程结束。
        QString strArg = "ping " + ip + " -n 1 -i 2";
        exitCode = QProcess::execute(strArg);

        if ( 0 == exitCode ) {
            // it's alive
            qDebug() << "shell ping " + ip + " success";
            emit commandSuccess(ip);
        } else {
            qDebug() << "shell ping " + ip + " failed";
            emit commandFailed(ip);
        }
    }

}


