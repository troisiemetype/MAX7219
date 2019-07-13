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
#include "Bargraph.h"


void Bargraph::init(uint8_t start, uint8_t end);

void Bargraph::setDot(uint8_t index);

void Bargraph::clrDot(uint8_t index);

void Bargraph::setArea(uint8_t start, uint8_t end);

void Bargraph::clrArea(uint8_t start, uint8_t end);
