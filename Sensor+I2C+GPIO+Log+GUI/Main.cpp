#include "Sensor.h"
#include "I2C.h"
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

int main() {	
	wiringPiSetupGpio();

	vector<Sensor*> sensors;	
	vector<Light*> lights;

	Light x(22);
	Camera cam;		//The camera	
	I2CCom i2c(I2CLOC);     //the i2c to communicate with sensors
	MotionSensor s1(0x05,i2c,cam,x);  
	Log log(LOG);
	PressureSensor s2(0x06, i2c, cam, log);

	sensors.push_back(&s1);
	sensors.push_back(&s2);

	lights.push_back(&x);	

	int active=0;
	int i;

	while(1){

		for(i=0;i<sensors.capacity();i++)
			if(sensors[i]->Check())
				active++;
		if(active==0)
			cout<<"uhoh"<<endl;
		active=0;

		for(i=0;i<lights.capacity();i++)
			lights[i]->Check();
	}
}
