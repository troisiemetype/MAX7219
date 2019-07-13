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
	0b01111110,			// 0
	0b00110000,			// 1
	0b01101101,			// 2
	0b01111001,			// 3
	0b00110011,			// 4
	0b01011011,			// 5
	0b01011111,			// 6
	0b01110000,			// 7
	0b01111111,			// 8
	0b01111011,			// 9
};

const uint8_t chars[] PROGMEM = {
	0b01110110,			// A
	0b00011111,			// B
	0b01001110,			// C
	0b01111101,			// D
	0b01001111,			// E
	0b01000111,			// F
	0b01011110,			// G
	0b00010111,			// H
	0b00000110,			// I
	0b00111100,			// J
	0b01010110,			// K
	0b00001110,			// L
	0b01110110,			// M
	0b00010101,			// N
	0b00011101,			// O
	0b01100111,			// P
	0b01110011,			// Q
	0b00000101,			// R
	0b01011011,			// S
	0b00001111,			// T
	0b00011100,			// U
	0b00111100,			// V
	0b00111110,			// W
	0b00110111,			// X
	0b00111011,			// Y

};

const uint8_t numbers_invert[] PROGMEM = {
	0b01111110,			// 0
	0b00000110,			// 1
	0b01101101,			// 2
	0b01001111,			// 3
	0b00010111,			// 4
	0b01011011,			// 5
	0b01111011,			// 6
	0b00001110,			// 7
	0b01111111,			// 8
	0b01011111,			// 9
};

const uint8_t chars_invert[] PROGMEM = {
	0b00111110,			// A
	0b01110011,			// B
	0b01111000,			// C
	0b01101111,			// D
	0b01111001,			// E
	0b00111001,			// F
	0b01111010,			// G
	0b00110011,			// H
	0b00110000,			// I
	0b01100110,			// J
	0b00111010,			// K
	0b01110000,			// L
	0b00111110,			// M
	0b00100011,			// N
	0b01100011,			// O
	0b00111101,			// P
	0b00011111,			// Q
	0b00100001,			// R
	0b01011011,			// S
	0b01110001,			// T
	0b01100010,			// U
	0b01100110,			// V
	0b01110110,			// W
	0b00110111,			// X
	0b01010111,			// Y
};


const uint8_t carret = 0b00000001;
const uint8_t blank PROGMEM = 0x00;

#endif