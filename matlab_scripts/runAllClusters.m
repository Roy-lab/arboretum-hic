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

function runAllClusters()

methods={'spec_spear','spec_crr','spec_cnt','spec_lcnt','spec_euc','hier_crr','hier_spear','hier_euc','hier_cnt','hier_lcnt','kmeans_crr','kmeans_spear','kmeans_euc','kmeans_cnt','kmeans_lcnt'};
fnames={'getSpearmanLap','getPearsonLap','getCntLap','getLCntLap','getEucLap','doHierC','doHierS','doHierE','doHierCnt','doHierLCnt','doKmeansC','doKmeansS','doKmeansE','doKmeansCnt','doKmeansLCnt'};

load('../data/hESC.mat');

for m=1:5
		fprintf('%s\n',methods{m});
		fun = str2func(sprintf('%s', fnames{m}));
		nmat = mat;
		L = fun(nmat);
		clusterL(L,sprintf('../clusters/%s',methods{m}));
	end
	for m=6:length(fnames)
		fprintf('%s\n',methods{m});
		nmat=mat;
		fun = str2func(sprintf('%s', fnames{m}));
		fun(nmat,sprintf('../clusters/%s',methods{m}));
	end


function doKmeansCnt(mat,outname)
for k=10
	cids=tanayKmeans(mat,k);
	saveClust(sprintf('%s.%d.txt',outname,k),cids);
end

function doKmeansLCnt(mat,outname)
for k=10
	cids=tanayKmeans(log2(1+mat),k);
	saveClust(sprintf('%s.%d.txt',outname,k),cids);
end

function doKmeansE(mat,outname)
for k=10
	cids = kmeans(log2(1+mat),k,'replicates',100);
	saveClust(sprintf('%s.%d.txt',outname,k),cids);
end

function doKmeansS(mat,outname)
for k=10
	cids = do1KmeansS(mat,k);
	saveClust(sprintf('%s.%d.txt',outname,k),cids);
end

function ccids = do1KmeansS(mat, k)
finalscore=inf;
for replicate=1:10
	centers = mat(:,randperm(size(mat,1),k));
	oldd=inf;
	while 1
		oldcenters=centers;
		dist = corr(mat,centers,'type','spearman');
		[~,ids] = max(dist,[],2);
		cids = ids;
		u=unique(ids);
		for j=1:length(u)
			i=u(j);
			centers(:,i) = mean(mat(:,ids==i),2);
		end
		d=0;
		for i=1:k
			d = d+pdist2(centers(:,i)',oldcenters(:,i)','euclidean');
		end
		if abs(oldd-d)<0.01
			break;
		end
		oldd=d;
	end
	if d<finalscore
		finalscore=d;
		ccids=cids;
	end
end

function doKmeansC(mat,outname)
for k=10
	cids = kmeans(log2(1+mat),k,'distance','correlation','replicates',100);
	saveClust(sprintf('%s.%d.txt',outname,k),cids);
end

function doHierC(mat,outname)
mdist=pdist(log2(1+mat),'correlation');
mtree=linkage(mdist,'average');
for k=10
	cids = cluster(mtree,'maxclust',k);
	saveClust(sprintf('%s.%d.txt',outname,k),cids);
end

function doHierE(mat,outname)
mdist=pdist(log2(1+mat),'euclidean');
mtree=linkage(mdist,'average');
for k=10
	cids = cluster(mtree,'maxclust',k);
	saveClust(sprintf('%s.%d.txt',outname,k),cids);
end

function doHierS(mat,outname)
mdist=pdist(mat,'spearman');
mtree=linkage(mdist,'average');
for k=10
	cids = cluster(mtree,'maxclust',k);
	saveClust(sprintf('%s.%d.txt',outname,k),cids);
end

function doHierCnt(mat,outname)
nmat=mat;
for i=1:size(mat,1)
	nmat(i,i)=0;
end
mdist=squareform(nmat);
mdist=max(mdist)-mdist;
mtree=linkage(mdist,'average');
for k=10
	cids = cluster(mtree,'maxclust',k);
	saveClust(sprintf('%s.%d.txt',outname,k),cids);
end

function doHierLCnt(mat,outname)
nmat=mat;
for i=1:size(mat,1)
	nmat(i,i)=0;
end
nmat=log2(1+nmat);
mdist=squareform(nmat);
mdist=max(mdist)-mdist;
mtree=linkage(mdist,'average');
for k=10
	cids = cluster(mtree,'maxclust',k);
	saveClust(sprintf('%s.%d.txt',outname,k),cids);
end

function L = getPearsonLap(mat)
c=corr(mat,'type','pearson');
c(c<0)=0;
for i=1:size(c,1)
	c(i,i)=0;
end
L = getLap(c);

function L = getSpearmanLap(mat)
c=corr(mat,'type','spearman');
c(c<0)=0;
for i=1:size(c,1)
	c(i,i)=0;
end
L = getLap(c);

function L = getCntLap(mat)
nmat = mat;
for i=1:size(nmat,1)
	nmat(i,i)=0;
end
L = getLap(nmat);

function L = getLCntLap(mat)
nmat = mat;
for i=1:size(nmat,1)
	nmat(i,i)=0;
end
nmat = log2(1+nmat);
L = getLap(nmat);

function L = getEucLap(mat)
dd = pdist(mat,'euclidean');
d  = squareform(dd);
d  = max(dd)-d;
for i=1:size(d,1)
	d(i,i)=0;
end
L = getLap(d);

function L = getLap(mat)
dd=sum(mat);
%dd(dd==0)=1;
D=diag(dd.^-.5);
L=D*mat*D;

function clusterL(L,outname)
[V,D] = eigs(L,10);
[~,idx] = sort(abs(diag(D)),'descend');

for k=10
	EV = V(:,idx(1:k));
	try
		cidx = kmeans(EV,k,'replicates',10);
		cidx = cidx';
	catch err
		cidx = zeros(1,size(EV,1));
		disp('ERROR in kmeans!')
	end
	cids=cidx;
	saveClust(sprintf('%s.%d.txt',outname,k),cids);
end

function saveClust(outname,cids)
fid = fopen(outname,'w');
for i=1:length(cids)
    fprintf(fid,'c%d\t%d\n',i,cids(i));
end
fclose(fid);

