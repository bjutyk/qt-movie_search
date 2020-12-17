#include "search.h"
#include "ui_search.h"
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QStringList>


search::search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
    if(readFromFile() == -1){
        QMessageBox::critical(this,"严重错误","文件打开失败，请重试");
        this->close();
    }

    this->model = new QStandardItemModel;

    //设置表头
    this->model->setHorizontalHeaderItem(0,new QStandardItem("电影名"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("编号"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("评分"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("名著改编"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("地域"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("剧情"));
    this->model->setHorizontalHeaderItem(6,new QStandardItem("语言"));
    this->model->setHorizontalHeaderItem(7,new QStandardItem("导演"));
    this->model->setHorizontalHeaderItem(8,new QStandardItem("演员"));

    this->ui->tableView->setModel(model);

}

search::~search()
{
    delete ui;
}

int search::readFromFile()
{
    QFile file("movie.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        return -1;
    }
    QTextStream in(&file);

    while(!in.atEnd()){
        QString line = in.readLine();
        mov_lines.append(line);
    }
    file.close();


    int i= 0;
    for(i = 0;i < mov_lines.length();i++){
        qDebug()<<mov_lines.at(i);
    }

    return 0;
}
//查询条件获取
//int index;
void search::on_pushButton_queren_clicked()
{
    int index = this->ui->comboBox_method->currentIndex();
    QString cnt = this->ui->lineEdit_search->text();
    doQuert(index,cnt);
}
//遍历文本信息
void search::doQuert(int index,QString cnt)
{
    //qDebug()<<index;
    int i = 0;
    int count = 0;
    for(i = 0;i < mov_lines.length();i++){
        QString line = mov_lines.at(i);
        line = line.trimmed();  //去掉前后空格
        QStringList subs = line.split(" ");//根据空格分隔字符串
        switch(index){
        case 1:
            if(cnt == subs.at(0)){
                display(count++,subs);
            }
            break;
        case 2:
            if(cnt == subs.at(1)){
                display(count++,subs);
            }
            break;
        case 3:
            if(cnt == subs.at(2)){
                display(count++,subs);
            }
            break;
        case 4:
            if(cnt == subs.at(3)){
                display(count++,subs);
            }
            break;
        case 5:
            if(cnt == subs.at(4)){
                display(count++,subs);
            }
            break;
        case 6:
            if(cnt == subs.at(5)){
                display(count++,subs);
            }
            break;
        case 7:
            if(cnt == subs.at(6)){
                display(count++,subs);
            }
            break;
        case 8:
            if(cnt == subs.at(7)){
                display(count++,subs);
            }
            break;
        case 9:
            if(cnt == subs.at(8)){
                display(count++,subs);
                //qDebug()<<line;
            }
            break;
        default:
            break;
        }

    }

}

void search::display(int row, QStringList subs)
{
    int i = 0;
    for(int i = 0;i < subs.length();i++){
        this->model->setItem(row,i,new QStandardItem(subs.at(i)));//???三个参数
    }
}
