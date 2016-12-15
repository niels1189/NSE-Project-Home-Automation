#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
public:
	Sensor();
	Sensor(int id,bool actief);	
	int alive();	
	void setactief();
private:	
    int id;		//Identifier (kan als pin in/out gebruikt worden)
	bool actief; //sensor is actief	
	int start;   //Timer
	int timeout; //tijd in seconden		
};

#endif // SENSOR_H



#pragma once
