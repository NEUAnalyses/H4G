Crab submission of microAOD
====


Flashgg framework: 

    https://github.com/cms-analysis/flashgg   

MicroAOD generation

    https://github.com/cms-analysis/flashgg/tree/master/MetaData   

Prepare json file with the datasets you want to run on (signals.json)   

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
