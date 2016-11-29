#ifndef DRUKSENSOR_H
#include "Sensor.h"
#define DRUKSENSOR_H
class DrukSensor :public Sensor{
public:
	DrukSensor(int id);	
	bool check();
	void state(); //debug

private:
	bool slaap = false;
	//void SetCamera(bool x);
	int start = 0;   //tijd
	
	bool actief = false;  //staat van sensor
	bool actief2 = false;  //vorige staat van sensor
	int sps = 0;  //spasms per second A.K.A state changes a second
	int warning = 5; //aantal toegestaande sps
	int slaaptijd = 5; //tijd voor slaapfunctie erkennen in sec
	//Sensor parent;
	void Aanval();
};


#endif
#pragma once
