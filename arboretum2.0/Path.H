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

//This stores a directed path of BioNodes. Some of the edges in this path are undirected.
//In principle I could store names of nodes, but this would mean I am storing strings which is
//expensive. Instead storing pointers to BioNodes is better
#ifndef _PATH
#define _PATH

#include <vector>
#include <fstream>

using namespace std;

class BioNode;

class Path
{
	public:
		Path();
		~Path();
		int setStartNode(BioNode*);
		int addNode(BioNode*);
		int getPathLength();
		BioNode* getNodeAt(int);
		Path* copy();	
		int showPath(ostream&);
		int hasBeenCopied();
		bool isCopied();
	private:
		vector<BioNode*> nodeSet;
		bool copyFlag;
};

#endif
