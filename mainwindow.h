#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//#include "addmovie.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionaddMovie_triggered();

    void on_actionmovie_search_triggered();

private:
    Ui::MainWindow *ui;
    //addMovie a;
};

#endif // MAINWINDOW_H
