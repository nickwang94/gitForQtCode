#include "mywidget.h"
#include <QPushButton>
#include "mybutton.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    /*
     * 对于父窗口（主窗口），坐标系统相对于屏幕
     * 原点：相对于屏幕左上角
     * x轴：往右递增
     * y轴：往下递增
     **/
    move(100, 100);

    /*
     * 子窗口，坐标系统相对于父窗口
     * 原点：窗口的空白区域，不包括边框
     * x轴：往右递增
     * y轴：往下递增
     **/
    QPushButton *b1 = new QPushButton(this);
    b1->move(100, 100);
    b1->setText("这是测试按钮");
    b1->resize(200, 100);

    // 在新建一个按钮，指定其父对象为b1
    QPushButton *b2 = new QPushButton(b1);
    b2->move(10, 10);
    b2->setText("按钮中的按钮");

    MyButton *b3 = new MyButton(this);
    b3->setText("123");

    // （1）指定父对象后
    // （2）直接或间接继承QObject
    // 如果是动态分配控件
    // 不需要手动delete，系统会自动释放
}

MyWidget::~MyWidget()
{

}
