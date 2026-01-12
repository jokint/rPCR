#' Imports a ThermoFisher PCR export file
#'
#' @param file file to be imported
#'
#' @return imported data
#' @export
#'
rpcr_import <- function(file) {
  if (missing(file)) file <- file.choose()
  data0 <- rpcr_readTF(file)
  data <- rpcr_wrap(data0)
  return(data)
}
