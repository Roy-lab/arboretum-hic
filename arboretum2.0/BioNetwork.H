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

#ifndef _BIONETWORK
#define _BIONETWORK
class BioNode;
class ProteinManager;
class GeneManager;
class InteractionManager;

class BioNetwork
{
	public:
		BioNetwork();
		~BioNetwork();
		int setProteinManager(ProteinManager*);
		int setGeneManager(GeneManager*);
		int setPPInteractionManager(InteractionManager*);
		int setPDInteractionManager(InteractionManager*);
		int createNetwork();
		int showNetworkStat();
		int getReachability();
		int getGraphInfo(const char*,int,map<int,int>&, map<string,int>&, map<string,int>&);
		int getDiffExpGenes(vector<int>&,int);
		int getAllNodeIDs(map<int,int>&);
	private:
		ProteinManager* pMgr;
		GeneManager* gMgr;
		InteractionManager* ppMgr;
		InteractionManager* pdMgr;
		map<string,BioNode*> bioNodeSet;
};
#endif
