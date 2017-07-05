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

#ifndef _GRAPH
#define _GRAPH
#include <map>
#include <string>
#include <vector>
#include "Node.H"
using namespace std;
typedef map<string,Node*> VERTEX_SET;
typedef map<string,Node*>::iterator VERTEX_SET_ITER;

class Node;
class Graph
{
	public:
		Graph();
		~Graph();
		int addNode(const char*,Node::NodeType,int,vector<int>&);
		int addEdge(const char*,const char*);
		int doTopologicalSort();
		vector<Node*>& getTopologicalSort();
		int genPNLInputFormat(const char*);
	private:
		int dfsVisit(Node*,int);
		VERTEX_SET nodeSet;
		vector<Node*> topSorted_R;
		vector<Node*> topSorted;
		map<string,int> visitFlag;
};
#endif
