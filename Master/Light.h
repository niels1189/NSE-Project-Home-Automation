#ifndef LIGHT_H
#define LIGHT_H

#include <thread>
/* Program runs on the principle of a dead-timer
   Once the dead timer is reached, the lights turn off
   Once motion is detected, the timers will update itself.   
*/

class Light{
    public:
	Light(int pin);
        bool check();                   // Routine check
        void setLight(bool b);
    private:	
        int timer           = 0;
        const int timeOut   = 900;      // How long will it take for the lights to turn off automatically
        bool active         = false;    // Lights are off by default
        int pin;
};

#endif
