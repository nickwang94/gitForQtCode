#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery> // SQL语句
#include <QVariantList>

#define cout qDebug()  << "[" << __FILE__ << " : " << __LINE__ << "]"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 打印支持的数据库驱动
    cout << QSqlDatabase::drivers();

    // 添加MySQL数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    // 配置数据库
    db.setHostName("127.0.0.1"); // 数据库服务器IP
    db.setUserName("root"); // 数据库用户名
    db.setPassword("Wangwenkun!94"); // 密码
    db.setDatabaseName("qtdatabase"); // 使用数据库名称

    // 打开数据库
    if ( false == db.open() )
    {
        QMessageBox::warning(this, QStringLiteral("错误"), db.lastError().text());
    }

    QSqlQuery query;

    // 添加表
//    query.exec("create table student("
//               "id int primary key auto_increment,"
//               "name varchar(255),"
//               "age int,"
//               "score int"
//               ");");

    // 插入
//    query.exec("insert "
//               "into student(id, name, age)"
//               "value(1, 'Nick', 25);");

    // ODBC风格插入
    // 预处理语句
    // 这里的?相当于占位符
//    query.prepare("insert into student(name, age, score) values(?, ?, ?);");
//    // 给字段设置内容 list
//    QVariantList nameList;
//    nameList << "xiaogou" << "tianmao" << "taobao";
//    QVariantList ageList;
//    ageList << 15 << 25 << 35;
//    QVariantList scoreList;
//    scoreList << 61 << 69 << 91;

//    // 给字段绑定相应的值 按顺序绑定
//    query.addBindValue(nameList);
//    query.addBindValue(ageList);
//    query.addBindValue(scoreList);

//    // 执行预处理命令
//    query.execBatch();

    // Oracal风格
    // 占位符 ":+自定义名字"
//    query.prepare("insert into student(name, age, score) values(:name, :age, :score);");
//    query.bindValue(":name", nameList);
//    query.bindValue(":score", scoreList);
//    query.bindValue(":age", ageList);
//    query.execBatch();

    // 修改
//    query.exec("update student set score=100 where id=1;"); // 该语句只有在一行时才有效

    // 查询
    query.exec("select * from student");

    while( query.next() ) // 逐行遍历
    {
        // 取出当前行的内容
        qDebug() << query.value(0).toInt()
                 << query.value(1).toString()
                 << query.value(2).toInt()
                 << query.value(3).toInt();
    }

}

Widget::~Widget()
{
    delete ui;
}

/**
 * 删除
 * @brief Widget::on_buttonDel_clicked
 */
void Widget::on_buttonDel_clicked()
{
    // 获取行编辑内容
    QString name = ui->lineEdit->text();

    QString sql = QString("delete from student where name = '%1'").arg(name);

    // 开启事务(设定一个点,该点之后的操作都可以撤销)
    QSqlDatabase::database().transaction();

    QSqlQuery query;
    query.exec(sql);
}


/**
 * 确定删除
 * @brief Widget::on_buttonOK_clicked
 */
void Widget::on_buttonOK_clicked()
{
    // 确定删除
    QSqlDatabase::database().commit();
}

/**
 * 取消删除
 * @brief Widget::on_buttonCancel_clicked
 */
void Widget::on_buttonCancel_clicked()
{
    // 回滚
    QSqlDatabase::database().rollback();
}
