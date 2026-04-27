#' Calibrates rPCR data from calibration samples
#'
#' @param df data from calibration samples
#' @param prop if TRUE data is in proportion, if FALSE in percentage
#' @param extend additional model
#' @param novel if novel = TRUE uses alternative model
#' @param silent if FALSE displays calibration error
#'
#' @return calibration parameters
#' @export
#' @importFrom minpack.lm nlsLM
rpcr_calib <- function(df,prop=TRUE,extend=FALSE,novel=FALSE,silent=FALSE) {
   tryCatch({
    if (!extend){
      if (!novel)
      fit <- minpack.lm::nlsLM(aprop ~ rpcr_simprop(tprop,a,ri,re,g, prop = prop, extend = extend, novel = novel),
                   data = df,
                   start =c(a = 1, ri = 0.1, re = 0.1, g = 1),
                   lower=c(0,0,0,0),
                   upper=c(Inf,1,1,Inf)) # ",...)" removed
      else
{
        fit <- minpack.lm::nlsLM(aprop ~ rpcr_simprop(tprop,a,ri,re,g, f, prop = prop, extend = extend, novel = novel), # removed ri,re
        data = df,
        start =c(a = 1, ri = 0.1, re = 0.1, g = 1,f=0.5),
        lower=c(0,0,0,0,0),
        upper=c(Inf,1,1,Inf,1)) # ,...) removed
}

    }
    else
      fit <- minpack.lm::nlsLM(aprop ~ rpcr_simprop(tprop,a,ri,re,g,f,prop = prop, extend = extend, novel = novel), data = df, start =c(a = 1, ri = 0.1, re = 0.1, g = 1, f= 1e-6),lower=c(0,0,0,0,0),upper=c(Inf,1,1,Inf,1))

    return(fit)
  },
  error = function(cond) {
    if (!silent) message(paste("Calibration failed ->",cond))
    return(NA)
  })
}
