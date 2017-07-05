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

#ifndef _INTERACTIONS
#define _INTERACTIONS

#include <map>
#include <string>

using namespace std;

#include "CommonDefs.H"

class Interaction
{
	public:
		Interaction();
		~Interaction();
		int setMembers(const char*, const char*);
		const char* getFirstMember();
		const char* getSecondMember();
		int setProperty(const char*, const char*);
		const char* getProperty(const char*);
	private:	
		map<string,string> properties;
		char firstMember[GENENAME_LEN];
		char secondMember[GENENAME_LEN];
		int occurCnt;
};
#endif
