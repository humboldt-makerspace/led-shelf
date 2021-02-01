#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "constants.hpp"
#include "Arduino.h"
#include "FastLED.h"

#include "utils/ColorGradient.hpp"
#include "utils/ShelfBlock.hpp"

class Interface {
private:
	/* variables */

	/* functions */
	static void changeMode (void);

public:
	/* variables */
	static CRGB leds[NUM_DATA_PINS][NUM_LEDS];

	/* functions */
	static void allLedsOff (void);
};

#endif
