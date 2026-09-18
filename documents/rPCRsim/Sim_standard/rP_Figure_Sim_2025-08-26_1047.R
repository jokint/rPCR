### SImulations

library(ggplot2)
library(plotly)
library(rPCR)

source("/scicore/home/sinnreic/kinter/R projects/rPCR/documents/scripts/rPCR_Figure_0_Init.R")
source("/scicore/home/sinnreic/kinter/R projects/rPCR/documents/rPCRsim/omPCR_functions.R")
ppath <- "/scicore/home/sinnreic/kinter/R projects/rPCR/"
pretag <- "Figure_Sim_"
 tag <- paste0(pretag,format(Sys.time(), "%d%m%Y_%H%M%S"))

fpath <- paste0(ppath,"documents/figures/",tag,"/")

para <- data.frame(
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
  Polymerase = 1e-7,
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




mPath <- "/scicore/home/sinnreic/kinter"
path_sim <- "/R\ projects/rPCR/documents/rPCRsim/"
path_model <- "/openmodelica/"
simModel <- "rPCR_03"
simPath <- paste0(mPath, path_model, simModel, "/")
para$stopTime <- para$cycle_time*para$cycle_max
para$stepSize <- para$cycle_time



### Standard

para$stepSize <- 0.5

title <- "standard"
expName <- paste0("Sim",format(Sys.time(), "%Y%m%d_%H%M%S"),"_",title)
expName <- paste0("Sim_",title)

nlist <- list()



plist <- unlist(lapply(seq_along(nlist),function(x) {
  if (is.matrix(nlist[[x]])){
    if (ncol(nlist[[x]])>1) rownames(nlist[[x]])
  } else {
    if (length(nlist[[x]])>1) names(nlist[x])
  }}))
plist <- unique(c(unlist(lapply(colnames(para), function(x){ x[length(unique(para[,x]))>1]})),plist))
if (auto) title <- paste(plist,collapse="_")
plist <- paste0("par_",plist)

results <- omPCRBatch(simModel,
                      simPath,
                      override=para,
                      nestedList=nlist,
                      logdir=expName,
                      project=title,
                      details = TRUE,
                      expName=expName)

df0 <- results
df0$well <- interaction(df0$par_startRatio,df0$par_hetero_k1,sep = "_")
df0$Fincl <- df0$totalA
df0$Fexcl <- df0$totalB
df0$Ftotal <- df0$totalT
df0$target <- "Simulation"
df0$sample <- df0$par_startRatio
df0$rcycle <- rpcr_batch("rpcr_relCycle", df0, id_col = c("Ftotal","cycle"))


p1 <- ggplot(data=results) + geom_line(aes(x=totalA,y=totalB,col=par_hetero_k1,group=interaction(par_startRatio,par_hetero_k1)))


ttt1 <- rpcr_plotData(df0,colplot=TRUE,alpha="par_hetero_k1", color_probe = rpcr_col_probe)

plots <- lapply(3:5, function(x) ttt1[[x]]+  scale_alpha_continuous(range = c(0.2, 1)))

  plot <- ggplot() +
  theme_rpcr() +
  theme(axis.text.y = element_text(size = 6, face = "plain"),
        axis.text.x = element_text(size = 6),
        panel.grid.major = element_blank(),
        axis.text = element_text(size = 6),
        axis.title = element_text(face = "plain"),
        axis.title.y = element_text(vjust = 0),
        strip.placement = "outside",
        strip.text.y = element_text(vjust = 0, size = 8))


  wline <- 0.5
  slabel <- 6
  stitle <- 8


psave(paste0("Figure_Sim",title),
      p1,
      dpi = 300,
      width = 18,
      height = 18,
      device = "pdf")

### Heteroduplex

title <- "heteroduplex"
para$stepSize <- para$cycle_time
expName <- paste0("Sim",format(Sys.time(), "%Y%m%d_%H%M%S"),"_",title)
expName <- paste0("Sim_",title)

nlist <- list(hetero_k1 = seq(1e5,1e6,1e5),
              startRatio = seq(0,1,0.1))



plist <- unlist(lapply(seq_along(nlist),function(x) {
  if (is.matrix(nlist[[x]])){
    if (ncol(nlist[[x]])>1) rownames(nlist[[x]])
  } else {
    if (length(nlist[[x]])>1) names(nlist[x])
  }}))
plist <- unique(c(unlist(lapply(colnames(para), function(x){ x[length(unique(para[,x]))>1]})),plist))
if (auto) title <- paste(plist,collapse="_")
plist <- paste0("par_",plist)

results <- omPCRBatch(simModel,
                      simPath,
                      override=para,
                      nestedList=nlist,
                      logdir=expName,
                      project=title,
                      details = FALSE,
                      expName=expName)

df0 <- results
df0$well <- interaction(df0$par_startRatio,df0$par_hetero_k1,sep = "_")
df0$Fincl <- df0$totalA
df0$Fexcl <- df0$totalB
df0$Ftotal <- df0$totalT
df0$target <- "Simulation"
df0$sample <- df0$par_startRatio
df0$rcycle <- rpcr_batch("rpcr_relCycle", df0, id_col = c("Ftotal","cycle"))


p1 <- ggplot(data=results) + geom_line(aes(x=totalA,y=totalB,col=par_hetero_k1,group=interaction(par_startRatio,par_hetero_k1)))


ttt1 <- rpcr_plotData(df0,colplot=TRUE,alpha="par_hetero_k1", color_probe = rpcr_col_probe)

plots <- lapply(3:5, function(x) ttt1[[x]]+  scale_alpha_continuous(range = c(0.2, 1)))

plot <- ggplot() +
  theme_rpcr() +
  theme(axis.text.y = element_text(size = 6, face = "plain"),
        axis.text.x = element_text(size = 6),
        panel.grid.major = element_blank(),
        axis.text = element_text(size = 6),
        axis.title = element_text(face = "plain"),
        axis.title.y = element_text(vjust = 0),
        strip.placement = "outside",
        strip.text.y = element_text(vjust = 0, size = 8))


wline <- 0.5
slabel <- 6
stitle <- 8


psave(paste0("Figure_Sim",title),
      p1,
      dpi = 300,
      width = 18,
      height = 18,
      device = "pdf")
