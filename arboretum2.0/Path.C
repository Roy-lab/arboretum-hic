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

#include "BioNode.H"
#include "Path.H"


Path::Path()
{
	copyFlag=false;
}

Path::~Path()
{
	nodeSet.clear();
}

int 
Path::setStartNode(BioNode* aNode)
{
	nodeSet.push_back(aNode);
	return 0;
}

int 
Path::addNode(BioNode* aNode)
{
	nodeSet.push_back(aNode);
	return 0;
}
	
int 
Path::getPathLength()
{
	return nodeSet.size();
}


BioNode*
Path::getNodeAt(int nodeId)
{
	return nodeSet[nodeId];
}

Path*
Path::copy()
{
	Path* newPath=new Path;
	for(int i=0;i<nodeSet.size();i++)
	{
		newPath->addNode(nodeSet[i]);
	}
	return newPath;
}

int 
Path::showPath(ostream& oFile)
{
	for(int i=0;i<nodeSet.size();i++)
	{
		if(i>0)
		{
			oFile <<" ";
		}
		oFile << nodeSet[i]->getName();
	}
	oFile << endl;
	return 0;
}


int 
Path::hasBeenCopied()
{
	copyFlag=true;
	return 0;
}

bool 
Path::isCopied()
{
	return copyFlag;
}
