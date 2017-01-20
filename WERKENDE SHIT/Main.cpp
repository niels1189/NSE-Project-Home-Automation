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




using namespace std;
int main() {	
	wiringPiSetupGpio();

	vector<Sensor*> sensors;	
	vector<Light*> lights;

	Light l1(18);
	Light l2(25);
	Light l3(23);
	Camera cam;		//The camera	
	I2CCom i2c(I2CLOC,0x08);     //the i2c to communicate with sensors
	MotionSensor m1(0xFC,i2c,cam,l1);  
	MotionSensor m2(0xBC,i2c,cam,l2);  
	MotionSensor m3(0xEC,i2c,cam,l3);  
	Log log(LOG);
	PressureSensor s2(0xAC, i2c, cam, log);

	sensors.push_back(&m1);
	sensors.push_back(&m2);
	sensors.push_back(&m3);
	sensors.push_back(&s2);

	sensors.shrink_to_fit();

	lights.push_back(&l1);	
	lights.push_back(&l2);	
	lights.push_back(&l3);	


	lights.shrink_to_fit();



	for(int i=0;i<lights.capacity();i++){
			lights[i]->Set_Light(false);
	}


	int active=0;
	int i;

	while(1){

		for(i=0;i<sensors.capacity();i++){

			if(sensors[i]->Check())
				active++;	

		}	
		if(active==0)
			cout<<"uhoh"<<endl;
		
		active=0;		
		for(i=0;i<lights.capacity();i++)
			lights[i]->Check();
				
	}
}
