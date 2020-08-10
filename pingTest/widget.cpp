#include "widget.h"
#include <QProcess>
#include <QDebug>

#define TEST_PING 1
#define TEST_GIT 1

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
#ifdef TEST_PING
    QString strPingIP = "192.168.118.181";
    QProcess pingProcess;
    QString strArg = "ping " + strPingIP + " -n 1 -i 2";
    pingProcess.start(strArg,QIODevice::ReadOnly);
    pingProcess.waitForFinished(-1);

    QString p_stdout = QString::fromLocal8Bit( pingProcess.readAllStandardOutput());
    qDebug()<<p_stdout;
#endif


#ifdef TEST_GIT
    bool res = QProcess::startDetached("git", QStringList() << "checkout" << "CPP7B_V1.0", "F:\\versionBranch\\cpp7");
    if (!res) {
        // show error message
        qDebug() << "error";
    }
#endif



}

Widget::~Widget()
{

}
