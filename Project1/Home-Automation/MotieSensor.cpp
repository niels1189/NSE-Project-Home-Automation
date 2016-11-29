#include "MotieSensor.h"
#include "Lamp.h"

MotieSensor::MotieSensor(int id,Lamp&gebondenlicht):gebondenlicht(gebondenlicht), Sensor(id, true) {
	
}

bool MotieSensor::check() {	
	if (alive()) {
		return false;
	}
	return true;
}

void MotieSensor::setlicht() {
	setactief();
	gebondenlicht.Activeer();
}