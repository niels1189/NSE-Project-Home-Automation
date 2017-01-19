#include "screenafterlogin.h"
#include "ui_screenafterlogin.h"

#define path_toLog "logbat.txt" //CHANGE PATH WHEN PUT ON THE RASPBERYY

using namespace std;

ScreenAfterLogin::ScreenAfterLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScreenAfterLogin)
{
    ui->setupUi(this);



    QTimer *timer = new QTimer(this); // this form
    connect(
                timer,
                SIGNAL(timeout()),  // SLOT happends when there is a SIGNAL, timeout is emitted when the timer times out
                this,
                SLOT(showTime())    // shows time again, after a timeout, this makes it realtime
            ); //

    timer->start();
}

ScreenAfterLogin::~ScreenAfterLogin()
{
    delete ui;

}

void ScreenAfterLogin::showTime() // Shows the Date and Time
{
    QDateTime date = QDateTime::currentDateTime(); // get current Date and Time
    QString datetimetext = date.toString(); // return the date and time as a string
    ui->date->setText(datetimetext);  // change label to the string (date and time)

}

void ScreenAfterLogin::on_LogSeizure_clicked()
{

        time_t timer;
        time(&timer);

        ofstream File;
        File.open(path_toLog, ios::out | ios::app); // app = appending, so that all data will be saved
                                                    // out = Open for output operations, write to file

       /* time_t timer = time(0);   // get time now
            struct tm* now = localtime( & timer );
            File << (now->tm_year + 1900) << '-' // output is 116 instead of 2016
                 << (now->tm_mon +1) << '-'      // output is month -1, so +1 we need to do
                 <<  now->tm_mday << " "
                 <<  now->tm_hour << ":"
                 <<  now->tm_min << ":"
                 <<  now->tm_sec
                 << " Tim had a epleptic seizure "
                 << endl; */
        File << count++ <<".  Tim had a epleptic seizure @   :   ";
        File << ctime(&timer);


        File.close();


}

void ScreenAfterLogin::on_setTemp_clicked(){
    //this->hide();
    this->~ScreenAfterLogin();
    temperaturescreen temperaturescreen;
    temperaturescreen.setModal(true); // shows Temperaturescreen
    temperaturescreen.exec();
}

void ScreenAfterLogin::on_openDeur_clicked(){

    //insert code to open door
}
