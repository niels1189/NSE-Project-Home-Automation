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
        bool Check();                   // Routine check
        void Set_Light(bool x);
    private:	
        int Timer           = 0; 
        const int TimeOut   = 900;      // How long will it take for the lights to turn off automatically
        bool Active         = false;    // Lights are off by default
        int Pin;
};

#endif
