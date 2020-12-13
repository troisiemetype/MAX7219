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

	MAX7219::begin(dataPin, loadPin, clkPin);
	_limit = nbDigit;

	for(uint8_t i = 0; i < 8; ++i){
		_digit[i] = 0;
	}

	setScanLimit(_limit);
}

void SevenSegments::setDigit(uint8_t digit, uint8_t value){
	if(value > 9) return;
	_digit[digit] &= ~0x7F;
	_digit[digit] |= pgm_read_byte_near(numbers + value);
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
		newDigit = carret;
	} else {
		newDigit = 0;
	}

	if(text >= 'A' && text <= 'Z'){
		newDigit = pgm_read_byte_near(chars + text - 'A');
	}

//	_digit[digit] &= ~0x7F;
	_digit[digit] = 0;
	_digit[digit] |= newDigit;
	MAX7219::setDigit(digit, _digit[digit]);
}

void SevenSegments::setText(String text){
	uint8_t length = text.length();
	for(uint8_t i = 0; i < _limit; i++){
		if (i == length) break;
		setChar(i, text.charAt(i));
	}
}

void SevenSegments::setInt(uint16_t value){
	uint8_t dim = 0;
	if(value > 999){
		dim = 4;
	} else if (value > 99){
		dim = 3;
	} else if (value > 9){
		dim = 2;
	} else {
		dim = 1;
	}

	for(uint8_t i = 0; i < _limit; i++){
		uint8_t digit = _limit - i - 1;
		if(i < dim){
			setDigit(digit, value % 10);
			value /= 10;
		} else {
			clrDigit(digit);
		}
	}
}

// End of the SevenSegments methods

// SevenSegmentsClock methods


void SevenSegmentsClock::begin(SevenSegments* ledDriver){
	_ledDriver = ledDriver;

	_minutes = 0;
	_seconds = 0;
	_dots = 0;
	_enable = true;

}

void SevenSegmentsClock::update(){
	if(_enable){
		_ledDriver->setDigit(3, _seconds%10);
		_ledDriver->setDigit(2, _seconds/10);
		_ledDriver->setDigit(1, _minutes%10);

		//test minutes value, so there is no leading zero displayed.
		uint8_t tenth = _minutes/10;
		if(tenth == 0){
			_ledDriver->clrDigit(0);
		} else {
			_ledDriver->setDigit(0, _minutes/10);
		}
	} else {

		// TODO: Try this instead, and see if the other setting are kept
		//_ledDriver->turnOff();
		for(uint8_t i = 0; i < 4; i++){
			_ledDriver->clrDigit(i);
			_ledDriver->clrDot(i);
		}
	}


}

void SevenSegmentsClock::setMinutes(uint8_t minutes){
	_minutes = minutes;
}

void SevenSegmentsClock::setSeconds(uint8_t seconds){
	_seconds = seconds;
}

void SevenSegmentsClock::setDots(bool value){
		_dots = value;
		if(value){
			_ledDriver->setDot(1);
		} else {
			_ledDriver->clrDot(1);
		}
}

void SevenSegmentsClock::clrDots(){
	setDots(false);
}

void SevenSegmentsClock::enable(bool value){
	_enable = value;
}
