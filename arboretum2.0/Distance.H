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

#ifndef _DISTANCE
#define _DISTANCE

#include<vector>

using namespace std;

class Distance
{
	public:
	Distance();
	~Distance();
	double computeSymmKLDivergence(double m1, double v1, double m2, double v2);
	double computeKLDivergence(double m1, double v1, double m2, double v2);
	double computeZstat(double m1,double v1,double m2, double v2,int sampleCnt);
	double computeCC(vector<double>& v1, vector<double>& v2);
	
	
};
#endif
