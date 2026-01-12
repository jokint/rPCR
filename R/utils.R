psave <- function(filename, plot, device="pdf",path=fpath,units="cm",dpi=300, ext = NULL,...)
  ggsave(filename=paste0(filename,".",device),plot=plot,device=device, path=path,units=units,dpi=dpi, ...)
