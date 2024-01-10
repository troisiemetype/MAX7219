#include "MAX7219.h"

const uint8_t PIN_DATA = 14;
const uint8_t PIN_CLK = 16;
const uint8_t PIN_LOAD = 3;

uint32_t counter = 1;

uint8_t bar = 0;

MAX7219 max;

void setup(){
	max.begin(PIN_DATA, PIN_LOAD, PIN_CLK);

	max.setScanLimit(7);
//	max.turnOff();
	max.setIntensity(8);
	max.clrAll();
}

void loop(){
//	max.setDigit(7, counter);

//	counter++;
//	counter *= 2;
//	counter |= 0xFF;

//	if(counter >= 127) counter = 1;

	if(bar >= 30) bar = 0;

	uint8_t bit = bar % 8;
	uint8_t segment = bar / 8;

	for(uint8_t i = 0; i < 4; i++){
		if(i == segment) max.setDigit(7 - i, 1 << bit);
		else max.setDigit(7 - i, 0);
	}

	bar++;

	delay(250);
}