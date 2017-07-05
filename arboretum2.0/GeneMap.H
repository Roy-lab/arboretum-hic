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

/*Stores for every species, a list of genes. For each gene it stores its orthology relationships in several species*/
#ifndef _GENEMAP_
#define _GENEMAP_

#include <map>
#include <string>

using namespace std;
typedef map<string,int> STRINTMAP;
typedef map<string,int>::iterator STRINTMAP_ITER;
class GeneMap
{
	public:
	GeneMap();
	~GeneMap();
	int addPair(const string& srcGene, const string& targetSpecies, const string& targetGene);
	map<string,int>* getHits(const char* srcGene, const char* targetSpecies);
	map<string,map<string,STRINTMAP*>*>& getGeneSet();

	private:
	map<string,map<string,STRINTMAP*>*> geneSet;
};
#endif
