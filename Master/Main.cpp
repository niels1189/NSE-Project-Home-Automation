//g++ *.cpp -lpthread -lwiringPi -std=c++11
//LATER MET GUI MAKEFILE <sudo make>

#include "Sensor.h"
#include "I22cCom.h"
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

using namespace std;

vector<Sensor*> motionSensors;    //Vector of the sensors
vector<Light*> lights;      //Vector of the lights
vector<int> active;
PressureSensor* pressureSensor;
Camera* cam;                //Pointer to the camera
Log* log;

int pressureValue;
bool asleep = false;
bool day = true;
bool anomaly = false;
int temperature = 20;


void checkAnomaly();
void updateSensors();
void checkCam();
void sendAlert();
void init();

int main() {
  init();
  while(1) {
        updateSensors();
        checkAnomaly();
        checkCam();
  }
}

/*Init for the main*/
void init() {
    wiringPiSetupGpio();
    I2CCom i2c(I2CLOC);     //the i2c to communicate with sensor
    Light x(22);
    MotionSensor s1(0xFC,i2c);
    MotionSensor s2(0xBC,i2c);
    MotionSensor s3(0xEC,i2c);
    PressureSensor s4(0x06, i2c);
    Log l1(LOG);
    Camera c1;
    cam = &c1;
    log = &l1;
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
    for(int i = 0; i<motionSensors.size();i++) {
        if(motionSensors[i]->check()) {
            //active[i]=1;
            alert = false;
		cout <<"halleyula" <<endl;
        } else{
            //active[i]=0;
        }
    }
    if (s4->check()) {
        asleep = true;
    }
    if(alert & !asleep) {
        sendAlert();
    }
    pressureValue = s4->getValue();
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

void checkAnomaly(){
    
    if(pressureValue > 20 && pressureValue < 150) {
        anomaly = true;
    }
    if(pressureValue > 150 && pressureValue < 200) { // Changing positions while asleep
        //Do nothing, maybe verify if person really is sleeping
    }
    if(pressureValue > 200) {
        asleep = true;
    }
    
}

