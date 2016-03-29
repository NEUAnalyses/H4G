import FWCore.ParameterSet.Config as cms

process = cms.Process("H4GSelector")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.load("Configuration.StandardSequences.GeometryRecoDB_cff")
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
# NOTE: the pick the right global tag!
#    for Spring15 50ns MC: global tag is 'auto:run2_mc_50'
#    for Spring15 25ns MC: global tag is 'auto:run2_mc'
#    for Run 2 data: global tag is 'auto:run2_data'
#  as a rule, find the "auto" global tag in $CMSSW_RELEASE_BASE/src/Configuration/AlCa/python/autoCond.py
#  This auto global tag will look up the "proper" global tag
#  that is typically found in the DAS under the Configs for given dataset
#  (although it can be "overridden" by requirements of a given release)
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, 'auto:run2_mc', '')


process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )

inputFiles = cms.untracked.vstring(
    # MiniAOD test files from 
    # /GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v1/MINIAODSIM
#       '/store/mc/RunIISpring15DR74/GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/00000/04904448-3D06-E511-AB50-00266CFCE03C.root',
       '/store/mc/RunIISpring15DR74/GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/00000/06A2ACA3-7005-E511-B165-008CFA0A58B4.root',
       '/store/mc/RunIISpring15DR74/GJet_Pt-40toInf_DoubleEMEnriched_MGG-80toInf_TuneCUETP8M1_13TeV_Pythia8/MINIAODSIM/Asympt25ns_MCRUN2_74_V9-v1/00000/06E82640-9605-E511-9165-001EC9ADCBEF.root',
    )

process.source = cms.Source ("PoolSource", fileNames = inputFiles ) 

#
# Set up photon ID (VID framework)
from PhysicsTools.SelectorUtils.tools.vid_id_tools import *
dataFormat = DataFormat.MiniAOD
switchOnVIDPhotonIdProducer(process, dataFormat)
# define which IDs we want to produce
my_id_modules = ['RecoEgamma.PhotonIdentification.Identification.mvaPhotonID_Spring15_25ns_nonTrig_V2_cff',
		  'RecoEgamma.PhotonIdentification.Identification.cutBasedPhotonID_Spring15_25ns_V1_cff']
#add them to the VID producer
for idmod in my_id_modules:
    setupAllVIDIdsInModule(process,idmod,setupVIDPhotonSelection)

process.TFileService = cms.Service("TFileService",
                                   fileName = cms.string( "outputFile.root" )
                                   )

process.load("H4G.H4GSelector.H4GSelector_cfi")
process.p = cms.Path(process.egmPhotonIDSequence * process.h4gselector)
