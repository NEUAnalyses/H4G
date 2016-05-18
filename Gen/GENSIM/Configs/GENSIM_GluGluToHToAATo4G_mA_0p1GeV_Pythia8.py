# Auto generated configuration file
# using: 
# Revision: 1.19 
# Source: /local/reps/CMSSW/CMSSW/Configuration/Applications/python/ConfigBuilder.py,v 
# with command line options: Configuration/GenProduction/python/Step0_GluGluToHToXXTo4G-fragment.py --fileout file:HIG-RunIISummer15GS-00174.root --mc --eventcontent RAWSIM --era Run2_25ns --datatier GEN-SIM --conditions 76X_mcRun2_asymptotic_v12 --pileup 2015_25ns_FallMC_matchData_PoissonOOTPU --step GEN,SIM --magField 38T_PostLS1 --python_filename HIG-RunIISummer15GS-00174_1_cfg.py --no_exec -n 100000
import FWCore.ParameterSet.Config as cms

from Configuration.StandardSequences.Eras import eras

process = cms.Process('SIM',eras.Run2_25ns)

# import of standard configurations
process.load('Configuration.StandardSequences.Services_cff')
process.load('SimGeneral.HepPDTESSource.pythiapdt_cfi')
process.load('FWCore.MessageService.MessageLogger_cfi')
process.load('Configuration.EventContent.EventContent_cff')
process.load('SimGeneral.MixingModule.mix_2015_25ns_FallMC_matchData_PoissonOOTPU_cfi')
process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.Geometry.GeometrySimDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_PostLS1_cff')
process.load('Configuration.StandardSequences.Generator_cff')
process.load('IOMC.EventVertexGenerators.VtxSmearedRealistic50ns13TeVCollision_cfi')
process.load('GeneratorInterface.Core.genFilterSummary_cff')
process.load('Configuration.StandardSequences.SimIdeal_cff')
process.load('Configuration.StandardSequences.EndOfProcess_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100000)
)

# Input source
process.source = cms.Source("EmptySource")

process.options = cms.untracked.PSet(

)

# Production Info
process.configurationMetadata = cms.untracked.PSet(
    annotation = cms.untracked.string('Configuration/GenProduction/python/Step0_GluGluToHToXXTo4G-fragment.py nevts:100000'),
    name = cms.untracked.string('Applications'),
    version = cms.untracked.string('$Revision: 1.19 $')
)

# Output definition

process.RAWSIMoutput = cms.OutputModule("PoolOutputModule",
    SelectEvents = cms.untracked.PSet(
        SelectEvents = cms.vstring('generation_step')
    ),
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('GEN-SIM'),
        filterName = cms.untracked.string('')
    ),
    eventAutoFlushCompressedSize = cms.untracked.int32(5242880),
    fileName = cms.untracked.string('file:HIG-RunIISummer15GS-00174.root'),
    outputCommands = process.RAWSIMEventContent.outputCommands,
    splitLevel = cms.untracked.int32(0)
)

# Additional output definition

# Other statements
process.genstepfilter.triggerConditions=cms.vstring("generation_step")
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '76X_mcRun2_asymptotic_v12', '')

process.generator = cms.EDFilter("Pythia8GeneratorFilter",
    PythiaParameters = cms.PSet(
        parameterSets = cms.vstring('pythia8CommonSettings', 
            'pythia8CUEP8M1Settings', 
            'processParameters'),
        processParameters = cms.vstring('HiggsSM:all = on', 
            'Higgs:useBSM = on',
            'HiggsBSM:all = off',    # Switch off all BSM Higgs production
            'HiggsBSM:gg2H2 = on',
            '35:m0 = 125.',
            #'35:mMin = 50.',

            '35:addChannel 1 0.01 100 54 54', 
            '35:onMode = off',
            '35:onIfMatch = 54 54',

            '54:isResonance = false',
            '54:mWidth = 0',
            '54:m0 = 0.1',
            '54:onMode = off',
            #'54:onIfAll = 22 22',
            '54:onIfMatch = 22 22',
            #'54:addChannel 1 1.00 101 22 22', 

            #'35:onMode = off',
            #'35:onIfMatch = 25 25',

            #'25:isResonance = false',
            #'25:mWidth = 0',
            #'25:m0 = 0.1',
            #'25:onMode = off',
            #'25:onIfAll = 22 22',
            ##'25:onIfMatch = 22 22',
            


                        #'Higgs:useBSM = on',
                        #'HiggsBSM:all = off',    # Switch off all BSM Higgs production
                        #'HiggsBSM:gg2H2 = on',
                        #'35:m0 = 90',
                        ##'35:mMin = 50.',

                        #'35:addChannel 1 0.01 100 54 54', 
                        #'35:onMode = off',
                        #'35:onIfMatch = 54 54',

                        #'54:isResonance = false',
                        #'54:mWidth = 0',
                        #'54:m0 = 0.25',
                        #'54:onMode = off',
                        #'54:onIfMatch = 13 -13',
                        
            #'Higgs:useBSM = on',     # Initialize and use the two-Higgs-doublet BSM states
            #'HiggsBSM:all = off',    # Switch off all BSM Higgs production
            #'HiggsBSM:gg2H2 = on',   # Switch on gg->H^0(H_2^0) scattering via loop contributions primarily from top. Code 1022. 
            #'35:m0 = 90.0',         #  mass in GeV of H0 (PDG ID = 35)
            #'36:m0 = 0.5',           #  mass in GeV of A0 (PDG ID = 36)
            # decays of H0 (PDG ID = 35)
            #'35:onMode = off',       # Turn off all H0 decay modes 
            #'35:onIfMatch = 36 36',  # Allow H0 decays to A0: H0 ->A0A0
            # decays of A0 (PDG ID = 36)
            #'36:onMode = off',       # Turn off all A0 decay modes
            #'36:onIfMatch = 13 -13', # Allow A0 decays to muons: A0 ->mu+mu-
            # Useful debug printouts
            'Init:showProcesses = on',        # Print a list of all processes that will be simulated, with their estimated cross section maxima
            'Init:showChangedSettings = on',  # Print a list of the changed flag/mode/parameter/word setting
            #'Init:showAllParticleData = on', # Print a list of all particle and decay data. Warning: this will be a long list

            #'Higgs:useBSM = on', 
            #'25:m0 = 0.1', 
            #'35:m0 = 125.09', 
            #'HiggsBSM:gg2H2  = on', 
            #'35:onMode = 0', 
            #'35:onIfAll = 25 25', 
            #'25:onMode = 0', 
            #'25:onIfAll = 22 22'
            ),
        pythia8CUEP8M1Settings = cms.vstring('Tune:pp 14', 
            'Tune:ee 7', 
            'MultipartonInteractions:pT0Ref=2.4024', 
            'MultipartonInteractions:ecmPow=0.25208', 
            'MultipartonInteractions:expPow=1.6'),
        pythia8CommonSettings = cms.vstring('Tune:preferLHAPDF = 2', 
            'Main:timesAllowErrors = 10000', 
            'Check:epTolErr = 0.01', 
            'Beams:setProductionScalesFromLHEF = off', 
            'SLHA:keepSM = on', 
            'SLHA:minMassSM = 1000.', 
            'ParticleDecays:limitTau0 = on', 
            'ParticleDecays:tau0Max = 10', 
            'ParticleDecays:allowPhotonRadiation = on')
    ),
    comEnergy = cms.double(13000.0),
    filterEfficiency = cms.untracked.double(1.0),
    maxEventsToPrint = cms.untracked.int32(1),
    pythiaHepMCVerbosity = cms.untracked.bool(False),
    pythiaPylistVerbosity = cms.untracked.int32(1)
)


process.ProductionFilterSequence = cms.Sequence(process.generator)

# Path and EndPath definitions
process.generation_step = cms.Path(process.pgen)
process.simulation_step = cms.Path(process.psim)
process.genfiltersummary_step = cms.EndPath(process.genFilterSummary)
process.endjob_step = cms.EndPath(process.endOfProcess)
process.RAWSIMoutput_step = cms.EndPath(process.RAWSIMoutput)

# Schedule definition
process.schedule = cms.Schedule(process.generation_step,process.genfiltersummary_step,process.simulation_step,process.endjob_step,process.RAWSIMoutput_step)
# filter all path with the production filter sequence
for path in process.paths:
	getattr(process,path)._seq = process.ProductionFilterSequence * getattr(process,path)._seq 


