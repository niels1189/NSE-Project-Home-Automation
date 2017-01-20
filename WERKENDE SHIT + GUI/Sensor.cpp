#include "Sensor.h"
#include "I2C.h"
#include <ctime>

using namespace std;

Sensor::Sensor(int id,I2CCom& x,Camera& cam):ID(id),Timer(time(0)+TimeOut),i2c(x),camera(cam){}

int Sensor::GetValue() {
	return i2c.I2C_GetValue(ID);
	
}

bool Sensor::Alive() {
	if (time(0) > Timer)
		return false;
	return true;
}

void Sensor::SetActive() {
	Timer = time(0) + TimeOut;
}