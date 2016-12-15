#include "Sensor.h"
#include "I2C.h"

#include <ctime>

Sensor::Sensor(int id, bool actief):id(id),actief(actief) {
	start = std::time(0);
	timeout = 15;
}

Sensor::Sensor():id(0),actief(0) {
	start = std::time(0);
	timeout = 15;
}

int Sensor::alive() {
    if(i2c_GetValue(id)==1){
        setactief();
        return 3;
    }
	if ((std::time(0) - start) >= timeout) {
		actief = false;
        return 0;
	}
    return 1;
}

void Sensor::setactief() {
	start = std::time(0);
}
