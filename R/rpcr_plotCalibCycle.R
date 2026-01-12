#' Title
#'
#' @param df data  to be plotted
#' @param title alternative title text
#' @param colplot plotting in color (default = TRUE)
#' @param box plot a boxplot (defaulr = TRUE)
#' @param brew_y colors
#' @param var column to be plotted
#'
#' @return plots
#' @export
#'
rpcr_plotCalibCycle <- function(df,title="",colplot=TRUE,box=TRUE,brew_y = brewer.pal(n = 8, name = "Dark2"),var="cycle") {

  plot <- ggplot(data=df)

  jwidth <- unique(df[,var])
  jwidth <- jwidth[order(jwidth)]
  jwidth <- mean(jwidth[2:(length(jwidth))]- jwidth[1:(length(jwidth)-1)])/5


  if (colplot) {
    plot <- plot + geom_rect(data = data.frame(target= unique(df[order(df$target),"target"]),x=1), aes(fill = target), col = NA, xmin = -Inf, xmax = Inf, ymin = -Inf, ymax = Inf, alpha = 0.1) +
      facet_grid2(rows = vars(target), switch = "y", strip = strip_themed(background_y = elem_list_rect(fill = brew_y))) + scale_fill_brewer(palette = "Dark2")
  }
  else plot <- plot +facet_grid(rows = vars(target))

  if (box) plot <- plot +  geom_boxplot(aes(x=get(var),y=delta,group=get(var)))

  plot <- plot + geom_jitter(aes(x=get(var),y=delta, group=interaction(get(var),tPSI)), # col= if (colplot) as.factor(tPSI) else "black",
                             width=jwidth,
                             alpha=0.2,
                             size=1
  ) +
    labs( y = paste0(expression(delta),"PSI"),
          title = title)


  plot
}
