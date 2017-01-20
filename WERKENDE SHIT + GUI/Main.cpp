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
Log* log;

int pressureValue;
bool asleep = false;
bool day = true;
bool anomaly = false;
int temperature = 20;
long sleepTimer = 0;

void init();


int routine() {	

    init();


	for(unsigned int i=0;i<lights.size();i++){
			lights[i]->setLight(false);
	}


	int active=0;
	int i;

	while(1){

		for(i=0;i<motionSensors.capacity();i++){

			if(motionSensors[i]->check())
				active++;	

		}	
		if(active==0)
			cout<<"uhoh"<<endl;
		
		active=0;		
		for(i=0;i<lights.capacity();i++)
			lights[i]->check();
				
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
    Log lo1 = log(LOG);

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
    log = &lo1;
    
    motionSensors.shrink_to_fit();
    
    lights.push_back(&l1);
    lights.push_back(&l2);
    lights.push_back(&l3);	
    
    
    lights.shrink_to_fit();
}

