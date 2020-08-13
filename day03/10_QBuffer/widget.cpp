#include "widget.h"
#include "ui_widget.h"
#include <QBuffer> // 内存文件
#include <QDebug>
#include <QDataStream>

/**
 * QBuffer为内存文件
 */

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QByteArray array;

    QBuffer memFile(&array); // 创建内存文件
    memFile.open(QIODevice::WriteOnly);

    // 写在缓冲区中
    memFile.write("111111");
    memFile.write("222222");

    memFile.close();

    // ans "111111222222" 放在内存中连在一起
    qDebug() << memFile.buffer();
    qDebug() << array;

    QBuffer memFile1;
    memFile1.open(QIODevice::WriteOnly);
    QDataStream stream(&memFile1);
    stream << QStringLiteral("测试") << 250;
    memFile1.close();

    qDebug() << memFile1.buffer();

    memFile1.open(QIODevice::ReadOnly);
    QDataStream in;
    in.setDevice( &memFile1 );
    QString str;
    int a;
    in >> str >> a;
    qDebug() << str.toUtf8().data() << a;
}

Widget::~Widget()
{
    delete ui;
}
