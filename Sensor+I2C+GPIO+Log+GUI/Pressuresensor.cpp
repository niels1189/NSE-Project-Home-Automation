#include "PressureSensor.h"
#include "Sensor.h"
#include "Log.h"
#include <string>

PressureSensor::PressureSensor(int id,I2CCom& x,Camera& cam,Log& log):Sensor(id,x,cam),value(0),log(log){}

bool PressureSensor::Check(){

	log.Write(std::string("checked"));

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