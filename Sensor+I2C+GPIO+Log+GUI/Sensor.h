#ifndef SENSOR_H
#define SENSOR_H

/*SENSOR
* A parent class for the pressure- and motionsensor
* Goes over the deadtimers and I2C communication.
*/
#include "I2C.h"
#include "Camera.h"
class Sensor {
public:
	Sensor(int id,I2CCom& x,Camera& cam); //constructor with I2C id
	int GetValue();  //Gives the value from I2C
	bool Alive();   //Checks if the sensor is still alive  |  true if alive
	void SetActive(); //resets the timer
	//virtual bool check() =0;
	//virtual ~Sensor();
private:
	I2CCom& i2c;  //I2C Com file/setup
	int ID;   //I2C address
	int Timer;  //the epoch of when it dies
	const int TimeOut = 60;  //value in seconds of how long a sensor can stay non-active
protected:
	static bool slaap;
	Camera& camera;
};

#endif

#pragma once
