#include "widget.h"
#include "ui_widget.h"

#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QFileDialog>

#define cout qDebug() << "[" << __FILE__ << ":" << __LINE__ << "]"

/*
 * 以文本流的方式操作文件
 * 其优点是可以指定编码形式
 **/

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    writeData();
    readData();
}

Widget::~Widget()
{
    delete ui;
}

/**
 * 写文件，创建文件的流对象，往流对象里写，就相当于往文件中写
 * @brief Widget::writeData
 */
void Widget::writeData()
{
    QFile file;
    file.setFileName("text.txt");

    bool isOK = file.open(QIODevice::WriteOnly);
    if (true == isOK)
    {
        QTextStream stream(&file);

        // 指定编码
        stream.setCodec("UTF-8");

        stream << QStringLiteral("你好，这是测试文本") << 250;

        file.close();
    }
}

/**
 * 读文件
 * @brief Widget::readData
 */
void Widget::readData()
{
    QFile file;
    file.setFileName("text.txt");

    bool isOK = file.open(QIODevice::ReadOnly);
    if (true == isOK)
    {
        QTextStream stream(&file);

        // 指定编码
        stream.setCodec("UTF-8");

        QString str;
        int num;

        stream >> str >> num;

        // "你好，这是测试文本250" 0
        // 该结果有误，读取时将QString和int全部读为QString，然后int输出默认值
        cout << str << num;


        file.close();
    }
}

/**
 * 按钮槽函数
 * @brief Widget::on_pushButton_clicked
 */
void Widget::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "Open", "../");
    if (false == path.isEmpty())
    {
        QFile file;
        file.setFileName(path);

        bool isOK = file.open(QIODevice::ReadOnly);
        if (true == isOK)
        {
            QTextStream stream(&file);

            // 指定编码
            stream.setCodec("UTF-8");

            // 一次性读
            QString str = stream.readAll();
            ui->textEdit->setText(str);
        }


    }

}
