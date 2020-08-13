#include "mythread.h"
#include <QPainter>
#include <QImage>
#include <QPen>
#include <QBrush>

MyThread::MyThread(QObject *parent)
    : QObject(parent)
{

}

void MyThread::drawImage()
{
    // 定义绘图设备
    QImage image(500, 500, QImage::Format_ARGB32);

    // 定义画家，指定绘图设备
    QPainter p(&image);

    // 设定画笔
    QPen pen;
    pen.setWidth(5); // 设画笔宽度

    // 把画笔交给画家
    p.setPen(pen);

    // 定义画刷
    QBrush brush;
    brush.setStyle(Qt::SolidPattern); // 样式
    brush.setColor(Qt::red); // 颜色

    // 把画刷交给画家
    p.setBrush(brush);

    // 定义5个点
    QPoint a[]
    {
        QPoint(qrand() % 500, qrand() % 500),
        QPoint(qrand() % 500, qrand() % 500),
        QPoint(qrand() % 500, qrand() % 500),
        QPoint(qrand() % 500, qrand() % 500),
        QPoint(qrand() % 500, qrand() % 500)
    };

    p.drawPolygon(a, 5);

    // 通过信号发送图片
    emit updateImage(image);
}
