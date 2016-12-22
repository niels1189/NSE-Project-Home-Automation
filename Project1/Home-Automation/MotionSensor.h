#ifndef MOTIESENSOR_H
#define MOTIESENSOR_H
#include "Sensor.h"
#include "Lamp.h"
using namespace std;

class MotionSensor :public Sensor{
public:
	MotionSensor(int id,Lamp &gebondenlicht);
	void setlicht();		
	bool check();
private:	
	Lamp& gebondenlicht;
	int id;
};
#endif

#pragma once
