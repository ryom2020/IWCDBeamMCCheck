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
//#include "Math/Vector3D.h"
#include "TVector3.h"

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

/*
void Angles(float fit_dir[3], float &theta, float &phi){
  theta = TMath::ACos(fit_dir[2]);
  phi = TMath::Sign(1.0, fit_dir[1]) * TMath::ACos( fit_dir[0]/sqrt(pow(fit_dir[0],2)+pow(fit_dir[1],2)) );
}
*/

float GetNorm(float x, float y, float z){
  float n = sqrt(x*x + y*y + z*z);
  return n;
}
float GetAngleCos(float x1, float y1, float z1, float x2, float y2, float z2){
  float n1 = GetNorm(x1, y1, z1);
  float n2 = GetNorm(x2, y2, z2);
  float cos = (x1*x2 + y1*y2 + z1*z2)/n1/n2;
  return cos;
}
float GetAngleDegree(float x1, float y1, float z1, float x2, float y2, float z2){
}


int main(int argc, char* argv[]){  
  //gSystem->Load("libTree.so");
  gStyle->SetOptStat(0);

  // /home/ryom/disk2/HK_beta_prod_IWCD/beta-production/iwcd/prod1A/validation/V01/neut536/t1/wcsim_v1.12.26_cwcs1.0/rwcs/
  // /home/ryom/disk2/HK_beta_prod_IWCD/beta-production/iwcd/prod1A/validation/V01/neut536/t1/wcsim_v1.12.26_cwcs1.0/fitqun_6.4.4_cfqn1.0.0/rfqn

  //char* path = "/home/ryom/disk2/HK_beta_prod_IWCD/beta-production/iwcd/prod1A/validation/V01/neut536/t1/wcsim_v1.12.26_cwcs1.0/rwcs/lbl_neut_iwcd_test_00000000-0000_rwcs.root";
  char* path = "/home/ryom/disk2/HK_beta_prod_IWCD/beta-production/iwcd/prod1A/validation/V01/neut536/t1/wcsim_v1.12.26_cwcs1.0/rwcs/lbl_neut_iwcd_test_00000000-*_rwcs.root";
  std::cout<<path<<std::endl;
  
  //=== load geometries
  TChain *gtree = new TChain("wcsimGeoT");
  gtree->Add(path);
  WCSimRootGeom* wcsimrootgeom = new WCSimRootGeom();
  TBranch *branch = gtree->GetBranch("wcsimrootgeom");
  branch->SetAddress(&wcsimrootgeom);
  gtree->GetEntry(0);

  //set the event branch
  TChain *wcsimT = new TChain("wcsimT");
  wcsimT->Add(path);
  WCSimRootEvent* wcsimrootevent = new WCSimRootEvent();
  wcsimT->SetBranchAddress("wcsimrootevent",&wcsimrootevent);
  wcsimT->GetBranch("wcsimrootevent")->SetAutoDelete(kTRUE);
  WCSimRootEvent* wcsimrootevent_OD = new WCSimRootEvent();
  wcsimT->SetBranchAddress("wcsimrootevent_OD",&wcsimrootevent_OD);
  wcsimT->GetBranch("wcsimrootevent_OD")->SetAutoDelete(kTRUE);

  
  //--- histograms
  TH2F *h_mc_vtx_xz = new TH2F("h_mc_vtx_xz","",100, -500, 500, 100, -500, 500);
  TH2F *h_mc_vtx_zy = new TH2F("h_mc_vtx_zy","",100, -500, 500, 100, -500, 500);
  TH1F *h_mc_vtx_R = new TH1F("h_mc_vtx_R","",100, 0, 500);
  TH1F *h_mc_numom = new TH1F("h_mc_numom","",100, 0, 1000);
  TH1F *h_mc_leptonmom = new TH1F("h_mc_leptonmom","",100, 0, 1000);
  TH1F *h_mc_nudir = new TH1F("h_mc_nudir","",100, 0, 90);
  TH1F *h_mc_leptondir = new TH1F("h_mc_leptondir","",100, 0, 90);
  TH1F *h_mc_mode = new TH1F("h_mc_mode","",100, 0, 100);
  TH1F *h_mc_hitSumQ_ID = new TH1F("h_mc_hitSumQ_ID","",100, 0, 1000);
  TH1F *h_mc_hitT_ID = new TH1F("h_mc_hitT_ID","",100, 0, 3000);
  TH1F *h_mc_hitSumQ_OD = new TH1F("h_mc_hitSumQ_OD","",100, 0, 1000);
  TH1F *h_mc_hitT_OD = new TH1F("h_mc_hitT_OD","",100, 0, 3000);

  
  //---Get the number of events
  int nevent = wcsimT->GetEntries();
  std::cout<<"event number = "<<nevent<<std::endl;
  
  for (int iev=0; iev<nevent; iev++){
    if(iev%1000==0) std::cout<<"progress: "<<iev<<std::endl;
    
    //---Read the event from the tree into instance
    wcsimT->GetEvent(iev);
    
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
    h_mc_hitSumQ_ID->Fill(sumQ);
    //h_mc_vtx_xz->Fill(vertex[0], vertex[2]);
    //h_mc_vtx_zy->Fill(vertex[2], vertex[1]);
    //h_mc_vtx_R->Fill(sqrt(vertex[0]*vertex[0] + vertex[2]*vertex[2]));
    //std::cout<<"vertex: "<< wcsimroottrigger->GetVtx(0) <<" "<< wcsimroottrigger->GetVtx(1) <<" "<< wcsimroottrigger->GetVtx(2) <<std::endl;
    
    WCSimRootTrigger *wcsimroottrigger_OD = wcsimrootevent_OD->GetTrigger(0);
    int ncherenkovdigihits_OD = wcsimroottrigger_OD->GetNcherenkovdigihits();    
    float sumQ_OD=wcsimroottrigger_OD->GetSumQ();
    h_mc_hitSumQ_OD->Fill(sumQ_OD);
    

    //if(true_mode!=1) continue;

    bool is_nu = false;
    //ROOT::Math::XYZVector dir_nu;
    TVector3 dir_nu;
    float mom_nu;
    bool is_lepton = false;
    //ROOT::Math::XYZVector dir_lepton;
    TVector3 dir_lepton;
    float mom_lepton;
    
    int ntrack = wcsimroottrigger->GetNtrack();    
    //---Get track information
    for(int itrack=0; itrack<ntrack; itrack++){
      TObject *element = (wcsimroottrigger->GetTracks())->At(itrack);
      WCSimRootTrack *wcsimroottrack = dynamic_cast<WCSimRootTrack*>(element);
      
      int pid = wcsimroottrack->GetIpnu();
      int pid_parent=wcsimroottrack->GetParenttype();
      float dir[3]; for(int axis = 0; axis<3; axis++) dir[axis] = wcsimroottrack->GetDir(axis);
      float momentum = wcsimroottrack->GetP();// M is mass, E is kinetic energy, P is momentum(MeV)
      float Ekin = wcsimroottrack->GetE();// M is mass, E is kinetic energy, P is momentum(MeV)
      float mass = wcsimroottrack->GetM();
      //std::cout<<itrack<<" "<<momentum<<" "<<Ekin<<" "<<mass<<" "<<pid<<" "<<pid_parent<<" "<< wcsimroottrack->GetTime() <<std::endl;

      bool pid_is_nu = pid == 12 || pid == 14 || pid ==16;
      bool pid_is_lepton = pid == 11 || pid == 13 || pid ==15;

      if(pid_parent==0 && pid_is_nu){
	is_nu = true;
	for(int axis = 0; axis<3; axis++) dir_nu[axis] = wcsimroottrack->GetDir(axis);
	mom_nu = wcsimroottrack->GetP();
	//std::cout<<"vertex1: "<< wcsimroottrack->GetStart(0) <<" "<< wcsimroottrack->GetStart(1) <<" "<< wcsimroottrack->GetStart(2) <<std::endl;
	float vertex[3]; for(int axis = 0; axis < 3; axis++) vertex[axis] = wcsimroottrack->GetStart(axis);
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

    
    if(is_nu){
      h_mc_numom->Fill(mom_nu);
      //ROOT::Math::XYZVector zaxis(0,0,1);
      TVector3 zaxis(0,0,1);
      h_mc_nudir->Fill(dir_nu.Angle(zaxis)*180./3.14);
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
  
  //TFile *outfile = new TFile("Hist.root","recreate");
  TCanvas *c1 = new TCanvas("c1","",600,600);
  float IDZ = 400.;//cm
  float IDR = 350.;//cm
  TEllipse *te_ID_xz = new TEllipse(0,0,IDR);
  te_ID_xz->SetFillStyle(0);
  te_ID_xz->SetLineColor(1);
  te_ID_xz->SetLineWidth(3);
  TBox *tb_ID_zy = new TBox(-IDR, -IDZ, IDR, IDZ);  
  tb_ID_zy->SetFillStyle(0);
  tb_ID_zy->SetLineColor(1);
  tb_ID_zy->SetLineWidth(3);
  
  h_mc_vtx_xz->Draw("colz");
  te_ID_xz->Draw("same");
  c1->Print("figures/h_mc_vtx_xz.pdf");

  h_mc_vtx_zy->Draw("colz");
  tb_ID_zy->Draw("same");
  c1->Print("figures/h_mc_vtx_zy.pdf");

  h_mc_vtx_R->Draw();
  c1->Print("figures/h_mc_vtx_R.pdf");
  h_mc_numom->Draw();
  c1->Print("figures/h_mc_numom.pdf");
  h_mc_leptonmom->Draw();
  c1->Print("figures/h_mc_leptonmom.pdf");
  h_mc_nudir->Draw();
  c1->Print("figures/h_mc_nudir.pdf");
  h_mc_leptondir->Draw();
  c1->Print("figures/h_mc_leptondir.pdf");
  //h_mc_mode->Draw();
  h_mc_hitSumQ_ID->Draw();
  c1->Print("figures/h_mc_hitSumQ_ID.pdf");
  h_mc_hitT_ID->Draw();
  c1->Print("figures/h_mc_hitT_ID.pdf");
  h_mc_hitSumQ_OD->Draw();
  c1->Print("figures/h_mc_hitSumQ_OD.pdf");
  h_mc_hitT_OD->Draw();
  c1->Print("figures/h_mc_hitT_OD.pdf");

  
  return 0;
}

