/*
 * Method 1
 * QPainter p; // 创建绘图工具
 * p.begin(this); // 指定当前窗口为绘图设备
 * // 绘图操作
 * p.end(); // 结束
 *
 * Method 2
 * QPainter(this);
 */

#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPainter>
#include <QPen>
#include <QBrush>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    x = 0; //笑脸图片的x坐标
}

MyWidget::~MyWidget()
{
    delete ui;
}

/**
 * @brief MyWidget::paintEvent
 * @param
 * 重写绘图事件A
 */
void MyWidget::paintEvent(QPaintEvent *)
{
    // 构造函数参数需要一个绘图设备
    QPainter p;
    // 指定该窗口为绘图设备
    p.begin(this);

    // 绘图操作 p.drawxxx();
    // 画背景图
    // p.drawPixmap(0, 0, width(), height(), QPixmap("://image/bg.png"));
    p.drawPixmap(rect(), QPixmap("://image/bg.png"));

    // 创建画笔
    QPen pen;
    pen.setWidth(5); // 设置线宽
    pen.setColor(QColor(14, 9, 234)); // 设置颜色
    pen.setStyle(Qt::DashLine); // 设置风格

    // 创建画刷
    QBrush brush;
    brush.setColor(Qt::red);
    brush.setStyle(Qt::Dense1Pattern);

    // 把画笔交给绘图设备
    p.setPen(pen);
    p.setBrush(brush);

    // 画直线
    p.drawLine(50, 50, 500, 50);
    p.drawLine(50, 50, 50, 500);

    // 画矩形
    p.drawRect(100, 100, 200, 200);

    // 画圆
    p.drawEllipse(150, 150, 100, 100);

    // 画笑脸
    p.drawPixmap(x, 300, 80, 80, QPixmap("://image/smile.png"));

    p.end();

}

/**
 * @brief MyWidget::on_pushButton_clicked
 * 界面ui按钮的槽
 * 通过“转到槽”生成
 */
void MyWidget::on_pushButton_clicked()
{
    x += 30;
    if (x > width() - 80){
        x = 0;
    }
    // 刷新窗口，让窗口重绘
    // 注意update函数不能放在paintEvent中，不停刷新
    update();
}
