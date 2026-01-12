#' Detect calibrations samples
#'
#' @param data amplification data
#' @param percentage percentage (default = FALSE)
#' @param qual qualifier for the calibration samples
#'
#' @return amplification data with tPCI column for detected calibration samples
#' @export
#' @importFrom stats na.omit
#'
rpcr_calibDetect <- function(data, qual = "Cal", percentage = FALSE, ...){
  percent <- if (percentage)  1 else 100
  if (!qual %in% names(data)){
    data$tPSI <- NA
    temp <- unlist(lapply(data[grep(qual, data$sample),]$sample,function(x) {
    as.numeric(sub(qual,"",x))/percent
    }))
    data[grep(qual, data$sample),"tPSI" ] <- temp
  } else data$tPSI <- as.numeric(data[,qual])/percent
  if (length(stats::na.omit(data$tPSI))==0) stop("No calibration samples detected.\nCheck qualifier definition to identify calibration samples.")
  return(data)
}
