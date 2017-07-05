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
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include "TestData.H"

TestData::TestData()
{
}

TestData::~TestData()
{
}

int 
TestData::readData(const char* aFName)
{
	ifstream inFile(aFName);
	char* buffer=NULL;
	int bufflen=0;
	string buffstr;
	while(inFile.good())
	{
		getline(inFile,buffstr);
		if(buffstr.length()<=0)
		{
			continue;
		}
		if(bufflen<=buffstr.length())
		{
			bufflen=buffstr.length()+1;
			if(buffer!=NULL)
			{
				delete [] buffer;
			}
			buffer=new char[bufflen];
		}
		strcpy(buffer,buffstr.c_str());
		char* tok=strtok(buffer,"\t");
		int tokCnt=0;
		string geneName;
		map<string,int>* featureSet=NULL;
		while(tok!=NULL)
		{
			if(tokCnt==0)
			{
				geneName.append(tok);	
				featureSet=new map<string,int>;
				dataSet[geneName]=featureSet;
			}
			else
			{
				char* pos=strchr(tok,':');
				if(pos==NULL)
				{
					cout << "Bad format" << endl;
					exit(0);
				}	
				*pos='\0';
				string motifName(tok);
				int occurence=atoi(pos+1);
				(*featureSet)[motifName]=occurence;
			}
			tok=strtok(NULL,"\t");
			tokCnt++;
		}
	}
	cout <<"Read " << dataSet.size() << " genes" << endl;
	inFile.close();
	return 0;
}

int 
TestData::getSize()
{
	return dataSet.size();
}

map<string,map<string,int>*>& 
TestData::getDataSet()
{
	return dataSet;
}
