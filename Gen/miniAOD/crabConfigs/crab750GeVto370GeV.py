from CRABClient.UserUtilities import config
config = config()

config.General.requestName = 'AOD_miniAOD_GluGluToXToAATo4G_mX_750GeV_mA_370GeV_13TeV_Pythia8_tris'
config.General.workArea = '/afs/cern.ch/user/a/amassiro/work/Hgg/H4G/CMSSW_7_6_3_patch2/src/crab_projects/'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'Analysis'
config.JobType.psetName = '/afs/cern.ch/user/a/amassiro/work/Hgg/H4G/CMSSW_7_6_3_patch2/src/H4G/Gen/miniAOD/Configs/AOD_miniAOD_generic.py'

config.Data.inputDataset = '/GluGluToXToAATo4G_mX_750GeV_mA_370GeV_Pythia8/amassiro-DR-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12-32f870ac2e5a27e6c7b243a0bfc25281/USER'
#config.Data.outputPrimaryDataset = 'AOD_miniAOD_GluGluToXToAATo4G_mX_750GeV_mA_370GeV_Pythia8'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 1
#NJOBS = 1000  # This is not a configuration parameter, but an auxiliary variable that we use in the next line.
#NJOBS = 999  # This is not a configuration parameter, but an auxiliary variable that we use in the next line.
#config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
config.Data.outLFNDirBase = '/store/user/amassiro/H4G/'
config.Data.publication = True
config.Data.outputDatasetTag = 'AOD_miniAOD-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12_tris'

#config.Site.storageSite = <site where the user has permission to write>
config.Site.storageSite = "T2_CH_CERN"

config.Data.inputDBS = 'phys03'
