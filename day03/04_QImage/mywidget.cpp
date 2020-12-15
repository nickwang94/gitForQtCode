#include "mywidget.h"
#include "ui_mywidget.h"
#include <QImage>
#include <QPainter>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // 绘图设备
    // QImage::Format_ARGB32 背景为透明
    QImage image(400, 300, QImage::Format_ARGB32);

    // 设定绘图工具
    QPainter p(&image);

    // 开始绘图
    p.drawImage(0, 0, QImage("://image/chrome.png"));

    // 对像素进行操作
    for (int i = 0; i < 50; i++){
        for (int j = 0; j < 50; j++){
            image.setPixel(i, j, qRgb(100, 100, 100));
        }
    }

    // 保存
    image.save("image.png");

}

MyWidget::~MyWidget()
{
    delete ui;
}
