#' Savitzky-Golay smoothing of an amplification curve
#'
#' @param df input data
#' @param ... further arguments, ignored (accepted so that the function can
#'   be called through rpcr_batch(), which passes id_col to every worker)
#'
#' @importFrom signal sgolayfilt
#' @return filtered data
#' @export
#'
rpcr_filter <- function(df, ...) {
  df <- signal::sgolayfilt(df)
  return(as.numeric(df))
}
