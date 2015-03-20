#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QPushButton>
#include <QTableView>
namespace Ui {
class MainWindow2;
}

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow2(QWidget *parent = 0);
    ~MainWindow2();

private:
    Ui::MainWindow2 *ui;
    QPushButton *showBtn ;//展示数据
    QPushButton *compileBtn ;//编译按钮
    QPushButton *outputBtn ;//获取输出按钮
    QPushButton *judgeBtn ;//评判按钮
    QTableView *tableView ;//数据框

private slots:
    void showData();
    void compile();
    void output();
};

#endif // MAINWINDOW2_H
