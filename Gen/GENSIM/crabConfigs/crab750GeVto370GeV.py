from CRABClient.UserUtilities import config
config = config()

config.General.requestName = 'GENSIM_GluGluToXToAATo4G_mX_750GeV_mA_370GeV_13TeV_Pythia8_FIX_2'
config.General.workArea = '/afs/cern.ch/user/a/amassiro/work/Hgg/H4G/CMSSW_7_6_3_patch2/src/crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'PrivateMC'
config.JobType.psetName = '//afs/cern.ch/user/a/amassiro/work/Hgg/H4G/CMSSW_7_6_3_patch2/src/H4G/Gen/GENSIM/Configs/GENSIM_GluGluToXToAATo4G_mX_750GeV_mA_10GeV_Pythia8.py'

config.Data.outputPrimaryDataset = 'GluGluToXToAATo4G_mX_750GeV_mA_370GeV_Pythia8_FIX_2'
config.Data.splitting = 'EventBased'
config.Data.unitsPerJob = 100
NJOBS = 1000  # This is not a configuration parameter, but an auxiliary variable that we use in the next line.
config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
config.Data.outLFNDirBase = '/store/user/amassiro/H4G/'
config.Data.publication = True
config.Data.outputDatasetTag = 'GENSIM-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12_FIX'

#config.Site.storageSite = <site where the user has permission to write>
config.Site.storageSite = "T2_CH_CERN"
