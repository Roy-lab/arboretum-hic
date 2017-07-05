Independent clustering
----------------------
*Clustering data using different methods and metrics (in matlab_scripts)*
>`runAllClusters()`

---


Running Arboretum
-----------------

*Making orthology mapping for input of Arboretum*
>`python python_scripts/makeOG.py data/human2mouse_1M.txt data/arboretum_ins/human2mouse.txt`

*Extracting sub-matrices using orthology mapping*

>`for i in hESC hIMR90;`  
>`do`  
>`	python python_scripts/makeSubMat.py data/human2mouse_1M.txt 0 data/1M_interaction/$i.txt data/sub_mats/$i.txt;`  
>`done`  
>`for i in mESC mCortex;`  
>`do`  
>`	python python_scripts/makeSubMat.py data/human2mouse_1M.txt 1 data/1M_interaction/$i.txt data/sub_mats/$i.txt;`  
>`done`

*Making Eigenvectors using the Matlab script (in matlab_scripts)*
>`getEigs()`


*Changing the region names*
>`python python_scripts/convertNames.py data/human2mouse_1M.txt 0 data/arboretum_ins/eigs_oldname/hESC.10.eigs.txt data/arboretum_ins/hESC.eigs.txt hESC `
>`python python_scripts/convertNames.py data/human2mouse_1M.txt 0 data/arboretum_ins/eigs_oldname/hIMR90.10.eigs.txt data/arboretum_ins/hIMR90.eigs.txt hIMR90 `
>`python python_scripts/convertNames.py data/human2mouse_1M.txt 1 data/arboretum_ins/eigs_oldname/mESC.10.eigs.txt data/arboretum_ins/mESC.eigs.txt mESC `
>`python python_scripts/convertNames.py data/human2mouse_1M.txt 1 data/arboretum_ins/eigs_oldname/mCortex.10.eigs.txt data/arboretum_ins/mCortex.eigs.txt mCortex `

*Running Arboretum (from data/arboretum_ins/ directory)*
>`../../arboretum2.0/arboretum -s specorder.txt -e human2mouse.txt -k 10 -t tree1.txt -c config.txt -r none -o arboretum_outs/ -m learn -b hESC -i uniform -p 0.8 -1 true -2 true -w true`

*Reordering the output cluster assignments*
>`for h in hESC hIMR90;`  
>`do`  
>`	python python_scripts/sortCluster.py data/human2mouse_1M.txt data/arboretum_ins/arboretum_outs/"$h"_speciesspecnames_clusterassign.txt data/arboretum_ins/arboretum_outs/"$h"_sorted.txt 0 $h;`  
>`done`  
>`for h in mESC mCortex;`  
>`do`  
>`	python python_scripts/sortCluster.py data/human2mouse_1M.txt data/arboretum_ins/arboretum_outs/"$h"_speciesspecnames_clusterassign.txt data/arboretum_ins/arboretum_outs/"$h"_sorted.txt 1 $h;`  
>`done`  
