# Day 1（2020-07-18）

## 1. QT介绍

### 1.1 什么是QT？

Qt是一个**跨平台**的c++**图形用户界面应用程序框架**。

> Qt是一个框架，这个框架是用来做用户图形界面编程，GUI编程。
>
> 其特点是跨平台

### 1.2 Qt历史

- 1991年 Qt最早由奇趣科技开发
- 1996年 进入商业领域，目前流行的Linux砖面环境KDE的基础
- 2008年 奇趣科技被诺基亚公司收购，Qt称为诺基亚旗下编程语言
- 2012年 Qt又被Digia公司收购
- 2014年 扩平台集成开发环境Qt Creator3.1.0发布，同年5月配发Qt5.3，至此实现对iOS、Android、WP等各平台全面支持。

### 1.3 支持平台

- Windows - XP、Vista、Win7、Win8、Win2008、Win10
- Uinux/X11 - Linux、Sun Solaris、HP-UX、Compaq
- Macintosh - Mac OS X
- Embedded - 由帧缓冲支持的嵌入式Linux平台

## 2. Qt框架

### 2.1 新建项目

- 选择Qt Widgets Application

![1595056985368](image\1595056985368.png)

- 创建项目不可以包含中文

<img src="image\1595057150044.png" alt="1595057150044" style="zoom:80%;" />

- 选择编译的套件，这里选择MinGW

![1595057179765](image\1595057179765.png)

- 在类信息中取消勾选窗口的创建

![1595057393386](image\1595057393386.png)

- 对于基类，Qt提供三个类，选择QWidget类

> QMainWindow 在PC中使用，带菜单栏
>
> QWidget 所有控件的基类
>
> QDialog 对话框

![1595057442571](C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595057442571.png)

图中的类名是子类的名字，取名为"MyWidget"，Qt会为我们自动生成一个类：

`class MyWidget:public QWidget`

- 界面说明

![1595057794975](C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595057794975.png)

> 第一个是“编译-运行”
>
> 第二个是“编译-调试”
>
> 第三个是“编译-不运行”

快捷键：Ctrl+R

- 结果

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595057960797.png" alt="1595057960797" style="zoom:50%;" />

一个空窗口

## 2.2 目录结构

![1595058553360](C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595058553360.png)

- 项目文件

每一个应用程序都对应一个项目文件 “01_QtTest.pro”

- main.cpp

主函数

- mywidget.h

该头文件自动生成“MyWidget”类

- mywidget.cpp



1. 从main.cpp文件开始看起：

![1595059331056](C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595059331056.png)

2. 看一下.h文件：

![1595059535411](C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595059535411.png)

其中“**Q_OBJECT**”是使用信号与槽的时候才用到的，这里可以对其进行屏蔽，不影响结果

> 快捷键说明，将光标锁定到文件中，按“**F4**”跳转至对应cpp文件
>
> "**Alt+0**"切换左边的文件管理窗口
>
> “**F1**”帮助文档

3. 看一下项目文件pro

![1595061361035](C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595061361035.png)

- 首先将光标放到.h文件中QWidget上，按F1调到对应的帮助文档，如下图，其中可以看到头文件“QWidget”需要包含的“***模块***”

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595059987980.png" alt="1595059987980" style="zoom:80%;" />

- TARGET后面对应的是应用程序的名字

![1595060253075](C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595060253075.png)

可执行程序的文件夹可以删除，删除后，修改“TARGET”后的名字为“NickTest”，重新编译项目，可以看到应用程序的名字已经被改变了

![1595060428638](C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595060428638.png)

## 2.3 QT基本模块

![1595061282331](C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595061282331.png)

# 3. 第一个Qt程序

## 3.1 创建一个新的空项目

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595061507796.png" alt="1595061507796" style="zoom:80%;" />

## 3.2 项目文件中添加模块

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595061694913.png" alt="1595061694913" style="zoom:80%;" />

## 3.3 添加main文件

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595061758582.png" alt="1595061758582" style="zoom:80%;" />

![1595061781553](C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595061781553.png)

1. 编写基本的框架

```c++
#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.exec();
    return 0;
}
```

2. 创建一个窗口QWidget

```c++
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // 创建窗口
    QWidget w;
    // 显示父对象
    w.show();

    app.exec();
    return 0;
}
```

3. 创建按钮QPushbutton

```c++
	// 窗口
	QWidget w;
    w.setWindowTitle("主要看气质"); // 设置标题
	w.show();
    // 按钮
    QPushButton b;
    b.setText("这是按钮");
    b.show();
```

- 其结果为：

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595063759383.png" alt="1595063759383" style="zoom:50%;" />

- 但是这并不是我们想要的效果，其原因是：

>如果不指定***父对象***，对象和对象（窗口和窗口）之间是独立的。
>
>指定父对象的方法有两种：
>
>（1）通过setParent(指针)
>
>（2）通过构造函数传参数
>
>指定父对象的好处：
>
>只需要显示父对象，上面的子对象自动显示

- 因此，修改代码为：

```c++
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget w;
    w.setWindowTitle("主要看气质"); // 设置标题
    // 按钮
    QPushButton b;
    b.setText("这是按钮");
    b.setParent(&w);
    // 显示父对象
    w.show();

    app.exec();
    return 0;
}
```

- 修改后的效果为：

![1595064088713](C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595064088713.png)

4. 移动button

```c++
 	QPushButton b;
    b.setText("这是按钮");
    b.setParent(&w); // 指定父对象
	b.move(100, 100); // 移动坐标
	
```

![1595064549167](C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595064549167.png)

5. 通过构造函数创建子对象

```c++
	// 按钮（通过构造函数传参指定父对象）
    QPushButton b1(&w);
    b1.setText("这是另一个按钮");
```

- 其结果为：

![1595065056485](C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595065056485.png)

# 4. 标准信号和槽

## 4.1 一个错误的示范

不要将控件的创建放入构造函数中：

![1595066062528](C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595066062528.png)

否则将无法显示控件。应该在.h文件中声明控件，在构造函数中创建。

- 头文件

![1595066294507](C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595066294507.png)

- cpp文件

![1595066318986](C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595066318986.png)

## 4.2 查看一个类的信号

- 通过类名找到对应的信号

- 首先对QPushbutton点击F1

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595066987521.png" alt="1595066987521" style="zoom:80%;" />

- 在Contents中并没有找到Signal
- 看QPushButton类介绍

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595067043488.png" alt="1595067043488" style="zoom:80%;" />

- 发现该类继承于QAbstractButton，点击继续查看

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595067095425.png" alt="1595067095425" style="zoom:80%;" />

- 在QAbstractButton中看到了Signal，点击查看

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595067130570.png" alt="1595067130570" style="zoom:80%;" />

- 继续点击“pressed”信号

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595067161009.png" alt="1595067161009" style="zoom:80%;" />

- 可以看到***<u>pressed</u>***信号是在按钮被按下时发送（emitted）

## 4.3 connect函数

- 知道了信号后，通过<u>***connect***</u>函数来进行信号与槽的链接

```c++
/*
     * connect函数参数说明：
     * （1）&b1：信号发出者，指针类型
     * （2）&QPushButton::pressed：处理的信号，&发送者类名::信号名字
     * （3）this：信号接收者
     * （4）&MainWidget::close：槽函数，信号处理函数，&接收者类名::槽函数名字
     **/
connect(&b1, &QPushButton::pressed, this, &MainWidget::close);
```

## 4.4 自定义槽函数

1. h文件中添加槽函数定义

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595207968096.png" alt="1595207968096" style="zoom:80%;" />

2. cpp文件中实现函数

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595208013715.png" alt="1595208013715" style="zoom:80%;" />

- 现在是窗口来接受信号
- 接下来使用另一个按钮来接受信号

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595208197116.png" alt="1595208197116" style="zoom:80%;" />

- 将信号可以理解为短信，而槽函数就是接受短信的手机，一条短信可以发送给不同的手机

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595208369935.png" alt="1595208369935" style="zoom:80%;" />

## 4.5 两个独立窗口

1. 创建两个独立的窗口

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595208640630.png" alt="1595208640630" style="zoom:80%;" />

2. 新建按钮，并设置相关属性

- 头文件添加一个按钮

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595208868853.png" alt="1595208868853" style="zoom:80%;" />

- 设置该按钮的相关属性

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595208888721.png" alt="1595208888721" style="zoom:80%;" />

3. 添加新窗口

- 右击项目新建一个c++类

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595208959347.png" alt="1595208959347" style="zoom:80%;" />

- 新建类名为“SubWidget”
- 然后在其头文件中添加按钮

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595209384760.png" alt="1595209384760" style="zoom:80%;" />

- 在其cpp文件构造函数中设置按钮父窗口

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595209424232.png" alt="1595209424232" style="zoom:80%;" />

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595212987919.png" alt="1595212987919" style="zoom:80%;" />

- 开始时显示主窗口隐藏子窗口

4. 点击主窗口按钮，隐藏自己，显示子窗口

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595214993172.png" alt="1595214993172" style="zoom:80%;" />

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595215008725.png" alt="1595215008725" style="zoom:80%;" />

5. 点击子窗口按钮，隐藏自己，显示父窗口

- 因为子窗口没有父窗口的指针，因此不能直接另父窗口显示
- 解决办法：

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595215634746.png" alt="1595215634746" style="zoom:80%;" />

- 子窗口类定义

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595215701413.png" alt="1595215701413" style="zoom:80%;" />

- 主窗口创建连接

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595215749721.png" alt="1595215749721" style="zoom:80%;" />

- 槽函数处理

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595215771050.png" alt="1595215771050" style="zoom:80%;" />

5. 一个小问题

- 将项目用另一台机子打开或者放在别的路径打开后编译会出现问题

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595222710499.png" alt="1595222710499" style="zoom:80%;" />

## 4.6 带参数的信号

1. 信号的重载

- 信号是可以重载的

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595224042917.png" alt="1595224042917" style="zoom:80%;" />

- 然后在之前的槽函数中发送两个信号，一个带参数，一个不带参数

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595224086144.png" alt="1595224086144" style="zoom:80%;" />

- 但是，信号重载之后会出现一个问题，之前的connect函数会出现编译错误

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595224225396.png" alt="1595224225396" style="zoom:80%;" />

- 因此为了解决重载的信号无法区分，需要使用函数指针

> 函数：void fun(int) {//...}
>
> 函数指针：void (*p)(int) = fun;

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595224336010.png" alt="1595224336010" style="zoom:80%;" />

- 然后处理重载信号的槽函数

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595224393947.png" alt="1595224393947" style="zoom:80%;" />

- 问题：如果输出的int没问题，但是str乱码，还需要将其转成UTF-8

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595224635023.png" alt="1595224635023" style="zoom:80%;" />

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595224535752.png" alt="1595224535752" style="zoom:80%;" />

2. Qt4风格的信号和槽函数

- 信号使用宏SIGNAL

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595225065064.png" alt="1595225065064" style="zoom:80%;" />

- 槽函数使用宏SLOT

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595225122963.png" alt="1595225122963" style="zoom:80%;" />

- 但是此处的槽函数必须要在类声明中使用关键字public || private slots:来修饰

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595225191763.png" alt="1595225191763" style="zoom:80%;" />

3. <u>***问题***</u>

- 为什么SIGNAL和SLOT宏这么好用，Qt5缺不再继续使用？

> 原因：
>
> （1）宏是将函数名字转换成字符串，而不进行错误检查
>
> （2）槽函数必须要使用slots关键字来修饰
>
> 例如：信号名字如果拼写错了，在Qt5的风格上直接就会显示编译错误
>
> 而Qt4的方式编译不会报错，只有在运行的时候才会提示，因为使用宏只要是字符串就行

## 4.7 Lamda表达式与信号的功能探究

1. 因为Lamda是c++11的新特性，Qt与信号结合使用很方便，需要在项目文件中添加CONFIG

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595225821537.png" alt="1595225821537" style="zoom:80%;" />

2. 使用Lamda表达式

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595227105064.png" alt="1595227105064" style="zoom:80%;" />

- 方便，不用写接收者和槽函数

3. 使用Lamda表达式修改按钮的文本

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595227206719.png" alt="1595227206719" style="zoom:80%;" />

- 编译会报错，其原因是表达式不能够识别b4这个控件
- 解决办法是将b4通过[]进行值传递

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595227290239.png" alt="1595227290239" style="zoom:80%;" />

- 需要传递多个值时使用逗号分隔，但是如果传入的值十分多，这种方式太过于复杂，使用**[=]**表示将所有的局部变量、类的成员函数以值传递的方式进行传递

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595227433311.png" alt="1595227433311" style="zoom:80%;" />

- 但是，由于是使用值传递，因此系统认为这些传进来的值是read-only的，如果想要改变其值，需要使用**mutable**

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595227563946.png" alt="1595227563946" style="zoom:80%;" />

- 多次点击按钮，可以在控制台看到输出的局部变量值已经修改了

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595227624495.png" alt="1595227624495" style="zoom:80%;" />

4. 如果信号带有参数

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595228160104.png" alt="1595228160104" style="zoom:80%;" />

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595228194202.png" alt="1595228194202" style="zoom:80%;" />

5. <u>***一个问题***</u>

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595228596423.png" alt="1595228596423" style="zoom:80%;" />

- 当点击按钮“切换到主窗口”后，信号是窗口发的，还是按钮发的？
- 看具体代码可知，按钮只是出发槽函数，槽函数发送了信号，而槽函数是属于窗口的，因此是窗口发送了信号

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595228532272.png" alt="1595228532272" style="zoom:80%;" />

- 另一个例子，点击“Close”按钮后窗口会关闭，关闭这个功能其实和按钮一点关系都没有。因为按钮被点击之后，会调用一个回调函数（软件中断），至于回调函数做什么按钮就不知道了。

## 4.8 坐标系统

1. 新创建一个项目

- 名字：04_QtCoordinate
- 生成类：Mywidget

2. 在类的构造函数中使用move函数来观察坐标系统

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595229758344.png" alt="1595229758344" style="zoom:80%;" />

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595229859449.png" alt="1595229859449" style="zoom:60%;" />

3. 子窗口的位置

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595230077701.png" alt="1595230077701" style="zoom:80%;" />

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595230119883.png" alt="1595230119883" style="zoom:80%;" />

4. 再创建一个按钮，并指定其父对象为b1

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595230348651.png" alt="1595230348651" style="zoom:80%;" />

- 按钮b2的坐标系统是相对于父窗口（b1按钮）而言的

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595230332379.png" alt="1595230332379" style="zoom:80%;" />

## 4.9 内存回收机制

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595230829492.png" alt="1595230829492" style="zoom:80%;" />

1. 为了验证Qt对象树的机制，需要在析构函数中输出信息，看系统会不会自动调用析构函数
2. 但是QPushButton并不是我们自己写的，不能在其析构函数中输出，因此自己新建一个c++类

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595231000451.png" alt="1595231000451" style="zoom:80%;" />

- 其名字为MyButton

3. 将其父类更改为QPushButton

- h头文件中

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595231146020.png" alt="1595231146020" style="zoom:80%;" />

- cpp构造函数中

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595231169131.png" alt="1595231169131" style="zoom:80%;" />

4. 为MyButton添加一个析构函数

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595231518371.png" alt="1595231518371" style="zoom:80%;" />

- 在析构函数中进行信息输出

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595231562994.png" alt="1595231562994" style="zoom:80%;" />

- 当窗口被关闭时，可以看到此条信息

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595231608783.png" alt="1595231608783" style="zoom:80%;" />

## 4.10 菜单栏和工具栏

1. 定义

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595232085016.png" alt="1595232085016" style="zoom:80%;" />

2. 新建项目

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595231987030.png" alt="1595231987030" style="zoom:80%;" />

3. 查看QMainWindow的帮助文档

- 文档中提供很多公有函数

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595232724886.png" alt="1595232724886" style="zoom:80%;" />

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595232795069.png" alt="1595232795069" style="zoom:80%;" />

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595232834521.png" alt="1595232834521" style="zoom:80%;" />

4. 创建菜单栏

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595233397537.png" alt="1595233397537" style="zoom:80%;" />

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595233536065.png" alt="1595233536065" style="zoom:80%;" />

5. 查看帮助文档<u>***QAction***</u>的信号

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595233790523.png" alt="1595233790523" style="zoom:80%;" />

- 使用Lamda表达式来处理该信号

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595234068735.png" alt="1595234068735" style="zoom:80%;" />

- 点击“新建”后会看到输出信息

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595234168087.png" alt="1595234168087" style="zoom:80%;" />

- 添加分隔符

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595234884919.png" alt="1595234884919" style="zoom:80%;" />

5. 创建工具栏

- 工具栏实际是菜单栏的快捷键

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595234927241.png" alt="1595234927241" style="zoom:80%;" />

- 添加后会有一个空的工具栏

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595235012130.png" alt="1595235012130" style="zoom:80%;" />

- 创建“新建”的工具栏，直接将菜单栏的指定按钮的Action指针作为参数

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595235179033.png" alt="1595235179033" style="zoom:80%;" />

- 可以看到创建的工具栏已经出来了

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595235161701.png" alt="1595235161701" style="zoom:80%;" />

- 点击该工具栏，会输出菜单栏新建的相应信息

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595235308365.png" alt="1595235308365" style="zoom:80%;" />

- 再添加一个按钮工具栏，点击后更改按钮的文本

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595235611583.png" alt="1595235611583" style="zoom:80%;" />

6. 添加状态栏

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595236094855.png" alt="1595236094855" style="zoom:80%;" />

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595236155821.png" alt="1595236155821" style="zoom:80%;" />

7. 核心控件

- 核心控件就是正中间的空间
- 核心控件添加一个文本编辑器QTextEdit

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595236413720.png" alt="1595236413720" style="zoom:80%;" />

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595236393849.png" alt="1595236393849" style="zoom:80%;" />

8. 浮动窗口

- 添加一个浮动窗口

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595236707935.png" alt="1595236707935" style="zoom:80%;" />

- 分享一个小技巧

>对于函数addDockWidget不知道参数的时候需要看帮助文档，但是对着函数按F1的时候会出现：
>
><img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595236790433.png" alt="1595236790433" style="zoom:80%;" />
>
>此时，应该先将函数的参数补齐，例如addDockWidget(1, 2)，然后将光标指向函数名按F1
>
><img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595236879080.png" alt="1595236879080" style="zoom:80%;" />
>
>可以看到第一个参数是表示dock的位置，这个参数是一个枚举类型，继续点击可以进行查看：
>
><img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595236936168.png" alt="1595236936168" style="zoom:80%;" />

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595236983004.png" alt="1595236983004" style="zoom:80%;" />

## 4.11 模态和非模态对话框

1. 模态对话框

- 阻塞，执行的时候会一直等待用户操作，对话框关闭后才继续执行代码
- 使用exec调用

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595237716201.png" alt="1595237716201" style="zoom:80%;" />

- 直到关闭该对话框，才能看到qDebug()输出

2. 非模态对话框

- 不阻塞，程序继续向后执行
- 不可以用局部变量，否则对话框一闪而过
- 可以将QDialog声明为QMainWindow的数据成员
- 后续的输出不受影响

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595238067183.png" alt="1595238067183" style="zoom:80%;" />

- 也可以动态分配空间，但是<u>***此方法不好***</u>，因为程序结束的时候才能够析构，如果这个按钮是经常按的，在程序结束之前，不停的new空间，但是不释放，会占用空间。

- 但是并不代表动态分配空间不可以使用，需要设置一个属性。创建的时候**不指定父对象**。

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595238377675.png" alt="1595238377675" style="zoom:80%;" />

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595238515363.png" alt="1595238515363" style="zoom:80%;" />

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595238611492.png" alt="1595238611492" style="zoom:80%;" />

## 4.11 标准对话框和文件对话框

1. 标准对话框QMessageBox

- 查看帮助文档

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595238860624.png" alt="1595238860624" style="zoom:80%;" />

- 查看Static Public Members

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595238962023.png" alt="1595238962023" style="zoom:80%;" />

2. 关于对话框

- 静态成员函数直接使用类名来调用

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595239086181.png" alt="1595239086181" style="zoom:80%;" />

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595239434686.png" alt="1595239434686" style="zoom:80%;" />

3. 问题对话框

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595241465668.png" alt="1595241465668" style="zoom:80%;" />

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595241615794.png" alt="1595241615794" style="zoom:80%;" />

4. 文件对话框

- 代码

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595241883763.png" alt="1595241883763" style="zoom:80%;" />

- 结果

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595241800504.png" alt="1595241800504" style="zoom:50%;" />

- 输出

<img src="C:\Users\wangwk-a\AppData\Roaming\Typora\typora-user-images\1595241824242.png" alt="1595241824242" style="zoom:80%;" />









