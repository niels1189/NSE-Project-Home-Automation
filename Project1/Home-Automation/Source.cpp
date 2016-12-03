#include <string.h>

#include <iostream>
#include <cstdio>
#include <ctime>


#include "Sensor.h"
#include "DrukSensor.h"
#include "Lamp.h"
#include "MotieSensor.h"
using namespace std;


//Log functie -- file announced in main & char c = 'O'< Out of bed OF 'I'< In bed
#include <fstream>
void write(fstream& file,char c) {		
	time_t t = time(0);   // get time now
	char y[30];
	ctime_s(&y[0],26,&t);	
	y[24] = ' ';
	y[25] = '>';
	y[26] = ' ';
	y[27] = c;
	y[28] = '\n';
	y[29] = '\0';
	file << y;		
}

int main() {		
	fstream file("sleep_log.txt", std::ios_base::app | std::ios_base::out);//LOGFILE
	///write(file, 'O');  //Write time + O to logfile
	///write(file, 'I');  //Write time + I to logfile
		
	Lamp y;
	MotieSensor a(0x01, y);
	DrukSensor b(0x02);
	a.setlicht();
	bool status[8] = {0};
	while (1) {						
		y.check();
		status[0]=a.check();
		status[1]=b.check();	
		double z = std::clock();
		while (z + 1000 > std::clock()); //1sec wait		

	}
	file.close();  //CLOSE LOGFILE
	return 0;	
}
