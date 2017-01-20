#include "temperaturescreen.h"
#include "ui_temperaturescreen.h"
#include "temperatuur.h"


temperaturescreen::temperaturescreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::temperaturescreen)
{
    ui->setupUi(this);

    et.start();
    QTimer *Deadtimer = new QTimer(this);
    connect(Deadtimer,SIGNAL(timeout()),SLOT(LogOut()));
    Deadtimer->start(1000);


     ui->dial->setValue(Ingesteldetemperatuur);

     QTimer *timer = new QTimer(this); // this form
         connect(
                     timer,
                     SIGNAL(timeout()),  // SLOT happends when there is a SIGNAL, timeout is emitted when the timer times out
                     this,
                     SLOT(tempSensor())    // shows time again, after a timeout, this makes it realtime
                 ); //

         connect(ui->dial,SIGNAL(sliderMoved(int)),this,SLOT(resettimer()));

}

temperaturescreen::~temperaturescreen()
{

    delete ui;
}

void temperaturescreen::on_backButton_clicked()
{
    //this->hide();
    this->~temperaturescreen();
    ScreenAfterLogin ScreenAfterLogin;
    ScreenAfterLogin.setModal(true); // shows ScreenAfterLogin screen
    ScreenAfterLogin.exec();
}

void temperaturescreen::tempSensor() {
    reset += 1;
      if(reset >= 1000){
          LcdNumber_2_Display(temp);
          reset = 0;
      }
}

void temperaturescreen::LcdNumber_2_Display(int i){

    ui->lcdNumber_2->display(i);

}

void temperaturescreen::LogOut() {

    if (et.elapsed() > 15000) { // interval ms
    this->~temperaturescreen();
    Dialog ls; // login screen
    ls.setModal(true); // shows login screen
    ls.exec();

    et.restart();
    }
}

void temperaturescreen::resettimer() {
    //deadtimer->stop();
    //deadtimer->start();
}
