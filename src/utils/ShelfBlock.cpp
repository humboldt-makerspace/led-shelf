#include "utils/ShelfBlock.hpp"

int ShelfBlock::neonWidth[BLOCKS_PER_COLUMN][BLOCKS_PER_ROW];
bool ShelfBlock::inc[BLOCKS_PER_COLUMN][BLOCKS_PER_ROW];

void ShelfBlock::blockOn (int row, int column)
{
	int begin = column * LEDS_PER_BLOCK;
	int end = (column + 1) * LEDS_PER_BLOCK;
	for (int i = begin; i < end; i++) {
		Interface::leds[row][i] = ColorGradient::colors[i];
	}
}

void ShelfBlock::blockOnMono (int row, int column, CRGB color)
{
	int begin = column * LEDS_PER_BLOCK;
	int end = (column + 1) * LEDS_PER_BLOCK;
	for (int i = begin; i < end; i++) {
		Interface::leds[row][i] = color;
	}
}

void ShelfBlock::blockPulse (int row, int column)
{
	int begin = column * LEDS_PER_BLOCK;
	int end = (column + 1) * LEDS_PER_BLOCK;
	int middle = column * LEDS_PER_BLOCK + LEDS_PER_BLOCK / 2;
	for (int i = begin; i < end; i++) {
		if (i < middle + ShelfBlock::neonWidth[row][column] && i > middle - ShelfBlock::neonWidth[row][column]) {
			Interface::leds[row][i] = ColorGradient::colors[i];
		}
		else Interface::leds[row][i] = CRGB::Black;
	}
	if (ShelfBlock::neonWidth[row][column] > LEDS_PER_BLOCK / 2) ShelfBlock::inc[row][column] = false;
	else if (ShelfBlock::neonWidth[row][column] <= 0) ShelfBlock::inc[row][column] = true;

	ShelfBlock::inc[row][column] ? ShelfBlock::neonWidth[row][column]++ : ShelfBlock::neonWidth[row][column]--;
}

void ShelfBlock::blockPulseMono (int row, int column, CRGB color)
{
	int begin = column * LEDS_PER_BLOCK;
	int end = (column + 1) * LEDS_PER_BLOCK;
	int middle = column * LEDS_PER_BLOCK + LEDS_PER_BLOCK / 2;
	for (int i = begin; i < end; i++) {
		if (i < middle + ShelfBlock::neonWidth[row][column] && i > middle - ShelfBlock::neonWidth[row][column]) {
			Interface::leds[row][i] = color;
		}
		else Interface::leds[row][i] = CRGB::Black;
	}
	if (ShelfBlock::neonWidth[row][column] > LEDS_PER_BLOCK / 2) ShelfBlock::inc[row][column] = false;
	else if (ShelfBlock::neonWidth[row][column] <= 0) ShelfBlock::inc[row][column] = true;

	ShelfBlock::inc[row][column] ? ShelfBlock::neonWidth[row][column]++ : ShelfBlock::neonWidth[row][column]--;
}
