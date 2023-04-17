#define USE_FC_LEN_T
#include <string>
#include "util.h"
#include "rpg.h"

#ifdef _OPENMP
#include <omp.h>
#endif

#include <R.h>
#include <Rmath.h>
#include <Rinternals.h>
#include <R_ext/Linpack.h>
#include <R_ext/Lapack.h>
#include <R_ext/BLAS.h>
#ifndef FCONE
# define FCONE
#endif

extern "C" {
  SEXP waicAbund(SEXP J_r, SEXP K_r, SEXP dist_r, SEXP modelType_r, SEXP y_r,
                 SEXP nSamples_r, SEXP NSamples_r, SEXP epsilonSamples_r, 
                 SEXP muSamples_r, SEXP pSamples_r, SEXP NMax_r, SEXP KMax_r, 
		 SEXP yMax_r) {

    /**********************************************************************
     * Initial constants
     * *******************************************************************/
    int i, g, t, j, k, s, r, l, info, nProtect=0;
    const int inc = 1;
    /**********************************************************************
     * Get inputs
     *********************************************************************/
    int J = INTEGER(J_r)[0];
    int *K = INTEGER(K_r);
    int dist = INTEGER(dist_r)[0];
    int modelType = INTEGER(modelType_r)[0];
    double *y = REAL(y_r);
    int nSamples = INTEGER(nSamples_r)[0]; 
    double *NSamples = REAL(NSamples_r);
    double *epsilonSamples = REAL(epsilonSamples_r);
    double *muSamples = REAL(muSamples_r);
    double *pSamples = REAL(pSamples_r);
    int *NMax = INTEGER(NMax_r);
    int KMax = INTEGER(KMax_r)[0];
    int *yMax = INTEGER(yMax_r);

    /**********************************************************************
     * Return stuff
     *********************************************************************/
    SEXP likeSamples_r; 
    PROTECT(likeSamples_r = allocMatrix(REALSXP, J, nSamples)); nProtect++; 

    /**********************************************************************
     * Other set up
     *********************************************************************/
    double *like = (double *) R_alloc(J, sizeof(double)); zeros(like, J);
    double tmp_0 = 0.0; 
    double yProd = 1.0;
    int JnSamples = J * nSamples;


    /**********************************************************************
     * Calculate WAIC
     *********************************************************************/
    GetRNGstate(); 
    /**********************************
     * N-mixture models 
     **********************************/
    if (modelType == 0) {
      for (i = 0; i < nSamples; i++) {
        // Rprintf("Sample: %i\n", i);
        zeros(like, J);
        for (j = 0; j < J; j++) {
          for (t = yMax[j]; t < NMax[j]; t++) {
            yProd = 1.0;
            for (k = 0; k < K[j]; k++) {
              // Rprintf("pCurr[%i]: %f\n",             
              yProd *= dbinom(y[k * J + j], t, pSamples[k * JnSamples + j * nSamples + i], 0);
            } // k (replicate)
            if (dist == 1) {
              tmp_0 = dpois(t, 
			    muSamples[j * nSamples + i] * epsilonSamples[j * nSamples + i], 
			    0);
            } else {
              tmp_0 = dpois(t, muSamples[j * nSamples + i], 0);
            }
            like[j] += tmp_0 * yProd;
          } // t (NMax)
          like[j] = like[j];
        } // j (site)
        F77_NAME(dcopy)(&J, like, &inc, &REAL(likeSamples_r)[i*J], &inc);
        R_CheckUserInterrupt();
      } // i (nSamples)
    }
    /**********************************
     * Distance sampling
     **********************************/
    if (modelType == 1) {
      for (i = 0; i < nSamples; i++) {
        zeros(like, J);
        for (j = 0; j < J; j++) {
          for (t = yMax[j]; t < NMax[j]; t++) {
            yProd = 0.0;
            for (k = 0; k < K[j]; k++) {
	      yProd -= lgammafn(y[k * J + j] + 1.0); 
	      yProd += log(pSamples[k * JnSamples + j * nSamples + i]) * y[k * J + j];
            } // k (replicate)
	    yProd += ((t - yMax[j]) * log(pSamples[K[j] * JnSamples + j * nSamples + i])) +
                     lgammafn(t + 1.0) - lgammafn(t - yMax[j] + 1.0);
            if (dist == 1) {
              tmp_0 = dpois(t, 
			    muSamples[j * nSamples + i] * epsilonSamples[j * nSamples + i], 
			    0);
            } else {
              tmp_0 = dpois(t, muSamples[j * nSamples + i], 0);
            }
            like[j] += tmp_0 * exp(yProd);
          } // t (NMax)
          like[j] = like[j];
        } // j (site)
        F77_NAME(dcopy)(&J, like, &inc, &REAL(likeSamples_r)[i*J], &inc);
        R_CheckUserInterrupt();
      } // i (nSamples)
    }
    PutRNGstate();

    SEXP result_r, resultName_r;
    int nResultListObjs = 1;

    PROTECT(result_r = allocVector(VECSXP, nResultListObjs)); nProtect++;
    PROTECT(resultName_r = allocVector(VECSXP, nResultListObjs)); nProtect++;

    // Setting the components of the output list.
    SET_VECTOR_ELT(result_r, 0, likeSamples_r);

    SET_VECTOR_ELT(resultName_r, 0, mkChar("like.samples")); 
   
    namesgets(result_r, resultName_r);
    
    UNPROTECT(nProtect);
    
    return(result_r);

  } // (waicAbund)	  
} // (extern C)
