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
#include <temperaturescreen.h>
#include <dialog.h>

namespace Ui {
class ScreenAfterLogin;
}

class ScreenAfterLogin : public QDialog
{
    Q_OBJECT

public:
    explicit ScreenAfterLogin(QWidget *parent = 0);
    ~ScreenAfterLogin();
protected:
	QTimer* deadtimer;


private slots:
    void showTime();
    void on_LogSeizure_clicked();
    void on_setTemp_clicked();
    void on_openDeur_clicked();

	void LogOut();
private:
    Ui::ScreenAfterLogin *ui;
    //QDateTime date;
    int count = 0;

};

#endif // SCREENAFTERLOGIN_H
