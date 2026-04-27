#' Efficiency calculation
#'
#' @param df vector eith amplification data
#'
#' @return efficiency data
#' @export
rpcr_calEff <- function(df) {
  len <- length(df)
  df <- data.frame(data = df, eff = 0)
  df[1:(len - 1 ), 2] <-
    (df[2:len, 1] - df[1:(len - 1), 1]) / df[1:(len - 1), 1]
  return(df$eff)
}
