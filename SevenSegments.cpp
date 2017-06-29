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
 * but WITHOUT ANY WARRANTY{
}
 without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "SevenSegments.h"


void SevenSegments::begin(uint8_t dataPin, uint8_t loadPin, uint8_t clkPin, uint8_t nbDigit){

	if(nbDigit > 8) nbDigit = 8;
	_limit = nbDigit;

	MAX7219::begin(dataPin, loadPin, clkPin);

	setScanLimit(_limit);
}

void SevenSegments::setDigit(uint8_t digit, uint8_t value){
	if(value > 9) return;
	_digit[digit] &= ~0x7F;
	_digit[digit] |= pgm_read_byte_near(numbers[value]);
	MAX7219::setDigit(digit, _digit[digit]);
}

void SevenSegments::clrDigit(uint8_t digit){
	_digit[digit] &= ~0x7F;
	MAX7219::setDigit(digit, _digit[digit]);
}

void SevenSegments::setDot(uint8_t digit){
	_digit[digit] |= 0x80;
	MAX7219::setDigit(digit, _digit[digit]);
}

void SevenSegments::clrDot(uint8_t digit){
	_digit[digit] &= ~0x80;
	MAX7219::setDigit(digit, _digit[digit]);
}

void SevenSegments::setChar(uint8_t digit, char text){
	uint8_t newDigit = 0;
	if(text >= '0' && text <= '9'){
		setDigit(digit, text - '0');
		return;
	} else if(text >= 'a' && text <= 'z'){
		text -= ('a' - 'A');
	} else if(text == '-'){
		newDigit = B01000000;
	} else {
		newDigit = 0;
	}

	if(text >= 'A' && text <= 'Z'){
		newDigit = pgm_read_byte_near(chars[text - 'A']);
	}

	_digit[digit] &= ~0x7F;
	_digit[digit] |= newDigit;
	MAX7219::setDigit(digit, _digit[digit]);
}
