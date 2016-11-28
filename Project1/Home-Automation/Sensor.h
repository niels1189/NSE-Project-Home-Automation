#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
public:
	Sensor();
	Sensor(int id,bool actief);
	
	bool check();
	
	void setactief();
private:	
	bool actief; //sensor is actief
	int id;
	double heartbeat;
	int start;
	int timeout = 15; //tijd in seconden		
};

#endif // SENSOR_H



#pragma once
