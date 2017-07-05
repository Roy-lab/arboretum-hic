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

#ifndef _VARIABLE_MANAGER
#define _VARIABLE_MANAGER

#include <string>
#include <map>

using namespace std;

class Error;
class Variable;
class VariableManager
{
	public:
		VariableManager();
		~VariableManager();
		Error::ErrorCode readVariables(const char*);
		int getVarID(const char*);
		bool isValid(int,int);
		map<int,Variable*>& getVariableSet();
		Variable* getVariableAt(int);
	private:
		map<string,int> varNameIDMap;
		map<int,Variable*> variableSet;
		int globalVarId;
};
#endif
