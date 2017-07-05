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

#ifndef _MOTIFREADER_
#define _MOTIFREADER_

#include <map>
#include <string>
#include "CommonTypes.H"
class MotifManager
{
	public:
	MotifManager();
	~MotifManager();
	int readMotifs(const char*);
	int readMotifTFMap(const char*);
	INTDBLMAP* getMotifProfile(const char*);
	map<string,INTDBLMAP*>& getMotifProfileSet();
	map<int,string>& getMotifIDMap();
	map<string,int>& getMotifNameIDMap();
	map<int,string>& getMotifIDInterpretation();
	double getMotifVal(const string&,int);
	map<string,STRINTMAP*>& getMotifTFMap();
	private:
	map<string,INTDBLMAP*> motifProfileSet;
	map<string,int> motifIDMap;
	map<int,string> idmotifMap;
	map<int,string> motifIDInterpret;
	map<string,STRINTMAP*> motifTFMap;
};
#endif
