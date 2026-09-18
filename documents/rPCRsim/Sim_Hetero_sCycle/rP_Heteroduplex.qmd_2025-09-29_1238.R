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
source("/scicore/home/sinnreic/kinter/R projects/rPCR/documents/scripts/rPCR_Figure_0_Init.R")
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
title <- "Hetero_sCycle"
expName <- paste0("Sim_",title)
para <- stdPara
para$stepSize <- para$cycle_time
para$cycle_max<-1
para$stopTime <-para$cycle_time * para$cycle_ma




template <- seq(1e-18,para$startPrimer*0.95,length.out=10)
primer <- para$startPrimer-template
mpara <- cbind(para, rep(1,length(template)))
mpara$startTemplate <- template
mpara$startPrimer <- primer

nlist <- list(hetero_k1 = c(3e5,6e5,1e6),
              startRatio = seq(0,1,0.05))

# results <- omPCRBatch(simModel,
#                       simPath,
#                       override=mpara,
#                       nestedList=nlist,
#                       logdir=expName,
#                       project=title,
#                       details = FALSE,
#                       expName=expName)

results <- readRDS(paste0(mPath,path_sim,"Sim_",title,"/results/results.rds"))

results$sprop <- results$par_startRatio
results$prop <- results$ratio
results$sratio <- results$sprop/(1-results$sprop)
results$slratio <- log(results$sratio)
results$ratio <- results$prop/(1-results$prop)
results$sT <- results$par_startTemplate 
results$sA <- results$sT * results$sprop
results$sB <- results$sT * (1- results$sprop)
results$difA <- results$totalA -results$sA
results$difB <- results$totalB -results$sB
results$difT <- results$totalT -results$sT
results$effA <- results$difA/results$sA 
results$effB <- results$difB/results$sB
results$effT <- results$difT/results$sT


```

The Simulation data show that heterodeuplex formation leads to a greater amplification efficiency. Re-annealing of the amplicon strands inhibit the generation of new strands.

The degree of inhibition depends on the kinetic properties of the re-annealing reaction. As heteroduplex do not perfectly match the re-annelaing rate and therefore the inhibition is reduced leading to increas amplification efficiency. In rPCR the relative amount of heteroduplexes is maximum at equal template amounts. In Figure

```{r}
ggplot(data=results) +geom_line(aes(x=par_startRatio,y=effT,col=factor(sT),group=interaction(par_hetero_k1,par_startTemplate)))
mat <- data.frame(unique(results[results$par_hetero_k1==3e5,c("sT","effT","sprop")]) %>% pivot_wider(names_from = sT,values_from = effT))
rownames(mat) <- mat[,1]
mat <- mat[,-1]
plot_ly(z = ~as.matrix(mat)) %>% add_surface()
mat2 <- unique(results[results$par_hetero_k1==3e5,c("sT","effT","sprop")]) 
plot_ly(mat2, y=~sT,x=~sprop,z =~effT) %>% add_surface()

sel <- results[results$par_hetero_k1==3e5,]

propeff <- function(x,a=1,b=1,c=1) c*x^a*(1-x)^b
ratioeff <- function(x,a=0.99,b=0.99,c=0.25) c*(x/(1+x))^a*(1/(1+x))^b
lratioeff <- function(x,a=0.99,b=0.99,c=0.25) c*(log(x)/(1+log(x)))^a*(1/(1+log(x)))^b
propdrift <- function(x,g=1) (x/(1-x))^g/(1+(x/(1-x))^g)
res <- lapply(unique(sel$sT)[-1], function(template){
   df <- sel[sel$sT==template,c("sprop","sratio","slratio","effT","prop","ratio")]
   df <- df[!(df$sprop %in% c(0,1)),]
   print(template)
  nlsLM(prop ~ propdrift(sprop,g), #),d=0.5),
        data=df,
        start=list(g=1), # d=0.5),
        upper=c(g=Inf), # d=1),
        lower=c(g=0) #,d=0)
        )
})
cor1 <- function(x,a,b,c) exp(log(x/(1-x))*(1-c*x^a*(1-x)^b ))
cor <- function(x,a,b,c) cor1(x,a=a,b=b,c=c)/(cor1(x,a=a,b=b,c=c) +1)
drift <- function(x,a,b,c,d=0.5) {
   x[x==1] <- NA
   nratio <- exp(log(x/(1-x))*(1-c*x^a*(1-x)^b ))
   out <- nratio/(nratio+1)
   out[is.na(x)] <- 1
   return(out)
}
res <- lapply(unique(sel$sT)[-1], function(template){
   df <- sel[sel$sT==template,c("sprop","sratio","slratio","effT","prop","ratio")]
   df <- df[!(df$sprop %in% c(0,1)),]
   print(template)
  nlsLM(prop ~ drift(sprop,a,b,c), #),d=0.5),
        data=df,
        start=list(a=0.9,b=0.9,c=0.5), # d=0.5),
        upper=c(a=Inf,b=Inf,c=Inf), # d=1),
        lower=c(a=-Inf,b=-Inf,c=-Inf) #,d=0)
        )
})
drift <- function(x,a,b,c,d) {
   x[x==1] <- NA
   lratio <- exp(log(x/(1-x)) - log(d/(1-d)))
   # nx <- lratio/(1+lratio)
   nratio <- exp(log(lratio)*(1-c*x^a*(1-x)^b ))
   out <- nratio/(nratio+1)
   out[is.na(x)] <- 1
   return(out)
}
res <- lapply(unique(sel$sT)[-1], function(template){
   df <- sel[sel$sT==template,c("sprop","sratio","slratio","effT","prop","ratio")]
  nlsLM(prop ~ drift(sprop,a,b,c,d),
        data=df,
        start=list(a=0.2,b=0.2,c=0,d=0.4),
        upper=c(a=Inf,b=Inf,c=Inf,d=1),
        lower=c(a=-Inf,b=-Inf,c=-Inf,d=0)
        )
})

sel <- results[results$par_hetero_k1==3e5&results$sT==unique(results$sT)[3],]
ggplot() +
  geom_line(data=sel,aes(x=slratio,y=effA,group=interaction(par_hetero_k1,par_startTemplate)),col=3) +
  geom_line(data=sel,aes(x=slratio,y=effB,group=interaction(par_hetero_k1,par_startTemplate)),col=4) +
  geom_line(data=sel,aes(x=slratio,y=effT,group=interaction(par_hetero_k1,par_startTemplate)),col=1) +
   theme_rpcr() + theme_figure + theme(legend.position = "none")

```

Formulas to approximate the efficincy:
Proportion: delta= c x\^a\*(1-x)\^b or factor = 1 + c x\^a (1-x)\^b
Ratio: gaus: a * e^(-0.5*((x-b)/c)^2)





Single cycle simulation

```{r}
title <- "Hetero_asymetric_sCycle"
expName <- paste0("Sim_",title)
para <- stdPara
para$stepSize <- para$cycle_time
para$cycle_max<-1
para$stopTime <-para$cycle_time * para$cycle_ma

para$rehybA_k1 = 1e6
para$rehybB_k1 = 3e6



template <- seq(1e-18,para$startPrimer*0.95,length.out=10)
primer <- para$startPrimer-template
mpara <- cbind(para, rep(1,length(template)))
mpara$startTemplate <- template
mpara$startPrimer <- primer

nlist <- list(hetero_k1 = c(3e5,6e5,1e6),
              startRatio = seq(0,1,0.05))

# results <- omPCRBatch(simModel,
#                       simPath,
#                       override=mpara,
#                       nestedList=nlist,
#                       logdir=expName,
#                       project=title,
#                       details = FALSE,
#                       expName=expName)

results <- readRDS(paste0(mPath,path_sim,"Sim_",title,"/results/results.rds"))

results$sprop <- results$par_startRatio
results$prop <- results$ratio
results$sratio <- results$sprop/(1-results$sprop)
results$slratio <- log(results$sratio)
results$ratio <- results$prop/(1-results$prop)
results$sT <- results$par_startTemplate 
results$sA <- results$sT * results$sprop
results$sB <- results$sT * (1- results$sprop)
results$difA <- results$totalA -results$sA
results$difB <- results$totalB -results$sB
results$difT <- results$totalT -results$sT
results$effA <- results$difA/results$sA 
results$effB <- results$difB/results$sB 
results$effT <- results$difT/results$sT 


```
