#' Efficiency calculation
#'
#' @param df numeric vector of amplification data
#' @param ... further arguments, ignored (accepted so that the function can
#'   be called through rpcr_batch(), which passes id_col to every worker)
#'
#' @return efficiency data
#' @export
rpcr_calEff <- function(df, ...) {
  len <- length(df)
  df <- data.frame(data = df, eff = 0)
  df[1:(len - 1 ), 2] <-
    (df[2:len, 1] - df[1:(len - 1), 1]) / df[1:(len - 1), 1]
  return(df$eff)
}
