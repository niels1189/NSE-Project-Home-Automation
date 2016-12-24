#include "Sensor.h"
#include "I2C.h"

#define DEVC "/dev/i2c-1"// <-- this is the real I2C device you need with the scale model
///#define DEVC "/dev/simudrv"


int main() {
	I2CCom x(DEVC); //the i2c to communicate with sensors
	Sensor a(5,x);  
	a.GetValue();
}
