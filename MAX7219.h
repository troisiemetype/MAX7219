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

/*
 * Modes of operation:
 * 8 7-segments digits,
 * bargraph,
 * 8*8 Led matrix.
 */

/*
 * Functions to be implemented:
 * On/off
 * Intensity
 * Scan limit
 * Send data
 * Decode mode (to be set on normal mode on startup).
 * No-op for chained diplays.
 */

/*
* Data formatting:
* D15 D14 D13 D12 D11 D10 D9  D8  D7  D6  D5  D4  D3  D2  D1  D0
*  X   X   X   X   [  ADDRESS  ]  [MSB         DATA         LSB]
*/

#ifndef MAX7219_H
#define MAX7219_H

#include <Arduino.h>

class MAX7219{
public:

	void begin(uint8_t dataPin, uint8_t loadPin, uint8_t clkPin);

	void turnOn();
	void turnOff();

	void test(bool state);

	void setIntensity(uint8_t value);
	void setScanLimit(uint8_t limit);
	void setDecodeMode(uint8_t value);
	void setDecodeMode(uint8_t digit, bool state);

	void setDigit(uint8_t digit, uint8_t value);

	void clrAll();


protected:

	void sendCommand(uint8_t address, uint8_t data);

	enum RegAddress_t{
		NO_OP = 0,
		DIGIT_0 = 0x01,
		DIGIT_1 = 0x02,
		DIGIT_2 = 0x03,
		DIGIT_3 = 0x04,
		DIGIT_4 = 0x05,
		DIGIT_5 = 0x06,
		DIGIT_6 = 0x07,
		DIGIT_7 = 0x08,
		DECODE_MODE = 0x09,
		INTENSITY = 0x0A,
		SCAN_LIMIT = 0x0B,
		SHUTDOWN = 0x0C,
		DISPLAY_TEST = 0x0F,
		LINE_0 = 0x01,
		LINE_1 = 0x02,
		LINE_2 = 0x03,
		LINE_3 = 0x04,
		LINE_4 = 0x05,
		LINE_5 = 0x06,
		LINE_6 = 0x07,
		LINE_7 = 0x08,
	};

	enum Data_t{
		SHUTDOWN_MODE = 0x0,
		NORMAL_OPERATION = 0x1,
	};
	uint8_t _dataPin, _clkPin, _loadPin;
	uint8_t _intensity, _limit, _decodeMode;

private:

};

#endif