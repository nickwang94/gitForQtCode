#include "mylabel.h"
#include <QMouseEvent>
#include <QDebug>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    // 设定默认追踪鼠标
    this->setMouseTracking(true);
}

/**
 * @brief MyLabel::mousePressEvent
 * @param ev 保存鼠标的相关属性
 * 鼠标点击事件
 */
void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    if (ev->button() == Qt::LeftButton){
        qDebug() << "Left";
    } else if (ev->button() == Qt::RightButton){
        qDebug() << "Right";
    } else if (ev->button() == Qt::MidButton){
        qDebug() << "Middle";
    } else {
        qDebug() << "鼠标其他按键激活";
    }

    // 字符串组包
    // QString str = QString("abc %1 like %2").arg("I").arg("nick");
    QString txt = QString("<center><h1>"
                          "Move Press : (%1 , %2)"
                          "</h1></center>").arg(ev->x()).arg(ev->y());

    this->setText(txt);
}

/**
 * @brief MyLabel::mouseReleaseEvent
 * @param ev
 * 鼠标释放事件
 */
void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    QString txt = QString("<center><h1>"
                          "Move Release : (%1 , %2)"
                          "</h1></center>").arg(ev->x()).arg(ev->y());

    this->setText(txt);
}

/**
 * @brief MyLabel::mouseMoveEvent
 * @param ev
 * 鼠标移动事件
 */
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString txt = QString("<center><h1>"
                          "Move Move : (%1 , %2)"
                          "</h1></center>").arg(ev->x()).arg(ev->y());

    this->setText(txt);
}

/**
 * @brief MyLabel::enterEvent
 * @param event
 * 鼠标进入窗口事件
 */
void MyLabel::enterEvent(QEvent *event)
{
    QString txt = QString("<center><h1>"
                          "进入窗口"
                          "</h1></center>");

    this->setText(txt);

    // 设置样式表
    this->setStyleSheet("MyLabel{"
                        "background-color : rgb(0, 155, 155);"
                        "}");
}

/**
 * @brief MyLabel::leaveEvent
 * @param event
 * 鼠标离开窗口事件
 */
void MyLabel::leaveEvent(QEvent *event)
{
    QString txt = QString("<center><h1>"
                          "离开窗口"
                          "</h1></center>");

    this->setText(txt);

    this->setStyleSheet("MyLabel{"
                        "background-color : rgb(155, 0, 155);"
                        "}");
}
