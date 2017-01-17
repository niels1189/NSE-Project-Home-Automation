#include "Sensor.h"
#include "MotionSensor.h"

bool MotionSensor::Check(){	
	if(GetValue()>0) { // Motion sensor is active
		SetActive(); // Set dead-timer
		return true;
	}
	else if(Alive()) { // If motionsensor is still active but not expired
		return true;
	}
	else
		return false;
}
