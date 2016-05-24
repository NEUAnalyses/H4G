miniAOD
====

    cmsDriver.py
    
    cmsDriver.py step1 --filein "dbs:/VBFHToWWTo2L2Nu_M210_13TeV_powheg_JHUgenv628_pythia8/RunIIFall15DR76-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/AODSIM" --fileout file:HIG-RunIIFall15MiniAODv2-00711.root --mc --eventcontent MINIAODSIM --runUnscheduled --datatier MINIAODSIM --conditions 76X_mcRun2_asymptotic_v12 --step PAT --era Run2_25ns --python_filename HIG-RunIIFall15MiniAODv2-00711_1_cfg.py --no_exec -n 1920 
    
    
    cmsDriver.py step2 --filein file:HIG-RunIIFall15DR76-00825_step1.root --fileout file:HIG-RunIIFall15DR76-00825.root --mc --eventcontent AODSIM,DQM --runUnscheduled --datatier AODSIM,DQMIO --conditions 76X_mcRun2_asymptotic_v12 --step RAW2DIGI,L1Reco,RECO,EI,DQM:DQMOfflinePOGMC --era Run2_25ns --python_filename HIG-RunIIFall15DR76-00825_2_cfg.py --no_exec --customise Configuration/DataProcessing/Utils.addMonitoring -n 82 || exit $? ; 



    cmsDriver.py step1 --filein "dbs:/VBFHToWWTo2L2Nu_M210_13TeV_powheg_JHUgenv628_pythia8/RunIIFall15DR76-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/AODSIM" --fileout file:HIG-RunIIFall15MiniAODv2-00711.root --mc --eventcontent MINIAODSIM --runUnscheduled --datatier MINIAODSIM --conditions 76X_mcRun2_asymptotic_v12 --step RAW2DIGI,L1Reco,RECO,EI,PAT --era Run2_25ns --python_filename HIG-RunIIFall15MiniAODv2-00711_1_cfg.py --no_exec -n 1920 

    cmsDriver.py step1 --filein "dbs:/VBFHToWWTo2L2Nu_M210_13TeV_powheg_JHUgenv628_pythia8/RunIIFall15DR76-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-v1/AODSIM" --fileout file:HIG-RunIIFall15MiniAODv2-00711.root --mc --eventcontent AODSIM --runUnscheduled --datatier AODSIM --conditions 76X_mcRun2_asymptotic_v12 --step RAW2DIGI,L1Reco,RECO,EI --era Run2_25ns --python_filename HIG-RunIIFall15MiniAODv2-00711_2_cfg.py --no_exec -n 1920 
