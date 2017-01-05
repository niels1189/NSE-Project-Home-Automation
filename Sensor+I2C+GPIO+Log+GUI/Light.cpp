#include "Light.h"
#include <ctime>
#include <WiringPi.h>
#include <softPwm.h>

using namespace std;

Light::Light(int pin):Pin(pin){

	softPwmCreate(pin,0,100);

}

void Light::Check(){

	if(Actief & Value<100){
		Value+=2;
		softPwmWrite(Pin,Value);
		return;
	}

	if(!Actief & Value>0){
		Value-=2;
		softPwmWrite(Pin,Value);		
		return;
	}	

	if(time(0) > timer)
		Active=false;
}

void Light::Set_Light(bool x){
	if(x){
		Timer = time(0) + TimeOut;
		Active=true;
		
	}
	else
		Active=false;
}