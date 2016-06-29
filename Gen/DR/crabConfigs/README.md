Crab submission
====

    source /cvmfs/cms.cern.ch/crab3/crab.sh

    voms-proxy-init --voms cms

    myproxy-init -v
     
     
    crab submit crabConfigs/crab750GeVto10GeV.py
    crab submit crabConfigs/crab750GeVto370GeV.py
    
    crab status ../../../crab_projects/crab_DR_GluGluToXToAATo4G_mX_750GeV_mA_10GeV_13TeV_Pythia8_FIX_2/
    crab status ../../../crab_projects/crab_DR_GluGluToXToAATo4G_mX_750GeV_mA_370GeV_13TeV_Pythia8_FIX_2/

    crab status ../../../crab_projects/crab_DR_GluGluToXToAATo4G_mX_750GeV_mA_370GeV_13TeV_Pythia8_FIX_3/

    
    
Inputs can be found here:

    https://cmsweb.cern.ch/das/request?view=list&limit=50&instance=prod%2Fphys03&input=dataset+dataset%3D%2FGluGluToXToAATo4G_mX_750GeV_mA_*GeV_Pythia8_FIX_2%2Famassiro*%2F*+status%3D*
    https://cmsweb.cern.ch/das/request?view=list&limit=50&instance=prod%2Fphys03&input=dataset+dataset%3D%2FGluGluToXToAATo4G_mX_750GeV_mA_*GeV_Pythia8_FIX_3%2Famassiro*%2F*+status%3D*
    
    

Outputs on eos:

    eos/cms/store/user/amassiro/H4G/GluGluToXToAATo4G_mX_750GeV_mA_370GeV_Pythia8_FIX_2/AOD_miniAOD-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12_tris_FIX_2/160622_075332/0000/
    eos/cms/store/user/amassiro/H4G/GluGluToXToAATo4G_mX_750GeV_mA_370GeV_Pythia8_FIX_3/DR-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12_FIX_3/160627_021719/0000/
    
    
before

drwxr-xr-x. 1 amassiro zh   1 Oct 23  2013 HWW
drwxr-xr-x. 1 amassiro zh   1 Nov 14  2013 WWInterference
drwxr-xr-x. 1 amassiro zh   1 Feb 10  2014 bbH
drwxr-xr-x. 1 cmsprod  zh 474 Jun 13 09:35 ..
drwxr-xr-x. 1 amassiro zh   1 Jun 17 03:51 WW
drwxr-xr-x. 1 amassiro zh   6 Jun 21 12:25 .
drwxr-xr-x. 1 amassiro zh   1 Jun 22 09:16 HH
drwxr-xr-x. 1 amassiro zh   6 Jun 28 00:26 H4G

after

drwxr-xr-x. 1 amassiro zh   1 Oct 23  2013 HWW
drwxr-xr-x. 1 amassiro zh   1 Nov 14  2013 WWInterference
drwxr-xr-x. 1 amassiro zh   1 Feb 10  2014 bbH
drwxr-xr-x. 1 cmsprod  zh 474 Jun 13 09:35 ..
drwxr-xr-x. 1 amassiro zh   1 Jun 17 03:51 WW
drwxr-xr-x. 1 amassiro zh   6 Jun 21 12:25 .
drwxr-xr-x. 1 amassiro zh   1 Jun 22 09:16 HH
drwxr-xr-x. 1 amassiro zh   6 Jun 28 00:26 H4G
