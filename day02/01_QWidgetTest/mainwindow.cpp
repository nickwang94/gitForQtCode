#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QCompleter>
#include <QStringList>
#include <QMovie>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->myButton->setText("内容已修改");

    // 获取行编辑的内容 QLineEdit
    QString str = ui->lineEdit->text();
    qDebug() << str;
    ui->lineEdit->setText("NickWang");

    // 设置内容显示的方式
    // 左边空15个像素点
    ui->lineEdit->setTextMargins(15, 0, 0, 0);
    // 以密码方式显示
    // ui->lineEdit->setEchoMode(QLineEdit::Password);

    // 添加提示
    QStringList list;
    list << "Hello" << "How are you" << "bey";
    QCompleter *com = new QCompleter(list, this);
    com->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(com);

    // QLabel
    // 设置图片
    ui->imgLabel->setPixmap(QPixmap("://image/icon.png"));

    // 创建动画
    QMovie *myMovie = new QMovie("://image/run.gif");
    // 设定动画
    ui->gifLabel->setMovie(myMovie);

    // 启动
    myMovie->start();
    ui->gifLabel->setScaledContents(true);


    // 链接
    ui->urlLabel->setText("<h1><a href=\"https://www.baidu.com\">百度一下</a></h1>");
    // 设置html跳转
    ui->urlLabel->setOpenExternalLinks(true);


    // 设置数码管lcd
    ui->lcdNumber->display(123);

    // 进度条
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(25);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_change_clicked
 * 此函数用来切换控件StackedWidget的页数
 */
void MainWindow::on_change_clicked()
{
    static int i = 0;
    ui->stackedWidget->setCurrentIndex(++i % 2);
}
