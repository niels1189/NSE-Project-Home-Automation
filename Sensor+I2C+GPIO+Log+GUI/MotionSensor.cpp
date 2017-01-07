#include "Sensor.h"
#include "MotionSensor.h"


MotionSensor::MotionSensor(int id,I2CCom& i2c,Camera& cam,Light& light):Sensor(id,i2c,cam),light(light){}

bool MotionSensor::Check(){
	if(GetValue()>0){
		SetActive();
		light.Set_Light(true);
		return true;
	}
	
	return Alive();
}