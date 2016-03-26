from CRABClient.UserUtilities import config
config = config()

config.General.requestName = 'GENSIM_GluGluToHToAATo4G_mA_0p1GeV_13TeV_Pythia8'
config.General.workArea = '/afs/cern.ch/work/r/rateixei/work/NEU_H4G/Mar23/CMSSW_7_6_1/src/crab_projects'
config.General.transferOutputs = True
config.General.transferLogs = False

config.JobType.pluginName = 'PrivateMC'
config.JobType.psetName = '/afs/cern.ch/work/r/rateixei/work/NEU_H4G/Mar23/CMSSW_7_6_1/src/Configs/GENSIM_GluGluToHToAATo4G_mA_0p1GeV_Pythia8.py'

config.Data.outputPrimaryDataset = 'GluGluToHToAATo4G_mA_0p1GeV_13TeV_Pythia8'
config.Data.splitting = 'EventBased'
config.Data.unitsPerJob = 5000
NJOBS = 20  # This is not a configuration parameter, but an auxiliary variable that we use in the next line.
config.Data.totalUnits = config.Data.unitsPerJob * NJOBS
config.Data.outLFNDirBase = '/store/user/rateixei/H4G/'
config.Data.publication = True
config.Data.outputDatasetTag = 'GENSIM-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12'

#config.Site.storageSite = <site where the user has permission to write>
config.Site.storageSite = "T2_CH_CERN"
