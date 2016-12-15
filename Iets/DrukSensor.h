#ifndef DRUKSENSOR_H
#include "Sensor.h"

#include <fstream>
#include <string>
#include <ctime>

#define DRUKSENSOR_H
class DrukSensor :public Sensor{
public:
	DrukSensor(int id);	
	bool check();
	void state(); //debug
	
private:
	bool slaap;  //slaap modus
	///void SetCamera(bool x);
	int start ;   //tijd	
	bool actief ;  //staat van sensor
	bool actief2 ;  //vorige staat van sensor
	int sps ;  //spasms per second A.K.A state changes a second
	int warning ; //aantal toegestaande sps
	int slaaptijd ; //tijd voor slaapfunctie erkennen in sec
	void Aanval();		
//LOG//
	std::string loc ; //Location of file
    std::ofstream test;      //datastream to file
	void write(char c);     //write to file
};


#endif
#pragma once
