#include "Sensor.h"
#include "I2C.h"
#include <ctime>

using namespace std;

Sensor::Sensor(int id,I2CCom& x): sensorID(id), timer(time(0)+timeOut), i2c(x), active(0), value(0){}

int Sensor::getValue() {
	return i2c.I2C_getValue(sensorID);
}

bool Sensor::alive() {
	if (time(0) > timer)
		return false;
	return true;
}

void Sensor::setActive() {
	timer = time(0) + timeOut;
}
