#include "Lamp.h"
#include "GPIO.h"
#include<string.h>
#include<iostream>
#include <ctime>


Lamp::Lamp(int id) :actief(false),id(id),start(0){

}

void Lamp::Activeer() {
	actief = true;
    	GPIOWrite(this->id, 1);
	start = std::time(0);
}

void Lamp::Deactiveer() {
	start = 0;
	actief = false;
	GPIOWrite(this->id, 0);
}

void Lamp::check() {	

	if ((actief)&(std::time(0) - start >= 5)) //langer dan 15 minuten		
		Deactiveer();
		
}
