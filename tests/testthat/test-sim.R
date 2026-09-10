## rpcr_sim() tabulates the forward model over a parameter sweep.

tprop <- c(0, 0.05, 0.15, 0.25, 0.35, 0.5, 0.65, 0.75, 0.85, 0.95, 1)

test_that("rpcr_sim returns one row per parameter combination and proportion", {
  s <- rpcr_sim(tprop = tprop, a = 2, ri = 0.1, re = 0.1, g = 1.5, steps = 3)
  expect_s3_class(s, "data.frame")
  expect_named(s, c("tprop", "a", "ri", "re", "g", "sprop"))
  expect_equal(nrow(s) %% length(tprop), 0)
  expect_gt(nrow(s), length(tprop))
})

test_that("each row of rpcr_sim is the forward model at that row's own parameters", {
  s <- rpcr_sim(tprop = tprop, a = 2, ri = 0.1, re = 0.1, g = 1.5, steps = 3)
  expected <- mapply(function(t, a, ri, re, g) rpcr_simprop(t, a = a, ri = ri, re = re, g = g),
                     s$tprop, s$a, s$ri, s$re, s$g)
  expect_equal(s$sprop, as.numeric(expected))
})
