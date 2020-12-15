#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 只针对某一个Label
    // 如果需要将所有Label修改
    // 应该使用this->setStyleSheet
    this->setStyleSheet("QLabel{"
        "color : red;"
        "background-color : rgb(0, 255, 255);"
        "font : bold;"
        "}");

    // 这个label特例
    ui->label->setStyleSheet("QLabel{"
        "color : red;"
        "background-color : blue;"
        "font : bold;"
        "background-image : url(://image/pic.png);"
        "border-image : url(://image/pic.png);"
        "}");

    // 改变按钮的样式
    ui->pushButton->setStyleSheet("QPushButton{"
                                  "border-image : url(://image/btnNromal.png);"
                                  "}"

                                  "QPushButton:hover {"
                                  "border-image : url(://image/btnHover.png);"
                                  "}"

                                  "QPushButton:pressed {"
                                  "border-image : url(://image/btnClicked.png);"
                                  "}");
}

Widget::~Widget()
{
    delete ui;
}
