#' Testing quality of calibration experiment
#'
#' @param df PCR data
#' @param ... paramters for the rpcr_batchFit, rpcr_fit and rpcr_calib routines
#' @param tPSI theoretical PSI used to calibrate the data
#'
#' @return QC parameters
#' @importFrom stats coef
#' @importFrom stats na.omit
#' @export
#'
rpcr_calibQC <- function(df, tPSI, ... ) {

  argg <- c(as.list(environment()),list(...))
  out <- list()

  ### calculating USI
  res_fit <- rpcr_calibrate(df,details=TRUE,...)
  psidata <- res_fit$details$summary

  out <- list()
  for (target in unique(psidata$target)) {
    err_msg <- ""
    ## Fitting error test
    temp <- psidata[psidata$target == target,]
    if (!length(unique(stats::na.omit(temp$tPSI))) == length(unique(temp$PSI))) err_msg <- paste(err_msg, "Fitting failed")
    calib <- if (!all(is.na(temp$USI))) rpcr_calib(temp) else NA
    psidata[psidata$target == target,]$cPSI <- if (!all(is.na(calib))) rpcr_psi(temp$USI,stats::coef(calib)) else NA
    psidata[psidata$target == target,]$delta <- temp$cPSI - temp$tPSI

    ## Calibration error test
    if (!all(unique(stats::na.omit(psidata)$tPSI)==unique(tPSI))) err_msg <- paste(err_msg, "Calibration failed")
    out[[target]] <- list(qc = if (!all(is.na(psidata$cPSI)))  mean(abs((psidata$delta))) else NA, ## ??? else mean(delta) ???
                          data = psidata,
                          calib = calib,
                          arguments = argg,
                          details = res_fit,
                          errors = err_msg)
  }
  results <- list(data=psidata,fitting=res_fit,calib=data) # ??? ,calib=data ??? TBD
  return(out)
}

rpcr_calibQCBatch <- function(df,
                             cols = paste0("bF",c("incl","excl")),
                             tres = 0,     # treshold value to define dynamic range
                             rtype = "full", # method to define range
                             roff = c(0,0), # offset from range defined by rtype
                             method = c("incl","excl"),
                             model = "linear",
                             ...) {
  argg <- c(as.list(environment()),list(...))
  genelist <- unique(df$target)
  mean(unlist(lapply(genelist, function(gene)
    rpcr_calibQC(df[df$target==gene,],argg)$qc)))
}
