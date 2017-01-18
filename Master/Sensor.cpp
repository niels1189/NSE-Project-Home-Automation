#include "Sensor.h"
#include "I2C.h"
#include <ctime>

using namespace std;

Sensor::Sensor(int id,I2CCom& x):ID(id),Timer(time(0)+TimeOut),i2c(x){}

int Sensor::getValue() {
	return i2c.I2C_GetValue(ID);
}

bool Sensor::alive() {
	if (time(0) > Timer)
		return false;
	return true;
}

void Sensor::setActive() {
	Timer = time(0) + TimeOut;
}
