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

//读取添加电影界面输入的信息并调用writeToFile(cnt)函数将其写入文件
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
    QString url = this->ui->lineEdit_url->text();


     QString content = name+'\n'+id+'\n'+rank+'\n'+ming+'\n'+region+'\n'+plot+'\n'+language+'\n'+director+'\n'+actor+'\n'+url;
     QString cnt = name+' '+id+' '+rank+' '+ming+' '+region+' '+plot+' '+language+' '+director+' '+actor+' '+url+'\n';
     if(name.length() < 1||id.length() < 1||director.length() < 1||actor.length() < 1||url.length() < 1){
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
//确认添加电影成功后清空添加电影页面文本框里原有信息
void addMovie::clearUserInterface()
{
    this->ui->lineEdit_name->setText("");
    //this->ui->lineEdit_name->clear();
    this->ui->lineEdit_id->clear();
    this->ui->lineEdit_director->clear();
    this->ui->lineEdit_actor->clear();
    this->ui->lineEdit_url->clear();
    this->ui->comboBox_rank->setCurrentIndex(0);
    this->ui->comboBox_ming->setCurrentIndex(0);
    this->ui->comboBox_region->setCurrentIndex(0);
    this->ui->comboBox_plot->setCurrentIndex(0);
    this->ui->comboBox_language->setCurrentIndex(0);
    this->ui->lineEdit_name->setFocus();

}
//将添加电影添加的电影信息写入txt文件
void addMovie::writeToFile(QString cnt)
{
    QFile file("movie.txt");
    if(!file.open(QIODevice::Append|QIODevice::Text))
    {
        QMessageBox::critical(this,"错误","文件打开失败，信息没有保存！","确定");
        return;
    }
    QTextStream out(&file);
    out<<cnt;
    file.close();
}
//取消按钮退出添加电影页面
void addMovie::on_pushButton_cancel_clicked()
{
    this->close();
}
