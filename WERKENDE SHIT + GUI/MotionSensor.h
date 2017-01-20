#ifndef MOTION_H
#define MOTION_H

#include "Sensor.h"
#include "Light.h"

class MotionSensor:public Sensor{
  public:
    MotionSensor(int id,I2CCom& i2c);
    bool check();
  private:
};

#endif
