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

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
#include "Path.H"
#include "Protein.H"
#include "GeneManager.H"
#include "ProteinManager.H"


ProteinManager::ProteinManager()
{
	proteinIds=0;
}

ProteinManager::~ProteinManager()
{
}


int 
ProteinManager::setGeneMgr(GeneManager* mPtr)
{
	geneMgr=mPtr;
	return 0;
}

int 
ProteinManager::readProteinData(const char* inFName)
{
	ifstream inFile(inFName);
	char buffer[EXPRFILE_LEN];
	while(inFile.good())
	{
		inFile.getline(buffer,EXPRFILE_LEN-1);
		if(strlen(buffer)<=0)
		{
			continue;
		}
		addProteinNode(buffer);
	}
	inFile.close();
	return 0;
}

//The parameter is a single line of the protein expression file
int 
ProteinManager::addProteinNode(const char* protData)
{
	int len=strlen(protData)+1;
	char* buffer=new char[len];
	strcpy(buffer,protData);
	//The data is tab-delimited
	int tokCnt=0;
	char* tok=strtok(buffer,"\t");
	Protein* aProt=NULL;
	while(tok!=NULL)
	{
		if(tokCnt==0)
		{
			aProt=new Protein;
			aProt->setName(tok);
			aProt->setType(BioNode::PROTEIN);
			aProt->setID(proteinIds);
			if(geneMgr->assocProtWithCodingGene(tok,proteinIds)==-1)
			{
				return -1;
			}
			proteinSet.push_back(aProt);
			string pKey(tok);
			proteinMap[pKey]=aProt;
			proteinIds++;
		}
		else
		{
			double aVal=atof(tok);
			aProt->addExpLevel(aVal);
		}
		tokCnt++;
		tok=strtok(NULL,"\t");
	}

	return 0;
}

Protein* 
ProteinManager::getProteinNode(int id)
{
	if((id<0) || (id>=proteinSet.size()))
	{
	//	cout <<"Bad protein ID given to ProteinManager " << endl;
		return NULL;
	}
	return proteinSet[id];
}

Protein*
ProteinManager::getProteinWithName(const char* aName)
{
	string aKey(aName);
	if(proteinMap.find(aKey)==proteinMap.end())
	{
		return NULL;
	}
	return proteinMap[aKey];
}

int 
ProteinManager::getTotalNumberOfProteins()
{
	return proteinSet.size();
}

int
ProteinManager::discretizeProteinExpr()
{
	for(int i=0;i<proteinSet.size();i++)
	{
		proteinSet[i]->discretizeLevels();
	}
	return 0;
}


int
ProteinManager::rankOrderProteinExpr()
{
	for(int i=0;i<proteinSet.size();i++)
	{
		//proteinSet[i]->rankOrder();
		proteinSet[i]->rankOrder_Store();
	}
	return 0;
}

int
ProteinManager::scaleProteinExpr()
{
	for(int i=0;i<proteinSet.size();i++)
	{
		proteinSet[i]->scaleExpression();
	}
	return 0;
}

int
ProteinManager::standardizeProteinExpr()
{
	for(int i=0;i<proteinSet.size();i++)
	{
		proteinSet[i]->standardizeData();
	}
	return 0;
}


