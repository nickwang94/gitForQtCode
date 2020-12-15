#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDialog>
#include <QDebug>
#include <QMessageBox> // 标准对话框
#include <QFileDialog> // 文件对话框

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMenuBar *mBar = menuBar();
    QMenu *menu = mBar->addMenu("对话框");

    // 模态对话框
    QAction *p1 = menu->addAction("模态对话框");
    connect(p1, &QAction::triggered,
        [=]() mutable
        {
            QDialog dlg;
            // exec执行到这里就不会动，等着用户操作
            dlg.exec();
            qDebug() << "这是在exec后一行的输出";
        }
    );

    // 非模态对话框
    QAction *p2 = menu->addAction("非模态对话框");
    connect(p2, &QAction::triggered,
        [=]() mutable
        {
            // show方法来调用，不会阻塞
            dlg.show();
            qDebug() << "这是在show后一行的输出";

            QDialog *dlg2 = new QDialog;
            dlg2->setAttribute(Qt::WA_DeleteOnClose);
            dlg2->show();
        }
    );

    // About对话框
    QAction *p3 = menu->addAction("关于对话框");
    connect(p3, &QAction::triggered,
        [=]() mutable
        {
            QMessageBox::about(this, "About", "这是关于该Demo的介绍");
        }
    );

    // 问题对话框
    QAction *p4 = menu->addAction("问题对话框");
    connect(p4, &QAction::triggered,
        [=]() mutable
        {
            int ret = QMessageBox::question(this, "Question", "NickWang帅么？");

            switch (ret) {
            case QMessageBox::Yes:
                qDebug() << "有眼光呀兄弟";
                break;
            case QMessageBox::No:
                qDebug() << "亲，这里建议您配一下眼镜";
                break;
            default:
                break;
            }
        }
    );

    // 文件对话框
    QAction *p5 = menu->addAction("文件对话框");
    connect(p5, &QAction::triggered,
        [=]() mutable
        {
            QString path = QFileDialog::getOpenFileName(
                        this,    // 父指针
                        "Open",  // 标题
                        "../",   // 路径
                        "Souce (*.cpp *.h);;"
                        "Text (*.txt);;"
                        "All (*.*)" // 文件格式
            );
            qDebug() << path;
        }
    );

    resize(500, 200);

}

MainWindow::~MainWindow()
{

}
