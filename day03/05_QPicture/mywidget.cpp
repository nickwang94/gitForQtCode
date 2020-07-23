#include "mywidget.h"
#include "ui_mywidget.h"
#include <QPainter>
#include <QPicture>
#include <QImage>
#include <QPixmap>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    // 创建绘图设备(只是保存绘图的状态)
    QPicture picture;

    // 创建绘图工具
    QPainter p;
    p.begin(&picture);

    // 绘制
    p.drawPixmap(0, 0, 80, 80, QPixmap("://image/wechat.png"));

    // 画一条线
    p.drawLine(50, 50, 150, 50);

    p.end();

    // 保存的是二进制文件
    picture.save("imgFile.png");
}

MyWidget::~MyWidget()
{
    delete ui;
}

/**
 * @brief MyWidget::paintEvent
 * @param event
 * 加载配置后重绘
 * 理论上是在另一个平台的机子上进行下载
 * 这里本地加载模拟一下
 */
void MyWidget::paintEvent(QPaintEvent *event)
{

# if 0
    // 加载
    QPicture pic;
    pic.load("imgFile.png");

    // 绘制
    QPainter p(this);
    p.drawPicture(0, 0, pic);
#endif

    // 二者的相互转化
    QPainter p(this);
    QPixmap pixmap;
    pixmap.load("://image/wechat.png");

    // QPixmap转化为QImage，进行无关平台的传输
    QImage tempImage = pixmap.toImage();
    p.drawImage(0, 0, tempImage);


    QImage image;
    image.load("://image/wechat.png");

    // QImage转换成QPixmap，进行针对屏幕优化的绘制
    QPixmap tempPixmap = QPixmap::fromImage(image);
    p.drawPixmap(200, 0, tempPixmap);

}
