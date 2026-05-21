#' Plot rpcr Fits and Derivatives
#'
#' This function generates a series of diagnostic plots for qPCR data.
#'
#' @param x A list containing a 'DATA' data frame, a length-2 'RANGE' vector, and a 'MODEL' name.
#' @param offset Numeric. The cycle offset to pass to the derivative calculation. Default = 1.
#' @param design A ggplot2 theme or design object. Default = theme_rpcr().
#' @param iso_color A character vector of length 2 defining colors for different variables.
#' @param aslist Logical. If TRUE, returns a list of individual plots instead of a combined layout. Default = FALSE.
#' @param line Logical. If TRUE, draws a vertical dashed line at the inflection point. Default = FALSE.
#' @param ... Additional arguments passing through to other functions.
#'
#' @return Either a list of 6 ggplot objects or a combined patchwork arrangement.
#' @export
#' @import ggplot2
#' @importFrom grDevices rgb
#' @importFrom tidyr pivot_longer
#' @importFrom dplyr filter
#'
rpcr_fitPlot <- function(x,
                         offset = 1,
                         design = theme_rpcr(),
                         iso_color = c("#00A087FF","#E64B35FF" ),
                         aslist = FALSE,
                         line = FALSE,
                         ...) {

  # Data Preparation & Derivatives ----
  df <- x$DATA

  df$cycle <- 1:nrow(df)
  df$aprop <- df$FA / df$FT

  df$dFA <- rpcr_calDer(df$FA, offset = offset)
  df$dFB <- rpcr_calDer(df$FB, offset = offset)
  df$dFT <- rpcr_calDer(df$FT, offset = offset)
  df$daprop <- df$dFA / df$dFT

  range_seq <- x$RANGE[1]:x$RANGE[2]
  ip <- which.max(df$dFT) # Inflection point

  dfm <- df %>%
    tidyr::pivot_longer(
      cols = c("FA", "FB", "FT", "dFA", "dFB", "dFT"),
      names_to = "variable",
      values_to = "value"
    )

  # Define Plot Axis Limits ----
  width <- max(df$FT) - min(df$FT)
  lim_min <- min(df$FT) - width / 6
  limits_raw <- c(ifelse(lim_min > 0, 0, lim_min), max(df$FT) + width / 6)

  width_d <- max(df$dFT) - min(df$dFT)
  lim_min_d <- min(df$dFT) - width_d / 6
  limits_der <- c(ifelse(lim_min_d > 0, 0, lim_min_d), max(df$dFT) + width_d / 6)

  # Build Individual Plots ----
  plots <- list()
  base_plot <- ggplot2::ggplot() + design

  base_line_plot <- if (line) {
    base_plot + ggplot2::geom_vline(xintercept = ip, colour = "grey30", linetype = "longdash")
  } else {
    base_plot
  }

  # Plot 1: Fluorescence Signal over Time ----
  p1 <- base_line_plot +
    ggplot2::geom_point(data = dplyr::filter(dfm, !startsWith(variable, "d") & cycle %in% range_seq), aes(x = cycle, y = value, group = variable), color = "grey30", alpha = 0.2, size = 1) +
    ggplot2::geom_point(data = dplyr::filter(dfm, !startsWith(variable, "d")), aes(x = cycle, y = value, col = variable),size=0.2) +
    ggplot2::geom_point(data = dplyr::filter(dfm, !startsWith(variable, "d") & cycle == ip), aes(x = cycle, y = value, group = variable), color = 2,size=0.5) +
    ggplot2::scale_colour_manual(values = c(iso_color, "black")) +
    ggplot2::labs(y = "Fluorescence signal")

  # Plot 2: First Derivative over Time ----
  p2 <- base_line_plot +
    ggplot2::geom_point(data = dplyr::filter(dfm, startsWith(variable, "d") & cycle %in% range_seq), aes(x = cycle, y = value, group = variable), color = "grey30", alpha = 0.2, size = 1) +
    ggplot2::geom_point(data = dplyr::filter(dfm, startsWith(variable, "d")), aes(x = cycle, y = value, col = variable),size=0.2) +
    ggplot2::geom_point(data = dplyr::filter(dfm, startsWith(variable, "d") & cycle == ip), aes(x = cycle, y = value, group = variable), color = 2,size=0.5) +
    ggplot2::scale_colour_manual(values = c(iso_color, "black")) +
    ggplot2::labs(y = "Fluorescence signal increase\n(first derivative)")

  # Plot 3: Apparent PSI ----
  p3 <- base_line_plot +
    ggplot2::geom_point(data = dplyr::filter(df, cycle %in% range_seq), aes(x = cycle, y = aprop), color = "grey30", alpha = 0.2, size = 4) +
    ggplot2::geom_point(data = df, aes(x = cycle, y = aprop), col = 1) +
    ggplot2::geom_point(data = dplyr::filter(df, cycle == ip), aes(x = cycle, y = aprop), color = 2) +
    ggplot2::scale_y_continuous(limits = c(0, 1)) +
    ggplot2::labs(y = "Apparent proportion")

  # Plot 4: Apparent PSI (Calculated using Derivative) ----
  p4 <- base_line_plot +
    ggplot2::geom_point(data = dplyr::filter(df, cycle %in% range_seq), aes(x = cycle, y = daprop), color = "grey30", alpha = 0.2, size = 4) +
    ggplot2::geom_point(data = df, aes(x = cycle, y = daprop), col = 1) +
    ggplot2::geom_point(data = dplyr::filter(df, cycle == ip), aes(x = cycle, y = .data$daprop), color = 2) +
    ggplot2::scale_y_continuous(limits = c(0, 1)) +
    ggplot2::labs(y = "Apparent proportion\n(first derivative data)")

  # Plot 5: Inclusion Probe vs Total Signal ----
  p5 <- base_plot +
    ggplot2::geom_path(data = dplyr::filter(df, cycle %in% range_seq), aes(x = FT, y = FA), col = "grey30") +
    ggplot2::stat_smooth(data = dplyr::filter(df, cycle %in% range_seq), aes(x = FT, y = FA), method = "lm", col = "red", formula = y ~ x) +
    ggplot2::geom_point(data = dplyr::filter(df, cycle %in% range_seq), aes(x = FT, y = FA), color = "grey30", alpha = 0.2, size = 4) +
    ggplot2::geom_point(data = df, aes(x = FT, y = FA)) +
    ggplot2::geom_point(data = dplyr::filter(df, cycle == ip), aes(x = FT, y = FA), color = 2) +
    # ggplot2::scale_y_continuous(limits = limits_raw) +
    # ggplot2::scale_x_continuous(limits = limits_raw) +
    ggplot2::labs(y = "Fluorescence signal A", x = "Total fluorescence signal")

  # Plot 6: 1st Derivative of Inclusion Probe vs Total ----
  p6 <- base_plot +
    ggplot2::geom_path(data = dplyr::filter(df, cycle %in% range_seq), aes(x = dFT, y = dFA), col = "grey30") +
    ggplot2::stat_smooth(data = dplyr::filter(df, cycle %in% range_seq), aes(x = dFT, y = dFA), method = "lm", col = "red", formula = y ~ x) +
    ggplot2::geom_point(data = dplyr::filter(df, cycle %in% range_seq), aes(x = dFT, y = dFA), color = "grey30", alpha = 0.2, size = 4) +
    ggplot2::geom_point(data = df, aes(x = dFT, y = dFA)) +
    ggplot2::geom_point(data = dplyr::filter(df, cycle == ip), aes(x = dFT, y = dFA), color = 2) +
    # ggplot2::scale_y_continuous(limits = limits_der) +
    # ggplot2::scale_x_continuous(limits = limits_der) +
    ggplot2::labs(y = "Fluorescence signal A\n(first derivative)", x = "Total fluorescence signal\n(first derivative)")

plots <- list(p1,p2,p3,p4,p5,p6)

  # Final Assembly ----
  if (aslist) {
    return(plots)
  }

  combined_plot <- patchwork::wrap_plots(plots, ncol = 2, nrow = 3) +
    patchwork::plot_annotation(tag_levels = "A")

  return(combined_plot)
}
