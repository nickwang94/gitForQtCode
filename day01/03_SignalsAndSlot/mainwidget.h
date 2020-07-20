#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h" // 子窗口头文件

class MainWidget : public QWidget
{
    Q_OBJECT // 信号与槽相关，这里可以不要`

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

    void myslot();
    void changeWin();
    void dealSub();

private:
    QPushButton b1;
    QPushButton *b2;
    QPushButton b3;

    SubWidget w;
};

#endif // MAINWIDGET_H
