#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 菜单栏
    QMenuBar *mBar = menuBar();

    // 添加菜单
    QMenu *pFile = mBar->addMenu("文件");

    // 添加菜单项，添加动作
    // QAction* QMenu::addAction()
    QAction *pNew = pFile->addAction("新建");

    connect(pNew, &QAction::triggered,
            [=]() mutable
            {
                qDebug() << "新建被按下";
            }

            );

    // 分割线
    pFile->addSeparator();

    // 添加打开
    QAction *pOpen = pFile->addAction("打开");


    // 工具栏，菜单项的快捷方式
    QToolBar *toolBar = addToolBar("Tool Bar");

    // 工具栏添加快捷键（动作）
    // 把之前菜单栏的动作的指针直接拿过来就行
    toolBar->addAction(pNew);

    // 添加一个按钮工具栏
    QPushButton *b = new QPushButton(this);
    b->setText("另一个工具栏选项");
    toolBar->addWidget(b);

    connect(b, &QPushButton::clicked,
        [=]() mutable
        {
            b->setText("工具栏被点击");
        }
    );


    // 状态栏
    QStatusBar *staBar = statusBar();
    QLabel *label = new QLabel(this);
    label->setText("Normal text file");
    staBar->addWidget(label);
    // addWidget从左往右依次添加
    staBar->addWidget(new QLabel("2", this));
    // addPermanentWidget从右往左添加
    staBar->addPermanentWidget(new QLabel("3", this));

    // 核心控件
    QTextEdit *textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);

    // 浮动窗口
    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    QTextEdit *textEdit1 = new QTextEdit(this);
    dock->setWidget(textEdit1);

}

MainWindow::~MainWindow()
{

}
