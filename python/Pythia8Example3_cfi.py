import FWCore.ParameterSet.Config as cms

source = cms.Source("Pythia8Source",
    maxEventsToPrint = cms.untracked.int32(1),
    pythiaPylistVerbosity = cms.untracked.int32(1),
    filterEfficiency = cms.untracked.double(1.0),
    pythiaHepMCVerbosity = cms.untracked.bool(False),
    LHEInputFileName = cms.untracked.string('ttbar.lhe'),
    PythiaParameters = cms.PSet(
        pythia8_example01 = cms.vstring(),
        parameterSets = cms.vstring('pythia8_example01')
    )
)
