#ifndef TEMPERATURESCREEN_H
#define TEMPERATURESCREEN_H

#include <QDialog>
#include <iostream>
#include <QTimer>
#include <QDateTime>
#include <QFileDialog>
#include <QElapsedTimer>
#include <QDesktopServices>
#include <QUrl>
#include <fstream>
#include <string>
#include <ctime>
#include <screenafterlogin.h>
#include <dialog.h>

namespace Ui {
class temperaturescreen;
}

class temperaturescreen : public QDialog
{
    Q_OBJECT

public:
    explicit temperaturescreen(QWidget *parent = 0);
    ~temperaturescreen();
private slots:
    void on_backButton_clicked();

    void tempSensor();

    void LcdNumber_2_Display(int i);

    void LogOut();

    void resettimer();
private:
    Ui::temperaturescreen *ui;
    int count = 0;
    int temp = 0;
    int reset = 0;
    QElapsedTimer et;
};

#endif // TEMPERATURESCREEN_H
