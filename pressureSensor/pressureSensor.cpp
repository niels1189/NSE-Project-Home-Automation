#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<iostream>
#include<unistd.h>
#include<sys/ioctl.h>
#include<linux/i2c.h>
#include<linux/i2c-dev.h>
#include "pressureSensor.h"

//#define DEVC "/dev/i2c-1" //Used for scale model
#define DEVC "/dev/simudrv" //Used for simulation

using namespace std;

pressureSensor::pressureSensor(int address): // constructor
input(address), value(0) {
	
}

int pressureSensor::value() {
	int file;

	file=open(DEVC, O_RDWR);

	ioctl(file, I2C_SLAVE, 0x08);
	
	char writeBuffer[1] = {
		address
	}; //Write address (HEX code)
	
	write(file, writeBuffer, 1);

	char readBuffer[10];
	if (read(file, readBuffer, 1))
		value = (int)readBuffer[0];

	close(file);
	return value;
}
