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

#ifndef _BFGS_WRAPPER_
#define _BFGS_WRAPPER_

#include <string>
#include <map>
using namespace std;
#include "gsl/gsl_multimin.h"

#define MAXCOMP 40


class BFGSWrapper
{
	public:
		BFGSWrapper();
		~BFGSWrapper();
		int setParamCnt(int aCnt);
		int setFeatureCnt(int aCnt);
		int setStepSize(double);
		int setTolerance(double);
		gsl_vector* getInitVector();
		int setInitVector(gsl_vector*);
		//Somebody populate the data and gammas
		map<int,map<int,double>*>& getData();
		map<int,map<int,double>*>& getGammas();
		int initializeMinimizer();
		int reinitializeMinimizer();
		int optimize();
		gsl_vector* getParams();
		double getOptimalFval();
		int reset();
	private:
		gsl_vector* getStartingPoint();
		int paramCnt;
		int featureCnt;
		double stepSize;
		double tolerance;
		gsl_vector* initx;
		map<int,map<int,double>*> gammas;
		map<int,map<int,double>*> data;
		double optimalFval;
		BFGSWrapperData bwdata;
		gsl_multimin_fdfminimizer* optimizer;
		gsl_multimin_function_fdf* optimizer_func;
		double lambda;
};
#endif

extern double likelihood_function(const gsl_vector* x, void* params);
extern void likelihood_gradient(const gsl_vector* v, void* params,gsl_vector* df);
extern void likelihood_function_gradient(const gsl_vector* x, void* params, double* f, gsl_vector* g);
