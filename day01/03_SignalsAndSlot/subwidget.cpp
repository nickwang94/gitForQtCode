#include "subwidget.h"

SubWidget::SubWidget(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("小弟");
    b.setParent(this);
    b.setText("切换到主窗口");

    connect(&b, &QPushButton::clicked, this, &SubWidget::sendSlot);

    resize(400, 300);
}

// 槽函数
void SubWidget::sendSlot()
{
    emit mySignal();
}


