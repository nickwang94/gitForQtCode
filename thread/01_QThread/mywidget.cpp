#include "mywidget.h"
#include "ui_mywidget.h"

#include <QThread>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    myTimer = new QTimer(this);

    // 只要定时器启动，自动触发timeout
    connect(myTimer, &QTimer::timeout, this, &MyWidget::dealTimer);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::dealTimer()
{
    static int i = 0;
    i++;

    ui->lcdNumber->display(i);
}

void MyWidget::on_pushButton_clicked()
{
    if (myTimer->isActive() == false)
    {
        myTimer->start(100);
    }

    // 复杂的数据处理，耗时时间长
    QThread::sleep(5);

    // 处理完数据之后，关闭定时器
    // myTimer->stop();
    qDebug() << "over";
}
