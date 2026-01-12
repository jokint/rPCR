#' theme for ggplot figures
#'
#' @param base_size font size
#' @param base_family font family
#'
#' @return theme for ggplot
#' @export
#' @importFrom ggthemes theme_foundation
#' @import ggplot2
#'
# library(ggplot2)
# library(grid)



theme_rpcr <- function(base_size=10, base_family = "sans") {
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
    ))

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
