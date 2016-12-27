#include "Lamp.h"
#include <ctime>


Lamp::Lamp() {
	actief = 0;
	timeout = 900; // After how many seconds will the light deactivate itself?

}

Lamp::Lamp(int timeout) {
	actief = 0;
	this.timeout = timeout; // After how many seconds will the light deactivate itself?

}

void Lamp::Activate() {
	active = true;
	expire = std::clock()+this.timeout;
}

void Lamp::Deactivate() {
	expire = 0;
	actief = 0;
}

void Lamp::Check() {
	if (std::clock() > expire) {
			Deactiveer();
	}
}
