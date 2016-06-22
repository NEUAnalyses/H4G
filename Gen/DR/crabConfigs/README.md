Crab submission
====

    source /cvmfs/cms.cern.ch/crab3/crab.sh

    voms-proxy-init --voms cms

    myproxy-init -v
     
     
    crab submit crabConfigs/crab750GeVto10GeV.py
    crab submit crabConfigs/crab750GeVto370GeV.py
    
    crab status ../../../crab_projects/crab_DR_GluGluToXToAATo4G_mX_750GeV_mA_10GeV_13TeV_Pythia8_FIX_2/
    crab status ../../../crab_projects/crab_DR_GluGluToXToAATo4G_mX_750GeV_mA_370GeV_13TeV_Pythia8_FIX_2/

    
Inputs can be found here:

    https://cmsweb.cern.ch/das/request?view=list&limit=50&instance=prod%2Fphys03&input=dataset+dataset%3D%2FGluGluToXToAATo4G_mX_750GeV_mA_*GeV_Pythia8_FIX_2%2Famassiro*%2F*+status%3D*
    