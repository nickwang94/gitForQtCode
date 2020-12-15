#include "mainwidget.h"
#include <QPushButton>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    // 实现相关控件
    b1.setParent(this);
    b1.setText("Close");
    b1.move(100, 100);

    // 另一个按钮
    b2 = new QPushButton(this);
    b2->setText("abc");

    /*
     * connect函数参数说明：
     * （1）&b1：信号发出者，指针类型
     * （2）&QPushButton::pressed：处理的信号，&发送者类名::信号名字
     * （3）this：信号接收者
     * （4）&MainWidget::close：槽函数，信号处理函数，&接收者类名::槽函数名字
     * [signal] void QAbstractButton::pressed()
     **/
    connect(&b1, &QPushButton::pressed, this, &MainWidget::close);

    /*
     * 自定义槽（普通函数的用法）
     * Qt5：任意的成员函数、普通全局函数、静态函数
     * 槽函数需要和信号参数、返回值一致
     * 由于信号都是没有返回值的，所以槽函数一定没有返回值
     *
     * [signal] void QAbstractButton::released()
     **/
    connect(b2, &QPushButton::pressed, this, &MainWidget::myslot);

    // 按钮抬起的时候将另一个按钮进行隐藏
    connect(b2, &QPushButton::released, &b1, &QPushButton::hide);

    /*
     * 信号：短信
     * 槽函数：接受短信的手机
     **/
    // 设置该窗口的名字
    this->setWindowTitle("老大");
    b3.setParent(this);
    b3.setText("切换到子窗口");
    b3.move(50, 50);

    // 显示子窗口
    // w.show();

    connect(&b3, &QPushButton::released, this, &MainWidget::changeWin);


    // 处理子窗口的信号
    connect(&w, &SubWidget::mySignal, this, &MainWidget::dealSub);


    resize(400, 300);
}

// 槽函数，实现将按钮文本更换的功能
void MainWidget::myslot()
{
    b2->setText("123");
}

// 槽函数，实现点击按钮后隐藏主窗口，显示子窗口
void MainWidget::changeWin()
{
    // 子窗口显示
    w.show();

    // 本窗口隐藏
    this->hide();
}

// 槽函数，处理子窗口的mySignal()信号
void MainWidget::dealSub()
{
    // 隐藏子窗口
    w.hide();

    // 显示主窗口
    this->show();
}


MainWidget::~MainWidget()
{

}
