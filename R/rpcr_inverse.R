#' Corrects proportion using the submitted parameters
#'
#' @param y model parameter
#' @param a model parameter
#' @param ri model parameter
#' @param re model parameter
#' @param g model parameter
#' @param lower lower end point for uniroot
#' @param upper upper end point for uniroot
#' @param f  model parameter
#' @param ... passing arguments
#'
#' @return corrected ratio
#' @export
#'
rpcr_inverse <- function(y,a,ri,re,g,f=1,lower=-0.1,upper=1.1,...) {
  tryCatch({

    ## test lower limit
    seq_lo <- seq(0, -1, -0.01)
    seq_up <- seq(1,  2,  0.01)
    test_lower <- rpcr_simprop(seq_lo,a=a,ri=ri,re=re,g=g,f=f,...)-y
    test_upper <- rpcr_simprop(seq_up,a=a,ri=ri,re=re,g=g,f=f,...)-y
    lower <- seq_lo[which(test_lower<0)[1]]
    upper <- seq_up[which(test_upper>0)[1]]

    if (is.na(lower)) return(NA)
    if (is.na(upper)) return(NA)

    stats::uniroot((function (x) rpcr_simprop(x,a,ri,re,g,f,...) - y), lower = lower, upper = upper)[1]

    }, error = function(cond) {
    message(cond)
    return(NA)
  })
}

