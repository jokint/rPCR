## Theme and palette helpers.

test_that("theme_rpcr provides both variants", {
  expect_s3_class(theme_rpcr(), "theme")
  expect_s3_class(theme_rpcr(type = "textless"), "theme")
})

test_that("the discrete scales forward ... to ggplot2", {
  ## Both scales accepted ... and silently dropped it, so
  ## scale_colour_rpcr(guide = "none") did nothing. Forwarding to
  ## ggplot2::discrete_scale() is a behaviour change: an argument that used to be
  ## dropped in silence now errors.
  expect_s3_class(scale_colour_rpcr(guide = "none"), "ScaleDiscrete")
  expect_s3_class(scale_fill_rpcr(), "ScaleDiscrete")
  expect_error(scale_colour_rpcr(nonsense = 1), "unused argument")
})
