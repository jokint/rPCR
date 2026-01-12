#' Title
#'
#' @param data data to be plotted
#' @param violin plot violoin (default TRUE)
#' @param boxplot plot boxplot (default TRUE)
#' @param point plot data points (default TRUE)
#' @param bar plot error bars (default FALSE)
#' @param abs ???
#' @param color plotting colors
#'
#' @return plots
#' @export
#'
rpcr_plotCalibQC <- function(data, violin = TRUE, boxplot = TRUE, point = TRUE, bar = FALSE, abs = FALSE, color = brewer.pal(n = 8, name = "Dark2") ) {

  plot <- ggplot(data=data, aes(x = target, y = if (abs) abs(delta) else delta, color = target, fill = target)) +
    scale_fill_manual(values=color) +
    scale_color_manual(values=color)

  # if (abs) plot <- plot +ylim(0,NA)

  if (bar) {
    plot <- plot +
      stat_summary(
        geom = "errorbar",
        fun.max = function(x) mean(x) + sd(x),
        fun.min = function(x) mean(x) - if (abs) mean(x)/2 else sd(x),
        width = .3, size = 1.2, colour = "black"
      ) +
      geom_bar(stat = "summary", width = .8, size = .8)
  } else {
    if (violin) plot <- plot +
        geom_violin(
          aes(fill = target,fill = after_scale(colorspace::lighten(fill, .5))),
          size = 1.2,
          alpha = 0.2
        )

    if (boxplot) plot <- plot +
        geom_boxplot(
          size = 1.2,
          width = 0.1,
          alpha = 0.2,
          colour = "grey30",
          linewidth=0.5)

    if (point) plot <- plot +
        geom_point(
          position = position_jitter(width = .03, seed = 0),
          size = 5,
          alpha = .5) +
        geom_point(
          position = position_jitter(width = .03, seed = 0),
          size = 5,
          stroke = .7,
          shape = 1)

    if (bar) plot <- plot +
        stat_summary(
          geom = "errorbar",
          fun.max = function(x) mean(x) + sd(x),
          fun.min = function(x) mean(x) - sd(x),
          width = .3, size = 1.2
        ) +
        geom_bar(stat = "summary", width = .8, size = .8)
  }

  return(plot+theme_rpcr())
}
