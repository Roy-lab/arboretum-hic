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

def readData(inname):
	f = open(inname,'r')
	names = []
	data  = []
	for l in f:
		parts = l.strip().split('\t')
		names.append(parts[0])
		data.append(parts[1:])
	f.close()
	return (names,data)

def writeData(outname,regs,names,data,pf):
	f = open(outname,'w')
	for i in range(len(regs)):
		f.write('%s_%s\t%s\n' % (pf,regs[i],'\t'.join(data[i])))
	f.close()

if __name__ == '__main__':
	regs = readRegs(sys.argv[1],int(sys.argv[2]))
	(names,data) = readData(sys.argv[3])
	writeData(sys.argv[4],regs,names,data,sys.argv[5])
