#include "addmovie.h"
#include "ui_addmovie.h"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

addMovie::addMovie(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addMovie)
{
    ui->setupUi(this);
    //connect(this->ui->pushButton_cancel,SIGNAL(clicked(bool)),this,SLOT(close()));

}

addMovie::~addMovie()
{
    delete ui;
}


void addMovie::on_pushButton_ok_clicked()
{
    QString name = this->ui->lineEdit_name->text();
    QString id = this->ui->lineEdit_id->text();
    QString rank = this->ui->comboBox_rank->currentText();
    QString ming = this->ui->comboBox_ming->currentText();
    QString region = this->ui->comboBox_region->currentText();
    QString plot = this->ui->comboBox_plot->currentText();
    QString language = this->ui->comboBox_language->currentText();
    QString director = this->ui->lineEdit_director->text();
    QString actor = this->ui->lineEdit_actor->text();

    //QMessageBox msgBox;

    //msgBox.setText(name +'\n'+id);
    //msgBox.exec();

//   msgBox.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
//   msgBox.addButton("确定",QMessageBox::AcceptRole);
//   QPushButton * cbtn = msgBox.addButton("取消",QMessageBox::AcceptRole);
//   msgBox.setDefaultButton(cbtn);
//   int ret = msgBox.exec();

//   QMessageBox::aboutQt(this,"鸣谢");
//   QMessageBox::information(this,"请确认信息",name+'\n'+id,QMessageBox::Ok|QMessageBox::Cancel);
//   QMessageBox::information(this,"请确认信息",name+"\n"+id,"确认","取消");
     //critical //information //question //waring

     QString content = name+'\n'+id+'\n'+rank+'\n'+ming+'\n'+region+'\n'+plot+'\n'+language+'\n'+director+'\n'+actor;
     QString cnt = name+' '+id+' '+rank+' '+ming+' '+region+' '+plot+' '+language+' '+director+' '+actor+'\n';
     if(name.length() < 1||id.length() < 1){
         QMessageBox::critical(this,"错误","信息填写不完整，请重新检查","确定");
     }else{
         int ret = QMessageBox::information(this,"请确认信息",content,"确认","取消");
         //qDebug()<<ret;
         if(ret == 0){
             clearUserInterface();//点击确认清空填写的数据
             writeToFile(cnt);
         }
     }
}

//void addMovie::on_lineEdit_name_cursorPositionChanged(int arg1, int arg2)
//{
//    qDebug()<<"cursorPositionChanged";
//}

//void addMovie::on_lineEdit_name_editingFinished()
//{
//    qDebug()<<"editingFinished";
//}

//void addMovie::on_lineEdit_name_returnPressed()
//{
//    qDebug()<<"returnPressed";
//}

//void addMovie::on_lineEdit_name_selectionChanged()
//{
//    qDebug()<<"selectionChanged";
//}

//void addMovie::on_lineEdit_name_textChanged(const QString &arg1)
//{
//    qDebug()<<"textChanged";
//}

//void addMovie::on_lineEdit_name_textEdited(const QString &arg1)
//{
//    qDebug()<<"textEdited";
//}

void addMovie::clearUserInterface()
{
    this->ui->lineEdit_name->setText("");
    //this->ui->lineEdit_name->clear();
    this->ui->lineEdit_id->clear();
    this->ui->lineEdit_director->clear();
    this->ui->lineEdit_actor->clear();
    this->ui->comboBox_rank->setCurrentIndex(0);
    this->ui->comboBox_ming->setCurrentIndex(0);
    this->ui->comboBox_region->setCurrentIndex(0);
    this->ui->comboBox_plot->setCurrentIndex(0);
    this->ui->comboBox_language->setCurrentIndex(0);
    this->ui->lineEdit_name->setFocus();
}

void addMovie::writeToFile(QString cnt)
{
    QFile file("movie.txt");
    if(!file.open(QIODevice::Append|QIODevice::Text))
    {   QMessageBox::critical(this,"错误","文件打开失败，信息没有保存！","确定");
        return;
    }
    QTextStream out(&file);
    out<<cnt;
    file.close();
}

void addMovie::on_pushButton_cancel_clicked()
{
    this->close();
}
