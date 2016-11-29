#include <string.h>

#include <iostream>
#include <cstdio>
#include <ctime>

#include "Sensor.h"
#include "DrukSensor.h"
#include "Lamp.h"
#include "MotieSensor.h"
using namespace std;


int main() {
	//Sensor y(0x00, true);
	
	
	Lamp y;
	MotieSensor a(0x01, y);
	DrukSensor b(0x02);
	a.setlicht();
	bool status[8] = {0};
	while (1) {				
		status[0]=a.check();
		status[1]=b.check();
	}	
	
}
