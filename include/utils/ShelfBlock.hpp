#ifndef SHELF_BLOCK_HPP
#define SHELF_BLOCK_HPP

#include "system/Interface.hpp"

class ShelfBlock {
private:
	/* variables */

	/* functions */

public:
	/* variables */
	static int neonWidth[BLOCKS_PER_COLUMN][BLOCKS_PER_ROW];
	static bool inc[BLOCKS_PER_COLUMN][BLOCKS_PER_ROW];

	/* functions */
	static void blockOn (int row, int column);
	static void blockOnMono (int row, int column, CRGB color);
	static void blockPulse (int row, int column);
	static void blockPulseMono (int row, int column, CRGB Color);
};

#endif
