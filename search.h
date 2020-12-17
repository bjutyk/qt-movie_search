#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include <QFile>
#include <QList>
#include <QString>
#include <QStandardItem>
#include <QStandardItemModel>

#include "QVariant"

namespace Ui {
class search;
}

class search : public QDialog
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = nullptr);
    ~search();
    int readFromFile();
    void doQuert(int index,QString cnt);
    void display(int row,QStringList subs);//按行显示txt中文本
    void doSorting(int index);///////////////////////////////////

private slots:
    void on_pushButton_queren_clicked();

    //void on_pushButton_sorting_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::search *ui;
    QList<QString> mov_lines;
    QStandardItemModel * model;
};

#endif // SEARCH_H
