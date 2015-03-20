#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlRecord>

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    showBtn = new QPushButton("show data ",this);
    showBtn->setGeometry(QRect(20,20,100,30));
    connect(showBtn,SIGNAL(clicked()),this,SLOT(showData()));
    //this->showData();
}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::setDatabase(QSqlDatabase db)
{
    this->database = db ;
}
void MainWindow2::showData()
{
    tableView = new QTableView(this);
    tableView->setGeometry(QRect(50,80,510,200));
    tableView->show();
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("answers");
    model->select();
    tableView->setModel(model);
    QSqlQuery query ;
    query.exec("select * from answers");
    //跳到第一条记录
    query.next();
    qDebug()<<query.record().value("code").toString();
}
