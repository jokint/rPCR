#' Title
#'
#' @param df data
#' @param calib calibration parameter
#'
#' @return calibrated ratio

#' @param calib Calibration parameters as named list like c(a = 1, ri = 0, re = 0)
#'
#' @param apsi apperent ratios to be calibrated
#' @param lower lower limits
#' @param upper upper limits
#' @param prop proportion
#' @param extend extended model
#' @param ... passing arguments
#'
#' @export
#'
#' @examples
#' rpcr_psi(df = data.frame(0.4, 0.2), calib = c(a = 3, ri = 0, re = 0.05))
rpcr_psi <- function(apsi,calib=c(1,0,0,1,0),lower = -0.1, upper = 1.1,prop = TRUE, extend = FALSE,...){

  tryCatch({
    cpsi <- lapply(apsi,function(x) do.call(rpcr_inverse,c(list(x),as.list(calib),as.list(c(lower = lower, upper = upper, prop = prop, extend = extend)))))
    return(unlist(cpsi))
  },
  error = function(cond) {
    message(cond)
    message(paste("PSI calculation failed:"))
    return(NA)
  })

}

rpcr_psi2 <- function(apsi,calib=c(1,0,0,1,1),lower = -0.1, upper = 1.1,prop = TRUE){
  tryCatch({
    if (prop) {
    cpsi <- lapply(apsi,function(x) do.call(rpcr_inverse2,c(list(x),as.list(calib),as.list(c(lower = lower, upper = upper)))))
    } else{
      a <- calib[1]
      ri <- calib[2]
      re <- calib[3]
      g <- calib[4]
      f <- calib[5]
      apsi[psi==1] <- 1/(1+1e-10)
      apsi <- apsi/(1-apsi)
      cpsi <- (apsi-a*ri)/(f(a-re*apsi))^(1/g)
      cpsi = cpsi/(1+cpsi)
    }


    return(unlist(cpsi))
  },
  error = function(cond) {
    message(cond)
    message(paste("PSI calculation failed:"))
    return(NA)
  })

}
