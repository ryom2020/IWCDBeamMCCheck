#include <iostream>
#include <stdio.h>     
#include <stdlib.h>
#include <fstream>

#include "TH1.h"
#include "TH2.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TStyle.h"

#include "TBox.h"
#include "TEllipse.h"


int main(int argc, char* argv[]){  
  gStyle->SetOptStat(0);
  gStyle->SetPadLeftMargin(0.2);
  gStyle->SetPadRightMargin(0.2);
  gStyle->SetPadBottomMargin(0.2);
  
  TFile *fin = new TFile(argv[1],"read");

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
  
  TH2F *h_mc_vtx_xz = (TH2F*)fin->Get("h_mc_vtx_xz");
  h_mc_vtx_xz->Draw("colz");
  te_ID_xz->Draw("same");
  c1->Print("figures/h_mc_vtx_xz.pdf");

  TH2F *h_mc_vtx_zy = (TH2F*)fin->Get("h_mc_vtx_zy");
  h_mc_vtx_zy->Draw("colz");
  tb_ID_zy->Draw("same");
  c1->Print("figures/h_mc_vtx_zy.pdf");

  TH2F *h_mc_vtx_xz_after_cut = (TH2F*)fin->Get("h_mc_vtx_xz_after_cut");
  h_mc_vtx_xz_after_cut->Draw("colz");
  te_ID_xz_after_cut->Draw("same");
  c1->Print("figures/h_mc_vtx_xz_after_cut.pdf");

  TH2F *h_mc_vtx_zy_after_cut = (TH2F*)fin->Get("h_mc_vtx_zy_after_cut");
  h_mc_vtx_zy_after_cut->Draw("colz");
  tb_ID_zy_after_cut->Draw("same");
  c1->Print("figures/h_mc_vtx_zy_after_cut.pdf");

  TH1F *h_mc_vtx_R = (TH1F*)fin->Get("h_mc_vtx_R");
  h_mc_vtx_R->Draw();
  c1->Print("figures/h_mc_vtx_R.pdf");

  TH1F *h_mc_numom = (TH1F*)fin->Get("h_mc_numom");
  h_mc_numom->Draw();
  c1->Print("figures/h_mc_numom.pdf");

  TH1F *h_mc_leptonmom = (TH1F*)fin->Get("h_mc_leptonmom");
  h_mc_leptonmom->Draw();
  c1->Print("figures/h_mc_leptonmom.pdf");

  TH1F *h_mc_nudir = (TH1F*)fin->Get("h_mc_nudir");
  h_mc_nudir->Draw();
  c1->SetLogy(1);
  c1->Print("figures/h_mc_nudir.pdf");
  c1->SetLogy(0);

  TH1F *h_mc_leptondir = (TH1F*)fin->Get("h_mc_leptondir");
  h_mc_leptondir->Draw();
  c1->Print("figures/h_mc_leptondir.pdf");

  TH1F *h_mc_mode = (TH1F*)fin->Get("h_mc_mode");
  h_mc_mode->Draw();
  c1->Print("figures/h_mc_mode.pdf");
  std::cout<<"=== mode "<<std::endl;
  std::cout<<"===     1 "<< h_mc_mode->GetBinContent(1)<<std::endl;
  std::cout<<"===     2 "<< h_mc_mode->GetBinContent(2)<<std::endl;
  std::cout<<"===     3 "<< h_mc_mode->GetBinContent(3)<<std::endl;
  std::cout<<"===     4 "<< h_mc_mode->GetBinContent(4)<<std::endl;
  std::cout<<"===     5 "<< h_mc_mode->GetBinContent(5)<<std::endl;
  
  TH1F *h_mc_hitSumQ_ID = (TH1F*)fin->Get("h_mc_hitSumQ_ID");
  h_mc_hitSumQ_ID->Draw();
  c1->SetLogy(1);
  c1->Print("figures/h_mc_hitSumQ_ID.pdf");
  c1->SetLogy(0);
  
  TH1F *h_mc_hitT_ID = (TH1F*)fin->Get("h_mc_hitT_ID");
  h_mc_hitT_ID->Draw();
  c1->Print("figures/h_mc_hitT_ID.pdf");

  TH1F *h_mc_hitSumQ_OD = (TH1F*)fin->Get("h_mc_hitSumQ_OD");
  h_mc_hitSumQ_OD->Draw();
  c1->SetLogy(1);
  c1->Print("figures/h_mc_hitSumQ_OD.pdf");
  c1->SetLogy(0);

  TH1F *h_mc_hitT_OD = (TH1F*)fin->Get("h_mc_hitT_OD");
  h_mc_hitT_OD->Draw();
  c1->Print("figures/h_mc_hitT_OD.pdf");
  
  TH1F *h_mc_Nhit_ID = (TH1F*)fin->Get("h_mc_Nhit_ID");
  h_mc_Nhit_ID->Draw();
  c1->SetLogy(1);
  c1->Print("figures/h_mc_Nhit_ID.pdf");
  c1->SetLogy(0);
  
  TH1F *h_mc_Nhit_OD = (TH1F*)fin->Get("h_mc_Nhit_OD");
  h_mc_Nhit_OD->Draw();
  c1->SetLogy(1);
  c1->Print("figures/h_mc_Nhit_OD.pdf");
  c1->SetLogy(0);
  
  
  TH1F *h_fq_diffvtx_e = (TH1F*)fin->Get("h_fq_diffvtx_e");
  h_fq_diffvtx_e->Draw();
  c1->Print("figures/h_fq_diffvtx_e.pdf");
  
  TH1F *h_fq_diffvtx_mu = (TH1F*)fin->Get("h_fq_diffvtx_mu");
  h_fq_diffvtx_mu->Draw();
  c1->Print("figures/h_fq_diffvtx_mu.pdf");
  
  TH1F *h_fq_diffdir_e = (TH1F*)fin->Get("h_fq_diffdir_e");
  h_fq_diffdir_e->Draw();
  c1->Print("figures/h_fq_diffdir_e.pdf");

  TH1F *h_fq_diffdir_mu = (TH1F*)fin->Get("h_fq_diffdir_mu");
  h_fq_diffdir_mu->Draw();
  c1->Print("figures/h_fq_diffdir_mu.pdf");

  TH1F *h_fq_diffmom_e = (TH1F*)fin->Get("h_fq_diffmom_e");
  h_fq_diffmom_e->Draw();
  c1->Print("figures/h_fq_diffmom_e.pdf");

  TH1F *h_fq_diffmom_mu = (TH1F*)fin->Get("h_fq_diffmom_mu");
  h_fq_diffmom_mu->Draw();
  c1->Print("figures/h_fq_diffmom_mu.pdf");

  TH1F *h_fq_pidlikelihood_e = (TH1F*)fin->Get("h_fq_pidlikelihood_e");
  h_fq_pidlikelihood_e->Draw();
  c1->Print("figures/h_fq_pidlikelihood_e.pdf");

  TH1F *h_fq_pidlikelihood_mu = (TH1F*)fin->Get("h_fq_pidlikelihood_mu");
  h_fq_pidlikelihood_mu->Draw();
  c1->Print("figures/h_fq_pidlikelihood_mu.pdf");

  TH2F *h_mc_leptonmom_vs_fq_mom_e = (TH2F*)fin->Get("h_mc_leptonmom_vs_fq_mom_e");
  h_mc_leptonmom_vs_fq_mom_e->Draw("colz");
  c1->Print("figures/h_mc_leptonmom_vs_fq_mom_e.pdf");
  
  TH2F *h_mc_leptonmom_vs_fq_mom_mu = (TH2F*)fin->Get("h_mc_leptonmom_vs_fq_mom_mu");
  h_mc_leptonmom_vs_fq_mom_mu->Draw("colz");
  c1->Print("figures/h_mc_leptonmom_vs_fq_mom_mu.pdf");

  return 0;
}

