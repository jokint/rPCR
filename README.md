# ratioPCR

Ratiometric quantification of co-amplified PCR templates.

`ratioPCR` estimates the relative abundance of two templates amplified together
in a single real-time PCR reaction. Sharing a primer pair couples the
amplification of the templates, which distorts the measured fluorescence ratio
in a way that is systematic rather than random. The package estimates that
distortion from calibration reactions of known composition, using a mechanistic
model of the coupled amplification, and inverts the model to convert a measured
ratio into a template ratio.

It is the analysis method of:

> Kinter J, Stiefvater A, Osterop S, Sinnreich M. *ratioPCR: Mechanistically
> corrected real-time analysis of multi-template PCR.* iScience (in press).

## Installation

The package is not on CRAN - its licence does not permit commercial use, which
CRAN requires. Install from the release tarball:

```r
install.packages("ratioPCR_0.1.0.tar.gz", repos = NULL, type = "source")
```

or from the repository:

```r
# install.packages("remotes")
remotes::install_github("jokint/rPCR")
```

R (>= 4.1.0) is required.

## Minimal example

The model, the calibration fit and the inversion can be exercised without any
instrument data. A calibration series of known composition is simulated with
known bias parameters, the parameters are estimated back from it, and an
apparent proportion is then corrected:

```r
library(ratioPCR)

## true composition of the calibration reactions
tprop <- c(0, 0.05, 0.15, 0.25, 0.35, 0.5, 0.65, 0.75, 0.85, 0.95, 1)

## what a biased assay would measure for them
aprop <- rpcr_simprop(tprop, a = 3, ri = 0.05, re = 0.1, g = 1.2)

## estimate the calibration parameters from the series
fit <- rpcr_calib(data.frame(tprop = tprop, aprop = aprop))
coef(fit)
#>    a   ri   re    g
#> 3.00 0.05 0.10 1.20

## correct measured proportions with a set of calibration parameters
rpcr_prop(c(0.4, 0.2), calib = c(a = 3, ri = 0, re = 0.05, g = 1))
#> [1] 0.18349040 0.07721026
```

The four parameters have mechanistic meaning: `a` is the ratio of the two probe
intensities, `ri` and `re` are the cross-reactivities of the inclusion and
exclusion probes, and `g` describes the asymmetry of the coupled amplification.

## Workflow on instrument data

For real measurements the entry point is the instrument export:

| Step | Function |
|---|---|
| Read a ThermoFisher export and reshape it | `rpcr_import()`, `rpcr_readTF()`, `rpcr_wrap()` |
| Baseline, derivatives, efficiencies | `rpcr_calBase()`, `rpcr_calDer()`, `rpcr_calEff()`, `rpcr_filter()` |
| Read out a curve at a threshold or cycle | `rpcr_calAmp()`, `rpcr_relCycle()`, `rpcr_fit()`, `rpcr_batchFit()` |
| Fit the calibration and its quality control | `rpcr_calibrate()`, `rpcr_calib()`, `rpcr_calibQC()` |
| Convert apparent to template proportions | `rpcr_prop()`, `rpcr_inverse()` |
| Simulate, plot | `rpcr_sim()`, `rpcr_simprop()`, `rpcr_plotCalib()`, `rpcr_plotData()`, `plot()` on an `rpcr_raw` object |

`vignette("ratioPCR_tutorial")` walks through the object model.

## Tests

```r
R CMD build . && R CMD check --as-cran ratioPCR_0.1.0.tar.gz
```

`tests/testthat/` covers the analytical core: the forward model's invariants,
inversion of the model, recovery of the calibration parameters from a simulated
series, the reshaping of raw data, and the density-peak readout. Two of the
tests are regressions for defects fixed in this version - an error handler that
re-signalled instead of reporting, and an argument-passing failure that made
`rpcr_wrap(full = TRUE)` unreachable.

## Licence

PolyForm Noncommercial License 1.0.0, copyright University of Basel - see
`LICENSE`. Noncommercial use, including academic research and teaching, is
permitted; commercial use is not covered. For uses outside the licence, contact
the corresponding author (j.kinter@unibas.ch).

## Citation

`citation("ratioPCR")` gives the article and the software entry.
