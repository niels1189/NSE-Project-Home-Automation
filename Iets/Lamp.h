#ifndef LAMP_H
#define LAMP_H

class Lamp {
public:
	Lamp(int id);
	void Deactiveer();  //zet lamp uit
	void Activeer();    //zet lamp aan + timer
	void check();		//check status van lamp
private:
	bool actief; // Aan/uit
	int id;
	int start; //Timer

	//int red;
	//int green;
	//int blue;	
	//void Settijd();
};
#endif
#pragma once
