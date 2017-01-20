#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QtSql>
#include <QFileInfo>
#include <QMessageBox>
#include <screenafterlogin.h>
#include <temperaturescreen.h>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT


public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QSqlDatabase myDB;
};

#endif // DIALOG_H
