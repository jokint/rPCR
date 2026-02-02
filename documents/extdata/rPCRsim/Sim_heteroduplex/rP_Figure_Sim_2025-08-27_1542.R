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



### Standard

para <- stdPara


title <- "standard"
expName <- paste0("Sim",format(Sys.time(), "%Y%m%d_%H%M%S"),"_",title)
expName <- paste0("Sim_",title)

nlist <- list(startRatio = seq(0,1,0.1))



plist <- unlist(lapply(seq_along(nlist),function(x) {
  if (is.matrix(nlist[[x]])){
    if (ncol(nlist[[x]])>1) rownames(nlist[[x]])
  } else {
    if (length(nlist[[x]])>1) names(nlist[x])
  }}))
plist <- unique(c(unlist(lapply(colnames(para), function(x){ x[length(unique(para[,x]))>1]})),plist))
plist <- paste0("par_",plist)

# results <- omPCRBatch(simModel,
#                       simPath,
#                       override=para,
#                       nestedList=nlist,
#                       logdir=expName,
#                       project=title,
#                       details = FALSE,
#                       expName=expName)

results <- readRDS(paste0(mPath,path_sim,"Sim_",title,"/results/results.rds"))

df0 <- omTrans(results)

plots <- rpcr_plotPanel(df0)


figure <- ggarrange(plotlist = plots,
                    ncol = 4,
                    labels = c("A","B","C","D"),
                    common.legend = TRUE,
                    legend="none",
                    widths = c(2,1,1,1),
                    font.label=list(color="black",size=10))



psave(paste0("Figure_Sim_",title),
      figure,
      dpi = 300,
      width = 18,
      height = 4,
      device = "pdf")


### Standard kinetic

para <- stdPara
para$stepSize <- 0.5
para$startRatio = 0.6

title <- "standard_kinetic"
expName <- paste0("Sim",format(Sys.time(), "%Y%m%d_%H%M%S"),"_",title)
expName <- paste0("Sim_",title)


# results <- omPCRBatch(simModel,
#                       simPath,
#                       override=para,
#                       nestedList=NULL,
#                       logdir=expName,
#                       project=title,
#                       details = TRUE,
#                       expName=expName)

results <- readRDS(paste0(mPath,path_sim,"Sim_",title,"/results/results.rds"))



df0 <- omTrans(results)

p1 <- ggplot(data=df0) +
  geom_line(aes(x=time,y=Fincl),alpha=0.2,col=rpcr_col_probe[[1]],linetype=2) +
  geom_point(data=df0[(df0$time-(df0$cycle-1)*45)==45,],aes(x=time,y=Fincl),col=rpcr_col_probe[[1]]) +
  geom_line(aes(x=time,y=Fexcl),alpha=0.2,col=rpcr_col_probe[[3]],linetype=2) +
  geom_point(data=df0[(df0$time-(df0$cycle-1)*45)==45,],aes(x=time,y=Fexcl),col=rpcr_col_probe[[3]]) +
  theme_rpcr()

p <- list()
cycles <- c(1,23,45)

p <-lapply(cycles, function(cycle) {
p <- list()
p$template <- ggplot(data=df0[df0$cycle==cycle,]) +
  geom_line(aes(x=time,y=Fincl),col=rpcr_col_probe[[1]]) +
  geom_line(aes(x=time,y=Fexcl),col=rpcr_col_probe[[3]]) +
  theme_rpcr() + theme_figure +
  scale_y_continuous(label= function(x)  gsub("\\-0","-",gsub("\\+0", "", formatC(x, format = "e", digits = 1))))

p$primer <- ggplot(data=df0[df0$cycle==cycle,]) +
  geom_line(aes(x=time,y=totalPra)) +
  theme_rpcr() + theme_figure +
  scale_y_continuous(label= function(x)  gsub("\\-0","-",gsub("\\+0", "", formatC(x, format = "e", digits = 1))))

p$hetero <- ggplot(data=df0[df0$cycle==cycle,]) +
  geom_line(aes(x=time,y=AaBs.c + AsBa.c)) +
  theme_rpcr() + theme_figure +
  scale_y_continuous(label= function(x)  gsub("\\-0","-",gsub("\\+0", "", formatC(x, format = "e", digits = 1))))

p
})


p$template <- ggplot(data=df0[df0$cycle %in% cycles,]) +
  geom_line(aes(x=time-(cycle-1)*45,y=Fincl,linetype=factor(cycle)),col=rpcr_col_probe[[1]]) +
  geom_line(aes(x=time-(cycle-1)*45,y=Fexcl,linetype=factor(cycle)),col=rpcr_col_probe[[3]]) +
  theme_rpcr() + theme_figure + scale_linetype_discrete() +
  theme(axis.title.y = element_blank(),
        axis.title.x = element_blank(),
        legend.position="none")
p$primer <- ggplot(data=df0[df0$cycle %in% cycles,]) +
  geom_line(aes(x=time-(cycle-1)*45,y=totalPra,linetype=factor(cycle))) +
  theme_rpcr() + theme_figure +
  theme(axis.title.y = element_blank(),
        axis.title.x = element_blank(),
        legend.position="none")

p$hetero <- ggplot(data=df0[df0$cycle %in% cycles,]) +
  geom_line(aes(x=time-(cycle-1)*45,y=AaBs.c + AsBa.c,linetype=factor(cycle))) +
  theme_rpcr() + theme_figure +
  theme(axis.title.y = element_blank(),
        axis.title.x = element_blank(),
        legend.position="none")


#
# p$template <- ggplot(data=df0) +
#   geom_line(aes(x=time-(cycle-1)*45,y=Fincl,alpha=cycle,group=cycle),col=rpcr_col_probe[[1]]) +
#   geom_line(aes(x=time-(cycle-1)*45,y=Fexcl,alpha=cycle,group=cycle),col=rpcr_col_probe[[3]]) +
#   theme_rpcr() + theme( plot.background = element_rect(colour = "black", fill=NA, linewidth=0.5)) + scale_linetype_discrete()
#
# p$primer <- ggplot(data=df0) +
#   geom_line(aes(x=time-(cycle-1)*45,y=totalPra,col=cycle,group=cycle)) +
#   theme_rpcr() + theme( plot.background = element_rect(colour = "black", fill=NA, linewidth=0.5))
#
# # p$primer_rel <- ggplot(data=df0) +
# #   geom_line(aes(x=time-(cycle-1)*45,y=totalPra,col=cycle,group=cycle)) +
# #   theme_rpcr() + theme( plot.background = element_rect(colour = "black", fill=NA, linewidth=0.5))
#
# p$hetero <- ggplot(data=df0) +
#   geom_line(aes(x=time-(cycle-1)*45,y=AaBs.c + AsBa.c,alpha=cycle,group=cycle)) +
#   theme_rpcr() + theme( plot.background = element_rect(colour = "black", fill=NA, linewidth=0.5)) +
#   scale_alpha_continuous(limits=c(0,1))



psave(paste0("Figure_Sim_",title), p1, dpi = 300, width = 15.5, height = 9, device = "pdf")

lapply(1:3, function(cycle){
psave(paste0("Figure_Sim_",title,"_c",cycles[cycle],"_template"),p[[cycle]]$template, dpi = 300, width = 2.5, height = 1.5, device = "pdf")
psave(paste0("Figure_Sim_",title,"_c",cycles[cycle],"_primer"),p[[cycle]]$primer, dpi = 300, width = 2.5, height = 1.5, device = "pdf")
psave(paste0("Figure_Sim_",title,"_c",cycles[cycle],"_hetero"),p[[cycle]]$hetero, dpi = 300, width = 2.5, height = 1.5, device = "pdf")
})

psave(paste0("Figure_Sim_",title,"_template"), p$template, dpi = 300, width = 2.5, height = 1.5, device = "pdf")
psave(paste0("Figure_Sim_",title,"_primer"), p$primer, dpi = 300, width = 2.5, height = 1.5, device = "pdf")
psave(paste0("Figure_Sim_",title,"_hetero"), p$hetero, dpi = 300, width = 2.5, height = 2.5, device = "pdf")



p_c3_template <- ggplot(data=df0[df0$cycle==1,]) +
  geom_line(aes(x=time,y=Fincl),col=rpcr_col_probe[[1]]) +
  geom_line(aes(x=time,y=Fexcl),col=rpcr_col_probe[[3]]) +
  theme_rpcr() + theme( plot.background = element_rect(colour = "black", fill=NA, linewidth=0.5))


df1 <- pivot_longer(data = df0,
   cols =c("totalAa","totalBa","AsBa.c"),
     values_to="value")

p1 <- ggplot(data=results[results$cycle %in% c(1:3),]) + geom_line(aes(x=time,y=totalAa),col=rpcr_col_probe[[1]]) + geom_line(aes(x=time,y=totalBa),col=rpcr_col_probe[[3]])+ facet_wrap(.~cycle, scales="free") + theme_rpcr()
p2 <- ggplot(data=results[results$cycle %in% c(23:25),]) + geom_line(aes(x=time,y=totalAa),col=rpcr_col_probe[[1]]) + geom_line(aes(x=time,y=totalBa),col=rpcr_col_probe[[3]])+ facet_wrap(.~cycle, scales="free") + theme_rpcr()
p3 <- ggplot(data=results[results$cycle %in% c(27:29),]) + geom_line(aes(x=time,y=totalAa),col=rpcr_col_probe[[1]]) + geom_line(aes(x=time,y=totalBa),col=rpcr_col_probe[[3]])+ facet_wrap(.~cycle, scales="free") + theme_rpcr()



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

nlist <- list(hetero_k1 = seq(3e5,1e6,1e5),
              startRatio = seq(0,1,0.1))



plist <- unlist(lapply(seq_along(nlist),function(x) {
  if (is.matrix(nlist[[x]])){
    if (ncol(nlist[[x]])>1) rownames(nlist[[x]])
  } else {
    if (length(nlist[[x]])>1) names(nlist[x])
  }}))
plist1 <- unique(c(unlist(lapply(colnames(para), function(x){ x[length(unique(para[,x]))>1]})),plist))
plist <- paste0("par_",plist1)

# results <- omPCRBatch(simModel,
#                       simPath,
#                       override=para,
#                       nestedList=nlist,
#                       logdir=expName,
#                       project=title,
#                       details = FALSE,
#                       expName=expName)

results <- readRDS(paste0(mPath,path_sim,"Sim_",title,"/results/results.rds"))

df0 <- omTrans(results)

plots <- rpcr_plotPanel(df0)

figure <- ggarrange(plotlist = plots,
                    ncol = 4,
                    labels = c("A","B","C","D"),
                    common.legend = TRUE,
                    legend="none",
                    widths = c(2,1,1,1),
                    font.label=list(color="black",size=10))



psave(paste0("Figure_Sim_",title),
      figure,
      dpi = 300,
      width = 18,
      height = 4,
      device = "pdf")



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

