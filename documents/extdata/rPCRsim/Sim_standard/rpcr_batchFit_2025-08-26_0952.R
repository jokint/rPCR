#' Function to calculate USI form multiple PCR experiments
#'
#' @param data data.frame with the pcr flourecence intensities
#' @param ... other parameters for rpcr_fit function
#' @return returns fittings for calibration curves
#' @export
rpcr_batchFit <- function(data,
                         calib = c(1 ,0 ,0 ,1,0),
                         info = FALSE,
                         signal = "Rn",
                         # derivative = FALSE,
                         ...) {

  prefix <- if (signal=="Rn") "" else "b"
  # prefix <- if (derivative) paste0("d1",prefix) else prefix
  cols <- paste0(prefix,c("Fincl","Fexcl"))


  targets <- unique(data$target)
  wells <- unique(data$well)
  out <- vector()
  results <- list()

  tryCatch({
    for (target in unique(data$target)) {

      para <- if (target %in% rownames(calib)) calib[target,] else calib

      for (well in unique(data[data$target==target,"well"])) {
        res <- rpcr_fit(data[data$well == well & data$target == target,cols],calib=unlist(para),...)

        temp <- data.frame(well = well,
                           sample = unique(data[data$well==well,"sample"]),
                           target = target,
                           slope = res$SLOPE[1],
                           range = paste(res$RANGE,collapse=":"),
                           model = res$MODEL,
                           rtype = paste(res$RTYPE,collapse=":"),
                           USI = res$USI[1],
                           cPSI = res$cPSI)

        if (!is.null(res$lm) & !is.na(temp$USI))
          temp <- cbind(temp,
                        stdErr = summary(res$lm)$coefficients[2,2],
                        sigma  = summary(res$lm)$sigma,
                        adjRsq = summary(res$lm)$adj.r.squared,
                        pvalue = summary(res$lm)$coefficients[2,4])
        else
          temp <- cbind(temp, stdErr = NA, sigma  = NA, adjRsq = NA, pvalue = NA)

        ### adding custom fields
        custom <-match("rcycle",names(data))
        if (custom<ncol(data)) {
          n1 <- names(data[,(custom+1):ncol(data)])
          temp1 <- unique(data[data$well==well,(custom+1):ncol(data)])
          names(temp1) <- n1
          temp <- cbind(temp, temp1)
        }
        results[[well]] <- res
        if (is.data.frame(temp)) out <- rbind(out, temp) else out <- c(out, temp)
      }
    }
  }, error = function(cond) {
    message(paste("rpcr_batchFit error in well", well))
    message(cond)
    return(NA)
  })
  rownames(out) <- NULL
  if (info) out <- c(summary=list(out),results)

  return(out)
}


