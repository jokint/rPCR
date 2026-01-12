#' Reformatting of imported data and additional calculations
#'
#' @param df data frame with the PCR data
#' @param full TRUE For additional calculations
#' @param convert ???
#'
#' @return data frame with results ?
#' @export
#' @importFrom tidyr pivot_wider
#' @importFrom stats na.omit
#' @importFrom magrittr %>%
#'
#'
# @import tidyverse
rpcr_wrap <- function(df, full = FALSE, convert = NULL) {


  ##   IDENTIFIER  ##


  id_A <- c("incl","toi","targetA","Allele 1")
  id_B <- c("excl","targetB","ref","Allele 2")
  id_T <- c("total","pan")

  id_FA <- "FA"
  id_FB <- "FB"
  id_FT <- "FT"
  id_bFA <- "bFA"
  id_bFB <- "bFB"
  id_bFT <- "bFT"






  ## convert Calibration export file in annotated data.frame
  df$cycle <-  as.integer(df$cycle)
  df$rn <-  as.numeric(df$rn)
  df$drn <-  as.numeric(df$drn)
  df$type <- NA
  dfcols1 <- NULL
  dfcols2 <- NULL
  if (any(grepl(paste(id_A,collapse="|"), df$target))) {
    df[grepl(paste(id_A,collapse="|"), df$target),]$type <- "A"
    dfcols1 <- c(dfcols1,id_FA)
    dfcols2 <- c(dfcols2,id_bFA)
  }
  if (any(grepl(paste(id_B,collapse="|"), df$target))) {
    df[grepl(paste(id_B,collapse="|"), df$target),]$type <- "B"
    dfcols1 <- c(dfcols1,id_FB)
    dfcols2 <- c(dfcols2,id_bFB)
    }
  if (any(grepl(paste(id_T,collapse="|"), df$target))) {
    df[grepl(paste(id_T,collapse="|"), df$target),]$type <- "T"
    dfcols1 <- c(dfcols1,id_FT)
    dfcols2 <- c(dfcols2,id_bFT)
    }

  df[,"target"] <- sapply(strsplit(df[,"target"],"_|-| "),"[[",1)  ### space is also a sperator can cause problems: maybe change

  df <- stats::na.omit(df[order(df$type),])
  dfcols1 <- dfcols1[order(dfcols1)]
  dfcols2 <- dfcols2[order(dfcols2)]

  df <- df %>% tidyr::pivot_wider(values_from = c(rn,drn), names_from = type) %>% as.data.frame()
  # df <- cbind(dcast(df,well+cycle+target+sample~type,value.var="rn"),
  #              dcast(df,well+cycle+target+sample~type,value.var="drn")[,5:(ncol(df)-1)])


    names(df) <- c("well","cycle","target","sample",dfcols1,dfcols2)


  for  (x in c(id_FA,id_bFA,id_FB,id_bFB,id_FT,id_bFT))
    if (!(x %in% names(df))) df[x] <- NA

  sel <- !is.na(df[,id_FA])&!is.na(df[,id_FB])&is.na(df[,id_FT])
  df[sel,id_FT] <- df[sel, id_FA] + df[sel, id_FB]
  sel <- !is.na(df[,id_FT])&!is.na(df[,id_FB])&is.na(df[,id_FA])
  df[sel,id_FA] <- df[sel, id_FT] - df[sel, id_FB]
  sel <- !is.na(df[,id_FT])&!is.na(df[,id_FA])&is.na(df[,id_FB])
  df[sel,id_FB] <- df[sel, id_FT] - df[sel, id_FA]
  sel <- !is.na(df[,id_bFA])&!is.na(df[,id_bFB])&is.na(df[,id_bFT])
  df[sel,id_bFT] <- df[sel, id_bFA] + df[sel, id_bFB]
  sel <- !is.na(df[,id_bFT])&!is.na(df[,id_bFB])&is.na(df[,id_bFA])
  df[sel,id_bFA] <- df[sel, id_bFT] - df[sel, id_bFB]
  sel <- !is.na(df[,id_bFT])&!is.na(df[,id_bFA])&is.na(df[,id_bFB])
  df[sel,id_bFB] <- df[sel, id_bFT] - df[sel, id_bFA]

  if(full) {
    id_sf_incl <- "sFA"
    id_sf_excl <- "sFB"
    id_sf_total <- "sFT"
    id_d1f_incl <- "d1FA"
    id_d1f_excl <- "d1FB"
    id_d1f_total <- "d1FT"
    id_d1bf_incl <- "d1bFA"
    id_d1bf_excl <- "d1bFB"
    id_d1bf_total <- "d1bFT"
    id_d1sf_incl <- "d1sFA"
    id_d1sf_excl <- "d1sFB"
    id_d1sf_total <- "d1sFT"
    id_d2f_incl <- "d2Fincl"
    id_d2f_excl <- "d2Fexcl"
    id_d2f_total <- "d2Ftotal"
    id_d2bf_incl <- "d2bFincl"
    id_d2bf_excl <- "d2bFexcl"
    id_d2bf_total <- "d2bFtotal"
    id_d2sf_incl <- "d2sFincl"
    id_d2sf_excl <- "d2sFexcl"
    id_d2sf_total <- "d2sFtotal"

    id_eff_excl <- "eff_incl"
    id_eff_incl <- "eff_excl"
    id_d0_r <- "d0_r"
    id_d1_r <- "d1_r"

    df[, id_d1f_incl] <- rpcr_batch("rpcr_calDer", df, id_col = id_FA)
    df[, id_d2f_incl] <- rpcr_batch("rpcr_calDer", df, id_d1f_incl, offset = TRUE)
    df[, id_d1bf_incl] <- rpcr_batch("rpcr_calDer", df, id_col = id_bFA)
    df[, id_d2bf_incl] <- rpcr_batch("rpcr_calDer", df, id_d1bf_incl, offset = TRUE)
    df[, id_d1f_total] <- rpcr_batch("rpcr_calDer", df, id_FT)
    df[, id_d2f_total] <- rpcr_batch("rpcr_calDer", df, id_d1f_total, offset = TRUE)
    df[, id_d1bf_total] <- rpcr_batch("rpcr_calDer", df, id_bFT)
    df[, id_d2bf_total] <- rpcr_batch("rpcr_calDer", df, id_d1bf_total, offset = TRUE)
    df[, id_d1f_excl] <- rpcr_batch("rpcr_calDer", df, id_FB)
    df[, id_d2f_excl] <- rpcr_batch("rpcr_calDer", df, id_d1f_excl, offset = TRUE)
    df[, id_d1bf_excl] <- rpcr_batch("rpcr_calDer", df, id_bFB)
    df[, id_d2bf_excl] <- rpcr_batch("rpcr_calDer", df, id_d1bf_excl, offset = TRUE)
    df[, id_sf_incl] <- rpcr_batch("rpcr_filter", df, id_bFA)
    df[, id_sf_excl] <- rpcr_batch("rpcr_filter", df, id_bFB)
    df[, id_sf_total] <- rpcr_batch("rpcr_filter", df, id_bFT)
    df[, id_d1sf_incl] <- rpcr_batch("rpcr_calDer", df, id_sf_incl)
    df[, id_d1sf_excl] <- rpcr_batch("rpcr_calDer", df, id_sf_excl)
    df[, id_d1sf_total] <- rpcr_batch("rpcr_calDer", df, id_sf_total)
    df[, id_d2sf_incl] <- rpcr_batch("rpcr_calDer", df, id_d1sf_incl)
    df[, id_d2sf_excl] <- rpcr_batch("rpcr_calDer", df, id_d1sf_excl)
    df[, id_d2sf_total] <- rpcr_batch("rpcr_calDer", df, id_d1sf_total)
    df[, "eff_incl"] <- rpcr_batch("rpcr_calEff", df, id_bFA)
    df[, "eff_excl"] <- rpcr_batch("rpcr_calEff", df, id_bFB)
    df[, id_d0_r] <- df[,id_bFA]/df[,id_bFB]
    df[, id_d1_r] <- df[,id_d1f_incl]/df[,id_d1f_excl]
  }

  df$ratio <- df[, id_FA] /df[, id_FB]
  df$bratio <- df[, id_bFA] /df[, id_bFB]
  df$prop <- df[, id_FA] /df[, id_FT]
  df$bprop <- df[, id_bFA] /df[, id_bFT]


  df[, "rcycle"] <- rpcr_batch("rpcr_relCycle", df, id_col = c(id_FT,"cycle"))


  ### generate new fields in case sample name has field signature
  for (x in 1:nrow(df)) {
    temp <- unlist(strsplit(df[x,"sample"],"_"))
    temp <- lapply(temp,function(x) {
      temp <- unlist(strsplit(x,c("=")))
      unlist(strsplit(temp,c(":")))
    })
    for (y in temp) if (length(y) > 1)  {
      if (!y[[1]] %in% colnames(df)) df[,y[[1]]] <- NA
      df[x,y[[1]]] <- y[[2]]
    }
  }
  custom <- match("rcycle",names(df))+1
  if (custom<=length(names(df))) {
    for (cc in custom:length(names(df)))
      if (!any(is.na(as.character(df[!is.na(df[,cc]),cc])))) {
         df[,cc] <- as.numeric(df[,cc])
      }
  }



  return(df)
}
