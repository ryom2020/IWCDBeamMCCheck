#include <iostream>
#include <stdio.h>     
#include <stdlib.h>
#include <fstream>

#include "TH1F.h"
#include "TH2F.h"
#include "TFile.h"
#include "TTree.h"
#include "TObject.h"
#include "TMath.h"
#include "TBranch.h"
#include "TCanvas.h"
#include "TSystem.h"
#include "TChain.h"
#include "TStyle.h"
#include "WCSimRootGeom.hh"
#include "WCSimRootEvent.hh"

#include "TBox.h"
#include "TEllipse.h"

//#include "WCSimRootPMT.hh"

float GetWall(float vertex[3]){
  float wall;
  float TankR = 3380./2;
  float TankhalfZ = 3620./2;
  float r = sqrt(pow(vertex[0],2) + pow(vertex[1],2) + pow(vertex[2],2));

  float candidateR = TankR - r;
  float candidateZ = TankhalfZ - abs(vertex[2]);
  if(candidateR > candidateZ) return candidateR;
  else return candidateZ;
}
void Angles(float fit_dir[3], float &theta, float &phi){
  theta = TMath::ACos(fit_dir[2]);
  phi = TMath::Sign(1.0, fit_dir[1]) * TMath::ACos( fit_dir[0]/sqrt(pow(fit_dir[0],2)+pow(fit_dir[1],2)) );
}

int main(int argc, char* argv[]){  
  gSystem->Load("libTree.so");
  gStyle->SetOptStat(0);

  char* path = "/home/ryom/disk3/workdir_IWCD/WCSim_v1.12.12/MCprod/diriso_pos000_no_hadscat_IWCD_mPMT/mu-/300/wcsimout.root";
  std::cout<<path<<std::endl;

  
  //---Open output file
  //TFile *outfile = new TFile("Hist.root","recreate");
  TCanvas *c1 = new TCanvas("c1","",600,600);
  //TH1F *hist_mom = new TH1F("hist_mom","",100, 0, 100);
    
  TChain *gtree = new TChain("wcsimGeoT");
  gtree->Add(path);
  WCSimRootGeom* wcsimrootgeom = new WCSimRootGeom();
  TBranch *branch = gtree->GetBranch("wcsimrootgeom");
  branch->SetAddress(&wcsimrootgeom);
  gtree->GetEntry(ev);
  
  TChain *wcsimT = new TChain("wcsimT");
  wcsimT->Add(path);
  WCSimRootEvent* wcsimrootevent = new WCSimRootEvent();
  wcsimT->SetBranchAddress("wcsimrootevent",&wcsimrootevent);
  wcsimT->GetBranch("wcsimrootevent")->SetAutoDelete(kTRUE);
  //---WCSimRootEvent has event information for each trigger.
  //---call wcsimrootevent->GetTrigger(itrigger) and get information in WCSimRootTrigger class.
  //---WCSimRootTrigger class have true and observed information:
  //---    number of track: GetNtrack()
  //---    number of digitized hit: GetNcherenkovdigihits()
  //---        if you need more information of hits, call GetCherenkovDigiHits()
  //---        and get WCSimRootCherenkovDigiHit class.
  //---    initial interaction mode: GetMode()
  //---    and more...
  //---WCSimRootTrack class is a member of this class.
  //---WCSimRootTrack class have information for each track.
  //---    true particle id (defined by particle data group): GetIpnu();
  //---    true direction: GetDir(axis), axis=0,1,2
  //---    true momentum(MeV/c): GetP()
  //---    and more...
  //---see WCSimRootEvent.hh for details.
  
  //---Get the number of events
  int nevent = wcsimT->GetEntries();
  std::cout<<"event number = "<<nevent<<std::endl;

  int start = 0;
  int end = nevent;
  if(argc==2){
    start = atoi(argv[1]);
    end = start+1;
  }
  for (int ev=start;ev<end; ev++){
    std::cout<<"==="<< ev <<" event"<<std::endl;
    //if(ev%1000==0) std::cout<<"progress: "<<ev<<std::endl;

    //---Read the event from the tree into instance
    wcsimT->GetEvent(ev);

    //---Get trigger information
    int itrigger=0;
    int ntrigger = wcsimrootevent->GetTrigger(itrigger);
    WCSimRootTrigger *wcsimroottrigger = wcsimrootevent->GetTrigger(itrigger);
    std::cout<<"trigger offset: "<<wcsimroottrigger->GetHeader()->GetDate()<<std::endl;

    int ntrack = wcsimroottrigger->GetNtrack();    
    int ncherenkovdigihits = wcsimroottrigger->GetNcherenkovdigihits();    
    int true_mode=wcsimroottrigger->GetMode();
    float sumQ=wcsimroottrigger->GetSumQ();

    std::cout<<"sumQ "<<sumQ<<std::endl;

    //if(true_mode!=1) continue;

    //---Get track information
    for(int itrack=0; itrack<ntrack; itrack++){
      TObject *element = (wcsimroottrigger->GetTracks())->At(itrack);
      WCSimRootTrack *wcsimroottrack = dynamic_cast<WCSimRootTrack*>(element);
      
      int pid_true = wcsimroottrack->GetIpnu();
      int true_parent_ipnu=wcsimroottrack->GetParenttype();
      float dir[3]; for(int axis = 0; axis<3; axis++) dir[axis] = wcsimroottrack->GetDir(axis);
      float momentum = wcsimroottrack->GetP();// M is mass, E is kinetic energy, P is momentum(MeV)
      float Ekin = wcsimroottrack->GetE();// M is mass, E is kinetic energy, P is momentum(MeV)
      float mass = wcsimroottrack->GetM();
      std::cout<<itrack<<" "<<momentum<<" "<<Ekin<<" "<<mass<<" "<<pid_true<<" "<<true_parent_ipnu<<" "<< wcsimroottrack->GetTime() <<std::endl;

      float vertex[3]; for(int axis = 0; axis < 3; axis++) vertex[axis] = wcsimroottrigger->GetVtx(axis);
      int stopvol = wcsimroottrack->GetStopvol();
      float stoppos[3];
      for(int axis = 0; axis < 3; axis++) stoppos[axis] = wcsimroottrack->GetStop(axis);
      float stopposR = sqrt(stoppos[0]*stoppos[0] + stoppos[2]*stoppos[2]);
      //--stopvol
      //see WCSimEventAction::WCSimEventFindStoppingVolume(G4String stopVolumeName)
      //    -1: default
      //    -3: unknown
      //notFV
      //    -2: (stopVolumeName == "WCBox")
      //    10: Tank, Barrel
      //    11: PMT, Cap, Cell
      //    12: OD
      //FV
      //    10: WCFVBarrel, WCFVAnnulus, WCFVRing
      //    13: FVPMT
      //else
      //    0: expHall
      //    40: catcher
      
      
    }
    
    //---Get hit PMT information
    for (int i=0; i<ncherenkovdigihits; i++) {
      WCSimRootCherenkovDigiHit *hit = (WCSimRootCherenkovDigiHit*)(wcsimroottrigger->GetCherenkovDigiHits()->At(i));
      float hittime = hit->GetT();
      float charge = hit->GetQ();
      int tubeId = hit->GetTubeId();
      float pmtpos[3];
      for(int axis = 0; axis < 3; axis++) pmtpos[axis] = wcsimrootgeom->GetPMT(tubeId-1).GetPosition(axis);
    }
    
  } //// End of loop over events
  //std::cout<< nPCevents <<" / "<< nevent <<" = "<< 100. * nPCevents / nevent <<" %"<<std::endl;
  
  return 0;
}

