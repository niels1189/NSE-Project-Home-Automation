#ifndef LIGHT_H
#define LIGHT_H

#include <thread>

class Light{
public:
Light(int pin);
bool Check();
void Set_Light(bool x);
private:	
int Timer =0 ;	
const int TimeOut = 20;
bool Active = false;
//int Value = 0;
int Pin;

};

#endif