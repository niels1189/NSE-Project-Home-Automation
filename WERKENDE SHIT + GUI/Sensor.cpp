#include "Sensor.h"
#include "I2C.h"
#include <ctime>

using namespace std;

Sensor::Sensor(int sensorID,I2CCom& x):sensorID(sensorID),timer(time(0)+timeOut),i2c(x){}

int Sensor::getValue() {
	return i2c.I2C_GetValue(sensorID);
}

bool Sensor::alive() {
	if (time(0) > timer)
		return false;
	return true;
}

void Sensor::setActive() {
	timer = time(0) + timeOut;
}
