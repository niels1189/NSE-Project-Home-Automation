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


//#define DEVC "/dev/i2c-1" <-- this is the real I2C device you need with the scale model
#define DEVC "/dev/simudrv"
using namespace std;

int main() {
int file=open(DEVC, O_RDWR);

ioctl(file, I2C_SLAVE, 0x08);

// declare writeBuffer
int writeBuffer[10];
writeBuffer[0]=0xCC;
int readBuffer[10];
write(file, writeBuffer, 1);

read(file, readBuffer, 1);
int output = readBuffer[0];

cout << output << endl;
close(file);

return 0;
}

