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

    crab status crab_Moriond16WSFinal-38-g7db7446_GluGluToXToAATo4G_mX_750GeV_mA_10GeV_Pythia8_amassiro
    crab status crab_Moriond16WSFinal-38-g7db7446_GluGluToXToAATo4G_mX_750GeV_mA_370GeV_Pythia8_amassiro
    

Try in local:

    cd /afs/cern.ch/user/a/amassiro/work/Hgg/CMSSW_7_6_3_patch2/src/flashgg/MetaData/work/    
    cmsenv
    cd /afs/cern.ch/user/a/amassiro/work/Hgg/H4G/CMSSW_7_6_3_patch2/src/H4G/Gen/microAOD/
    
    cmsRun microAODstd_X750_h370.py
    cmsRun microAODstd_X750_h10.py

To prepare the list of files:

    
    ls  --color=none  eos/cms/store/user/amassiro/H4G/GluGluToXToAATo4G_mX_750GeV_mA_370GeV_Pythia8_FIX_2/AOD_miniAOD-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12_tris_FIX_2/160622_075332/0000/*.root  | awk '{print "@file:"$1"@,"}' | tr "@" "'" >tmp.txt
    ls  --color=none eos/cms/store/user/amassiro/H4G/GluGluToXToAATo4G_mX_750GeV_mA_10GeV_Pythia8_FIX_2/AOD_miniAOD-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12_tris_FIX_2/160622_074438/0000/*.root | awk '{print "@file:"$1"@,"}' | tr "@" "'" >tmp.txt
    
    
And the output file then I move to eos:

    eos/cms/store/user/amassiro/H4G/microAOD/FIX_2/
    myMicroAODOutputFile_GluGluToXToAATo4G_mX_750GeV_mA_10GeV_Pythia8.root
    myMicroAODOutputFile_GluGluToXToAATo4G_mX_750GeV_mA_370GeV_Pythia8.root

    