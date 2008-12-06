#ifndef Pythia8_Source_h
#define Pythia8_Source_h

/** \class Pythia8Source
 *
 * Generates Pythia8 HepMC events
 *
 * Mikhail Kirsanov 2007
 *
 ***************************************/

#define PYCOMP pycomp_

#include "FWCore/Framework/interface/GeneratedInputSource.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <map>
#include <string>
#include "HepMC/GenEvent.h"

#include "Pythia.h"
#include "HepMCInterface.h"

namespace CLHEP
{
  class RandFlat ;
  class HepRandomEngine;
}

namespace edm
{
  class Pythia8Source : public GeneratedInputSource {
  public:

    /// Constructor
    Pythia8Source(const ParameterSet &, const InputSourceDescription &);
    /// Destructor
    virtual ~Pythia8Source();

    void endRun( Run& r);

  private:

    /// Interface to the PYGIVE pythia routine, with add'l protections
//    bool call_pygive(const std::string& iParm );
    bool call_txgive(const std::string& iParm );
    bool call_txgive_init();
  
  private:
    
    virtual bool produce(Event & e);
    void clear();
    
    /// Pythia PYLIST Verbosity flag
    unsigned int pythiaPylistVerbosity_;
    /// HepMC verbosity flag
    bool pythiaHepMCVerbosity_;
    /// Events to print if verbosity
    unsigned int maxEventsToPrint_;    
    
    Pythia8::Pythia* pythia;
    Pythia8::Event* pythia8event;
    HepMC::I_Pythia8* ToHepMC;

    // external cross section and filter efficiency
    double extCrossSect;
    double extFilterEff;

    // for single particle generation in pythia
    int    particleID;
    bool   doubleParticle;
    double ptmin, ptmax;
    double etamin, etamax;
    double phimin, phimax;
    double comenergy;
    
    CLHEP::HepRandomEngine* fRandomEngine;
    CLHEP::RandFlat*        fRandomGenerator; 

  };
} 

#endif
