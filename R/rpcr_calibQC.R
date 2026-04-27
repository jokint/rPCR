#' Testing quality of calibration experiment
#'
#' @param df PCR data
#' @param ... paramters for the rpcr_batchFit, rpcr_fit and rpcr_calib routines
#' @param tprop theoretical proportions used to calibrate the data
#'
#' @return QC parameters
#' @importFrom stats coef
#' @importFrom stats na.omit
#' @export
#'
rpcr_calibQC <- function(df, tprop, ... ) {

  argg <- c(as.list(environment()),list(...))
  out <- list()

  ### calculating apparent proportion aprop
  res_fit <- rpcr_calibrate(df,details=TRUE,...)
  cdata <- res_fit$details$summary

  out <- list()
  for (target in unique(cdata$target)) {
    err_msg <- ""
    ## Fitting error test
    temp <- cdata[cdata$target == target,]
    if (!length(unique(stats::na.omit(temp$tprop))) == length(unique(temp$aprop))) err_msg <- paste(err_msg, "Fitting failed")
    calib <- if (!all(is.na(temp$aprop))) rpcr_calib(temp) else NA
    cdata[cdata$target == target,]$cprop <- if (!all(is.na(calib))) rpcr_prop(temp$aprop,stats::coef(calib)) else NA
    cdata[cdata$target == target,]$delta <- temp$cprop - temp$tprop

    ## Calibration error test
    if (!all(unique(stats::na.omit(cdata)$tprop)==unique(tprop))) err_msg <- paste(err_msg, "Calibration failed")
    out[[target]] <- list(qc = if (!all(is.na(cdata$cprop)))  mean(abs((cdata$delta))) else NA, ## ??? else mean(delta) ???
                          data = cdata,
                          calib = calib,
                          arguments = argg,
                          details = res_fit,
                          errors = err_msg)
  }
  return(out)
}
