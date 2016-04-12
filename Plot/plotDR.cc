
#include "TLorentzVector.h"
#include "TROOT.h"
#include "TSystem.h"

void plotDR(float mass_a = 0.100, int NY = 1000, int NX = 100){
 
 std::cout << " mass_a = " << mass_a << std::endl;
 std::cout << " NY =     " << NY     << std::endl;
 std::cout << " NX =     " << NX     << std::endl;
 
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

 TH1F* h_boost = new TH1F("h_boost","",100,0,100);
 
 
 int point_number = 0;
 for (int ix = 0; ix < NX; ix++) {
//  for (int ix = 0; ix < 1; ix++) {
  double alpha = 1. * ix / NX * (3.14/2);
  for (int iy = 0; iy < NY; iy++) {
   double boost = iy/10.; //---- 1./10. GeV
//    double boost = iy/10. + 10; //---- 1./10. GeV
   //    double boost = iy/1.; //---- 1./1. GeV
   //    double boost = iy/0.01; //---- 1./10. GeV
   
   TLorentzVector Particle_a_newSys = Particle_a;
   Particle_a_newSys.SetPxPyPzE(Particle_a.X() + boost*sin(alpha), Particle_a.Y() + boost*cos(alpha), 0, Particle_a.E() + boost);
   
   TVector3 BoostVector;
//    BoostVector = Particle_a_newSys.BoostVector();
   double gamma =  (mass_a + boost) / mass_a;
   double beta = sqrt(1-1./gamma/gamma);
   
   BoostVector.SetXYZ(beta*sin(alpha), beta*cos(alpha), 0);
   
   
   TLorentzVector Photon_1_newSys = Photon_1;
   Photon_1_newSys.Boost(BoostVector);
   
   TLorentzVector Photon_2_newSys = Photon_2;
   Photon_2_newSys.Boost(BoostVector);
   
//    std::cout << " BoostVector = " << BoostVector.X() << std::endl;
//    std::cout << " Mass = " << (Photon_1_newSys + Photon_2_newSys).M() << std::endl;


//    std::cout << " Particle_a.X() = " << Particle_a.X() << "   Particle_a.E() = " << Particle_a.E() << " shift = " << boost << " beta = " << BoostVector.Mag();
//    std::cout << " ptgg = " << (Photon_1_newSys + Photon_2_newSys).Pt() << " pta = " << Particle_a_newSys.Pt();
//    std::cout << " x,y,z = " << BoostVector.X() << "," << BoostVector.Y() << "," << BoostVector.Z() << "," ;
//    std::cout << " beta = " << sqrt(1-1./(Particle_a_newSys.E() / mass_a * Particle_a_newSys.E() / mass_a)) << std::endl;


   
   double Dr = Photon_1_newSys.DeltaR(Photon_2_newSys);
//    double Dr = fabs(Photon_1_newSys.DeltaPhi(Photon_2_newSys));
   
   grDR->SetPoint(point_number, alpha, boost, Dr);
   grDR_ph2->SetPoint(point_number, alpha, Photon_2_newSys.E(), Dr);
   grDR_ph1->SetPoint(point_number, alpha, Photon_1_newSys.E(), Dr);
   
//    grDR_ptgg->SetPoint(point_number, alpha, (Photon_1_newSys + Photon_2_newSys).E(), Dr);
   grDR_ptgg->SetPoint(point_number, alpha, (Photon_1_newSys + Photon_2_newSys).Pt(), Dr);
   
   grDR_pta->SetPoint(point_number, alpha, Particle_a_newSys.Pt(), Dr);

   grDR_boost->SetPoint(point_number, alpha, BoostVector.Mag(), Dr);
   
   h_boost->Fill(Particle_a_newSys.Pt() / BoostVector.Mag());
   
   
//    std::cout << " point_number, alpha, boost, Dr = " << point_number << "," << alpha << "," << boost << "," << Dr << std::endl;
   point_number++;
  }
 } 
 
 
 
 Double_t contours[6];
 contours[0] = 0.0175;
 contours[1] = 0.0175*2;
 contours[2] = 0.0175*3;
 contours[3] = 0.0175*4;
 contours[4] = 0.0175*5;
 contours[5] = 0.0175*6;
 
 TCanvas* cc = new TCanvas ("cc","",800,600); 
 grDR->SetTitle("a boost");
 grDR->Draw("cont4z");
 grDR->GetHistogram()->GetXaxis()->SetTitle("#alpha");
 grDR->GetHistogram()->GetYaxis()->SetTitle("Boost (GeV)");
 grDR->GetHistogram()->GetZaxis()->SetTitle("Angle (rad)");
 grDR->Draw("cont4z");
 
 cc->SetGrid();
 cc->SetLogz();
 
 





 
 TCanvas* cc_ph2 = new TCanvas ("cc_ph2","",1600,600); 
 cc_ph2->Divide(2,1);
 cc_ph2->cd(1);
 grDR_ph2->SetTitle("photon 2");
 grDR_ph2->Draw("cont4z");
 grDR_ph2->GetHistogram()->GetXaxis()->SetTitle("#alpha");
 grDR_ph2->GetHistogram()->GetYaxis()->SetTitle("p_{T} photon (GeV)");
 grDR_ph2->GetHistogram()->GetZaxis()->SetTitle("Angle (rad)");
 grDR_ph2->Draw("cont4z");
 gPad->SetGrid();
 gPad->SetLogz();
 
 cc_ph2->cd(2);
 TH2F* HistStreamFn_ph2 = (TH2F*) (grDR_ph2->GetHistogram())->Clone("testhisto_ph2");
 HistStreamFn_ph2->SetContour(6, contours);
 HistStreamFn_ph2->SetLineWidth(2);
 HistStreamFn_ph2->SetLineStyle(2);
 HistStreamFn_ph2->Draw("CONT1 Z LIST");
 gPad->SetGrid();
 gPad->SetLogz();
 
 
 
 
 
 
 
 
 TCanvas* cc_ph1 = new TCanvas ("cc_ph1","",1600,600); 
 cc_ph1->Divide(2,1);
 cc_ph1->cd(1);
 grDR_ph1->SetTitle("photon 1");
 grDR_ph1->Draw("cont4z");
 grDR_ph1->GetHistogram()->GetXaxis()->SetTitle("#alpha");
 grDR_ph1->GetHistogram()->GetYaxis()->SetTitle("p_{T} photon (GeV)");
 grDR_ph1->GetHistogram()->GetZaxis()->SetTitle("Angle (rad)");
 grDR_ph1->Draw("cont4z");
 gPad->SetGrid();
 gPad->SetLogz();
 
 cc_ph1->cd(2);
 TH2F* HistStreamFn_ph1 = (TH2F*) (grDR_ph1->GetHistogram())->Clone("testhisto_ph1");
 HistStreamFn_ph1->SetContour(6, contours);
 HistStreamFn_ph1->SetLineWidth(2);
 HistStreamFn_ph1->SetLineStyle(2);
 HistStreamFn_ph1->Draw("CONT1 Z LIST");
 gPad->SetGrid();
 gPad->SetLogz();
 
 
 
 
 
 TCanvas* cc_ptgg = new TCanvas ("cc_ptgg","",1600,600); 
 cc_ptgg->Divide(2,1);
 cc_ptgg->cd(1);
 grDR_ptgg->SetTitle("pt gg");
 grDR_ptgg->Draw("cont4z");
 grDR_ptgg->GetHistogram()->GetXaxis()->SetTitle("#alpha");
 grDR_ptgg->GetHistogram()->GetYaxis()->SetTitle("p_{T} di-photon (GeV)");
 grDR_ptgg->GetHistogram()->GetZaxis()->SetTitle("Angle (rad)");
 grDR_ptgg->Draw("cont4z");
 gPad->SetGrid();
 gPad->SetLogz();
 
 cc_ptgg->cd(2);
 TH2F* HistStreamFn_ptgg = (TH2F*) (grDR_ptgg->GetHistogram())->Clone("testhisto_ptgg");
 HistStreamFn_ptgg->SetContour(6, contours);
 HistStreamFn_ptgg->SetLineWidth(2);
 HistStreamFn_ptgg->SetLineStyle(2);
 HistStreamFn_ptgg->Draw("CONT1 Z LIST");
 gPad->SetGrid();
 gPad->SetLogz();
 

 
 TCanvas* cc_pta = new TCanvas ("cc_pta","",800,600); 
 grDR_pta->SetTitle("pt a");
 grDR_pta->Draw("cont4z");
 grDR_pta->GetHistogram()->GetXaxis()->SetTitle("#alpha");
 grDR_pta->GetHistogram()->GetYaxis()->SetTitle("p_{T} a (GeV)");
 grDR_pta->GetHistogram()->GetZaxis()->SetTitle("Angle (rad)");
 grDR_pta->Draw("cont4z");
 
 cc_pta->SetGrid();
 cc_pta->SetLogz();
 
 
//  TCanvas* cc_boost = new TCanvas ("cc_boost","",800,600); 
//  grDR_boost->SetTitle("boost");
//  grDR_boost->Draw("cont4z");
//  grDR_boost->GetHistogram()->GetXaxis()->SetTitle("#alpha");
//  grDR_boost->GetHistogram()->GetYaxis()->SetTitle("boost");
//  grDR_boost->GetHistogram()->GetZaxis()->SetTitle("Angle (rad)");
//  grDR_boost->Draw("cont4z");
//  
//  cc_boost->SetGrid();
//  cc_boost->SetLogz();
//  cc_boost->SetLogy();
 
//  
//  TCanvas* cc_h_boost = new TCanvas ("cc_h_boost","",800,600); 
//  h_boost->SetTitle("boost");
//  h_boost->Draw();
//  h_boost->GetXaxis()->SetTitle("pt/boost");
//  
//  cc_h_boost->SetGrid();
//  cc_h_boost->SetLogz();
//  cc_h_boost->SetLogy();
 
 
 
 
}


