#ifndef LIGHT_H
#define LIGHT_H

class Light{
public:
  Light(int pin);
  void Check();
  void timerSet(bool x);
private:	
  int Timer = 0;	
  const int TimeOut = 900;
  bool Active = false;
  int Value = 0;
  int Pin;
};

#endif
