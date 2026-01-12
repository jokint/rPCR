#' Title
#'
#' @param para parameter for simulation
#' @param ltype line type
#' @param asize line size
#' @param bsize line size
#' @param csize line size
#' @param ctype line type
#' @param acol color
#' @param ccol color
#' @param balpha alpha
#'
#' @return plot
#' @export
#'
rpcr_plotSim <- function(para = NULL,
                        ltype = "solid",
                        asize = 1.5,
                        bsize = 1.5,
                        csize = 0.5,
                        ctype = "longdash",
                        acol = "black",
                        ccol = "grey30",
                        balpha = 0.2,
                        append = NULL,
                        ratio = 2,
                        single = FALSE,
                        lincols = brewer.pal(n = 8, name = "Dark2"),
                        ...) {

  para <- data.frame(para)
  len <- length(para)

  linetypes <- c(1,2,3,4,5)
  sim_fun <- "rpcr_simpsi"
  fun_para <- c("a", "ri", "g", "re")
  names(linetypes) <- c("all",fun_para)

  para <- data.frame(para)
  len <- length(para)
  para <- as.data.frame(t(para))
  curves <- rbind(linetype = c(rep(0.5, length(para) - 1), 2), para)
  curves <- rbind(col = 2:(length(curves) + 1), curves)



  # leglabel <-  c(TeX(
  #   paste0(
  #     "$\\alpha = ",
  #     para["a"],
  #     " ; \\r_e = ",
  #     para["re"],
  #     " ; \\r_i = ",
  #     para["ri"],
  #     " ; \\gamma= ",
  #     para["g"],
  #     "$"
  #   )
  # ),
  # TeX(paste0("$\\alpha = ", para["a"], "$")),
  # TeX(paste0("$\\r_i = ", para["re"], "$")),
  # TeX(paste0("$\\r_e = ", para["re"], "$")),
  # TeX(paste0("$\\gamma = ", para["ri"], "$")))



  if (is.null(append)){
    p1 <- ggplot()+ geom_function(
      fun = get(sim_fun),
      linetype = ctype,
      linewidth = csize,
      col = ccol) +
      scale_colour_brewer(palette = "Dark2")

    p2 <- ggplot() + geom_function(
      fun = function(x) get(sim_fun)(x) - x,
      linetype = ctype,
      linewidth = csize,
      col = ccol) +
      scale_colour_brewer(palette = "Dark2")
  }
  else {
    p1 <- append[[1]]
    p2 <- append[[2]]
  }



  if (single) {
    for (i in 1:len) {
      for (j in fun_para) {
        p1 <- p1 + geom_function(
          color = lincols[i],
          fun = get(sim_fun),
          args = para[i, j, drop = FALSE],
          alpha = balpha,
          linewidth = bsize,
          linetype = linetypes[j]
        )

        p2 <- p2 + geom_function(
          color = lincols[i],
          fun = function(x, ...) get(sim_fun)(x, ...) - x ,
          args = para[i, j, drop = FALSE],
          alpha = balpha,
          linewidth = bsize,
          linetype = linetypes[j]
        )
      }
    }
  }


  for (i in 1:len) {
    p1 <- p1 + geom_function(
      color = lincols[i],
      fun = get(sim_fun),
      args = para[i, fun_para],
      linewidth = asize,
      alpha = if (is.null(append)) 1 else 0.5
    )
    p2 <- p2 + geom_function(
      color = lincols[i],
      fun = function(x, ...)
        get(sim_fun)(x, ...) - x,
      args = para[i, fun_para,drop=FALSE],
      linewidth = asize,
      alpha = if (is.null(append)) 1 else 0.5
    )





  }

  # scale_colour_manual(
  #   name = "parameters",
  #   breaks = c("all", "a", "re", "ri", "g"),
  #   values = lincols,
  #   labels = leglabel
  # ) +
  # xlab(TeX("$\\psi$")) +
  # ylab(TeX("$\\Delta\\psi\\ [\\psi - \\psi_a$]")) +
  # theme_rpcr()


  merge <-
    ggarrange(
      p1 + theme(plot.margin = unit(c(1, 1, 0, 1), "lines")),
      p2+ theme(plot.title = element_blank(),plot.margin = unit(c(0, 1, 1, 1), "lines")),
      ncol = 1,
      nrow = 2,
      common.legend = TRUE,
      legend = "bottom",
      heights = c(ratio, 1),
      align = "v"
    )

  return(list(p1,p2,merge))
}
