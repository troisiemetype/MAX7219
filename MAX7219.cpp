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


void MAX7219::begin(uint8_t dataPin, uint8_t loadPin, uint8_t clkPin){
	_dataPin = dataPin;
	_loadPin = loadPin;
	_clkPin = clkPin;

	pinMode(dataPin, OUTPUT);
	pinMode(loadPin, OUTPUT);
	pinMode(clkPin, OUTPUT);
}

void MAX7219::turnOn(){
	sendCommand(SHUTDOWN, NORMAL_OPERATION);
}

void MAX7219::turnOff(){
	sendCommand(SHUTDOWN, SHUTDOWN_MODE);
}

void MAX7219::test(bool state){
	sendCommand(DISPLAY_TEST, state);
}

void MAX7219::setIntensity(uint8_t value){
	if(value > 15) value = 15;
	_intensity = value;
	sendCommand(INTENSITY, value);
}

void MAX7219::setScanLimit(uint8_t limit){
	_limit = limit;
	sendCommand(SCAN_LIMIT, limit);
}

void MAX7219::setDecodeMode(uint8_t value){
	_decodeMode = value;
	sendCommand(DECODE_MODE, _decodeMode);
}

void MAX7219::setDecodeMode(uint8_t digit, bool state){
	if(digit > 7) return;
	_decodeMode &= ~_BV(digit);
	_decodeMode |= (state << digit);
	setDecodeMode(_decodeMode);
}

void MAX7219::setDigit(uint8_t digit, uint8_t value){
	if(digit > 7) return;
	sendCommand((digit + 1), value);
}

void MAX7219::sendCommand(uint8_t address, uint8_t data){
	shiftOut(_dataPin, _clkPin, MSBFIRST, address);
	shiftOut(_dataPin, _clkPin, MSBFIRST, data);
}

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
	for(uint8_t = 0; i < 8; i++){
		_state[i] |= _BV(col);
		setDigit(i, _state[i]);
	}
}

void Matrix64::clrCol(uint8_t col){
	for(uint8_t = 0; i < 8; i++){
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
