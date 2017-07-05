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

#ifndef _SLIM_FACTOR
#define _SLIM_FACTOR
#include <iostream>
using namespace std;

#include "CommonTypes.H"
class Variable;
class Potential;

class SlimFactor
{
	public:
		SlimFactor();
		SlimFactor(int);
		~SlimFactor();
		//This returns the ids of the maximal subsets of this factor. That is
		//all subsets with vCnt-1 factors
		int generateMaximalSubsets(int**);
		int getSetDiff(SlimFactor* aFactor,int* diffVIds,int& diffSize);
		bool isMemberVariable(int v);
		int genMBSubsets(int);
		int thresholdToOne(double);
		bool allEntriesInsignificant();
		int showFactor(ostream&, VSET& variableSet, bool newLine=true);

		int fId;
		int* vIds;
		int vCnt;
		int secondPId;
		double mutualInfo;
		double conditionalEntropy;
		double marginalEntropy;
		double jointEntropy;
		double mbScore;
		double moveScore;
		double confidence;
		//The collection of all Markov blankets that are good for this factor
		INTDBLMAP goodMBIDs;
		//The merged Markov blanket 
		INTINTMAP mergedMB;
		INTDBLMAP candidateNeighbours;
		vector<int> candidateNeighbours_vect;
		vector<INTINTMAP*> mbSubsets;
		//Store the start indices for Markov blanket subsets of different sizes
		map<int,int> mbSubsetStartInd;
		Potential* canonicalParams;
};
#endif
