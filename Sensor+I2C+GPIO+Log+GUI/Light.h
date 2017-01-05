#ifndef LIGHT_H
#define LIGHT_H

class Light{
public:
Light(int pin);
void Check();
void Set_Light(bool x);
private:	
int Timer;	
const int TimeOut = 900;
bool Active;
int Value;
int Pin;
};

#endif