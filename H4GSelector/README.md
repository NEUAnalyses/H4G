## Repository for the H->aa->4gamma analysis

### Installation
```
cmsrel CMSSW_7_6_3_patch2
cd CMSSW_7_6_3_patch2/src/
cmsenv
git clone git@github.com:NEUAnalyses/H4G.git
cd H4G/H4GSelector/
scramv1 b -j 10
```

### Make selection tree
Currently only storing photons (kinematics and ID variables)   
```
cd ${CMSSW_BASE}/src/H4G/H4GSelector/test/
cmsRun MakeSelection.py
```
