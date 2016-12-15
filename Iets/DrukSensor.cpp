#include "DrukSensor.h"
#include "Sensor.h"


#include <fstream>
#include <ctime>
#include <string>

#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

DrukSensor::DrukSensor(int id):Sensor(id,true) {	        
    slaap = false;  //slaap modus
    start = 0;   //tijd
    actief = false;  //staat van sensor
    actief2 = false;  //vorige staat van sensor
    sps = 0;  //spasms per second A.K.A state changes a second
    warning = 5; //aantal toegestaande sps
    slaaptijd = 5;//300

    loc = "slaaplog.txt";
	
}

void DrukSensor::Aanval() {
//	int x = 0;
	//alarm sturen en camera aanzetten
}

bool DrukSensor::check() {
	//reset heartbeat
    bool actief =false;
    int buffer = alive();
    if(3==buffer)
        actief=true;

	///slaap functies///
	//set timer
	if ((start==0)&actief & !slaap) {
		start = std::time(0);		
	}

	//sensor for X seconds active -- set sleep mode
	if ((start!=0)&actief & !slaap&(std::time(0) > (start + slaaptijd))) {
		slaap = true;
	//	std::cout<<"slaap aan"<<std::endl;
		write('I');
		//CAMERA UIT
	}

	//reset timer if sensor is not active
	if ((start!=0) & (!actief) & (!slaap)) {
		start = 0;
	}


	///sps functies///
	//state change when asleep
	if ((actief != actief2)&slaap) { //slaap mogelijk weg
		sps++;
		actief2 = actief;

		if (std::time(0) > start) { //reset na 1 sec
			sps = 0;
			start = std::time(0);
		}
	}
	//state changes exceed the warning limit
	if (sps > warning) {
		std::cout<<"AANVAL"<<std::endl;
		Aanval();
	}

	//out of bed
	//set timer
	if(slaap & !actief & (start==0)){
		start = std::time(0);
	}
	//state change - reset timer
	if (slaap & actief & (start!=0)) {
		start = 0;
	}
	//sensor for X seconds non-active -- reset sleep mode
	if (slaap & !actief & (std::time(0) > start + slaaptijd)) {
		slaap = false;
	//	std::cout<<"slaap uit"<<std::endl;
		write('O');
		//CAMERA AAN
	}

	//check
    if (buffer)
		return false;
	return true;
}
//Log functie -- file announced in main & char c = 'O'< Out of bed OF 'I'< In bed
void DrukSensor::write(char c) {	
	test.open(loc, (std::ios_base::out|std::ios_base::app));
	time_t t = time(0);   // get time now
	string y;
	//ctime_s(&y[0], 26, &t);
	y=ctime(&t);
	y.erase(y.find('\n'));
	test<<(y + " : " + c+"\n");
	test.close();
	return;
	//y[24] = ' ';
	//y[25] = '>';
	//y[26] = ' ';
	//y[27] = c;
	//y[28] = '\n';
	//y[29] = '\0';
	//test << y;

}


//debug
void DrukSensor::state() {
	if (actief == true) {
		actief = false;
		return;
	}
	if( actief == false)
		actief = true;
	write('S');
}
