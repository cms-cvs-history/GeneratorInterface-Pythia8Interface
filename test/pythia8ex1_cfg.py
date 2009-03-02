import FWCore.ParameterSet.Config as cms

process = cms.Process("PROD")

process.load("Configuration.StandardSequences.SimulationRandomNumberGeneratorSeeds_cff")

process.load("GeneratorInterface.Pythia8Interface.Pythia8Example1_cfi")

process.MessageLogger = cms.Service("MessageLogger",
    cout = cms.untracked.PSet(
        default = cms.untracked.PSet(
            limit = cms.untracked.int32(0)
        )
    ),
    destinations = cms.untracked.vstring('cout')
)

process.RandomNumberGeneratorService = cms.Service("RandomNumberGeneratorService",
    moduleSeeds = cms.PSet(
        g4SimHits = cms.untracked.uint32(123456788),
        VtxSmeared = cms.untracked.uint32(123456789)
    ),
    sourceSeed = cms.untracked.uint32(98765)
)

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(10)
)

process.GEN = cms.OutputModule("PoolOutputModule",
    dataset = cms.untracked.PSet(
        dataTier = cms.untracked.string('GEN')
    ),
    fileName = cms.untracked.string('pythia8ex1.root')
)

process.outpath = cms.EndPath(process.GEN)
process.schedule = cms.Schedule(process.outpath)

