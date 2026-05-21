utils::globalVariables(
  c("FA",
    "FB",
    "TeX" ,
    "coefficients",
    "cycle",
    "data",
    "delta",
    "dincl",
    "drn",
    "dtotal",
    "dusi",
    "fill",
    "fpath",
    "incl",
    "melt",
    "par_startRatio",
    "prop",
    "ratio",
    "rn",
    "rpcr_col_probe",
    "rpcr_dpeak",
    "rtype signal",
    "tprop",
    "targetA",
    "total",
    "type",
    "usi",
    "value",
    "variable",
    "well",
    "x",
    "y"
  )
)
rpcr_col_target <-  c("#4DBBD5FF","#3C5488FF","#F39B7FFF","#8491B4FF","#91D1C2FF","#DC0000FF","#7E6148FF","#B09C85FF")
rpcr_col_probe <- c("#E64B35FF","#FFE064FF","#00A087FF")

rpcr_col_sample <- grDevices::colorRampPalette(c("grey90", "grey30"))
