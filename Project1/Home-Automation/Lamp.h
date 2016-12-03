#ifndef LAMP_H
#define LAMP_H

class Lamp {
public:
	Lamp();
	void Deactiveer();
	void Activeer();
	void check();
private:
	bool actief;
	int red;
	int green;
	int blue;
	int start;
//	void Settijd();
};
#endif
#pragma once
