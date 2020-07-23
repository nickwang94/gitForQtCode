#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPainter>

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


void MyWidget::paintEvent(QPaintEvent *event)
{
    // 背景绘制一张图
    QPainter p(this);
    p.drawPixmap(0, 0, width(), height(), QPixmap("://image/github.png"));

    // 窗口设置为透明

}
