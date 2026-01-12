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
  df$usi <- df$incl/df$total
  df$dincl <- rpcr_calDer(df$incl,offset=offset)
  df$dexcl <- rpcr_calDer(df$excl,offset=offset)
  df$dtotal <- rpcr_calDer(df$total,offset=offset)
  df$dusi <- df$dincl/df$dtotal

  range <- c(x$RANGE[1]:x$RANGE[2])

  width <- max(df$total)-min(df$total)
  lim_min <- min(df$total)-width/6
  limits <- c(if(lim_min>0) 0 else lim_min,max(df$total)+width/6)

  width <- max(df$dtotal)-min(df$dtotal)
  lim_min <- min(df$dtotal)-width/6
  lim_max <- max(df$dtotal)+width/6
  dlimits <- c(if(lim_min>0) 0 else lim_min,lim_max)

  ip <- which.max(df$dtotal)

  dfm <- melt(df,measure.vars=c("incl","excl","total","dincl","dexcl","dtotal"))
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
    geom_path(data = df[df$cycle %in% range,], aes(x = total, y = incl), col = "grey30",arrow = arrow(angle=15,type="closed", unit(0.25, "inches"))) +
    stat_smooth(data = df[df$cycle %in% range,], aes(x = total, y = incl),method = "lm", col = "red") +
    geom_point(data = df[df$cycle %in% range,], aes(x = total, y = incl),color="grey30",alpha=0.2,size=4) +
    geom_point(data = df, aes(x = total, y = incl)) +
    geom_point(data = df[df$cycle %in% ip,], aes(x = total, y = incl), color = 2) +
    design +
    labs(y = "fluorescence signal\n(inclusion probe)",
         x = "fluorescence signal\n(both probes - total signal)")

  plots[[5]] <- plots[[7]] + scale_y_continuous(limits = limits) +scale_x_continuous(limits = limits)

  plots[[8]] <- plot +
    geom_path(data =  df[df$cycle %in% range,], aes(x = dtotal, y = dincl), col = "grey30",arrow = arrow(angle=15,type="closed", unit(0.25, "inches"))) +
    stat_smooth(data = df[df$cycle %in% range,], aes(x = dtotal, y = dincl),method = "lm", col = "red") +
    geom_point(data = df[df$cycle %in% range,], aes(x = dtotal, y = dincl),color="grey30",alpha=0.2,size=4) +
    geom_point(data = df, aes(x = dtotal, y = dincl)) +
    geom_point(data = df[df$cycle %in% ip,], aes(x = dtotal, y = dincl), color = 2) +
    design +
    labs(y = "1st derivate of fluorescence signal\n(inclusion probe)",
         x = "1st derivate of fluorescence signal\n(both probes - total signal)")

  plots[[6]] <- plots[[8]] + scale_y_continuous(limits = dlimits) +scale_x_continuous(limits = dlimits)

  plot <- ggarrange(plotlist=plots,
            labels = c("A", "B", "C","D","E","F"),
            ncol = 2, nrow = 4,align="hv")

  return(if (aslist) plots else plot)
}
