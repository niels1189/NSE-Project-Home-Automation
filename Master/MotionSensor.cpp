#include "Sensor.h"
#include "MotionSensor.h"

MotionSensor::MotionSensor(int id,I2CCom& i2c):Sensor(id,i2c){}

bool MotionSensor::check(){
	if(getValue()>60) { // Motion sensor is active
		setActive(); // Set dead-timer
		return true;
	}
	else if(alive()) { // If motionsensor is still active but not expired
		return true;
	}
	else
		return false;
}
