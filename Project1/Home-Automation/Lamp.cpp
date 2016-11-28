#include "Lamp.h"
#include <ctime>


Lamp::Lamp() {
	actief = 0;

}

void Lamp::Activeer(void) {
	actief = true;
	start = std::clock();
}

void Lamp::Deactiveer() {
	start = 0;
	actief = 0;
}

void Lamp::check() {
	if (start > 0) {
		long x = std::clock() - start;
		if (x > (1500 * 60))
			Deactiveer();
	}
}
