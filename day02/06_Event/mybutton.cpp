#include "mybutton.h"
#include <QMouseEvent>
#include <QDebug>
#include <QWidget>

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}

/**
 * @brief MyButton::mousePressEvent
 * @param e
 * 判断左键按下打印一句话，否则不做处理
 */
void MyButton::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton) {
        qDebug() << "MyButton::mousePressEvent--左键点击";
    } else if (e->button() == Qt::RightButton) {
        qDebug() << "MyButton::mousePressEvent--右键点击";
    } else {
        qDebug() << "MyButton::mousePressEvent--中间点击";
    }

    QPushButton::mousePressEvent(e);
}



/**
 * @brief MyButton::saySth
 * 这是槽函数
 */
void MyButton::saySth()
{
    qDebug() << "这是Mybutton的一个槽函数";
}
