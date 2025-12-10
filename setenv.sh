#!/bin/bash

source /usr/local/sklib_gcc8/root_v6.22.06/bin/thisroot.sh
#source /usr/local/sklib_gcc8/root_v5.34.38/build_cmake/bin/thisroot.sh
source /home/ryom/disk3/workdir_WCTE/geant4-v10.3.3/install/bin/geant4.sh
source /home/ryom/disk3/workdir_WCTE/geant4-v10.3.3/build/geant4make.sh
export HepMC3_DIR=/home/ryom/disk3/workdir_WCTE/hepmc3-install/share/HepMC3/cmake

export WCSIMDIR=/home/ryom/disk3/workdir_IWCD/WCSim_v1.12.21/WCSim
source /home/ryom/disk3/workdir_IWCD/WCSim_v1.12.21/WCSim-build/this_wcsim.sh 
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$WCSIMDIR/../WCSim-build/src
export FITQUN_ROOT=/home/ryom/disk3/workdir_IWCD/WCSim_v1.12.21/fiTQun



