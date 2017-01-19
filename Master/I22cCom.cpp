#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#include<sys/ioctl.h>
#include<linux/i2c.h>
#include<linux/i2c-dev.h>

#include "I22cCom.h"
using namespace std;


I2CCom::I2CCom(const char* File) {
	int file = open(File, O_RDWR);
	ioctl(file, I2C_SLAVE, 0x08);
	i2cfile = file;
}

int I2CCom::I2C_GetValue(int hex) {
	int writebuffer[10];
	writebuffer[0] = hex;
	write(i2cfile, writebuffer, 1);

	int readbuffer[10];
	read(i2cfile, readbuffer, 1);
	cout << hex << ":  " << readbuffer[0] << endl;
	
	return readbuffer[0];
}

I2CCom::~I2CCom() {
	close(i2cfile);
}
