#' Calibrate apparent proportions
#'
#' @param aprop apparent proportions to be calibrated
#' @param calib calibration parameters as a named vector, e.g.
#'   c(a = 1, ri = 0, re = 0, g = 1)
#' @param lower lower limit passed to rpcr_inverse()
#' @param upper upper limit passed to rpcr_inverse()
#' @param prop proportion
#' @param extend extended model
#' @param ... passing arguments
#'
#' @return calibrated proportions
#' @export
#'
#' @examples
#' rpcr_prop(c(0.4, 0.2), calib = c(a = 3, ri = 0, re = 0.05, g = 1))
rpcr_prop <- function(aprop,calib=c(1,0,0,1,0),lower = -0.1, upper = 1.1,prop = TRUE, extend = FALSE,...){

  tryCatch({
    cprop <- lapply(aprop,function(x) do.call(rpcr_inverse,c(list(x),as.list(calib),as.list(c(lower = lower, upper = upper, prop = prop, extend = extend)))))
    return(unlist(cprop))
  },
  error = function(cond) {
    message(conditionMessage(cond))
    message(paste("Ratio calculation failed:"))
    return(NA)
  })

}
