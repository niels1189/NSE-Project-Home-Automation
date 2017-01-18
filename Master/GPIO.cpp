#include <map>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
//#include <io.h>
#include <unistd.h> // <<  io.h

#define IN  0
#define OUT 1
#define LOW  0
#define HIGH 1

#include "GPIO.h"

using namespace std;

GPIO::GPIO(){}

int GPIO::GPIOExport(int pin){
	#define BUFFER_MAX 3
	char buffer[BUFFER_MAX];
	ssize_t bytesWritten;
	int fd;
 
	fd = open(("/sys/class/gpio/export"), O_WRONLY);
	if (-1 == fd) {
		fprintf(stderr, "Failed to open export for writing!\n");
		return(-1);
	}
 
	bytesWritten = snprintf(buffer, BUFFER_MAX, "%d", pin);
	write(fd, buffer, bytesWritten);
	close(fd);
	return(0);
}

int GPIO::GPIOUnexport(int pin){
	char buffer[BUFFER_MAX];
	ssize_t bytesWritten;
	int fd;
 
	fd = open("/sys/class/gpio/unexport", O_WRONLY);
	if (-1 == fd) {
		fprintf(stderr, "Failed to open unexport for writing!\n");
		return(-1);
	}
 
	bytesWritten = snprintf(buffer, BUFFER_MAX, "%d", pin);
	write(fd, buffer, bytesWritten);
	close(fd);
	return(0);
}

int GPIO::GPIODirection(int pin, int dir){
    static const char s_directions_str[]  = "in\0out";

	#define DIRECTION_MAX 35
	char path[DIRECTION_MAX];
	int fd;
 
	snprintf(path, DIRECTION_MAX, "/sys/class/gpio/gpio%d/direction", pin);
	fd = open(path, O_WRONLY);
	if (-1 == fd) {
		fprintf(stderr, "Failed to open gpio direction for writing!\n");
		return(-1);
	}
 
	if (-1 == write(fd, &s_directions_str[IN == dir ? 0 : 3], IN == dir ? 2 : 3)) {
		fprintf(stderr, "Failed to set direction!\n");
		return(-1);
	}
 
	close(fd);
	return(0);
}
 
int GPIO::GPIORead(int pin){

	if(pinsInUse.find(pin)==pinsInUse.end()){ //if pin is never used 
		if(GPIOExport(pin)!=0)
			return -2;
		if(GPIODirection(pin, 0)!=0)
			return -3;
		pinsInUse.insert(pair<int,int>(pin,0));
	}

	#define VALUE_MAX 30
	char path[VALUE_MAX];
	char value_str[3];
	int fd;
 
	snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
	fd = open(path, O_RDONLY);
	if (-1 == fd) {
		fprintf(stderr, "Failed to open gpio value for reading!\n");
		return(-1);
	}
 
	if (-1 == read(fd, value_str, 3)) {
		fprintf(stderr, "Failed to read value!\n");
		return(-1);
	}
 
	close(fd);
 
	return(atoi(value_str));
}

int GPIO::GPIOWrite(int pin, int value){

	if(pinsInUse.find(pin)==pinsInUse.end()){ //if pin is never used 
		if(GPIOExport(pin)!=0)
			return -2;
		if(GPIODirection(pin, 1))
			return -3;
		pinsInUse.insert(pair<int,int>(pin,1));
	}
	else if(pinsInUse[pin]==0){ //if pin is in read mode
		if(GPIODirection(pin, 1))
			return -3;
		pinsInUse[pin]=1;
	}


    static const char s_values_str[] = "01";

	char path[VALUE_MAX];
	int fd;
 
	snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
	fd = open(path, O_WRONLY);
	if (-1 == fd) {
		fprintf(stderr, "Failed to open gpio value for writing!\n");
		return(-1);
	}
 
	if (1 != write(fd, &s_values_str[LOW == value ? 0 : 1], 1)) {
		fprintf(stderr, "Failed to write value!\n");
		return(-1);
	}
 
	close(fd);
	return(0);
}


GPIO::~GPIO(){
	for(map<int,int>::iterator it=pinsInUse.begin(); it!=pinsInUse.end(); it++){
		GPIOUnexport(it->first);
	}

}
