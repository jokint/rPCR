#' Title
#'
#' @param df data
#' @param ... passing arguments
#'
#' @returns list
#' @export
#'
rpcr_dpcr <- function(df,...) {

  df <- na.omit(df$ratioB)
  peaks <- rpcr_dPeak(df,output="details",...)
  dense <- peaks$dense
  peaks <- peaks$peak
  ratios <- c(peaks$dvalue[1]/(peaks$dvalue[1]+peaks$dvalue[5]),
              peaks$dvalue[2]/(peaks$dvalue[2]+peaks$dvalue[4]),
              sum(peaks$dvalue[1:2])/sum(peaks$dvalue[c(1:2,4:5)]))

  med <- median(peaks$peak)
  tratio <- sum(dense[dense$x<med,]$y/sum(dense$y))
  return(list(ratios,peaks,med,tratio))
}



#' Function to detect density peaks for the identification of cluster
#' @param df dPCR data
#' @param bw bandwith for density
#' @param filter filter
#' @param plot TRUE for plotting
#' @param scale rescaling data
#' @param output specifies output type
#'
#' @importFrom stats density
#' @importFrom utils tail
#' @return peak information
#' @export
#'
rpcr_dpeak <- function(df,bw=NULL,filter=NULL,plot=FALSE,scale=100,output=""){
  if (length(df)==0) {
    print("rpcr_dpeak: No data provided")
    return(NA)}

  if (!is.numeric(bw)) bw <- (max(df)-min(df))/scale
  if (bw<=0) bw <- 1

  dense <- data.frame(stats::density(df,bw=bw)[1:2])
  if (plot) plot(dense)
  if (!is.numeric(filter)) filter <- max(dense$y)/20
  peak <- data.frame(start=NA,peak=NA,end=NA,dvalue=NA)
  max <- dense[which(diff(sign(diff(dense$y)))==-2),]
  min <- dense[which(diff(sign(diff(dense$y)))==2),]
  max <- max[max$y>filter,]
  if (length(max)!=0) {
    peaks <- do.call(rbind,lapply(1:nrow(max),function(i){
    start <- utils::tail(min$x[min$x<max$x[i]],n=1)
    if (length(start)==0) start <- min(df)/2
    end <- min$x[min$x>max$x[i]][1]
    if (is.na(end)) end <- max(df)*2
    data.frame(start=start,peak=max$x[i],end=end,dvalue=dense[dense$x==max$x[i],]$y)
  }))
}
  return(if (output == "details") list(peaks=peaks,dense=dense) else peaks)
}




#' Function to identify certain population in rdPCR
#'
#' @param df dPCR data
#'
#' @return cluster info
#' @importFrom utils head
#' @export
#'
rpcr_dcluster <- function(df) {

  do.call(rbind,
          lapply(unique(df$Well),function(well) {
            sel <- df[df$Well==well,]
            sel$cluster <- 0
            cluster_var <- c("RFU.total","RFU.x","RFU.y","rprop")
            sel[,paste0("cl_",cluster_var)] <- 0
            tpeak <- rpcr_dpeak(sel$RFU.total)
            ppeak <- rpcr_dpeak(sel$rprop)
            ypeak <- rpcr_dpeak(sel$RFU.y)
            xpeak <- rpcr_dpeak(sel$RFU.x)

            if (nrow(tpeak)*nrow(ppeak)*nrow(ypeak)*nrow(xpeak)==1) {
              print(paste(well,"No multiple cluster detected"))
              return(sel)
            }


            peak <- utils::head(tpeak,1)[[3]]
            if (!is.na(peak)) sel[sel$RFU.total<peak,]$cluster <- "b"
            #
            # var <- "RFU.x"
            # peak <- rpcr_dpeak(sel[sel$cluster!="b",var])
            # if (nrow(peak)>0) for (i in 1:nrow(peak)) {
            #  print(peak)
            #   print("OK")
            #    sel[sel$cluster!="b"&sel[,var]>peak[i,1]&sel[,var]<peak[i,3],]$cluster <- paste(var,i,sep="_")
            # }
            #   var <- "RFU.y"
            # peak <- rpcr_dpeak(sel[sel$cluster!="b",var])
            # print(peak)
            # if (nrow(peak)>0) for (i in 1:nrow(peak)){
            #
            #   print("OK2")
            #   sel[sel$cluster!="b"&sel[,var]>peak[i,1]&sel[,var]<peak[i,3],]$cluster <- paste(var,i,sep="_")
            # }
            # var <- "rprop"
            for (var in cluster_var){
            peak <- rpcr_dpeak(sel[sel$cluster!="b",var])
            if (nrow(peak)>0) for (i in 1:nrow(peak)) {
              sel[sel[,var]>peak[i,1]&sel[,var]<peak[i,3],paste0("cl_",var)] <- i
            }}


            sel
            }))
}
