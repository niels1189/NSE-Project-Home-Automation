#include "PressureSensor.h"
#include "Sensor.h"
#include "Log.h"
#include <string>

PressureSensor::PressureSensor(int sensorID,I2CCom& x):Sensor(sensorID,x),value(0){}

bool PressureSensor::check(){

	//log.Write(std::string("checked"));

	if(getValue()>0){
		setActive();
		return true;
	}
	else if(alive()){
		return true;
	}
	else
		return false;
}
