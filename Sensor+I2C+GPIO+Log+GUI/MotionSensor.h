#ifndef MOTION_H
#def MOTION_H

#include "Sensor.h"
#include "Light.h"

class MotionSensor:public Sensor{
public:
MotionSensor(int id,I2CCom& i2c,Camera& cam,Light& light);
bool Check();
private:
Light& light;
}

#endif