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

#include <vector>
#include <map>
#include <string>
using namespace std;

typedef vector<int> INTVECT;
typedef vector<string> STRVECT;
typedef vector<double> DBLVECT;

typedef map<string,int> STRINTMAP;
typedef map<string,int>::iterator STRINTMAP_ITER;

typedef map<int,double> INTDBLMAP;
typedef map<int,double>::iterator INTDBLMAP_ITER;

typedef map<string,double> STRDBLMAP;
typedef map<string,double>::iterator STRDBLMAP_ITER;

typedef map<int,double> INTDBLMAP;
typedef map<int,double>::iterator INTDBLMAP_ITER;

typedef map<int,int> INTINTMAP;
typedef map<int,int>::iterator INTINTMAP_ITER;
#define CONSTR_LEN 256
