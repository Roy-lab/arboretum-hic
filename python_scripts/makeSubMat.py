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

def readInt(inname):
	rmap = {}
	f = open(inname,'r')
	for l in f:
		parts = l.strip().split('\t')
		r1 = '%s_%s' % (parts[0],parts[1])
		r2 = '%s_%s' % (parts[2],parts[3])
		rmap[(r1,r2)] = float(parts[4])
		rmap[(r2,r1)] = float(parts[4])
	f.close()
	return rmap

def writeMat(outname,regs,rmap):
	f = open(outname,'w')
	for i in range(len(regs)):
		f.write('\t'.join(['%f' % rmap.get((regs[i],regs[j]),0) for j in range(len(regs))])+'\n')
	f.close()

if __name__ == '__main__':
	regs = readRegs(sys.argv[1],int(sys.argv[2]))
	rmap = readInt(sys.argv[3])
	writeMat(sys.argv[4],regs,rmap)
