#' Reading ThermoFisher Export files
#'
#' @param filepath optional specifiy export file
#'
#' @return data frame with pcr data and calculations
#' @importFrom readxl excel_sheets
#' @importFrom readxl read_excel
#' @importFrom tools file_ext
#' @importFrom utils read.table
#' @export
rpcr_readTF <- function(filepath) {

  # This function reads "Amplification data" sheet
  # recognizes header line
  # Renames header names

  id_well <- "Well"
  id_cycle <- "Cycle"
  id_rn <- "Rn"
  id_target <- "arget"
  id_sample <- "ample"


  id_header <- c(id_cycle,id_well,id_target)

  # old - why id_.. needed?
  # id_header_names <- c("well","cycle","target","sample",id_f_incl,id_bf_incl,"name",id_f_excl,id_bf_excl)

  # new - id.. removed
  id_header_names <- c("well","cycle","target","sample","name")

  plate384<-cbind(1:384,as.data.frame(mapply(paste0,as.vector(mapply(rep,LETTERS[1:16],24)),1:24)))
  plate384b<-cbind(1:384,as.data.frame(mapply(paste0,as.vector(mapply(rep,LETTERS[1:16],24)),sprintf("%02d",1:24))))
  names(plate384) <- c("ID","well")
  names(plate384b) <- c("ID","well")

  if (missing(filepath)) filepath <- file.choose()

  ext <- substr(tools::file_ext(filepath),1,3)

  if (ext == "xls") {
    xsheet <- readxl::excel_sheets(path = filepath)
    xsheet <- xsheet[which(grepl("mplific", xsheet))]
    lines <- suppressMessages(do.call(paste, data.frame(readxl::read_excel(filepath, sheet = xsheet, range = "A1:z100", col_names = FALSE))))
    header <- which(grepl(paste0("(?=.*", id_header, ")", collapse=""), lines, perl=TRUE, ignore.case = TRUE))[1]
    df <- data.frame(readxl::read_excel(filepath, sheet = xsheet, skip = header - 1, col_names = TRUE, col_types = "text"))
  } else {
    con <- file(filepath, "r")
    lines <- readLines(con, n = 100)
    close(con)
    header <- which(grepl(paste0("(?=.*", id_header, ")", collapse=""), lines, perl=TRUE, ignore.case = TRUE))[1]
    df <- utils::read.table(filepath,
                     skip = header - 1, header = TRUE, sep = ",", stringsAsFactors = FALSE)
  }
  if (sum(grepl("well", names(df),ignore.case = TRUE)) > 1) df$Well <- NULL
  out <- data.frame(well = df[which(grepl(id_well, names(df),ignore.case = TRUE))])
  names(out)[1] <- "well"
  out[, "cycle"]  <- df[which(grepl(id_cycle, names(df)))]
  out[, "target"]  <- df[which(grepl(id_target, names(df)))]
  if (any(grepl(id_sample, names(df)))) out[, "sample"]  <- df[which(grepl(id_sample, names(df)))]
  out[, "rn"] <- df[,id_rn]
  out[, "drn"] <- df[which(grepl(id_rn, names(df)))[2]]

  ## checking naming format of wells:
  if (length(intersect(plate384b[,2],unique(out$well)))>length(intersect(plate384[,2],unique(out$well)))) {
    uwells <- unique(out$well)
    for (i in 1:length(uwells)){
      out$well[out$well==uwells[i]] <- plate384$well[which(plate384b$well==uwells[i])]
    }
  }

  return(out)
}
