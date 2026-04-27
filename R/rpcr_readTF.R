#' Reading ThermoFisher Export files
#'
#' @description
#' Reads the amplification data sheet from ThermoFisher export files.
#' Auto-detects the header line and standardizes well names.
#'
#' @param filepath Optional character string specifying the path to the file.
#'   If missing, a file selection dialog will open automatically.
#'
#' @return A data frame with extracted and standardized PCR amplification data.
#' @export
rpcr_readTF <- function(filepath) {

  # File Selection & Validation ----

  # Open file selection dialog if no path was provided
  if (missing(filepath)) {
    filepath <- tryCatch(
      file.choose(),
      error = function(e) {
        message("File selection cancelled by user.")
        return(NULL)
      }
    )
  }

  # Stop execution if user cancelled the dialog
  if (is.null(filepath)) return(invisible(NULL))

  # Ensure the file actually exists
  if (!file.exists(filepath)) {
    stop(
      paste0("The file '", filepath, "' does not exist! Please check the path."),
      call. = FALSE
    )
  }

  # Check file extension and warn on unexpected formats
  ext <- substr(tools::file_ext(filepath), 1, 3)
  if (!ext %in% c("xls", "csv", "txt")) {
    warning("File extension is not .xls, .csv or .txt. This might cause read errors!")
  }

  # Definitions & Helper Variables ----

  id_well   <- "Well"
  id_cycle  <- "Cycle"
  id_rn     <- "Rn"
  id_target <- "arget"
  id_sample <- "ample"

  # These three columns must be present in the header line
  id_header <- c(id_cycle, id_well, id_target)

  # Generate 384-well plate templates for later name standardization
  plate384  <- cbind(1:384, as.data.frame(mapply(paste0, as.vector(mapply(rep, LETTERS[1:16], 24)), 1:24)))
  plate384b <- cbind(1:384, as.data.frame(mapply(paste0, as.vector(mapply(rep, LETTERS[1:16], 24)), sprintf("%02d", 1:24))))
  names(plate384)  <- c("ID", "well")
  names(plate384b) <- c("ID", "well")

  # File Import ----

  if (ext == "xls") {
    # Find sheet containing amplification data
    xsheet <- readxl::excel_sheets(path = filepath)
    xsheet <- xsheet[which(grepl("mplific", xsheet))]

    # Read first 100 lines to detect header row
    lines <- suppressMessages(do.call(paste, data.frame(readxl::read_excel(filepath, sheet = xsheet, range = "A1:z100", col_names = FALSE))))
    header <- which(grepl(paste0("(?=.*", id_header, ")", collapse=""), lines, perl=TRUE, ignore.case = TRUE))

    # Read the actual data sheet starting from the header row
    df <- data.frame(readxl::read_excel(filepath, sheet = xsheet, skip = header - 1, col_names = TRUE, col_types = "text"))
  } else {
    # Read first 100 lines to detect header row
    con <- file(filepath, "r")
    lines <- readLines(con, n = 100)
    close(con)

    header <- which(grepl(paste0("(?=.*", id_header, ")", collapse=""), lines, perl=TRUE, ignore.case = TRUE))

    # Read the file as CSV starting from the header row
    df <- utils::read.table(filepath, skip = header - 1, header = TRUE, sep = ",", stringsAsFactors = FALSE)
  }

  # Data Extraction & Column Normalization ----

  # Remove duplicate well columns if present
  if (sum(grepl("well", names(df), ignore.case = TRUE)) > 1) {
    df$Well <- NULL
  }

  # Successively build target dataframe
  out <- data.frame(well = df[which(grepl(id_well, names(df), ignore.case = TRUE))])
  names(out) <- "well"

  out[, "cycle"]  <- df[which(grepl(id_cycle, names(df)))]
  out[, "target"] <- df[which(grepl(id_target, names(df)))]

  # Handle optional sample column
  if (any(grepl(id_sample, names(df)))) {
    out[, "sample"] <- df[which(grepl(id_sample, names(df)))]
  }

  out[, "rn"]  <- df[, id_rn]
  out[, "drn"] <- df[which(grepl(id_rn, names(df)))[2]]

  # Well Name Standardization ----

  # Convert well formats like A01 to A1 if needed
  if (length(intersect(plate384b[, 2], unique(out$well))) > length(intersect(plate384[, 2], unique(out$well)))) {
    uwells <- unique(out$well)
    for (i in 1:length(uwells)) {
      out$well[out$well == uwells[i]] <- plate384$well[which(plate384b$well == uwells[i])]
    }
  }

  return(out)
}
