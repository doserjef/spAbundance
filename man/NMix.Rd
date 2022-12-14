\name{NMix}
\alias{NMix}
\title{Function for Fitting Single-Species N-mixture Models}

\usage{
NMix(abund.formula, det.formula, data, inits, priors, tuning,
     n.batch, batch.length, accept.rate = 0.43, family = 'NB',
     n.omp.threads = 1, verbose = TRUE,
     n.report = 100, n.burn = round(.10 * n.batch * batch.length), n.thin = 1, 
     n.chains = 1, k.fold, k.fold.threads = 1, k.fold.seed = 100, 
     k.fold.only = FALSE, ...)
}

\description{
  Function for fitting single-species N-mixture models 
}

\arguments{
\item{abund.formula}{a symbolic description of the model to be fit
  for the abundance portion of the model using R's model syntax. Only
  right-hand side of formula is specified. See example below. Random intercepts
  are allowed using lme4 syntax (Bates et al. 2015).}

\item{det.formula}{a symbolic description of the model to be fit
  for the detection portion of the model using R's model syntax. Only
  right-hand side of formula is specified. See example below. Random intercepts
  are allowed using lme4 syntax (Bates et al. 2015).}

\item{data}{a list containing data necessary for model fitting.
  Valid tags are \code{y}, \code{abund.covs}, and \code{det.covs}. \code{y}
  is a matrix or data frame of the observed count values, 
  with first dimension equal to the number of 
  sites (\eqn{J}{J}) and second dimension equal to the maximum number of 
  replicates at a given site. \code{abund.covs} is a matrix or data frame
  containing the variables used in the abundance portion of the model, with
  \eqn{J}{J} rows for each column (variable). \code{det.covs} is a list of
  variables included in the detection portion of the model. Each list element
  is a different detection covariate, which can be site-level or 
  observational-level. Site-level covariates are specified as a vector 
  of length \eqn{J}{J} while observation-level covariates are specified 
  as a matrix or data frame with the number of rows equal to \eqn{J}{J} and 
  number of columns equal to the maximum number of replicates at a given site.}

\item{inits}{a list with each tag corresponding to a parameter name.
  Valid tags are \code{N}, \code{beta}, \code{alpha}, \code{kappa}, 
  \code{sigma.sq.mu}, and \code{sigma.sq.p}. The value portion of each tag is the 
  parameter's initial value. \code{sigma.sq.mu} and \code{sigma.sq.p} are 
  only relevant when including random effects in the occurrence and 
  detection portion of the occupancy model, respectively. \code{kappa} is 
  only relevant when \code{family = 'NB'}. See \code{priors} 
  description for definition of each parameter name.
  Additionally, the tag \code{fix} can be set to \code{TRUE} 
  to fix the starting values across all chains. If \code{fix} is not specified
  (the default), starting values are varied randomly across chains.}

\item{priors}{a list with each tag corresponding to a parameter name. 
  Valid tags are \code{beta.normal}, \code{alpha.normal}, \code{kappa.unif}, 
  \code{sigma.sq.mu.ig}, and \code{sigma.sq.p.ig}. 
  Abundance (\code{beta}) and detection (\code{alpha}) 
  regression coefficients are assumed to follow a normal distribution. 
  The hyperparameters of the normal distribution are passed as a list of 
  length two with the first and second elements corresponding to the mean 
  and variance of the normal distribution, which are each specified as vectors of 
  length equal to the number of coefficients to be estimated or of length one
  if priors are the same for all coefficients. If not specified, prior means 
  are set to 0 and prior variances set to 100 for the abundance coefficients
  and 2.72 for the detection coefficients. \code{kappa} is the negative binomial 
  dispersion parameter and is assumed to follow a uniform distribution. The 
  hyperparameters of the uniform distribution are passed as a vector of length
  two with the first and second elements corresponding to the lower and upper
  bounds of the uniform distribution. \code{sigma.sq.mu} and 
  \code{sigma.sq.p} are the random effect variances for any abundance or 
  detection random effects, respectively, and are assumed to follow an inverse
  Gamma distribution. The hyperparameters of the inverse-Gamma distribution
  are passed as a list of length two with first and second elements corresponding
  to the shape and scale parameters, respectively, which are each specified as
  vectors of length equal to the number of random intercepts or of length one 
  if priors are the same for all random effect variances.}

\item{tuning}{a single numeric value representing the initial variance of the
  adaptive sampler for \code{kappa}, the negative binomial dispersion parameter. 
  name. See Roberts and Rosenthal (2009) for details.}

\item{n.batch}{the number of MCMC batches in each chain to run for the Adaptive MCMC 
  sampler. See Roberts and Rosenthal (2009) for details.}

\item{batch.length}{the length of each MCMC batch in each chain to run for the Adaptive 
  MCMC sampler. See Roberts and Rosenthal (2009) for details.}

\item{accept.rate}{target acceptance rate for Adaptive MCMC. Default is 
  0.43. See Roberts and Rosenthal (2009) for details.}

\item{family}{the distribution to use for the latent abundance process. Currently 
  supports \code{'NB'} (negative binomial) and \code{'Poisson'}.} 

\item{n.omp.threads}{a positive integer indicating the number of threads
  to use for SMP parallel processing. The package must be compiled for 
  OpenMP support. For most Intel-based machines, we recommend setting 
  \code{n.omp.threads} up to the number of hypterthreaded cores. Note, 
  \code{n.omp.threads} > 1 might not work on some systems. Currently only 
  relevant for spatial models.}

\item{verbose}{if \code{TRUE}, messages about data preparation, 
  model specification, and progress of the sampler are printed to the screen. 
  Otherwise, no messages are printed.}

\item{n.report}{the interval to report MCMC progress.}

\item{n.burn}{the number of samples out of the total \code{n.samples} to 
  discard as burn-in for each chain. By default, the first 10\% of samples is discarded.}

\item{n.thin}{the thinning interval for collection of MCMC samples. The
  thinning occurs after the \code{n.burn} samples are discarded. Default 
  value is set to 1.}

\item{n.chains}{the number of chains to run in sequence.}

\item{k.fold}{specifies the number of \emph{k} folds for cross-validation. 
  If not specified as an argument, then cross-validation is not performed
  and \code{k.fold.threads} and \code{k.fold.seed} are ignored. In \emph{k}-fold
  cross-validation, the data specified in \code{data} is randomly
  partitioned into \emph{k} equal sized subsamples. Of the \emph{k} subsamples, 
  \emph{k} - 1 subsamples are used to fit the model and the remaining \emph{k}
  samples are used for prediction. The cross-validation process is repeated 
  \emph{k} times (the folds). As a scoring rule, we use the model deviance 
  as described in Hooten and Hobbs (2015). Cross-validation is performed
  after the full model is fit using all the data. Cross-validation results
  are reported in the \code{k.fold.deviance} object in the return list.}

\item{k.fold.threads}{number of threads to use for cross-validation. If 
  \code{k.fold.threads > 1} parallel processing is accomplished using the 
  \pkg{foreach} and \pkg{doParallel} packages. Ignored if \code{k.fold}
  is not specified.} 

\item{k.fold.seed}{seed used to split data set into \code{k.fold} parts
  for k-fold cross-validation. Ignored if \code{k.fold} is not specified.}

\item{k.fold.only}{logical value indicating whether to only perform
  k-fold cross-validation. Setting this to \code{TRUE} will only return
  the k-fold deviance.}

\item{...}{currently no additional arguments}
}

\note{
 Some of the underlying code used for generating random numbers from the
 Polya-Gamma distribution is taken from the \pkg{pgdraw} package written
 by Daniel F. Schmidt and Enes Makalic. Their code implements Algorithm
 6 in PhD thesis of Jesse Bennett Windle (2013) \url{https://repositories.lib.utexas.edu/handle/2152/21842}.
}

\references{

  Bates, Douglas, Martin Maechler, Ben Bolker, Steve Walker (2015).
  Fitting Linear Mixed-Effects Models Using lme4. Journal of
  Statistical Software, 67(1), 1-48. \doi{10.18637/jss.v067.i01}.

  Hooten, M. B., and Hobbs, N. T. (2015). A guide to Bayesian model 
  selection for ecologists. Ecological monographs, 85(1), 3-28.
  
  Polson, N.G., J.G. Scott, and J. Windle. (2013) Bayesian Inference for
  Logistic Models Using Polya-Gamma Latent Variables. 
  \emph{Journal of the American Statistical Association}, 108:1339-1349.

  Royle, J. A. (2004). N???mixture models for estimating population size 
  from spatially replicated counts. Biometrics, 60(1), 108-115.
}

\author{
  Jeffrey W. Doser \email{doserjef@msu.edu}, \cr
  Andrew O. Finley \email{finleya@msu.edu}
}

\value{
  An object of class \code{NMix} that is a list comprised of: 

  \item{beta.samples}{a \code{coda} object of posterior samples
    for the abundance regression coefficients.}

  \item{alpha.samples}{a \code{coda} object of posterior samples
    for the detection regression coefficients.}
  
  \item{kappa.samples}{a \code{coda} object of posterior samples
    for the abundance dispersion parameter. Only included when
    \code{family = 'NB'}.}

  \item{N.samples}{a \code{coda} object of posterior samples 
    for the latent abundance values}

  \item{mu.samples}{a \code{coda} object of posterior samples
    for the latent expected abundance values}

  \item{sigma.sq.mu.samples}{a \code{coda} object of posterior samples
    for variances of random intercepts included in the abundance portion
    of the model. Only included if random intercepts are specified in 
    \code{abund.formula}.}

  \item{sigma.sq.p.samples}{a \code{coda} object of posterior samples
    for variances of random intercpets included in the detection portion 
    of the model. Only included if random intercepts are specified in 
    \code{det.formula}.}

  \item{beta.star.samples}{a \code{coda} object of posterior samples
    for the abundance random effects. Only included if random intercepts
    are specified in \code{abund.formula}.}

  \item{alpha.star.samples}{a \code{coda} object of posterior samples
    for the detection random effects. Only included if random intercepts 
    are specified in \code{det.formula}.}

  \item{like.samples}{a \code{coda} object of posterior samples
    for the likelihood value associated with each site. Used for calculating
    WAIC.}

  \item{rhat}{a list of Gelman-Rubin diagnostic values for some of the model
    parameters.}

  \item{ESS}{a list of effective sample sizes for some of the model parameters.}

  \item{run.time}{execution time reported using \code{proc.time()}.}

  \item{k.fold.deviance}{scoring rule (deviance) from k-fold cross-validation. 
    Only included if \code{k.fold} is specified in function call.}

  The return object will include additional objects used for 
  subsequent prediction and/or model fit evaluation. Note that detection
  probability estimated values are not included in the model object, but can be 
  extracted using \code{fitted()}. 

}

\examples{
set.seed(1010)
J.x <- 10
J.y <- 10
J <- J.x * J.y
n.rep <- sample(3, J, replace = TRUE)
beta <- c(0, -1.5)
p.abund <- length(beta)
alpha <- c(0.5, 1.2, -0.5)
p.det <- length(alpha)
mu.RE <- list()
p.RE <- list()
phi <- 3/.6
sigma.sq <- 2
kappa <- 0.3
sp <- FALSE 
cov.model <- 'exponential'
dist <- 'NB'
dat <- simNMix(J.x = J.x, J.y = J.y, n.rep = n.rep, beta = beta, alpha = alpha,
	       kappa = kappa, mu.RE = mu.RE, p.RE = p.RE, sp = sp, 
               phi = phi, sigma.sq = sigma.sq, cov.model = cov.model, 
               family = 'NB')

y <- dat$y
X <- dat$X
X.p <- dat$X.p

abund.covs <- X
colnames(abund.covs) <- c('int', 'abund.cov.1')

det.covs <- list(det.cov.1 = X.p[, , 2], 
		 det.cov.2 = X.p[, , 3])

data.list <- list(y = y, 
		  abund.covs = abund.covs,
		  det.covs = det.covs)

# Priors
prior.list <- list(beta.normal = list(mean = rep(0, p.abund), 
				      var = rep(100, p.abund)),
		   alpha.normal = list(mean = rep(0, p.det),
			               var = rep(2.72, p.det)), 
                   kappa.unif = c(0, 10)) 
# Starting values
inits.list <- list(alpha = 0,
		   beta = 0,
		   kappa = kappa, 
		   N = apply(y, 1, max, na.rm = TRUE))


tuning <- 0.5
n.batch <- 4
batch.length <- 25
n.burn <- 50
n.thin <- 1
n.chains <- 1

out <- NMix(abund.formula = ~ abund.cov.1,
	    det.formula = ~ det.cov.1 + det.cov.2, 
	    data = data.list, 
	    n.batch = n.batch, 
	    batch.length = batch.length, 
	    inits = inits.list, 
	    priors = prior.list, 
	    accept.rate = 0.43, 
	    n.omp.threads = 1, 
	    verbose = TRUE, 
	    n.report = 1,
	    n.burn = n.burn,
	    n.thin = n.thin,
	    n.chains = n.chains) 
}
