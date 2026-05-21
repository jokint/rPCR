#' theme for ggplot figures
#'
#' @param base_size font size
#' @param base_family font family
#'
#' @return theme for ggplot
#' @export
theme_rpcr <- function(base_size=8,
                       base_family = "",
                       type = "standard"
                       ) {

  t <- theme_bw(base_size = base_size, base_family = base_family)

  t <- t +theme(plot.title = element_text(size = 8,
                                          hjust = 0.5),
            panel.background = element_blank(),
            panel.border = element_blank(),
            plot.background = element_blank(),
            panel.grid.major = element_blank(),
            panel.grid.minor = element_blank(),
            legend.key = element_rect(colour = NA),
            legend.position = "bottom",
            legend.direction = "horizontal",
            legend.key.size= unit(0.3, "cm"),
            legend.spacing = unit(0.1, "cm"),
            legend.title = element_text(face="italic"),
            legend.text=element_text(size=5),
            legend.background = element_blank(),
            legend.box.background = element_blank(),
            strip.background = element_blank(),
            strip.text = element_text(size=5, face="bold"),
            strip.placement = "outside",
            strip.text.y = element_text(vjust = 0,
                                        size = 6),
            plot.margin = margin(0, 0, 0, 0, "cm")
            )

  if (type == "textless") {
    t <- t + theme(
      axis.title = element_blank(),
      axis.text = element_blank(),
      axis.line = element_blank(),
      axis.ticks = element_blank(),
    )
  } else {
    t <- t + theme(
      axis.title = element_text(face = "plain", size = 6),
      axis.title.y = element_text(angle = 90, vjust = 0),
      axis.title.x = element_text(vjust = -0.2),
      axis.text.y = element_text(size = 5, face = "plain"),
      axis.text.x = element_text(size = 5),
      axis.line = element_line(colour = "black"),
      axis.ticks = element_line()
    )
  }

  return(t)

}

simple_theme <- theme(
  panel.background = element_rect(fill='transparent'),
  plot.background = element_rect(fill='transparent', color=NA),
  panel.grid.major = element_blank(),
  panel.grid.minor = element_blank(),
  legend.background = element_rect(fill='transparent'),
  legend.box.background = element_blank(),
  strip.background =element_rect(fill='transparent'),
  strip.text.x = element_blank(),
  strip.text.y = element_blank()
)

theme_textless <- theme(
  axis.text.y = element_blank(),
  axis.text.x = element_blank(),
  axis.title.y = element_blank(),
  axis.title.x = element_blank())

theme_figure <- theme(
  axis.text.y = element_text(size = 5, face = "plain"),
  axis.text.x = element_text(size = 5),
  panel.grid.major = element_blank(),
  axis.text = element_text(size = 5),
  axis.title = element_text(face = "plain"),
  axis.title.y = element_text(vjust = 0),
  strip.placement = "outside",
  strip.text.y = element_text(vjust = 0, size = 8),
  plot.margin = margin(0, 0, 0, 0, "cm"))

basic_plot <- ggplot() + theme_rpcr() + scale_colour_gradientn(colours = rpcr_col_probe) + theme_figure + theme(legend.position = "none")

theme_plot <- function(base_size=6, base_family = "sans") {

  (ggthemes::theme_foundation(base_size=base_size, base_family=base_family)
   + theme(plot.title = element_text(face = "bold",
                                     size = rel(1.2), hjust = 0.5),
           text = element_text(),
           panel.background = element_rect(colour = NA),
           plot.background = element_rect(colour = NA),
           panel.border = element_rect(colour = NA),
           axis.title = element_text(face = "bold",size = rel(1)),
           axis.title.y = element_text(angle=90,vjust =2),
           axis.title.x = element_text(vjust = -0.2),
           axis.text = element_text(size=rel(1.2)),
           axis.line = element_line(colour="black"),
           axis.ticks = element_line(),
           panel.grid.major = element_line(colour="#f0f0f0"),
           panel.grid.minor = element_blank(),
           legend.key = element_rect(colour = NA),
           legend.position = "bottom",
           legend.direction = "horizontal",
           legend.key.size= unit(0.6, "cm"),
           legend.spacing = unit(0.1, "cm"),
           legend.title = element_text(face="italic"),
           legend.text=element_text(size=rel(0.8)),
           plot.margin=unit(c(10,5,5,5),"mm"),
           strip.background=element_rect(colour="#f0f0f0",fill="#f0f0f0"),
           strip.text = element_text(face="bold")
   ) # + scale_fill_rpcr() + scale_colour_rpcr()
  )
}

#' Title
#'
#' @return fill color scale
#' @export
#' @importFrom scales manual_pal
#'
scale_fill_rpcr <- function(...){
  ggplot2::discrete_scale("fill","Publication",scales::manual_pal(values = c("#386cb0","#fdb462","#7fc97f","#ef3b2c","#662506","#a6cee3","#fb9a99","#984ea3","#ffff33")))

}

#' Title
#'
#' @return color sclae
#' @export
#' @importFrom scales manual_pal
#'
scale_colour_rpcr <- function(...){
  ggplot2::discrete_scale("colour","Publication",scales::manual_pal(values = c("#386cb0","#fdb462","#7fc97f","#ef3b2c","#662506","#a6cee3","#fb9a99","#984ea3","#ffff33")))
}
