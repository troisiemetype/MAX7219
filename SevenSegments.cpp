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


#include "MAX7219.h"
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

