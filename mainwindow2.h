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
    QPushButton *showBtn ;//展示
    QTableView *tableView ;
private slots:
    void showData();
public:
    void setDatabase(QSqlDatabase);
};

#endif // MAINWINDOW2_H
