#' Baseline detection
#'
#' @param df amplification data
#' @param offset offset for derivative calculation
#' @param ... other parameters
#' @param tres treshold
#' @importFrom utils tail
#'
#' @return the corrected values
#' @export
rpcr_calBase <- function(df, offset = 1, tres=0,...) {

  names(df) <- c("incl","excl")
  df$total <- df$incl+df$excl
  Ft_d1 <- rpcr_calDer(df$total,offset=offset,...)
  Ft_d1_max <- max(Ft_d1)
  if (length(tres)==1) tres <- c(tres,tres)
  bool1 <- rle(with(rle(Ft_d1 > Ft_d1_max*tres[1]), rep(lengths == max(lengths[values]) & values, lengths)))
  bool1$lengths <- utils::tail(c(0,bool1$lengths),3) #corrects in case the curve (d1) is always above treshold
  bool2 <- rle(with(rle(Ft_d1 > Ft_d1_max*tres[2]), rep(lengths == max(lengths[values]) & values, lengths)))
  range <- seq(bool1$length[1]+1, sum(bool2$length[1:2]))

  incl <- rpcr_calDer(df$incl,offset=offset,...)[range]
  excl <- rpcr_calDer(df$excl,offset=offset,...)[range]

  df$incl <- 0
  df$excl <- 0

  df[range,]$incl <- unlist(lapply(seq_along(incl), function(x) sum(incl[1:x])))
  df[range,]$excl <- unlist(lapply(seq_along(excl), function(x) sum(excl[1:x])))

  df[sum(bool2$length[1:2]):length(Ft_d1),] <-df[sum(bool2$length[1:2]),]

  return(df[,c("incl","excl")])
}
