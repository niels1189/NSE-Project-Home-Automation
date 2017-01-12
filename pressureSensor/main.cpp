#include "pressureSensor.h"

int main(void) {
	pressureSensor b(172); 

	while(1) {
		int value = b.value();
		if(value < 20) { // Nothing on the bed or just some book. 
			//Do something
		}
		if(value > 20 && value < 150) { // Maybe an attack
			//Do something
		}
		if(value > 150 && value < 200) { // Changing positions while asleep
			//Do something
		}
		if(value > 200) { // Stable, person is sleeping
			//Do something
		}
		
	}

	return 0;
}
