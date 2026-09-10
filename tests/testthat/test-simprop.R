## The forward model: apparent proportion as a function of the true one.
## rpcr_simprop() is the analytical core - rpcr_calib() fits it, rpcr_inverse()
## inverts it - so these are the invariants everything else rests on.

tprop <- c(0, 0.05, 0.15, 0.25, 0.35, 0.5, 0.65, 0.75, 0.85, 0.95, 1)
para <- c(a = 3, ri = 0.05, re = 0.1, g = 1.2)

test_that("the unbiased parameter set is the identity", {
  expect_equal(rpcr_simprop(tprop, a = 1, ri = 0, re = 0, g = 1), tprop)
})

test_that("specific probes preserve the endpoints", {
  ## ri = 0: the inclusion probe sees nothing of the exclusion isoform
  expect_equal(rpcr_simprop(0, a = 3, ri = 0, re = 0.05, g = 1), 0)
  ## re = 0: the exclusion probe sees nothing of the inclusion isoform
  expect_equal(rpcr_simprop(1, a = 3, ri = 0, re = 0, g = 1), 1)
  ## with re > 0 the apparent proportion at tprop = 1 is a / (a + re)
  expect_equal(rpcr_simprop(1, a = 3, ri = 0, re = 0.05, g = 1), 3 / 3.05)
})

test_that("the forward model is monotone in the true proportion", {
  aprop <- rpcr_simprop(tprop, a = para[["a"]], ri = para[["ri"]],
                        re = para[["re"]], g = para[["g"]])
  expect_true(all(diff(aprop) > 0))
  expect_true(all(aprop >= 0 & aprop <= 1))
})

test_that("the model variants evaluate over the whole calibration range", {
  for (variant in list(list(extend = TRUE), list(novel = TRUE), list(prop = FALSE))) {
    out <- do.call(rpcr_simprop,
                   c(list(tprop, a = para[["a"]], ri = para[["ri"]],
                          re = para[["re"]], g = para[["g"]]), variant))
    expect_length(out, length(tprop))
    expect_true(all(is.finite(out)))
  }
})
