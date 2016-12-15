#include "MotieSensor.h"
#include "Lamp.h"

MotieSensor::MotieSensor(int id,Lamp&gebondenlicht): Sensor(id, true),gebondenlicht(gebondenlicht) {

}

bool MotieSensor::check() {
gebondenlicht.check();		
    switch(alive()){
        case(3):
            setlicht();
            return false;
            break;
        case(1):
            return false;
            break;
        default:
            return true;
            break;
	}	
}

void MotieSensor::setlicht() {	
	gebondenlicht.Activeer();
}
