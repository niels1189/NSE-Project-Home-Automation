#include "Light.h"
#include <ctime>
#include <WiringPi.h>
#include <softPwm.h>

using namespace std;

Light::Light(int pin):Pin(pin) {

	softPwmCreate(pin,0,100);

}

bool Light::Check(){
	if(Actief && Value<100) {
		Value+=2;
		softPwmWrite(Pin,Value);
		timerSet(1);
		return 1;
	}

	if(!Actief && Value>0) {
		Value-=2;
		softPwmWrite(Pin,Value);
		timerSet(1);
		return 1;
	}

	if(time(0) > Timer) {
		this->Active=false;
		timerSet(0);
		return 0;	
	}
}

void Light::timerSet(bool x) {
	if(x) {
		this->Timer = time(0) + this->TimeOut;
		this->Active=true;
		return;
	}
	else {
		Active=false;
		return;
	}
}
