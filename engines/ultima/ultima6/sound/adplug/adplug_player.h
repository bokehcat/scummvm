/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef H_ADPLUG_PLAYER
#define H_ADPLUG_PLAYER

#include "ultima/shared/std/string.h"

#include "opl.h"

class CPlayer {
public:
	CPlayer(Copl *newopl);
	virtual ~CPlayer();

	/***** Operational methods *****/
	void seek(unsigned long ms);

	virtual bool load(const std::string &filename) = 0; // loads file
	virtual bool update() = 0;          // executes replay code for 1 tick
	virtual void rewind(int subsong = -1) = 0;  // rewinds to specified subsong
	virtual float getrefresh() = 0;         // returns needed timer refresh rate

	/***** Informational methods *****/
	unsigned long songlength(int subsong = -1);

	virtual std::string gettype() = 0;  // returns file type
	virtual std::string gettitle() {    // returns song title
		return std::string();
	}
	virtual std::string getauthor() {   // returns song author name
		return std::string();
	}
	virtual std::string getdesc() {     // returns song description
		return std::string();
	}
	virtual unsigned int getpatterns() { // returns number of patterns
		return 0;
	}
	virtual unsigned int getpattern() { // returns currently playing pattern
		return 0;
	}
	virtual unsigned int getorders() {  // returns size of orderlist
		return 0;
	}
	virtual unsigned int getorder() {   // returns currently playing song position
		return 0;
	}
	virtual unsigned int getrow() {     // returns currently playing row
		return 0;
	}
	virtual unsigned int getspeed() {   // returns current song speed
		return 0;
	}
	virtual unsigned int getsubsongs() { // returns number of subsongs
		return 1;
	}
	virtual unsigned int getinstruments() { // returns number of instruments
		return 0;
	}
	virtual std::string getinstrument(unsigned int n) { // returns n-th instrument name
		return std::string();
	}

protected:
	Copl        *opl;   // our OPL chip

	static const unsigned short note_table[12]; // standard adlib note table
	static const unsigned char op_table[9];     // the 9 operators as expected by the OPL2
};

#endif