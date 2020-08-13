#include "widget.h"
#include "ui_widget.h"
#include <QPainter>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 自定义类对象，需要分配空间
    myT = new MyThread; // 不能指定父对象

    // 创建子线程
    thread = new QThread(this);
    // 把自定义模块添加到子线程中
    myT->moveToThread(thread);
    // 启动子线程，不启动线程处理函数
    thread->start();

    // 线程处理函数通过信号槽处理
    connect(ui->pushButton, &QPushButton::clicked,
            myT, &MyThread::drawImage);

    connect(myT, &MyThread::updateImage,
            this, &Widget::getImage);

    connect(this, &Widget::destroyed,
            this, &Widget::dealClose);
}

Widget::~Widget()
{
    delete ui;
}

/**
 * 重写绘图事件
 * @brief Widget::paintEvent
 * @param event
 */
void Widget::paintEvent(QPaintEvent *event)
{
    // 创建画家，指定绘图设备为窗口
    QPainter p(this);

    // 此时的image为空，点击按钮后从线程中传过来
    p.drawImage(50, 50, image);
}

/**
 * 获取图片槽函数
 * @brief Widget::getImage
 */
void Widget::getImage(QImage temp)
{
    image = temp;
    update(); // 更新窗口，间接调用paintEvent
}

/**
 * 窗口关闭槽函数
 * @brief Widget::dealClose
 */
void Widget::dealClose()
{
    thread->quit(); // 退出线程
    thread->wait(); // 回收资源

    delete myT;
}
