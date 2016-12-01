#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define IN  0
#define OUT 1
 
#define LOW  0
#define HIGH 1
 
static int GPIOExport(int pin) {
	#define BUFFER_MAX 3
	char buffer[BUFFER_MAX];
	ssize_t bytes_written;
	int fd;
 
	fd = open("/sys/class/gpio/export", O_WRONLY);
	if (-1 == fd) {
		fprintf(stderr, "Failed to open export for writing!\n");
		return(-1);
	}
 
	bytes_written = snprintf(buffer, BUFFER_MAX, "%d", pin);
	write(fd, buffer, bytes_written);
	close(fd);
	return(0);
}
 
static int GPIOUnexport(int pin) {
	char buffer[BUFFER_MAX];
	ssize_t bytes_written;
	int fd;
 
	fd = open("/sys/class/gpio/unexport", O_WRONLY);
	if (-1 == fd) {
		fprintf(stderr, "Failed to open unexport for writing!\n");
		return(-1);
	}
 
	bytes_written = snprintf(buffer, BUFFER_MAX, "%d", pin);
	write(fd, buffer, bytes_written);
	close(fd);
	return(0);
}
 
static int GPIODirection(int pin, int dir) {
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
 
static int GPIORead(int pin) {
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
 
static int GPIOWrite(int pin, int value) {
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

#define led1	18 //
#define led2	23 //
#define buzzer	24 //
#define door	25 //
#define led3	 4 //
#define spare	21 //

#define pushb1  0xCC //
#define pushb2  0x8C //
#define bed		0xAC //
#define mov1	0xFC //
#define mov2	0xBC //
#define mov3	0xEC //
 
int main() {
	/*
	 * Enable GPIO pins
	 */
	int outputs[6] = {led1,led2,buzzer,door,led3,spare};
	for(int i=0;i<=6;i++) {
		if (-1 == GPIOExport(outputs[i])) // Set PIN input/output 
			return(1);
		if (-1 == GPIODirection(outputs[i], 1)) // Set PIN output
			return(2);
		if(i!=3) GPIOWrite(outputs[i], 0);
		else GPIOWrite(outputs[i], 1);
	}

	

	printf("I'm reading %d in GPIO %d\n", GPIORead(led1), led1);
	GPIOWrite(led1, 1); // Write value 1/0
	printf("I'm reading %d in GPIO %d\n", GPIORead(led1), led1);
	usleep(500 * 1000);
  
	if (-1 == GPIOUnexport(led1))
		return(4);
 
	return(0);
}
