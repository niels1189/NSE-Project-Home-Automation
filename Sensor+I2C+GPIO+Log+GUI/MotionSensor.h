#ifndef MOTION_H
#define MOTION_H

#include "Sensor.h"
#include "Light.h"

class MotionSensor:public Sensor{
  public:
    MotionSensor(int id,I2CCom& i2c,Camera& cam,Light& light);
    bool Check();
  private:
    Light& light;
    int Active        = 0;
    int Timer         = 0;
    const int TimeOut = 300;  // How long will it take for the motionsensor to die
};

#endif
