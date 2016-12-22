#include "MotionSensor.h"
#include "Lamp.h"
#include <time.h>

MotionSensor::MotieSensor(int id,Lamp&gebondenlicht):gebondenlicht(gebondenlicht), Sensor(id, true){
	if(0<id<4)
		this->id = id;
	else this->id = 0;
}

bool MotieSensor::check() {
	if(this->detectMotion()) {
		gebondenlicht.Activeer(this->id);
		setactief(int id);
		time(&this->expire);
		// difftime(timenew,this->expire); // timenew-this->expire
		return true;
	} else {
		Guard.Notify();
		return false;
	}
}
