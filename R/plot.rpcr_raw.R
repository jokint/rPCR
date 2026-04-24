#' Plots a series of charts to summarize a calibration experiment
#'
#' @description
#' Generates and returns plots based on the selected plot type and signal type.
#' It calls the internal functions `rpcr_plotData` and `rpcr_plotBar`.
#' If multiple plots are generated, they are automatically combined into a
#' single grid layout using the `patchwork` package.
#'
#' @param x An object of class `rpcr_raw` containing the PCR data.
#' @param plot_type Character string indicating the plot style.
#'   Options are `"all"` (default), `"general"`, or `"cycle"`.
#' @param signal Character string indicating the signal type.
#'   Options are `"all"` (default), `"Rn"`, or `"deltaRn"`.
#' @param ... Further arguments passed to `rpcr_plotData` and `rpcr_plotBar`.
#'
#' @return A single ggplot object or a combined patchwork grid of plots.
#' @exportS3Method graphics::plot
plot.rpcr_raw <- function(x, plot_type = "all", signal = "all", ...) {

  figures <- list()

  # 1. Generate "general" plots (using rpcr_plotData) ----
  if (plot_type %in% c("all", "general")) {

    # Process Rn signal
    if (signal %in% c("all", "Rn")) {
      # This function returns a named list of 5 ggplot objects
      rn_plots <- rpcr_plotData(x, title = "normalized fluorescence\n", signal = "Rn", ...)

      # Flatten the list and add to the main figures list
      for (plot_name in names(rn_plots)) {
        figures[[paste0("Rn_", plot_name)]] <- rn_plots[[plot_name]]
      }
    }

    # Process deltaRn signal
    if (signal %in% c("all", "deltaRn")) {
      drn_plots <- rpcr_plotData(x, title = "normalized fluorescence\n", signal = "deltaRn", ...)

      # Flatten the list and add to the main figures list
      for (plot_name in names(drn_plots)) {
        figures[[paste0("deltaRn_", plot_name)]] <- drn_plots[[plot_name]]
      }
    }
  }

  # 2. Generate "cycle" plots (using rpcr_plotBar) ----
  if (plot_type %in% c("all", "cycle")) {

    if (signal %in% c("all", "Rn")) {
      figures$cycle_Rn <- rpcr_plotBar(
        x,
        title = "normalized fluorescence\n",
        signal = "Rn",
        ...
      )
    }

    if (signal %in% c("all", "deltaRn")) {
      figures$cycle_deltaRn <- rpcr_plotBar(
        x,
        title = "normalized fluorescence\n",
        signal = "deltaRn",
        ...
      )
    }
  }

  # 3. Combine and return the plots ----

  # Filter out anything that is NOT a valid ggplot object (safety check)
  is_ggplot <- sapply(figures, function(fig) inherits(fig, "ggplot"))
  figures <- figures[is_ggplot]

  # Return NULL if no valid plots were generated
  if (length(figures) == 0) {
    message("No valid ggplot objects generated with the current settings.")
    return(invisible(NULL))
  }

  # If only 1 plot is present, return it directly
  if (length(figures) == 1) {
    return(figures[[1]])
  }

  # Combine multiple plots into a grid with 2 columns
  # This returns a single, combined patchwork object
  combined_plot <- patchwork::wrap_plots(figures, ncol = 2)

  return(combined_plot)
}
