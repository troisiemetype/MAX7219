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

#ifndef MATRIX64_H
#define MATRIX64_H

#include <Arduino.h>

class Matrix64:public MAX7219{
public:

	void begin(uint8_t dataPin, uint8_t loadPin, uint8_t clkPin);

	void setDot(uint8_t index);
	void setDot(uint8_t col, uint8_t row);

	void clrDot(uint8_t index);
	void clrDot(uint8_t col, uint8_t row);

	void setCol(uint8_t col);
	void clrCol(uint8_t col);

	void setRow(uint8_t row);
	void clrRow(uint8_t row);

protected:

	inline uint8_t indexToCol(uint8_t index){return (index % 8);}
	inline uint8_t indexToRow(uint8_t index){return (index / 8);}
	inline uint8_t posToIndex(uint8_t col, uint8_t row){return (col + row * 8);}

	void setScanLimit(uint8_t limit);

	void setDecodeMode(uint8_t value);
	void setDecodeMode(uint8_t digit, bool state);

private:
	uint8_t _state[8];

};

#endif