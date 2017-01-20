#include "Light.h"
#include <ctime>
#include <wiringPi.h>
#include <softPwm.h>
#include <thread>
#include <chrono>

#include<iostream>
using namespace std;



void TurnOn(int pin){

	int Value=0;
	while(Value<100){
		Value+=1;
		softPwmWrite(pin,Value);
		this_thread::sleep_for(chrono::milliseconds(20));
	}
	return;
}

void TurnOff(int pin){
	int Value=100;
	while(Value>0){
		Value-=1;
		softPwmWrite(pin,Value);
		this_thread::sleep_for(chrono::milliseconds(20));
	}
	return;
}



Light::Light(int pin):Pin(pin){

	softPwmCreate(pin,0,100);

}

bool Light::Check(){
	if((time(0) > Timer)&&(Active)){
		cout<<"turningoff"<<endl;
		Active=false;
		thread turnoff(TurnOff, Pin);
		turnoff.detach();
		return 0;
	}
	else if(Active)
		return 1;
	else
		return 0;
}

void Light::Set_Light(bool x){
	if((x) && (!Active)){		
		cout<<"turningon"<<endl;
		Timer = time(0) + TimeOut;
		Active=true;
		thread turnon(TurnOn, Pin);
		turnon.detach();
	}
	else if((x) && (Active)) { 
		Timer = time(0) + TimeOut; 
	}
	else if(!x)
		Timer=time(0);//+3; //3 seconds till lights turn off
}