#' Generating plot to validate calibration
#'
#' @param error displays errorbars if TRUE
#' @param ctype cycle
#' @param confidence confidence interval
#' @param signal type of signal
#' @param percentage use derivative of signal when TRUE
#' @param limit axis limits of plots
#' @param para parameter for calibration
#' @param smooth smooth date
#' @param ratio Ratio between plots
#' @param ... arguments for passing
#' @param data data
#' @param derivate derivate (default = FALSE)
#' @param calibrate perform calibration (default = FALSE)
#' @param color_target colors for target
#' @param color_sample colors for samples
#' @param raw raw ???
#' @param var selected variable
#'
#' @importFrom grDevices colorRampPalette
#' @importFrom RColorBrewer brewer.pal
#' @return plots
#' @export
#'
rpcr_plotCalib <- function(data = NULL,
                          error = FALSE,
                          ctype = "fix",
                          confidence = FALSE,
                          signal = "Rn",
                          derivate = FALSE,
                          percentage = FALSE,
                          limit = c(-0.5,0.5),
                          calibrate = FALSE,
                          para = NULL,
                          smooth = FALSE,
                          ratio = 2,
                          color_target = c("#1B9E77","#D95F02","#7570B3","#E7298A","#66A61E","#E6AB02","#A6761D","#666666"),
                          color_sample = colorRampPalette(c("grey90", "grey30")),
                          raw = TRUE,
                          var = "aprop",
                          ...) {

  argg <- c(as.list(environment()),list(...))

  percent <- if (percentage)  100 else 1


  plot_list <- list( ggplot() + geom_line(data = data.frame(x = c(0, percent), y = c(0, percent), target = ""),
                                aes(x, y),
                                col = "black",
                                linewidth = 0.2,
                                linetype = "dashed") +
                       theme_rpcr() +
                       scale_alpha_continuous(range = c(0.2, 0.8)) +
                       scale_colour_manual(values = color_target) +
                       scale_fill_manual(values = color_target)
                      ,
                    ggplot() + geom_line(data = data.frame(x = c(0, percent), y = c(0, 0), target = ""),
                                         aes(x, y),
                                         col = "black",
                                         linewidth = 0.2,
                                         linetype = "dashed") +
                      theme_rpcr() +
                      scale_alpha_continuous(range = c(0.2, 0.8)) +
                      scale_colour_manual(values = color_target) +
                      scale_fill_manual(values = color_target))

  if (!is.null(data)) {

    df <- if (raw) do.call(rpcr_calibrate,c(argg,output = "details"))$summary else data

    df$delta <- df[,var] - df$tprop

    plot_list[[1]] <-plot_list[[1]] +
      geom_point(data = df, aes(x = tprop, y = .data[[var]], col = target),size=0.5) +
      labs(
        x = "theoretical proportion",
        y = signal)

    plot_list[[2]] <-plot_list[[2]] +
      geom_point(data = df, aes(x = tprop, y = .data[[var]] - tprop, col = target),size=0.5) +
      labs(
        x = "tprop",
        y = paste0("delta (",var,"-tprop)"))

    if (smooth) {
      plot_list[[1]] <-plot_list[[1]] + geom_line(data = df, stat = "smooth", method = "loess", aes(x = tprop, y = .data[[var]], col = target),linewidth=0.5,alpha=0.5)
      plot_list[[2]] <-plot_list[[2]] + geom_line(data = df, stat = "smooth", method = "loess", aes(x = tprop, y = .data[[var]] - tprop, col = target),linewidth=0.5, alpha = 0.5)
    }

    if (error) {
      df1 <- aggregate(as.formula(paste(var, "~ tprop + target")), data = df,
                       FUN = function(x) c(mean = mean(x), sd = sd(x, na.rm = TRUE)))
      df1 <- cbind(df1[1:2], as.data.frame(df1[[3]]))

      df2 <- aggregate(delta ~ tprop + target, data = df,
                       FUN = function(x) c(mean = mean(x), sd = sd(x, na.rm = TRUE)))
      df2 <- cbind(df2[1:2], as.data.frame(df2[[3]]))

      plot_list[[1]] <- plot_list[[1]] + stat_summary(data = df,
                                                      aes(x = tprop, y = .data[[var]], col = target),
                                                      fun.data = mean_sdl,
                                                      fun.args = list(mult = 1),
                                                      geom = "errorbar",
                                                      width = 0.1,
                                                      linewidth = 0.05)
                # geom_errorbar(data = df1, aes(x = tprop, ymin = mean - sd, ymax = mean + sd, col = target), width = 0.05)
      plot_list[[2]] <- plot_list[[2]] + stat_summary(data = df,
                                                      aes(x = tprop, y = delta, col = target),
                                                      fun.data = mean_sdl,
                                                      fun.args = list(mult = 1),
                                                      geom = "errorbar",
                                                      width = 0.1,
                                                      linewidth = 0.05)
        # geom_errorbar(data = df2, aes(x = tprop, ymin = mean - sd, ymax = mean + sd, col = target), width = 0.05)

    }


    if (confidence) {
      plot_list[[1]] <-plot_list[[1]] + geom_smooth(data = df, aes(x = tprop, y = .data[[var]], fill = target), col = NA, method = "loess")
      plot_list[[2]] <-plot_list[[2]]  + geom_smooth(data = df, aes(x = tprop, y = .data[[var]]- tprop, fill = target), col = NA, method = "loess")
    }

    # if (limit) {
      plot_list[[1]] <-plot_list[[1]]  + coord_cartesian(ylim = c(0, percent))
      plot_list[[2]] <-plot_list[[2]]  + coord_cartesian(ylim = limit*percent)
    # }
  }

  if (calibrate && is.null(para)) {

    if (!is.null(data)) para <- if (!all(is.na(data[,var]))) t(do.call(rpcr_calibrate,argg))

    para <- data.frame(para)

    para <- para[,order(names(para))]
    plot_list <- rpcr_plotSim(para = data.frame(para),append = plot_list,lincols = color_target, ...)
  }


  plot_list[[3]] <- (plot_list[[1]] + theme(plot.margin = unit(c(1, 1, 0, 1), "lines"))) /
    (plot_list[[2]] + theme(plot.title = element_blank(), plot.margin = unit(c(0, 1, 1, 1), "lines"))) +
    patchwork::plot_layout(
      heights = c(ratio, 1),
      guides = "collect"
    ) &
    theme(legend.position = "bottom")


  plot_list[[3]] <- plot_list[[3]] &
    scale_colour_manual(values = color_target) &
    scale_fill_manual(values = color_target)

  return(plot_list)
}

