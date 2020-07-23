#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this ,&Widget::saySth);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::saySth()
{
    qDebug() << "这是槽函数";
}
