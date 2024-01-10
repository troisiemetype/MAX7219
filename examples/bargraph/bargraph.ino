#include "MAX7219.h"

const uint8_t PIN_DATA = 14;
const uint8_t PIN_CLK = 16;
const uint8_t PIN_LOAD = 3;

uint32_t counter = 1;

MAX7219 max;

void setup(){
	max.begin(PIN_DATA, PIN_LOAD, PIN_CLK);

	max.setScanLimit(7);
//	max.turnOff();
	max.setIntensity(8);
	max.clrAll();
}

void loop(){
	max.setDigit(7, counter);

//	counter++;
	counter *= 2;
//	counter |= 0xFF;

	if(counter >= 127) counter = 1;

	delay(250);
}