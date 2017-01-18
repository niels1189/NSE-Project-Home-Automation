#ifndef MOTION_H
#define MOTION_H

#include "Sensor.h"
#include "Light.h"

class MotionSensor:public Sensor{
  public:
    bool check();
  private:
};

#endif
