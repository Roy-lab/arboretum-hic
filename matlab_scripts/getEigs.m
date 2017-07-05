%
%    This file is part of Arboretum-Hi-C.
%    
%    Copyright (C) 2016 Sushmita Roy's Lab sroy@biostat.wisc.edu
%
%    This program is free software: you can redistribute it and/or modify
%    it under the terms of the GNU General Public License as published by
%    the Free Software Foundation, either version 3 of the License, or
%    (at your option) any later version.
%
%    This program is distributed in the hope that it will be useful,
%    but WITHOUT ANY WARRANTY; without even the implied warranty of
%    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%    GNU General Public License for more details.
%
%    You should have received a copy of the GNU General Public License
%    along with this program.  If not, see <http://www.gnu.org/licenses/>.
%

function getEigs()

cellines={'hESC','hIMR90','mESC','mCortex'};

for i=1:length(cellines)
	mat = importdata(sprintf('../data/sub_mats/%s.txt',cellines{i}));
	L = getSpearmanLap(mat);
	clusterL(L,sprintf('../data/arboretum_ins/eigs_oldname/%s',cellines{i}));
end

function L = getSpearmanLap(mat)
c=corr(mat,'type','spearman');
c(c<0)=0;
for i=1:size(c,1)
	c(i,i)=0;
end
c(isnan(c))=0;
L = getLap(c);

function L = getLap(mat)
nmat=mat;
nmat(isnan(nmat))=0;
dd=sum(mat);
if sum(dd==0)>0
	fprintf('%d\n',sum(dd==0));
	find(dd==0)
end
nmat=nmat(dd~=0,dd~=0);
dd=dd(dd~=0);
D=diag(dd.^-.5);
L=D*nmat*D;

function clusterL(L,outname)
[V,D] = eigs(L,10);
[~,idx] = sort(abs(diag(D)),'descend');

for k=10:10
	EV = V(:,idx(1:k));
	try
		cidx = kmeans(EV,k,'replicates',10);
		cidx = cidx';
	catch err
		cidx = zeros(1,size(EV,1));
		disp('ERROR in kmeans!')
	end
	cids=cidx;
	saveClust(sprintf('%s.%d.kmns',outname,k),cids);
	saveEig(sprintf('%s.%d.eigs.txt',outname,k),EV);
end

function saveClust(outname,cids)
fid = fopen(outname,'w');
for i=1:length(cids)
    fprintf(fid,'c%d\t%d\n',i,cids(i));
end
fclose(fid);

function saveEig(outname,V)
fid = fopen(outname,'w');
for i=1:size(V,1)
    fprintf(fid,'c%d',i);
	for j=1:size(V,2)
    	fprintf(fid,'\t%f',V(i,j));
	end
	fprintf(fid,'\n');
end
fclose(fid);
