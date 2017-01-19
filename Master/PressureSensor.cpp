#include "PressureSensor.h"
#include "Sensor.h"
#include "Log.h"
#include <string>

PressureSensor::PressureSensor(int id,I2CCom& x):Sensor(id,x),value(0){}

bool PressureSensor::Check(){

	//log.Write(std::string("checked"));

	if(GetValue()>0){
		SetActive();
		return true;
	}
	else if(Alive()){
		return true;
	}
	else
		return false;
}
