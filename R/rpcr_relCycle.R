
#' rpcr_rcycle
#'
#' @param df data
#' @param offset offset
#'
#' @return relative cycle
#' @export
#'
rpcr_relCycle <- function(df, id_col) {
  return(df$cycle-which.max(rpcr_calDer(df[,id_col[1]],offset=1)))
}
