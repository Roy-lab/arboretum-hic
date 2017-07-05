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

#include "Variable.H"

Variable::Variable()
{
}

Variable::~Variable()
{
}

int 
Variable::setName(const char* aStr)
{
	name.append(aStr);
	return 0;
}

const string& 
Variable::getName()
{
	return name;
}

int
Variable::setID(int aId)
{
	vId=aId;
	return 0;
}

int
Variable::getID()
{
	return vId;
}

int 
Variable::setNextValue(int aVal)
{
	valueSet.push_back(aVal);
	return 0;
}

int 
Variable::setValues(INTVECT& aValSet)
{
	for(int i=0;i<aValSet.size();i++)
	{
		valueSet.push_back(aValSet[i]);
	}
	return 0;
}

INTVECT& 
Variable::getValues()
{
	return valueSet;
}

int 
Variable::getValueCnt()
{
	return valueSet.size();
}


bool 
Variable::isValidValue(int aVal)
{
	bool found=false;
	int i=0;
	while((i<valueSet.size()) && (!found))
	{
		if(aVal==valueSet[i])
		{
			found=true;
		}
		i++;
	}
	return found;
}


int
Variable::initEvidence(INTDBLMAP& evidData)
{
	for(int i=0;i<valueSet.size();i++)
	{
		evidData[valueSet[i]]=0.0;
	}
	return 0;
}

