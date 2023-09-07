
<!-- README.md is generated from README.Rmd. Please edit that file -->

# spAbundance

# spAbundance

[![](http://cranlogs.r-pkg.org/badges/grand-total/spAbundance?color=blue)](https://CRAN.R-project.org/package=spAbundance)
[![CRAN](https://www.r-pkg.org/badges/version/spAbundance)](https://CRAN.R-project.org/package=spAbundance)
[![Codecov test
coverage](https://codecov.io/gh/doserjef/spAbundance/branch/main/graph/badge.svg)](https://codecov.io/gh/doserjef/spAbundance?branch=main)

`spAbundance` fits univariate (i.e., single-species) and multivariate
(i.e., multi-species) spatial abundance models using Markov Chain Monte
Carlo (MCMC). The package currently contains all functionality for it’s
first release on CRAN, and is currently undergoing extensive testing
prior to the release on CRAN. `spAbundance` uses analogous syntax to its
“sister package”
[spOccupancy](https://www.jeffdoser.com/files/spoccupancy-web/) (Doser
et al. 2022).

## Installation

`spAbundance` is not yet on CRAN, with a planned initial submission date
in Fall 2023. To download the development version of the package, you
can use `devtools` as follows:

``` r
devtools::install_github("doserjef/spAbundance")
```

Note that because we implement the MCMC in C++, you will need a C++
compiler on your computer to install the package from GitHub. To compile
C++ on Windows, you can install
[`RTools`](https://cran.r-project.org/bin/windows/Rtools/). To compile
C++ on a Mac, you can install `XCode` from the Mac app store.

## Functionality

| `spAbundance` Function | Description                                                             |
| ---------------------- | ----------------------------------------------------------------------- |
| `NMix()`               | Single-species N-mixture model                                          |
| `spNMix()`             | Single-species spatial N-mixture model                                  |
| `msNMix()`             | Multi-species N-mixture model                                           |
| `lfMsNMix()`           | Multi-species N-mixture model with species correlations                 |
| `sfMsNMix()`           | Multi-species spatial N-mixture model with species correlations         |
| `DS()`                 | Single-species distance sampling model                                  |
| `spDS()`               | Single-species spatial distance sampling model                          |
| `msDS()`               | Multi-species distance sampling model                                   |
| `lfMsDS()`             | Multi-species distance sampling model with species correlations         |
| `sfMsDS()`             | Multi-species spatial distance sampling model with species correlations |
| `abund()`              | Single-species abundance GLM                                            |
| `spAbund()`            | Single-species spatial abundance GLM                                    |
| `msAbund()`            | Multi-species abundance GLM                                             |
| `lfMsAbund()`          | Multi-species abundance GLM with species correlations                   |
| `sfMsAbund()`          | Multi-species spatial abundance GLM with species correlations           |
| `ppcAbund()`           | Posterior predictive check using Bayesian p-values                      |
| `waicAbund()`          | Calculate Widely Applicable Information Criterion (WAIC)                |
| `simNMix()`            | Simulate single-species repeated count data                             |
| `simAbund()`           | Simulate single-species count data                                      |
| `simMsAbund()`         | Simulate multi-species count data                                       |
| `simMsNMix()`          | Simulate multi-species repeated count data                              |
| `simDS()`              | Simulate single-species distance sampling data                          |
| `simMsDS()`            | Simulate multi-species distance sampling data                           |

All model fitting functions allow for Poisson and negative binomial
distributions for the abundance portion of the model. All GLM(M)s also
allow for Gaussian models.

## Citing `spAbundance`

Please cite `spAbundance` as:

Doser, J. W. and Finley, A. O. (2023). spAbundance: Univariate and
Multivariate Spatial Modeling of Species Abundance". R package version
0.1.0. <https://github.com/doserjef/spAbundance>

## References

Doser, J. W., Finley, A. O., Kéry, M., and Zipkin, E. F. (2022a).
spOccupancy: An R package for single-species, multi-species, and
integrated spatial occupancy models. Methods in Ecology and Evolution.
<https://doi.org/10.1111/2041-210X.13897>.
