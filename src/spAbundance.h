#include <R.h>
#include <Rinternals.h>

extern "C" {

  SEXP abund(SEXP y_r, SEXP X_r, SEXP XRE_r, SEXP XRandom_r,
             SEXP consts_r,SEXP nAbundRELong_r, 
             SEXP betaStarting_r, SEXP kappaStarting_r, 
	     SEXP sigmaSqMuStarting_r, SEXP betaStarStarting_r, 
             SEXP siteIndx_r, SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
	     SEXP muBeta_r, SEXP SigmaBeta_r, 
	     SEXP kappaA_r, SEXP kappaB_r, SEXP sigmaSqMuA_r, 
	     SEXP sigmaSqMuB_r, SEXP tuning_r,
	     SEXP nBatch_r, SEXP batchLength_r, SEXP acceptRate_r, SEXP nThreads_r, 
             SEXP verbose_r, SEXP nReport_r, SEXP samplesInfo_r,
	     SEXP chainInfo_r, SEXP family_r, SEXP offset_r);

  SEXP abundGaussian(SEXP y_r, SEXP X_r, SEXP XRE_r, SEXP XRandom_r,
               SEXP consts_r, SEXP nRELong_r, 
               SEXP betaStarting_r, SEXP tauSqStarting_r, SEXP sigmaSqMuStarting_r,
               SEXP betaStarStarting_r,  
               SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
               SEXP muBeta_r, SEXP SigmaBeta_r, 
	       SEXP tauSqA_r, SEXP tauSqB_r, 
               SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, SEXP nBatch_r, 
               SEXP batchLength_r, SEXP acceptRate_r, SEXP nThreads_r, SEXP verbose_r, 
               SEXP nReport_r, SEXP samplesInfo_r, SEXP chainInfo_r);

  SEXP spAbundNNGP(SEXP y_r, SEXP X_r, SEXP coords_r, SEXP XRE_r, 
                   SEXP XRandom_r, SEXP consts_r, SEXP nAbundRELong_r, 
                   SEXP m_r, SEXP nnIndx_r, 
                   SEXP nnIndxLU_r, SEXP uIndx_r, SEXP uIndxLU_r,
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
                   SEXP chainInfo_r, SEXP sigmaSqIG_r, SEXP family_r, SEXP offset_r);

  SEXP spAbundGaussianNNGP(SEXP y_r, SEXP X_r, SEXP coords_r, SEXP XRE_r, SEXP XRandom_r,
                           SEXP consts_r, SEXP nRELong_r, SEXP m_r, SEXP nnIndx_r,
                           SEXP nnIndxLU_r, SEXP uIndx_r, SEXP uIndxLU_r, SEXP uiIndx_r,
                           SEXP betaStarting_r, SEXP tauSqStarting_r, SEXP sigmaSqMuStarting_r,
                           SEXP betaStarStarting_r,
                           SEXP wStarting_r, SEXP phiStarting_r,
                           SEXP sigmaSqStarting_r, SEXP nuStarting_r,
                           SEXP betaStarIndx_r, SEXP betaLevelIndx_r,
                           SEXP muBeta_r, SEXP SigmaBeta_r,
	                   SEXP tauSqA_r, SEXP tauSqB_r, SEXP phiA_r, SEXP phiB_r,
                           SEXP sigmaSqA_r, SEXP sigmaSqB_r, SEXP nuA_r, SEXP nuB_r,
                           SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r,
                           SEXP tuning_r, SEXP covModel_r, SEXP nBatch_r,
                           SEXP batchLength_r, SEXP acceptRate_r,
			   SEXP nThreads_r, SEXP verbose_r,
                           SEXP nReport_r, SEXP samplesInfo_r, SEXP chainInfo_r,
			   SEXP sigmaSqIG_r);

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
               SEXP samplesInfo_r, SEXP chainInfo_r, SEXP family_r, SEXP offset_r);

  SEXP msAbundGaussian(SEXP y_r, SEXP X_r, SEXP XRE_r,
                       SEXP XRandom_r, SEXP consts_r, SEXP nRELong_r, 
                       SEXP betaStarting_r, SEXP betaCommStarting_r,  
                       SEXP tauSqBetaStarting_r, SEXP tauSqStarting_r,
                       SEXP sigmaSqMuStarting_r, SEXP betaStarStarting_r, 
		       SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
                       SEXP muBetaComm_r, SEXP SigmaBetaComm_r, SEXP tauSqBetaA_r, 
                       SEXP tauSqBetaB_r, SEXP tauSqA_r, SEXP tauSqB_r,
		       SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, 
                       SEXP tuning_r, SEXP nBatch_r, SEXP batchLength_r, 
                       SEXP acceptRate_r, SEXP nThreads_r, 
                       SEXP verbose_r, SEXP nReport_r, 
                       SEXP samplesInfo_r, SEXP chainInfo_r,
                       SEXP z_r, SEXP family_r);

  SEXP lfMsAbund(SEXP y_r, SEXP X_r, SEXP XRE_r, SEXP XRandom_r,
	         SEXP consts_r, SEXP nAbundRELong_r, 
	         SEXP betaStarting_r, SEXP kappaStarting_r, SEXP betaCommStarting_r, 
		 SEXP tauSqBetaStarting_r, SEXP lambdaStarting_r, SEXP wStarting_r,
	         SEXP sigmaSqMuStarting_r, SEXP betaStarStarting_r,  
	         SEXP siteIndx_r, SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
	         SEXP muBetaComm_r, SEXP SigmaBetaComm_r, SEXP kappaA_r, 
	         SEXP kappaB_r, SEXP tauSqBetaA_r, SEXP tauSqBetaB_r, 
	         SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, SEXP tuning_r,  
		 SEXP nBatch_r, SEXP batchLength_r, SEXP acceptRate_r,
	         SEXP nThreads_r, SEXP verbose_r, SEXP nReport_r, 
	         SEXP samplesInfo_r, SEXP chainInfo_r, SEXP family_r, SEXP offset_r);

  SEXP lfMsAbundGaussian(SEXP y_r, SEXP X_r, SEXP XRE_r,
                       SEXP XRandom_r, SEXP consts_r, SEXP nRELong_r, 
                       SEXP betaStarting_r, SEXP betaCommStarting_r,  
                       SEXP tauSqBetaStarting_r, SEXP tauSqStarting_r,
		       SEXP lambdaStarting_r, SEXP wStarting_r,
                       SEXP sigmaSqMuStarting_r, SEXP betaStarStarting_r, 
		       SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
                       SEXP muBetaComm_r, SEXP SigmaBetaComm_r, SEXP tauSqBetaA_r, 
                       SEXP tauSqBetaB_r, SEXP tauSqA_r, SEXP tauSqB_r,
		       SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, 
                       SEXP tuning_r, SEXP nBatch_r, SEXP batchLength_r, 
                       SEXP acceptRate_r, SEXP nThreads_r, 
                       SEXP verbose_r, SEXP nReport_r, 
                       SEXP samplesInfo_r, SEXP chainInfo_r,
                       SEXP z_r, SEXP family_r);

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
	            SEXP samplesInfo_r, SEXP chainInfo_r, SEXP family_r, SEXP offset_r);

  SEXP sfMsAbundGaussianNNGP(SEXP y_r, SEXP X_r, SEXP coords_r, SEXP XRE_r,
                             SEXP XRandom_r, SEXP consts_r, SEXP nRELong_r, 
			     SEXP m_r, SEXP nnIndx_r, 
                             SEXP nnIndxLU_r, SEXP uIndx_r, SEXP uIndxLU_r, SEXP uiIndx_r, 
                             SEXP betaStarting_r, SEXP betaCommStarting_r,  
                             SEXP tauSqBetaStarting_r, SEXP tauSqStarting_r,
                             SEXP phiStarting_r, SEXP lambdaStarting_r, SEXP nuStarting_r, 
                             SEXP wStarting_r, SEXP sigmaSqMuStarting_r, 
                             SEXP betaStarStarting_r, SEXP betaStarIndx_r, 
			     SEXP betaLevelIndx_r, 
                             SEXP muBetaComm_r, SEXP SigmaBetaComm_r, SEXP tauSqBetaA_r, 
                             SEXP tauSqBetaB_r, SEXP tauSqA_r, SEXP tauSqB_r, SEXP phiA_r, 
                             SEXP phiB_r, SEXP nuA_r, SEXP nuB_r, 
                             SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, 
                             SEXP tuning_r, SEXP covModel_r,
			     SEXP nBatch_r, SEXP batchLength_r, 
                             SEXP acceptRate_r, SEXP nThreads_r, 
			     SEXP verbose_r, SEXP nReport_r, 
                             SEXP samplesInfo_r, SEXP chainInfo_r,
			     SEXP z_r, SEXP family_r);

  SEXP sfMsAbundNNGPPredict(SEXP coords_r, SEXP J_r, SEXP nObs_r, SEXP family_r, SEXP nSp_r, 
		            SEXP q_r, SEXP pAbund_r, SEXP m_r, SEXP X0_r, SEXP coords0_r, 
			    SEXP J0_r, SEXP nObs0_r, SEXP sitesLink_r, SEXP sites0Sampled_r, 
			    SEXP sites0_r, SEXP nnIndx0_r, SEXP betaSamples_r, 
			    SEXP thetaSamples_r, SEXP kappaSamples_r, SEXP lambdaSamples_r, 
			    SEXP wSamples_r, SEXP betaStarSiteSamples_r, 
			    SEXP nSamples_r, SEXP covModel_r, SEXP nThreads_r, SEXP verbose_r, 
			    SEXP nReport_r);

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
	    SEXP chainInfo_r, SEXP family_r, SEXP offset_r);

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
	          SEXP chainInfo_r, SEXP sigmaSqIG_r, SEXP family_r, SEXP offset_r);

  SEXP spNMixNNGPPredict(SEXP coords_r, SEXP J_r, SEXP family_r,
		         SEXP pAbund_r, SEXP m_r, SEXP X0_r, SEXP coords0_r, 
			 SEXP J0_r, SEXP nnIndx0_r, SEXP betaSamples_r, 
			 SEXP thetaSamples_r, SEXP kappaSamples_r, SEXP wSamples_r, 
			 SEXP betaStarSiteSamples_r, 
                         SEXP sitesLink_r, SEXP sites0Sampled_r, SEXP sites0_r,
			 SEXP nSamples_r, SEXP covModel_r, SEXP nThreads_r, SEXP verbose_r, 
			 SEXP nReport_r);

  SEXP msNMix(SEXP y_r, SEXP X_r, SEXP Xp_r, SEXP XRE_r, SEXP XpRE_r, 
              SEXP XRandom_r, SEXP XpRandom_r, SEXP yMax_r, 
	      SEXP consts_r, SEXP nAbundRELong_r, SEXP nDetRELong_r, 
	      SEXP betaStarting_r, SEXP alphaStarting_r, SEXP kappaStarting_r, SEXP NStarting_r, 
	      SEXP betaCommStarting_r, SEXP alphaCommStarting_r, 
	      SEXP tauSqBetaStarting_r, SEXP tauSqAlphaStarting_r, 
	      SEXP sigmaSqMuStarting_r, SEXP sigmaSqPStarting_r, 
	      SEXP betaStarStarting_r, SEXP alphaStarStarting_r, 
	      SEXP NLongIndx_r, SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
	      SEXP alphaStarIndx_r, SEXP alphaLevelIndx_r, 
	      SEXP muBetaComm_r, SEXP muAlphaComm_r, 
	      SEXP SigmaBetaComm_r, SEXP SigmaAlphaComm_r, SEXP kappaA_r, 
	      SEXP kappaB_r, SEXP tauSqBetaA_r, 
	      SEXP tauSqBetaB_r, SEXP tauSqAlphaA_r, SEXP tauSqAlphaB_r, 
	      SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, 
	      SEXP sigmaSqPA_r, SEXP sigmaSqPB_r, 
	      SEXP tuning_r, SEXP nBatch_r, SEXP batchLength_r, SEXP acceptRate_r,
	      SEXP nThreads_r, SEXP verbose_r, SEXP nReport_r, 
	      SEXP samplesInfo_r, SEXP chainInfo_r, SEXP family_r, SEXP offset_r);

  SEXP lfMsNMix(SEXP y_r, SEXP X_r, SEXP Xp_r, SEXP XRE_r, SEXP XpRE_r, 
                SEXP XRandom_r, SEXP XpRandom_r, SEXP yMax_r, 
	        SEXP consts_r, SEXP nAbundRELong_r, SEXP nDetRELong_r, 
	        SEXP betaStarting_r, SEXP alphaStarting_r, 
		SEXP kappaStarting_r, SEXP NStarting_r, 
	        SEXP betaCommStarting_r, SEXP alphaCommStarting_r, 
		SEXP lambdaStarting_r, SEXP wStarting_r,
	        SEXP tauSqBetaStarting_r, SEXP tauSqAlphaStarting_r, 
	        SEXP sigmaSqMuStarting_r, SEXP sigmaSqPStarting_r, 
	        SEXP betaStarStarting_r, SEXP alphaStarStarting_r, 
	        SEXP NLongIndx_r, SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
	        SEXP alphaStarIndx_r, SEXP alphaLevelIndx_r, 
	        SEXP muBetaComm_r, SEXP muAlphaComm_r, 
	        SEXP SigmaBetaComm_r, SEXP SigmaAlphaComm_r, SEXP kappaA_r, 
	        SEXP kappaB_r, SEXP tauSqBetaA_r, 
	        SEXP tauSqBetaB_r, SEXP tauSqAlphaA_r, SEXP tauSqAlphaB_r, 
	        SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, 
	        SEXP sigmaSqPA_r, SEXP sigmaSqPB_r, SEXP tuning_r, 
		SEXP nBatch_r, SEXP batchLength_r, SEXP acceptRate_r,
	        SEXP nThreads_r, SEXP verbose_r, SEXP nReport_r, 
	        SEXP samplesInfo_r, SEXP chainInfo_r, SEXP family_r, SEXP offset_r);

  SEXP sfMsNMixNNGP(SEXP y_r, SEXP X_r, SEXP Xp_r, SEXP coords_r, SEXP XRE_r, SEXP XpRE_r, 
                    SEXP XRandom_r, SEXP XpRandom_r, SEXP yMax_r, 
	            SEXP consts_r, SEXP nAbundRELong_r, SEXP nDetRELong_r, 
		    SEXP m_r, SEXP nnIndx_r, 
		    SEXP nnIndxLU_r, SEXP uIndx_r, SEXP uIndxLU_r, SEXP uiIndx_r, 
	            SEXP betaStarting_r, SEXP alphaStarting_r, SEXP kappaStarting_r, SEXP NStarting_r, 
	            SEXP betaCommStarting_r, SEXP alphaCommStarting_r, 
		    SEXP phiStarting_r, SEXP lambdaStarting_r, SEXP nuStarting_r, SEXP wStarting_r,
	            SEXP tauSqBetaStarting_r, SEXP tauSqAlphaStarting_r, 
	            SEXP sigmaSqMuStarting_r, SEXP sigmaSqPStarting_r, 
	            SEXP betaStarStarting_r, SEXP alphaStarStarting_r, 
	            SEXP NLongIndx_r, SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
	            SEXP alphaStarIndx_r, SEXP alphaLevelIndx_r, 
	            SEXP muBetaComm_r, SEXP muAlphaComm_r, 
	            SEXP SigmaBetaComm_r, SEXP SigmaAlphaComm_r, SEXP kappaA_r, 
	            SEXP kappaB_r, SEXP tauSqBetaA_r, 
	            SEXP tauSqBetaB_r, SEXP tauSqAlphaA_r, SEXP tauSqAlphaB_r, 
	            SEXP spatialPriors_r, SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, 
	            SEXP sigmaSqPA_r, SEXP sigmaSqPB_r, 
	            SEXP tuning_r, SEXP covModel_r, 
		    SEXP batchInfo_r, SEXP acceptRate_r, 
	            SEXP nThreads_r, SEXP verbose_r, SEXP nReport_r, 
	            SEXP samplesInfo_r, SEXP chainInfo_r, SEXP family_r, SEXP offset_r);

  SEXP sfMsNMixNNGPPredict(SEXP coords_r, SEXP J_r, SEXP family_r, SEXP nSp_r, SEXP q_r,
		           SEXP pAbund_r, SEXP m_r, SEXP X0_r, SEXP coords0_r, 
			   SEXP JStr_r, SEXP nnIndx0_r, SEXP betaSamples_r, 
			   SEXP thetaSamples_r, SEXP kappaSamples_r, SEXP lambdaSamples_r, 
			   SEXP wSamples_r, SEXP betaStarSiteSamples_r, 
			   SEXP nSamples_r, SEXP covModel_r, SEXP nThreads_r, SEXP verbose_r, 
			   SEXP nReport_r, SEXP sitesLink_r, SEXP sites0Sampled_r);

  SEXP DS(SEXP y_r, SEXP X_r, SEXP Xp_r, SEXP XRE_r, SEXP XpRE_r, 
          SEXP XRandom_r, SEXP XpRandom_r, SEXP yMax_r, SEXP offset_r,
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
          SEXP kappaA_r, SEXP kappaB_r, SEXP detModel_r, 
	  SEXP transect_r, SEXP distBreaks_r, SEXP tuning_r,
          SEXP nBatch_r, SEXP batchLength_r, SEXP acceptRate_r, SEXP nThreads_r, 
          SEXP verbose_r, SEXP nReport_r, SEXP samplesInfo_r,
          SEXP chainInfo_r, SEXP family_r);

  SEXP spDSNNGP(SEXP y_r, SEXP X_r, SEXP Xp_r, SEXP coords_r, SEXP XRE_r, SEXP XpRE_r, 
          SEXP XRandom_r, SEXP XpRandom_r, SEXP yMax_r, SEXP offset_r,
          SEXP consts_r, SEXP K_r, SEXP nAbundRELong_r, SEXP nDetRELong_r,
          SEXP m_r, SEXP nnIndx_r, 
          SEXP nnIndxLU_r, SEXP uIndx_r, SEXP uIndxLU_r, SEXP uiIndx_r,
          SEXP betaStarting_r, SEXP alphaStarting_r, SEXP kappaStarting_r,
          SEXP sigmaSqMuStarting_r, SEXP sigmaSqPStarting_r,
          SEXP betaStarStarting_r, SEXP alphaStarStarting_r, SEXP NStarting_r,
          SEXP wStarting_r, SEXP phiStarting_r, SEXP sigmaSqStarting_r, SEXP nuStarting_r,
          SEXP NLongIndx_r, SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
          SEXP alphaStarIndx_r, SEXP alphaLevelIndx_r,
          SEXP muBeta_r, SEXP SigmaBeta_r, 
          SEXP muAlpha_r, SEXP SigmaAlpha_r, SEXP spatialPriors_r,
          SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, 
          SEXP sigmaSqPA_r, SEXP sigmaSqPB_r, 
          SEXP kappaA_r, SEXP kappaB_r, SEXP detModel_r, 
	  SEXP transect_r, SEXP distBreaks_r, SEXP tuning_r, SEXP covModel_r,
          SEXP nBatch_r, SEXP batchLength_r, SEXP acceptRate_r, SEXP nThreads_r, 
          SEXP verbose_r, SEXP nReport_r, SEXP samplesInfo_r,
          SEXP chainInfo_r, SEXP sigmaSqIG_r, SEXP family_r);

  SEXP msDS(SEXP y_r, SEXP X_r, SEXP Xp_r, SEXP XRE_r, SEXP XpRE_r, 
            SEXP XRandom_r, SEXP XpRandom_r, SEXP yMax_r, SEXP offset_r,
            SEXP consts_r, SEXP K_r, SEXP nAbundRELong_r, SEXP nDetRELong_r,
            SEXP betaStarting_r, SEXP alphaStarting_r, SEXP kappaStarting_r,
            SEXP NStarting_r, SEXP betaCommStarting_r, SEXP alphaCommStarting_r,
	    SEXP tauSqBetaStarting_r, SEXP tauSqAlphaStarting_r,
            SEXP sigmaSqMuStarting_r, SEXP sigmaSqPStarting_r,
            SEXP betaStarStarting_r, SEXP alphaStarStarting_r, 
            SEXP NLongIndx_r, SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
            SEXP alphaStarIndx_r, SEXP alphaLevelIndx_r,
            SEXP muBetaComm_r, SEXP SigmaBetaComm_r, 
            SEXP muAlphaComm_r, SEXP SigmaAlphaComm_r, 
            SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, 
            SEXP sigmaSqPA_r, SEXP sigmaSqPB_r, 
            SEXP kappaA_r, SEXP kappaB_r, 
	    SEXP tauSqBetaA_r, SEXP tauSqBetaB_r, 
	    SEXP tauSqAlphaA_r, SEXP tauSqAlphaB_r, SEXP detModel_r, 
	    SEXP transect_r, SEXP distBreaks_r, SEXP tuning_r,
            SEXP nBatch_r, SEXP batchLength_r, SEXP acceptRate_r, SEXP nThreads_r, 
            SEXP verbose_r, SEXP nReport_r, SEXP samplesInfo_r,
            SEXP chainInfo_r, SEXP family_r);

  SEXP lfMsDS(SEXP y_r, SEXP X_r, SEXP Xp_r, SEXP XRE_r, SEXP XpRE_r, 
              SEXP XRandom_r, SEXP XpRandom_r, SEXP yMax_r, SEXP offset_r,
              SEXP consts_r, SEXP K_r, SEXP nAbundRELong_r, SEXP nDetRELong_r,
              SEXP betaStarting_r, SEXP alphaStarting_r, SEXP kappaStarting_r,
              SEXP NStarting_r, SEXP betaCommStarting_r, SEXP alphaCommStarting_r,
	      SEXP lambdaStarting_r, SEXP wStarting_r,
	      SEXP tauSqBetaStarting_r, SEXP tauSqAlphaStarting_r,
              SEXP sigmaSqMuStarting_r, SEXP sigmaSqPStarting_r,
              SEXP betaStarStarting_r, SEXP alphaStarStarting_r, 
              SEXP NLongIndx_r, SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
              SEXP alphaStarIndx_r, SEXP alphaLevelIndx_r,
              SEXP muBetaComm_r, SEXP SigmaBetaComm_r, 
              SEXP muAlphaComm_r, SEXP SigmaAlphaComm_r, 
              SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, 
              SEXP sigmaSqPA_r, SEXP sigmaSqPB_r, 
              SEXP kappaA_r, SEXP kappaB_r, 
	      SEXP tauSqBetaA_r, SEXP tauSqBetaB_r, 
	      SEXP tauSqAlphaA_r, SEXP tauSqAlphaB_r, SEXP detModel_r, 
	      SEXP transect_r, SEXP distBreaks_r, SEXP tuning_r,
              SEXP nBatch_r, SEXP batchLength_r, SEXP acceptRate_r, SEXP nThreads_r, 
              SEXP verbose_r, SEXP nReport_r, SEXP samplesInfo_r,
              SEXP chainInfo_r, SEXP family_r);

  SEXP sfMsDSNNGP(SEXP y_r, SEXP X_r, SEXP Xp_r, SEXP coords_r, SEXP XRE_r, SEXP XpRE_r, 
                  SEXP XRandom_r, SEXP XpRandom_r, SEXP yMax_r, SEXP offset_r,
                  SEXP consts_r, SEXP nAbundRELong_r, SEXP nDetRELong_r,
                  SEXP nnIndx_r, SEXP nnIndxLU_r, SEXP uIndx_r, SEXP uIndxLU_r, SEXP uiIndx_r, 
                  SEXP betaStarting_r, SEXP alphaStarting_r, SEXP kappaStarting_r,
                  SEXP NStarting_r, SEXP betaCommStarting_r, SEXP alphaCommStarting_r,
	          SEXP phiStarting_r, SEXP lambdaStarting_r, SEXP nuStarting_r, SEXP wStarting_r,
	          SEXP tauSqBetaStarting_r, SEXP tauSqAlphaStarting_r,
                  SEXP sigmaSqMuStarting_r, SEXP sigmaSqPStarting_r,
                  SEXP betaStarStarting_r, SEXP alphaStarStarting_r, 
                  SEXP NLongIndx_r, SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
                  SEXP alphaStarIndx_r, SEXP alphaLevelIndx_r,
                  SEXP muBetaComm_r, SEXP SigmaBetaComm_r, 
                  SEXP muAlphaComm_r, SEXP SigmaAlphaComm_r, 
                  SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, 
                  SEXP sigmaSqPA_r, SEXP sigmaSqPB_r, 
                  SEXP kappaA_r, SEXP kappaB_r, 
	          SEXP tauSqBetaA_r, SEXP tauSqBetaB_r, 
	          SEXP tauSqAlphaA_r, SEXP tauSqAlphaB_r, SEXP spatialPriors_r, 
	          SEXP transect_r, SEXP distBreaks_r, SEXP tuning_r, 
                  SEXP nBatch_r, SEXP batchLength_r, SEXP acceptRate_r, SEXP nThreads_r, 
                  SEXP verbose_r, SEXP nReport_r, SEXP samplesInfo_r,
                  SEXP chainInfo_r);

  SEXP waicAbund(SEXP J_r, SEXP yNA_r, SEXP dist_r, SEXP modelType_r, SEXP y_r,
                 SEXP nSamples_r, SEXP NSamples_r, SEXP kappaSamples_r, 
                 SEXP muSamples_r, SEXP pSamples_r, SEXP NMax_r, SEXP KMax_r, 
		 SEXP yMax_r);

  SEXP checkAlphaDS(SEXP y_r, SEXP Xp_r, SEXP XpRE_r, 
                    SEXP XpRandom_r, SEXP yMax_r, 
                    SEXP consts_r, SEXP K_r, SEXP nDetRELong_r,
                    SEXP alphaStarting_r, 
                    SEXP sigmaSqPStarting_r,
                    SEXP alphaStarStarting_r, SEXP NStarting_r,
                    SEXP NLongIndx_r,  
                    SEXP alphaStarIndx_r, SEXP alphaLevelIndx_r,
                    SEXP muAlpha_r, SEXP SigmaAlpha_r, 
                    SEXP detModel_r, 
	            SEXP transect_r, SEXP distBreaks_r);

  SEXP checkMSAlphaDS(SEXP y_r, SEXP Xp_r,  SEXP XpRE_r, 
                      SEXP XpRandom_r, SEXP yMax_r, 
                      SEXP consts_r, SEXP K_r, 
                      SEXP alphaStarting_r, 
                      SEXP alphaCommStarting_r,
	              SEXP tauSqAlphaStarting_r,
                      SEXP sigmaSqPStarting_r,
                      SEXP alphaStarStarting_r, SEXP NStarting_r,
                      SEXP alphaStarIndx_r, SEXP alphaLevelIndx_r,
                      SEXP muAlphaComm_r, SEXP SigmaAlphaComm_r, 
	              SEXP detModel_r, 
	              SEXP transect_r, SEXP distBreaks_r);

  SEXP svcAbundNNGP(SEXP y_r, SEXP X_r, SEXP Xw_r, SEXP coords_r, SEXP XRE_r, SEXP XRandom_r,
               SEXP consts_r, SEXP nRELong_r, SEXP m_r, SEXP nnIndx_r, 
               SEXP nnIndxLU_r, SEXP uIndx_r, SEXP uIndxLU_r, SEXP uiIndx_r,
               SEXP betaStarting_r, SEXP tauSqStarting_r, SEXP sigmaSqMuStarting_r,
               SEXP betaStarStarting_r,  
               SEXP wStarting_r, SEXP phiStarting_r, 
               SEXP sigmaSqStarting_r, SEXP nuStarting_r, 
               SEXP betaStarIndx_r, SEXP betaLevelIndx_r, 
               SEXP muBeta_r, SEXP SigmaBeta_r, 
	       SEXP tauSqA_r, SEXP tauSqB_r, SEXP phiA_r, SEXP phiB_r, 
               SEXP sigmaSqA_r, SEXP sigmaSqB_r, SEXP nuA_r, SEXP nuB_r, 
               SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, 
               SEXP tuning_r, SEXP covModel_r, SEXP nBatch_r, 
               SEXP batchLength_r, SEXP acceptRate_r, SEXP nThreads_r, SEXP verbose_r, 
               SEXP nReport_r, SEXP samplesInfo_r, SEXP chainInfo_r);

  SEXP svcAbundNNGPPredict(SEXP coords_r, SEXP J_r, SEXP family_r, 
		           SEXP pAbund_r, SEXP pTilde_r, 
		           SEXP m_r, SEXP X0_r, SEXP Xw0_r, SEXP coords0_r, 
			   SEXP J0_r, SEXP nnIndx0_r, SEXP betaSamples_r, 
			   SEXP thetaSamples_r, SEXP tauSqSamples_r, SEXP wSamples_r, 
			   SEXP betaStarSiteSamples_r, SEXP sitesLink_r, 
			   SEXP sites0Sampled_r, SEXP sites0_r, SEXP nSamples_r, 
			   SEXP covModel_r, SEXP nThreads_r, SEXP verbose_r, 
			   SEXP nReport_r, SEXP z0Samples_r);

  SEXP svcMsAbundGaussianNNGP(SEXP y_r, SEXP X_r, SEXP Xw_r, SEXP coords_r, SEXP XRE_r,
                              SEXP XRandom_r, SEXP consts_r, SEXP nRELong_r, 
			      SEXP m_r, SEXP nnIndx_r, 
                              SEXP nnIndxLU_r, SEXP uIndx_r, SEXP uIndxLU_r, SEXP uiIndx_r, 
                              SEXP betaStarting_r, SEXP betaCommStarting_r,  
                              SEXP tauSqBetaStarting_r, SEXP tauSqStarting_r,
                              SEXP phiStarting_r, SEXP lambdaStarting_r, SEXP nuStarting_r, 
                              SEXP wStarting_r, SEXP sigmaSqMuStarting_r, 
                              SEXP betaStarStarting_r, SEXP betaStarIndx_r, 
			      SEXP betaLevelIndx_r, 
                              SEXP muBetaComm_r, SEXP SigmaBetaComm_r, SEXP tauSqBetaA_r, 
                              SEXP tauSqBetaB_r, SEXP tauSqA_r, SEXP tauSqB_r, SEXP phiA_r, 
                              SEXP phiB_r, SEXP nuA_r, SEXP nuB_r, 
                              SEXP sigmaSqMuA_r, SEXP sigmaSqMuB_r, 
                              SEXP tuning_r, SEXP covModel_r,
			      SEXP nBatch_r, SEXP batchLength_r, 
                              SEXP acceptRate_r, SEXP nThreads_r, 
			      SEXP verbose_r, SEXP nReport_r, 
                              SEXP samplesInfo_r, SEXP chainInfo_r,
			      SEXP z_r, SEXP family_r);

  SEXP svcMsAbundGaussianNNGPPredict(SEXP coords_r, SEXP J_r, SEXP family_r, 
		                     SEXP N_r, SEXP q_r, SEXP p_r, 
				     SEXP pTilde_r, SEXP m_r, 
                                     SEXP X0_r, SEXP Xw0_r, SEXP coords0_r, 
			             SEXP J0_r, SEXP sitesLink_r, 
				     SEXP sites0Sampled_r, 
				     SEXP nnIndx0_r, SEXP betaSamples_r, 
			             SEXP thetaSamples_r, SEXP tauSqSamples_r, 
				     SEXP lambdaSamples_r, 
			             SEXP wSamples_r, SEXP betaStarSiteSamples_r, 
			             SEXP nSamples_r, SEXP covModel_r, 
			             SEXP nThreads_r, SEXP verbose_r, SEXP nReport_r, 
				     SEXP z0Samples_r);
}
