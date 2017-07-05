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

#ifndef _ORTHOGROUP_
#define _ORTHOGROUP_
#include <string>
#include <map>
using namespace std;

class GeneMap;
class MappedOrthogroup
{
	public:
	MappedOrthogroup();
	~MappedOrthogroup();
	int setMembers(map<string,string>&);
	int setID(int);
	int getID();
	int incrCnt();
	int getCnt();

	map<string,GeneMap*>& getOrthoMembers();
	GeneMap* getSpeciesHits(const char* specName);
	STRINTMAP* getSpeciesHitsForGene(const char* srcSpecName, const char* targetSpecName, const char* geneName);
	map<int,map<string,string>*>& getGeneSets();
	private:
	map<string,GeneMap*> orthoMembers;
	map<string,int> scerHits;
	map<int,map<string,string>*> geneSets;
	map<string,int> specList;
	int oid;
	int cnts;
};
#endif
