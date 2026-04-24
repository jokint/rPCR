#' Plotting Bar charts of calibration Data
#'
#' @description
#' Generates bar charts with standard error bars for PCR calibration data
#' at a specific amplification cycle.
#'
#' @param data A data frame (or `rpcr_raw` object) containing the PCR data.
#' @param cycle Numeric. Specific cycle to plot. If `NULL`, defaults to the maximum cycle.
#' @param ctype Character string indicating cycle type. If not `"fix"`, uses `rcycle`.
#' @param signal Character string indicating the signal type. Options are `"Rn"` or `"deltaRn"`.
#' @param derivate Character string for derivative prefix.
#' @param title Alternative plot title.
#' @param color_target Color vector for different targets.
#' @param color_sample Color mapping function for different samples.
#' @param colplot Logical. If `TRUE`, adds background colors based on target.
#' @param ... Further arguments passed to `rpcr_calibDetect`.
#'
#' @return A ggplot object.
#' @export
rpcr_plotBar <- function(data,
                         cycle = NULL,
                         ctype = "fix",
                         signal = "Rn",
                         derivate = "",
                         title = "normalized fluorescence\n",
                         color_target = RColorBrewer::brewer.pal(n = 8, name = "Dark2"),
                         color_sample = grDevices::colorRampPalette(c("grey90", "grey30")),
                         colplot = FALSE,
                         ...) {

  # Ensure calibration detection was performed
  if (!"tPSI" %in% names(data)) {
    data <- rpcr_calibDetect(data, ...)
  }

  # Default to maximum cycle if not specified
  if (is.null(cycle)) {
    cycle <- max(data$cycle, na.rm = TRUE)
  }

  # Filter for calibration samples only
  data <- data[!is.na(data$tPSI), ]

  # Pivot to long format for ggplot using native pipe
  df <- data |>
    tidyr::pivot_longer(
      cols = c("FA", "FB", "bFA", "bFB"),
      names_to = "variable",
      values_to = "value"
    ) |>
    as.data.frame()

  # Safe factor conversion for samples
  unique_numeric_samples <- sort(as.numeric(unique(df$tPSI))) * 100

  df$sample <- factor(
    df$tPSI * 100,
    levels = as.character(unique_numeric_samples)
  )



  if (ctype != "fix") df$cycle <- df$rcycle

  prefix <- if (signal == "Rn") "F" else "bF"

  # Setup labels and colors
  newlabel <- c("Inclusion", "Exclusion")
  names(newlabel) <- paste0(derivate, prefix, c("A", "B"))

  targets <- length(unique(df$target))
  samples <- length(unique(df$sample))

  color_sample <- color_sample(samples)
  color_target <- color_target[1:targets]

  # Base ggplot setup
  plot <- ggplot2::ggplot() +
    ggplot2::theme_minimal() + # Replaced theme_rpcr with fallback
    ggplot2::theme(
      axis.text.y = ggplot2::element_text(size = 10, face = "plain"),
      axis.text.x = ggplot2::element_text(size = 8, angle = 45, hjust = 1, vjust = 1),
      panel.grid.major = ggplot2::element_blank(),
      axis.text = ggplot2::element_text(size = 8),
      axis.title = ggplot2::element_text(face = "plain"),
      axis.title.y = ggplot2::element_text(vjust = 0),
      strip.placement = "outside",
      strip.text.y = ggplot2::element_text(vjust = 0, size = 10)
    ) +
    ggplot2::guides(colour = ggplot2::guide_legend(override.aes = list(size = 5), title = NULL))

  # Add background grid color if colplot is TRUE
  if (colplot) {
    plot <- plot +
      ggplot2::geom_rect(
        data = unique(df[order(df$sample, df$target), c("sample", "target")]),
        ggplot2::aes(fill = target),
        col = NA, xmin = -Inf, xmax = Inf, ymin = -Inf, ymax = Inf, alpha = 0.1
      ) +
      ggplot2::scale_fill_manual(values = c("grey80", "grey20", color_target))
  }

  # Build the final plot with bar charts and error bars
  plot <- plot +
    ggplot2::stat_summary(
      data = df[df$cycle == cycle & df$variable %in% paste0(prefix, c("A", "B")), ],
      ggplot2::aes(x = variable, y = value, color = variable, fill = variable),
      fun = mean,
      position = "dodge",
      geom = "col",
      linewidth = 0.5,
      lty = 1,
      col = "black",
      width = 0.7
    ) +
    ggplot2::stat_summary(
      data = df[df$cycle == cycle & df$variable %in% paste0(prefix, c("A", "B")), ],
      ggplot2::aes(x = variable, y = value),
      fun.data = ggplot2::mean_se,
      geom = "errorbar",
      width = 0.5,
      linewidth = 0.5,
      col = "black"
    ) +
    ggh4x::facet_grid2(
      target ~ sample,
      switch = "y",
      strip = ggh4x::strip_themed(
        background_y = if (colplot) ggh4x::elem_list_rect(fill = color_target) else ggh4x::elem_list_rect(fill = "grey90"),
        background_x = ggh4x::elem_list_rect(fill = color_sample)
      )
    ) +
    ggplot2::labs(
      x = "",
      y = signal,
      subtitle = paste("normalized fluorescence at cycle", cycle)
    ) +
    ggplot2::scale_x_discrete(labels = newlabel)

  return(plot)
}



### OLD, please delete from here

#'
#' #' Plotting Bar charts of calibration Data
#' #'
#' #' @param cycle ???
#' #' @param ctype ???
#' #' @param signal type of signal
#' #' @param title alternative plot title
#' #' @param color_target color vector for different targets
#' #' @param color_sample color vector for different samples
#' #' @param colplot TRUE id plot in color
#' #' @param ... passing arguments
#' #' @param data data
#' #' @param derivate derivate
#' #'
#' #' @return plots
#' #' @export
#' #' @importFrom ggh4x facet_grid2 strip_themed elem_list_rect
#' #' @importFrom RColorBrewer brewer.pal
#' #' @importFrom grDevices colorRampPalette
#' #' @import ggplot2
#' #' @import dplyr
#' #'
#' rpcr_plotBar <- function(data,
#'                          cycle = NULL,
#'                          ctype = "fix",
#'                          signal = "Rn",
#'                          derivate = "",
#'                          title = "normalized flourescence\n ",
#'                          color_target = brewer.pal(n = 8, name = "Dark2"),
#'                          color_sample = colorRampPalette(c("grey90", "grey30")),
#'                          colplot = FALSE,
#'                          ...) {
#'   if (!"tPSI" %in% names(data))
#'     data <- rpcr_calibDetect(data, ...)
#'   if (is.null(cycle))
#'     cycle <- max(data$cycle)
#'
#'   ## only calibration sammples
#'
#'   data <- data[!is.na(data$tPSI), ]
#'
#'   df <- data %>% tidyr::pivot_longer(
#'     cols = c("FA", "FB", "bFA", "bFB"),
#'     names_to = "variable",
#'     values_to = "value"
#'   )
#'
#'   df$sample <- factor(df$tPSI * 100, levels = as.character(unique(df$tPSI)[order(unique(df$tPSI))] * 100))
#'
#'   if (ctype != "fix")
#'     df$cycle <- df$rcycle
#'   prefix <- if (signal == "Rn")
#'     "F"
#'   else
#'     "bF"
#'
#'   newlabel <- c("Inclusion", "Exclusion")
#'   names(newlabel) <- paste0(derivate, prefix, c("A", "B"))
#'   targets <- length(unique(df$target))
#'   samples <- length(unique(df$sample))
#'   color_sample <- color_sample(samples)
#'   color_target <- color_target[1:targets]
#'
#'   plot <- ggplot() +
#'     theme_rpcr() +
#'     theme(
#'       axis.text.y = element_text(size = 10, face = "plain"),
#'       axis.text.x = element_text(
#'         size = 8,
#'         angle = 45,
#'         hjust = 1,
#'         vjust = 1
#'       ),
#'       panel.grid.major = element_blank(),
#'       axis.text = element_text(size = 8),
#'       axis.title = element_text(face = "plain"),
#'       axis.title.y = element_text(vjust = 0),
#'       strip.placement = "outside",
#'       strip.text.y = element_text(vjust = 0, size = 10)
#'     ) +
#'     guides(colour = guide_legend(override.aes = list(size = 5), title = NULL))
#'
#'   if (colplot)
#'     plot <- plot + geom_rect(
#'       data = unique(df[order(df$sample, df$target), c("sample", "target")]),
#'       aes(fill = target),
#'       col = NA,
#'       xmin = -Inf,
#'       xmax = Inf,
#'       ymin = -Inf,
#'       ymax = Inf,
#'       alpha = 0.1
#'     )  +  scale_fill_manual(values = c("grey80", "grey20", color_target))
#'
#'   plot <- plot +
#'     stat_summary(
#'       data = df[df$cycle == cycle &
#'                   df$variable %in% paste0(prefix, c("incl", "excl")), ],
#'       aes(
#'         x = variable,
#'         y = value,
#'         color = variable,
#'         fill = variable
#'       ),
#'       fun = mean,
#'       position = "dodge",
#'       geom = "col",
#'       linewidth = 0.5,
#'       lty = 1,
#'       col = "black",
#'       width = 0.7
#'     ) +
#'     stat_summary(
#'       data = df[df$cycle == cycle &
#'                   df$variable %in% paste0(prefix, c("incl", "excl")), ],
#'       aes(x = variable, y = value),
#'       fun.data = mean_se,
#'       geom = "errorbar",
#'       width = 0.5,
#'       linewidth = 0.5,
#'       col = "black"
#'     ) +
#'     facet_grid2(
#'       target ~ sample,
#'       switch = "y",
#'       strip = strip_themed(
#'         background_y = if (colplot)
#'           elem_list_rect(fill = color_target)
#'         else
#'           elem_list_rect(fill = "grey90"),
#'         background_x = elem_list_rect(fill = color_sample)
#'       )
#'     ) +
#'     labs(
#'       x = "",
#'       y = signal,
#'       subtitle = paste("normalized flourescence at cycle", cycle)
#'     ) +
#'     scale_x_discrete(labels = newlabel)
#'
#'   return(plot)
#' }
