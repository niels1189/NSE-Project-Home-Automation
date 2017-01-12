#ifndef pressureSensor_H
#define pressureSensor_H

class pressureSensor {
public:
	pressureSensor(int address);
	int value();
private:
	int input;
	int value;
};

#endif