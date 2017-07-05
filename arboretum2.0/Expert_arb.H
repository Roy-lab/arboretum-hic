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

#ifndef _EXPERT_
#define _EXPERT_
#include <vector>
using namespace std;
#include "gsl/gsl_randist.h"
#include "CommonTypes.H"
#define PI 3.1472
class Matrix;
class Expert
{
	public:
		Expert();
		~Expert();
		int setMean(Matrix*);
		int setCovariance(Matrix*);
		double getOutputPDF(vector<double>* y);
		double getOutputPDF_Nocov(vector<double>* y);
		int setPrior(double);
		double getPrior();
		Matrix* getMean();
		Matrix* getCovariance();
		int updateCovariance();
		int assignGeneToExpert(const char*);
		map<string,int>& getGeneSet();
		int resetAssignedGenes();
		double getEntropy();
		int generateSample(gsl_rng* r, vector<double>&);
		int resetClip();
		int getClip();
		inline double getMinPDF()
		{
			return minpdf;
		}
	private:
		 Matrix* covariance;
		 Matrix* invCovariance;
		 Matrix* mean;
		 double normFactor;
		 map<string,int> geneSet;
		double priorProb;
		int clipCnt;
		double minpdf;
};
#endif

