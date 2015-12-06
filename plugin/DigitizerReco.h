#ifndef __DIGITIZER_RECO__
#define __DIGITIZER_RECO__

#include <iostream>

#include "plugin/PluginBase.h"
#include "interface/RecoTree.h"
#include "interface/WFTree.h"
#include "interface/WFClass.h"
#include "interface/WFClassNINO.h"
#include "interface/WFViewer.h"

class DigitizerReco: public PluginBase
{
public:
    //---ctors---
    DigitizerReco(){};

    //---dtor---
    ~DigitizerReco(){};

    //---utils---
    bool Begin(CfgManager& opts, int* index);
    bool ProcessEvent(const H4Tree& event, CfgManager& opts);
    
private:    
    //---internal data
    int                         nSamples_;
    float                       tUnit_;
    vector<string>              channelsNames_;
    map<string, vector<float> > timeOpts_;
    RecoTree                    recoTree_;
    WFTree                      outWFTree_;
    map<string, WFClass*>       WFs;
    map<string, WFViewer>       WFViewers;
    map<string, TH1*>           templates;

    //---datamember for registration
    PLUGIN_REGISTER(DigitizerReco)
};

DEFINE_PLUGIN(DigitizerReco);

#endif
