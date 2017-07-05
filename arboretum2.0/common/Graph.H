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

using namespace std;

class Vertex;
class Graph
{
	public:
		Graph();
		~Graph();
		int setDirectionality(bool);
		int makeGraph(const char*);
		int makeGraph(const char*,int);
		int getVertexCnt();
		int dumpGraph();
		int obtainConnectivity();
		int showConnectivity();

		bool isConnected();
		int getDegreeDist();
		int showDegreeDist(const char*);

		Vertex* getVertex(const char*);

	private:
		int getDegreeDist(bool,map<int,int>&);

		map<string,Vertex*> vertexList;
		map<string,Vertex*> untouchedVertexMap;
		map<int,int> indegreeDist;
		map<int,int> outdegreeDist;
		bool direction;
		
};

#endif
