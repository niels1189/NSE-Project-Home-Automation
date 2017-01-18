#include "Sensor.h"
#include "MotionSensor.h"

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
