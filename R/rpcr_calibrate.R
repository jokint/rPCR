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
                          qual="Cal",
                          signal,
                          rtype,
                          ...) {

  argg <- c(as.list(environment()),list(...))
  df <- do.call(rpcr_batchFit,c(argg,info = "TRUE"))

  df$summary <- rpcr_calibDetect(df$summary,qual=qual,...)

  if (median) {
    df$summary <- df$summary %>% dplyr::group_by(target,sample) %>% dplyr::mutate(aprop = median(aprop))
    df$summary <- as.data.frame(unique(df$summary[,c("sample","target","aprop","tprop")]))
  }

  ### for each target the calibration is performed separately
  for (targets in unique(df$summary$target)){

    # The calibration parameters is calculated from calibration samples (tprop<>NA)
    df[["calib"]][[targets]]  <- rpcr_calib(df$summary[df$summary$target==targets&!is.na(df$summary$tprop),], prop = prop, extend = extend) # added ",...)" 7.8.2025 removed again 18.8

    # if calibration was successful, cprop and delta calculated using the calibration parameter
    if (!is.na(df[["calib"]][targets])) {
      df$summary[df$summary$target==targets,"cprop"] <-rpcr_prop(df$summary[df$summary$target==targets,"aprop"], stats::coef(df$calib[[targets]]),prop=prop,extend=extend)
      df$summary[df$summary$target==targets,"delta"] <-df$summary[df$summary$target==targets,"cprop"]-df$summary[df$summary$target==targets,"tprop"]
      } else { # if calibration failed, for cprop and delta is set to NA
      df$summary[df$summary$target==targets,"cprop"] <- NA
      df$summary[df$summary$target==targets,"delta"] <- NA
      }
    }

  ### empty calibration summary data.frame with NA
  summary <- list(calib=data.frame(target=unique(data$target),a=NA,ri=NA,re=NA,g=NA,f=NA),
                    qc=data.frame(target=unique(data$target),RSSfit=NA,RSEfit=NA,RSScprop=NA,RSEcprop=NA,MSDfit=NA,MSDcprop=NA,facRSE=NA,facMSD=NA,failures=TRUE))

  ### Coefficients are calculatd
  for (targets in unique(data$target)){
    if (!is.na(df$calib[targets])) {
      fit <- df$calib[[targets]]
      coef <- stats::coef(fit)
      summary$calib[summary$calib$target==targets,names(coef)] <- coef
      rownames(summary$calib) <- summary$calib$target # added 20250902
      summary$qc[summary$qc$target==targets,c("RSSfit","RSEfit")] <- c(RSSfit = stats::deviance(fit),RSEfit=summary(fit)$sigma)
      temp <- df$summary[df$summary$target==targets&!is.na(df$summary$cprop)&!is.na(df$summary$tprop),]
      if (nrow(temp)>0) summary$qc[summary$qc$target==targets,c("RSScprop","RSEcprop")] <- temp %>%
        dplyr::summarise(RSScprop = stats::deviance(stats::lm(cprop ~ tprop, na.action = na.omit)), RSEcprop = summary(stats::lm(cprop ~ tprop, na.action = na.omit))$sigma)
      }}
  failure <- df$summary[!is.na(df$summary$tprop),] %>% dplyr::group_by(target) %>%
        dplyr::summarise(failures = ifelse(any(is.na(cprop)), TRUE, FALSE))

    temp <- stats::aggregate(list(sd1 = df$summary[, "aprop"] * 100,sd2 = df$summary[, "cprop"] * 100),
                    list(target = df$summary$target, sample = df$summary$sample),
                    sd)
    temp <- stats::aggregate(list(MSDfit = temp$sd1,MSDcprop = temp$sd2),
                    list(target = temp$target),
                    function(x) mean(x))
    for (targets in unique(data$target)) summary$qc[summary$qc$target==targets,c("MSDfit","MSDcprop")] <-temp[temp$target==targets,c("MSDfit","MSDcprop")]
    summary$qc$facRSE <- summary$qc$RSEfit/summary$qc$RSEcprop
    summary$qc$facMSD <- summary$qc$MSDfit/summary$qc$MSDcprop
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

    out <- cbind(temp0,mean = mean(temp1[,output]),temp2)


  }
  if (output=="details") out <- df

  return(out)
}

utils::globalVariables(c("target","aprop","cprop","sd"))


