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
#include <string.h>

#include "Interaction.H"
#include "InteractionManager.H"

InteractionManager::InteractionManager()
{
}

InteractionManager::~InteractionManager()
{
}

int
InteractionManager::setDirectionality(bool dirFlag)
{
	directionality=dirFlag;
	return 0;
}

int
InteractionManager::setDelimiter(const char* aDel)
{
	strcpy(delim,aDel);
	return 0;
}

int
InteractionManager::readInteractions(const char* fileName)
{
	ifstream inFile(fileName);
	char buffer[1024];
	int totalIntr=0;
	while(inFile.good())
	{
		inFile.getline(buffer,1023);
		if(strlen(buffer)<=0)
		{
			continue;
		}
		int tokCnt=0;
		char* tok=strtok(buffer,delim);
		char firstGene[GENENAME_LEN];
		char secondGene[GENENAME_LEN];
		string actiontype;
		while(tok!=NULL)
		{
			switch(tokCnt)
			{
				case 0:
				{
					strcpy(firstGene,tok);
					break;
				}
				case 1:
				{
					actiontype.append(tok);
					break;
				}
				case 2:
				{
					strcpy(secondGene,tok);
					break;
				}
			}
			tok=strtok(NULL,delim);
			tokCnt++;
		}
		string aKey;
		createKey(firstGene,secondGene,aKey);
		totalIntr++;
		if(interactionSet.find(aKey)==interactionSet.end())
		{
			Interaction* intr=new Interaction;
			intr->setMembers(firstGene,secondGene);
			intr->setProperty("actiontype",actiontype.c_str());
			interactionSet[aKey]=intr;
			intrIDtoString[interactionSet.size()-1]=aKey;
		}
	}
	inFile.close();

	cout << "Added " << interactionSet.size() << " out of a total " << totalIntr <<  " interactions"<< endl;
	return 0;
}

INTR_MAP&
InteractionManager::getInteractions()
{
	return interactionSet;
}

bool
InteractionManager::isInteraction(const char* firstOrf, const char* secondOrf)
{
	string aKey;
	createKey(firstOrf,secondOrf,aKey);
	if(interactionSet.find(aKey)==interactionSet.end())
	{
		return false;
	}
	return true;
}

int
InteractionManager::addInteraction(const char* firstOrf, const char* secondOrf)
{
	string aKey;
	createKey(firstOrf,secondOrf,aKey);
	if(interactionSet.find(aKey)==interactionSet.end())
	{
		Interaction* intr=new Interaction;
		intr->setMembers(firstOrf,secondOrf);
		interactionSet[aKey]=intr;
	}
	return 0;
}


int
InteractionManager::getNumberOfIntr()
{
	return interactionSet.size();
}

Interaction*
InteractionManager::getInteractionAt(int intrId)
{
	map<int,string>::iterator aIter=intrIDtoString.find(intrId);
	if(aIter==intrIDtoString.end())
	{
		return NULL;
	}
	return interactionSet[aIter->second];
}

int
InteractionManager::dumpInteractions(const char* ofName)
{
	ofstream oFile(ofName);
	for(INTR_MAP_ITER imIter=interactionSet.begin();imIter!=interactionSet.end();imIter++)
	{
		oFile <<imIter->first.c_str() <<  endl;
	}
	oFile.close();
	return 0;
}

int
InteractionManager::createKey(const char* firstGene, const char* secondGene, string& aKey)
{
	char keyChar[1024];
	if(directionality)
	{
		/*int len1=strlen(firstGene);
		int len2=strlen(secondGene);
		int compLen=len1;
		if(len2<len1)
		{
			compLen=len2;
		}
		int i=0;
		int smallId=0;
		while((i<compLen) && (smallId==0))
		{
			if(firstGene[i]<secondGene[i])
			{
				smallId=1;
			}
			else if(firstGene[i]>secondGene[i])
			{
				smallId=2;
			}
			i++;
		}
		if(smallId==1)
		{
			sprintf(keyChar,"%s-%s",firstGene,secondGene);
		}
		else if(smallId==2)
		{
			sprintf(keyChar,"%s-%s",secondGene,firstGene);
		}
		else
		{
			//cout << "First and second genes are the same " << firstGene << endl;
			sprintf(keyChar,"%s-%s",secondGene,firstGene);
		}*/
		if(strcmp(firstGene,secondGene)<=0)
		{
			sprintf(keyChar,"%s-%s",firstGene,secondGene);
		}
		else
		{
			sprintf(keyChar,"%s-%s",secondGene,firstGene);
		}
	}
	else
	{
		sprintf(keyChar,"%s-%s",firstGene,secondGene);
	}
	aKey.append(keyChar);
	
	return 0;
}


