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

#include <iostream>
using namespace std;

#include "RegressionTree.H"
#include "Rule.H"

Rule::Rule()
{
}

Rule::~Rule()
{
}

//True means gt and false means lteq
int 
Rule::addCondition(RegressionTree* aNode, int test)
{	
	int cid=conditionSet.size();
	conditionSet[cid]=aNode;
	conditionTest[cid]=test;
	return 0;
}

map<int,RegressionTree*>& 
Rule::getAllConditions()
{
	return conditionSet;
}

int
Rule::setMarginalEntropy(double anEntropy)
{
	marginalEntropy=anEntropy;
	return 0;
}

double
Rule::getMarginalEntropy()
{
	return marginalEntropy;
}

int
Rule::setCoverage(int c)
{
	coverage=c;
}

int
Rule::getCoverage()
{
	return coverage;
}

int
Rule::showRule()
{
	int parentBranch=-1;
	int shownCondition=0;
	for(map<int,RegressionTree*>::iterator lIter=conditionSet.begin();lIter!=conditionSet.end();lIter++)
	{
		RegressionTree* node=lIter->second;
		if(conditionTest[lIter->first]==-1)
		{
			continue;
		}
		double testValue=node->getTestValue();
		int testVar=node->getTestVariable();
		int gt=conditionTest[lIter->first];
		if(shownCondition>0)
		{
			cout <<" && ";
		}
		if(gt==1)
		{
			cout << "(" << testVar << " > " << testValue << ")";
		}
		else if(gt==0)
		{
			cout << "("<< testVar<< "<= " << testValue << ")";
		}
		shownCondition++;
	}
	cout << endl;
	return 0;
}

int
Rule::getBranch(int cId)
{
	int bval=-1;
	if(conditionTest.find(cId)==conditionTest.end())
	{
		return bval;
	}
	bval=conditionTest[cId];
}

double
Rule::getRuleComplexity(int delMe)
{
	double complexity=0;
	for(map<int,RegressionTree*>::iterator cIter=conditionSet.begin();cIter!=conditionSet.end();cIter++)
	{
		if(cIter->first==delMe)
		{
			continue;
		}
		complexity=complexity+cIter->second->getCodingLength();
	}
	return complexity;
}
