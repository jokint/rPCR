#' pots a series of charts to summarize a calibration experiment using the functions rpcr_plotData and rpcr_plotBar
#'
#' @param data data for plotting
#' @param type plot type
#' @param signal signal type
#' @param ... passing arguments
#'
#' @return returns a list of plots
#' @export
#'
rpcr_plotCalibSummary <- function(data, type = "all", signal = "all", ...) {

  fig <- 0
  figures <- list()

  if (type %in% c("all", "general")) {
    if (signal %in% c("all", "Rn")) {
      fig <- fig + 1
      figures[[fig]] <- rpcr_plotData(data,
                                     title = "normalized flourescence\n ",
                                     signal = "Rn",
                                     ...)
    }
    if (signal %in% c("all", "deltaRn")) {
      fig <- fig + 1
      figures[[fig]] <- rpcr_plotData(data,
                                     title = "normalized flourescence\n ",
                                     signal = "deltaRn",
                                     ...)
    }
  }
  if (type %in% c("all", "cycle")) {
    if (signal %in% c("all", "Rn")) {
      fig <- fig + 1
      figures[[fig]] <- rpcr_plotBar(data,
                                    title = "normalized flourescence\n ",
                                    signal = "Rn",
                                    ...)
    }
    if (signal %in% c("all", "deltaRn")) {
      fig <- fig + 1
      figures[[fig]] <- rpcr_plotBar(data,
                                    title = "normalized flourescence\n ",
                                    signal = "deltaRn",
                                    ...)
    }
  }
  return(figures)
}
