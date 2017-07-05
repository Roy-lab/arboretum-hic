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
%
%    This script was written based on the clustering method described in:
%    Eitan Yaffe and Amos Tanay
%    Probabilistic modeling of Hi-C contact maps eliminates systematic biases to characterize global chromosomal architecture. 
%    Nature genetics, 43(11):1059–1065, November 2011.
%
%

function cids = tanayKmeans(mat,k)
onemaxitr = 50;
maxitr = 100;
bests  = 0;
for itr=1:maxitr
	disp(itr)
	[newids,s] = getKmeans(mat,k,onemaxitr);
    %disp([itr,s,bests]);
	if s > bests
		%disp([s,bests])
		cids  = newids;
		bests = s;
	end
end

function cids = initClusters(mat,k)
n = size(mat,1);
rcenters = randperm(n,k);
[~,cids] = max(mat(:,rcenters),[],2);
cids(rcenters) = 1:k;

function [bestids,bests] = getKmeans(mat, k, maxitr)
curids = initClusters(mat,k);
%maxitr = 100;
bestids= curids;
bests  = 0;
%done   = 0;
%cnt    = 0
%while ~done
for itr=1:maxitr
    [newids,s] = updateClust(mat, k, curids);
	if s > bests
		bests = s;
		bestids = newids;
	end
	curids = newids;
	%cnt = cnt + 1;
end

function [newids,s] = updateClust(mat, k, curids)
n = size(mat,1);
svals = zeros(n,k);
cvals = zeros(n,k);
mvals = zeros(n,k);
for i=1:k
	svals(:,i) = sum(mat(:,curids==i),2);
	cvals(:,i) = sum(mat(:,curids==i)~=0,2);
end
mvals = svals./cvals;
mvals(isnan(mvals)) = 0;
mvals(isinf(mvals)) = 0;
[newdists,newids] = max(mvals,[],2);
s=mean(newdists);

