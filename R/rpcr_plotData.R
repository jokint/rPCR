#' Title
#'
#' @param df0 data
#' @param signal type of signal
#' @param title alternative title text
#' @param color_target color of targets
#' @param color_sample color of samples
#' @param colplot TRUE for color plotting
#' @param ... passing arguments
#'
#' @return plots
#' @importFrom tidyr pivot_longer
#' @importFrom grDevices colorRampPalette
#' @importFrom RColorBrewer brewer.pal
#' @importFrom scales number_format
#' @import dplyr
#' @import ggplot2
#' @export
#'
rpcr_plotData <- function(df0,
                          signal = "Rn",
                          derivate = "",
                          title = "normalized flourescence\n ",
                          color_target = RColorBrewer::brewer.pal(n = 8, name = "Dark2"),
                          color_sample = grDevices::colorRampPalette(c("grey90", "grey30")),
                          color_probe =  c(
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
  Cmax <- max(df0$cycle)

  targets <- unique(df0$target)
  samples <- length(unique(df0$sample))
  color_sample <- color_sample(samples)
  color_target <- color_target[seq_along(targets)]

  prefix <- if (signal == "Rn")
    "F"
  else
    "bF"

  fluo <- paste0(derivate, prefix, c("A", "B"))

  df0$sample <- as.numeric(df0$sample)

  if (signal != "Rn")
    signal <- "\u0394Rn"

  df <- df0 %>% pivot_longer(cols = fluo,
                             values_to = "value",
                             names_to = "variable")

  plot <- ggplot() +
    theme_rpcr() +
    theme(
      axis.text.y = element_text(size = 6, face = "plain"),
      axis.text.x = element_text(size = 6),
      panel.grid.major = element_blank(),
      panel.grid.minor = element_blank(),
      axis.title = element_text(face = "plain"),
      axis.title.y = element_text(vjust = 0),
      strip.placement = "outside",
      strip.text.y = element_text(vjust = 0, size = 8)
    ) +
    scale_fill_manual(values = color_target, guide = "none")

  p1 <- plot +
    geom_point(
      data = df[df$variable %in% fluo, ],
      aes(x = cycle, y = value, col = variable),
      shape = 20,
      size = 0.5
    ) +
    scale_color_manual(
      values = c("grey30", "grey60") ,
      labels = c(targetA, targetB)
    ) +
    scale_x_continuous(breaks = c(1, Cmax)) +
    scale_y_continuous(labels = scales::number_format(accuracy = 1)) +
    labs(
      x = "Cycle",
      y = signal,
      title = title,
    )

  if (colplot) {
    p1 <- p1 + geom_rect(
      data = unique(df[, c("sample", "target")]),
      aes(fill = target),
      col = NA,
      xmin = -Inf,
      xmax = Inf,
      ymin = -Inf,
      ymax = Inf,
      alpha = 0.1
    ) +
      ggh4x::facet_grid2(
        target ~ sample,
        switch = "y",
        axes = "x",
        strip = ggh4x::strip_themed(
          background_x = ggh4x::elem_list_rect(fill = color_sample),
          background_y = ggh4x::elem_list_rect(fill = color_target)
        )
      )
  } else {
    p1 <- p1 + ggh4x::facet_grid2(
      target ~ sample,
      switch = "y",
      axes = "x",
      strip = ggh4x::strip_themed(background_x = ggh4x::elem_list_rect(fill = color_sample))
    )
  }

  df1 <- df0
  for (i in targets) {
    df1[df1$target == i, fluo[1]] <- df0[df0$target == i, fluo[1]] / max(df0[df0$target == i, fluo[1]])
    df1[df1$target == i, fluo[2]] <- df0[df0$target == i, fluo[2]] / max(df0[df0$target == i, fluo[2]])
  }

  p2 <- plot + geom_point(
    data = df1,
    aes(x = get(fluo[[2]]), y = get(fluo[[1]])),
    shape = 20,
    size = 0.5
  ) +
    scale_x_continuous(breaks = c(0, 0.5, 1)) +
    labs(
      x = targetB,
      y = targetA,
      title = title
    )

  p4 <- plot +
    geom_line(
      data = df0,
      if (is.null(alpha))
        aes(
          x = get(fluo[[2]]),
          y = get(fluo[[1]]),
          col = sample,
          group = well
        )
      else
        aes(
          x = Fexcl,
          y = Fincl,
          col = sample,
          group = well,
          alpha = get(alpha)
        )
      ,
      linewidth = wline
    )  +
    ggh4x::facet_grid2(
      target ~ .,
      switch = "y",
      scales = "free",
      independent = "all"
    ) +
    # strip = ggh4x::strip_themed(background_y = ggh4x::elem_list_rect(fill = "grey90")))
    labs(
      x = paste0(targetB," (", signal, ")"),
      y = paste0(targetA," (", signal, ")")
    ) +
    theme(
      axis.title.x = element_text(size = stitle),
      axis.title.y = element_text(size = stitle),
      axis.text.x = element_text(size = slabel),
      axis.text.y = element_text(size = slabel)
    )

  p5 <- plot +
    geom_line(
      data = df0,
      if (is.null(alpha))
        aes(
          x = cycle,
          y = get(fluo[[1]]) / (get(fluo[[1]]) + get(fluo[[2]])),
          col = sample,
          group = well
        )
      else
        aes(
          x = cycle,
          y = get(fluo[[1]]) / (get(fluo[[1]]) + get(fluo[[2]])),
          col = sample,
          group = well,
          alpha = get(alpha)
        )
      ,
      linewidth = wline
    )  +
    ggh4x::facet_grid2(
      target ~ .,
      switch = "y",
      scales = "free",
      independent = "all"
    ) +
    # strip = ggh4x::strip_themed(background_y = ggh4x::elem_list_rect(fill = "grey90"))) +
    labs(x = "cycle", y = "ratio") +
    theme(
      axis.title.x = element_text(size = stitle),
      axis.title.y = element_text(size = stitle),
      axis.text.x = element_text(size = slabel),
      axis.text.y = element_text(size = slabel)
    )







  if (colplot) {
    p2 <- p2 +
      geom_rect(
        data = unique(df1[, c("sample", "target")]),
        aes(fill = target),
        col = NA,
        xmin = -Inf,
        xmax = Inf,
        ymin = -Inf,
        ymax = Inf,
        alpha = 0.1
      ) +
      ggh4x::facet_grid2(
        target ~ sample,
        switch = "y",
        axes = "x",
        strip = ggh4x::strip_themed(
          background_x = ggh4x::elem_list_rect(fill = color_sample),
          background_y = elem_list_rect(fill = color_target)
        )
      )

    p4 <- p4 + scale_colour_gradientn(colours = color_probe)
    p5 <- p5 + scale_colour_gradientn(colours = color_probe)
  }  else  {
    p2 <- p2 + ggh4x::facet_grid2(
      target ~ sample,
      switch = "y",
      axes = "x",
      strip = ggh4x::strip_themed(background_x = ggh4x::elem_list_rect(fill = color_sample))
    )
    p4 <- p4 + scale_colour_gradientn(colours = color_sample)
    p5 <- p4 + scale_colour_gradientn(colours = color_sample)
  }

  p3 <- plot +
    geom_line(
      data = df,
      if (is.null(alpha))
        aes(
          x = cycle,
          y = value,
          col = sample,
          group = well
        )
      else
        aes(
          x = cycle,
          y = value,
          col = sample,
          group = well,
          alpha = get(alpha)
        )
      ,
      linewidth = wline
    )  +
    ggh4x::facet_grid2(
      target ~ variable,
      switch = "y",
      # strip=ggh4x::strip_themed(background_y = ggh4x::elem_list_rect(fill = "grey90"),background_x = element_blank()),
      scales = "free",
      independent = "all",
      labeller = labeller(
        variable = c(
          Fincl = paste(targetA, "(Rn)"),
          Fexcl = paste(targetB, "(Rn)"),
          bFincl = paste0(targetA, " (", signal, ")"),
          bFexcl = paste0(targetB, " (", signal, ")")
        )
      )
    ) +
    labs(x = "cycle", y = signal)

  p3 <- p3 + if (colplot)
    scale_colour_gradientn(colours = color_probe)
  else
    scale_colour_gradientn(colours = color_sample)



  return(list(p1, p2, p3, p4, p5))
}
