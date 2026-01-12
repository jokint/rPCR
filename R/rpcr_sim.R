#' Function to simulate a range of values for a specific parameters
#'
#' @param psiCal calibration values
#' @param a fitting parameter
#' @param ri fitting parameter
#' @param re fitting parameter
#' @param steps number of steps to be simulated
#'
#' @return a set of biased PSIs for a range of parameter values
#' @export
#'
#' @importFrom purrr map
#' @importFrom dplyr bind_rows
rpcr_sim <- function(psiCal = c(0, 0.05, 0.15, 0.25, 0.35, 0.5, 0.65, 0.75, 0.85, 0.95, 1), a = 1, ri = 0, re = 0, steps = 10, g = 1, range = "arireg") {

  a_range <- if(grepl("a",range)) seq(1, a, by = (a - 1) / (steps - 1)) else a
  ri_range <- if(grepl("ri",range)) seq(0, ri, by = ri / (steps - 1)) else ri
  re_range <- if(grepl("re",range)) seq(0, re, by = re / (steps - 1)) else re
  g_range <- if(grepl("g",range)) seq(1, g, by = (g-1) / (steps - 1)) else g
  res <- lapply(re_range, function(xe) {
    lapply(g_range, function(xg) {
    lapply(ri_range, function(xi) {
      lapply(a_range, function(xa) {
        data.frame(tPSI = psiCal, a = xa, ri = xi, re = xe, g = xg, sPSI = rpcr_simpsi(psi = psiCal, a = xa, ri = xi, re = xe, g=xg))
      }) %>% purrr::map(dplyr::bind_rows)
    }) %>% purrr::map(dplyr::bind_rows)
  }) %>% purrr::map(dplyr::bind_rows)
}) %>% purrr::map(dplyr::bind_rows)
  return(res[[1]])
}



