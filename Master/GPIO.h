#ifndef GPIO_H
#define GPIO_H

#include <map>


class GPIO{
private:
	std::map<int,int> pinsInUse;
	int GPIOExport(int pin);
	int GPIOUnexport(int pin);
	int GPIODirection(int pin, int dir);
public:
	int GPIORead(int pin);
	int GPIOWrite(int pin, int value);
	GPIO();
	~GPIO();

};

#endif