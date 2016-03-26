# link to fragment:
# https://github.com/cms-sw/genproductions/blob/ef5cc36c849cd17c08d54fa9843a4b65876f9a7f/python/ThirteenTeV/Higgs/Hadronizer_TuneCUETP8M1_13TeV_powhegEmissionVeto_1p_GluGluHToGG_M-125_LHE_pythia8_cff.py


import FWCore.ParameterSet.Config as cms
from Configuration.Generator.Pythia8CommonSettings_cfi import *
from Configuration.Generator.Pythia8CUEP8M1Settings_cfi import *

generator = cms.EDFilter("Pythia8GeneratorFilter",
                         maxEventsToPrint = cms.untracked.int32(1),
                         pythiaPylistVerbosity = cms.untracked.int32(1),
                         filterEfficiency = cms.untracked.double(1.0),
                         pythiaHepMCVerbosity = cms.untracked.bool(False),
                         comEnergy = cms.double(13000.),
                         PythiaParameters = cms.PSet(
        pythia8CommonSettingsBlock,
        pythia8CUEP8M1SettingsBlock,
        processParameters = cms.vstring(
	    'HiggsSM:all = on',
            'Higgs:useBSM = on',
            '25:m0 = 10.',
            '35:m0 = 125.09',
            'HiggsBSM:gg2H2  = on',
            '35:onMode = 0',
            '35:onIfAll = 25 25',
            '25:onMode = 0',
            '25:onIfAll = 22 22'
          ),
        parameterSets = cms.vstring('pythia8CommonSettings',
                                    'pythia8CUEP8M1Settings',
                                    'processParameters'
                                    )
        )
                         )

ProductionFilterSequence = cms.Sequence(generator)
