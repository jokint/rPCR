#' Calculate proportion from ratioPCR data
#'
#' Calculate the aprop from fluorescence data.
#' Different methods can by used for the calculation of aprop
#'
#' @param df Data frame containing the flourescence data of the inclusion and exclusion probe
#' @param tres Threshold value to define a range of cycles used for aprop calculation when the range type is dynamic.
#' @param rtype A vector of two values defining the method, how to determine the starting and ending cycle used for aprop calculation
#'   Possible methods c("dynamic","full","ip",c(1:dim((df))))
#' @param roff offset from range defined by rtype
#' @param model Single String defining the model used to calculate aprop c("linear","single")
#' @param method Method type how to calculate the ratio
#' @param calib calibration parameter for ratio correction
#' @param plot print plot (default = FALSE)
#' @param average default = TRUE
#' @param offset offset for derivate calculation
#' @param derivative data transformed to 1. derivative (default = FALSE)
#' @param baseline baseline correction (default = FALSE)
#' @param ... parameters passed to other functions
#'
#' @return calculated ratio
#' @export
#'
rpcr_fit <- function(df,
                    tres = c(0,0),     # treshold value to define dynamic range
                    rtype="ip", # method to define range
                    roff=c(0,0), # offset from range defined by rtype
                    model="linear", # fitting method: either linear or single
                    method=c("FA","FT"), # Variables used for fitting
                    calib = c(1,0,0,1), # Calibration parameters
                    plot=FALSE, # add a plot
                    average = TRUE,
                    offset=1,
                    derivative = FALSE,
                    baseline = FALSE,
                    ...) {

  ## valid parameters
  p_rtype <- c("dynamic","full","ip","amp",paste0("amp-",letters[1:6]),c(1:dim((df))[1]))
  p_model <- c("linear","single")
  p_method <- list(c("FB","FA"),c("FA","FB"),c("FA","FT"),c("FB","FT"),1,2,3,4)
  p_convert <- list(quote(1/(slope+1)),quote(slope/(slope+1)),quote(slope),quote(1-slope))

  ## include some qc testing

  flag_test <- TRUE

  # PARAMTER VALIDATION

  ## Validation of method
  if (!(Position(function(x) identical(x, method), p_method, nomatch = 0) > 0)) stop("Method paramter is invalid") else if(is.numeric(method)) method <- p_method[[method]]

  ## Validation of range
  if (length(rtype)==1) rtype <- c(rtype,rtype)
  if (!all(unlist(lapply(rtype, function(x) x %in% p_rtype)))) warning(paste("Range parameter is invalid:",rtype))

  # PREPARING DATA

  ## getting total values from provided data
  names(df) <- c("FA","FB")

  if (baseline) df$FA <-  rpcr_calBase(df,offset=offset,tres=tres,...)

  df$FT <- df$FA + df$FB

  Ft_d1 <- rpcr_calDer(df$FT,offset=offset,...)

  Cpi <- rpcr_calCip(df$FT,...)
  if (is.na(Cpi)) {
    flag_test <- FALSE
    Cpi <- 0
  }
  Ft_d1_max <- Ft_d1[Cpi]




  # DEFINING THE RANGE

  rtable <- data.frame(type = NULL, start = NULL, end = NULL)

  ## setting range for daynamic paramters
  if ("ip" %in% rtype) {
    rtable <- rbind(rtable, data.frame(type = "ip", start = Cpi, end = Cpi))# old ..., end = which.max(Ft_d1)))
  }

  if (any(grepl("amp",rtype))) {
    temp <- rpcr_calCip(df$FT, detail = TRUE)
    t1 <- do.call(rbind,strsplit(rtype,"-"))[,2]
    rtable <- rbind(rtable, data.frame(type = "amp", start = if (Cpi>0) utils::tail(temp[temp$qc==TRUE,t1[1]],1) else 0, end = if (Cpi>0) utils::tail(temp[temp$qc==TRUE,t1[2]],1) else 0))# old ..., end = which.max(Ft_d1)))
    rtype[grepl("amp",rtype)] <- "amp"
  }

  if ("dynamic" %in% rtype) {
    if (length(tres)==1) tres <- c(tres,tres)
    bool1 <- rle(with(rle(Ft_d1 > Ft_d1_max*tres[1]), rep(lengths == max(lengths[values]) & values, lengths)))
    if (length(bool1$lengths)==1) bool1$length <- c(0,bool1$lengths) #corrects in case the curve (d1) is always above treshold
    bool2 <- rle(with(rle(Ft_d1 > Ft_d1_max*tres[2]), rep(lengths == max(lengths[values]) & values, lengths)))
    rtable <- rbind(rtable,data.frame(type = "dynamic", start = bool1$length[1]+1, end = sum(bool2$length[1:2])))
    }
  if ("full" %in% rtype) {
    rtable <- rbind(rtable,data.frame(type = "full", start = 1, end = dim(df)[1]))
  }

  if (derivative) {
    df$FA <-  rpcr_calDer(df$FA,offset=offset,...)
    df$FB <-  rpcr_calDer(df$FB,offset=offset,...)
    df$FT <-  rpcr_calDer(df$FT,offset=offset,...)
  }

  ## in case numeric cycle number is provided to define the range
  range <- rtype
  suppressWarnings({
    if (is.na(as.numeric(rtype[1]))) range[1] <- rtable[rtable$type==rtype[1],2]
    if (is.na(as.numeric(rtype[2]))) range[2] <- rtable[rtable$type==rtype[2],3]
  })

  range <- as.numeric(range)+roff

  ## Testing range parameters
  if (any(is.na(rtable))) flag_test <- FALSE else {
  if (range[1]<1) flag_test <- FALSE  # range[1] <- 1
  if (range[2]>dim(df)[1]) flag_test <- FALSE # range[2] <- dim(df)[1]
  if (range[1]>range[2]) flag_test <- FALSE   # range[1] <- range[2]
  if (range[1]==range[2]) model="single"
  }

  ## Constructing the fitting model using parameter model and method
  res <- list()
  class(res) <- c("qspcr","ln")
  rownames(df) <- c(1:dim(df)[1])
  res$DATA <- df
  res$RANGE <- range
  res$MODEL <- model
  res$RTYPE <- rtype
  res$SLOPE <- NA

  if (flag_test) {
    if (model=="linear"){
      LM <- stats::lm(paste0(method[[1]]," ~ ",method[[2]]), data = df[range[1]:range[2],])
      res$CALL <- as.list(LM$call)
      res$lm <- LM
      if(!any(is.na(stats::coef(LM)))) {
        slope <- stats::coef(LM)[2]
        res$SLOPE <- c(slope,summary(LM)$coefficients[2,4],summary(LM)$adj.r.squared)
        names(res$SLOPE) <- c("slope","Pr(>|t|)","adj.r.squared")
        } else {
        slope <- NA
        res$SLOPE <- slope
        }
      } else {
      slope <- mean(df[range[1]:range[2],method[[1]]]/df[range[1]:range[2],method[[2]]],na.rm = TRUE)
      res$SLOPE <- slope
      names(res$SLOPE) <- c("slope")
      }

    res$aprop <- eval(p_convert[[Position(function(x) identical(x, method), p_method, nomatch = 0)]])
    res$cprop <- rpcr_prop(res$SLOPE,calib=calib, ...)[1]
  } else {
    res$aprop <- NA
    res$cprop <- NA
  }

  if (plot) res$plot <- rpcr_fitPlot(res,...) else res$plot <- NA

  return(res)
}
