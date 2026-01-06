#!/bin/bash

#source $BASE_DIR/root/install/bin/thisroot.sh
source /opt/geant4/share/Geant4-10.3.3/geant4make/geant4make.sh
source /opt/geant4/bin/geant4.sh
export HepMC3_DIR=/opt/HepMC3/hepmc3-install/share/HepMC3/cmake
export WCSIMDIR=/opt/WCSim
source $WCSIMDIR/build/this_wcsim.sh
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$WCSIMDIR/build/src
export FITQUN_ROOT=$BASE_DIR/fiTQun
