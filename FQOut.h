//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jan  6 02:04:39 2026 by ROOT version 6.28/06
// from TTree fiTQun/
// found on file: /home/ryom/disk2/HK_beta_prod_IWCD/beta-production/iwcd/prod1A/validation/V01/neut536/t1/wcsim_v1.12.26_cwcs1.0/fitqun_6.4.4_cfqn1.0.0/rfqn/lbl_neut_iwcd_test_00000000-0000_rfqn.root
//////////////////////////////////////////////////////////

#ifndef FQOut_h
#define FQOut_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class FQOut {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           cluster_ncand;
   Float_t         cluster_tstart[3];   //[cluster_ncand]
   Float_t         cluster_tend[3];   //[cluster_ncand]
   Int_t           cluster_nhits[3];   //[cluster_ncand]
   Float_t         cluster_totq[3];   //[cluster_ncand]
   Int_t           cluster_goodflag[3];   //[cluster_ncand]
   Int_t           cluster_npeaks[3][6];   //[cluster_ncand]
   Int_t           cluster_ipeak[3][6][10];   //[cluster_ncand]
   Float_t         cluster_timeofpeak[3][6][10];   //[cluster_ncand]
   Int_t           muechk_ncand[6];
   Float_t         muechk_toya[6];
   Float_t         muechk_tpeak[6][10];
   Int_t           muechk_bg[6][10];
   Float_t         muechk_mean[6][10];
   Float_t         muechk_excess[6][10];
   Float_t         muechk_signif[6][10];
   Int_t           muechk_icluster[6][10];
   Float_t         trgoff;
   Int_t           fqntwnd;
   Int_t           fqtwnd_iclstr[4];   //[fqntwnd]
   Int_t           fqtwnd_npeak[4];   //[fqntwnd]
   Float_t         fqtwnd_prftt0[4];   //[fqntwnd]
   Float_t         fqtwnd_prftpos[4][3];   //[fqntwnd]
   Float_t         fqtwnd[4][2];   //[fqntwnd]
   Float_t         fqtwnd_peakt0[4][10];   //[fqntwnd]
   Float_t         fqtwnd_peakiness[4][10];   //[fqntwnd]
   Int_t           fqnse;
   Int_t           fqitwnd[4];   //[fqnse]
   Int_t           fqipeak[4];   //[fqnse]
   Int_t           fqnhitpmt[4];   //[fqnse]
   Float_t         fqtotq[4];   //[fqnse]
   Float_t         fq0rtotmu[4];   //[fqnse]
   Float_t         fq0rnll[4];   //[fqnse]
   Int_t           fqn50[4];   //[fqnse]
   Float_t         fqq50[4];   //[fqnse]
   Int_t           fq1rpcflg[4][7];   //[fqnse]
   Double_t        fq1rseed[4][7][8];   //[fqnse]
   Float_t         fq1rmom[4][7];   //[fqnse]
   Float_t         fq1rt0[4][7];   //[fqnse]
   Float_t         fq1rtotmu[4][7];   //[fqnse]
   Float_t         fq1rnll[4][7];   //[fqnse]
   Float_t         fq1rpos[4][7][3];   //[fqnse]
   Float_t         fq1rdir[4][7][3];   //[fqnse]
   Float_t         fq1rdconv[4][7];   //[fqnse]
   Float_t         fq1reloss[4][7];   //[fqnse]
   Int_t           fqpi0pcflg[2];
   Float_t         fqpi0mom1[2];
   Float_t         fqpi0mom2[2];
   Float_t         fqpi0momtot[2];
   Float_t         fqpi0dconv1[2];
   Float_t         fqpi0dconv2[2];
   Float_t         fqpi0t0[2];
   Float_t         fqpi0totmu[2];
   Float_t         fqpi0nll[2];
   Float_t         fqpi0mass[2];
   Float_t         fqpi0photangle[2];
   Float_t         fqpi0pos[2][3];
   Float_t         fqpi0dir1[2][3];
   Float_t         fqpi0dir2[2][3];
   Float_t         fqpi0dirtot[2][3];
   Float_t         fq2elecmom1;
   Float_t         fq2elecmom2;
   Float_t         fq2elect0;
   Float_t         fq2electotmu;
   Float_t         fq2elecnll;
   Float_t         fq2elecpos[3];
   Float_t         fq2elecdir[3];
   Int_t           fqnmrfit;
   Int_t           fqmrifit[1];   //[fqnmrfit]
   Int_t           fqmrnring[1];   //[fqnmrfit]
   Int_t           fqmrpcflg[1];   //[fqnmrfit]
   Float_t         fqmrnll[1];   //[fqnmrfit]
   Float_t         fqmrtotmu[1];   //[fqnmrfit]
   Int_t           fqmrpid[1][6];   //[fqnmrfit]
   Float_t         fqmrmom[1][6];   //[fqnmrfit]
   Float_t         fqmrdconv[1][6];   //[fqnmrfit]
   Float_t         fqmreloss[1][6];   //[fqnmrfit]
   Float_t         fqmrt0[1][6];   //[fqnmrfit]
   Float_t         fqmrpos[1][6][3];   //[fqnmrfit]
   Float_t         fqmrdir[1][6][3];   //[fqnmrfit]
   Int_t           fqmsnfit;
   Int_t           fqmspcflg[1];   //[fqmsnfit]
   Int_t           fqmsnseg[1];   //[fqmsnfit]
   Int_t           fqmspid[1];   //[fqmsnfit]
   Int_t           fqmsifit[1];   //[fqmsnfit]
   Int_t           fqmsimer[1];   //[fqmsnfit]
   Float_t         fqmstotmu[1];   //[fqmsnfit]
   Float_t         fqmsnll[1];   //[fqmsnfit]
   Float_t         fqmsmom[1][20];   //[fqmsnfit]
   Float_t         fqmseloss[1][20];   //[fqmsnfit]
   Float_t         fqmst0[1][20];   //[fqmsnfit]
   Float_t         fqmspos[1][20][3];   //[fqmsnfit]
   Float_t         fqmsdir[1][20][3];   //[fqmsnfit]
   Int_t           fqtestn1r;
   Int_t           fqtest1rstage[12];   //[fqtestn1r]
   Int_t           fqtest1rse[12];   //[fqtestn1r]
   Int_t           fqtest1rpid[12];   //[fqtestn1r]
   Int_t           fqtest1rpcflg[12];   //[fqtestn1r]
   Float_t         fqtest1rmom[12];   //[fqtestn1r]
   Float_t         fqtest1rt0[12];   //[fqtestn1r]
   Float_t         fqtest1rtotmu[12];   //[fqtestn1r]
   Float_t         fqtest1rnll[12];   //[fqtestn1r]
   Float_t         fqtest1rpos[12][3];   //[fqtestn1r]
   Float_t         fqtest1rdir[12][3];   //[fqtestn1r]
   Float_t         fqtest1rdconv[12];   //[fqtestn1r]
   Float_t         fqtest1reloss[12];   //[fqtestn1r]
   Int_t           fqtestnpi0;
   Int_t           fqtestpi0stage[2];   //[fqtestnpi0]
   Int_t           fqtestpi0pcflg[2];   //[fqtestnpi0]
   Float_t         fqtestpi0mom1[2];   //[fqtestnpi0]
   Float_t         fqtestpi0mom2[2];   //[fqtestnpi0]
   Float_t         fqtestpi0momtot[2];   //[fqtestnpi0]
   Float_t         fqtestpi0dconv1[2];   //[fqtestnpi0]
   Float_t         fqtestpi0dconv2[2];   //[fqtestnpi0]
   Float_t         fqtestpi0t0[2];   //[fqtestnpi0]
   Float_t         fqtestpi0totmu[2];   //[fqtestnpi0]
   Float_t         fqtestpi0nll[2];   //[fqtestnpi0]
   Float_t         fqtestpi0mass[2];   //[fqtestnpi0]
   Float_t         fqtestpi0photangle[2];   //[fqtestnpi0]
   Float_t         fqtestpi0pos[2][3];   //[fqtestnpi0]
   Float_t         fqtestpi0dir1[2][3];   //[fqtestnpi0]
   Float_t         fqtestpi0dir2[2][3];   //[fqtestnpi0]
   Float_t         fqtestpi0dirtot[2][3];   //[fqtestnpi0]
   Int_t           fqpmgpcflg[2];
   Float_t         fqpmgmom1[2];
   Float_t         fqpmgmom2[2];
   Float_t         fqpmgt01[2];
   Float_t         fqpmgt02[2];
   Float_t         fqpmgtotmu[2];
   Float_t         fqpmgnll[2];
   Float_t         fqpmgpos1[2][3];
   Float_t         fqpmgpos2[2][3];
   Float_t         fqpmgdir1[2][3];
   Float_t         fqpmgdir2[2][3];
   Int_t           ifqver;
   Float_t         fqproctime[20];
   Int_t           nevt;

   // List of branches
   TBranch        *b_cluster_ncand;   //!
   TBranch        *b_cluster_tstart;   //!
   TBranch        *b_cluster_tend;   //!
   TBranch        *b_cluster_nhits;   //!
   TBranch        *b_cluster_totq;   //!
   TBranch        *b_cluster_goodflag;   //!
   TBranch        *b_cluster_npeaks;   //!
   TBranch        *b_cluster_ipeak;   //!
   TBranch        *b_cluster_timeofpeak;   //!
   TBranch        *b_muechk_ncand;   //!
   TBranch        *b_muechk_toya;   //!
   TBranch        *b_muechk_tpeak;   //!
   TBranch        *b_muechk_bg;   //!
   TBranch        *b_muechk_mean;   //!
   TBranch        *b_muechk_excess;   //!
   TBranch        *b_muechk_signif;   //!
   TBranch        *b_muechk_icluster;   //!
   TBranch        *b_trgoff;   //!
   TBranch        *b_fqntwnd;   //!
   TBranch        *b_fqtwnd_iclstr;   //!
   TBranch        *b_fqtwnd_npeak;   //!
   TBranch        *b_fqtwnd_prftt0;   //!
   TBranch        *b_fqtwnd_prftpos;   //!
   TBranch        *b_fqtwnd;   //!
   TBranch        *b_fqtwnd_peakt0;   //!
   TBranch        *b_fqtwnd_peakiness;   //!
   TBranch        *b_fqnse;   //!
   TBranch        *b_fqitwnd;   //!
   TBranch        *b_fqipeak;   //!
   TBranch        *b_fqnhitpmt;   //!
   TBranch        *b_fqtotq;   //!
   TBranch        *b_fq0rtotmu;   //!
   TBranch        *b_fq0rnll;   //!
   TBranch        *b_fqn50;   //!
   TBranch        *b_fqq50;   //!
   TBranch        *b_fq1rpcflg;   //!
   TBranch        *b_fq1rseed;   //!
   TBranch        *b_fq1rmom;   //!
   TBranch        *b_fq1rt0;   //!
   TBranch        *b_fq1rtotmu;   //!
   TBranch        *b_fq1rnll;   //!
   TBranch        *b_fq1rpos;   //!
   TBranch        *b_fq1rdir;   //!
   TBranch        *b_fq1rdconv;   //!
   TBranch        *b_fq1reloss;   //!
   TBranch        *b_fqpi0pcflg;   //!
   TBranch        *b_fqpi0mom1;   //!
   TBranch        *b_fqpi0mom2;   //!
   TBranch        *b_fqpi0momtot;   //!
   TBranch        *b_fqpi0dconv1;   //!
   TBranch        *b_fqpi0dconv2;   //!
   TBranch        *b_fqpi0t0;   //!
   TBranch        *b_fqpi0totmu;   //!
   TBranch        *b_fqpi0nll;   //!
   TBranch        *b_fqpi0mass;   //!
   TBranch        *b_fqpi0photangle;   //!
   TBranch        *b_fqpi0pos;   //!
   TBranch        *b_fqpi0dir1;   //!
   TBranch        *b_fqpi0dir2;   //!
   TBranch        *b_fqpi0dirtot;   //!
   TBranch        *b_fq2elecmom1;   //!
   TBranch        *b_fq2elecmom2;   //!
   TBranch        *b_fq2elect0;   //!
   TBranch        *b_fq2electotmu;   //!
   TBranch        *b_fq2elecnll;   //!
   TBranch        *b_fq2elecpos;   //!
   TBranch        *b_fq2elecdir;   //!
   TBranch        *b_fqnmrfit;   //!
   TBranch        *b_fqmrifit;   //!
   TBranch        *b_fqmrnring;   //!
   TBranch        *b_fqmrpcflg;   //!
   TBranch        *b_fqmrnll;   //!
   TBranch        *b_fqmrtotmu;   //!
   TBranch        *b_fqmrpid;   //!
   TBranch        *b_fqmrmom;   //!
   TBranch        *b_fqmrdconv;   //!
   TBranch        *b_fqmreloss;   //!
   TBranch        *b_fqmrt0;   //!
   TBranch        *b_fqmrpos;   //!
   TBranch        *b_fqmrdir;   //!
   TBranch        *b_fqmsnfit;   //!
   TBranch        *b_fqmspcflg;   //!
   TBranch        *b_fqmsnseg;   //!
   TBranch        *b_fqmspid;   //!
   TBranch        *b_fqmsifit;   //!
   TBranch        *b_fqmsimer;   //!
   TBranch        *b_fqmstotmu;   //!
   TBranch        *b_fqmsnll;   //!
   TBranch        *b_fqmsmom;   //!
   TBranch        *b_fqmseloss;   //!
   TBranch        *b_fqmst0;   //!
   TBranch        *b_fqmspos;   //!
   TBranch        *b_fqmsdir;   //!
   TBranch        *b_fqtestn1r;   //!
   TBranch        *b_fqtest1rstage;   //!
   TBranch        *b_fqtest1rse;   //!
   TBranch        *b_fqtest1rpid;   //!
   TBranch        *b_fqtest1rpcflg;   //!
   TBranch        *b_fqtest1rmom;   //!
   TBranch        *b_fqtest1rt0;   //!
   TBranch        *b_fqtest1rtotmu;   //!
   TBranch        *b_fqtest1rnll;   //!
   TBranch        *b_fqtest1rpos;   //!
   TBranch        *b_fqtest1rdir;   //!
   TBranch        *b_fqtest1rdconv;   //!
   TBranch        *b_fqtest1reloss;   //!
   TBranch        *b_fqtestnpi0;   //!
   TBranch        *b_fqtestpi0stage;   //!
   TBranch        *b_fqtestpi0pcflg;   //!
   TBranch        *b_fqtestpi0mom1;   //!
   TBranch        *b_fqtestpi0mom2;   //!
   TBranch        *b_fqtestpi0momtot;   //!
   TBranch        *b_fqtestpi0dconv1;   //!
   TBranch        *b_fqtestpi0dconv2;   //!
   TBranch        *b_fqtestpi0t0;   //!
   TBranch        *b_fqtestpi0totmu;   //!
   TBranch        *b_fqtestpi0nll;   //!
   TBranch        *b_fqtestpi0mass;   //!
   TBranch        *b_fqtestpi0photangle;   //!
   TBranch        *b_fqtestpi0pos;   //!
   TBranch        *b_fqtestpi0dir1;   //!
   TBranch        *b_fqtestpi0dir2;   //!
   TBranch        *b_fqtestpi0dirtot;   //!
   TBranch        *b_fqpmgpcflg;   //!
   TBranch        *b_fqpmgmom1;   //!
   TBranch        *b_fqpmgmom2;   //!
   TBranch        *b_fqpmgt01;   //!
   TBranch        *b_fqpmgt02;   //!
   TBranch        *b_fqpmgtotmu;   //!
   TBranch        *b_fqpmgnll;   //!
   TBranch        *b_fqpmgpos1;   //!
   TBranch        *b_fqpmgpos2;   //!
   TBranch        *b_fqpmgdir1;   //!
   TBranch        *b_fqpmgdir2;   //!
   TBranch        *b_ifqver;   //!
   TBranch        *b_fqproctime;   //!
   TBranch        *b_nevt;   //!

   FQOut(TTree *tree=0);
   virtual ~FQOut();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef FQOut_cxx
FQOut::FQOut(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/home/ryom/disk2/HK_beta_prod_IWCD/beta-production/iwcd/prod1A/validation/V01/neut536/t1/wcsim_v1.12.26_cwcs1.0/fitqun_6.4.4_cfqn1.0.0/rfqn/lbl_neut_iwcd_test_00000000-0000_rfqn.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/home/ryom/disk2/HK_beta_prod_IWCD/beta-production/iwcd/prod1A/validation/V01/neut536/t1/wcsim_v1.12.26_cwcs1.0/fitqun_6.4.4_cfqn1.0.0/rfqn/lbl_neut_iwcd_test_00000000-0000_rfqn.root");
      }
      f->GetObject("fiTQun",tree);

   }
   Init(tree);
}

FQOut::~FQOut()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t FQOut::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t FQOut::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void FQOut::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("cluster_ncand", &cluster_ncand, &b_cluster_ncand);
   fChain->SetBranchAddress("cluster_tstart", cluster_tstart, &b_cluster_tstart);
   fChain->SetBranchAddress("cluster_tend", cluster_tend, &b_cluster_tend);
   fChain->SetBranchAddress("cluster_nhits", cluster_nhits, &b_cluster_nhits);
   fChain->SetBranchAddress("cluster_totq", cluster_totq, &b_cluster_totq);
   fChain->SetBranchAddress("cluster_goodflag", cluster_goodflag, &b_cluster_goodflag);
   fChain->SetBranchAddress("cluster_npeaks", cluster_npeaks, &b_cluster_npeaks);
   fChain->SetBranchAddress("cluster_ipeak", cluster_ipeak, &b_cluster_ipeak);
   fChain->SetBranchAddress("cluster_timeofpeak", cluster_timeofpeak, &b_cluster_timeofpeak);
   fChain->SetBranchAddress("muechk_ncand", muechk_ncand, &b_muechk_ncand);
   fChain->SetBranchAddress("muechk_toya", muechk_toya, &b_muechk_toya);
   fChain->SetBranchAddress("muechk_tpeak", muechk_tpeak, &b_muechk_tpeak);
   fChain->SetBranchAddress("muechk_bg", muechk_bg, &b_muechk_bg);
   fChain->SetBranchAddress("muechk_mean", muechk_mean, &b_muechk_mean);
   fChain->SetBranchAddress("muechk_excess", muechk_excess, &b_muechk_excess);
   fChain->SetBranchAddress("muechk_signif", muechk_signif, &b_muechk_signif);
   fChain->SetBranchAddress("muechk_icluster", muechk_icluster, &b_muechk_icluster);
   fChain->SetBranchAddress("trgoff", &trgoff, &b_trgoff);
   fChain->SetBranchAddress("fqntwnd", &fqntwnd, &b_fqntwnd);
   fChain->SetBranchAddress("fqtwnd_iclstr", fqtwnd_iclstr, &b_fqtwnd_iclstr);
   fChain->SetBranchAddress("fqtwnd_npeak", fqtwnd_npeak, &b_fqtwnd_npeak);
   fChain->SetBranchAddress("fqtwnd_prftt0", fqtwnd_prftt0, &b_fqtwnd_prftt0);
   fChain->SetBranchAddress("fqtwnd_prftpos", fqtwnd_prftpos, &b_fqtwnd_prftpos);
   fChain->SetBranchAddress("fqtwnd", fqtwnd, &b_fqtwnd);
   fChain->SetBranchAddress("fqtwnd_peakt0", fqtwnd_peakt0, &b_fqtwnd_peakt0);
   fChain->SetBranchAddress("fqtwnd_peakiness", fqtwnd_peakiness, &b_fqtwnd_peakiness);
   fChain->SetBranchAddress("fqnse", &fqnse, &b_fqnse);
   fChain->SetBranchAddress("fqitwnd", fqitwnd, &b_fqitwnd);
   fChain->SetBranchAddress("fqipeak", fqipeak, &b_fqipeak);
   fChain->SetBranchAddress("fqnhitpmt", fqnhitpmt, &b_fqnhitpmt);
   fChain->SetBranchAddress("fqtotq", fqtotq, &b_fqtotq);
   fChain->SetBranchAddress("fq0rtotmu", fq0rtotmu, &b_fq0rtotmu);
   fChain->SetBranchAddress("fq0rnll", fq0rnll, &b_fq0rnll);
   fChain->SetBranchAddress("fqn50", fqn50, &b_fqn50);
   fChain->SetBranchAddress("fqq50", fqq50, &b_fqq50);
   fChain->SetBranchAddress("fq1rpcflg", fq1rpcflg, &b_fq1rpcflg);
   fChain->SetBranchAddress("fq1rseed", fq1rseed, &b_fq1rseed);
   fChain->SetBranchAddress("fq1rmom", fq1rmom, &b_fq1rmom);
   fChain->SetBranchAddress("fq1rt0", fq1rt0, &b_fq1rt0);
   fChain->SetBranchAddress("fq1rtotmu", fq1rtotmu, &b_fq1rtotmu);
   fChain->SetBranchAddress("fq1rnll", fq1rnll, &b_fq1rnll);
   fChain->SetBranchAddress("fq1rpos", fq1rpos, &b_fq1rpos);
   fChain->SetBranchAddress("fq1rdir", fq1rdir, &b_fq1rdir);
   fChain->SetBranchAddress("fq1rdconv", fq1rdconv, &b_fq1rdconv);
   fChain->SetBranchAddress("fq1reloss", fq1reloss, &b_fq1reloss);
   fChain->SetBranchAddress("fqpi0pcflg", fqpi0pcflg, &b_fqpi0pcflg);
   fChain->SetBranchAddress("fqpi0mom1", fqpi0mom1, &b_fqpi0mom1);
   fChain->SetBranchAddress("fqpi0mom2", fqpi0mom2, &b_fqpi0mom2);
   fChain->SetBranchAddress("fqpi0momtot", fqpi0momtot, &b_fqpi0momtot);
   fChain->SetBranchAddress("fqpi0dconv1", fqpi0dconv1, &b_fqpi0dconv1);
   fChain->SetBranchAddress("fqpi0dconv2", fqpi0dconv2, &b_fqpi0dconv2);
   fChain->SetBranchAddress("fqpi0t0", fqpi0t0, &b_fqpi0t0);
   fChain->SetBranchAddress("fqpi0totmu", fqpi0totmu, &b_fqpi0totmu);
   fChain->SetBranchAddress("fqpi0nll", fqpi0nll, &b_fqpi0nll);
   fChain->SetBranchAddress("fqpi0mass", fqpi0mass, &b_fqpi0mass);
   fChain->SetBranchAddress("fqpi0photangle", fqpi0photangle, &b_fqpi0photangle);
   fChain->SetBranchAddress("fqpi0pos", fqpi0pos, &b_fqpi0pos);
   fChain->SetBranchAddress("fqpi0dir1", fqpi0dir1, &b_fqpi0dir1);
   fChain->SetBranchAddress("fqpi0dir2", fqpi0dir2, &b_fqpi0dir2);
   fChain->SetBranchAddress("fqpi0dirtot", fqpi0dirtot, &b_fqpi0dirtot);
   fChain->SetBranchAddress("fq2elecmom1", &fq2elecmom1, &b_fq2elecmom1);
   fChain->SetBranchAddress("fq2elecmom2", &fq2elecmom2, &b_fq2elecmom2);
   fChain->SetBranchAddress("fq2elect0", &fq2elect0, &b_fq2elect0);
   fChain->SetBranchAddress("fq2electotmu", &fq2electotmu, &b_fq2electotmu);
   fChain->SetBranchAddress("fq2elecnll", &fq2elecnll, &b_fq2elecnll);
   fChain->SetBranchAddress("fq2elecpos", fq2elecpos, &b_fq2elecpos);
   fChain->SetBranchAddress("fq2elecdir", fq2elecdir, &b_fq2elecdir);
   fChain->SetBranchAddress("fqnmrfit", &fqnmrfit, &b_fqnmrfit);
   fChain->SetBranchAddress("fqmrifit", &fqmrifit, &b_fqmrifit);
   fChain->SetBranchAddress("fqmrnring", &fqmrnring, &b_fqmrnring);
   fChain->SetBranchAddress("fqmrpcflg", &fqmrpcflg, &b_fqmrpcflg);
   fChain->SetBranchAddress("fqmrnll", &fqmrnll, &b_fqmrnll);
   fChain->SetBranchAddress("fqmrtotmu", &fqmrtotmu, &b_fqmrtotmu);
   fChain->SetBranchAddress("fqmrpid", &fqmrpid, &b_fqmrpid);
   fChain->SetBranchAddress("fqmrmom", &fqmrmom, &b_fqmrmom);
   fChain->SetBranchAddress("fqmrdconv", &fqmrdconv, &b_fqmrdconv);
   fChain->SetBranchAddress("fqmreloss", &fqmreloss, &b_fqmreloss);
   fChain->SetBranchAddress("fqmrt0", &fqmrt0, &b_fqmrt0);
   fChain->SetBranchAddress("fqmrpos", &fqmrpos, &b_fqmrpos);
   fChain->SetBranchAddress("fqmrdir", &fqmrdir, &b_fqmrdir);
   fChain->SetBranchAddress("fqmsnfit", &fqmsnfit, &b_fqmsnfit);
   fChain->SetBranchAddress("fqmspcflg", fqmspcflg, &b_fqmspcflg);
   fChain->SetBranchAddress("fqmsnseg", fqmsnseg, &b_fqmsnseg);
   fChain->SetBranchAddress("fqmspid", fqmspid, &b_fqmspid);
   fChain->SetBranchAddress("fqmsifit", fqmsifit, &b_fqmsifit);
   fChain->SetBranchAddress("fqmsimer", fqmsimer, &b_fqmsimer);
   fChain->SetBranchAddress("fqmstotmu", fqmstotmu, &b_fqmstotmu);
   fChain->SetBranchAddress("fqmsnll", fqmsnll, &b_fqmsnll);
   fChain->SetBranchAddress("fqmsmom", fqmsmom, &b_fqmsmom);
   fChain->SetBranchAddress("fqmseloss", fqmseloss, &b_fqmseloss);
   fChain->SetBranchAddress("fqmst0", fqmst0, &b_fqmst0);
   fChain->SetBranchAddress("fqmspos", fqmspos, &b_fqmspos);
   fChain->SetBranchAddress("fqmsdir", fqmsdir, &b_fqmsdir);
   fChain->SetBranchAddress("fqtestn1r", &fqtestn1r, &b_fqtestn1r);
   fChain->SetBranchAddress("fqtest1rstage", fqtest1rstage, &b_fqtest1rstage);
   fChain->SetBranchAddress("fqtest1rse", fqtest1rse, &b_fqtest1rse);
   fChain->SetBranchAddress("fqtest1rpid", fqtest1rpid, &b_fqtest1rpid);
   fChain->SetBranchAddress("fqtest1rpcflg", fqtest1rpcflg, &b_fqtest1rpcflg);
   fChain->SetBranchAddress("fqtest1rmom", fqtest1rmom, &b_fqtest1rmom);
   fChain->SetBranchAddress("fqtest1rt0", fqtest1rt0, &b_fqtest1rt0);
   fChain->SetBranchAddress("fqtest1rtotmu", fqtest1rtotmu, &b_fqtest1rtotmu);
   fChain->SetBranchAddress("fqtest1rnll", fqtest1rnll, &b_fqtest1rnll);
   fChain->SetBranchAddress("fqtest1rpos", fqtest1rpos, &b_fqtest1rpos);
   fChain->SetBranchAddress("fqtest1rdir", fqtest1rdir, &b_fqtest1rdir);
   fChain->SetBranchAddress("fqtest1rdconv", fqtest1rdconv, &b_fqtest1rdconv);
   fChain->SetBranchAddress("fqtest1reloss", fqtest1reloss, &b_fqtest1reloss);
   fChain->SetBranchAddress("fqtestnpi0", &fqtestnpi0, &b_fqtestnpi0);
   fChain->SetBranchAddress("fqtestpi0stage", fqtestpi0stage, &b_fqtestpi0stage);
   fChain->SetBranchAddress("fqtestpi0pcflg", fqtestpi0pcflg, &b_fqtestpi0pcflg);
   fChain->SetBranchAddress("fqtestpi0mom1", fqtestpi0mom1, &b_fqtestpi0mom1);
   fChain->SetBranchAddress("fqtestpi0mom2", fqtestpi0mom2, &b_fqtestpi0mom2);
   fChain->SetBranchAddress("fqtestpi0momtot", fqtestpi0momtot, &b_fqtestpi0momtot);
   fChain->SetBranchAddress("fqtestpi0dconv1", fqtestpi0dconv1, &b_fqtestpi0dconv1);
   fChain->SetBranchAddress("fqtestpi0dconv2", fqtestpi0dconv2, &b_fqtestpi0dconv2);
   fChain->SetBranchAddress("fqtestpi0t0", fqtestpi0t0, &b_fqtestpi0t0);
   fChain->SetBranchAddress("fqtestpi0totmu", fqtestpi0totmu, &b_fqtestpi0totmu);
   fChain->SetBranchAddress("fqtestpi0nll", fqtestpi0nll, &b_fqtestpi0nll);
   fChain->SetBranchAddress("fqtestpi0mass", fqtestpi0mass, &b_fqtestpi0mass);
   fChain->SetBranchAddress("fqtestpi0photangle", fqtestpi0photangle, &b_fqtestpi0photangle);
   fChain->SetBranchAddress("fqtestpi0pos", fqtestpi0pos, &b_fqtestpi0pos);
   fChain->SetBranchAddress("fqtestpi0dir1", fqtestpi0dir1, &b_fqtestpi0dir1);
   fChain->SetBranchAddress("fqtestpi0dir2", fqtestpi0dir2, &b_fqtestpi0dir2);
   fChain->SetBranchAddress("fqtestpi0dirtot", fqtestpi0dirtot, &b_fqtestpi0dirtot);
   fChain->SetBranchAddress("fqpmgpcflg", fqpmgpcflg, &b_fqpmgpcflg);
   fChain->SetBranchAddress("fqpmgmom1", fqpmgmom1, &b_fqpmgmom1);
   fChain->SetBranchAddress("fqpmgmom2", fqpmgmom2, &b_fqpmgmom2);
   fChain->SetBranchAddress("fqpmgt01", fqpmgt01, &b_fqpmgt01);
   fChain->SetBranchAddress("fqpmgt02", fqpmgt02, &b_fqpmgt02);
   fChain->SetBranchAddress("fqpmgtotmu", fqpmgtotmu, &b_fqpmgtotmu);
   fChain->SetBranchAddress("fqpmgnll", fqpmgnll, &b_fqpmgnll);
   fChain->SetBranchAddress("fqpmgpos1", fqpmgpos1, &b_fqpmgpos1);
   fChain->SetBranchAddress("fqpmgpos2", fqpmgpos2, &b_fqpmgpos2);
   fChain->SetBranchAddress("fqpmgdir1", fqpmgdir1, &b_fqpmgdir1);
   fChain->SetBranchAddress("fqpmgdir2", fqpmgdir2, &b_fqpmgdir2);
   fChain->SetBranchAddress("ifqver", &ifqver, &b_ifqver);
   fChain->SetBranchAddress("fqproctime", fqproctime, &b_fqproctime);
   fChain->SetBranchAddress("nevt", &nevt, &b_nevt);
   Notify();
}

Bool_t FQOut::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void FQOut::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t FQOut::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef FQOut_cxx
