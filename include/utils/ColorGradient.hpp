#ifndef COLOR_GRADIENT_HPP
#define COLOR_GRADIENT_HPP

#include "system/Interface.hpp"

class ColorGradient {
private:
	/* variables */

	/* functions */

public:
	/* variables */
	static CRGB colors[SHELF_WIDTH];
	static CRGB satColors[NUM_COLORS];

	/* functions */
	static void changeColorGradient (ColorMode mode);
};

#endif
