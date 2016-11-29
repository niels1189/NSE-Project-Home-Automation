#include "DrukSensor.h"
#include "Sensor.h"
#include <ctime>

DrukSensor::DrukSensor(int id):Sensor(id,true){
	
}

void DrukSensor::Aanval() {
	int x = 0;
	//alarm sturen en camera aanzetten
}

bool DrukSensor::check() {
	//slaap functies
	if (actief) {
		setactief();
	}

	if ((start==0)&actief & !slaap) {
		start = std::clock();
	}

	if ((actief & !slaap)&(std::clock() > start + slaaptijd * 1000)) {
		slaap = true;
		//CAMERA UIT
	}

	if (start & !actief & !slaap) {
		start = 0;
	}

	//sps functies
	if ((actief != actief2)&slaap) { //slaap mogelijk weg
		sps++;
		actief2 = actief;

		if (std::clock() > start + 1000) { //reset na 1 sec
			sps = 0;
			start = std::clock();
		}
	}
	
	if (sps > warning) {
		Aanval();
	}

	//check
	if (alive())
		return false;
	return true;
}
//debug
void DrukSensor::state() {
	if (actief == true) {
		actief = false;
		return;
	}
	if( actief == false)
		actief = true;
}