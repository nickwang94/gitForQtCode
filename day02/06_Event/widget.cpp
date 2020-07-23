#include "widget.h"
#include "ui_widget.h"
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>
#include <QCloseEvent>
#include <QMessageBox>
#include <QEvent>

int Widget::min = 0;
int Widget::sec = 0;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 启动计时器，以毫秒为单位
    timerId1 = this->startTimer(60000);
    timerId2 = this->startTimer(1000);

    // 处理按钮的信号
    // 在MyButton类中重载了鼠标按下的事件
    // 只对鼠标左键响应，此时该槽函数不会被执行
    connect(ui->pushButton, &MyButton::clicked, ui->pushButton, &MyButton::saySth);

    // 安装过滤器
    ui->timer1->installEventFilter(this);

    // 设置鼠标自动追踪
    ui->timer1->setMouseTracking(true);
}

Widget::~Widget()
{
    delete ui;
}

/**
 * @brief Widget::keyPressEvent
 * @param event
 * 键盘按下事件
 */
void Widget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << (char)event->key();

    if (event->key() == Qt::Key_F1){
        this->killTimer(timerId1);
        this->killTimer(timerId2);
        ui->timerResult->setText(QString("%1min%2sec").arg(min).arg(sec));
    }
}

/**
 * @brief Widget::timerEvent
 * @param event
 * 计时器事件
 * 应用：闹钟、幻灯片等
 */
void Widget::timerEvent(QTimerEvent *event)
{


    if (event->timerId() == this->timerId1) {
        min++;
    } else if (event->timerId() == this->timerId2) {
        sec++;
        if(sec % 60 == 0){
            sec = 0;
        }
    }

    ui->timer1->setText(QString("<center><h1>"
                               "%1 min : "
                               "</h1></center>").arg(min));
    ui->timer2->setText(QString("<center><h1>"
                               "%1 sec"
                               "</h1></center>").arg(sec));

}


/**
 * @brief closeEvent
 * @param event
 * 关闭事件
 */
void Widget::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::question(this, "Question", "是否需要关闭窗口？");

    if (ret == QMessageBox::Yes) {
        // 关闭窗口
        // 处理关闭窗口事件，接受事件，事件就不会再往下传递
        event->accept();
    } else {
        // 不关闭
        // 忽略事件，事件继续给父组件传递
        event->ignore();
    }
}

/**
 * @brief Widget::event
 * @param event
 * @return
 * 重写事件分发函数
 */
bool Widget::event(QEvent *event)
{
    if (event->type() == QEvent::Timer){
        // 关闭定时器
        // 如果返回true，事件停止传播
        QTimerEvent *env = static_cast<QTimerEvent *>(event);
        timerEvent(env);
        return true;
    } else if (event->type() == QEvent::KeyPress){
        // 只处理按键B的响应
        QKeyEvent *env = static_cast<QKeyEvent *>(event);
        if (env->key() == Qt::Key_B){
            return QWidget::event(event);
        }
        return true;
    } else {
        return QWidget::event(event);
    }
}

/**
 * @brief Widget::eventFilter
 * @param watched
 * @param event
 * @return
 * 过滤器创建
 */
bool Widget::eventFilter(QObject *watched, QEvent *event)
{
    // 对定时器的QLabel类型进行事件过滤
    if (watched == ui->timer1){
        QMouseEvent *env = static_cast<QMouseEvent *>(event);
        // 判断事件
        if (event->type() == QEvent::MouseMove){
            ui->timer1->setText(QString("Mouse Move:(%1,%2)").arg(env->x()).arg(env->y()));
            return true; // 不让这个事件继续传播
        }
    }
    return QWidget::eventFilter(watched, event);
}

