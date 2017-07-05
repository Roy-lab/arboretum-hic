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

#ifndef _EXPERTL_
#define _EXPERTL_
#include <vector>
using namespace std;
#include "CommonTypes.H"
#define PI 3.1472
class Matrix;
class ExpertL
{
	public:
		ExpertL();
		~ExpertL();
		int setMean(Matrix*);
		int setCovariance(Matrix*);
		int setFeatureWeight(int,double);
		double getOutputPDF(Matrix* y);
		double getOutputPDF_Fast(Matrix* y);
		double getOutputPDF_Nocov(Matrix* y);
		double getMixtureWeight(INTDBLMAP* x);
		Matrix* getMean();
		Matrix* getCovariance();
		int updateCovariance();
		INTDBLMAP& getFeatureWeights();
		int sortFeatures();
		int sortFeatures_Enrichment(INTDBLMAP&);
		vector<int>& getSortedFeatures();
		int assignGeneToExpert(int);
		map<int,int>& getGeneSet();
		int resetAssignedGenes();
		double getEntropy();
		int setPrior(double);
		double getPrior();
	private:
		 Matrix* covariance;
		 Matrix* invCovariance;
		 Matrix* mean;
		 double normFactor;
		 INTDBLMAP featureWeights;
		 vector<int> sortedFeatureIDs;
		 map<int,int> geneSet;
		double prior;
};
#endif

