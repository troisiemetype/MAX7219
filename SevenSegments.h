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



#ifndef SEVEN_SEGMENTS_H
#define SEVEN_SEGMENTS_H

#include <Arduino.h>
#include <avr/pgmspace.h>

#include "MAX7219.h"
#include "SevenSegmentsTables.h"

class SevenSegments:public MAX7219{
public:
	void begin(uint8_t dataPin, uint8_t loadPin, uint8_t clkPin, uint8_t nbDigit = 8);

	void setDigit(uint8_t digit, uint8_t value);
	void clrDigit(uint8_t digit);

	void setDot(uint8_t digit);
	void clrDot(uint8_t digit);

	void setChar(uint8_t digit, char text);
	void setText(String text);
	void setInt(uint16_t value);

protected:

private:

	uint8_t _digit[8];
};

class SevenSegmentsClock{
public:

	void begin(SevenSegments* ledDriver);

	void update();

	void setMinutes(uint8_t minutes);
	void setSeconds(uint8_t seconds);
	void setDots(bool value = true);
	void clrDots();
	void enable(bool value = true);

protected:
	uint8_t _minutes;
	uint8_t _seconds;
	bool _dots;

	SevenSegments* _ledDriver;

	bool _enable;

};

#endif