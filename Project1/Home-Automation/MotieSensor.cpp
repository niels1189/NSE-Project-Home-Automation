#include "MotieSensor.h"
#include "Lamp.h"

MotieSensor::MotieSensor(int id,Lamp&gebondenlicht):gebondenlicht(gebondenlicht) {
	parent = Sensor(id, true);
}

bool MotieSensor::check() {
	if (!parent.check())
		return false;
	return true;
}

void MotieSensor::setlicht() {
	parent.setactief();
	gebondenlicht.Activeer();
}