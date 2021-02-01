#include "includes.hpp"

void setup ()
{
	Setup::init();
}

void loop ()
{
	/*for (int i = 0; i < SHELF_HEIGHT; i++) {
		LightShow::pride(i);
	}*/
	LightShow::pulse(30, TOP_SHELF);
	LightShow::pulse(30, MIDDLE_SHELF);
	LightShow::pulse(30, BOTTOM_SHELF);
	//LightShow::blockChaos();
	//LightShow::pulseBlockwise();
	FastLED.show();
	FastLED.delay(1);
}
