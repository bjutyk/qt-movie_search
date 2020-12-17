#ifndef ADDMOVIE_H
#define ADDMOVIE_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class addMovie; }
QT_END_NAMESPACE

class addMovie : public QDialog
{
    Q_OBJECT

public:
    addMovie(QWidget *parent = nullptr);
    ~addMovie();
    void clearUserInterface();
    void writeToFile(QString cnt);

private slots:
    void on_pushButton_ok_clicked();

//    void on_lineEdit_name_cursorPositionChanged(int arg1, int arg2);
//    void on_lineEdit_name_editingFinished();
//    void on_lineEdit_name_returnPressed();
//    void on_lineEdit_name_selectionChanged();
//    void on_lineEdit_name_textChanged(const QString &arg1);
//    void on_lineEdit_name_textEdited(const QString &arg1);

    void on_pushButton_cancel_clicked();

private:
    Ui::addMovie *ui;
};
#endif // ADDMOVIE_H
