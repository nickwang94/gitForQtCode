#include <QApplication>
#include <QWidget> // 窗口控件基类
#include <QPushButton>

/*
 * 如果不指定父对象，对象和对象（窗口和窗口）
 * 是独立的，如果a指定b为它的父对象，即a放在b
 * 里面。
 * 指定父对象的两种方法：
 * （1）通过setParent
 * （2）通过构造函数传参数
 * 指定父对象好处：
 * 只需要显示父对象，上面的子对象自动显示
 **/

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget w;
    w.setWindowTitle("主要看气质"); // 设置标题

    // 按钮（通过setParent函数指定父对象）
    QPushButton b;
    b.setText("这是按钮");
    b.setParent(&w); // 指定父对象
    b.move(100, 100); // 移动坐标

    // 按钮（通过构造函数传参指定父对象）
    QPushButton b1(&w);
    b1.setText("这是另一个按钮");


    // 显示父对象
    w.show();





    app.exec();
    return 0;
}
