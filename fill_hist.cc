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
#include "TVector3.h"
#include "FQOut.C"


int main(int argc, char* argv[]){  
  gStyle->SetOptStat(0);
  gStyle->SetPadLeftMargin(0.2);
  gStyle->SetPadRightMargin(0.2);
  gStyle->SetPadBottomMargin(0.2);
  /*
  char* path_wcsim = "/home/ryom/disk2/HK_beta_prod_IWCD/beta-production/iwcd/prod1A/validation/V01/neut536/t1/wcsim_v1.12.26_cwcs1.0/rwcs/lbl_neut_iwcd_test_00000000-*_rwcs.root";
  char* path_fq = "/home/ryom/disk2/HK_beta_prod_IWCD/beta-production/iwcd/prod1A/validation/V01/neut536/t1/wcsim_v1.12.26_cwcs1.0/fitqun_6.4.4_cfqn1.0.0/rfqn/lbl_neut_iwcd_test_00000000-*_rfqn.root";
  */
  
  char* path_wcsim = "/home/ryom/disk2/HK_beta_prod_IWCD/beta-production/iwcd/prod1A/validation/V01/neut536/t1/wcsim_v1.12.26_cwcs1.0/rwcs/lbl_neut_iwcd_test_00000000-0000_rwcs.root";
  char* path_fq = "/home/ryom/disk2/HK_beta_prod_IWCD/beta-production/iwcd/prod1A/validation/V01/neut536/t1/wcsim_v1.12.26_cwcs1.0/fitqun_6.4.4_cfqn1.0.0/rfqn/lbl_neut_iwcd_test_00000000-0000_rfqn.root";

  char* path_outroot = "out/hist.root";
  
  bool is_wcsim = false;
  bool is_fq = false;
  bool is_outroot = false;
  /*
  bool is_wcsim = true;
  bool is_fq = true;
  bool is_outroot = true;
  */
  //load option             
  int opt;
  while ((opt = getopt(argc, argv, "w:f:o:")) != -1){
    switch (opt){
    case 'w':
      path_wcsim = optarg;
      
      is_wcsim = true;
      break;
    case 'f':
      path_fq = optarg;
      is_fq = true;
      break;
    case 'o':
      path_outroot = optarg;
      is_outroot = true;
      break;
    default:
      std::cout<<"undefined option"<<std::endl;
      break;
    }
  }
  
  if(argc==1 || !is_wcsim || !is_outroot){
    std::cout<<"Usage: ./fill_hist -w /path/to/wcsimout.root -f /path/to/fitqunout.root -o /path/to/output.root"<<std::endl;
    return -1;
  }

  std::cout<<"Reading WCSim: "<<path_wcsim<<std::endl;
  std::cout<<"Reading fiTQun: "<<path_fq<<std::endl;
  std::cout<<"Output file: "<<path_outroot<<std::endl;

  //=== load geometries
  TChain *gtree = new TChain("wcsimGeoT");
  gtree->Add(path_wcsim);
  WCSimRootGeom* wcsimrootgeom = new WCSimRootGeom();
  TBranch *branch = gtree->GetBranch("wcsimrootgeom");
  branch->SetAddress(&wcsimrootgeom);
  gtree->GetEntry(0);

  //set the event branch
  TChain *wcsimT = new TChain("wcsimT");
  wcsimT->Add(path_wcsim);
  WCSimRootEvent* wcsimrootevent = new WCSimRootEvent();
  wcsimT->SetBranchAddress("wcsimrootevent",&wcsimrootevent);
  wcsimT->GetBranch("wcsimrootevent")->SetAutoDelete(kTRUE);
  WCSimRootEvent* wcsimrootevent_OD = new WCSimRootEvent();
  wcsimT->SetBranchAddress("wcsimrootevent_OD",&wcsimrootevent_OD);
  wcsimT->GetBranch("wcsimrootevent_OD")->SetAutoDelete(kTRUE);

  
  //=== load fiTQun variables
  TChain *fqtree;
  FQOut *fqv;
  if(is_fq){
    fqtree = new TChain("fiTQun");
    fqtree->Add(path_fq);
    fqv = new FQOut(fqtree);
    
    if(fqtree->GetEntries() != wcsimT->GetEntries()){
      std::cout<<"fqtree->GetEntries() != wcsimT->GetEntries()"<<std::endl;
      std::cout<<"wcsimT->GetEntries() = "<<wcsimT->GetEntries()<<std::endl;
      std::cout<<"fqtree->GetEntries() = "<<fqtree->GetEntries() <<std::endl;
      return 1;
    }  
  }
  
  //=== histograms
  //=== MC true
  TH2F *h_mc_vtx_xz = new TH2F("h_mc_vtx_xz",";X (cm);Z (cm);",100, -500, 500, 100, -500, 500);
  TH2F *h_mc_vtx_zy = new TH2F("h_mc_vtx_zy",";Z (cn);Y (cm);",100, -500, 500, 100, -500, 500);
  TH1F *h_mc_vtx_R = new TH1F("h_mc_vtx_R",";R (cm);Events",100, 0, 500);
  TH1F *h_mc_numom = new TH1F("h_mc_numom",";Momentum (MeV/c);Events",100, 0, 1500);
  TH1F *h_mc_leptonmom = new TH1F("h_mc_leptonmom",";Momentum (MeV/c);Events",100, 0, 1500);
  TH1F *h_mc_nudir = new TH1F("h_mc_nudir",";Angle (degree);Events",100, 0, 180);
  TH1F *h_mc_leptondir = new TH1F("h_mc_leptondir",";Angle (degree);Events;",100, 0, 180);
  TH1F *h_mc_mode = new TH1F("h_mc_mode","",100, 0, 100);
  TH1F *h_mc_hitSumQ_ID = new TH1F("h_mc_hitSumQ_ID",";Total charge (p.e.);Events",100, 0, 100);
  TH1F *h_mc_hitT_ID = new TH1F("h_mc_hitT_ID",";Hittime (ns);Hits",100, 0, 200);
  TH1F *h_mc_hitSumQ_OD = new TH1F("h_mc_hitSumQ_OD",";Total charge (p.e.);Events",1000, 0, 1000);
  TH1F *h_mc_hitT_OD = new TH1F("h_mc_hitT_OD",";Hittime (ns);Hits",100, 0, 1000);
  TH1F *h_mc_Nhit_ID = new TH1F("h_mc_Nhit_ID",";Number of hit PMTs;Events",1000, 0, 1000);
  TH1F *h_mc_Nhit_OD = new TH1F("h_mc_Nhit_OD",";Number of hit PMTs;Events",500, 0, 500);

  TH2F *h_mc_vtx_xz_after_cut = new TH2F("h_mc_vtx_xz_after_cut",";X (cm);Z (cm);",100, -500, 500, 100, -500, 500);
  TH2F *h_mc_vtx_zy_after_cut = new TH2F("h_mc_vtx_zy_after_cut",";Z (cn);Y (cm);",100, -500, 500, 100, -500, 500);

  //=== 1-ring reconstruction
  TH1F *h_fq_diffvtx_e = new TH1F("h_fq_diffvtx_e",";Vertex diff. (cm);Events",50, 0, 100);
  TH1F *h_fq_diffvtx_mu = new TH1F("h_fq_diffvtx_mu",";Vertex diff. (cm);Events",100, 0, 100);
  TH1F *h_fq_diffdir_e = new TH1F("h_fq_diffdir_e",";Direction diff. (degree);Events",45, 0, 45);
  TH1F *h_fq_diffdir_mu = new TH1F("h_fq_diffdir_mu",";Direction diff. (degree);Events",45, 0, 45);
  TH1F *h_fq_diffmom_e = new TH1F("h_fq_diffmom_e",";(reco.-true)/true momentum;Events",100, -1, 1);
  TH1F *h_fq_diffmom_mu = new TH1F("h_fq_diffmom_mu",";(reco.-true)/true momentum;Events",100, -1, 1);
  TH1F *h_fq_pidlikelihood_e = new TH1F("h_fq_pidlikelihood_e","",100, -2000, 2000);
  TH1F *h_fq_pidlikelihood_mu = new TH1F("h_fq_pidlikelihood_mu","",100, -2000, 2000);
  TH2F *h_mc_leptonmom_vs_fq_mom_e = new TH2F("h_mc_leptonmom_vs_fq_mom_e",";True momentum (MeV/c);Reco. momentum (MeV/c);",100, 0, 1500, 100, 0, 1500);
  TH2F *h_mc_leptonmom_vs_fq_mom_mu = new TH2F("h_mc_leptonmom_vs_fq_mom_mu",";True momentum (MeV/c);Reco. momentum (MeV/c);",100, 0, 1500, 100, 0, 1500);

  
  
  //---Get the number of events
  int nevent = wcsimT->GetEntries();
  std::cout<<"event number = "<<nevent<<std::endl;
  
  for (int iev=0; iev<nevent; iev++){
    if(iev%1000==0) std::cout<<"progress: "<<iev<<std::endl;
    //std::cout<<"progress: "<<iev<<std::endl;
    
    //---Read the event from the tree into instance
    wcsimT->GetEntry(iev);
    if(is_fq) fqtree->GetEntry(iev);

    
    //---Get trigger information
    int ntrigger = wcsimrootevent->GetNumberOfEvents();
    int itrigger=0;
    WCSimRootTrigger *wcsimroottrigger = wcsimrootevent->GetTrigger(itrigger);
    //std::cout<<"trigger offset: "<<wcsimroottrigger->GetHeader()->GetDate()<<std::endl;
    
    int ncherenkovdigihits = wcsimroottrigger->GetNcherenkovdigihits();    
    int mode=wcsimroottrigger->GetMode();
    float sumQ=wcsimroottrigger->GetSumQ();
    //float vertex[3]; for(int axis = 0; axis < 3; axis++) vertex[axis] = wcsimroottrigger->GetVtx(axis);
    //std::cout<<"mode: "<<mode<<std::endl;

    //h_mc_mode->Fill(mode);
    h_mc_Nhit_ID->Fill(ncherenkovdigihits);
    h_mc_hitSumQ_ID->Fill(sumQ);
    //h_mc_vtx_xz->Fill(vertex[0], vertex[2]);
    //h_mc_vtx_zy->Fill(vertex[2], vertex[1]);
    //h_mc_vtx_R->Fill(sqrt(vertex[0]*vertex[0] + vertex[2]*vertex[2]));
    //std::cout<<"vertex: "<< wcsimroottrigger->GetVtx(0) <<" "<< wcsimroottrigger->GetVtx(1) <<" "<< wcsimroottrigger->GetVtx(2) <<std::endl;
    
    WCSimRootTrigger *wcsimroottrigger_OD = wcsimrootevent_OD->GetTrigger(0);
    int ncherenkovdigihits_OD = wcsimroottrigger_OD->GetNcherenkovdigihits();    
    float sumQ_OD=wcsimroottrigger_OD->GetSumQ();
    h_mc_Nhit_OD->Fill(ncherenkovdigihits_OD);
    h_mc_hitSumQ_OD->Fill(sumQ_OD);    
    
    bool is_nu = false;
    TVector3 dir_nu;
    float mom_nu;
    bool is_lepton = false;
    TVector3 dir_lepton;
    float mom_lepton;
    TVector3 vertex;
    
    std::vector<int> primary_pid_list;
    
    int ntrack = wcsimroottrigger->GetNtrack();    
    //---Get track information
    for(int itrack=0; itrack<ntrack; itrack++){
      TObject *element = (wcsimroottrigger->GetTracks())->At(itrack);
      WCSimRootTrack *wcsimroottrack = dynamic_cast<WCSimRootTrack*>(element);
      
      int pid = wcsimroottrack->GetIpnu();
      int pid_parent=wcsimroottrack->GetParenttype();
      //float dir[3]; for(int axis = 0; axis<3; axis++) dir[axis] = wcsimroottrack->GetDir(axis);
      //float momentum = wcsimroottrack->GetP();// M is mass, E is kinetic energy, P is momentum(MeV)
      //float Ekin = wcsimroottrack->GetE();// M is mass, E is kinetic energy, P is momentum(MeV)
      //float mass = wcsimroottrack->GetM();
      //std::cout<<itrack<<" "<<momentum<<" "<<Ekin<<" "<<mass<<" "<<pid<<" "<<pid_parent<<" "<< wcsimroottrack->GetTime() <<std::endl;

      bool pid_is_nu = pid == 12 || pid == 14 || pid ==16;
      bool pid_is_lepton = pid == 11 || pid == 13 || pid ==15;
      if(pid_parent==0){
	primary_pid_list.push_back(pid);
	//std::cout<<"parent 0 pid = "<<pid<<std::endl;
      }
      
      if(pid_parent==0 && pid_is_nu){
	is_nu = true;
	for(int axis = 0; axis<3; axis++) dir_nu[axis] = wcsimroottrack->GetDir(axis);
	mom_nu = wcsimroottrack->GetP();
	//std::cout<<"vertex1: "<< wcsimroottrack->GetStart(0) <<" "<< wcsimroottrack->GetStart(1) <<" "<< wcsimroottrack->GetStart(2) <<std::endl;
	for(int axis = 0; axis < 3; axis++) vertex[axis] = wcsimroottrack->GetStart(axis);
	h_mc_vtx_xz->Fill(vertex[0], vertex[2]);
	h_mc_vtx_zy->Fill(vertex[2], vertex[1]);
	h_mc_vtx_R->Fill(sqrt(vertex[0]*vertex[0] + vertex[2]*vertex[2]));
	
      }
      if(pid_parent==0 && pid_is_lepton){
	is_lepton = true;
	for(int axis = 0; axis<3; axis++) dir_lepton[axis] = wcsimroottrack->GetDir(axis);
	mom_lepton = wcsimroottrack->GetP();					    
	//std::cout<<"vertex2: "<< wcsimroottrack->GetStart(0) <<" "<< wcsimroottrack->GetStart(1) <<" "<< wcsimroottrack->GetStart(2) <<std::endl;
      }      
    }

    int Nneutrino=0, Nlepton=0, Nnucleon=0, Ngamma=0, Nother=0;
    int Nelectron=0, Nmuon=0;
    for (int& pid : primary_pid_list) {
      if     (pid==12||pid==14) Nneutrino++;
      else if(pid==11) Nelectron++;
      else if(pid==13) Nmuon++;
      else if(pid==2212||pid==2112) Nnucleon++;
      else if(pid==22) Ngamma++;
      else if(pid==0);
      else Nother++;
    }
    Nlepton = Nelectron + Nmuon;
    bool is_CCQE= Nneutrino==1 && Nlepton==1 && Nnucleon==2 && (Ngamma==0 || Ngamma==1) && Nother==0;
    bool is_nueCCQE= Nelectron==1 && is_CCQE;
    bool is_numuCCQE= Nmuon==1 && is_CCQE;
    if     (is_nueCCQE)  h_mc_mode->Fill(1);
    else if(is_numuCCQE) h_mc_mode->Fill(2);
    else                 h_mc_mode->Fill(3);

    //Fill fiTQun variables

    bool is_PC = ncherenkovdigihits_OD >= 5;
    bool is_IDhit = ncherenkovdigihits >= 5;

    int ie=1, imu=2, ipi=3;
    int isubev=0;

    if(is_fq){
      if(is_nueCCQE && !is_PC && is_IDhit){
	TVector3 fqvtx(fqv->fq1rpos[isubev][ie]);
	float distance_vtx = (vertex - fqvtx).Mag();
	h_fq_diffvtx_e->Fill(distance_vtx);
	TVector3 fqdir(fqv->fq1rdir[isubev][ie]);
	h_fq_diffdir_e->Fill(fqdir.Angle(dir_lepton)*180/3.14);
	float relmom = (fqv->fq1rmom[isubev][ie] - mom_lepton)/mom_lepton;
	h_fq_diffmom_e->Fill(relmom);
	//---pid with smaller nll is selected.
	float pidl = fqv->fq1rnll[isubev][imu] - fqv->fq1rnll[isubev][ie];
	h_fq_pidlikelihood_e->Fill(pidl);
	h_mc_leptonmom_vs_fq_mom_e->Fill(mom_lepton, fqv->fq1rmom[isubev][ie]);
      }
      if(is_numuCCQE && !is_PC && is_IDhit){
	TVector3 fqvtx(fqv->fq1rpos[isubev][imu]);
	float distance_vtx = (vertex - fqvtx).Mag();
	h_fq_diffvtx_mu->Fill(distance_vtx);
	TVector3 fqdir(fqv->fq1rdir[isubev][imu]);
	h_fq_diffdir_mu->Fill(fqdir.Angle(dir_lepton)*180/3.14);
	float relmom = (fqv->fq1rmom[isubev][imu] - mom_lepton)/mom_lepton;
	h_fq_diffmom_mu->Fill(relmom);
	//---pid with smaller nll is selected.
	float pidl = fqv->fq1rnll[isubev][imu] - fqv->fq1rnll[isubev][ie];
	h_fq_pidlikelihood_mu->Fill(pidl);
	h_mc_leptonmom_vs_fq_mom_mu->Fill(mom_lepton, fqv->fq1rmom[isubev][imu]);
      }
      
    }
    
    if( is_CCQE && !is_PC && is_IDhit ){
      h_mc_vtx_xz_after_cut->Fill(vertex[0], vertex[2]);
      h_mc_vtx_zy_after_cut->Fill(vertex[2], vertex[1]);
    }
    
    if(is_nu){
      h_mc_numom->Fill(mom_nu);
      //ROOT::Math::XYZVector zaxis(0,0,1);
      TVector3 zaxis(0,0,1);
      h_mc_nudir->Fill(dir_nu.Angle(zaxis)*180./3.14);
      std::cout<<"debug "<<dir_nu[0]<<" "<<dir_nu[1]<<" "<<dir_nu[2]<<std::endl;
    }
    if(is_lepton){
      h_mc_leptonmom->Fill(mom_lepton);
      if(is_nu) h_mc_leptondir->Fill(dir_lepton.Angle(dir_nu)*180/3.14);
    }    
    
    //---Get ID hit PMT information
    for (int i=0; i<ncherenkovdigihits; i++) {
      WCSimRootCherenkovDigiHit *hit = (WCSimRootCherenkovDigiHit*)(wcsimroottrigger->GetCherenkovDigiHits()->At(i));
      float hittime = hit->GetT();
      float charge = hit->GetQ();
      int tubeId = hit->GetTubeId();
      float pmtpos[3];
      for(int axis = 0; axis < 3; axis++) pmtpos[axis] = wcsimrootgeom->GetPMT(tubeId-1).GetPosition(axis);
      h_mc_hitT_ID->Fill(hittime);
    }
    
    //---Get OD hit PMT information
    for (int i=0; i<ncherenkovdigihits_OD; i++) {
      WCSimRootCherenkovDigiHit *hit = (WCSimRootCherenkovDigiHit*)(wcsimroottrigger_OD->GetCherenkovDigiHits()->At(i));
      float hittime = hit->GetT();
      float charge = hit->GetQ();
      int tubeId = hit->GetTubeId();
      float pmtpos[3];
      for(int axis = 0; axis < 3; axis++) pmtpos[axis] = wcsimrootgeom->GetODPMT(tubeId-1).GetPosition(axis);
      h_mc_hitT_OD->Fill(hittime);
    }
    
  } //// End of loop over events

  //save objects
  if(is_outroot){
    TFile *fout = new TFile(path_outroot,"recreate");
    fout->cd();
    h_mc_vtx_xz->Write();
    h_mc_vtx_zy->Write();
    h_mc_vtx_R->Write();
    h_mc_numom->Write();
    h_mc_leptonmom->Write();
    h_mc_nudir->Write();
    h_mc_leptondir->Write();
    h_mc_mode->Write();
    h_mc_hitSumQ_ID->Write();
    h_mc_hitT_ID->Write();
    h_mc_hitSumQ_OD->Write();
    h_mc_hitT_OD->Write();

    h_mc_vtx_xz_after_cut->Write();
    h_mc_vtx_zy_after_cut->Write();
  
    h_mc_Nhit_ID->Write();
    h_mc_Nhit_OD->Write();

    if(is_fq){
      h_fq_diffvtx_e->Write();
      h_fq_diffvtx_mu->Write();
      h_fq_diffdir_e->Write();
      h_fq_diffdir_mu->Write();
      h_fq_diffmom_e->Write();
      h_fq_diffmom_mu->Write();
      h_fq_pidlikelihood_e->Write();
      h_fq_pidlikelihood_mu->Write();
      h_mc_leptonmom_vs_fq_mom_e->Write();
      h_mc_leptonmom_vs_fq_mom_mu->Write();
    }
    
    fout->Close();
  }
  return 0;
}

