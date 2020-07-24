#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class MyWidget;
}

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = 0);
    ~MyWidget();

protected:
    // 重绘
    void paintEvent(QPaintEvent *event);
    // 鼠标移动
    void mouseMoveEvent(QMouseEvent *event);
    // 鼠标按下
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::MyWidget *ui;
    QPoint p; // 差值AAAAA
};

#endif // MYWIDGET_H
