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

#ifndef _RULE_
#define _RULE_

#include <map>
using namespace std;

class RegressionTree;
class Rule
{
	public:
	Rule();
	~Rule();
	int addCondition(RegressionTree*,int);
	map<int,RegressionTree*>& getAllConditions();
	int setMarginalEntropy(double);
	double getMarginalEntropy();
	int setCoverage(int);
	int getCoverage();
	int showRule();
	int getBranch(int);
	double getRuleComplexity(int);
	private:
	map<int,RegressionTree*> conditionSet;
	map<int,int> conditionTest;
	double marginalEntropy;
	int coverage;
	
};
#endif
