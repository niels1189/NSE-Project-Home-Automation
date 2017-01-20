#ifndef PRESSURESENSOR_H
#define PRESSURESENSOR_H

#include "Sensor.h"
#include "Log.h"


class PressureSensor : public Sensor{
public:
	PressureSensor(int id,I2CCom& x,Camera& cam,Log& log);
	bool Check();
private:
	int value;		
	Log& log;
};

#endif