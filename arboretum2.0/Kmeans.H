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

/*This class implements the functionality of the K means clustering in 1d.
 * The user of this class provides a 1d data and gets back k clusters of the
 * data*/
#include <vector>
#include <map>

#include "CommonTypes.H"

using namespace std;

typedef map<int,INTDBLMAP*> KMEANS_SP_DATA;
typedef map<int,INTDBLMAP*>::iterator KMEANS_SP_DATA_ITER;


typedef vector<int> MEMBER;
typedef map<int,MEMBER*> CLUSTERS;
typedef map<int,MEMBER*>::iterator CLUSTERS_ITER;



class Kmeans
{
	public:
		Kmeans();
		~Kmeans();
		int setConvergenceThreshold(double);
		int setClusterCnt(int);
		int setMaxDim(int);
	
		typedef enum
		{
			EUCLID,
			MI
		}DistanceType;
		int setDistanceType(DistanceType);
		int cluster(KMEANS_SP_DATA*);
		int showClusters(const char*);
		CLUSTERS& getClusters();
		//This is the sum of all within cluster simillarity
		double getWithinClusterDist();
		double getAcrossClusterDist();
		double computeWithinDistance();
		double computeAcrossDistance();
		int clear();
		int setMaxIter(int);
	private:
		int setInitialCenters();
		int setInitialCenters_DataPts();
		int formClusters();
		int resetCenters();
	
		int showCenters();
		
		double getPairwiseDist(DBLVECT*,DBLVECT*);
		double getPairwiseDist(INTDBLMAP*,INTDBLMAP*);
		double getPairwiseDist_Euclid(INTDBLMAP*, INTDBLMAP*);
		double getPairwiseDist_CC(INTDBLMAP*, INTDBLMAP*);
		double getPairwiseDist_MI(INTDBLMAP*, INTDBLMAP*);
	
		
		int clusterCnt;
		double threshold;
		double withinDist;
		double acrossDist;
		int maxDim;
		int maxIter;
			
		KMEANS_SP_DATA centers;
		CLUSTERS clusters;
		KMEANS_SP_DATA* dataSet;
		DistanceType dtype;
};
