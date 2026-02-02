library(data.table)
library(minpack.lm)
library(ggplot2)
library(dplyr)
library(misty)


# path_model <- "/AppData/Local/Temp/OpenModelica/OMEdit/"
# path_sim <- "/Documents/R/R projects/rPCR Simulations/simulations/"


omPCR <- function(model,omPath,override=NA,omOptions="",rname=NULL,logdir=NULL,details=FALSE,dif=TRUE,...){

  oldwd <- getwd()
  setwd(omPath)

  if (!missing(override)) {
    out <- unlist(lapply(seq_along(override),function(x) {paste0(names(override)[x],"=",override[x])}))
    fileConn<-file(paste0(omPath,"Para.csv"))
    writeLines(out, fileConn)
    close(fileConn)
    omOptions <- paste0(omOptions," -overrideFile=Para.csv")
  }

  if (is.null(rname)) rname <- paste0(model,"_res.csv")
  ## Windows System
  # system2(paste0(model,".bat"), args = omOptions, stdout = "LOG.txt",stderr="ERR.txt",wait=TRUE)

  ## Linux System via apptainer
  #system(paste0("apptainer exec /scicore/soft/containers/apptainer/openmodelica/openmodelica-1.25.1.sif ./" ,model," ",omOptions))
  # ,   args = omOptions, stdout = "LOG.txt",stderr="ERR.txt",wait=TRUE)


  system2("apptainer",
          args = paste0("exec /scicore/soft/containers/apptainer/openmodelica/openmodelica-1.25.1.sif ./",model," ",omOptions),
  stdout = "LOG.txt",
  stderr="ERR.txt",
  wait=TRUE)




  par <- override
  names(par) <- paste0("par_",names(override))
  res <-cbind(par,read.csv(rname), row.names = NULL)
  setwd(oldwd)

  if (!details) {
    res <- res[(res$time -(res$cycle -1) * override$cycle_time )==override$cycle_time,]
    if (dif) res <- omdiff(res)
    # res$deltaN <- 0
    # res$deltaN[1:(moPara$cycle_max-1)] <- res$totalN[2:(override$cycle_max)] - res$totalN[1:(override$cycle_max-1)]
  }

  return(res)
}


omPCRNested <- function(omModel,omPath,override=NA,omOptions="",nestedList=list(ratio=seq(0,1,0.1),fraction=seq(0.05,0.95,0.05)),logdir=NULL,details=details,...) { # time = 45
  if (is.vector(override)) override <- data.frame(t(override)) else override <- data.frame(override)

  # tPCR <- nrow(override)*prod(unlist(lapply(nestedList, function(x) if (is.matrix(x)) ncol(x) else length(x))))
  # print(nestedList$time)

  simData <-
    if (is.matrix(nestedList[[1]])) {
      apply(nestedList[[1]],2,  function(x)   {
        override[names(x)] <- x
        if (length(nestedList)==1){
          counter <<- counter + 1
          res <- omPCR(omModel,omPath,override = override,omOptions=omOptions,logdir=logdir,details=details,...) # ,time=override$time
          res <- cbind(pcr=counter,res)
        }
        else{
          res <-   omPCRNested(omModel,omPath,override=override,omOptions="", nestedList=nestedList[-1],logdir=logdir,details=details,...)
        }
        return(res)

      })}

  else {

    lapply(nestedList[[1]],function(x){
      override[names(nestedList)[1]] <- x
      if (length(nestedList)==1){
        counter <<- counter + 1
        # cat(paste0("PCR ",counter,"/",tPCR," -> "))
        res <- omPCR(omModel,omPath,override = override,omOptions=omOptions,logdir=logdir,details=details) # ,time=override$time
        res <- cbind(pcr=counter,res)
      }
      else{
        res <-   omPCRNested(omModel,omPath,override=override,omOptions="", nestedList=nestedList[-1],logdir=logdir,details=details)
      }
      return(res)
    })}
  simData = do.call(what = rbind, args = simData)
  return(simData)
}

omPCRBatch <-function(omModel,omPath,override=NA,omOptions="",nestedList=NULL,logdir=NULL,project=NULL,details=FALSE,plot=FALSE,...) { #,time=45
  print(Sys.time())
  counter <<- 0
  if (!is.null(project)) createSim(project,simModel = omModel,settings = override,...)

  if (is.vector(override)) override <- data.frame(t(override)) else override <- data.frame(override)
  print(paste("Unnested conditions:", nrow(override)))
  print(paste("Nested Levels:", length(nestedList)))
  tPCR <- nrow(override)*prod(unlist(lapply(nestedList, function(x) if (is.matrix(x)) ncol(x) else length(x))))
  print(paste("Total PCR simulation:",  tPCR))
  plist <- unlist(lapply(seq_along(nlist),function(x) {
    if (is.matrix(nlist[[x]])){
      if (ncol(nlist[[x]])>1) rownames(nlist[[x]])
    } else {
      if (length(nlist[[x]])>1) names(nlist[x])
    }}))
  plist <- unique(c(unlist(lapply(colnames(override), function(x){ x[length(unique(override[,x]))>1]})),plist))
  print(paste("Variations in following parameters:",paste(plist,collapse=", ")))
  oldwd <- getwd()
  setwd(omPath)
  atime <- Sys.time()
  omPCR(omModel,omPath,override[1,],omOptions,logdir=logdir,details=details,...)
  eTime <- Sys.time()
  setwd(oldwd)
  etime <- as.numeric(eTime-atime,units="mins")*tPCR*1
  tunits <- if (etime>60) "hours" else if (etime>1) "mins" else "secs"
  print(paste("Estimated run time:",as.numeric(eTime-atime,units = tunits )*tPCR*1,tunits))
  simData <- lapply(1:nrow(override),function(row){
    res <- if (is.null(nestedList)) {
      counter <<- counter + 1
      cbind(pcr=counter, omPCR(omModel,omPath,override = override[row,],omOptions=omOptions,logdir=logdir,details=details,...)) # time=time,
    } else omPCRNested(omModel,omPath,override = override[row,],omOptions=omOptions,nestedList=nestedList,logdir=logdir,details=details,...)
    cbind(class=row,res)
  })
  ctime <- Sys.time()
  totalTime <- as.numeric(ctime-atime,units="mins")
  tunits <- if (totalTime>1) "mins" else if (totalTime>60) "hours" else "secs"
  print(paste("Total time:",as.numeric(ctime-atime,units = tunits ),tunits))
  print(paste("Time per PCR:",as.numeric(ctime-atime,units="secs")/counter,"secs"))
  simData = do.call(what = rbind, args = simData)

  # simData <- simData %>%
  #   group_by_at(paste0("par_",names(nestedList))) %>%
  #   mutate(index = cur_group_id()) %>%
  #   ungroup() %>%
  #   data.frame()

  ## Postprocessing

  print("Postprocessing...")
  # simData$totalA <- (simData$totalAs + simData$totalAa)/2
  # simData$totalB <- (simData$totalBs + simData$totalBa)/2
  # simData$totalT <- simData$totalA+simData$totalB
  #
  # simData$totalNAs <- simData$totalAs/(simData$par_senseA+simData$par_antiPrimer)
  # simData$totalNAa <- simData$totalAa/(simData$par_antiA+simData$par_sensePrimer)
  # simData$totalNBs <- simData$totalBs/(simData$par_senseB+simData$par_antiPrimer)
  # simData$totalNBa <- simData$totalBa/(simData$par_antiB+simData$par_sensePrimer)
  # simData$totalNA <- (simData$totalNAs+simData$totalNAa)/2
  # simData$totalNB <- (simData$totalNBs+simData$totalNBa)/2
  # simData$totalN <- (simData$totalNA+simData$totalNB)

  if (!is.null(project)) {
    print("Saving data....")
    saveRDS(simData, file = paste0(expPath,expName,"/results/results.rds"))
    results <- simData[simData$stopTime==simData$time,]
    saveRDS(results, file = paste0(expPath,expName,"/results/results_small.rds"))


    ### Preparing figures
    if (plot) {
      print("Preparing plots....")
      plist <- paste0("par_",plist)

      p <- ggplot(data=results,aes(group=pcr,col=interaction(results[,plist],sep="/"))) + guides(col=guide_legend(title=paste(plist,collapse="/")))
      p1 <- p + geom_line(aes(x=cycle,y=totalT))
      p2 <- p + geom_line(aes(x=totalA,y=totalB))
      p3 <- p + geom_line(aes(x=cycle,y=PSI))
      p4 <- p + geom_line(aes(x=totalT,y=PSI))

      dif <- do.call(rbind,lapply(unique(results$pcr), function(pcr) {
        data <- results[results$pcr==pcr,]
        temp <- data$totalN
        cbind(data[-nrow(data),],data.frame(diff=temp[-1]-temp[-length(temp)],eff=(temp[-1]-temp[-length(temp)])/temp[-length(temp)]))
      }))
      p5 <- ggplot(data=dif) + geom_point(aes(x=totalN,y=diff,group=pcr,col=interaction(dif[,plist],sep="/"))) + guides(col=guide_legend(title=paste(plist,collapse="/")))
      p6 <- ggplot(data=dif) + geom_point(aes(x=totalN,y=eff,group=pcr,col=interaction(dif[,plist],sep="/"))) + guides(col=guide_legend(title=paste(plist,collapse="/")))



      print("Plotting....")
      sapply(list(p1,p2,p3,p4,p5,p6), plot)


      print("Saving Plots....")
      ggsave("curve.png", plot = p1,path = paste0(expPath,expName),dpi = 75)
      ggsave("slope.png", plot = p2,path = paste0(expPath,expName),dpi = 75)
      ggsave("PSI.png", plot = p3,path = paste0(expPath,expName),dpi = 75)
      ggsave("PSI2.png", plot = p4,path = paste0(expPath,expName),dpi = 75)
      ggsave("dif.png", plot = p5,path = paste0(expPath,expName),dpi = 75)
      ggsave("eff.png", plot = p6,path = paste0(expPath,expName),dpi = 75)
    }
  }
  print(Sys.time())
  # print(dim(simData))
  return(simData)
  # return(if (details) simData else  simData[simData$stopTime==simData$time,])
}



counter <- function() {
  i <- 0
  function() {
    i <<- i + 1
    i
  }
}


createSim <- function(title=NULL,
                      simModel = "qsPCR_2025_02",settings,expName=NULL) {

  print(paste("Creating project:",title))
  simModel <<- simModel
  simPath <<- paste0(mPath,path_model,simModel) # ,"/") -> )
  if (is.null(expName)) expName <- paste0("Sim", format(Sys.time(), "%Y%m%d_%H%M%S")," (",title,")")
  expPath <<- paste0(mPath,path_sim)

  dir.create(expPath, showWarnings = FALSE)
  dir.create(paste0(expPath,expName), showWarnings = FALSE)
  dir.create(paste0(expPath,expName,"/log"), showWarnings = FALSE)
  dir.create(paste0(expPath,expName,"/results"), showWarnings = FALSE)
  dir.create(paste0(expPath,expName,"/model"), showWarnings = FALSE)

  file.copy(file.path(simPath,list.files(simPath)),paste0(expPath,expName,"/model"))
  fileout <<- paste0(expPath,expName,"/log/stdoutmain.log")
  fileerr <<- paste0(expPath,expName,"/log/stderrtmain.log")
  simPath <<- paste0(expPath,expName,"/model/")
  script.copy(file = NULL, folder = paste0(expPath,expName), create.folder = FALSE,
              time = TRUE, format = "%Y-%m-%d_%H%M", overwrite = TRUE,
              check = TRUE)

  file.create(fileout)
  file.create(fileerr)
  write.table(settings,paste0(expPath,expName,"/settings.txt"),sep="\t",row.names=FALSE)
}


copytoconc <- function(copies,volume = 20e-6 , avogadro =  6.02214076e23) {
  copies/volume/avogadro
}




StdPara <- data.frame(
  PSI = 1,
  ratio = 0,
  Template = copytoconc(1e5),
  Primer = 5e-7,
  fFluoA = 1,
  Signal_A = 0,
  fFluoB = 1,
  Signal_B = 0,
  Primer_k1 = 5e5,  # literature: 5e5 /M s
  Primer_k2 = 1e-4, # literature: 1e-4 /s
  ProbeA_k1 = 7e5,
  ProbeA_k2 = 1e-4,
  Poly_k1 = 1e8,
  ProbeB_k1 = 7e5,
  ProbeB_k2 = 1e-4,
  hetero_k1 = 1e6,
  hetero_k2 = 1e-10,
  rehybA_k1 = 1e7,
  rehybA_k2 = 1e-10, # 100bp : 1e-4/s
  rehybB_k1 = 1e7,
  rehybB_k2 = 1e-10,
  ProbeA = 3e-7,
  ProbeB = 3e-7,
  Polymerase = 2e-4, # literatue typical 1e-8
  RdsPoly_k1 = 3e6,
  RdsPoly_k2 = 1e-3)


StdPara2 <- data.frame(
  stopTime = 45,
  PSI = 1,
  ratio = 0,
  Template = copytoconc(1e5),
  Primer = 5e-7,
  fFluoA = 1,
  fFluoB = 1,
  bFluoA = 0,
  bFluoB = 0,
  Signal_A = 0,
  Signal_B = 0,
  Primer_k1 = 5e5,  # literature: 5e5 /M s
  Primer_k2 = 1e-4, # literature: 1e-4 /s
  ProbeA_k1 = 7e5,
  ProbeA_k2 = 1e-4,
  ProbeB_k1 = 7e5,
  ProbeB_k2 = 1e-4,
  hetero_k1 = 1e6,
  hetero_k2 = 1e-10,
  rehybA_k1 = 1e7,
  rehybA_k2 = 1e-10, # 100bp : 1e-4/s
  rehybB_k1 = 1e7,
  rehybB_k2 = 1e-10,
  ProbeA = 3e-7,
  ProbeB = 3e-7,
  Polymerase = 2e-4, # literatue typical 1e-8
  Poly_k1 = 1e8,
  RdsPoly_k1 = 3e6,
  RdsPoly_k2 = 1e-3)



omnorm<- function(temp){

  Template <- temp$par_startTemplate[1]
  Primer <- temp$par_startPrimer[1]
  Ratio <- temp$par_startRatio[1]

  temp$totalA <- (temp$totalAa + temp$totalAs)/2
  temp$totalB <- (temp$totalBa + temp$totalBs)/2
  temp$totalT <- temp$totalA + temp$totalB
  temp$totalNA <- temp$totalA/(Template*Ratio + Primer)
  temp$totalNB <- temp$totalB/(Template*(1-Ratio) + Primer)
  temp$totalNT <- temp$totalT/(Template + Primer)
  return(temp)
}

omdiff <- function(temp){

  Template <- temp$par_startTemplate[1]
  Primer <- temp$par_startPrimer[1]
  Ratio <- temp$par_startRatio[1]
  temp <- omnorm(temp)
  len <- nrow(temp)
  difA <- difB <- difT <- dif2A <- dif2B <- dif2T <- dif3A <- dif3B <- dif3T <- effA <- effB <- effT <- NA
  if (len>1) {
    difA <- c(temp$totalA[2:len]-temp$totalA[1:(len-1)],NA)
    difB <- c(temp$totalB[2:len]-temp$totalB[1:(len-1)],NA)
    difT <- c(temp$totalT[2:len]-temp$totalT[1:(len-1)],NA)
    effA <- c(temp$totalA[2:len]/temp$totalA[1:(len-1)],NA)
    effB <- c(temp$totalB[2:len]/temp$totalB[1:(len-1)],NA)
    effT <- c(temp$totalT[2:len]/temp$totalT[1:(len-1)],NA)
    if (len>2) {
      dif2A <- c(NA,difA[2:(len-1)]-difA[1:(len-2)],NA)
      dif2B <- c(NA,difB[2:(len-1)]-difB[1:(len-2)],NA)
      dif2T <- c(NA,difT[2:(len-1)]-difT[1:(len-2)],NA)
      if (len>3) {
        dif3A <- c(NA,dif2A[3:(len-1)]-dif2A[2:(len-2)],NA,NA)
        dif3B <- c(NA,dif2B[3:(len-1)]-dif2B[2:(len-2)],NA,NA)
        dif3T <- c(NA,dif2T[3:(len-1)]-dif2T[2:(len-2)],NA,NA)
      }}}

  temp$difA <- difA
  temp$difB <- difB
  temp$difT <- difT
  temp$dif2A <- dif2A
  temp$dif2B <- dif2B
  temp$dif2T <- dif2T
  temp$dif3A <- dif3A
  temp$dif3B <- dif3B
  temp$dif3T <- dif3T
  temp$difNA <- difA/(Template*Ratio + Primer)
  temp$difNB <- difB/(Template*(1-Ratio) + Primer)
  temp$difNT <- difT/(Template + Primer)
  temp$dif2NA <- dif2A/(Template*Ratio + Primer)
  temp$dif2NB <- dif2B/(Template*(1-Ratio) + Primer)
  temp$dif2NT <- dif2T/(Template + Primer)
  temp$dif3NA <- dif3A/(Template*Ratio + Primer)
  temp$dif3NB <- dif3B/(Template*(1-Ratio) + Primer)
  temp$dif3NT <- dif3T/(Template + Primer)
  temp$effA <- effA
  temp$effB <- effB
  temp$effT <- effT

  return(temp)
}

calPCRcoef <- function(df){
  # cd1 <- max(which(df$dif2NT>0))
  # xcd1 <- calcross(data.frame(x=df$totalNT[cd1:(cd1+1)],y=df$dif2NT[cd1:(cd1+1)]))-0.1
  # cd2a <- max(which(df$dif3NT[1:cd1]>0))
  # xcd2a <- calcross(data.frame(x=df$totalNT[cd2a:(cd2a+1)],y=df$dif3NT[cd2a:(cd2a+1)]))
  # cd2b <- min(which(df$dif3NT[(cd1+1):length(df$dif3NT)]>0))+cd1-1
  # xcd2b <- calcross(data.frame(x=df$totalNT[cd2b:(cd2b+1)],y=df$dif3NT[cd2b:(cd2b+1)]))
  over <- df[1,grep("par_",names(df))]
  names(over) <- substring(names(over),5)

  cmax <- which.max(df$difNT)
  interval <- df$totalNT[c(cmax-1,cmax+1)]
  print(interval)
  a <- optimize(omPCRopt,interval=interval,dif=1,tol=0.0001,maximum=TRUE,simPath=simPath,simModel=simModel,override=over)
  cmax <- which.max(df$dif2NT)
  interval <- df$totalNT[c(cmax-1,cmax+1)]
  b <- optimize(omPCRopt,interval=interval,dif=2,tol=0.0001,maximum=TRUE,simPath=simPath,simModel=simModel,override=over,delta=0.01)
  cmax <- which.min(df$dif2NT)
  interval <- df$totalNT[c(cmax-1,cmax+1)]
  c <- optimize(omPCRopt,interval=interval,dif=2,tol=0.0001,maximum=FALSE,simPath=simPath,simModel=simModel,override=over,delta=0.01)



  # over$stopTime <- 45
  # PCRmax <- over$startPrimer+over$startTemplate
  # over$startPrimer <- PCRmax*(1-xcd1)
  # over$startTemplate <- PCRmax*xcd1
  # over$stepSize <- 45
  # print(over)
  #
  #  md1 <-  omnorm(omPCR(simModel,
  #                simPath,
  #                override=over,
  #                details = FALSE))$totalNT
  # print(which.max(df$difNT))
  #
  #  print(df$totalNT[which.max(df$difNT)])
  #
  #  print(max(df$difNT,na.rm=TRUE))
  #  print(cd1)
  #  print(xcd1)
  #  print(md1-xcd1)
  return(c(unlist(a),b$maximum,c$minimum))
}

calcross <- function(df){
  df$y <- abs(df$y)
  cross <- df$x[1]+(df$x[2]-df$x[1])*df$y[1]/(df$y[1]+df$y[2])
  return(cross)
}

omPCRopt <- function(x,dif,simModel,simPath,override,delta=0.0001){

  PCRmax <- override$startPrimer+override$startTemplate
  override$startPrimer <- PCRmax*(1-x)
  override$startTemplate <- PCRmax*x
  override$stepSize <- 45
  override$stopTime <- 45
  if (dif==1) {
    temp <- omnorm(omPCR(simModel,
                         simPath,
                         override=override,
                         details = FALSE))$totalNT-x
  }
  else {
    x1 <- x -delta
    override$startPrimer <- PCRmax*(1-x1)
    override$startTemplate <- PCRmax*x1
    override$stepSize <- 45
    override$stopTime <- 45
    temp1 <- omnorm(omPCR(simModel,
                          simPath,
                          override=override,
                          details = FALSE))$totalNT-x1
    x2 <- x -delta
    override$startPrimer <- PCRmax*(1-x2)
    override$startTemplate <- PCRmax*x2
    override$stepSize <- 45
    override$stopTime <- 45
    temp2 <- omnorm(omPCR(simModel,
                          simPath,
                          override=override,
                          details = FALSE))$totalNT-x2
    temp <- temp2-temp1



  }


  return(temp)
}


omTrans <- function(data,signal = c("totalA","totalB"),target = NULL,col = NULL,sdfac=200,seed=2025) {

  data$well <- as.numeric(interaction(data[,grep("par_",names(data))]))
  data$sample <- paste0("Cal",import$par_startRatio*100)
  data$target <- if (is.null(target)) "Simulation" else interaction(data[,target])

  # old -> data$sample <- if (is.null(sample)) data$well else interaction(data[,sample])
  if (is.null(col)) col <- names(data)[grep("par_",names(data))[[1]]]

  set.seed(seed)
  data$FluoARn <- data$FluoA  + rnorm(length(data$FluoA), mean = 0, sd = data$par_bFluoA/sdfac)
  data$FluoBRn <- data$FluoB  + rnorm(length(data$FluoB), mean = 0, sd = data$par_bFluoB/sdfac)
  data$FluoARndelta <- data$FluoARn - data$par_bFluoA
  data$FluoBRndelta <- data$FluoBRn - data$par_bFluoB

  data$FluoAdelta <- data$FluoA - data$par_bFluoA
  data$FluoBdelta <- data$FluoB - data$par_bFluoB


  data$Fincl <- data[,signal[1]]
  data$Fexcl <- data[,signal[2]]
  data$bFincl <- data$Fincl
  data$bFexcl <- data$Fexcl
  data$Ftotal <- data$Fincl + data$Fexcl
  data$bFtotal <- data$bFincl + data$bFexcl
  data$USI <- data$Fincl/data$Ftotal
  data$bUSI <- data$bFincl/data$bFtotal
  data$rcycle <- rpcr_batch("rpcr_relCycle", data, id_col = c("Ftotal","cycle"))
  data$tPSI <- data$par_startRatio
  return(data)
}
