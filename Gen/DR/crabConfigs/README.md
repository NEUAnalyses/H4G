Crab submission
====

    source /cvmfs/cms.cern.ch/crab3/crab.sh

    voms-proxy-init --voms cms

    crab submit crabConfigs/crab750GeVto10GeV.py
    crab submit crabConfigs/crab750GeVto370GeV.py
    
    crab status ../../../crab_projects/crab_DR_GluGluToXToAATo4G_mX_750GeV_mA_10GeV_13TeV_Pythia8/
    crab status ../../../crab_projects/crab_DR_GluGluToXToAATo4G_mX_750GeV_mA_370GeV_13TeV_Pythia8/
    