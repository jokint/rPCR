
#' Cycle numbers relative to the point of steepest increase
#'
#' @param df data
#' @param id_col columns to use; the first names the fluorescence column whose
#'   first derivative is maximised, and the cycle of that maximum becomes cycle zero
#'
#' @return relative cycle
#' @export
#'
rpcr_relCycle <- function(df, id_col) {
  return(df$cycle-which.max(rpcr_calDer(df[,id_col[1]],offset=1)))
}
