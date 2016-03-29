#!/usr/bin/python

from ROOT import *
import sys, getopt

idVars = [
"PhoSCEtaMultiRangeCut_0",
"PhoSingleTowerHadOverEmCut_0",
"PhoFull5x5SigmaIEtaIEtaCut_0",
"PhoAnyPFIsoWithEACut_0",
"PhoAnyPFIsoWithEAAndQuadScalingCut_0",
"PhoAnyPFIsoWithEACut_1"
]

idWP = [
"Loose",
"Medium",
"Tight"
]

def main(argv):
   inputfiles = ''
   outputfile = 'output.root'
   try:
      opts, args = getopt.getopt(argv,"hi:o:",["inputFiles=","outputFile="])
   except getopt.GetoptError:
      print 'test.py -i <inputfile1,inputfile2,inputfile3...> -o <outputfile>'
      sys.exit(2)
   for opt, arg in opts:
      if opt == '-h':
         print 'test.py -i <inputfile1,inputfile2,inputfile3...> -o <outputfile>'
         sys.exit()
      elif opt in ("-i", "--inputFiles"):
         inputfiles = arg
      elif opt in ("-o", "--outputFile"):
         outputfile = arg

   listOfFiles = inputfiles.split(",")
   print "Number of input files: ", len(listOfFiles)

   tree = TChain("h4gselector/H4GTree")
   for f in listOfFiles:
      print "\t Adding file:", f
      tree.AddFile(f)
   print "Total number of events to be analyzed:", tree.GetEntries()

   #Tree Loop:
   for evt in range(0, tree.GetEntries()):
      if evt%1000 == 0: print "## Analyzing event ", evt
      tree.GetEntry(evt)

      print "Number of photons:", tree.n_pho
      if tree.n_pho < 1:
         continue

#      print "Pho 1 pt:", tree.v_pho_pt[0], tree.v_pho_p4[0].pt()

      #idVars
#      idVarsMap = tree.v_phoIdvars[0]
#      for v in idVars:
#         print v, idVarsMap[v+"_Loose"]

      #id decisions
#      idDecs = tree.v_pho_cutid[0]
#      for w in idWP:
#         print w, ":", idDecs[w]

      for p in range(0, tree.n_pho):
         idDecs = tree.v_pho_cutid[p]
         for w in idWP:
            if idDecs[w] == 1:
               print "photon", p, "passed", w, "id!"

if __name__ == "__main__":
   main(sys.argv[1:])

