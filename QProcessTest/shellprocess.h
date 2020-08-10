#ifndef SHELLPROCESS_H
#define SHELLPROCESS_H

#include <QThread>
#include <QStringList>
#include <QProcess>

class ShellProcess : public QThread
{
    Q_OBJECT
public:
    explicit ShellProcess(QObject *parent = 0);
    QStringList getIpRange(); // 获取需要扫描ip的列表
    static bool isAlive(QString ip, int port, int timeout = 1000);

protected:
    void run();

signals:
    void commandSucceed(QString ip);
    void commandFailed(QString ip);

public slots:
    void setIpRange(QStringList ipRang); // 设置需要扫描ip列表
    void readResult();
    void startedThread();


private:
    void bindEvent();

    QStringList ipRange;
    QProcess *m_process;


};

#endif // SHELLPROCESS_H
