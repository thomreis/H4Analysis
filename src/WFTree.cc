#include "interface/WFTree.h"

WFTree::WFTree(int nCh, int nSamples, int* idx, TTree* tree, string suffix)
{
    suffix_= suffix;
    tree_ = tree ? tree : new TTree();

    index=idx;
    time_stamp=0;
    WF_samples = nSamples*nCh;
}

void WFTree::Init()
{
    //---set total number of WF samples 
    WF_ch = new int[WF_samples];
    WF_time = new float[WF_samples];
    WF_val = new float[WF_samples];
    //---global branches
    string size_var = "WF_samples"+suffix_;
    tree_->Branch("index", index,"index/I");
    tree_->Branch("time_stamp", &time_stamp, "time_stamp/l");
    tree_->Branch(size_var.c_str(), &WF_samples, (size_var+"/I").c_str());
    tree_->Branch(("WF_ch"+suffix_).c_str(), WF_ch, ("WF_ch"+suffix_+"["+size_var+"]/I").c_str());
    tree_->Branch(("WF_time"+suffix_).c_str(), WF_time, ("WF_time"+suffix_+"["+size_var+"]/F").c_str());
    tree_->Branch(("WF_val"+suffix_).c_str(), WF_val, ("WF_val"+suffix_+"["+size_var+"]/F").c_str());
}

