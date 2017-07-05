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

#ifndef _GAMMA_MGR
#define _GAMMA_MGR
#include <map>
#include <string>
using namespace std;

class SpeciesDistManager;
class Gamma;
class GeneTreeManager;
class MappedOrthogroupReader;

class GammaManager
{
	public:
	GammaManager();
	~GammaManager();
	int setMaxClusterCnt(int k);
	int setOrthogroupReader(MappedOrthogroupReader* aPtr);
	int setSpeciesDistManager(SpeciesDistManager* aPtr);
	SpeciesDistManager* getSpeciesDistManager();
	int initGamma(int ogid, string& geneName, string& specName,int clustID);
	int estimateLeafGamma(int,map<int,double>&,string& geneName, string& specName);
	int estimateLeafAlpha(int,map<int,double>&,string& geneName, string& specName);
	int estimateNonLeafPosterior();
	double getNonLeafScore();
	Matrix* getGamma(int ogid,string& geneName, string& specName);
	Matrix* getNormTerm(int ogid,string& geneName, string& specName);
	double getPrior(string&,int,int);
	double getAllNodeScore();
	map<int,double>* getLeafLikelihood_store(int ogid,string& geneName);
	double getNodeScore(Gamma::Node*);
	int estimateNonLeafPosterior(Gamma::Node* node);
	int estimateNonLeafPosteriorAlpha(Gamma::Node*);
	int estimateNonLeafPosteriorBeta(Gamma::Node*);
	int estimateNonLeafPosteriorGamma(Gamma::Node*,double&);
	int getAllClusterAssignments(map<int,map<string,int>*>& allClusterAssignments,bool);
	int getAllClusterAssignments_Grouped(map<int,map<string,int>*>& allClusterAssignments);
	int getAllClusterAssignments_Conditional(map<int,map<string,int>*>& allClusterAssignments);
	int revisitLeafAssignments(Gamma::Node* anode, map<string,int>& clusterAssignment_prior, map<string,int>* clusterAssignment_posterior);
	int getAllClusterGammas(map<int,map<string,map<int,double>*>*>& allClusterGammas);
	int getMaximalAssignment(Gamma::Node* anode,map<string,int>* assignment);
	int getMaximalAssignment_Grouped(Gamma::Node* anode,map<string,int>* assignment,int dupID);
	int showAssignments(const char*);
	int showMaximalAssignment_Grouped(Gamma::Node* anode,string& assignment,int assign,int dupID,int&,int&);

	//This remains 1 until we reach a duplication node which is 2
	int getMaximalAssignment(Gamma::Node* anode,map<string,int>* assignment,int dupID);
	int getMaximalConditionalAssignment(Gamma::Node* anode,map<string,int>* assignment,int dupID,int parentClusterID);
	int getClusterProb(Gamma::Node* anode,map<string,map<int,double>*>* prob);
	int estimateTransitionProbability();
	int reestimateTransitionProbability();
	int showClusterFlipCnts();
	const char* getDupAncestor(int);
	inline int getTotalUpdatedParentCnt()
	{
		return gtMgr.getTotalAdditionalParents();
	}
	int showTotalUpdatedParents();
	int sampleAllClusterAssignments(map<int,map<string,int>*>& allClusterAssignments);
	int showAllAlphas(Gamma::Node*);
	private:
	int updateTransitionMatrix(Gamma::Node*);
	int updateTransitionMatrix_ML(Gamma::Node*,int);
	int updateTransitionMatrix_GammaFix(Gamma::Node*);
	bool hasDuplicate(Gamma::Node*);
	int drawAssignment(Gamma::Node* anode, map<string,int>* assignment,int dupID,int parentID);
	int sampleAncestralCluster(gsl_rng* r,SpeciesDistManager::Species* root);
	int sampleChildCluster(gsl_rng* r,SpeciesDistManager::Species* child,int parentID);
	int sampleChildCluster(gsl_rng* r, int parentClusterId,Matrix* params,vector<int>* sortedClustIDs);
	int sortIndices(Matrix* params,int parentID,vector<int>* sortedClustIDs);
	int getLoss(Gamma::Node*);
	SpeciesDistManager* spdistMgr;
	//We will store one instance of Gamma for each OGid
	map<int,Gamma*> gammaSet;
	int maxClusterCnt;
	GeneTreeManager gtMgr;
	MappedOrthogroupReader* mgrpReader;
	bool showGammas;
	map<int,string> ogDupAncMap;
	map<string,Matrix*> clusterFlipCnt;
	gsl_rng* r;
	map<int,double> llStore;
};

#endif
