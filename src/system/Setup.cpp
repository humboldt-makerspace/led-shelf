#include "system/Setup.hpp"
#include "system/Interface.hpp"
#include "features/Lightshow.hpp"

void initLeds (void)
{
	FastLED.addLeds<WS2812B, LED_PIN_1, GRB>(Interface::leds[TOP_SHELF], NUM_LEDS);
	FastLED.addLeds<WS2812B, LED_PIN_2, GRB>(Interface::leds[MIDDLE_SHELF], NUM_LEDS);
	FastLED.addLeds<WS2812B, LED_PIN_3, GRB>(Interface::leds[BOTTOM_SHELF], NUM_LEDS);
}

void initPositions (void)
{
	for (int i = 0; i < NUM_DATA_PINS; i++) {
		LightShow::pulsePosition[i] = i * ROW_SHIFT;
		LightShow::shiftPosition[i] = i * ROW_SHIFT;
		LightShow::inc[i] = true;
	}
	for (int i = 0; i < BLOCKS_PER_COLUMN; i++) {
		for (int j = 0; j < BLOCKS_PER_ROW; j++) {
			ShelfBlock::neonWidth[i][j] = 0;
			ShelfBlock::inc[i][j] = true;
		}
	}
}

void initColors (void)
{
	ColorGradient::changeColorGradient(RAINBOW);
	ColorGradient::satColors[0] = CRGB::Red;
	ColorGradient::satColors[1] = CRGB::Blue;
	ColorGradient::satColors[2] = CRGB::Green;
	ColorGradient::satColors[3] = CRGB::Orange;
	ColorGradient::satColors[4] = CRGB::Yellow;
	ColorGradient::satColors[5] = CRGB::Magenta;
	ColorGradient::satColors[6] = CRGB::Cyan;
	ColorGradient::satColors[7] = CRGB::Violet;
	ColorGradient::satColors[8] = CRGB::Pink;
	ColorGradient::satColors[9] = CRGB::Olive;
	ColorGradient::satColors[10] = CRGB::Purple;
	ColorGradient::satColors[11] = CRGB::Brown;
}

void Setup::init (void)
{
	Serial.begin(115200);
	initLeds();
	initColors();
	initPositions();
}
