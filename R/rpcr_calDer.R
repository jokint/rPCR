#' derivative calculation
#'
#' @param df data for derivative calculation
#' @param offset adding zero values
#'
#' @return derivative data
#' @export
rpcr_calDer <- function(df, offset = 1, ...) {
  len <- length(df)
  df <- data.frame(data = df, der = 0)
  df[(1 + offset):(len - 1 + offset), 2] <- df[2:len, 1] - df[1:len - 1, 1]
  return(df$der)
}
