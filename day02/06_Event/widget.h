#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    // 键盘按下事件
    void keyPressEvent(QKeyEvent *event);

    // 计时器
    void timerEvent(QTimerEvent *event);


    // 关闭事件
    void closeEvent(QCloseEvent *event);


private:
    Ui::Widget *ui;
    int timerId1;
    int timerId2;
    static int sec;
    static int min;
};

#endif // WIDGET_H
