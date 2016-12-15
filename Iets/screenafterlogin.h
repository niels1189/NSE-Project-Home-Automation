#ifndef SCREENAFTERLOGIN_H
#define SCREENAFTERLOGIN_H

#include <QDialog>
#include <iostream>
#include <QTimer>
#include <QDateTime>
#include <QFileDialog>
#include <QDesktopServices>
#include <QUrl>
#include <fstream>
#include <string>
#include <ctime>

namespace Ui {
class ScreenAfterLogin;
}

class ScreenAfterLogin : public QDialog
{
    Q_OBJECT

public:
    explicit ScreenAfterLogin(QWidget *parent = 0);
    ~ScreenAfterLogin();
private slots:
    void showTime();
    void on_LogSeizure_clicked();

private:
    Ui::ScreenAfterLogin *ui;
    //QDateTime date;
    int count = 0;

};

#endif // SCREENAFTERLOGIN_H
