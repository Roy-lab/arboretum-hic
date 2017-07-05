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

#ifndef _GENETREEMGR_
#define _GENETREEMGR_
#include <map>
using namespace std;
class GeneTree;
class SpeciesDistManager;
class MappedOrthogroup;
class GeneTreeManager
{
	public:
	GeneTreeManager();
	~GeneTreeManager();
	int setSpeciesTree(SpeciesDistManager::Species*);
	int setSpeciesDistManager(SpeciesDistManager*);
	int setGeneTreeDir(const char*);
	GeneTree* getGeneTree(int);	
	GeneTree* getGeneTree(MappedOrthogroup*);	
	GeneTree* generateTree(MappedOrthogroup*);
	GeneTree* generateTreeFromFile(MappedOrthogroup*);
	inline int getTotalAdditionalParents()
	{
		return totalAdditionalParents;
	}
	int showTotalAdditionalParentDist();
	int countLossForTree(int);
	private:
	int showTree(GeneTree*);
	int pruneTree(GeneTree*);
	int insertTree(GeneTree* node);
	int setNodeType(GeneTree* node);
	int identifyAncestorWithDuplicates(SpeciesDistManager::Species* speciesnode,MappedOrthogroup* mor,SpeciesDistManager::Species** duplicateSpecies);
	const char* getSpeciesName(GeneTree* node);
	int getSpeciesName(GeneTree* node,map<string,int>&);
	GeneTree* createTree(SpeciesDistManager::Species* duplicateSpecies,SpeciesDistManager::Species* node, MappedOrthogroup* mor, int copyno);
	GeneTree* readTreeFromFile(const char* treePath);
	int addKpolGene(GeneTree*,string&);
	GeneTree* isKpolAnc(GeneTree* gtree,string& parentName);
	int countLossForTree(GeneTree*);
	map<int,GeneTree*> genetreeSet;
	SpeciesDistManager::Species* speciestreeRoot;
	SpeciesDistManager* sdMgr;
	//SK: variable for gene tree direrctory, to be used if readung in from files instead of the MappedOrthogroupReader object
	char dirName[1024];
	int totalAdditionalParents;
	map<string,int> addedParents;
};
#endif
