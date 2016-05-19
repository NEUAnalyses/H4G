DigiReco (DR)
====

    cmsDriver.py step1 --filein "dbs:/GluGluToXToAATo4G_mX_750GeV_mA_10GeV_Pythia8/amassiro-GENSIM-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-203d0f155a3a777d1b20a819dc59a748/USER" --fileout file:HIG-RunIIFall15DR76-00139_step1.root --pileup_input "dbs:/MinBias_TuneCUETP8M1_13TeV-pythia8/RunIISummer15GS-MCRUN2_71_V1-v2/GEN-SIM" --mc --eventcontent RAWSIM --pileup 2015_25ns_FallMC_matchData_PoissonOOTPU --datatier GEN-SIM-RAW --conditions 76X_mcRun2_asymptotic_v12 --step DIGI,L1,DIGI2RAW,HLT:@frozen25ns --era Run2_25ns --python_filename HIG-RunIIFall15DR76-00139_1_cfg.py --no_exec --customise Configuration/DataProcessing/Utils.addMonitoring -n 82; 

