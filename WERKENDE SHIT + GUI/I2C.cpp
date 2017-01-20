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

#include "I2C.h"
using namespace std;


I2CCom::I2CCom(const char* File,int address) {
	int file = open(File, O_RDWR);
	ioctl(file, I2C_SLAVE, address);
	i2cfile = file;
}

int I2CCom::I2C_GetValue(int hex) {
for(int x=0;x<2;x++){ //Called thrice to get rid of potential overflow/static
	int writebuffer[10];
	writebuffer[0] = hex;
	write(i2cfile, writebuffer, 1);

	int readbuffer[10];
	read(i2cfile, readbuffer, 1);
}	
//	int writebuffer[10];
//	writebuffer[0] = hex;
//	write(i2cfile, writebuffer, 1);
	
	int readbuffer[10]={0};
	read(i2cfile, readbuffer, 1);
	//readbuffer[0]-=85504;
//	cout<<readbuffer[0]<<endl;
	return readbuffer[0];
}

I2CCom::~I2CCom() {
	close(i2cfile);
}
