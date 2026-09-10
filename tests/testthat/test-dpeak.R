## rpcr_dpeak() locates populations in the density of a droplet/endpoint readout.

test_that("rpcr_dpeak returns one row per density peak", {
  set.seed(1)
  x <- c(stats::rnorm(200, 0.2, 0.02), stats::rnorm(200, 0.8, 0.02))
  pk <- rpcr_dpeak(x)
  expect_s3_class(pk, "data.frame")
  expect_named(pk, c("start", "peak", "end", "dvalue"))
  expect_equal(nrow(pk), 2)
  expect_equal(pk$peak, c(0.2, 0.8), tolerance = 0.05)
  expect_true(all(pk$start < pk$peak & pk$peak < pk$end))
})

test_that("rpcr_dpeak can return the density alongside the peaks", {
  set.seed(1)
  x <- c(stats::rnorm(200, 0.2, 0.02), stats::rnorm(200, 0.8, 0.02))
  det <- rpcr_dpeak(x, output = "details")
  expect_named(det, c("peaks", "dense"))
  expect_equal(det$peaks, rpcr_dpeak(x))
  expect_true(all(c("x", "y") %in% names(det$dense)))
})

test_that("an empty input is guarded", {
  expect_true(is.na(rpcr_dpeak(numeric(0))))
})

## Not covered: the branch taken when no local maximum clears the filter
## (defect C4, guard corrected from length(max) != 0 to nrow(max) > 0). No input
## reaching it was found - the density's global maximum is an interior local
## maximum and always clears filter = max(y)/20 - so its reachability is still
## unknown and the shape of its return value is unverified.
