#
#    This file is part of Arboretum-Hi-C.
#    
#    Copyright (C) 2016 Sushmita Roy's Lab sroy@biostat.wisc.edu
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

import sys

def readRegs(inname,id):
	regs = []
	f = open(inname,'r')
	for l in f:
		parts = l.strip().split('\t')
		regs.append(parts[id])
	f.close()
	return regs

def readClusters(inname):
	clust = {}
	f = open(inname,'r')
	for l in f:
		parts = l.strip().split('\t')
		clust[parts[0]] = parts[1:]
	f.close()
	return clust

def writeClust(outname,clust,regs,prfx):
	f = open(outname,'w')
	for r in regs:
		k = '%s_%s' % (prfx,r)
		f.write('%s\t%s\n' % (k,'\t'.join(clust[k])))
	f.close()

if __name__ == '__main__':
	regs = readRegs(sys.argv[1],int(sys.argv[4]))
	clust = readClusters(sys.argv[2])
	writeClust(sys.argv[3],clust,regs,sys.argv[5])
