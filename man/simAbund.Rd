\name{simAbund}
\alias{simAbund}
\title{Simulate Single-Species Count Data without Imperfect Detection}

\description{
  The function \code{simAbund} simulates single-species count data without imperfect detection for simulation studies, power assessments, or function testing. Data can be optionally simulated with a spatial Gaussian Process in the model. Non-spatial random intercepts can also be included in the model.
}

\usage{
simAbund(J.x, J.y, n.rep, beta, kappa, mu.RE = list(), 
       sp = FALSE, cov.model, sigma.sq, phi, nu, 
       family = 'NB', ...)
}

\arguments{
\item{J.x}{a single numeric value indicating the number of sites to simulate count data along the horizontal axis. Total number of sites with simulated data is \eqn{J.x \times J.y}{J.x x J.y}. }

\item{J.y}{a single numeric value indicating the number of sites to simulate count data along the vertical axis. Total number of sites with simulated data is \eqn{J.x \times J.y}{J.x x J.y}. }

\item{n.rep}{a numeric vector of length \eqn{J = J.x \times J.y}{J = J.x x J.y} indicating the number of replicate surveys at each of the \eqn{J}{J} sites.}

\item{beta}{a numeric vector containing the intercept and regression coefficient parameters for the abundance model.}

\item{kappa}{a single numeric value containing the dispersion parameter for the abundance portion of the model. Only relevant when \code{family = 'NB'}.}

\item{mu.RE}{a list used to specify the non-spatial random intercepts included in the model. The list must have two tags: \code{levels} and \code{sigma.sq.mu}. \code{levels} is a vector of length equal to the number of distinct random intercepts to include in the model and contains the number of levels there are in each intercept. \code{sigma.sq.mu} is a vector of length equal to the number of distinct random intercepts to include in the model and contains the variances for each random effect. A third optional tage is \code{beta.indx}, which is a numeric vector with length equal to the number of distinct random intercepts. The values in \code{beta.indx} denote the intercept/covariate for which you wish to simulate a random intercept/slope. Numeric values correspond to the intercept/covaraite in \code{beta}. If \code{mu.RE} is not specified, no random effects are included in the abundance portion of the model.}

\item{sp}{a logical value indicating whether to simulate a spatially-explicit model with a Gaussian process. By default set to \code{FALSE}.}

\item{cov.model}{a quoted keyword that specifies the covariance function used to model the spatial dependence structure among the abundance data.  Supported covariance model key words are: \code{"exponential"}, \code{"matern"}, \code{"spherical"}, and \code{"gaussian"}.}

\item{sigma.sq}{a numeric value indicating the spatial variance parameter. Ignored when \code{sp = FALSE}.}

\item{phi}{a numeric value indicating the spatial decay parameter. Ignored when \code{sp = FALSE}. }

\item{nu}{a numeric value indicating the spatial smoothness parameter. Only used when \code{sp = TRUE} and \code{cov.model = "matern"}.} 

\item{family}{the distribution to use for the data. Currently
  supports \code{'NB'} (negative binomial) and \code{'Poisson'}.}

\item{...}{currently no additional arguments}
}

\author{
  Jeffrey W. Doser \email{doserjef@msu.edu}, \cr
  Andrew O. Finley \email{finleya@msu.edu}
}

\value{
  A list comprised of: 

  \item{X}{a three-dimensional numeric design array of covariates with dimensions corresponding to sites, replicates, and number of covariates (including an intercept) for the model.}
  \item{coords}{a \eqn{J \times 2}{J x 2} numeric matrix of coordinates of each site. Required for spatial models.}
  \item{w}{a \eqn{J \times 1}{J x 1} matrix of the spatial random effects. Only used to simulate data when \code{sp = TRUE}.}
  \item{mu}{a \code{J x max(n.rep)} matrix of the expected abundance values for each site and replicate survey.}
  \item{y}{a \code{J x max(n.rep)} matrix of the raw count data for each site and replicate combination.}
  \item{X.re}{a numeric three-dimensional array containing the levels of any abundance random effect included in the model. Only relevant when abundance random effects are specified in \code{mu.RE}.}
  \item{beta.star}{a numeric vector that contains the simulated abundance random effects for each given level of the random effects included in the abundance model. Only relevant when abundance random effects are included in the model.}
}

\examples{
set.seed(401)
J.x <- 15
J.y <- 15
J <- J.x * J.y
n.rep <- sample(3, J, replace = TRUE)
beta <- c(0, -1.5, 0.3, -0.8)
p.abund <- length(beta)
mu.RE <- list(levels = c(30),
	       sigma.sq.mu = c(1.3))
kappa <- 0.5
sp <- FALSE 
family <- 'NB'
dat <- simAbund(J.x = J.x, J.y = J.y, n.rep = n.rep, beta = beta, 
	        kappa = kappa, mu.RE = mu.RE, sp = sp, family = 'NB')
}
