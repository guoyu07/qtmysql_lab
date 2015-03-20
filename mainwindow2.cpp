#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include <QTableView>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QStringList>

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);
    showBtn = new QPushButton("show data ",this);
    showBtn->setGeometry(QRect(20,20,100,30));
    compileBtn = new QPushButton("compile",this);
    compileBtn->setGeometry(QRect(120,20,70,30));
    outputBtn = new QPushButton("output",this);
    outputBtn->setGeometry(QRect(190,20,70,30));
    connect(showBtn,SIGNAL(clicked()),this,SLOT(showData()));
    connect(compileBtn,SIGNAL(clicked()),this,SLOT(compile()));
    connect(outputBtn,SIGNAL(clicked()),this,SLOT(output()));
}

MainWindow2::~MainWindow2()
{
    delete ui;
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
    query.exec("select * from answers where status = 'pending'");
    //跳到第一条记录
    query.next();
    qDebug()<<query.record().value("code").toString();
    //将代码取出保存
    QFile file("E:/qt_test/corelab/code/and.c");
    if(file.open(QIODevice::ReadWrite))
    {
        QTextStream out(&file);
        out<<query.record().value("code").toString();
    }
}
//编译程序
void MainWindow2::compile()
{
    QProcess *comProcess = new QProcess ;
    QStringList opt ;
    opt<<"-w"<<"-o"<<"E:/qt_test/coreLab/exe/and.exe";
    QString tempString = "E:/qt_test/coreLab/code/and.c";
    opt<<tempString;
    comProcess->start("gcc",opt);
    //comProcess->close();
}
//获取输出结果
void MainWindow2::output()
{
    QProcess *exeProcess = new QProcess ;
    exeProcess->setStandardInputFile("E:/qt_test/coreLab/input/input.txt");
    exeProcess->setStandardOutputFile("E:/qt_test/coreLab/output/output.txt");
    exeProcess->start("E:/qt_test/coreLab/exe/and.exe");
}
