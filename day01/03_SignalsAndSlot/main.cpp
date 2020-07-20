#include "mainwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 执行MainWidget构造函数
    // 应该把控件放到其构造函数中去写
    MainWidget w;
    w.show();

    return a.exec();
}
