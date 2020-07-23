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
    // 重写绘图事件，如果给窗口绘图一定要在paintEvent绘制
    void paintEvent(QPaintEvent *event);

private:
    Ui::MyWidget *ui;
};

#endif // MYWIDGET_H
