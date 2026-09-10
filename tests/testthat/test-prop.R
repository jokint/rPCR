## rpcr_prop() calibrates a vector of apparent proportions.

tprop <- c(0, 0.05, 0.15, 0.25, 0.35, 0.5, 0.65, 0.75, 0.85, 0.95, 1)
para <- c(a = 3, ri = 0.05, re = 0.1, g = 1.2)

test_that("the documented example returns its published values", {
  expect_equal(unname(rpcr_prop(c(0.4, 0.2), calib = c(a = 3, ri = 0, re = 0.05, g = 1))),
               c(0.18349040, 0.07721026), tolerance = 1e-6)
})

test_that("rpcr_prop inverts the forward model over a whole calibration series", {
  aprop <- rpcr_simprop(tprop, a = para[["a"]], ri = para[["ri"]],
                        re = para[["re"]], g = para[["g"]])
  back <- suppressMessages(rpcr_prop(aprop, calib = para))
  expect_length(back, length(tprop))
  expect_equal(unname(back), tprop, tolerance = 1e-4)
})

test_that("an error is reported and NA returned under an enclosing handler", {
  ## Regression test for defect C1 - see test-inverse.R for the mechanism.
  res <- tryCatch(suppressMessages(rpcr_prop("x", calib = para)),
                  error = function(e) "aborted")
  expect_true(all(is.na(res)))
})

test_that("the condition message is printed rather than re-signalled", {
  expect_message(rpcr_prop("x", calib = para), "non-numeric argument")
})
