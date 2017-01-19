//g++ *.cpp -lpthread -lwiringPi -std=c++11
//LATER MET GUI MAKEFILE <sudo make>

#include "Sensor.h"
#include "I22cCom.h"
#include "Log.h"
#include "Camera.h"
#include "Light.h"
#include "MotionSensor.h"
#include "PressureSensor.h"
#define I2CLOC "/dev/i2c-1"// <-- this is the real I2C device you need with the scale model
///#define I2CLOC "/dev/simudrv"
#define LOG "Slaaplog.txt"

#include <vector>
#include <iostream>
#include <wiringPi.h>  //compile with -lwiringPi

using namespace std;

vector<Sensor*> motionSensors;    //Vector of the sensors
vector<Light*> lights;      //Vector of the lights
vector<int> active;
PressureSensor& pressureSensor;
Camera& cam;                //Pointer to the camera
Log& log;

int pressureValue;
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
void updateSensors();
void checkCam();
void sendAlert();
void init();

int main() {	

    init();
    
    while(1) {
        /*
        for(int i=0;i<sensors.capacity();i++) // For every sensor
            if(sensors[i]->Check()) { // Call their check function
				active[i]=1; // And if the check is positive (returns true). 
				//TODO ENABLE LIGHTS
			} else active[i]=0;
		if(sumActive(active)==0) {
            sendAlert();
		}
		for(i=0;i<lights.capacity();i++) // For every light
			lights[i]->Check(); // Check if timer expired yet
        */
        updateSensors();
        checkAnomaly();
        checkCam();
	}
}

/*Init for the main*/
void init() {
    wiringPiSetupGpio();
    I2CCom i2c(I2CLOC);     //the i2c to communicate with sensors
    
    Light x(22);
    MotionSensor s1(0x05,i2c);
    PressureSensor s2(0x06, i2c, log);
    Log l1(LOG);
    Camera c1();
    
    cam = &c1
    log = &l1;
    pressureSensor = &s2;
    motionSensors.push_back(&s1);
    lights.push_back(&x);

    active.resize(motionSensors.size);
}
/*Updates sensors*/
void updateSensors() {
    //update van elke sensor de value en de active
    bool alert = true;
    for(int i = 0; i<motionSensors.size();i++) {
        if(motionSensors[i]->check()) {
            active[i]=1;
            alert = false;
        } else {
            active[i]=0;
        }
    }
    if(alert) {
        sendAlert();
    }
}

/*Send Alarm*/
void sendAlert(){
    cout<<"Alert"<<endl;
}

/*Sets the camera*/
void checkCam(){
    if(day) {
        cam.setCamera(true);
    } else if(anomaly) {
        cam.setCamera(true);
    } else {
        cam.setCamera(false);
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
        sleep = true;
    }
    
}

