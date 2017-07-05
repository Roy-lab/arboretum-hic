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

#ifndef _PROTEIN_MANAGER
#define _PROTEIN_MANAGER
#include <vector>
#include <map>
#include <string>
using namespace std;
class Protein;
class GeneManager;

typedef vector<Protein*> PROTSET;
typedef map<string,Protein*> PROTMAP;
typedef map<string,Protein*>::iterator PROTMAP_ITER;

class ProteinManager
{
	public:
		ProteinManager();
		~ProteinManager();
		int setGeneMgr(GeneManager*);
		int readProteinData(const char*);
		//The argument is a single line of the protein expression file
		int addProteinNode(const char*);
		Protein* getProteinNode(int id);
		Protein* getProteinWithName(const char*);
		int getTotalNumberOfProteins();
		int discretizeProteinExpr();
		int rankOrderProteinExpr();
		int scaleProteinExpr();
		int standardizeProteinExpr();
	private:
		PROTSET proteinSet;
		PROTMAP proteinMap;
		int proteinIds;
		GeneManager* geneMgr;
};
#endif
