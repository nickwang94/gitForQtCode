#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);

protected:
    // 继承基类QWidget的虚函数
    // 函数返回值，函数名，参数都要和基类相同
    // 参数ev是保存了鼠标点击的相关属性
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);

    // 进入窗口区域
    void enterEvent(QEvent *event);
    // 离开窗口区域
    void leaveEvent(QEvent *event);

signals:

public slots:
};

#endif // MYLABEL_H
