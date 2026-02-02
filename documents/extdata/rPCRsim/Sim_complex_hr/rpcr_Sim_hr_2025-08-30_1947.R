### SImulations

library(ggplot2)
library(plotly)
library(rPCR)


source("/scicore/home/sinnreic/kinter/R projects/rPCR/documents/scripts/rPCR_Figure_0_Init.R")
source("/scicore/home/sinnreic/kinter/R projects/rPCR/documents/rPCRsim/omPCR_functions.R")
ppath <- "/scicore/home/sinnreic/kinter/R projects/rPCR/"
pretag <- "Figure_Sim_"
tag <- paste0(pretag,format(Sys.time(), "%d%m%Y_%H%M%S"))

fpath <- paste0(ppath,"documents/figures/Simulations/")

theme_figure <- theme(
  axis.text.y = element_text(size = 5, face = "plain"),
  axis.text.x = element_text(size = 5),
  panel.grid.major = element_blank(),
  axis.text = element_text(size = 5),
  axis.title = element_text(face = "plain"),
  axis.title.y = element_text(vjust = 0),
  strip.placement = "outside",
  strip.text.y = element_text(vjust = 0, size = 8),
  plot.margin = margin(0, 0, 0, 0, "cm"))


basic_plot <- ggplot() + theme_rpcr() + scale_colour_gradientn(colours = rpcr_col_probe) + theme_figure + theme(legend.position = "none")



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




mPath <- "/scicore/home/sinnreic/kinter"
path_sim <- "/R\ projects/rPCR/documents/rPCRsim/"
path_model <- "/openmodelica/"
simModel <- "rPCR_03"
simPath <- paste0(mPath, path_model, simModel, "/")
stdPara$stopTime <- stdPara$cycle_time*stdPara$cycle_max
stdPara$stepSize <- stdPara$cycle_time

### Heteroduplex

para <- stdPara

title <- "heteroduplex_hr"
para$stepSize <- para$cycle_time
expName <- paste0("Sim",format(Sys.time(), "%Y%m%d_%H%M%S"),"_",title)
expName <- paste0("Sim_",title)

nlist <- list(hetero_k1 = seq(3e5,1e6,1e5),
              startRatio = seq(0,1,0.01))


results <- omPCRBatch(simModel,
                      simPath,
                      override=para,
                      nestedList=nlist,
                      logdir=expName,
                      project=title,
                      details = FALSE,
                      expName=expName)

results <- readRDS(paste0(mPath,path_sim,"Sim_",title,"/results/results.rds"))

# old: df0 <- omTrans(results,sample="par_startRatio")
df0 <- omTrans(results,target="par_startRatio")

write.csv(ttt1,"/scicore/home/sinnreic/kinter/R projects/rPCR/documents/temp/hetero_hr.csv", row.names = FALSE)






### Complex

para <- stdPara




para$ProbeA = 300 * 1e-9
para$ProbeB = 300 * 1e-9
para$ProbeA_k1 <- 4e5
# ProbeA_k2 = 1e-3,
# ProbeB_k1 = 3e5,
# ProbeB_k2 = 1e-3,
para$hetero_k1 <- 5e5
para$rehybA_k1 <- 1.5e6
# rehybA_k2 = 1e-4,
# rehybB_k1 = 1e6,
# rehybB_k2 = 1e-4,
# RdsPoly_k1 = 1e6,
# RdsPoly_k2 = 1e-3,
# RiniPoly_k1 = 1e6,
# RiniPoly_k2 = 1e-3,
# RextPoly_k1 = 60,
para$sFluoA <- 50e6
para$sFluoB = 10e6
para$bFluoA <- 2.5
# bFluoB = 1
# lFluoA = 0,
# lFluoB = 0,
para$Aa_PB_k1 <- 2e4
para$Aa_PB_k2 <- 1e-3
# para$Ba_PA_k1 <- 2e4
# para$Ba_PA_k2 <- 1e-3
















title <- "complex_hr"
para$stepSize <- para$cycle_time
expName <- paste0("Sim_",title)

nlist <- list(startRatio = seq(0,1,0.01))

para$stepSize <- 0.5
results <- omPCRBatch(simModel,
                      simPath,
                      override=para,
                      nestedList=nlist,
                      logdir=expName,
                      project=title,
                      details = FALSE,
                      expName=expName)





results <- readRDS(paste0(mPath,path_sim,"Sim_",title,"/results/results.rds"))

# old: df0 <- omTrans(results,sample="par_startRatio")
df0 <- omTrans(results,target="par_startRatio")
