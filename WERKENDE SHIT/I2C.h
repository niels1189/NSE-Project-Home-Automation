#ifndef i2c_H
#define i2c_H

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


using namespace std;

/*
* I2CCom is needed for the I2C communication
*/

class I2CCom {
public:
	I2CCom(const char* File,int address);  //constructor with the file to use as buffer.
	int I2C_GetValue(int hex); //gets the value received from the address parameter.
	~I2CCom();				//Deconstructor which closes the file
private:
	int i2cfile;  //buffer file
};
#endif