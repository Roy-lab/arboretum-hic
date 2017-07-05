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

/*The goal of this class is to interface the factor graph classes with the kmeans or other
 * clustering programs. This class first checks if there any existing clusters generated
 * via non-negative matrix factorizations or previous run of kmeans. If not it gets
 * data from the evidence manager and then uses kmeans to generate the clusters*/

#include <vector>
using namespace std;

class VariableManager;
class EvidenceManager;
class Kmeans;

class ClusterManager
{
	public:
	ClusterManager();
	~ClusterManager();
	int setVariableManager(VariableManager* aPtr);
	int setEvidenceManager(EvidenceManager* aPtr);
	int setOutputDir(const char*);
	int setClusterCnt(int);
	int setMaxIter(int);
	vector<VSET*>& getClusters();
	vector<INTINTMAP*>& getClusters(map<int,INTDBLMAP*>& kmeansData);
	vector<VSET*>& getRandomClusters();
	private:
	int readClusters();
	int generateClusters();
	int generateClusters_Randomrestarts();
	int generateClusters_Randomrestarts(map<int,INTDBLMAP*>&);
	int maxIter;
	Kmeans kmeans;
	int clusterCnt;
	char outputDir[1024];
	VariableManager* vMgr;
	EvidenceManager* evidMgr;
	vector<VSET*> variableSubsets;
	vector<INTINTMAP*> variableSubsets_IDs;
	vector<VSET*> randomVariableSubsets;
};



