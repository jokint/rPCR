#' Title
#'
#' @param df data to normalize
#' @param type ???
#' @param mode ???
#'
#' @return normalized data frame ?
#' @export
#' @importFrom stats coef
#'
rpcr_norm <- function(df,type=c("T","A"),mode=2) {
  if (!("cycle" %in% names(df))) df$cycle <- 1:nrow(df)
  df <- df %>% relocate(cycle)
  pos <- match("T",type)
  if (is.na(pos)) df$Total <- df[,2] + df[,3] else df$Total <- df[,1+pos]
    temp <- rpcr_calCip(df$Total,detail=TRUE)
  df[,2] <- df[,2] - df[temp$a,2]
  df[,3] <- df[,3] - df[temp$a,3]
  if (is.na(pos)) df$Total <- df[,2] + df[,3] else df$Total <- df[,1+pos]

  sel <- if (mode==1) 1:nrow(df) else temp$c:temp$f
  nfit <- coef(rpcr_normfit(df[temp$a:temp$b,c("cycle","Total")],detail=TRUE))

  Ci <- nfit["Ci"]
  multi <- df$Total[as.integer(Ci)]+ (df$Total[as.integer(Ci)+1]-df$Total[as.integer(Ci)])* (Ci - as.integer(Ci))

  df[,2] <- (df[,2]-nfit["b"])/(multi-nfit["b"])
  df[,3] <- df[,3]/multi

  return(df[,1:3])
}




#' Title
#'
#' @param df data to fit
#' @param detail TRUE for more detailed results
#'
#' @return coefficients or detailed fit
#' @importFrom stats nls nls.control
#' @export
#'
rpcr_normfit <- function(df,detail=FALSE) {

  colnames(df) <- c("cycle","Fluo")
  cont <- stats::nls.control(maxiter = 10000, minFactor = 2^-30, warnOnly = T)

  Mid <- which.max(diff(df$Fluo))
  m <- max(df$Fluo)-min(df$Fluo)
  fit <-nls(Fluo ~ Fx - Fx/((1 + D * E^(cycle - Ci))^(1/D)) + a*cycle+b,
                          data= df,
                          start = list(Fx = m, D = 2, Ci = Mid, a = 0, b = 0, E=2),
                          lower = c(m/3, 0.01,  5, -m * 0.05, -m * 0.5,0),
                          upper = c(m*3, 10, 50, m * 0.05, m * 0.5,2),
                          control = cont, algorithm = "port")

  out <- if (detail) fit else coef(fit)[c(1,5)]
  return(out)
}
