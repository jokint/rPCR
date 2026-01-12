#' Function to simulate qasPCR
#'
#' @param psi a theoretical PSI value or a list of PSI values
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
rpcr_simpsi <- function(psi = c(0, 0.05, 0.15, 0.25, 0.35, 0.5, 0.65, 0.75, 0.85, 0.95, 1),
                       a = 1,
                       ri = 0,
                       re = 0,
                       g = 1,
                       f = 0.5,
                       prop = TRUE,
                       extend = FALSE,
                       novel = FALSE,
                       ...) {

  ##### OLD #####
  # psi_a <- (psi*a*g^(1-2*psi)-psi*ri+ri)/(psi*a*(1+re)*g^(1-2*psi)-psi*ri-psi+ri+1) # old
  if (prop) {
     psi_c <- g^(1-2*psi)
     if (novel)
       z <- a*f^(2*f-2*psi)
     else
       z <- a

    if (!extend)
      psi_a <- (psi_c*z*psi+z*ri*(1-psi))/(psi_c*(z*psi+re*psi)+(z*ri+1)*(1-psi))
    else
       psi_a <- (psi_c*a*psi*f+a*ri*(1-psi))/(psi_c*psi*f*(a+re)+(a*ri+1)*(1-psi))
  } else {
    psi[psi==1] <- 1/(1+1e-10)
    r <- psi/(1-psi)
    if (!extend) {
      # psi_a <- a*(abs(r)^g*sign(r)+ri)/(1+abs(r)^g*sign(r)*re)
      r <- r*g^(2*r/(r+1))
      psi_a <- a*(r+ri)/(1+r*re)
    } else {
      r <- abs(r)^(g+abs(log(abs(r)))*f)*sign(r)
      psi_a <- a*(r+ri)/(1+r*re)
    }
    psi_a <- psi_a/(psi_a+1)
  }

  return(psi_a)
}

