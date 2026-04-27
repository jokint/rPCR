#' Detect calibrations samples
#'
#' @param data amplification data
#' @param percentage percentage (default = FALSE)
#' @param qual qualifier for the calibration samples
#'
#' @return amplification data with tprop column for detected calibration samples
#' @export

rpcr_calibDetect <- function(data, qual = "Cal", percentage = FALSE, ...){
  divisor <- if (percentage)  1 else 100
  if (!qual %in% names(data)){
    data$tprop <- NA
    temp <- unlist(lapply(data[grep(qual, data$sample),]$sample,function(x) {
    as.numeric(sub(qual,"",x))/divisor
    }))
    data[grep(qual, data$sample),"tprop" ] <- temp
  } else data$tprop <- as.numeric(data[,qual])/divisor
  if (length(stats::na.omit(data$tprop))==0) stop("No calibration samples detected.\nCheck qualifier definition to identify calibration samples.")
  return(data)
}
