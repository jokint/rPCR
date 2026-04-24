#' Import and Process ThermoFisher PCR Export Files
#'
#' @description
#' High-level function to import ThermoFisher PCR data and automatically
#' convert it into the `pcr_raw` S3 class.
#'
#' @param file Optional file path. If missing, a dialog opens.
#'
#' @return Returns an object of S3 class `pcr_raw`.
#'
#' @details
#' The function operates in two steps:
#' 1. It reads the raw ThermoFisher file format using `rpcr_readTF()`.
#' 2. It wraps and converts the data into the package-specific `rpcr_raw` S3 class
#'    using `rpcr_wrap()`.
#'
#' @examples
#' \dontrun{
#' # Interactive file selection:
#' my_data <- rpcr_import()
#'
#' # Direct file path:
#' my_data <- rpcr_import("path/to/my_pcr_export.txt")
#' }
#'
#' @export
rpcr_import <- function(file) {

  # Import data (opens dialog if needed)
  data <- rpcr_readTF(file)

  # Stop execution if user cancelled the dialog
  if (is.null(data)) return(invisible(NULL))

  # Convert to S3 class
  data <- rpcr_wrap(data)

  return(data)
}
