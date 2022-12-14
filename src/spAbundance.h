#include <R.h>
#include <Rinternals.h>

extern "C" {

  SEXP NMix(SEXP y_r, SEXP X_r, SEXP Xp_r, SEXP XRE_r, SEXP XpRE_r, 
            SEXP XRandom_r, SEXP XpRandom_r, SEXP yMax_r,
            SEXP consts_r, SEXP K_r, SEXP nAbundRELong_r, SEXP nDetRELong_r,
            SEXP betaStarting_r, SEXP alphaStarting_r, SEXP kappaStarting_r,
            SEXP sigmaSqMuStarting_r, SEXP sigmaSqPStarting_r,
            SEXP betaStarStarting_r, SEXP alphaStarStarting_r, SEXP NStarting_r,
            SEXP NLongIndx_r, SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
	    SEXP alphaStarIndx_r, SEXP alphaLevelIndx_r,
	    SEXP muBeta_r, SEXP SigmaBeta_r, 
	    SEXP muAlpha_r, SEXP SigmaAlpha_r, 
            SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, 
            SEXP sigmaSqPA_r, SEXP sigmaSqPB_r, 
	    SEXP kappaA_r, SEXP kappaB_r, SEXP tuning_r,
	    SEXP nBatch_r, SEXP batchLength_r, SEXP acceptRate_r, SEXP nThreads_r, 
            SEXP verbose_r, SEXP nReport_r, SEXP samplesInfo_r,
	    SEXP chainInfo_r, SEXP family_r);

  SEXP spNMixNNGP(SEXP y_r, SEXP X_r, SEXP Xp_r, SEXP coords_r, SEXP XRE_r, SEXP XpRE_r, 
		  SEXP XRandom_r, SEXP XpRandom_r, SEXP yMax_r,
                  SEXP consts_r, SEXP nAbundRELong_r, SEXP nDetRELong_r,
                  SEXP m_r, SEXP nnIndx_r, 
                  SEXP nnIndxLU_r, SEXP uIndx_r, SEXP uIndxLU_r, SEXP uiIndx_r,
                  SEXP betaStarting_r, SEXP alphaStarting_r, SEXP kappaStarting_r,
                  SEXP sigmaSqMuStarting_r, SEXP sigmaSqPStarting_r,
                  SEXP betaStarStarting_r, SEXP alphaStarStarting_r, SEXP NStarting_r,
		  SEXP wStarting_r, SEXP phiStarting_r, SEXP sigmaSqStarting_r, SEXP nuStarting_r,
                  SEXP NLongIndx_r, SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
	          SEXP alphaStarIndx_r, SEXP alphaLevelIndx_r,
	          SEXP muBeta_r, SEXP SigmaBeta_r, 
	          SEXP muAlpha_r, SEXP SigmaAlpha_r, 
		  SEXP phiA_r, SEXP phiB_r, SEXP sigmaSqA_r, SEXP sigmaSqB_r,
		  SEXP nuA_r, SEXP nuB_r, SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, 
                  SEXP sigmaSqPA_r, SEXP sigmaSqPB_r, 
	          SEXP kappaA_r, SEXP kappaB_r, SEXP tuning_r, SEXP covModel_r,
	          SEXP nBatch_r, SEXP batchLength_r, SEXP acceptRate_r, SEXP nThreads_r, 
                  SEXP verbose_r, SEXP nReport_r, SEXP samplesInfo_r,
	          SEXP chainInfo_r, SEXP sigmaSqIG_r, SEXP family_r);

  SEXP spNMixNNGPPredict(SEXP coords_r, SEXP J_r, SEXP family_r,
		         SEXP pAbund_r, SEXP m_r, SEXP X0_r, SEXP coords0_r, 
			 SEXP J0_r, SEXP nnIndx0_r, SEXP betaSamples_r, 
			 SEXP thetaSamples_r, SEXP kappaSamples_r, SEXP wSamples_r, 
			 SEXP betaStarSiteSamples_r, SEXP nSamples_r, 
			 SEXP covModel_r, SEXP nThreads_r, SEXP verbose_r, 
			 SEXP nReport_r);

  SEXP abund(SEXP y_r, SEXP X_r, SEXP XRE_r, SEXP XRandom_r,
             SEXP consts_r, SEXP K_r, SEXP nAbundRELong_r, 
             SEXP betaStarting_r, SEXP kappaStarting_r, 
	     SEXP sigmaSqMuStarting_r, SEXP betaStarStarting_r, 
             SEXP siteIndx_r, SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
	     SEXP muBeta_r, SEXP SigmaBeta_r, 
	     SEXP kappaA_r, SEXP kappaB_r, SEXP sigmaSqMuA_r, 
	     SEXP sigmaSqMuB_r, SEXP tuning_r,
	     SEXP nBatch_r, SEXP batchLength_r, SEXP acceptRate_r, SEXP nThreads_r, 
             SEXP verbose_r, SEXP nReport_r, SEXP samplesInfo_r,
	     SEXP chainInfo_r, SEXP family_r);

  SEXP spAbundNNGP(SEXP y_r, SEXP X_r, SEXP coords_r, SEXP XRE_r, 
                   SEXP XRandom_r, SEXP consts_r, SEXP nAbundRELong_r, 
                   SEXP m_r, SEXP nnIndx_r, 
                   SEXP nnIndxLU_r, SEXP uIndx_r, SEXP uIndxLU_r, SEXP uiIndx_r,
                   SEXP betaStarting_r, SEXP kappaStarting_r,
                   SEXP sigmaSqMuStarting_r, SEXP betaStarStarting_r, 
                   SEXP wStarting_r, SEXP phiStarting_r, SEXP sigmaSqStarting_r, 
                   SEXP nuStarting_r,
                   SEXP siteIndx_r, SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
                   SEXP muBeta_r, SEXP SigmaBeta_r, 
		   SEXP kappaA_r, SEXP kappaB_r,
		   SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, 
                   SEXP phiA_r, SEXP phiB_r, 
                   SEXP sigmaSqA_r, SEXP sigmaSqB_r, SEXP nuA_r, SEXP nuB_r, SEXP tuning_r,
                   SEXP covModel_r,
                   SEXP nBatch_r, SEXP batchLength_r, SEXP acceptRate_r, SEXP nThreads_r, 
                   SEXP verbose_r, SEXP nReport_r, SEXP samplesInfo_r,
                   SEXP chainInfo_r, SEXP sigmaSqIG_r, SEXP family_r);

  SEXP spAbundNNGPPredict(SEXP coords_r, SEXP J_r, SEXP nObs_r, 
		          SEXP pAbund_r, SEXP m_r, SEXP X0_r, SEXP coords0_r, 
			  SEXP J0_r, SEXP nObs0_r, 
			  SEXP sitesLink_r, SEXP sites0Sampled_r, SEXP sites0_r,
			  SEXP nnIndx0_r, SEXP betaSamples_r, 
			  SEXP thetaSamples_r, SEXP wSamples_r, 
			  SEXP betaStarSiteSamples_r, SEXP kappaSamples_r, SEXP nSamples_r, 
			  SEXP covModel_r, SEXP nThreads_r, SEXP verbose_r, 
			  SEXP nReport_r, SEXP family_r);

  SEXP msAbund(SEXP y_r, SEXP X_r, SEXP XRE_r, SEXP XRandom_r, 
               SEXP consts_r, SEXP nAbundRELong_r, 
               SEXP betaStarting_r, SEXP kappaStarting_r,  
               SEXP betaCommStarting_r, SEXP tauSqBetaStarting_r, 
               SEXP sigmaSqMuStarting_r, SEXP betaStarStarting_r,  
               SEXP siteIndx_r, SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
               SEXP muBetaComm_r, SEXP SigmaBetaComm_r, SEXP kappaA_r, 
               SEXP kappaB_r, SEXP tauSqBetaA_r, SEXP tauSqBetaB_r, 
               SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, SEXP tuning_r,  
               SEXP nBatch_r, SEXP batchLength_r, SEXP acceptRate_r,
               SEXP nThreads_r, SEXP verbose_r, SEXP nReport_r, 
               SEXP samplesInfo_r, SEXP chainInfo_r, SEXP family_r);

  SEXP sfMsAbundNNGP(SEXP y_r, SEXP X_r, SEXP coords_r, SEXP XRE_r, SEXP XRandom_r,
	            SEXP consts_r, SEXP nAbundRELong_r, SEXP m_r, SEXP nnIndx_r, 
		    SEXP nnIndxLU_r, SEXP uIndx_r, SEXP uIndxLU_r, SEXP uiIndx_r,
	            SEXP betaStarting_r, SEXP kappaStarting_r, SEXP betaCommStarting_r, 
		    SEXP tauSqBetaStarting_r, SEXP phiStarting_r, 
		    SEXP lambdaStarting_r, SEXP nuStarting_r, SEXP wStarting_r,
	            SEXP sigmaSqMuStarting_r, SEXP betaStarStarting_r,  
	            SEXP siteIndx_r, SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
	            SEXP muBetaComm_r, SEXP SigmaBetaComm_r, SEXP kappaA_r, 
	            SEXP kappaB_r, SEXP tauSqBetaA_r, SEXP tauSqBetaB_r, 
		    SEXP phiA_r, SEXP phiB_r, SEXP nuA_r, SEXP nuB_r,
	            SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, 
	            SEXP tuning_r, SEXP covModel_r, 
		    SEXP nBatch_r, SEXP batchLength_r, SEXP acceptRate_r,
	            SEXP nThreads_r, SEXP verbose_r, SEXP nReport_r, 
	            SEXP samplesInfo_r, SEXP chainInfo_r, SEXP family_r);

  SEXP waicAbund(SEXP J_r, SEXP K_r, SEXP dist_r, SEXP modelType_r, SEXP y_r,
                 SEXP nSamples_r, SEXP NSamples_r, SEXP kappaSamples_r, 
                 SEXP muSamples_r, SEXP pSamples_r, SEXP NMax_r, SEXP KMax_r, 
		 SEXP yMax_r);

}
