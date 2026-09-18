### Settings for figures

# loading libraries
library(ratioPCR)
library(tidyverse)
library(readxl)
library(ggplot2)
library(ggpubr)
library(patchwork)

pp <- here::here()
fpath <- file.path(pp,"documents","figures")


# variable definiton
genelist <- c("NUMA1","SYNE1","KIF13A")
datalist <- c("F","bF")
modellist <- c("linear","single")


# List of standards used for the calibration curve
psiCal <- c(0, 0.05, 0.15, 0.25, 0.35, 0.5, 0.65, 0.75, 0.85, 0.95, 1)
tPSI <- rep(psiCal, each = 3)



rpcr_col_target <-  c("#4DBBD5FF","#3C5488FF","#F39B7FFF","#8491B4FF","#91D1C2FF","#DC0000FF","#7E6148FF","#B09C85FF")
rpcr_col_probe <- c("#E64B35FF","#FFE064FF","#00A087FF")

rpcr_col_sample <- grDevices::colorRampPalette(c("grey90", "grey30"))

colplot = TRUE

if (!exists("figures")) figures <- list()
if (!exists("res")) res <- list()

standardSettings <- data.frame(signal = "Rn",
                               tres = "0:0",
                               rtype = "dynamic:dynamic",
                               roff = "0:0",
                               model = "linear",
                               method = "incl:total",
                               calib = "1:0:0:1",
                               average = TRUE,
                               offset=1,
                               derivative = FALSE,
                               baseline = FALSE)

psave <- function(filename, plot, device="pdf",path=fpath,units="cm",dpi=300, ext = NULL,...)
  ggsave(filename=paste0(filename,".",device),plot=plot,device=device, path=path,units=units,dpi=dpi, ...)


