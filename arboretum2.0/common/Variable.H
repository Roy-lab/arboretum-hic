/*
 *     This file is part of Arboretum-Hi-C.
 *         
 *     Arboretum: An algorithm to cluster functional genomesomics data from multiple species
 *     Copyright (C) 2013-2016 Sushmita Roy's Lab sroy@biostat.wisc.edu
 *
 *     This program is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _VARIABLE
#define _VARIABLE

#include <map>
#include <string>

using namespace std;
#include "CommonTypes.H"

class Variable;

typedef map<int,Variable*> VSET;
typedef map<int,Variable*>::iterator VSET_ITER;

class Variable
{
	public:
		Variable();
		~Variable();
		//This is how the variable will be used throughout
		//the system
		int setID(int);
		int getID();
		//This is the name assigned to the variable by the user
		int setName(const char*);
		const string& getName();
		
		int setNextValue(int);
		int setValues(INTVECT&);
		INTVECT& getValues();
		int getValueCnt();
		bool isValidValue(int);
		int initEvidence(INTDBLMAP&);
	private:
		//The set of values this variable can take
		INTVECT valueSet;
		string name;
		int vId;
};
#endif
