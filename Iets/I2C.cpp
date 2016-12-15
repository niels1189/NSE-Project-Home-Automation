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
///#define DEVC "/dev/i2c-1"// <-- this is the real I2C device you need with the scale model
#define DEVC "/dev/simudrv"
using namespace std;
int i2cfile;

extern int i2c_GetValue (int hex){	
	//int i2cfile=open(DEVC, O_RDWR);
	//ioctl(i2cfile, I2C_SLAVE, 0x08);
	int writebuffer[10];
	writebuffer[0]=hex;
	write(i2cfile,writebuffer,1);
	
	int readbuffer[10];
	read(i2cfile,readbuffer,1);
	cout<<hex<<":  "<<readbuffer[0]<<endl;
	//close(i2cfile);
	return readbuffer[0];
}

extern void i2c_open(){
    int file=open(DEVC, O_RDWR);
    ioctl(file, I2C_SLAVE, 0x08);
    i2cfile=file;
}

extern void i2c_close(){
	close(i2cfile);
}
