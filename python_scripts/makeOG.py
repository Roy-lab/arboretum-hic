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

def readWrite(inname,outname):
	fi = open(inname,'r')
	fo = open(outname,'w')
	fo.write('1OG\n')
	cnt = 0
	for l in fi:
		cnt += 1
		parts = l.strip().split('\t')
		fo.write('OG%d_1\thESC_%s,hIMR90_%s,mESC_%s,mCortex_%s\n' % (cnt,parts[0],parts[0],parts[1],parts[1]))
	fo.close()
	fi.close()

if __name__ == '__main__':
	readWrite(sys.argv[1],sys.argv[2])
