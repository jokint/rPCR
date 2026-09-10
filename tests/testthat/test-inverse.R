## rpcr_inverse() solves the forward model for the true proportion.

tprop <- c(0, 0.05, 0.15, 0.25, 0.35, 0.5, 0.65, 0.75, 0.85, 0.95, 1)
para <- c(a = 3, ri = 0.05, re = 0.1, g = 1.2)

test_that("rpcr_inverse recovers the proportion the forward model was given", {
  aprop <- rpcr_simprop(tprop, a = para[["a"]], ri = para[["ri"]],
                        re = para[["re"]], g = para[["g"]])
  back <- vapply(aprop, function(y) {
    as.numeric(rpcr_inverse(y, a = para[["a"]], ri = para[["ri"]],
                            re = para[["re"]], g = para[["g"]])$root)
  }, numeric(1))
  ## uniroot's own convergence tolerance sets the floor here
  expect_equal(back, tprop, tolerance = 1e-4)
})

test_that("a target value outside the model range returns NA rather than an error", {
  expect_true(is.na(suppressMessages(rpcr_inverse(5, a = 3, ri = 0, re = 0.05, g = 1))))
})

test_that("an error inside rpcr_inverse is reported, not re-signalled", {
  ## Regression test for defect C1. The handler read
  ##   error = function(cond) { message(cond); return(NA) }
  ## and message() given a condition object *signals* it, so the error was
  ## re-dispatched to the next handler on the stack: the intended graceful NA
  ## became a hard abort inside any enclosing tryCatch - knitr, Shiny, testthat,
  ## targets, or user code. The fix is message(conditionMessage(cond)).
  res <- tryCatch(suppressMessages(rpcr_inverse("x", a = 3, ri = 0, re = 0.05, g = 1)),
                  error = function(e) "aborted")
  expect_true(is.na(res))
})
