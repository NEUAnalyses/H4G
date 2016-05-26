Crab submission of microAOD
====


Flashgg framework: 

    https://github.com/cms-analysis/flashgg   

MicroAOD generation

    https://github.com/cms-analysis/flashgg/tree/master/MetaData   

Prepare json file with the datasets you want to run on (signals.json)

    signals.json

Prepare crab configuration files with ./prepareCrabJobs.py   

    cd /afs/cern.ch/user/a/amassiro/work/Hgg/CMSSW_7_6_3_patch2/src/flashgg/MetaData/work/    
    cmsenv
    ./prepareCrabJobs.py -C myTest  -s /afs/cern.ch/user/a/amassiro/work/Hgg/H4G/CMSSW_7_6_3_patch2/src/H4G/Gen/microAOD/signals.json --mkPilot


Keep track of your campaign name (myTest above), as it will be useful later on.
This will create a directory "myTest" with all your crab configuration files, the CMSSW parameter set, and the dump of all the script options.


Submit all:

    source /cvmfs/cms.cern.ch/crab3/crab.sh
    voms-proxy-init --voms cms

    
    cd myTest
    echo crabConfig_*.py | xargs -n 1 crab sub

    
NB: the config.General.requestName could be created too long (more than 100 characters, not allowed in Crab3). Just change the name by hand.
Same issue for "outputDatasetTag"
Remember to change the inputDBS, since I will need to read from phy03:

    config.Data.inputDBS = 'phys03'

Check crab:

    ls crab_* -d | xargs -n 1 crab status  

    crab status crab_Moriond16WSFinal-GluGluToXToAATo4G_mX_750GeV_mA_370GeV_Pythia8_amassiro/
    crab status crab_Moriond16WSFinal-GluGluToXToAATo4G_mX_750GeV_mA_10GeV_Pythia8_amassiro/
    
