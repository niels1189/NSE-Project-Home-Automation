//g++ *.cpp -lpthread -lwiringPi -std=c++11
//LATER MET GUI MAKEFILE <sudo make>

#include "Sensor.h"
#include "I2C.h"
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


#define I2CLOC "/dev/i2c-1"// <-- this is the real I2C device you need with the scale model
///#define I2CLOC "/dev/simudrv"
#define LOG "Slaaplog.txt"

#include <vector>
#include <iostream>
#include <wiringPi.h>  //compile with -lwiringPi

using namespace std;

vector<Sensor*> sensors;    //Vector of the sensors
vector<Light*> lights;      //Vector of the lights
vector<int> values;         //Vector of the values from the sensors
vector<int> active;
Camera& cam;                //Pointer to the camera

bool sleep = false;
bool day = true;
bool anomaly = false;
int temperature = 20;


int sumActive(int active[]) {
	int sum=0;
	for(int i=0;i<sizeof(active[])/sizeof(active[0]);i++)
		sum+=active[i];
	return sum;
}

void checkAnomaly();

void checkCam();

void init();

int main(int argc, char* argv[]) {	
	/*
	QApplication a(argc, argv);
	Dialog w;
   	w.show();
	*/
    
    while(1) {
	 
	//a.processEvents();
        for(int i=0;i<sensors.capacity();i++) // For every sensor
            if(sensors[i]->Check()) { // Call their check function
				active[i]=1; // And if the check is positive (returns true). 
				//TODO ENABLE LIGHTS
			} else active[i]=0;
		if(sumActive(active)==0) {
			cout<<"uhoh"<<endl;
			// Guard.sendAlert();
		}
		for(i=0;i<lights.capacity();i++) // For every light
			lights[i]->Check(); // Check if timer expired yet
	}
	
}

/*Init for the main*/
void init() {
    wiringPiSetupGpio();
    Light x(22);
    I2CCom i2c(I2CLOC);     //the i2c to communicate with sensors
    MotionSensor s1(0x05,i2c);
    Log log(LOG);
    PressureSensor s2(0x06, i2c, log);
    
    sensors.push_back(&s1);
    sensors.push_back(&s2);
    
    lights.push_back(&x);

    active.resize(sensors.sizeof);
    values.resize(sensors.sizeof);
}

/*Sets the camera*/
void checkCam(){
    if(day) {
        cam.setCamera(true);
    } else if(anamoly) {
        cam.setCamera(true);
    } else {
        cam.setCamera(false);
    }
}

void checkAnomaly(){
    
    int pressureValue = values[2];
    
    if(pressureValue > 20 && value < 150) {
        anomaly = true;
    }
    if(pressureValue > 150 && pressureValue < 200) { // Changing positions while asleep
        //Do nothing, maybe verify if person really is sleeping
    }
    if(pressureValue > 200) {
        sleep = true;
    }
    
}

