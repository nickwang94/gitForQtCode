#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPainter>
#include <QBitmap>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    // QPixmap图片背景透明
    p.drawPixmap(0, 0, 100, 100, QPixmap("://image/chrome.png"));

    // QBitmap图片背景透明
    p.drawPixmap(120, 0, 100, 100, QBitmap("://image/chrome.png"));

    // QPixmap 背景白色
    QPixmap pixmap;
    pixmap.load("://image/wechat.png");
    p.drawPixmap(0, 120, 100, 100, pixmap);

    // QBitmap 背景白色
    QBitmap bitmap;
    bitmap.load("://image/wechat.png");
    p.drawPixmap(120, 120, 100, 100, bitmap);
}
