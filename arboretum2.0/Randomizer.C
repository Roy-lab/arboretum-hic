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

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/timeb.h>
#include <time.h>

#include "Randomizer.H"

Randomizer::Randomizer()
{
}

Randomizer::~Randomizer()
{
}

void
Randomizer::initialize(int anUpper, int aLower)
{
	upperBound=anUpper;
	lowerBound=aLower;
	ftime(&atime);
	int pid=getpid();
	 
	srand((unsigned int) atime.millitm);
	//srand(pid);
}

int
Randomizer::getRandomNumber()
{
	int randomNumCnt=upperBound-lowerBound;
//	sleep(1);
	int randNum=rand();
	int randIndex=randNum%(randomNumCnt-1);
	return randIndex;
	
}

#ifdef TEST

int main()
{
	Randomizer randomize;
	randomize.initialize(0,6000);
	for(int i=0;i <100; i++)
	{
		int no=randomize.getRandomNumber();
		cout << no  << endl;	
	}
	return 0;
}
#endif
