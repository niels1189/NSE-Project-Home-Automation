#include "temperaturescreen.h"
#include "ui_temperatureScreen.h"
#include "temperatuur.h"


temperaturescreen::temperaturescreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::temperaturescreen)
{
    ui->setupUi(this);    

QTimer *Deadtimer = new QTimer(this);
	Deadtimer->setInterval(15*1000);
	Deadtimer->setSingleShot(true);
	connect(Deadtimer,SIGNAL(timeout()),SLOT(LogOut()));
	Deadtimer->start();
	deadtimer=Deadtimer;

    ui->dial->setValue(Ingesteldetemperatuur);

    QTimer *timer = new QTimer(this); // this form
    connect(
                timer,
                SIGNAL(timeout()),  // SLOT happends when there is a SIGNAL, timeout is emitted when the timer times out
                this,
                SLOT(tempSensor())    // shows time again, after a timeout, this makes it realtime
            ); //
	
	connect(ui->dial,SIGNAL(sliderMoved(int)),this,SLOT(resettimer()));
    timer->start();
    

}

void temperaturescreen::resettimer(){
deadtimer->stop();
deadtimer->start();
}

temperaturescreen::~temperaturescreen()
{
    Ingesteldetemperatuur = ui->dial->value();
    delete ui;
}

void temperaturescreen::LogOut(){
	this->~temperaturescreen();
	Dialog ScreenAfterLogin;
    	ScreenAfterLogin.setModal(true); // shows ScreenAfterLogin screen
    	ScreenAfterLogin.exec();
}

void temperaturescreen::tempSensor(){

    test += 1;
    if(test >= 1000){
        temp += 1;
            if(temp > 30){
                temp = 0;
            }
        LcdNumber_2_Display(temp);
        test = 0;
    }
}

void temperaturescreen::LcdNumber_2_Display(int i){

    ui->lcdNumber_2->display(i);

}

void temperaturescreen::on_pushButton_clicked(){
    //this->hide();
    this->~temperaturescreen();
    ScreenAfterLogin ScreenAfterLogin;
    ScreenAfterLogin.setModal(true); // shows ScreenAfterLogin screen
    ScreenAfterLogin.exec();
}
