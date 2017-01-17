#include "pressureSensor.h"


void checkSensors();


int main(void) {
	pressureSensor b(172); 

	while(1) {
		int value = b.value();
		if(value < 20) { // Nothing on the bed or just some book. 
			//Do nothing just log
		}
		if(value > 20 && value < 150) { // Maybe an attack
			//Switch camera on
		}
		if(value > 150 && value < 200) { // Changing positions while asleep
			//Do nothing, maybe verify if person really is sleeping
		}
		if(value > 200) { // Stable, person is sleeping
			//DO nothing just log 
		}
		
	}

	return 0;
}

checkSensors