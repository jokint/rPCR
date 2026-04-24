#' Title
#'
#' @param x data
#' @param offset offset
#' @param design  design
#' @param iso_color colors
#' @param aslist default = FALSE
#' @param line draw line (default = FALSE)
#' @param ... passing arguments
#'
#' @return generated plots
#' @export
#' @import ggpubr
#' @importFrom grDevices rgb
#'
rpcr_fitPlot <- function(x,
                        offset = 1,
                        design = theme_rpcr(),
                        iso_color = c(grDevices::rgb(199, 235, 211, maxColorValue = 255),grDevices::rgb(255, 190, 190, maxColorValue = 255)),
                        aslist = FALSE,
                        line = FALSE,
                        ...) {

  df <- x$DATA
  df$cycle <- 1:dim(df)[1]
  df$usi <- df$FA/df$FT
  df$dFA <- rpcr_calDer(df$FA,offset=offset)
  df$dFB <- rpcr_calDer(df$FB,offset=offset)
  df$dFT <- rpcr_calDer(df$FT,offset=offset)
  df$dusi <- df$dFA/df$dFT

  range <- c(x$RANGE[1]:x$RANGE[2])

  width <- max(df$FT)-min(df$FT)
  lim_min <- min(df$FT)-width/6
  limits <- c(if(lim_min>0) 0 else lim_min,max(df$FT)+width/6)

  width <- max(df$dFT)-min(df$dFT)
  lim_min <- min(df$dFT)-width/6
  lim_max <- max(df$dFT)+width/6
  dlimits <- c(if(lim_min>0) 0 else lim_min,lim_max)

  ip <- which.max(df$dFT)

  dfm <- df %>%
    pivot_longer(
      cols = c("FA", "FB", "FT", "dFA", "dFB", "dFT"),
      names_to = "variable",
      values_to = "value"
    )




  dfm$variable <- as.character(dfm$variable)

  # cat(paste("Model:",x$MODEL,"\n"))
  # cat(paste("Range type:",paste(x$RTYPE, collapse = ","),"\n"))
  # cat(paste("Cycle range:",paste(x$RANGE,collapse = "-"),"\n"))

  plots <- list()

  plot <- ggplot()  + design

  plots[1:4] <- list(if (line) plot + geom_vline(xintercept = ip, colour="grey30", linetype = "longdash") else plot)
  plots[[1]] <- plots[[1]] +
    geom_point(data = dfm[!startsWith(dfm$variable,"d")&df$cycle %in% range,], aes(x = cycle, y = value,group=variable), color = "grey30", alpha=0.2, size = 4) +
    geom_point(data=dfm[!startsWith(dfm$variable,"d"),],aes(x=cycle,y=value,col=variable)) +
    geom_point(data = dfm[!startsWith(dfm$variable,"d")&df$cycle %in% ip,], aes(x = cycle, y = value,group=variable), color = 2) +
    scale_colour_manual(values = c(iso_color,"black")) +
    labs(y = "flourescence signal")

  plots[[2]] <- plots[[2]] +
    geom_point(data = dfm[startsWith(dfm$variable,"d")&df$cycle %in% range,], aes(x = cycle, y = value,group=variable), color = "grey30", alpha = 0.2, size = 4) +
    geom_point(data=dfm[startsWith(dfm$variable,"d"),],aes(x=cycle,y=value,col=variable)) +
    geom_point(data = dfm[startsWith(dfm$variable,"d")&df$cycle %in% ip,], aes(x = cycle, y = value,group=variable), color = 2) +
    scale_colour_manual(values = c(iso_color,"black")) +
    labs(y = "flourescence signal increase\n(first derivative)")

  plots[[3]] <- plots[[3]]  +
    geom_point(data = df[df$cycle %in% range,], aes(x = cycle, y = usi), color = "grey30", alpha=0.2, size = 4) +
    geom_point(data = df, aes(x=cycle,y=usi),col=1)+
    geom_point(data = df[df$cycle %in% ip,], aes(x = cycle, y = usi), color = 2) +
    scale_y_continuous(limits = c(0,1)) +
    labs(y = "apparent PSI\n(uncalibrated)")

  plots[[4]] <- plots[[4]] +
    geom_point(data = df[df$cycle %in% range,], aes(x = cycle, y = dusi), color = "grey30", alpha=0.2, size = 4) +
    geom_point(data = df, aes(x=cycle,y=dusi),col=1)+
    geom_point(data = df[df$cycle %in% ip,], aes(x = cycle, y = dusi), color = 2) +
    scale_y_continuous(limits = c(0,1)) +
    labs(y = "apparent PSI (uncalibrated)\n[calculated using first derivative data]")

  plots[[7]] <- plot +
    geom_path(data = df[df$cycle %in% range,], aes(x = FT, y = FA), col = "grey30",arrow = arrow(angle=15,type="closed", unit(0.25, "inches"))) +
    stat_smooth(data = df[df$cycle %in% range,], aes(x = FT, y = FA),method = "lm", col = "red") +
    geom_point(data = df[df$cycle %in% range,], aes(x = FT, y = FA),color="grey30",alpha=0.2,size=4) +
    geom_point(data = df, aes(x = FT, y = FA)) +
    geom_point(data = df[df$cycle %in% ip,], aes(x = FT, y = FA), color = 2) +
    design +
    labs(y = "fluorescence signal\n(inclusion probe)",
         x = "fluorescence signal\n(both probes - total signal)")

  plots[[5]] <- plots[[7]] + scale_y_continuous(limits = limits) +scale_x_continuous(limits = limits)

  plots[[8]] <- plot +
    geom_path(data =  df[df$cycle %in% range,], aes(x = dFT, y = dFA), col = "grey30",arrow = arrow(angle=15,type="closed", unit(0.25, "inches"))) +
    stat_smooth(data = df[df$cycle %in% range,], aes(x = dFT, y = dFA),method = "lm", col = "red") +
    geom_point(data = df[df$cycle %in% range,], aes(x = dFT, y = dFA),color="grey30",alpha=0.2,size=4) +
    geom_point(data = df, aes(x = dFT, y = dFA)) +
    geom_point(data = df[df$cycle %in% ip,], aes(x = dFT, y = dFA), color = 2) +
    design +
    labs(y = "1st derivate of fluorescence signal\n(inclusion probe)",
         x = "1st derivate of fluorescence signal\n(both probes - total signal)")

  plots[[6]] <- plots[[8]] + scale_y_continuous(limits = dlimits) +scale_x_continuous(limits = dlimits)

  plot <- ggarrange(plotlist=plots,
            labels = c("A", "B", "C","D","E","F"),
            ncol = 2, nrow = 4,align="hv")

  return(if (aslist) plots else plot)
}
