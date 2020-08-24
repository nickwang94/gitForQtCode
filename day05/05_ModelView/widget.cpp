#include "widget.h"
#include "ui_widget.h"

#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlRecord>
#include <QDebug>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 添加数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("root");
    db.setPassword("Wangwenkun!94");
    db.setDatabaseName("qtdatabase");

    if ( false == db.open() )
    {
        QMessageBox::information(this, QStringLiteral("提示"), QStringLiteral("数据库连接失败"));
        return;
    }

    // 设置模型
    model = new QSqlTableModel(this);
    model->setTable("student"); // 指定使用哪一个表

    // 把model设置到view中
    ui->tableView->setModel(model);

    // 显示model中的数据
    model->select();

    // 设置显示的标题，修改的是view，与数据库本身无关
    model->setHeaderData(0, Qt::Horizontal, QStringLiteral("学号"));
    model->setHeaderData(1, Qt::Horizontal, QStringLiteral("姓名"));
    model->setHeaderData(2, Qt::Horizontal, QStringLiteral("年龄"));
    model->setHeaderData(3, Qt::Horizontal, QStringLiteral("分数"));

    // 设置model的编辑模式，手动提交修改
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 设置不允许在view中直接进行数据修改
//    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

Widget::~Widget()
{
    delete ui;
}



/**
 * 查找功能
 * @brief Widget::on_buttonFind_clicked
 */
void Widget::on_buttonFind_clicked()
{
    // 过滤条件直接写SQL中where的部分
    QString name = ui->lineEdit->text();
    QString str = QString("name = '%1'").arg(name);
    qDebug() << str;
    model->setFilter(str);
    model->select();
}

/**
 * 添加功能
 * @brief Widget::on_buttonAdd_clicked
 */
void Widget::on_buttonAdd_clicked()
{
    // 添加空记录
    QSqlRecord record = model->record(); // 获取空记录

    // 获取行号，从0开始，行号就是待插入空记录的位置
    int row = model->rowCount();

    // 在指定行插入空记录
    model->insertRecord(row, record);
}

/**
 * 确定提交
 * @brief Widget::on_buttonSure_clicked
 */
void Widget::on_buttonSure_clicked()
{
    // 提交动作
    model->submitAll();
}

/**
 * 取消
 * @brief Widget::on_buttonCancel_clicked
 */
void Widget::on_buttonCancel_clicked()
{
    // 取消所有动作
    model->revertAll();
    // 提交取消的动作
    model->submitAll();
}

/**
 * 删除按钮
 * @brief Widget::on_buttonDel_clicked
 */
void Widget::on_buttonDel_clicked()
{
    // 取出选中的模型
    QItemSelectionModel *sModel = ui->tableView->selectionModel();

    // 取出模型中的索引
    QModelIndexList list = sModel->selectedRows();

    // 删除所有选中的行
    for (int i = 0; i < list.count(); i++)
    {
        qDebug() << list.at(i).row();
        model->removeRow( list.at(i).row() );
    }
}
