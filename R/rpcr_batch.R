#' A helper function to perform helper function in a batch mode
#'
#' @param fun the helper function to be executed
#' @param df the data frame to be analysed
#' @param id_col the data column to be used
#' @param ... addition arguments passed to fun
#'
#' @return returns the aggregated data calculated by fun
#' @export
rpcr_batch <- function(fun, df, id_col,...) {
  wells <- unique(df$well)
  out <- vector()
  tryCatch({
    for (i in wells) {
      targets <- unique(df[df$well == i, ]$target)
      for (j in targets) {
        res <- match.fun(fun)(df[df$well == i & df$target == j, id_col],  id_col = id_col,...)
        if (is.data.frame(res)) out <- rbind(out, res) else out <- c(out, res)
      }
    }
  }, error = function(cond) {
    message(paste(fun, ": Fehler in well", i))
    message(cond)
    return(NA)
  }
  )
  return(out)
}
