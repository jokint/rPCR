---
title: "Untitled"
format: html
editor: visual
---

## rPCR - Influence of Heteroduplex formation on ratio bias and amplification efficiency

In multi-template PCR like rPCR heterodoplex are formed. We are using our rPCR model to investigate the impact of heteroduplex formation on ratio bias and amplification efficiency.

As the PCR is an iterative process the effects are cumulative. Therefore we performed first single cycle simulations with different increasing starting amounts to avoid summation of effects which are more difficult to analyze. In a second step we perform full PCR simulations to apply the discovered principles to the accumulative effects.

## Setup

```{r}

library(ggplot2)
library(rPCR)
source("/scicore/home/sinnreic/kinter/R projects/rPCR/documents/rPCRsim/omPCR_functions.R")
ppath <- "/scicore/home/sinnreic/kinter/R projects/rPCR/"
fpath <- paste0(ppath,"documents/figures/Simulations/")
mPath <- "/scicore/home/sinnreic/kinter"
path_model <- "/openmodelica/"
simModel <- "rPCR_03"
simPath <- paste0(mPath, path_model, simModel, "/")
path_sim <- "/R\ projects/rPCR/documents/rPCRsim/"

### Following standard parameters are used. Differences from this standard values will be noted. 

stdPara <- data.frame(
  tolerance = 1e-8,
  cycle_max = 45,
  cycle_time = 45,
  startPrimer = 500 * 1e-9, # nM
  startTemplate = copytoconc(1e6), # copies
  startRatio = 0.5,
  ProbeA = 0 * 1e-9, # nM
  ProbeB = 0 * 1e-9, # nM
  Signal_A = 0,
  Signal_B = 0,
  Primer_k1 = 2e5,
  # literature: 5e5 /M s
  Primer_k2 = 1e-3,
  # literature: 1e-4 /s
  ProbeA_k1 = 3e5,
  ProbeA_k2 = 1e-3,
  ProbeB_k1 = 3e5,
  ProbeB_k2 = 1e-3,
  hetero_k1 = 1e6,
  hetero_k2 = 1e-4,
  rehybA_k1 = 1e6,
  rehybA_k2 = 1e-4,
  rehybB_k1 = 1e6,
  rehybB_k2 = 1e-4,
  Polymerase = 2e-7,
  RdsPoly_k1 = 1e6,
  RdsPoly_k2 = 1e-3,
  RiniPoly_k1 = 1e6,
  RiniPoly_k2 = 1e-3,
  RextPoly_k1 = 60,
  sFluoA = 50e6,
  sFluoB = 50e6,
  bFluoA = 1,
  bFluoB = 1,
  lFluoA = 0,
  lFluoB = 0,
  Aa_PB_k1 =1e-20,
  Aa_PB_k2 =1e20,
  Ba_PA_k1 =1e-20,
  Ba_PA_k2 =1e20
)

stdPara$stopTime <- stdPara$cycle_time*stdPara$cycle_max
stdPara$stepSize <- stdPara$cycle_time



```

Single cycle simulation

```{r}
title <- "hetero_singlecycle"
expName <- paste0("Sim_",title)
para <- stdPara
para$stepSize <- para$cycle_time
para$cycle_max<- 1
para$stopTime <- stdPara$cycle_time




template <- seq(1e-18,para$startPrimer*0.95,length.out=10)
primer <- para$startPrimer-template
mpara <- cbind(para, rep(1,length(template)))
mpara$startTemplate <- template
mpara$startPrimer <- primer

nlist <- list(hetero_k1 = seq(3e5,1e6,1e5),
              startRatio = seq(0,1,0.01))

results <- omPCRBatch(simModel,
                      simPath,
                      override=mpara,
                      nestedList=nlist,
                      logdir=expName,
                      project=title,
                      details = FALSE,
                      expName=expName)


```

The `echo: false` option disables the printing of code (only output is displayed).

```{r}
ggplot(data=results) +geom_line(aes(x=par_startRatio,y=difT,group=interaction(par_hetero_k1,par_startTemplate)))
```
