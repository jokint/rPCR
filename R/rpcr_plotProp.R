#' rpcr_plotProp
#'
#' @param para parameter
#' @param data data to be ploted
#' @param ltype line type
#' @param asize line size
#' @param bsize line size
#' @param csize line size
#' @param ctype line type
#' @param acol color
#' @param ccol color
#' @param balpha alpha level
#' @param single ???
#' @param sub ===
#'
#' @return plots
#' @export
#'
rpcr_plotProp <- function(para=c(a=3,ri=0.1,re=0.2,g=2),data = NULL,ltype = "solid",asize=1.5,bsize=1.5,csize=0.5,ctype="longdash",acol="black",ccol="grey30",balpha= 0.2,single=TRUE,sub = FALSE) {

  lincols <- acol
  if (single) lincols <- c(acol,2,3,4,5)


  leglabel <-  c(
    TeX(paste0("$\\alpha = ",para["a"]," ; \\r_e = ",para["re"]," ; \\r_i = ",para["ri"]," ; \\gamma= ",para["g"],"$")),
    TeX(paste0("$\\alpha = ",para["a"],"$")),
    TeX(paste0("$\\r_i = ",para["ri"],"$")),
    TeX(paste0("$\\r_e = ",para["re"],"$")),
    TeX(paste0("$\\gamma = ",para["g"],"$"))
  )

  sim_fun <- "rpcr_simprop"

  p1 <- ggplot() + geom_function(fun= match.fun(sim_fun), linetype = ctype,linewidth=csize, col = ccol)

  if (single) {
    p1 <- p1 +
    geom_function(aes(color= "a"),fun = match.fun(sim_fun), args = para["a"], alpha=balpha, linewidth = bsize, linetype = ltype) +
    geom_function(aes(color= "ri"),fun = match.fun(sim_fun), args = para["ri"], alpha=balpha, linewidth = bsize, linetype = ltype) +
    geom_function(aes(color= "re"),fun = match.fun(sim_fun), args = para["re"], alpha=balpha, linewidth = bsize, linetype = ltype) +
    geom_function(aes(color= "g"),fun = match.fun(sim_fun), args = para["g"], alpha=balpha, linewidth = bsize, linetype = ltype)
  }

  p1 <- p1 +    geom_function(aes(color= "all"),fun = match.fun(sim_fun), args = para, linewidth = asize) +
    scale_colour_manual(name= "parameters", breaks= c("all", "a", "re","ri","g"), values = lincols, labels = leglabel) +
    ggtitle(leglabel[[1]]) +
    xlab(TeX("$\\tprop$")) +
    ylab(TeX("$\\aprop$")) +
    theme_rpcr() +
    xlim(0, 1) + ylim(0, 1) +
    guides(colour = guide_legend(override.aes = list(color=lincols))) # + theme(legend.position="right")


  p2 <- ggplot() +  geom_function(fun= function(x) {match.fun(sim_fun)(x) -x}, linetype = ctype,linewidth=csize, col = ccol)

  if (single) {
    p2 <- p2 +
    geom_function(aes(color= "a"),fun = function(x,a) {match.fun(sim_fun)(x,a=a) -x}, args = para[["a"]], alpha=balpha, linewidth = bsize, linetype = ltype) +
    geom_function(aes(color= "ri"),fun = function(x,ri) {match.fun(sim_fun)(x,ri=ri) -x}, args = para[["ri"]], alpha=balpha, linewidth = bsize,linetype = ltype) +
    geom_function(aes(color= "re"),fun = function(x,re) {match.fun(sim_fun)(x,re=re) -x}, args = para[["re"]], alpha=balpha, linewidth = bsize, linetype = ltype) +
    geom_function(aes(color= "g"),fun = function(x,g) {match.fun(sim_fun)(x,g=g) -x}, args = para[["g"]], alpha=balpha, linewidth = bsize,linetype = ltype)
  }

  p2 <- p2 +  geom_function(aes(color= "all"),fun = function(x,a,re,ri,g) {match.fun(sim_fun)(x,a=a,re=re,ri=ri,g=g) -x}, args = para, linewidth = asize) +
    scale_colour_manual(name= "parameters", breaks= c("all", "a", "re","ri","g"), values = lincols, labels = leglabel) +
    xlab(TeX("$\\tprop$")) +
    ylab(TeX("$\\Delta\\tprop\\ [\\tprop - \\aprop$]")) +
    theme_rpcr()

  merge_plots <- list(p1 + theme(plot.margin = unit(c(1,1,0,1), 'lines')),p2 + theme(plot.title = element_blank(),plot.margin = unit(c(0,1,1,1), 'lines')))
  p3 <- ggarrange(plotlist=merge_plots, ncol=1,nrow=2, common.legend =TRUE,legend="bottom",heights= c(ratio,1),align="v")
  if (sub) list(p1,p2 + ggtitle(leglabel[[1]]),p3) else p3
}
