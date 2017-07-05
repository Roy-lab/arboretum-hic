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

#ifndef _INTERACTIONMANAGER
#define _INTERACTIONMANAGER

#include <map>
#include <string>
#include "Interaction.H"

using namespace std;

class Interaction;
typedef map<string, Interaction*> INTR_MAP;
typedef map<string, Interaction*>::iterator INTR_MAP_ITER;

class InteractionManager 
{
	public:
		InteractionManager();
		~InteractionManager();
		int setDirectionality(bool);
		int setDelimiter(const char*);
		int readInteractions(const char*);
		INTR_MAP& getInteractions();
		
		bool isInteraction(const char*, const char*);
		int addInteraction(const char*,const char*);
		int getNumberOfIntr();
		Interaction* getInteractionAt(int);
		int dumpInteractions(const char*);
	private:
		int createKey(const char*, const char* ,string&);
		INTR_MAP interactionSet;
		map<int,string> intrIDtoString;
		bool directionality;
		char delim[5];
};
#endif
