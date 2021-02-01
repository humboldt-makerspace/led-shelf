#ifndef LIGHT_SHOW_HPP
#define LIGHT_SHOW_HPP

#include "constants.hpp"

class LightShow {
private:
	/* variables */

public:
	/* variables */
	static int pulsePosition[NUM_DATA_PINS];
	static int shiftPosition[NUM_DATA_PINS];
	static bool inc[NUM_DATA_PINS];

	/* functions */
	static void pride (int row);
	static void staticColor (int row);
	static void pulse (int pulseWidth, int row);
	static void shift (int row);
	static void blockChaos (void);
	static void pulseBlockwise (void);
};

#endif
