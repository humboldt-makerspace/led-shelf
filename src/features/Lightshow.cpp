#include "features/LightShow.hpp"
#include "system/Interface.hpp"

int LightShow::pulsePosition[NUM_DATA_PINS];
int LightShow::shiftPosition[NUM_DATA_PINS];
bool LightShow::inc[NUM_DATA_PINS];

void LightShow::pride (int row)
{
	static uint16_t sPseudotime = 0;
	static uint16_t sLastMillis = 0;
	static uint16_t sHue16 = 0;

	uint8_t sat8 = beatsin88(87, 220, 250);
	uint8_t brightdepth = beatsin88(341, 96, 224);
	uint16_t brightnessthetainc16 = beatsin88(203, (25 * 256), (40 * 256));
	uint8_t msmultiplier = beatsin88(147, 23, 60);

	uint16_t hue16 = sHue16;
	uint16_t hueinc16 = beatsin88(113, 1, 3000);

	uint16_t ms = millis();
	uint16_t deltams = ms - sLastMillis ;
	sLastMillis = ms;
	sPseudotime += deltams * msmultiplier;
	sHue16 += deltams * beatsin88(400, 5, 9);
	uint16_t brightnesstheta16 = sPseudotime;

	for (uint16_t i = 0; i < NUM_LEDS; i++) {
		hue16 += hueinc16;
		uint8_t hue8 = hue16 / 256;

		brightnesstheta16 += brightnessthetainc16;
		uint16_t b16 = sin16( brightnesstheta16  ) + 32768;

		uint16_t bri16 = (uint32_t)((uint32_t)b16 * (uint32_t)b16) / 65536;
		uint8_t bri8 = (uint32_t)(((uint32_t)bri16) * brightdepth) / 65536;
		bri8 += (255 - brightdepth);

		CRGB newcolor = CHSV(hue8, sat8, bri8);

		uint16_t pixelnumber = i;
		pixelnumber = (NUM_LEDS - 1) - pixelnumber;

		nblend(Interface::leds[row][pixelnumber], newcolor, 64);
	}
}

void LightShow::staticColor (int row)
{
	for (int x = 0; x < SHELF_WIDTH; x++) {
		Interface::leds[row][x] = ColorGradient::colors[x];
	}
}

void LightShow::pulse (int pulseWidth, int row)
{
	for (int x = 0; x < SHELF_WIDTH; x++) {
		if (x >= LightShow::pulsePosition[row] && x <= LightShow::pulsePosition[row] + pulseWidth - 1) Interface::leds[row][x] = ColorGradient::colors[x];
		else Interface::leds[row][x] = CRGB::Black;
	}
	if (LightShow::pulsePosition[row] >= SHELF_WIDTH - pulseWidth) inc[row] = false;
	else if (LightShow::pulsePosition[row] <= 0) inc[row] = true;

	inc[row] ? LightShow::pulsePosition[row]++ : LightShow::pulsePosition[row]--;
}

void LightShow::shift (int row)
{
	for (int x = 0; x < SHELF_WIDTH; x++) {
		int newColorIndex = x + LightShow::shiftPosition[row];
		if (newColorIndex > SHELF_WIDTH - 1) newColorIndex -= SHELF_WIDTH;
		Interface::leds[row][x] = ColorGradient::colors[newColorIndex];
	}
	LightShow::shiftPosition[row] >= SHELF_WIDTH - 1 ? LightShow::shiftPosition[row] = 0 : LightShow::shiftPosition[row]++;
}

void LightShow::blockChaos (void)
{
	std::vector<int> numbers;
	for (int i = 0; i < NUM_COLORS; i++) {
		numbers.push_back(i);
	}
	for (int i = 0; i < BLOCKS_PER_COLUMN; i++) {
		for (int j = 0; j < BLOCKS_PER_ROW; j++) {
			int randSelect = rand() % numbers.size();
			ShelfBlock::blockOnMono(i, j, ColorGradient::satColors[numbers.at(randSelect)]);
			numbers.erase(numbers.begin() + randSelect); 
		}
	}
	FastLED.delay(2000);
}

void LightShow::pulseBlockwise (void)
{
	for (int i = 0; i < BLOCKS_PER_COLUMN; i++) {
		for (int j = 0; j < BLOCKS_PER_ROW; j++) {
			ShelfBlock::blockPulse(i, j);
		}
	}
}
