#ifndef LAMP_H
#define LAMP_H

class Lamp {
public:
	Lamp();
	Lamp(int timeout);
	void Deactivate();
	void Activate();
	void Check();
	bool actief;
private:
	long timeout;
	long expire;
	bool timerExpire();
};
#endif
#pragma once
