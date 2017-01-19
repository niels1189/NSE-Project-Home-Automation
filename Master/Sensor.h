#ifndef SENSOR_H
#define SENSOR_H

/*SENSOR
* A parent class for the pressure- and motionsensor
* Goes over the deadtimers and I2C communication.
*/
#include "I22cCom.h"
#include "Camera.h"
class Sensor {
public:
	Sensor(int sensorID,I2CCom& x); //constructor with I2C id
	int getValue();  //Gives the value from I2C
	bool alive();   //Checks if the sensor is still alive  |  true if alive
	void setActive(); //resets the timer
	virtual bool check() =0;
	//virtual ~Sensor();
private:
	I2CCom& i2c;  //I2C Com file/setup
	int sensorID;   //I2C address
	int timer;  //the epoch of when it dies
    int active;
    int value;
	const int timeOut = 900;  //value in seconds of how long a sensor can stay non-active
};

#endif

#pragma once
