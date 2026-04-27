#' Title
#'
#' @param df data
#' @param calib calibration parameter
#'
#' @return calibrated ratio

#' @param calib Calibration parameters as named list like c(a = 1, ri = 0, re = 0)
#'
#' @param aprop apperent ratios to be calibrated
#' @param lower lower limits
#' @param upper upper limits
#' @param prop proportion
#' @param extend extended model
#' @param ... passing arguments
#'
#' @export
#'
#' @examples
#' rpcr_prop(df = data.frame(0.4, 0.2), calib = c(a = 3, ri = 0, re = 0.05))
rpcr_prop <- function(aprop,calib=c(1,0,0,1,0),lower = -0.1, upper = 1.1,prop = TRUE, extend = FALSE,...){

  tryCatch({
    cprop <- lapply(aprop,function(x) do.call(rpcr_inverse,c(list(x),as.list(calib),as.list(c(lower = lower, upper = upper, prop = prop, extend = extend)))))
    return(unlist(cprop))
  },
  error = function(cond) {
    message(cond)
    message(paste("Ratio calculation failed:"))
    return(NA)
  })

}
