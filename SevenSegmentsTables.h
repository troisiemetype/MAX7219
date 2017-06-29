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

#ifndef SEVEN_SEGMENTS_TABLES_H
#define SEVEN_SEGMENTS_TABLES_H

const uint8_t numbers[] PROGMEM = {
	B00111111,			// 0
	B00000110,			// 1
	B01011011,			// 2
	B01001111,			// 3
	B01100110,			// 4
	B01101101,			// 5
	B01111101,			// 6
	B00000111,			// 7
	B01111111,			// 8
	B01101111,			// 9
};

const uint8_t chars[] PROGMEM = {
	B00110111,			// A
	B01111100,			// B
	B00111001,			// C
	B01011111,			// D
	B01111001,			// E
	B01110001,			// F
	B00111101,			// G
	B01110100,			// H
	B00110000,			// I
	B00011110,			// J
	B00110101,			// K
	B01110000,			// L
	B00110111,			// M
	B01010100,			// N
	B01011100,			// O
	B01110011,			// P
	B01100111,			// Q
	B01010000,			// R
	B01101101,			// S
	B01111000,			// T
	B00011100,			// U
	B00011110,			// V
	B00111110,			// W
	B01110110,			// X
	B01101110,			// Y

};

const uint8_t carret PROGMEM = B01000000;
const uint8_t blank PROGMEM = 0x00;

#endif