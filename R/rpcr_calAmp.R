#' detection of cycle range with significant amplification
#'
#' @param df data
#' @param start start cycle
#' @param end end cycle
#' @param zero zero value
#' @param cycle either TRUE or FALSE
#' @param tres threshold number form 0 to 1
#' @param roff cycle offset c(offset from start,offset from end)
#' @return returns the range
#' @export
#' @importFrom utils tail
#'
#' @examples # currently no example
rpcr_calAmp <- function(df,start="c",end="f",zero="c",cycle=TRUE,tres=0.1,roff=c(0,0)) {

tcycle <- NULL

if (!is.null(ncol(df))&"cycle" %in% colnames(df)) {
  df <- df[order(df$cycle),]
  tcycle <- df$cycle
  df <- subset(df, select=-c(cycle))
  if (ncol(df)==1) df <-df[,1]
}

temp0 <- if (is.null(ncol(df))) df else rowSums(df)
temp <- rpcr_calCip(temp0, detail = TRUE)
start <- utils::tail(temp[temp$qc==TRUE,start],1)
if (length(start)==0) return(NA)
end <- utils::tail(temp[temp$qc==TRUE,end],1)
base <- utils::tail(temp[temp$qc==TRUE,zero],1)
d1 <- rpcr_calDer(temp0)

sel <- c(1:length(d1))[d1>d1[utils::tail(temp[temp$qc==TRUE,"d"],1)]*tres]
start <- max(start,min(sel)) + roff[1]
end <- min(end,max(sel)) + roff[2]
out <-  if (is.null(ncol(df))) df[start:end] - df[base]  else sweep(df[start:end,],2,as.matrix(df)[base,])

if (cycle) {
  tcycle <- if (is.null(tcycle)) start:end else tcycle[start:end]
  out <- data.frame(cycle=tcycle,data.frame(out))
}

return(out)
}
