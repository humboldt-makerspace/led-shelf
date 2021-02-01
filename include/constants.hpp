#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

/* data pins for led stripes */
#define LED_PIN_1				D0
#define LED_PIN_2				D1
#define LED_PIN_3				D2

/* physical led stripe positions */
#define BOTTOM_SHELF			0
#define MIDDLE_SHELF			1
#define TOP_SHELF				2

/* shelf block dimensions */
#define LEDS_PER_BLOCK			27
#define BLOCKS_PER_ROW			4
#define BLOCKS_PER_COLUMN		3

/* number of leds per data pin */
#define NUM_LEDS				108

/* total number of data pins */
#define NUM_DATA_PINS			3

/* shelf dimensions */
#define SHELF_WIDTH				108
#define SHELF_HEIGHT			3

/* initial shift between rows */
#define ROW_SHIFT				SHELF_WIDTH / 3

/* number of predefined colors */
#define NUM_COLORS				12

/* color modes for light show */
typedef enum colors {
	RAINBOW,
	SUPERMAN,
	AVH,
	TEMPERATURE,
	MONO
} ColorMode;

#endif
