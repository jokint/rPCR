#' Function to simulate qasPCR
#'
#' @param tprop a theoretical proportion value or a list of proportion values
#' @param a The alpha (a) value describes the difference in
#' probe intensities (incl/excl)
#' @param ri The ratio ri describes the crossreactivity of the intensity probe
#'
#' The ratio can be between 0 and 1.
#' ri = 0 -> The inclusion probe is specific there is no cross reactivity with the exclusion isoform
#' ri = 1 -> The inclsuion probe is unspecific. The probe recognizes both isoforms equally.
#' 0 > ri > 1 -> There is a certain specificity towards the inclusion isoform, but also recognizes the exclusion isoform.
#'
#' @param re The ratio re describes the crossreactivity of the exclusion probe
#'
#' The ratio can be between 0 and 1.
#' re = 0 -> The exclusion probe is specific there is no cross reactivity with the inclusion isoform
#' re = 1 -> The exclusion probe is unspecific. The probe recognizes both isoforms equally.
#' 0 > ri > 1 -> There is a certain specificity towards the exclusion isoform, but also recognizes the inclusion isoform.
#'
#' @param g parameter
#'
#' @return The simulated biased PSI
#' @export
#'
rpcr_simprop <- function(tprop = c(0, 0.05, 0.15, 0.25, 0.35, 0.5, 0.65, 0.75, 0.85, 0.95, 1),
                       a = 1,
                       ri = 0,
                       re = 0,
                       g = 1,
                       f = 0.5,
                       prop = TRUE,
                       extend = FALSE,
                       novel = FALSE,
                       ...) {

  if (prop) {
     gamma_fac <- g^(1-2*tprop)

     if (novel)
       z <- a*f^(2*f-2*tprop)
     else
       z <- a

    if (!extend)
       aprop <- (gamma_fac*z*tprop+z*ri*(1-tprop))/(gamma_fac*(z*tprop+re*tprop)+(z*ri+1)*(1-tprop))
    else
       aprop <- (gamma_fac*a*tprop*f+a*ri*(1-tprop))/(gamma_fac*tprop*f*(a+re)+(a*ri+1)*(1-tprop))
  } else {
    tprop[tprop==1] <- 1/(1+1e-10)
    tratio <- tprop/(1-tprop)
    if (!extend) {
      tratio <- tratio*g^(2*tratio/(tratio+1))
      aratio <- a*(tratio+ri)/(1+tratio*re)
    } else {
      tratio <- ifelse(tratio==0,0,abs(tratio)^(g+abs(log(abs(tratio)))*f)*sign(tratio))
      aratio <- a*(tratio+ri)/(1+tratio*re)
    }
    aprop <- aratio/(aratio+1)
  }

  return(aprop)
}

