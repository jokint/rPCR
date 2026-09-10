## rpcr_calib() is the calibration fit: it estimates a, ri, re and g from
## reactions of known composition. Simulating a calibration series with known
## parameters and recovering them is what demonstrates that a published ratio
## follows from the code rather than from the fit's starting values.

tprop <- c(0, 0.05, 0.15, 0.25, 0.35, 0.5, 0.65, 0.75, 0.85, 0.95, 1)
para <- c(a = 3, ri = 0.05, re = 0.1, g = 1.2)
aprop <- rpcr_simprop(tprop, a = para[["a"]], ri = para[["ri"]],
                      re = para[["re"]], g = para[["g"]])

test_that("rpcr_calib recovers the parameters used to simulate the series", {
  fit <- rpcr_calib(data.frame(tprop = tprop, aprop = aprop))
  expect_s3_class(fit, "nls")
  expect_equal(stats::coef(fit)[c("a", "ri", "re", "g")], para, tolerance = 1e-6)
  expect_lt(stats::deviance(fit), 1e-20)
})

test_that("the fitted parameters return the calibration series to its true composition", {
  fit <- rpcr_calib(data.frame(tprop = tprop, aprop = aprop))
  cprop <- suppressMessages(rpcr_prop(aprop, calib = stats::coef(fit)))
  expect_equal(unname(cprop), tprop, tolerance = 1e-4)
})

test_that("a calibration that cannot be fitted returns NA instead of aborting", {
  ## Regression test for defect C1 - see test-inverse.R for the mechanism.
  df <- data.frame(tprop = tprop, aprop = rep(NA_real_, length(tprop)))
  res <- tryCatch(suppressMessages(rpcr_calib(df, silent = TRUE)),
                  error = function(e) "aborted")
  expect_true(is.na(res))
})
