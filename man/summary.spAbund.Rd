\name{summary.spAbund}

\alias{summary.spAbund}
\alias{print.spAbund}

\title{Methods for spAbund Object}

\description{
  Methods for extracting information from fitted abundance GLMs (\code{spAbund}) without imperfect detection.
}

\usage{
\method{summary}{spAbund}(object, quantiles = c(0.025, 0.5, 0.975), 
        digits = max(3L, getOption("digits") - 3L), \dots)
\method{print}{spAbund}(x, \dots)
}

\arguments{
  \item{object, x}{object of class \code{spAbund}.}
  \item{quantiles}{for \code{summary}, posterior distribution quantiles to compute.}
  \item{digits}{for \code{summary}, number of digits to report.}
  \item{\dots}{currently no additional arguments}
}

\details{
  A set of standard extractor functions for fitted model objects of
  class \code{spAbund}, including methods to the generic functions \code{\link[base]{print}} and \code{\link[base]{summary}}. 
}

\value{
  No return value, called to display summary information of a \code{spAbund} object.
}


\keyword{model}
