#include "Sensor.h"
#include "I22cCom.h"
#include <ctime>

using namespace std;

Sensor::Sensor(int id,I2CCom& x):id(id),timer(time(0)+timeOut),i2c(x){}

int Sensor::getValue() {
	return i2c.I2C_GetValue(id);
}

bool Sensor::alive() {
	if (time(0) > timer)
		return false;
	return true;
}

void Sensor::setActive() {
	timer = time(0) + timeOut;
}
