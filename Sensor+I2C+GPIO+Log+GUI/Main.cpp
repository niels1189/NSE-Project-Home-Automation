#include "Sensor.h"
#include "I2C.h"
#include "GPIO.h"
#include "Log.h"
#include "Camera.h"

#define I2CLOC "/dev/i2c-1"// <-- this is the real I2C device you need with the scale model
///#define I2CLOC "/dev/simudrv"
#define LOG "Slaaplog.txt"

#include <vector>
#include <iostream>

using namespace std;

int main() {	
	std::vector<Sensor&> sensoren;	

	Camera cam();		//The camera
	GPIO gpio();		//The GPIO
	I2CCom i2c(I2CLOC);     //the i2c to communicate with sensors
	Sensor s1(0x05,i2c,cam);  

	sensoren.pushback(s1);

	s1.GetValue();
	Log log(LOG);
	log.Write("holla \n");
	log.LogInBed();
	
	active=0;
	int i;
	while(1){
		for(i=0;i<sensoren.capacity();i++)
			if(sensoren[i]->check())
				active++;
		if(active==0);
			cout<<"uhoh"<<endl;
		active=0;
	}
}
