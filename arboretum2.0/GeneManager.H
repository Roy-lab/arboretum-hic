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

#ifndef _GENE_MANAGER
#define _GENE_MANAGER
#include <vector>
#include <map>
#include <string>
using namespace std;
class Gene;

typedef vector<Gene*> GENESET;
typedef map<string,Gene*> GENEMAP;
typedef map<string,Gene*>::iterator GENEMAP_ITER;

class GeneManager
{
	public:
		GeneManager();
		~GeneManager();
		int readGeneData(const char*, int logtrans=0);
		int readGeneData(const char*, int datastart, int logtrans=0);
		//The parameter is a single line of the protein expression file
		int addGeneNode(const char*,int logtrans=0);
		Gene* getGeneNode(int id);
		Gene* getGeneWithName(const char*);
		int getTotalNumberOfGenes();
		int discretizeGeneExpr();
		int rankOrderGeneExpr();
		int scaleGeneExpr();
		int standardizeGeneExpr();
		int zeroMeanGeneExpr();

		int assocProtWithCodingGene(const char*, int);
	private:
		GENESET geneSet;
		GENEMAP geneMap;
		int geneIds;
		int totalMeasurements;
		double maxExp;
		double minExp;
};
#endif
