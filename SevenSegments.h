/*
 * This Arduino library interfacing a MAX7219 led-diplay driver chip.
 * Copyright (C) 2017  Pierre-Loup Martin
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Pins needed:
 * DIN (pin 1): data in. Shift bits from MCU.
 * LOAD (pin 12): update data sent on load's rising edge.
 * CLK (pin 13): 10MHz max. Data shifted into register on rising edge.
 * Data shifted out to chained chips on falling edge.
 */

#ifndef SEVEN_SEGMENTS_H
#define SEVEN_SEGMENTS_H

#include <Arduino.h>

#include "SevenSegmentsTables.h"

class SevenSegments:public MAX7219{
public:
	void begin(uint8_t dataPin, uint8_t loadPin, uint8_t clkPin, uint8_t nbDigit = 8);

	void setDigit(uint8_t digit, uint8_t value);
	void clrDigit(uint8_t digit);

	void setDot(uint8_t digit);
	void clrDot(uint8_t digit);

protected:

private:
	uint8_t _nbDigit;

	uint8_t _digit[8];
};

#endif