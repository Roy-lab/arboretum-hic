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

#ifndef _SPECIES_DATA_
#define _SPECIES_DATA_

#include <map>
#include <vector>
#include <string>
using namespace std;
class Matrix;
class SpeciesDistManager
{
	public:
	SpeciesDistManager();
	~SpeciesDistManager();
	int readSpeciesTree(const char*);
	int setMaxClusters(int k);
	double getAncestralClustering(map<string,int>& extantStatus,map<string,int>& ancestralStatus);
	double getExtantClustering(map<string,int>& ancestralClustering, map<string,int>& extantClustering);
	double getConditionalProb(string& child,int parentCluster,int childCluster);
	//double getProbGainLoss(string&);
	//double getProbLossGain(string&);
	//double getProbLossLoss(string&);
	//int enumerateAllAncestors(map<string,int>& edgeStatus);
	double scoreAssignment(map<string,int>& jointAssign);
	double getEdgeStatusProb(map<string,int>& edgeStatus);
	int showInferredConditionals(const char* outputDir);
	int showInferredConditionals_ML(const char* outputDir);

	struct Species;

	struct Species 
	{
		string name;
		Species* parent;
		Species* leftchild;
		Species* rightchild;
		Matrix* conditional;
		Matrix* conditional_ml;
		inline Matrix* getParams()
		{
			return conditional;
		}
		map<int,vector<int>*> sortedClustIDs;
		inline vector<int>* getSortedClusterIDs(int rowID)
		{
			vector<int>* sortedIDs=NULL;
			if(sortedClustIDs.find(rowID)!=sortedClustIDs.end())
			{
				sortedIDs=sortedClustIDs[rowID];
			}
			return sortedIDs;
		}
		inline int setSortedClusterIDs(int rowId,vector<int>* sortedIDs)
		{
			sortedClustIDs[rowId]=sortedIDs;
		}
	};
	
	Species* getRoot();
	int assignLevel();
	int assignLevel(SpeciesDistManager::Species*,int);
	int getLevelFromRoot(const char* nodeName);
	int getSpeciesListPrefix(vector<string>&);
	map<string,Species*>& getAllSpecies();
	Species* getSpecies(string&);
	Matrix* getConditional(string& spName);
	int resetTransitionProbability();
	int resetTransitionProbability(Species*);
	int normalizeTransitionMatrix();
	int normalizeTransitionMatrix(Species*);

	int initTransitionMatrix_ML();
	int initTransitionMatrix_ML(Species*);
	Matrix* getTransitionMatrix_ML(string& name);
	int normalizeTransitionMatrix_ML();
	int normalizeTransitionMatrix_ML(Species*);
	
	int assignExtantClustering(map<string,int>& ancestralClusterAssign,Species* node, map<string,int>& extantClusterAssign);
	double getSubTree(int,Species*,map<string,int>&);
	double maxSubTree(int parentCluster, Species* child, map<string,int>& extantCluster,map<string,int>& ancestralCluster);
	//int enumerateChild(Species*,map<string,int>&,map<string,int>&,vector<map<string,int>*>&);
	int getMaxClusterAssignForChild(int parentClustID,Species* child);
	int showConditionals(const char*,SpeciesDistManager::Species* species);
	int showConditionals_ML(const char*,SpeciesDistManager::Species* species);
	//Should be called on a per datapoint level, where a datapoint represents the joint assignment of all
	//variables. The input parameter, dataPtProb is the probability density of the data point from the
	//ith cluster, where i is the key of the map.
	//The output parameter is the normalization constant for each node.
	//int estimateNormalizationConstants(map<string,map<int,double>*>& dataPtProb, map<string,double>& normConstants);
	//int estimateNormalizationConstant_Node(map<string,map<int,double>*>& dataPtProb, map<string,double>& normConstants,Species*,int ancestralClustID);
	private:
	int getSpeciesListPrefix(Species*,vector<string>&);
	map<string,Species*> speciesSet;
	Species* root;
	int maxClusterCnt;
	map<string,int> levelFromRoot;
};
#endif
