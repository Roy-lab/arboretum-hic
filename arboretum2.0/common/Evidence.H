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

#ifndef _EVIDENCE
#define _EVIDENCE
//This is the evidence for a particular variable
//This can take the place of the likelihood

#include <fstream>
using namespace std;
#include "CommonTypes.H"

class Evidence
{
	public:
		Evidence();
		~Evidence();
		typedef enum
		{
			HARD,
			SOFT
		}EvidenceType;

		int assocVariable(int);
		int getAssocVariable();
		int setData(INTDBLMAP&);
		int addToData(int,double);
		INTDBLMAP& getData();
		int setType(EvidenceType);
		EvidenceType getType();
		int dumpEvidence(ostream&);
		int makeHidden();
		bool isHidden();
		//Get the value which is the most likely, i.e., the one with the max
		//value in the evidData
		int getMLVal();
		//This will prevent the loop over the values of the associated variable
		//in case of hard evidence
		int getHardEvidVal();
		int setEvidVal(double);
		double getEvidVal();
	private:
		INTDBLMAP evidData;
		int varID;
		EvidenceType eType;
		bool hiddenFlag;
		//Store the value of the hard evidence
		int hardValue;
		double contValue;
};

#endif
