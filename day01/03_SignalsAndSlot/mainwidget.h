#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h" // 瀛愮獥鍙ｅご鏂囦欢

class MainWidget : public QWidget
{
    Q_OBJECT // 淇″彿涓庢Ы鐩稿叧锛岃繖閲屽彲浠ヤ笉瑕乣

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
