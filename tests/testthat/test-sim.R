## rpcr_sim() tabulates the forward model over a parameter sweep.

tprop <- c(0, 0.05, 0.15, 0.25, 0.35, 0.5, 0.65, 0.75, 0.85, 0.95, 1)

test_that("rpcr_sim returns one row per proportion and parameter combination", {
  s <- rpcr_sim(tprop = tprop, a = 2, ri = 0.1, re = 0.1, g = 1.5, steps = 3)
  expect_s3_class(s, "data.frame")
  expect_named(s, c("tprop", "a", "ri", "re", "g", "sprop"))
  expect_equal(nrow(s), length(tprop) * 3^4)
  expect_equal(nrow(unique(s[, c("a", "ri", "re", "g")])), 3^4)
})

test_that("every value of every swept parameter reaches the returned table", {
  ## The function built the whole sweep as four nested loops with re outermost,
  ## then returned res[[1]] - the slice belonging to the first re value only. So
  ## a, ri and g were swept as documented while re stayed at 0, and a sweep of re
  ## alone returned a single re value. The return now binds the whole list.
  s <- rpcr_sim(tprop = tprop, a = 2, ri = 0.1, re = 0.1, g = 1.5, steps = 3)
  expect_equal(sort(unique(s$a)), c(1, 1.5, 2))
  expect_equal(sort(unique(s$ri)), c(0, 0.05, 0.1))
  expect_equal(sort(unique(s$re)), c(0, 0.05, 0.1))
  expect_equal(sort(unique(s$g)), c(1, 1.25, 1.5))
})

test_that("sweeping one parameter varies that parameter and holds the others", {
  s <- rpcr_sim(tprop = tprop, re = 0.2, steps = 3, range = "re")
  expect_equal(nrow(s), length(tprop) * 3)
  expect_equal(sort(unique(s$re)), c(0, 0.1, 0.2))
  expect_equal(unique(s$a), 1)
  expect_equal(unique(s$g), 1)

  s <- rpcr_sim(tprop = tprop, a = 2, steps = 3, range = "a")
  expect_equal(nrow(s), length(tprop) * 3)
  expect_equal(sort(unique(s$a)), c(1, 1.5, 2))
  expect_equal(unique(s$re), 0)
})

test_that("each row of rpcr_sim is the forward model at that row's own parameters", {
  s <- rpcr_sim(tprop = tprop, a = 2, ri = 0.1, re = 0.1, g = 1.5, steps = 3)
  expected <- mapply(function(t, a, ri, re, g) rpcr_simprop(t, a = a, ri = ri, re = re, g = g),
                     s$tprop, s$a, s$ri, s$re, s$g)
  expect_equal(s$sprop, as.numeric(expected))
})
