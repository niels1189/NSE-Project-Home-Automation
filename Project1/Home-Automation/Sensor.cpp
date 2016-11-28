#include "Sensor.h"
#include <ctime>

Sensor::Sensor(int id, bool actief):id(id),actief(actief) {
	start = std::clock();
}

Sensor::Sensor() {
	id = 0;
	actief = 0;
	heartbeat = 0;
}

bool Sensor::check() {
	heartbeat = std::clock() - start;
	heartbeat /= 1000;
	if (heartbeat > timeout) {
		actief = false;
		return false;
	}
	return true;
}

void Sensor::setactief() {
	start = std::clock();
}