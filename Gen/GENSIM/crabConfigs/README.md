Crab submission
====

    source /cvmfs/cms.cern.ch/crab3/crab.sh

    voms-proxy-init --voms cms

    crab submit crabConfigs/crab750GeVto10GeV.py
    crab submit crabConfigs/crab750GeVto370GeV.py
    
    crab status ../../../crab_projects/crab_GENSIM_GluGluToXToAATo4G_mX_750GeV_mA_10GeV_13TeV_Pythia8/
    crab status ../../../crab_projects/crab_GENSIM_GluGluToXToAATo4G_mX_750GeV_mA_370GeV_13TeV_Pythia8/

    crab status ../../../crab_projects/crab_GENSIM_GluGluToXToAATo4G_mX_750GeV_mA_370GeV_13TeV_Pythia8_FIX/

    
    
Test generated sample at GEN:

    cd /afs/cern.ch/user/a/amassiro/work/Hgg/H4G/TestFlashGG/CMSSW_7_6_3_patch2/src/
    git clone git@github.com:latinos/LatinoTreesGEN.git
    cmsenv
    scramv1 b -j 20
    
    cd LatinoTreesGEN/GenDumper/test/
    
    cmsRun gendumper_cfg.py   \
        inputFiles=file:/tmp/amassiro/eos/cms/store/user/amassiro/H4G/GluGluToXToAATo4G_mX_750GeV_mA_370GeV_Pythia8_FIX/GENSIM-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12_FIX/160614_225907/0000/HIG-RunIISummer15GS-00174_938.root  \
        outputFile=/tmp/amassiro/test.root  \
        isMiniAod=False  \
        doLHE=False   \
        genJets=ak4GenJets \
        debug=True
        
        
    cmsRun gendumper_cfg.py   \
        inputFiles=file:/tmp/amassiro/eos/cms/store/user/amassiro/H4G/GluGluToXToAATo4G_mX_750GeV_mA_10GeV_Pythia8/GENSIM-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12/160517_123644/0000/HIG-RunIISummer15GS-00174_896.root  \
        outputFile=/tmp/amassiro/test.old.root  \
        isMiniAod=False  \
        doLHE=False   \
        genJets=ak4GenJets
        
        
     cmsRun gendumper_cfg.py   \
        inputFiles=file:/afs/cern.ch/user/a/amassiro/work/Hgg/H4G/CMSSW_7_6_3_patch2/src/H4G/Gen/GENSIM/Configs/HIG-RunIISummer15GS-00174.root  \
        outputFile=/tmp/amassiro/test.new.root  \
        isMiniAod=False  \
        doLHE=False   \
        genJets=ak4GenJets
        
        

        
        