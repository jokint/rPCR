## rpcr_wrap() reshapes an instrument export into an rpcr_raw object.
## The helper builds a deterministic two-well, two-target, 40-cycle stand-in for
## rpcr_readTF() output - a logistic amplification curve rather than the
## single-cycle frame used in the examples, so that the smoothing and efficiency
## steps of full = TRUE have enough cycles to work on.

amp <- function(cycles, midpoint, offset) 10 / (1 + exp(-(cycles - midpoint) / 2)) + offset

raw_stand_in <- function() {
  cyc <- 1:40
  signal <- c(amp(cyc, 22, 0.05), amp(cyc, 20, 0.10),
              amp(cyc, 23, 0.15), amp(cyc, 21, 0.20))
  data.frame(
    well = rep(c("A1", "A2"), each = 80),
    cycle = rep(cyc, 4),
    target = rep(c("Gene_incl", "Gene_excl"), each = 40),
    sample = "S1",
    rn = signal,
    drn = signal / 10,
    stringsAsFactors = FALSE
  )
}

test_that("rpcr_wrap pivots raw data into an rpcr_raw object", {
  w <- rpcr_wrap(raw_stand_in())
  expect_s3_class(w, "rpcr_raw")
  expect_s3_class(w, "data.frame")
  expect_equal(nrow(w), 80)
  expect_true(all(c("FA", "FB", "FT", "bFA", "bFB", "bFT",
                    "ratio", "bratio", "aprop", "bprop", "rcycle") %in% names(w)))
})

test_that("the total channel and the proportions are consistent with the two probes", {
  w <- rpcr_wrap(raw_stand_in())
  expect_equal(w$FT, w$FA + w$FB)
  expect_equal(w$aprop, w$FA / w$FT)
  expect_equal(w$ratio, w$FA / w$FB)
})

test_that("the full = TRUE branch runs and fills the derivative and efficiency columns", {
  ## Regression test for defect C2. rpcr_batch() passes id_col to every worker,
  ## but rpcr_filter() and rpcr_calEff() accepted neither id_col nor ..., so the
  ## whole full = TRUE branch aborted with "unused argument (id_col = id_col)"
  ## and the Savitzky-Golay, efficiency and d1/d2 columns were unreachable.
  expect_no_message(rpcr_wrap(raw_stand_in(), full = TRUE))
  w <- rpcr_wrap(raw_stand_in(), full = TRUE)
  expect_true(all(c("d1FA", "d2Fincl", "sFA", "sFB", "sFT",
                    "eff_incl", "eff_excl", "d0_r", "d1_r") %in% names(w)))
  expect_true(all(is.finite(w$eff_incl)))
  expect_true(all(is.finite(w$eff_excl)))
  expect_gt(ncol(w), ncol(rpcr_wrap(raw_stand_in())))
})
