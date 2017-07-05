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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Node.H"

Node::Node()
{
	valueStr[0]='\0';
}

Node::~Node()
{
}

int 
Node::setName(const char* aName)
{
	strcpy(nodeName,aName);
	return 0;
}

const char* 
Node::getName()
{
	return nodeName;
}

int 
Node::setNodeType(Node::NodeType aType)
{
	ntype=aType;
	return 0;
}

int 
Node::setIdInData(int id)
{
	nodeId=id;
	return 0;
}

int 
Node::getIdInData()
{
	return nodeId;
}

int 
Node::setTopSortId(int id)
{
	topsortId=id;
}

int 
Node::getTopSortId()
{
	return topsortId;
}


Node::NodeType 
Node::getNodeType()
{
	return ntype;
}

int 
Node::setValues(vector<int>& valSet)
{
	for(int i=0;i<valSet.size();i++)
	{
		values.push_back(valSet[i]);
		if(i==0)
		{
			sprintf(valueStr,"%d",valSet[i]);
		}
		else
		{
			char tempStr[5];
			sprintf(tempStr,",%d",valSet[i]);
			strcat(valueStr,tempStr);
		}
	}
	return 0;
}

vector<int>& 
Node::getValues()
{
	return values;
}

const char*
Node::getValueStr()
{
	return valueStr;
}

int 
Node::addChild(Node* aNode)
{
	children.push_back(aNode);
	return 0;
}

int 
Node::addParent(Node* aNode)
{
	parents.push_back(aNode);
	return 0;
}

vector<Node*>&
Node::getChildren()
{
	return children;
}
	
vector<Node*>&
Node::getParents()
{
	return parents;
}

int
Node::getNeighbourCnt()
{
	return parents.size()+children.size();
}
