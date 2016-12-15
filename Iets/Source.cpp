#include <string.h>

#include <iostream>
#include <cstdio>
#include <ctime>
#include <unistd.h>
#include <thread>

#include "GPIO.h"
#include "Sensor.h"
#include "DrukSensor.h"
#include "Lamp.h"
#include "MotieSensor.h"
#include "I2C.h"

//GUI
#include "dialog.h"
#include <QApplication>
//

bool done=false;

//Slaap + lichten+ heartbeat+ gui+ log+ sql
//I/O  +  knx(temperatuur)

using namespace std;

void routine(){
//	cout << time(0) << "   :start" << endl;
	Lamp y(18);
    MotieSensor Motie(0xFC, y);
    DrukSensor Druk(0xCC);
i2c_open();
	bool status[8] = {0};

 //   cout<<"start loop"<<endl;
	while(done==false){
		status[0]=Druk.check();
		status[1]=Motie.check();	
		usleep(1000000);
		if (status[0] & status[1]) {
			cout<<"alarm"<<endl;  //<<BUG: Overflow to I2C making values exceptional!
//			cout<< GPIORead(18) <<endl;
//			cout << std::time(0) << "   :END"<<endl;			
		}

	}
cout<<"done loop"<<endl;
}





int main(int argc, char *argv[]) {		


	GPIOExport(18);
	GPIODirection(18,1);
	GPIOWrite(18,0);

	std::thread mainloop(routine);
	


    QApplication a(argc, argv);
    Dialog w;
    w.show();
    a.exec();
	
	done=true;
    
	mainloop.join();	
	return(0);
		
	
}
