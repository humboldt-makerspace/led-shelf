#include "system/Interface.hpp"

CRGB Interface::leds[NUM_DATA_PINS][NUM_LEDS];

void Interface::allLedsOff (void)
{
	for (int i = 0; i < NUM_DATA_PINS; i++) {
		for (int j = 0; j < NUM_LEDS; j++) {
			Interface::leds[i][j] = CRGB::Black;
		}
	}
}

void Interface::changeMode (void)
{
	/*if (mode == WallMode::AUDIO_VISUALIZER) mode = WallMode::LIGHT_SHOW_PRIDE;
	else {
		int tmp = (int) mode;
		tmp++;
		mode = (WallMode) tmp;
	}*/
	Interface::allLedsOff();
}
