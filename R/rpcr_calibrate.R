#' Title
#'
#' @param data input data for calibration
#' @param ... parameters passed to other functions
#' @param output type of data to be returned
#' @param median median
#' @param prop proportion setting
#' @param extend extended model
#' @param roff relative cycle offset
#' @param tres treshold
#' @param method method
#' @param model model
#' @param qual calibration samples qualifier
#' @param signal signal type
#' @param rtype range type
#'
#' @return calibration parameters
#' @export
#' @importFrom dplyr group_by
#' @importFrom dplyr mutate
#' @importFrom dplyr summarise
#' @importFrom magrittr %>%
#' @importFrom stats aggregate
#' @importFrom stats coef
#' @importFrom stats deviance
#' @importFrom stats lm
#' @importFrom stats median
#'
#'
rpcr_calibrate <- function(data,
                          output = "calib",
                          median = FALSE,
                          prop = TRUE,
                          extend = FALSE,
                          roff,
                          tres,
                          method,
                          model,
                          qual,
                          signal,
                          rtype,
                          ...) {


  df <- rpcr_batchFit(data,info=TRUE,...)

  df$summary <- rpcr_calibDetect(df$summary,qual=qual,...)


  if (median) {
    df$summary <- df$summary %>% dplyr::group_by(target,sample) %>% dplyr::mutate(USI = median(USI))
    df$summary <- as.data.frame(unique(df$summary[,c("sample","target","USI","tPSI")]))
  }
  ### for each target the calibration is performed separately


  for (targets in unique(df$summary$target)){

    ### The calibration parameters is calculated from calibration samples (tPSI<>NA)
    df[["calib"]][[targets]]  <- rpcr_calib(df$summary[df$summary$target==targets&!is.na(df$summary$tPSI),], prop = prop, extend = extend) # added ",...)" 7.8.2025 removed again 18.8

    ### if calibration was successful, cPSI and delta calculated using the calibration parameter
    if (!is.na(df[["calib"]][targets])) {
    df$summary[df$summary$target==targets,"cPSI"] <-rpcr_psi(df$summary[df$summary$target==targets,"USI"], stats::coef(df$calib[[targets]]),prop=prop,extend=extend)
    df$summary[df$summary$target==targets,"delta"] <-df$summary[df$summary$target==targets,"cPSI"]-df$summary[df$summary$target==targets,"tPSI"]
    }
    ### if calibration failed, for cPSI and delta is set to NA
    else {
      df$summary[df$summary$target==targets,"cPSI"] <- NA
      df$summary[df$summary$target==targets,"delta"] <- NA
    }
  }

  ### empty calibration summary data.frame with NA
  summary <- list(calib=data.frame(target=unique(data$target),a=NA,ri=NA,re=NA,g=NA,f=NA),
                    qc=data.frame(target=unique(data$target),RSSfit=NA,RSEfit=NA,RSScpsi=NA,RSEcpsi=NA,MSDfit=NA,MSDcpsi=NA,facRSE=NA,facMSD=NA,failures=TRUE))

  ### Coefficients are calculatd
  for (targets in unique(data$target)){
    if (!is.na(df$calib[targets])) {
      fit <- df$calib[[targets]]
      coef <- stats::coef(fit)
      summary$calib[summary$calib$target==targets,names(coef)] <- coef
      rownames(summary$calib) <- summary$calib$target # added 20250902
      summary$qc[summary$qc$target==targets,c("RSSfit","RSEfit")] <- c(RSSfit = stats::deviance(fit),RSEfit=summary(fit)$sigma)
      temp <- df$summary[df$summary$target==targets&!is.na(df$summary$cPSI)&!is.na(df$summary$tPSI),]
      if (nrow(temp)>0) summary$qc[summary$qc$target==targets,c("RSScpsi","RSEcpsi")] <- temp %>%
        dplyr::summarise(RSScpsi = stats::deviance(stats::lm(cPSI ~ tPSI),na.rm=TRUE), RSEcpsi = summary(stats::lm(cPSI ~ tPSI))$sigma)
      }}

  failure <- df$summary[!is.na(df$summary$tPSI),] %>% dplyr::group_by(target) %>%
        dplyr::summarise(failures = ifelse(any(is.na(cPSI)), TRUE, FALSE))

    temp <- stats::aggregate(list(sd1 = df$summary[, "USI"] * 100,sd2 = df$summary[, "cPSI"] * 100),
                    list(target = df$summary$target, sample = df$summary$sample),
                    sd)
    temp <- stats::aggregate(list(MSDfit = temp$sd1,MSDcpsi = temp$sd2),
                    list(target = temp$target),
                    function(x) mean(x))
    for (targets in unique(data$target)) summary$qc[summary$qc$target==targets,c("MSDfit","MSDcpsi")] <-temp[temp$target==targets,c("MSDfit","MSDcpsi")]
    summary$qc$facRSE <- summary$qc$RSEfit/summary$qc$RSEcpsi
    summary$qc$facMSD <- summary$qc$MSDfit/summary$qc$MSDcpsi
    summary$qc <- merge(summary$qc,failure, by = "target")

   # }

  df$calib$summary <- summary

  if (output=="calib") out <- summary$calib
  if (output=="qc") out <- summary$qc
  if (output %in% names(summary$qc)){

    temp0 <- data.frame(signal=signal,rtype=paste(rtype,collapse=":"),roff=paste(roff,collapse=":"),tres=paste(tres,collapse=":"),method=paste(method,collapse=":"),model= model)
    temp1 <- rpcr_calibrate(df,tres=tres,rtype=rtype,roff=roff,method=method,model=model,qual=qual,output="qc",...)
    rownames(temp1) <- temp1$target

    temp2 <- data.frame(t(temp1))[,output]

    cbind(temp0,mean = mean(temp1[,output]),temp2)


  }
  if (output=="details") out <- df

  return(out)
}

utils::globalVariables(c("target","USI","cPSI","sd"))


