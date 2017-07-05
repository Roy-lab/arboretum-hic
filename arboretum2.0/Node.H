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

#ifndef _NODE_
#define _NODE_

#include <vector>
using namespace std;
#include "CommonDefs.H"


class Node
{
	public:
		Node();
		~Node();
		int setName(const char*);
		const char* getName();
		
		//This applies primarily to the gene and protein nodes
		int setIdInData(int id);
		int getIdInData();
		//Set the id according to topsort
		int setTopSortId(int id);
		int getTopSortId();
		typedef enum
		{
			GENE,
			PROTEIN,
			STAT_PG,
			STAT_PP,
			DYN_PG,
			DYN_PP
		}NodeType;
		
		int setNodeType(NodeType);
		NodeType getNodeType();

		int setValues(vector<int>&);
		vector<int>& getValues();
		//This is the string version of the value vector above
		const char* getValueStr();

		int addChild(Node*);
		int addParent(Node*);
		vector<Node*>& getChildren();
		vector<Node*>& getParents();
		int getNeighbourCnt();
	private:
		char nodeName[GENENAME_LEN];
		int nodeId;
		int topsortId;
		NodeType ntype;
		vector<Node*> children;
		vector<Node*> parents;
		vector<int> values;
		char valueStr[VALSTR_LEN];
};
#endif
