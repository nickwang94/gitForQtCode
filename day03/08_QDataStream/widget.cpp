#include "widget.h"
#include <QDataStream> // 二进制，视频、音频，文件灵活
#include <QFile>
#include <QDebug>

#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    writeData();
    readData();
}

Widget::~Widget()
{

}

/**
 * 写二进制文件
 * @brief Widget::writeData
 */
void Widget::writeData()
{
    QFile file("../text.txt");

    // 打开文件，只写，文件最后保存为二进制
    bool isOK = file.open(QIODevice::WriteOnly);
    if (isOK == true)
    {
        // 创建数据流，和file文件关联
        QDataStream stream(&file);

        // 往数据流中写数据，相当于往文件写数据
        stream << QString("NickWang") << 250;

        // 关闭文件
        file.close();
    }
}

/**
 * 读二进制文件
 * @brief Widget::readData
 */
void Widget::readData()
{
    QFile file("../text.txt");

    // 打开文件，只写，文件最后保存为二进制
    bool isOK = file.open(QIODevice::ReadOnly);
    if (isOK == true)
    {
        // 创建数据流，和file文件关联
        QDataStream stream(&file);

        // 读的时候，按写的顺序取数据
        QString str;
        int num;

        stream >> str >> num;

        file.close();
        cout << str.toUtf8().data() << num;
    }
}
