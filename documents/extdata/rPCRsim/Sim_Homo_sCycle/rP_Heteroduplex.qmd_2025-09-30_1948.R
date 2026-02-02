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
              startRatio = seq(0.0,1,0.05))

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
results$lratio <- log(results$ratio)
results$sT <- results$par_startTemplate 
results$sA <- results$sT * results$sprop
results$sB <- results$sT * (1- results$sprop)
results$difA <- results$totalA -results$sA
results$difB <- results$totalB -results$sB
results$difT <- results$totalT -results$sT
results$effA <- results$difA/results$sA 
results$effB <- results$difB/results$sB
results$effT <- results$difT/results$sT

results <- results  %>%
  mutate(homo = AaAs.c +  BaBs.c +  AaAsPoly.c + BaBsPoly.c ,
         hetero = AaBs.c + AsBa.c + AaBsPoly.c + AsBaPoly.c,
         homoA = AaAs.c + AaAsPoly.c,
         homoB = BaBs.c + BaBsPoly.c)
         


```

The Simulation data show that heterodeuplex formation leads to a greater amplification efficiency. Re-annealing of the amplicon strands inhibit the generation of new strands.

The degree of inhibition depends on the kinetic properties of the re-annealing reaction. As heteroduplex do not perfectly match the re-annelaing rate and therefore the inhibition is reduced leading to increas amplification efficiency. In rPCR the relative amount of heteroduplexes is maximum at equal template amounts. In Figure

```{r}

results <- results  %>%
  mutate(homo = AaAs.c +  BaBs.c +  AaAsPoly.c + BaBsPoly.c ,
         hetero = AaBs.c + AsBa.c + AaBsPoly.c + AsBaPoly.c)

sel <- results[results$par_hetero_k1==1e6,]

# ggplot(data=sel) +
#   geom_line(aes(x=par_startRatio,y=hetero/totalT,group=interaction(par_hetero_k1,par_startTemplate)),col=3) +
#   geom_line(aes(x=par_startRatio,y=homo/totalT,group=interaction(par_hetero_k1,par_startTemplate)),col=2) +
#   geom_line(aes(x=par_startRatio,y=difT/totalT,group=interaction(par_hetero_k1,par_startTemplate)),col=1) +
#   ylim(0,1)

plist <- list()

plist[[1]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=par_startRatio,y=(homo-2*difT)/sT*100,group=sT,col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal")  + ylim(-1,100) + xlab("proportion") + ylab("re-annealing of homoduplex (%)")

plist[[2]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=par_startRatio,y=hetero/sT*100,group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal") + ylim(-1,100) + xlab("proportion") + ylab("re-annealing of heteroduplex (%)")



# plist[[3]] <- ggplot() + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
#   geom_line(data=sel,aes(x=par_startRatio,y=hetero/(homo + hetero),group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
#   theme(legend.position = "right",
#         legend.direction = "vertical",
#         legend.box = "horizontal") + ylim(0,1) + xlab("proportion") + ylab("duplex (%)")
  
plist[[4]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=par_startRatio,y=(homo-2*difT+hetero)/sT*100,group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal") + ylim(-1,100) + xlab("proportion") + ylab("total re-annealing (%)")

  
  
plist[[5]] <- ggplot() + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(data=sel,aes(x=par_startRatio,y=effT*100,group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal") + ylim(-1,100) + xlab("proportion") + ylab("total efficiency (%)")

plist[[6]] <- ggplot() + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(data=sel,aes(x=par_startRatio,y=difT,group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal")+ xlab("proportion") + ylab("new amplicons (M)")



# plist[[7]] <- ggplot() + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
#   geom_line(data=sel,aes(x=hetero/(hetero+homo),y=effT,group=interaction(sT),col=sT)) +
#   theme(legend.position = "right",
#         legend.direction = "vertical",
#         legend.box = "horizontal")


plot <- ggarrange(plotlist=plist[c(1,2,4,5,6)],ncol=5,nrow=1,common.legend=TRUE,legend="right")

ggsave(
  paste0(fpath, "Hetero_sCycle_1e6_total.pdf"),
  plot,
  width = 6,
  height = 3,
  dpi = 600,
  units = "cm"
)

```



```{r}
sel <- results[results$par_hetero_k1==3e5,]

# ggplot(data=sel) +
#   geom_line(aes(x=par_startRatio,y=hetero/totalT,group=interaction(par_hetero_k1,par_startTemplate)),col=3) +
#   geom_line(aes(x=par_startRatio,y=homo/totalT,group=interaction(par_hetero_k1,par_startTemplate)),col=2) +
#   geom_line(aes(x=par_startRatio,y=difT/totalT,group=interaction(par_hetero_k1,par_startTemplate)),col=1) +
#   ylim(0,1)

plist <- list()

plist[[1]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=par_startRatio,y=(homo-2*difT)/sT*100,group=sT,col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal")  + ylim(-1,100) + xlab("proportion") + ylab("re-annealing of homoduplex (%)")

plist[[2]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=par_startRatio,y=hetero/sT*100,group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal") + ylim(-1,100) + xlab("proportion") + ylab("re-annealing of heteroduplex (%)")



# plist[[3]] <- ggplot() + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
#   geom_line(data=sel,aes(x=par_startRatio,y=hetero/(homo + hetero),group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
#   theme(legend.position = "right",
#         legend.direction = "vertical",
#         legend.box = "horizontal") + ylim(0,1) + xlab("proportion") + ylab("duplex (%)")
  
plist[[4]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=par_startRatio,y=(homo-2*difT+hetero)/sT*100,group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal") + ylim(-1,100) + xlab("proportion") + ylab("total re-annealing (%)")

  
  
plist[[5]] <- ggplot() + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(data=sel,aes(x=par_startRatio,y=effT*100,group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal") + ylim(-1,100) + xlab("proportion") + ylab("total efficiency (%)")

plist[[6]] <- ggplot() + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(data=sel,aes(x=par_startRatio,y=difT,group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal")+ xlab("proportion") + ylab("new amplicons (M)")



# plist[[7]] <- ggplot() + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
#   geom_line(data=sel,aes(x=hetero/(hetero+homo),y=effT,group=interaction(sT),col=sT)) +
#   theme(legend.position = "right",
#         legend.direction = "vertical",
#         legend.box = "horizontal")


plot <- ggarrange(plotlist=plist[c(1,2,4,5,6)],ncol=5,nrow=1,common.legend=TRUE,legend="right")

ggsave(
  paste0(fpath, "Hetero_sCycle_3e5_total.pdf"),
  plot,
  width = 6,
  height = 3,
  dpi = 600,
  units = "cm"
)

```




```{r}


### oonly template A

sel <- results[results$par_hetero_k1==3e5,]

# ggplot(data=sel) +
#   geom_line(aes(x=par_startRatio,y=hetero/totalT,group=interaction(par_hetero_k1,par_startTemplate)),col=3) +
#   geom_line(aes(x=par_startRatio,y=homo/totalT,group=interaction(par_hetero_k1,par_startTemplate)),col=2) +
#   geom_line(aes(x=par_startRatio,y=difT/totalT,group=interaction(par_hetero_k1,par_startTemplate)),col=1) +
#   ylim(0,1)

plist <- list()

plist[[1]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=par_startRatio,y=(homoA-2*difA)/sA*100,group=sT,col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal")  + ylim(-1,100) + xlab("proportion") + ylab("re-annealing of homoduplex (%)")

plist[[2]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=par_startRatio,y=(hetero/2)/sA*100,group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal") + ylim(-1,100) + xlab("proportion") + ylab("re-annealing of heteroduplex (%)")



plist[[3]] <- ggplot() + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(data=sel,aes(x=par_startRatio,y=hetero/(homoA*2 + hetero),group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal") + ylim(0,1) + xlab("proportion") + ylab("template A heteroduplex (%)")

plist[[4]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=par_startRatio,y=(homoA-2*difA+hetero/2)/sA*100,group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal") + ylim(-1,100) + xlab("proportion") + ylab("total re-annealing (%)")

  
  
plist[[5]] <- ggplot() + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(data=sel,aes(x=par_startRatio,y=effA*100,group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal") + ylim(-1,100) + xlab("proportion") + ylab("efficiency (%)")

plist[[6]] <- ggplot() + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(data=sel,aes(x=par_startRatio,y=difA,group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal")+ xlab("proportion") + ylab("new amplicons (M)")



# plist[[7]] <- ggplot() + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
#   geom_line(data=sel,aes(x=hetero/(hetero+homo),y=effT,group=interaction(sT),col=sT)) +
#   theme(legend.position = "right",
#         legend.direction = "vertical",
#         legend.box = "horizontal")


plot <- ggarrange(plotlist=plist[c(1,2,4,5)],ncol=4,nrow=1,common.legend=TRUE,legend="right")

ggsave(
  paste0(fpath, "Hetero_sCycle_3e5_templateA.pdf"),
  plot,
  width = 6,
  height = 3,
  dpi = 600,
  units = "cm"
)


```





```{r}


### only template B

sel <- results[results$par_hetero_k1==3e5,]

# ggplot(data=sel) +
#   geom_line(aes(x=par_startRatio,y=hetero/totalT,group=interaction(par_hetero_k1,par_startTemplate)),col=3) +
#   geom_line(aes(x=par_startRatio,y=homo/totalT,group=interaction(par_hetero_k1,par_startTemplate)),col=2) +
#   geom_line(aes(x=par_startRatio,y=difT/totalT,group=interaction(par_hetero_k1,par_startTemplate)),col=1) +
#   ylim(0,1)

plist <- list()

plist[[1]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=par_startRatio,y=(homoB-2*difB)/sB*100,group=sT,col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal")  + ylim(-1,100) + xlab("proportion") + ylab("re-annealing of homoduplex (%)")

plist[[2]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=par_startRatio,y=(hetero/2)/sB*100,group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal") + ylim(-1,100) + xlab("proportion") + ylab("re-annealing of heteroduplex (%)")



plist[[3]] <- ggplot() + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(data=sel,aes(x=par_startRatio,y=hetero/(homoA*2 + hetero),group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal") + ylim(0,1) + xlab("proportion") + ylab("template A heteroduplex (%)")

plist[[4]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=par_startRatio,y=(homoB-2*difB+hetero/2)/sB*100,group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal") + ylim(-1,100) + xlab("proportion") + ylab("total re-annealing (%)")

  
  
plist[[5]] <- ggplot() + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(data=sel,aes(x=par_startRatio,y=effB*100,group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal") + ylim(-1,100) + xlab("proportion") + ylab("efficiency (%)")

plist[[6]] <- ggplot() + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(data=sel,aes(x=par_startRatio,y=difB,group=interaction(par_hetero_k1,par_startTemplate),col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal")+ xlab("proportion") + ylab("new amplicons (M)")



# plist[[7]] <- ggplot() + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
#   geom_line(data=sel,aes(x=hetero/(hetero+homo),y=effT,group=interaction(sT),col=sT)) +
#   theme(legend.position = "right",
#         legend.direction = "vertical",
#         legend.box = "horizontal")


plot <- ggarrange(plotlist=plist[c(1,2,4,5)],ncol=4,nrow=1,common.legend=TRUE,legend="right")

ggsave(
  paste0(fpath, "Hetero_sCycle_3e5_templateB.pdf"),
  plot,
  width = 6,
  height = 3,
  dpi = 600,
  units = "cm"
)


```


```{r}
plist <- list()

sel <- results[results$par_hetero_k1==1e6,]

plist[[1]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=par_startRatio,y=effA/effB,group=sT,col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal")   + xlab("proportion") + ylab(" efficiency ratio (template A/template B)") + scale_y_log10(limits = c(0.5,2))




plist[[2]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=effA,y=effB,group=sprop,col=sprop)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal")  +
  labs(x="template A efficiency", y="template B efficiency",, color = "proportion")

plist[[7]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=sprop,y=prop-sprop,group=sT,col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal")  +
  labs(x="template proportion", y="residuals (amplicon proportion - template proportion",, color = "proportion")+ ylim(-0.015,+0.015)

sel <- results[results$par_hetero_k1==6e5,]

plist[[3]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=par_startRatio,y=effA/effB,group=sT,col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal")   + xlab("proportion") + ylab(" efficiency ratio (template A/template B)") + scale_y_log10(limits = c(0.5,2))




plist[[4]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=effA,y=effB,group=sprop,col=sprop)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal")  +
  labs(x="template A efficiency", y="template B efficiency",, color = "proportion")

plist[[8]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=sprop,y=prop-sprop,group=sT,col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal")  +
labs(x="template proportion", y="residuals (amplicon proportion - template proportion",, color = "proportion")+ ylim(-0.015,+0.015)



sel <- results[results$par_hetero_k1==3e5,]

plist[[5]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=par_startRatio,y=effA/effB,group=sT,col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal")   + xlab("proportion") + ylab(" efficiency ratio (template A/template B)") + scale_y_log10(limits = c(0.5,2))




plist[[6]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=effA,y=effB,group=sprop,col=sprop)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal")  +
  labs(x="template A efficiency", y="template B efficiency",, color = "proportion")

plist[[9]] <- ggplot(data=sel) + theme_rpcr() + theme_figure + scale_color_viridis(discrete=FALSE) +
  geom_line(aes(x=sprop,y=prop-sprop,group=sT,col=sT)) +
  theme(legend.position = "right",
        legend.direction = "vertical",
        legend.box = "horizontal")  +
labs(x="template proportion", y="residuals (amplicon proportion - template proportion",, color = "proportion") + ylim(-0.015,+0.015)


ggarrange(ggarrange(plotlist=plist[c(2,4,6)],ncol=3,nrow=1,common.legend=TRUE,legend="right"),
ggarrange(plotlist=plist[c(1,3,5)],ncol=3,nrow=1,common.legend=TRUE,legend="right"),
ggarrange(plotlist=plist[c(7,8,9)],ncol=3,nrow=1,common.legend=TRUE,legend="right")
,nrow=3)

ggsave(
  paste0(fpath, "Hetero_sCycle_summary.pdf"),
  plot,
  width = 6,
  height = 3,
  dpi = 600,
  units = "cm"
)

```




```{r}  
  
ggplot(data=results[results$par_hetero_k1==3e5,]) +
  geom_line(aes(x=par_startRatio,y=difT/totalT,col=factor(par_startTemplate),group=interaction(par_hetero_k1,par_startTemplate))) 

ggplot(data=results[results$par_hetero_k1==3e5,]) +
  geom_line(aes(x=par_startRatio,y=(AaAs.c+BaBs.c+AaBs.c+AsBa.c)/(totalT-difT),col=factor(par_startTemplate),group=interaction(par_hetero_k1,par_startTemplate))) 

ggplot(data=results[results$par_hetero_k1==3e5,]) +
  geom_line(aes(x=par_startRatio,y=(AaAs.c+BaBs.c)/(AaAs.c+BaBs.c+AaBs.c+AsBa.c),col=factor(par_startTemplate),group=interaction(par_hetero_k1,par_startTemplate))) 
 




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

drift <- function(x,a,b,c,d,e=1) {
   x[x==1] <- NA
   lratio <- exp(log(x/(1-x)) - log(d/(1-d)))
   # nx <- lratio/(1+lratio)
   nratio <- exp(log(lratio)*(e-c*x^a*(1-x)^b ))
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

Formulas to approximate the efficiency:
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
results$lratio <- log(results$ratio)
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




```{r}

sel <- results[results$par_hetero_k1==3e5,]
pdrift <- function(x,a,b,c,d,e=1) {
   x[x==1] <- NA
   lratio <- exp(log(x/(1-x)) - log(d/(1-d)))
   nratio <- exp(log(lratio)*(e-c*x^a*(1-x)^b ))
   out <- nratio/(nratio+1)
   out[is.na(x)] <- 1
   return(out)
}

rdrift <- function(x,a,b,c,d,e=1) {
   prop <- exp(x)/(1+exp(x))
   out <- (x-log(d/(1-d)))*(e-c*prop^a*(1-prop)^b )
   return(out)
}


sfit <- function(df) {
  df <- df[is.finite(df$slratio),]
  df$qt <- df$ratio/df$sratio
  sdrift <- function(x,a,b,c,d) {
    z <- x/(1-x)*(a+b*cos(c*log(x/(1-x))+d))
    z/(1+z)
    }
  
  nlsLM(prop ~ sdrift(sprop,a,b,c,d),
        data=df,
        start=list(a=1,b=1,c=1,d=1),
        upper=c(a=Inf,b=Inf,c=Inf,d=Inf),
        lower=c(a=-Inf,b=-Inf,c=-Inf,d=-Inf),
        control = nls.lm.control(ftol = 1e-7)
        )
}

rfit <- function(df) {
    df <- df[is.finite(df$slratio),]
    nlsLM(lratio ~ rdrift(slratio,a,b,c,d),
          data=df,
          start=list(a=0.2,b=0.2,c=0,d=0.4),
          upper=c(a=Inf,b=Inf,c=Inf,d=1),
          lower=c(a=-Inf,b=-Inf,c=-Inf,d=0)
    )
}

   odrift <- function(x,a) {
     z <- a^(1-2*x)*x
     z/(z+1-x)
   }
   
ndrift <- function(x,a,b) {
     (a*x+b*x^2)/((a-1)*x+b*x^2+1)
   }
   
ofit <- function(df) {
  

  nlsLM(prop ~ odrift(sprop,a),
        data=df,
        start=list(a=1),
        upper=c(a=Inf),
        lower=c(a=-Inf)
        )
}

nfit <- function(df) {
  

  nlsLM(prop ~ ndrift(sprop,a,b),
        data=df,
        start=list(a=1,b=0),
        upper=c(a=Inf,b=Inf),
        lower=c(a=-Inf,b=-Inf)
        )
}


pfit <- function(df) {
  nlsLM(prop ~ pdrift(sprop,a,b,c,d),
        data=df,
        start=list(a=0.2,b=0.2,c=0,d=0.4),
        upper=c(a=Inf,b=Inf,c=Inf,d=1),
        lower=c(a=-Inf,b=-Inf,c=-Inf,d=0)
        )
}

pres <- lapply(unique(sel$sT)[-1], function(template){
   df <- sel[sel$sT==template,c("sprop","sratio","slratio","effT","prop","ratio")]
   pfit(df)
})


rres <- lapply(unique(sel$sT)[-1], function(template){
  df <- sel[sel$sT==template,c("sprop","sratio","slratio","effT","prop","ratio","lratio")]
  rfit(df)
})

sres <- lapply(unique(sel$sT)[-1], function(template){
  df <- sel[sel$sT==template,c("sprop","sratio","slratio","effT","prop","ratio","lratio")]
  sfit(df)
})


plot(residuals(res[[3]]))
para <- coef(res[[3]])
df <- results[results$par_hetero_k1==3e5&results$sT==unique(sel$sT)[-1][6],]

df0 <- do.call(pdrift, c(x = list(df$prop),as.list(coef(pfit(df)))))
      
```

```{r}
title <- "Hetero_asyProbe_full"
expName <- paste0("Sim_",title)
para <- stdPara
para$stepSize <- para$cycle_time
para$cycle_max<-45
para$stopTime <-para$cycle_time * para$cycle_ma

para$rehybA_k1 = 1e6
para$rehybB_k1 = 2e6
para$ProbeA <- 400 * 1e-9
para$ProbeB <- 400 * 1e-9

para$ProbeA_k1 <- 5e5
para$ProbeB_k1 <- 3e5

template <- seq(1e-18,para$startPrimer/100,length.out=10)

mpara <- cbind(para, rep(1,length(template)))
mpara$startTemplate <- template

nlist <- list(hetero_k1 = c(3e5,6e5,1e6),
              startRatio = seq(0,1,0.05))

results <- omPCRBatch(simModel,
                      simPath,
                      override=mpara,
                      nestedList=nlist,
                      logdir=expName,
                      project=title,
                      details = FALSE,
                      expName=expName)

results <- readRDS(paste0(mPath,path_sim,"Sim_",title,"/results/results.rds"))

results$sprop <- results$par_startRatio
results$prop <- results$ratio
results$sratio <- results$sprop/(1-results$sprop)
results$slratio <- log(results$sratio)
results$ratio <- results$prop/(1-results$prop)
results$lratio <- log(results$ratio)
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



```{r}

fdrift <- function(x,a,b,c,d) {
     (a+b*x)/(1+c*x+d*x^2)
   }
   

ffit <- function(df) {

  nlsLM(sprop ~ fdrift(fprop,a,b,c,d),
        data=df,
        start=list(a=0,b=0,c=0,d=0),
        )
}

zdrift <- function(x,a,b,c,d) {
     a+b*cos(c*x+d)
   }
   

zfit <- function(df) {

  nlsLM(sprop ~ zdrift(prop,a,b,c,d),
        data=df,
        start=list(a=0.5,b=0.5,c=1,d=2),
        )
}





df0 <- do.call(fdrift, c(x = list(df$prop),as.list(coef(ffit(df)))))
```

