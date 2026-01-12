#' Title
#'
#' @param df input data
#'
#' @importFrom signal sgolayfilt
#' @return filtered data
#' @export
#'
rpcr_filter <- function(df) {
  df <- signal::sgolayfilt(df)
  return(as.numeric(df))
}
