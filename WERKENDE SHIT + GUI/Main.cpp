#include "Sensor.h"
#include "I2C.h"
#include "Log.h"
#include "Camera.h"
#include "Light.h"
#include "MotionSensor.h"
#include "PressureSensor.h"
//#define I2CLOC "/dev/i2c-1"// <-- this is the real I2C device you need with the scale model
#define I2CLOC "/dev/simudrv"
#define LOG "Slaaplog.txt"

#include <vector>
#include <iostream>
#include <wiringPi.h>  //compile with -lwiringPi
#include <thread>

//GUI
#include "dialog.h"
#include <QApplication>
#include "temperatuur.h"
//
using namespace std;


vector<Sensor*> motionSensors;    //Vector of the sensors
vector<Light*> lights;      //Vector of the lights
PressureSensor* pressureSensor;
Camera* cam;                //Pointer to the camera
//Log* log;

int pressureValue;
bool asleep = false;
bool day = true;
bool anomaly = false;
int temperature = 20;
long sleepTimer = 0;

void checkSleep();
void updateSensors();
void checkCam();
void sendAlert();
void init();

int routine() {	

    init();


	for(unsigned int i=0;i<lights.size();i++){
			lights[i]->setLight(false);
	}

	while(1){
        updateSensors();
    }

}


int temp=20;

int main(int argc, char *argv[]){
    Ingesteldetemperatuur =25;
    thread Routine(routine);
    QApplication a(argc, argv);
    Dialog w;
    w.show();

    return a.exec();
}

void init() {
    wiringPiSetupGpio();
    
    Light l1(18);
    Light l2(25);
    Light l3(23);
    Camera c1;		//The camera
    //Log lo1 = Log(LOG);

    I2CCom i2c(I2CLOC,0x08);     //the i2c to communicate with sensors
    MotionSensor m1(0xFC,i2c);
    MotionSensor m2(0xBC,i2c);
    MotionSensor m3(0xEC,i2c);
    PressureSensor s2(0xAC, i2c);
    
    motionSensors.push_back(&m1);
    motionSensors.push_back(&m2);
    motionSensors.push_back(&m3);
   
    pressureSensor = &s2;
    cam = &c1;
    //log = &lo1;
    
    motionSensors.shrink_to_fit();
    
    lights.push_back(&l1);
    lights.push_back(&l2);
    lights.push_back(&l3);	
    
    
    lights.shrink_to_fit();
}
/*Updates sensors*/
void updateSensors() {
    
    int active=0;
    unsigned int i;
    bool alert = false;
    
    for(i=0;i<motionSensors.size();i++){
        
        if(motionSensors[i]->check())
            active++;
        
    }
    if(active==0) {
        alert = true;
    }
    
    for(i=0;i<lights.size();i++){
        lights[i]->check();
				
    }
    
    //update van elke sensor de value en de active
    bool alert = true;

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



