#include "widget.h"
#include "ui_widget.h"

#include <QFile>
#include <QFileDialog>
#include <QFileInfo> // 存储文件信息
#include <QDebug>
#include <QDateTime>

#define READ_ALL 1

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

/**
 * 读文件
 * @brief Widget::on_buttonRead_clicked
 */
void Widget::on_buttonRead_clicked()
{
    QString path = QFileDialog::getOpenFileName(this,
                "Open", "../", "TXT(*.txt)");

    if (path.isEmpty() == false)
    {
        // 文件对象
        QFile file(path);

        // 只读方式打开
        bool isOK = file.open(QIODevice::ReadOnly);
        if (isOK == true)
        {
#ifdef READ_ALL
            // 读文件，默认只识别UTF-8的编码
            QByteArray array = file.readAll();

            // 文本显示
            ui->textEdit->setText(QString(array));
#endif

#ifdef READ_LINE
            QByteArray array;
            while (file.atEnd() == false)
            {
                // 读一行
                array += file.readLine();
            }
            ui->textEdit->setText(array);
#endif

            // 关闭文件
            file.close();

            // 获取文件信息，不需要打开文件
            // 如果文件名中有中文，.toUtf8().data()
            QFileInfo info(path);
            qDebug() << QStringLiteral("文件名:") << info.fileName();
            qDebug() << QStringLiteral("文件后缀:") << info.suffix();
            qDebug() << QStringLiteral("文件大小:") << info.size();
            qDebug() << QStringLiteral("文件创建时间:") << info.created().toString("yyyy-MM-dd hh:mm:ss");
        }
    }
}

/**
 * 保存文件
 * @brief Widget::on_buttonWrite_clicked
 */
void Widget::on_buttonWrite_clicked()
{
    // 保存路径
    QString path = QFileDialog::getSaveFileName(this, "Save", "../", "TXT(*.txt)");
    if (path.isEmpty() == false)
    {
        QFile file; // 创建文件对象
       // 关联文件名字
        file.setFileName(path);

        // 打开文件，只读方式
        bool isOK = file.open(QIODevice::WriteOnly);
        if (isOK == true)
        {
            QString str = ui->textEdit->toPlainText();

            // 写文件
            // QString->QByteArray
            // 中文 toUtf8()
            // 本地编码 toLocal8Bit()--为windos默认编码ANSI
            // QByteArray->char*--data()
            // char*->QString--QString(.)
            file.write(str.toUtf8());
        }
        file.close();
    }
}
