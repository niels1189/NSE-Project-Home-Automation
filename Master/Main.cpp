//g++ *.cpp -lpthread -lwiringPi -std=c++11
//LATER MET GUI MAKEFILE <sudo make>

#include "I22cCom.h"
// Sensors -------------------
#include "Sensor.h"
#include "Log.h"
#include "Camera.h"
#include "Light.h"
#include "MotionSensor.h"
#include "PressureSensor.h"
// GUI includes
#include <QApplication>
#include "dialog.h"
#include "screenafterlogin.h"
#include "temperaturescreen.h"
#include "temperatuur.h"
// ----------
//#define I2CLOC "/dev/i2c-1"// <-- this is the real I2C device you need with the scale model
#define I2CLOC "/dev/simudrv"
#define LOG "Slaaplog.txt"

#include <vector>
#include <iostream>
#include <wiringPi.h>  //compile with -lwiringPi

using namespace std;

vector<Sensor*> motionSensors;    //Vector of the sensors
vector<Light*> lights;      //Vector of the lights
vector<int> active;
PressureSensor* pressureSensor;
Camera* cam;                //Pointer to the camera
//Log* log;

int pressureValue;
bool asleep = false;
bool day = true;
bool anomaly = false;
int temperature = 20;
int IngesteldeTemperatuur = 20;
long sleepTimer = 0;


void checkSleep();
void updateSensors();
void checkCam();
void sendAlert();
void init();


int main(int argc, char* argv[]) {	
	
	QApplication a(argc, argv);
	Dialog w;
   	w.show();
	
  init();
  while(1) {
	a.processEvents();
        updateSensors();
        checkSleep();
        checkCam();
        checkTemperature();
  }
}

/*Init for the main*/
void init() {
	//GUI
    //thread GUIloop(GUImain);
	//GUIloop.join();
    //I2C
	wiringPiSetupGpio();
	I2CCom i2c(I2CLOC);     //the i2c to communicate with sensor
	
    //Create sensorobjects
    Light x(22);
	MotionSensor s1(0xFC,i2c);
	MotionSensor s2(0xBC,i2c);
	MotionSensor s3(0xEC,i2c);
	PressureSensor s4(0x06, i2c);
	//Log l1(LOG);
	Camera c1;
    
    //Create pointers to the sensors
	cam = &c1;
	//log = &l1;
	pressureSensor = &s4;
	motionSensors.push_back(&s1);
	motionSensors.push_back(&s2);
	motionSensors.push_back(&s3);
	lights.push_back(&x);

    active.resize(motionSensors.size());
}
/*Updates sensors*/
void updateSensors() {
    //update van elke sensor de value en de active
    bool alert = true;
    for(unsigned int i = 0; i<motionSensors.size(); ++i) {
        if(motionSensors[i]->check()) {
            //active[i]=1;
            alert = false;
        } else{
            //active[i]=0;
        }
    }
    if (pressureSensor->check()) {
        asleep = true;
    }
    if(alert & !asleep) {
        sendAlert();
    }
    pressureValue = pressureSensor->getValue();
}

/*Send Alarm*/
void sendAlert(){
    cout<<"Alert"<<endl;
}

/*Sets the camera*/
void checkCam(){
    if(day) {
        cam->setCamera(true);
    } else if(anomaly) {
        cam->setCamera(true);
    } else {
        cam->setCamera(false);
    }
}

/*Checks if there is an anomaly, otherwise checks if Tim's asleep*/
void checkSleep(){
    if(pressureValue < 20) {
        asleep = false;
        sleepTimer = 0;
    } else if(pressureValue > 20 && pressureValue < 150) {
        anomaly = true;
        sleepTimer = 0;
    } else if(pressureValue > 150 && pressureValue < 200) {
        sleepTimer = 0;
        // Changing positions while asleep
        //Do nothing, maybe verify if person really is sleeping
    } else if(pressureValue > 200 && sleepTimer == 0) {
        sleepTimer = time(0) + 900;
    } else if(pressureValue >200 && sleepTimer != 0) {
        if( time(0) >= sleepTimer) {
            asleep = true;
        }
    }
    
}

/*Checks the set temperature from the gui*/
void checkTemperature() {
    temperature = IngesteldeTemperatuur;
}

