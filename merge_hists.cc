#include <TFile.h>
#include <TKey.h>
#include <TH1.h>
#include <TClass.h>

#include <iostream>
#include <vector>
int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0]
	      << " output.root input1.root input2.root ..." << std::endl;
    return 1;
  }
  
  std::vector<std::string> inputFiles;
  for (int i = 2; i < argc; ++i) {
    inputFiles.push_back(argv[i]);
  }
  
  TFile *fout = new TFile(argv[1], "RECREATE");
  
  TFile *f0 = TFile::Open(inputFiles[0].c_str());
  TIter next(f0->GetListOfKeys());
  TKey *key;
  
  while ((key = (TKey*)next())) {
    TObject *obj = key->ReadObj();
    if (!obj->InheritsFrom("TH1")) continue;
    
    TH1 *hMerged = (TH1*)obj->Clone();
    hMerged->Reset();
    hMerged->SetDirectory(0);
    
    for (auto &fname : inputFiles) {
      TFile *f = TFile::Open(fname.c_str());
      TH1 *h = (TH1*)f->Get(obj->GetName());
      if (h) hMerged->Add(h);
      f->Close();
    }
    
    fout->cd();
    hMerged->Write();
  }
  
  f0->Close();
  fout->Close();

  return 0;
}
