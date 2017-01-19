#ifndef TEMPERATURESCREEN_H
#define TEMPERATURESCREEN_H

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
#include <screenafterlogin.h>


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
    void tempSensor();
    void LcdNumber_2_Display(int i);
    void on_pushButton_clicked();
    void resettimer();

private:
    Ui::temperaturescreen *ui;
    int count = 0;
    int temp = 0;
    int resettemp = 0;
};

#endif // TEMPERATURESCREEN_H
