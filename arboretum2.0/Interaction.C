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

#include <string.h>
#include "Interaction.H"

Interaction::Interaction()
{
	occurCnt=1;
}

Interaction::~Interaction()
{
}

int 
Interaction::setMembers(const char* mem1, const char* mem2)
{
	strcpy(firstMember,mem1);
	strcpy(secondMember,mem2);
	return 0;
}

const char*
Interaction::getFirstMember()
{
	return firstMember;
}

const char*
Interaction::getSecondMember()
{
	return secondMember;
}

int 
Interaction::setProperty(const char* name, const char* value)
{
	string nameStr(name);
	string valueStr(value);
	properties[nameStr]=valueStr;
	return 0;
}


const char* 
Interaction::getProperty(const char* name)
{
	string nameStr(name);
	map<string,string>::iterator aIter=properties.find(nameStr);
	if(aIter==properties.end())
	{
		return NULL;
	}
	return aIter->second.c_str();
}

