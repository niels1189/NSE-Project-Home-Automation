#include "Light.h"
#include <ctime>
#include <wiringPi.h>
#include <softPwm.h>
#include <thread>
#include <chrono>

/* Program runs on the principle of a dead-timer
   Once the dead timer is reached, the lights turn off
   Once motion is detected, the timers will update itself.   
*/ 

using namespace std;



void turnOn(int pin){	// Turn on Light on pin
	int value=0;
	while(value<100){  // Fade in lights with a 100 b 20ms loop. Meaning over 2 seconds the light will fade in
		value+=1;
		softPwmWrite(pin,value); // PWM write to slowly increase brightness
		this_thread::sleep_for(chrono::milliseconds(20)); // time-delay (20ms)
	}
	return;
}

void turnOff(int pin) { // Turn off Light on pin
	int value=100;
	while(value>0){ // Fade out lights with a 100 b 20ms loop. Meaning the light will fade out over the span of 2 seconds
		value-=1;
		softPwmWrite(pin,value); // PWM write to slowly decrease brightness
		this_thread::sleep_for(chrono::milliseconds(20)); // time-delay (20ms)
	}
	return;
}



Light::Light(int pin):Pin(pin){
	softPwmCreate(pin,0,100); // Create a PWM instance for pin with a value between 0 and 100
}

bool Light::check(){
	if((time(0) > timer)&&(active)){ // if the current time is less than the timer (for expiry)
		active=false; //(meaning the dead-timer for the light has expired) and the Light is still active.
		thread turnOff(turnOff, Pin); // Turn off the lights. 
		turnOff.detach();
		return 0; // Return 0 because the timer expired.
	}
	else if(active) {
		return 1; // If light is still active (and on), return a 1
	}
	else
		return 0; // If the light is out, return 0
}

void Light::setLight(bool b) {
	if((b) && (!active)) { // If b is true and the lights are off. Turn on the lights
		timer = time(0) + timeOut; // current time + the time after which the lights will turn off sets the dead-time
		active=true;
		thread turnOn(turnOn, Pin);
		turnOn.detach();
	}
	else if((b) && (active)) { // If b is true and the lights are on. Update the dead-timer (if lights are on, no need to turn them on)
		timer = time(0) + timeOut; // current time + the time after which the lights will turn off sets the dead-time
	}
	else if(!b)
		timer=time(0)+3; // 3 seconds till lights turn off
}
