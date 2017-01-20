#ifndef PRESSURESENSOR_H
#define PRESSURESENSOR_H

#include "Sensor.h"
#include "Log.h"


class PressureSensor : public Sensor{
public:
	PressureSensor(int sensorID,I2CCom& x);
	bool check();
private:
	int value;
};

#endif
