#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPainter>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // 创建绘图设备
    // 之前的绘图设备是窗口，现在不是
    QPixmap pixmap(400, 300); // 绘图设备

    QPainter p(&pixmap);

    // 填充白色背景
    // p.fillRect(0, 0, 400, 300, QBrush(Qt::white));

    pixmap.fill(Qt::white);

    p.drawPixmap(0, 0, 100, 100, QPixmap("://image/smile.png"));

    // 保存图片
    pixmap.save("pixmap.png");
}

MyWidget::~MyWidget()
{
    delete ui;
}
