## H->aa->4gamma Signal MC Production

#### Pythia8 signal instructions
Based on Pythia6 RunI H->aa->bbtautau signal (from Abdollah: https://www.dropbox.com/s/egntcw42szj9qif/mmtt_ma35_cfg.py?dl=0)   
Pythia doesn't do h(125)->aa, but it does H->hh with 2HDM model. So, make m(H) = 125 and m(h) = [5,60].   
Full Pythia8 fragment is in this repository.   
Cannot use POWHEG LHE because it produces h(125) - pdgid 25.   

#### CMS GEN Production
##### Step 0

    curl -s --insecure https://raw.githubusercontent.com/NEUAnalyses/H4G/master/Gen/GENSIM/Step0_GluGluToHToXXTo4G-fragment.py    --retry 2 --create-dirs -o Configuration/GenProduction/python/Step0_GluGluToHToXXTo4G-fragment.py 
    
    cmsDriver.py Configuration/GenProduction/python/Step0_GluGluToHToXXTo4G-fragment.py --fileout file:HIG-RunIISummer15GS-00174.root --mc --eventcontent RAWSIM --era Run2_25ns --datatier GEN-SIM --conditions 76X_mcRun2_asymptotic_v12 --pileup 2015_25ns_FallMC_matchData_PoissonOOTPU --step GEN,SIM --magField 38T_PostLS1 --python_filename HIG-RunIISummer15GS-00174_1_cfg.py --no_exec -n 32   

    already prepared in folder: Gen/GENSIM/Configs
    Different configurations
    
##### Step 1, DR

    already prepared in folder: Gen/DR/Configs
    Different configurations

##### Step miniAOD    

    already prepared in folder: Gen/miniAOD/Configs
    Different configurations

##### Step MicroAOD

First, one should be familiar with the flashgg framework: https://github.com/cms-analysis/flashgg   
Specifically, for the MicroAOD generation, read https://github.com/cms-analysis/flashgg/tree/master/MetaData   
###### 1) Prepare json file with the datasets you want to run on (signals.json)   

```
cd flashgg/MetaData/work/
vim signals.json
```   

signals.json should look like this:   

```
{
    "data" : [
     ],
    "sig"  : [	
	"/GluGluToXToAATo4G_mX_750GeV_mA_370GeV_Pythia8/amassiro-AOD_miniAOD-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12_tris-f4b2dfe8fd4637946dd0210f2ad467dd/USER",
	"/GluGluToXToAATo4G_mX_750GeV_mA_10GeV_Pythia8/amassiro-AOD_miniAOD-RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12_tris-f4b2dfe8fd4637946dd0210f2ad467dd/USER"
    ],
    "bkg" : []
}
```   
###### 2) Prepare crab configuration files with ./prepareCrabJobs.py   
```
./prepareCrabJobs.py -C <Campaign>  -s signals.json --mkPilot
```    

Keep track of your campaign name, as it will be useful later on...   
This will create a directory <Campaign> with all your crab configuration files, the CMSSW parameter set, and the dump of all the script options.   

###### 3) Submit all    
```
cd <Campaign>
echo crabConfig_*.py | xargs -n 1 crab sub
```
