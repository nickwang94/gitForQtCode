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
    // 重写绘图事件，虚函数
    // 如果在窗口绘图，必须放在绘图事件中实现
    // 绘图事件内部自动调用，在窗口重绘（状态改变）的时候
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MyWidget *ui;
    int x;
};

#endif // MYWIDGET_H
