#ifndef MOTIESENSOR_H
#define MOTIESENSOR_H
#include "Sensor.h"
#include "Lamp.h"
using namespace std;

class MotieSensor :public Sensor{
private:
    Lamp& gebondenlicht;
public:
	MotieSensor(int id,Lamp &gebondenlicht);
	void setlicht();		
	bool check();

};
#endif

#pragma once
