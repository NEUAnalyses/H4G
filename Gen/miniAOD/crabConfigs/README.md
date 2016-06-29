Crab submission
====

    source /cvmfs/cms.cern.ch/crab3/crab.sh

    voms-proxy-init --voms cms

    myproxy-init -v
     
     
    crab submit crabConfigs/crab750GeVto10GeV.py
    crab submit crabConfigs/crab750GeVto370GeV.py
    
    crab status ../../../crab_projects/crab_AOD_miniAOD_GluGluToXToAATo4G_mX_750GeV_mA_10GeV_13TeV_Pythia8/
    crab status ../../../crab_projects/crab_AOD_miniAOD_GluGluToXToAATo4G_mX_750GeV_mA_370GeV_13TeV_Pythia8/
    
    crab status ../../../crab_projects/crab_AOD_miniAOD_GluGluToXToAATo4G_mX_750GeV_mA_10GeV_13TeV_Pythia8_bis/
    crab status ../../../crab_projects/crab_AOD_miniAOD_GluGluToXToAATo4G_mX_750GeV_mA_370GeV_13TeV_Pythia8_bis/
    
    crab status ../../../crab_projects/crab_AOD_miniAOD_GluGluToXToAATo4G_mX_750GeV_mA_10GeV_13TeV_Pythia8_tris/
    crab status ../../../crab_projects/crab_AOD_miniAOD_GluGluToXToAATo4G_mX_750GeV_mA_370GeV_13TeV_Pythia8_tris/

    crab status ../../../crab_projects/crab_AOD_miniAOD_GluGluToXToAATo4G_mX_750GeV_mA_10GeV_13TeV_Pythia8_tris_FIX_2/
    crab status ../../../crab_projects/crab_AOD_miniAOD_GluGluToXToAATo4G_mX_750GeV_mA_370GeV_13TeV_Pythia8_tris_FIX_2/
    
    crab status ../../../crab_projects/crab_AOD_miniAOD_GluGluToXToAATo4G_mX_750GeV_mA_370GeV_13TeV_Pythia8_tris_FIX_3/
    
    
Local tests:

    "/store/user/amassiro/H4G/GluGluToXToAATo4G_mX_750GeV_mA_10GeV_Pythia8/DR-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12/160519_145441/0000/HIG-RunIIFall15DR76-00139_step1_1.root"

 
Inputs can be found here:

    https://cmsweb.cern.ch/das/request?view=list&limit=50&instance=prod%2Fphys03&input=dataset+dataset%3D%2FGluGluToXToAATo4G_mX_750GeV_mA_*GeV_Pythia8_FIX_2%2Famassiro*%2F*+status%3D*
    https://cmsweb.cern.ch/das/request?view=list&limit=50&instance=prod%2Fphys03&input=dataset+dataset%3D%2FGluGluToXToAATo4G_mX_750GeV_mA_*GeV_Pythia8_FIX_3%2Famassiro*%2F*+status%3D*

    
Outputs on eos:

    eos/cms/store/user/amassiro/H4G/GluGluToXToAATo4G_mX_750GeV_mA_10GeV_Pythia8_FIX_2/AOD_miniAOD-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12_tris_FIX_2/160622_074438/0000/
    eos/cms/store/user/amassiro/H4G/GluGluToXToAATo4G_mX_750GeV_mA_370GeV_Pythia8_FIX_2/AOD_miniAOD-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12_tris_FIX_2/160622_075332/0000/
    
    eos/cms/store/user/amassiro/H4G/GluGluToXToAATo4G_mX_750GeV_mA_370GeV_Pythia8_FIX_3/AOD_miniAOD-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12_tris_FIX_3/160627_230328/0000/