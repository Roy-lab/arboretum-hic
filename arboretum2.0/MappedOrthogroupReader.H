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

#ifndef _ORTHOGROUP_READER
#define _ORTHOGROUP_READER
#include <map>
using namespace std;

class MappedOrthogroup;
class MappedOrthogroupReader
{
	public:
	MappedOrthogroupReader();
	~MappedOrthogroupReader();
	int readFile(const char*);
	int readSpeciesMapping(const char*);
	int getMappedOrthogroupID(const char*, const char*);
	MappedOrthogroup* getMappedOrthogroup(const char*, const char*);
	map<int,MappedOrthogroup*>& getMappedOrthogroups();
	STRINTMAP* getOrtholog(const char* srcSpecName, const char* geneName, const char* targetSpecName);

	private:
	int addMembers(char*,MappedOrthogroup*);
	int generateGeneOrthoMap();
	map<int,MappedOrthogroup*> orthogroupSet;
	map<string,STRINTMAP*> geneOrthoMap;
	map<int,string> speciesIDNameMap;
};
#endif
