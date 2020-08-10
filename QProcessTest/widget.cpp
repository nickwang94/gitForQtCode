#include "widget.h"
#include "shellprocess.h"
#include <QDebug>

void Widget::slot_onCommandSucedded(QString)
{
    qDebug() << QStringLiteral("成功");
}

void Widget::slot_onCommandFailed(QString)
{
    qDebug() << QStringLiteral("失败");
}

void Widget::deleteLater()
{
    qDebug() << QStringLiteral("完成");
}

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QStringList ipLst;
    ipLst << "192.168.118.161"
          << "192.168.118.173"
          << "192.168.118.184"
          << "192.168.118.182"
          << "192.168.118.181";

    ShellProcess *shellProcess = new ShellProcess();
    shellProcess->setIpRange(ipLst);

    connect(shellProcess, SIGNAL(commandSucceed(QString)),
            this, SLOT(slot_onCommandSucedded(QString)));
    connect(shellProcess, SIGNAL(commandFailed(QString)),
            this, SLOT(slot_onCommandFailed(QString)));
    connect(shellProcess, SIGNAL(finished()),
            this, SLOT(deleteLater()));

}

Widget::~Widget()
{

}
