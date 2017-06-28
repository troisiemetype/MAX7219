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
#include "Matrix64.h"


void Matrix64::begin(uint8_t dataPin, uint8_t loadPin, uint8_t clkPin){
	for(uint8_t i = 0; i < 8; i++){
		_state[i] = 0;
	}
	MAX7219::begin(dataPin, loadPin, clkPin);
}

void Matrix64::setDot(uint8_t index){
	setDot(indexToCol(index), indexToRow(index));
}

void Matrix64::setDot(uint8_t col, uint8_t row){
	_state[row] |= _BV(col);
	setDigit(row, _state[row]);
}

void Matrix64::clrDot(uint8_t index){
	setDot(indexToCol(index), indexToRow(index));
}

void Matrix64::clrDot(uint8_t col, uint8_t row){
	_state[row] &= ~_BV(col);
	setDigit(row, _state[row]);
}

void Matrix64::setCol(uint8_t col){
	for(uint8_t i = 0; i < 8; i++){
		_state[i] |= _BV(col);
		setDigit(i, _state[i]);
	}
}

void Matrix64::clrCol(uint8_t col){
	for(uint8_t i = 0; i < 8; i++){
		_state[i] &= ~_BV(col);
		setDigit(i, _state[i]);
	}
}

void Matrix64::setRow(uint8_t row){
	_state[row] = 0xFF;
	setDigit(row, _state[row]);
}

void Matrix64::clrRow(uint8_t row){
	_state[row] = 0x00;
	setDigit(row, _state[row]);
}

