#' Amplification curve detection
#'
#' @description
#' `rpcr_calCip` analyzes the amplification curve and returns starting, inflection and ending cycle of the amplification
#'
#' @details
#' Ther is no description for this function yet
#'
#' @param x a vector of PCR amplification singlas
#' @param qc_tres treshold
#' @param detail output details
#' @param len length parameter
#' @param mincycle minimum cycle
#' @param stringent  stringency
#' @param lead  lead cycles
#' @param ... passing paramaters
#'
#' @return returns different amplification curve indicators
#' @importFrom stats na.omit
#' @importFrom utils tail
#' @export
#'
rpcr_calCip <- function(x, qc_tres = 1.15, detail = FALSE,len=10,mincycle=13,stringent =TRUE,lead=3,...){
  ## get first derivative data and look for stretches of positive or negative values
  ## The increase in qPCR signal will lead to long stretches of positive values
  x <- x-min(x)
  temp <- rle(sign(rpcr_calDer(x)))
  length2 <- temp$lengths
  length2[temp$values==-1] <- 0
  max <- (1:length(length2))[length2>len]
  if (length(max)==0) max <- which.max(length2)
  a <- unlist(lapply(max, function(max) if (max==1) 1 else sum(temp$lengths[1:(max-1)])+1))
  b <- a+length2[max]-1
  temp <- do.call(rbind,lapply(1:length(a),function(z) {
    ## get second derivative data
    temp <- rle(sign(rpcr_calDer(rpcr_calDer(x))[a[z]:b[z]]))
    length2 <- temp$lengths
    t1 <- if (a[z]<b[z]) na.omit(data.frame(do.call(rbind,lapply(seq(which(temp$values==1)[1],length(temp$values),2),function(x){
      c(x,temp$length[x],temp$length[x+1],temp$length[x]+temp$length[x+1])
    })))) else data.frame(0,0,0,0)
    ## QC the first D2 increasing part must be more than lead=3 cycles
    t1 <- t1[t1[,2]>lead,]
    #  length2[temp$values==-1] <- 0
    #  max <- which.max(length2)
    if (!length(t1[,4])==0) {
    max <- utils::tail(t1[t1[,4]==max(t1[,4],na.rm=TRUE),1],1)
    c <- a[z]+ if (max==1) 0 else sum(temp$lengths[1:(max-1)])
    d <- c+temp$length[max]-1
    e <- d+1
    f <- d+temp$length[max+1]
    g <- x[f]/x[c]
    dif <- diff(diff(x))
    part <- dif[e+2]/sum(dif[(d-3):(d+3)])
    ci <- d + part
    Fci <- x[d] + diff(x)[d-1]*part
    qc <- if (d>mincycle & g>qc_tres & all(x[1:(d-1)]<x[d])) TRUE else FALSE
    comment <- paste(d>mincycle,g>qc_tres,all(x[1:(d-1)]<x[d]))
    data.frame(c=c,d=d,e=e,f=f,g=g,ci = ci,Fci=Fci, qc=qc,comment=comment)
    } else data.frame(c=0,d=0,e=0,f=0,g=0,ci=0,Fci=0,qc=FALSE,comment=FALSE)
  }))

  res <- cbind(max=max,a=a,b=b,temp)
  if (detail) return(res)
  temp <- res[res$qc==TRUE,]
  res <- if (nrow(temp)==0) if (stringent) NA else res[which.max(res$d),]$d else temp[which.max(temp$d),]$d
  return(res)
}
