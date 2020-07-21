#include "smallwidget.h"
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>

SmallWidget::SmallWidget(QWidget *parent) : QWidget(parent)
{
    // 构造两个控件的指针对象
    QSpinBox *spin = new QSpinBox(this);
    QSlider *slider = new QSlider(Qt::Horizontal, this);

    // 将控件添加布局中
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(spin);
    hLayout->addWidget(slider);

    // 实现QSpinBox与QSlider数据同步
    // 要这样写的原因是：QSpinBox::valueChanged有重载
    // 需要使用强制转换 static_cast<函数指针>()
    // 函数指针为 void (*类名::函数名)(参数)
    connect(spin, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            slider, &QSlider::setValue);

    connect(slider, &QSlider::valueChanged,
            spin, &QSpinBox::setValue);

}
