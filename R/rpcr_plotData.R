#' Plot Detailed PCR Amplification Data
#'
#' @description
#' Generates a series of diagnostic plots (grids, phase plots, and ratios)
#' for PCR amplification data. Returns a list of ggplot objects.
#'
#' @param df0 A data frame with the PCR data.
#' @param signal Character string, either `"Rn"` or `"deltaRn"`.
#' @param derivate Character string for derivative prefix (e.g., `"d1"`).
#' @param title Alternative title text for the plots.
#' @param color_target Vector of colors for the targets.
#' @param color_sample A color mapping function for samples.
#' @param color_probe Vector of colors for probes.
#' @param colplot Logical. If `TRUE`, adds background colors based on target.
#' @param label Logical. Currently unused.
#' @param wline Numeric. Line width for plot lines.
#' @param slabel Numeric. Axis text size.
#' @param stitle Numeric. Axis title size.
#' @param text Logical. Currently unused.
#' @param alpha Character. Column name to map to alpha (transparency).
#' @param targetA Character. Custom label for Target A.
#' @param targetB Character. Custom label for Target B.
#' @param ... Further arguments passed to methods.
#'
#' @return A named list of 5 ggplot objects.
#' @export
rpcr_plotData <- function(df0,
                          signal = "Rn",
                          derivate = "",
                          title = "normalized fluorescence\n",
                          color_target = RColorBrewer::brewer.pal(n = 8, name = "Dark2"),
                          color_sample = grDevices::colorRampPalette(c("grey90", "grey30")),
                          color_probe = c(
                            rgb(199, 235, 211, maxColorValue = 255),
                            rgb(255, 255, 190, maxColorValue = 255),
                            rgb(255, 190, 190, maxColorValue = 255)
                          ),
                          colplot = FALSE,
                          label = TRUE,
                          wline = 0.5,
                          slabel = 6,
                          stitle = 8,
                          text = TRUE,
                          alpha = NULL,
                          targetA = "target A",
                          targetB = "target B",
                          ...) {

  # Setup & Helper Variables ----

  max_cycle <- max(df0$cycle)
  targets <- unique(df0$target)
  n_samples <- length(unique(df0$sample))

  # Assign color vectors based on counts
  color_sample <- color_sample(n_samples)
  color_target <- color_target[seq_along(targets)]

  # Determine data columns based on signal type
  prefix <- if (signal == "Rn") "F" else "bF"
  fluo_cols <- paste0(derivate, prefix, c("A", "B"))

  # Prevent "NAs introduced by coercion" by converting to factor instead of numeric [1]
  df0$sample <- as.character(df0$sample) |>
    gsub(pattern = "%", replacement = "") |>
    as.numeric()

  if (signal != "Rn") signal <- "\u0394Rn"

  # Pivot data for faceting (Long Format)
  df_long <- df0 |>
    tidyr::pivot_longer(cols = tidyr::all_of(fluo_cols),
                        values_to = "value",
                        names_to = "variable")

  # Base ggplot Theme ----

  base_plot <- ggplot2::ggplot() +
    ggplot2::theme_minimal() + # Use a clean default theme instead of theme_rpcr
    ggplot2::theme(
      axis.text.y = ggplot2::element_text(size = 6, face = "plain"),
      axis.text.x = ggplot2::element_text(size = 6),
      panel.grid.major = ggplot2::element_blank(),
      panel.grid.minor = ggplot2::element_blank(),
      axis.title = ggplot2::element_text(face = "plain"),
      axis.title.y = ggplot2::element_text(vjust = 0),
      strip.placement = "outside",
      strip.text.y = ggplot2::element_text(vjust = 0, size = 8)
    )

  # Plot 1: Facet Grid with Raw Points ----

  p1 <- base_plot +
    ggplot2::geom_point(
      data = df_long[df_long$variable %in% fluo_cols, ],
      ggplot2::aes(x = cycle, y = value, col = variable),
      shape = 20,
      size = 0.5
    ) +
    ggplot2::scale_color_manual(
      values = c("grey30", "grey60"),
      labels = c(targetA, targetB)
    ) +
    ggplot2::scale_x_continuous(breaks = c(1, max_cycle)) +
    ggplot2::scale_y_continuous(labels = scales::number_format(accuracy = 1)) +
    ggplot2::labs(x = "Cycle", y = signal, title = title)

  # Add background colors and strip styling via ggh4x
  if (colplot) {
    p1 <- p1 +
      ggplot2::geom_rect(
        data = unique(df_long[, c("sample", "target")]),
        ggplot2::aes(fill = target),
        col = NA, xmin = -Inf, xmax = Inf, ymin = -Inf, ymax = Inf, alpha = 0.1
      ) +
      ggplot2::scale_fill_manual(values = color_target, guide = "none") +
      ggh4x::facet_grid2(
        target ~ sample, switch = "y", axes = "x",
        strip = ggh4x::strip_themed(
          background_x = ggh4x::elem_list_rect(fill = color_sample),
          background_y = ggh4x::elem_list_rect(fill = color_target)
        )
      )
  } else {
    p1 <- p1 + ggh4x::facet_grid2(
      target ~ sample, switch = "y", axes = "x",
      strip = ggh4x::strip_themed(background_x = ggh4x::elem_list_rect(fill = color_sample))
    )
  }

  # Plot 2: Normalized Scatter Plot (Target A vs. Target B) ----

  # Perform normalization without for-loops for better performance
  df_norm <- df0
  for (target_name in targets) {
    idx <- df_norm$target == target_name
    df_norm[idx, fluo_cols[1]] <- df_norm[idx, fluo_cols[1]] / max(df_norm[idx, fluo_cols[1]], na.rm = TRUE)
    df_norm[idx, fluo_cols[2]] <- df_norm[idx, fluo_cols[2]] / max(df_norm[idx, fluo_cols[2]], na.rm = TRUE)
  }

  # Replaced get() with safe .data[[...]] syntax [2]
  p2 <- base_plot +
    ggplot2::geom_point(
      data = df_norm,
      ggplot2::aes(x = .data[[fluo_cols[2]]], y = .data[[fluo_cols[1]]]),
      shape = 20,
      size = 0.5
    ) +
    ggplot2::scale_x_continuous(breaks = c(0, 0.5, 1)) +
    ggplot2::labs(x = targetB, y = targetA, title = title)

  if (colplot) {
    p2 <- p2 +
      ggplot2::geom_rect(
        data = unique(df_norm[, c("sample", "target")]),
        ggplot2::aes(fill = target),
        col = NA, xmin = -Inf, xmax = Inf, ymin = -Inf, ymax = Inf, alpha = 0.1
      ) +
      ggplot2::scale_fill_manual(values = color_target, guide = "none") +
      ggh4x::facet_grid2(
        target ~ sample, switch = "y", axes = "x",
        strip = ggh4x::strip_themed(
          background_x = ggh4x::elem_list_rect(fill = color_sample),
          background_y = ggh4x::elem_list_rect(fill = color_target)
        )
      )
  } else {
    p2 <- p2 + ggh4x::facet_grid2(
      target ~ sample, switch = "y", axes = "x",
      strip = ggh4x::strip_themed(background_x = ggh4x::elem_list_rect(fill = color_sample))
    )
  }

  # Plot 4: Phase Plane Line Plot ----

  aes_p4 <- if (is.null(alpha)) {
    ggplot2::aes(x = .data[[fluo_cols[2]]], y = .data[[fluo_cols[1]]], col = sample, group = well)
  } else {
    ggplot2::aes(x = Fexcl, y = Fincl, col = sample, group = well, alpha = .data[[alpha]])
  }

  p4 <- base_plot +
    ggplot2::geom_line(data = df0, mapping = aes_p4, linewidth = wline) +
    ggh4x::facet_grid2(target ~ ., switch = "y", scales = "free", independent = "all") +
    ggplot2::labs(x = paste0(targetB, " (", signal, ")"), y = paste0(targetA, " (", signal, ")")) +
    ggplot2::theme(
      axis.title.x = ggplot2::element_text(size = stitle),
      axis.title.y = ggplot2::element_text(size = stitle),
      axis.text.x = ggplot2::element_text(size = slabel),
      axis.text.y = ggplot2::element_text(size = slabel)
    )

  # Plot 5: Cycle vs. Ratio Plot ----

  aes_p5 <- if (is.null(alpha)) {
    ggplot2::aes(x = cycle, y = .data[[fluo_cols[1]]] / (.data[[fluo_cols[1]]] + .data[[fluo_cols[2]]]), col = sample, group = well)
  } else {
    ggplot2::aes(x = cycle, y = .data[[fluo_cols[1]]] / (.data[[fluo_cols[1]]] + .data[[fluo_cols[2]]]), col = sample, group = well, alpha = .data[[alpha]])
  }

  p5 <- base_plot +
    ggplot2::geom_line(data = df0, mapping = aes_p5, linewidth = wline) +
    ggh4x::facet_grid2(target ~ ., switch = "y", scales = "free", independent = "all") +
    ggplot2::labs(x = "cycle", y = "ratio") +
    ggplot2::theme(
      axis.title.x = ggplot2::element_text(size = stitle),
      axis.title.y = ggplot2::element_text(size = stitle),
      axis.text.x = ggplot2::element_text(size = slabel),
      axis.text.y = ggplot2::element_text(size = slabel)
    )

  # Apply continuous color gradients to plots 4 & 5
  if (colplot) {
    p4 <- p4 + ggplot2::scale_colour_gradientn(colours = color_probe)
    p5 <- p5 + ggplot2::scale_colour_gradientn(colours = color_probe)
  } else {
    p4 <- p4 + ggplot2::scale_colour_gradientn(colours = color_sample)
    p5 <- p5 + ggplot2::scale_colour_gradientn(colours = color_sample)
  }

  # Plot 3: Cycle vs. Signal Line Plot ----

  aes_p3 <- if (is.null(alpha)) {
    ggplot2::aes(x = cycle, y = value, col = sample, group = well)
  } else {
    ggplot2::aes(x = cycle, y = value, col = sample, group = well, alpha = .data[[alpha]])
  }

  p3 <- base_plot +
    ggplot2::geom_line(data = df_long, mapping = aes_p3, linewidth = wline) +
    ggh4x::facet_grid2(
      target ~ variable, switch = "y", scales = "free", independent = "all",
      labeller = ggplot2::labeller(
        variable = c(
          Fincl  = paste(targetA, "(Rn)"),
          Fexcl  = paste(targetB, "(Rn)"),
          bFincl = paste0(targetA, " (", signal, ")"),
          bFexcl = paste0(targetB, " (", signal, ")")
        )
      )
    ) +
    ggplot2::labs(x = "cycle", y = signal)

  p3 <- p3 + if (colplot) {
    ggplot2::scale_colour_gradientn(colours = color_probe)
  } else {
    ggplot2::scale_colour_gradientn(colours = color_sample)
  }

  # Return final list of plots ----
  return(list(
    grid_points = p1,
    scatter     = p2,
    grid_lines  = p3,
    phase_plot  = p4,
    ratio_plot  = p5
  ))
}
