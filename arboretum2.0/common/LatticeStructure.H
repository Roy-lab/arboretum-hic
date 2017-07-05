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

/*The goal of this class is to store the Lattice structure of the random variables.
 * This class stores two types of relationships: superset relationship, subset relationship
 * Although, one can derive one from the other, we will store these relationships
 * in a matrix like data structure. For the superset relation, each row corresponds
 * to a factor and the entries in the row are factor ids that are contained in the factor
 * corresponding to this row. 
 * In the subset relation, each row corresponds to a factor and each entry in the row corresponds
 * to the factor ids that contain the factor corresponding to the row.
 * The superset relation is used to make the Markov blankets consistent, also while finding maximal 
 * clustes. 
 * The subset relation is used to search for Markov blankets
 * */
#ifndef _LATTICE_STRUCTURE
#define _LATTICE_STRUCTURE
#include "CommonTypes.H"

typedef map<int,INTINTMAP*> MATRIX;
typedef map<int,INTINTMAP*>::iterator MATRIX_ITER;

class LatticeStructure
{
	public:
		LatticeStructure();
		~LatticeStructure();
		int addSubset(int,int);
		int addSuperset(int,int);
		INTINTMAP* getSubsets(int);
		INTINTMAP* getSupersets(int);

		int getSupersets(int,INTINTMAP&,int);
		int getSuperSets(int fId,INTINTMAP& supersets,int currlevel,int level);

		int getAllSubsets(int, INTINTMAP&);

		int deleteFromLattice(int);
	private:
		MATRIX mSubset;
		MATRIX mSuperset;
};
#endif
