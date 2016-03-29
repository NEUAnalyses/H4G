// -*- C++ -*-
//
// Package:    H4G/H4GSelector
// Class:      H4GSelector
// 
/**\class H4GSelector H4GSelector.cc H4G/H4GSelector/plugins/H4GSelector.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Rafael Teixeira De Lima
//         Created:  Sat, 26 Mar 2016 16:30:02 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

//my includes
#include <memory>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <utility>
#include <cmath>
#include "TTree.h"
#include "TFile.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/PatCandidates/interface/PackedGenParticle.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"
#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/PatCandidates/interface/Photon.h"
#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/PatCandidates/interface/VIDCutFlowResult.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/Math/interface/deltaR.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#ifdef _CINT_
#pragma link C++ class std::vector<std::map<std::string,float>>;
#pragma link C++ class std::vector<std::map<std::string,int>>;
#endif

//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class H4GSelector : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit H4GSelector(const edm::ParameterSet&);
      ~H4GSelector();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

      //Selector elements:
      typedef math::XYZTLorentzVector LorentzVector;
      edm::EDGetTokenT<edm::View<pat::Photon> > photonsToken_;
      edm::EDGetTokenT<edm::View<reco::GenParticle> > genParticlesToken_;
      // ID decision objects
      edm::EDGetTokenT<edm::ValueMap<bool> > phoLooseIdMapToken_;
      edm::EDGetTokenT<edm::ValueMap<bool> > phoMediumIdMapToken_;
      edm::EDGetTokenT<edm::ValueMap<bool> > phoTightIdMapToken_;
      // One example of full information about the cut flow
      edm::EDGetTokenT<edm::ValueMap<vid::CutFlowResult> > phoLooseIdFullInfoMapToken_;
      edm::EDGetTokenT<edm::ValueMap<vid::CutFlowResult> > phoMediumIdFullInfoMapToken_;
      edm::EDGetTokenT<edm::ValueMap<vid::CutFlowResult> > phoTightIdFullInfoMapToken_;
      // MVA info
      edm::EDGetTokenT<edm::ValueMap<float> > mvaValuesMapToken_;

      //Out tree elements:
      TTree* outTree;
      int n_pho, run, lumi, evtnum;
      std::vector<LorentzVector> v_pho_p4;
      std::vector<LorentzVector> v_genpho_p4;
      std::vector<int> v_genpho_motherpdgid;
      std::vector<float> v_pho_pt;
      std::vector<float> v_pho_eta;
      std::vector<float> v_pho_phi;
      std::vector<float> v_pho_e;
      std::vector<std::vector<float>> v_pho_dr;
      std::vector<std::vector<float>> v_pho_dphi;
      std::vector<std::vector<float>> v_pho_deta;
      std::vector<std::map<std::string,float>> v_phoIdvars;
      std::vector<std::map<std::string, int>> v_pho_cutid;
      std::vector<float> v_pho_mva;

   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
H4GSelector::H4GSelector(const edm::ParameterSet& iConfig):
  phoLooseIdMapToken_(consumes<edm::ValueMap<bool> >(iConfig.getParameter<edm::InputTag>("phoLooseIdMap"))),
  phoMediumIdMapToken_(consumes<edm::ValueMap<bool> >(iConfig.getParameter<edm::InputTag>("phoMediumIdMap"))),
  phoTightIdMapToken_(consumes<edm::ValueMap<bool> >(iConfig.getParameter<edm::InputTag>("phoTightIdMap"))),
  phoLooseIdFullInfoMapToken_(consumes<edm::ValueMap<vid::CutFlowResult> >
			       (iConfig.getParameter<edm::InputTag>("phoLooseIdFullInfoMap"))),
  phoMediumIdFullInfoMapToken_(consumes<edm::ValueMap<vid::CutFlowResult> >
			       (iConfig.getParameter<edm::InputTag>("phoMediumIdFullInfoMap"))),
  phoTightIdFullInfoMapToken_(consumes<edm::ValueMap<vid::CutFlowResult> >
			       (iConfig.getParameter<edm::InputTag>("phoTightIdFullInfoMap"))),
  mvaValuesMapToken_(consumes<edm::ValueMap<float> >(iConfig.getParameter<edm::InputTag>("mvaValuesMap")))
{
   //now do what ever initialization is needed
   usesResource("TFileService");
   edm::Service<TFileService> fs;
   outTree = fs->make<TTree> ("H4GTree", "Tree for h->4g analysis");
   outTree->Branch("run", &run, "run/I");
   outTree->Branch("lumi", &lumi, "lumi/I");
   outTree->Branch("evtnum", &evtnum, "evtnum/I");

   outTree->Branch("n_pho", &n_pho, "n_pho/I");
   outTree->Branch("v_pho_p4", &v_pho_p4);
   outTree->Branch("v_genpho_p4", &v_genpho_p4);
   outTree->Branch("v_genpho_motherpdgid", &v_genpho_motherpdgid);
   outTree->Branch("v_pho_pt", &v_pho_pt);
   outTree->Branch("v_pho_eta", &v_pho_eta);
   outTree->Branch("v_pho_phi", &v_pho_phi);
   outTree->Branch("v_pho_e", &v_pho_e);
   outTree->Branch("v_pho_dr", &v_pho_dr);
   outTree->Branch("v_pho_dphi", &v_pho_dphi);
   outTree->Branch("v_pho_deta", &v_pho_deta);
   outTree->Branch("v_phoIdvars", &v_phoIdvars);
   outTree->Branch("v_pho_cutid", &v_pho_cutid);
   outTree->Branch("v_pho_mva", &v_pho_mva);

   photonsToken_ = mayConsume<edm::View<pat::Photon> >
    (iConfig.getParameter<edm::InputTag>
     ("photons"));
  
   genParticlesToken_ = mayConsume<edm::View<reco::GenParticle> >
    (iConfig.getParameter<edm::InputTag>
     ("genParticles"));

}


H4GSelector::~H4GSelector()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
H4GSelector::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

   run = iEvent.id().run();
   lumi = iEvent.id().luminosityBlock();
   evtnum = iEvent.id().event();

   edm::Handle<edm::View<pat::Photon> > photons;
   iEvent.getByToken(photonsToken_, photons);
   Handle<edm::View<reco::GenParticle> > genParticles;
   iEvent.getByToken(genParticlesToken_,genParticles);

   edm::Handle<edm::ValueMap<bool> > loose_id_decisions;
   edm::Handle<edm::ValueMap<bool> > medium_id_decisions;
   edm::Handle<edm::ValueMap<bool> > tight_id_decisions;
   iEvent.getByToken(phoLooseIdMapToken_ ,loose_id_decisions);
   iEvent.getByToken(phoMediumIdMapToken_,medium_id_decisions);
   iEvent.getByToken(phoTightIdMapToken_ ,tight_id_decisions);
   // Full cut flow info for all of the working points:
   edm::Handle<edm::ValueMap<vid::CutFlowResult> > loose_id_cutflow_data;
   edm::Handle<edm::ValueMap<vid::CutFlowResult> > medium_id_cutflow_data;
   edm::Handle<edm::ValueMap<vid::CutFlowResult> > tight_id_cutflow_data;
   iEvent.getByToken(phoLooseIdFullInfoMapToken_,loose_id_cutflow_data);
   iEvent.getByToken(phoMediumIdFullInfoMapToken_,medium_id_cutflow_data);
   iEvent.getByToken(phoTightIdFullInfoMapToken_,tight_id_cutflow_data);
   //MVA info
   edm::Handle<edm::ValueMap<float> > mvaValues;
   iEvent.getByToken(mvaValuesMapToken_,mvaValues);

   //Initialize tree variables
   n_pho = 0;
   v_pho_p4.clear();
   v_genpho_p4.clear();
   v_pho_pt.clear();
   v_pho_eta.clear();
   v_pho_phi.clear();
   v_pho_e.clear();
   v_pho_dr.clear();
   v_pho_dphi.clear();
   v_pho_deta.clear();
   v_phoIdvars.clear();
   v_pho_cutid.clear();
   v_pho_mva.clear();

   // Loop over photons
   for (size_t i = 0; i < photons->size(); ++i){
     const auto pho = photons->ptrAt(i);

     // Kinematics
     if( pho->pt() < 15 ) 
       continue;
    
     n_pho++;

     //
     // Save photon kinematics
     //
     v_pho_pt.push_back( pho->pt() );
     v_pho_eta.push_back( pho->superCluster()->eta() );
     v_pho_phi.push_back( pho->superCluster()->phi() );
     v_pho_e.push_back( pho->energy() );
     math::PtEtaPhiELorentzVectorD tmpVec;
     tmpVec.SetPt( pho->pt() );
     tmpVec.SetEta( pho->superCluster()->eta() );
     tmpVec.SetPhi( pho->superCluster()->phi() );
     tmpVec.SetE( pho->energy() );
     LorentzVector thisPhoV4( tmpVec );
     v_pho_p4.push_back( thisPhoV4 );
 
     //
     // Look up and save the ID decisions
     // 
     bool isPassLoose  = (*loose_id_decisions)[pho];
     bool isPassMedium = (*medium_id_decisions)[pho];
     bool isPassTight  = (*tight_id_decisions)[pho];
     std::map<std::string, int> idMap;
     idMap["loose"] = isPassLoose;
     idMap["medium"] = isPassMedium;
     idMap["tight"] = isPassTight;
     v_pho_cutid.push_back( idMap );
 
     //Look up and save ID variables
     vid::CutFlowResult fullCutFlowDataLoose = (*loose_id_cutflow_data)[pho];
     vid::CutFlowResult fullCutFlowDataMedium = (*medium_id_cutflow_data)[pho];
     vid::CutFlowResult fullCutFlowDataTight = (*tight_id_cutflow_data)[pho];

//     if(i == 0) std::cout << "Id vars:" << std::endl;
     std::map<std::string, float> varsMap;
     for( size_t cut = 0; cut < fullCutFlowDataLoose.cutFlowSize(); cut++) {
         std::string varName_Loose = fullCutFlowDataLoose.getNameAtIndex(cut);
         varName_Loose.append("_Loose");
         std::string varName_Medium = fullCutFlowDataMedium.getNameAtIndex(cut);
         varName_Medium.append("_Medium");
         std::string varName_Tight = fullCutFlowDataTight.getNameAtIndex(cut);
         varName_Tight.append("_Tight");

         double var_Loose = fullCutFlowDataLoose.getValueCutUpon(cut);
         double var_Medium = fullCutFlowDataMedium.getValueCutUpon(cut);
         double var_Tight = fullCutFlowDataTight.getValueCutUpon(cut);
 
         varsMap[varName_Loose] = var_Loose;
         varsMap[varName_Medium] = var_Medium;
         varsMap[varName_Tight] = var_Tight; 

/*        if(i == 0 ) {
            std::cout << varName_Loose << std::endl;
            std::cout << varName_Medium << std::endl;
            std::cout << varName_Tight << std::endl;
         }
*/

     }
     v_phoIdvars.push_back(varsMap);

     //Save MVA ID
     v_pho_mva.push_back( (*mvaValues)[pho] );
   }

   // Save delta r between selected photons
   for( size_t p = 0; p < v_pho_p4.size(); p++) {
      LorentzVector pho = v_pho_p4[p];
      std::vector<float> vecDR;
      std::vector<float> vecDPhi;
      std::vector<float> vecDEta;
      for ( size_t p2 = 0; p < v_pho_p4.size(); p++) {
         LorentzVector pho2 = v_pho_p4[p];
         float deltar = 0;
         float deltaphi = 0;
         float deltaeta = 0;
         if( p2 == p ) {
            deltar = -999;
            deltaphi = -999;
            deltaeta = -999;
         }
         if( p2 != p ) {
            deltar = deltaR(pho, pho2);
            deltaphi = deltaPhi(pho.phi(), pho2.phi());
            deltar = fabs(pho.eta() - pho2.eta());
         }
         vecDR.push_back(deltar);
         vecDPhi.push_back(deltaphi);
         vecDEta.push_back(deltaeta);
      }
      v_pho_dr.push_back(vecDR);
      v_pho_dphi.push_back(vecDPhi);
      v_pho_deta.push_back(vecDEta);
   }

   // Save prompt photon gen information
   for( size_t g = 0; g < genParticles->size(); g++) {
      const auto gen = genParticles->ptrAt(g);

      //Only save gen information of prompt+final state photons (this includes FSR/ISR)
      if( gen->isPromptFinalState() == 0 ) continue;

      //Only save photons
      if( gen->pdgId() != 22 ) continue;

      v_genpho_p4.push_back( gen->p4() );
      int motherPDGID = -999;
      if( gen->mother() ) motherPDGID = gen->mother()->pdgId();
      v_genpho_motherpdgid.push_back(motherPDGID);

   }
   
   // Save the info
   outTree->Fill();

}


// ------------ method called once each job just before starting event loop  ------------
void 
H4GSelector::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
H4GSelector::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
H4GSelector::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(H4GSelector);
