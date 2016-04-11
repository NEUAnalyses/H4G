
#include "TLorentzVector.h"
#include "TROOT.h"
#include "TSystem.h"

void plotDR(float mass_a = 0.100){
 
 gSystem->Load("libPhysics");
 
//  float mass_a = 0.100;  //---- GeV
 
 //---- rest frame
 TLorentzVector Photon_1;
 Photon_1.SetPxPyPzE(mass_a/2.,0, 0,mass_a/2.);
 TLorentzVector Photon_2;
 Photon_2.SetPxPyPzE(-mass_a/2.,0, 0,mass_a/2.);
 
 TLorentzVector Particle_a;
 Particle_a = Photon_1 + Photon_2;
  
 
 TGraph2D* grDR_ph2 = new TGraph2D();
 TGraph2D* grDR_ph1 = new TGraph2D();
 TGraph2D* grDR_ptgg = new TGraph2D();
 
 TGraph2D* grDR = new TGraph2D();
 TGraph2D* grDR_pta = new TGraph2D();
 TGraph2D* grDR_boost = new TGraph2D();
 
 int NX = 100;
 int NY = 2000;
 
 int point_number = 0;
 for (int ix = 0; ix < NX; ix++) {
  double alpha = 1. * ix / NX * (3.14/2);
  for (int iy = 0; iy < NY; iy++) {
   double boost = iy/10.; //---- 1./10. GeV
//    double boost = iy/10. + 10; //---- 1./10. GeV
   //    double boost = iy/1.; //---- 1./1. GeV
   //    double boost = iy/0.01; //---- 1./10. GeV
   
   TLorentzVector Particle_a_newSys = Particle_a;
   Particle_a_newSys.SetPxPyPzE(Particle_a.X() + boost*sin(alpha), Particle_a.Y() + boost*cos(alpha), 0, Particle_a.E() + boost);
   
   TVector3 BoostVector;
   BoostVector = Particle_a_newSys.BoostVector();
   
   
   TLorentzVector Photon_1_newSys = Photon_1;
   Photon_1_newSys.Boost(BoostVector);
   
   TLorentzVector Photon_2_newSys = Photon_2;
   Photon_2_newSys.Boost(BoostVector);
   
//    std::cout << " BoostVector = " << BoostVector.X() << std::endl;
//    std::cout << " Mass = " << (Photon_1_newSys + Photon_2_newSys).M() << std::endl;
   
   double Dr = Photon_1_newSys.DeltaR(Photon_2_newSys);
//    double Dr = fabs(Photon_1_newSys.DeltaPhi(Photon_2_newSys));
   
   grDR->SetPoint(point_number, alpha, boost, Dr);
   grDR_ph2->SetPoint(point_number, alpha, Photon_2_newSys.E(), Dr);
   grDR_ph1->SetPoint(point_number, alpha, Photon_1_newSys.E(), Dr);
   
//    grDR_ptgg->SetPoint(point_number, alpha, (Photon_1_newSys + Photon_2_newSys).E(), Dr);
   grDR_ptgg->SetPoint(point_number, alpha, (Photon_1_newSys + Photon_2_newSys).Pt(), Dr);
   
   grDR_pta->SetPoint(point_number, alpha, Particle_a_newSys.Pt(), Dr);

   grDR_boost->SetPoint(point_number, alpha, BoostVector.Mag(), Dr);
   
//    std::cout << " point_number, alpha, boost, Dr = " << point_number << "," << alpha << "," << boost << "," << Dr << std::endl;
   point_number++;
  }
 } 
 
 
 TCanvas* cc = new TCanvas ("cc","",800,600); 
 grDR->SetTitle("a boost");
 grDR->Draw("cont4z");
 grDR->GetHistogram()->GetXaxis()->SetTitle("#alpha");
 grDR->GetHistogram()->GetYaxis()->SetTitle("Boost (GeV)");
 grDR->GetHistogram()->GetZaxis()->SetTitle("Angle (rad)");
 grDR->Draw("cont4z");
 
 cc->SetGrid();
 cc->SetLogz();
 
 
 TCanvas* cc_ph2 = new TCanvas ("cc_ph2","",800,600); 
 grDR_ph2->SetTitle("photon 2");
 grDR_ph2->Draw("cont4z");
 grDR_ph2->GetHistogram()->GetXaxis()->SetTitle("#alpha");
 grDR_ph2->GetHistogram()->GetYaxis()->SetTitle("p_{T} photon (GeV)");
 grDR_ph2->GetHistogram()->GetZaxis()->SetTitle("Angle (rad)");
 grDR_ph2->Draw("cont4z");
 
 cc_ph2->SetGrid();
 cc_ph2->SetLogz();
 
 
 
 
 TCanvas* cc_ph1 = new TCanvas ("cc_ph1","",800,600); 
 grDR_ph1->SetTitle("photon 1");
 grDR_ph1->Draw("cont4z");
 grDR_ph1->GetHistogram()->GetXaxis()->SetTitle("#alpha");
 grDR_ph1->GetHistogram()->GetYaxis()->SetTitle("p_{T} photon (GeV)");
 grDR_ph1->GetHistogram()->GetZaxis()->SetTitle("Angle (rad)");
 grDR_ph1->Draw("cont4z");
 
 cc_ph1->SetGrid();
 cc_ph1->SetLogz();
 
 
 
 
 
 TCanvas* cc_ptgg = new TCanvas ("cc_ptgg","",800,600); 
 grDR_ptgg->SetTitle("pt gg");
 grDR_ptgg->Draw("cont4z");
 grDR_ptgg->GetHistogram()->GetXaxis()->SetTitle("#alpha");
 grDR_ptgg->GetHistogram()->GetYaxis()->SetTitle("p_{T} di-photon (GeV)");
 grDR_ptgg->GetHistogram()->GetZaxis()->SetTitle("Angle (rad)");
 grDR_ptgg->Draw("cont4z");
 
 cc_ptgg->SetGrid();
 cc_ptgg->SetLogz();
 

 
 TCanvas* cc_pta = new TCanvas ("cc_pta","",800,600); 
 grDR_pta->SetTitle("pt a");
 grDR_pta->Draw("cont4z");
 grDR_pta->GetHistogram()->GetXaxis()->SetTitle("#alpha");
 grDR_pta->GetHistogram()->GetYaxis()->SetTitle("p_{T} a (GeV)");
 grDR_pta->GetHistogram()->GetZaxis()->SetTitle("Angle (rad)");
 grDR_pta->Draw("cont4z");
 
 cc_pta->SetGrid();
 cc_pta->SetLogz();
 
 
 TCanvas* cc_boost = new TCanvas ("cc_boost","",800,600); 
 grDR_boost->SetTitle("boost");
 grDR_boost->Draw("cont4z");
 grDR_boost->GetHistogram()->GetXaxis()->SetTitle("#alpha");
 grDR_boost->GetHistogram()->GetYaxis()->SetTitle("boost");
 grDR_boost->GetHistogram()->GetZaxis()->SetTitle("Angle (rad)");
 grDR_boost->Draw("cont4z");
 
 cc_boost->SetGrid();
 cc_boost->SetLogz();
 cc_boost->SetLogy();
 
 
 
 
}


