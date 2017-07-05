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

#ifndef _FACTOR_GRAPH
#define _FACTOR_GRAPH

#include <map>

using namespace std;
class Variable;
class SlimFactor;
class VariableManager;
class FactorManager;

class FactorGraph
{
	public:
	FactorGraph();
	~FactorGraph();
	int setFactor(SlimFactor*);
	int getFactorCnt();
	SlimFactor* getFactorAt(int);
	map<int,SlimFactor*>& getAllFactors();
	int dumpFactors_ClusterFormat(const char*,int,VSET& variableSet);
	int dumpFactors_PairwiseFormat(const char*,int,VSET& variableSet);
	int dumpVarMB_ClusterFormat(const char*,int,VSET& variableSet,FactorManager*);
	int dumpVarMB_PairwiseFormat(const char*,int,VSET&,FactorManager*);
	int readVarMB_PairwiseFormat(const char* aFName,VariableManager* vMgr,FactorManager* fMgr);
	int dumpCandidateVarMB_PairwiseFormat(const char*,int,VSET&,FactorManager*);
	bool isConsistent();
	private:
	int showFactor_PW(SlimFactor*,ostream&,VSET& variableSet);
	map<int,SlimFactor*> factorSet;
};
#endif
