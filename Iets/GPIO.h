#ifndef GPIO_H
#define GPIO_H
extern int  GPIOExport(int pin);
extern int GPIOUnexport(int pin);
extern int GPIODirection(int pin, int dir) ;
extern int GPIORead(int pin) ;
extern int GPIOWrite(int pin, int value) ;
#endif

#pragma once
