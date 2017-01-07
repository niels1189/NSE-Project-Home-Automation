#include "Sensor.h"
#include "MotionSensor.h"


MotionSensor::MotionSensor(int id,I2CCom& i2c,Camera& cam,Light& light):Sensor(id,i2c,cam),light(light){}


bool MotionSensor::Check(){
	if(i2c.I2C_GetValue()>0){
		this->Active=1; // Motion sensor is active
		Timer = time(0) + TimeOut;
		light.Set_Light(true); // Turn on the bound lights
		return true;
	}
	
	if((time(0) > Timer)&&(Active)){ // if the current time is less than the Timer (for expiry)
		this->Active=false; //(meaning the dead-timer for the motionsensor has expired)
		return 0; // Return 0 because the timer expired.
	}
	else if(Active) {
		return 1; // If motionsensor is still active but not expired, return a 1
	}
	else
		return 0; // If the motionsensor is inactive, return 0
	return true;
}
