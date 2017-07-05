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

#ifndef _GAMMA_
#define _GAMMA_
#include <map>
#include <string>
using namespace std;
class Matrix;
class GeneTree;
class Gamma
{
	public:
	Gamma();
	~Gamma();
	inline int setMaxClusterCnt(int k)
	{
		maxClusterCnt=k;
	}
	int addGene(string& geneName,string& specName,int maxClusterCnt);
	int setGeneClusterID(string&,string&,int);
	int initUsingGeneTree(GeneTree*);
	Matrix* getGamma(string&,string&);
	Matrix* getNormTerm(string&,string&);
	double getScore();
	struct Node;
	struct Node
	{
		string name;
		string species;
		Node* leftchild;
		Node* rightchild;
		Node* parent;
		//This is 2 for duplication and 1 for speciation
		int nodeType;
		int nodeID;
		Matrix* normTerm;
		Matrix* gamma;
		Matrix* alpha;
		Matrix* beta;
		bool hasData;
		map<int,double>* dataLL;
		bool excludeFlag;
	};
	Node* getRoot();
	Node* getGeneNode(string&,string&);
	Node* root;
	int showTree();
	map<int,double>* getDataLL(string&);
	string& getDupAncestor();
	double ll;
	private:
	Gamma::Node* initSubtree(GeneTree* gtreenode);
	Gamma::Node* initSubtree(GeneTree* gtreenode,string& rootname);
	int showTree(Node*);
	map<string,Node*> geneMap;
	map<string,Matrix*> gammas;
	map<string,map<int,double>*> datall;
	int maxClusterCnt;
	int nodeID;
	string dupAncName;
};
#endif
