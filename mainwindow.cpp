#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addmovie.h"
#include "search.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionaddMovie_triggered()
{
    addMovie a;
    //a.show();  //对象不会销毁
    a.exec();
    //this->a.show();
}

void MainWindow::on_actionmovie_search_triggered()
{
    search a;
    a.exec();
}
