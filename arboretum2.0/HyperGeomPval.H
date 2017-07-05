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

#ifndef _HYPERGEOM_PVAL
#define _HYPERGEOM_PVAL
class HyperGeomPval
{
	public:
		HyperGeomPval();
		~HyperGeomPval();
		//Here we ask, what is the probability of getting k out x elements
		//to belong to category A, given there n1 elements in category A
		//and n2 elements is category B.
		double getOverRepPval(int x, int k, int n1, int n2);
		double getUnderRepPval(int x, int k, int n1, int n2);
	
};

#endif
