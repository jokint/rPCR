#' Title
#'
#' @param df data
#' @param wline line size
#' @param slabel label size
#' @param stitle title font size
#' @param ... passing arguments
#'
#' @return plots
#' @export
#'
rpcr_plotPanel <- function(df,
                           wline = 0.5,
                           slabel = 6,
                           stitle = 8,
                           ...) {
  plist <- names(df)[grep("par_", names(df))]
  plist <- unlist(lapply(plist, function(x) {
    x[length(unique(df[, x])) > 1]
  }))

  plots <- rpcr_plotData(
    df,
    colplot = TRUE,
    color_probe = rpcr_col_probe,
    wline = wline,
    slabel = slabel,
    stitle = stitle,
    ...
  )[3:5]

  cleaner <- theme(strip.background.y = element_blank(),
                   strip.background.x = element_blank())

  plots <- lapply(plots, function(plot)
    plot +  scale_alpha_continuous(range = c(0.2, 1)) + cleaner)
  plots[[1]] <- plots[[1]] +
    theme(
      plot.margin = margin(0.2, 0, 0.3, 0.2, "cm"),
      strip.text = element_text(face = "plain")
    ) +
    scale_y_continuous(
      labels = function(x)
        gsub("\\-0", "-", gsub(
          "\\+0", "", formatC(x, format = "e", digits = 1)
        ))
    ) +
    expand_limits(y = 0, x = 0)

  plots[[2]] <- plots[[2]] +
    theme(
      plot.margin = margin(0.8, 0, 0.3, 0.5, "cm"),
      strip.text.y = element_blank(),
      axis.text.x = element_text(angle = 30, hjust = 1)
    ) +
    expand_limits(y = 0, x = 0) +
    scale_x_continuous(
      labels = function(x)
        gsub("\\-0", "-", gsub(
          "\\+0", "", formatC(x, format = "e", digits = 1)
        ))
    ) +
    scale_y_continuous(
      labels = function(x)
        gsub("\\-0", "-", gsub(
          "\\+0", "", formatC(x, format = "e", digits = 1)
        ))
    )

  plots[[3]] <- plots[[3]] +
    theme(plot.margin = margin(0.8, 0, 0.3, 0.5, "cm"),
          strip.text.y = element_blank()) +
    scale_y_continuous(breaks = seq(0, 1, 0.2), limits = c(-0.1, 1.1))

  grouping <- plist[plist != "par_startRatio"]

  plots[[4]] <- ggplot(df[df$cycle == max(df$cycle), ]) +
    geom_line(
      if (length(grouping) > 0)
        aes(
          x = par_startRatio,
          y = ratio - par_startRatio,
          group = interaction(df[df$cycle == max(df$cycle), grouping])
        )
      else
        aes(x = par_startRatio, y = ratio - par_startRatio)
      ,
      linewidth = wline
    ) +
    theme_rpcr() +
    scale_y_continuous(limits = c(-0.15, 0.15)) +
    labs(x = "theoretical ratio", y = "residuals") +
    theme(
      axis.title.x = element_text(size = stitle),
      axis.title.y = element_text(size = stitle),
      axis.text.x = element_text(
        size = slabel,
        angle = 30,
        hjust = 1
      ),
      axis.text.y = element_text(size = slabel),
      panel.grid.major = element_blank(),
      panel.grid.minor = element_blank()
    )


  return(plots)
}
