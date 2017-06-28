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

const uint8_t numbers[10] PROGMEM = {
	B00111111,
	B00000110,
	B01011011,
	B01001111,
	B01100110,
	B00101101,
	B01111101,
	B00000111,
	B01111111,
	B01101111,
}

#endif