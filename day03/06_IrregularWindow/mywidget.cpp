﻿#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPainter>
#include <QMouseEvent>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // 设置为对话框
    // setWindowFlags(Qt::Dialog);

    // 去除边框
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    // 把窗口设置为透明
    // 但是窗口现在是不会移动，无法关闭的
    // 需要重写鼠标和键盘事件
    setAttribute(Qt::WA_TranslucentBackground);
}

MyWidget::~MyWidget()
{
    delete ui;
}

/**
 * @brief MyWidget::paintEvent
 * @param event
 * 重绘
 */
void MyWidget::paintEvent(QPaintEvent *event)
{
    // 背景绘制一张图
    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap("://image/github.png"));

    // 窗口设置为透明

}

/**
 * @brief mouseMoveEvent
 * @param event
 * 鼠标移动
 */
void MyWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton){
        // 鼠标按下左键
        move(event->globalPos() - p);
    }
}

/**
 * @brief MyWidget::mousePressEvent
 * @param event
 * 鼠标按下
 */
void MyWidget::mousePressEvent(QMouseEvent *event)
{
    // 左键按下就移动，右键按下就关闭
    if (event->button() == Qt::RightButton){
        close();
    } else if (event->button() == Qt::LeftButton){
        // 获取坐标差距
        // 当前点击坐标 - 窗口左上角坐标
        p = event->globalPos() - this->frameGeometry().topLeft();
    }
}



















