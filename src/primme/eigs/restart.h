/*******************************************************************************
 * Copyright (c) 2018, College of William & Mary
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the College of William & Mary nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COLLEGE OF WILLIAM & MARY BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * PRIMME: https://github.com/primme/primme
 * Contact: Andreas Stathopoulos, a n d r e a s _at_ c s . w m . e d u
 *******************************************************************************
 *   NOTE: THIS FILE IS AUTOMATICALLY GENERATED. PLEASE DON'T MODIFY
 ******************************************************************************/


#ifndef restart_H
#define restart_H
#if !defined(CHECK_TEMPLATE) && !defined(restart_Sprimme)
#  define restart_Sprimme CONCAT(restart_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(restart_Rprimme)
#  define restart_Rprimme CONCAT(restart_,REAL_SUF)
#endif
int restart_dprimme(double *V, double *W, PRIMME_INT nLocal, int basisSize,
       PRIMME_INT ldV, double *hVals, double *hSVals, int *flags, int *iev,
       int *ievSize, double *blockNorms, double *evecs, PRIMME_INT ldevecs,
       int *evecsPerm, double *evals, double *resNorms, double *evecsHat,
       PRIMME_INT ldevecsHat, double *M, int ldM, double *UDU, int ldUDU,
       int *ipivot, int *numConverged, int *numLocked, int *lockedFlags,
       int *numConvergedStored, double *previousHVecs, int *numPrevRetained,
       int ldpreviousHVecs, int numGuesses, double *prevRitzVals,
       int *numPrevRitzVals, double *H, int ldH, double *VtBV, int ldVtBV,
       double *Q, PRIMME_INT ldQ, double *R, int ldR, double* QtV, int ldQtV,
       double *hU, int ldhU, int newldhU, double *hVecs, int ldhVecs,
       int newldhVecs, int *restartSizeOutput, int *targetShiftIndex,
       int *numArbitraryVecs, double *hVecsRot, int ldhVecsRot,
       int *restartsSinceReset, int *reset, double machEps, double *rwork,
       size_t *rworkSize, int *iwork, int iworkSize, primme_params *primme);
#if !defined(CHECK_TEMPLATE) && !defined(Num_reset_update_VWXR_Sprimme)
#  define Num_reset_update_VWXR_Sprimme CONCAT(Num_reset_update_VWXR_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(Num_reset_update_VWXR_Rprimme)
#  define Num_reset_update_VWXR_Rprimme CONCAT(Num_reset_update_VWXR_,REAL_SUF)
#endif
int Num_reset_update_VWXR_dprimme(double *V, double *W, PRIMME_INT mV,
   int nV, PRIMME_INT ldV,
   double *h, int nh, int ldh, double *hVals,
   double *X0, int nX0b, int nX0e, PRIMME_INT ldX0,
   double *X1, int nX1b, int nX1e, PRIMME_INT ldX1,
   double *evecs, int evecsSize, int nX2b, int nX2e, PRIMME_INT ldevecs,
   double *Wo, int nWob, int nWoe, PRIMME_INT ldWo,
   double *R, int nRb, int nRe, PRIMME_INT ldR, double *Rnorms,
   double *rnorms, int nrb, int nre,
   int reset, double machEps, double *rwork, size_t *lrwork,
   primme_params *primme);
#if !defined(CHECK_TEMPLATE) && !defined(retain_previous_coefficients_Sprimme)
#  define retain_previous_coefficients_Sprimme CONCAT(retain_previous_coefficients_,SCALAR_SUF)
#endif
#if !defined(CHECK_TEMPLATE) && !defined(retain_previous_coefficients_Rprimme)
#  define retain_previous_coefficients_Rprimme CONCAT(retain_previous_coefficients_,REAL_SUF)
#endif
int retain_previous_coefficients_dprimme(double *hVecs, int ldhVecs,
   double *hU, int ldhU, double *previousHVecs, int ldpreviousHVecs,
   int mprevious, int basisSize, int *iev, int blockSize, int *flags,
   int *numPrevRetained, int *iwork, int iworkSize, primme_params *primme);
int restart_zprimme(PRIMME_COMPLEX_DOUBLE *V, PRIMME_COMPLEX_DOUBLE *W, PRIMME_INT nLocal, int basisSize,
       PRIMME_INT ldV, double *hVals, double *hSVals, int *flags, int *iev,
       int *ievSize, double *blockNorms, PRIMME_COMPLEX_DOUBLE *evecs, PRIMME_INT ldevecs,
       int *evecsPerm, double *evals, double *resNorms, PRIMME_COMPLEX_DOUBLE *evecsHat,
       PRIMME_INT ldevecsHat, PRIMME_COMPLEX_DOUBLE *M, int ldM, PRIMME_COMPLEX_DOUBLE *UDU, int ldUDU,
       int *ipivot, int *numConverged, int *numLocked, int *lockedFlags,
       int *numConvergedStored, PRIMME_COMPLEX_DOUBLE *previousHVecs, int *numPrevRetained,
       int ldpreviousHVecs, int numGuesses, double *prevRitzVals,
       int *numPrevRitzVals, PRIMME_COMPLEX_DOUBLE *H, int ldH, PRIMME_COMPLEX_DOUBLE *VtBV, int ldVtBV,
       PRIMME_COMPLEX_DOUBLE *Q, PRIMME_INT ldQ, PRIMME_COMPLEX_DOUBLE *R, int ldR, PRIMME_COMPLEX_DOUBLE* QtV, int ldQtV,
       PRIMME_COMPLEX_DOUBLE *hU, int ldhU, int newldhU, PRIMME_COMPLEX_DOUBLE *hVecs, int ldhVecs,
       int newldhVecs, int *restartSizeOutput, int *targetShiftIndex,
       int *numArbitraryVecs, PRIMME_COMPLEX_DOUBLE *hVecsRot, int ldhVecsRot,
       int *restartsSinceReset, int *reset, double machEps, PRIMME_COMPLEX_DOUBLE *rwork,
       size_t *rworkSize, int *iwork, int iworkSize, primme_params *primme);
int Num_reset_update_VWXR_zprimme(PRIMME_COMPLEX_DOUBLE *V, PRIMME_COMPLEX_DOUBLE *W, PRIMME_INT mV,
   int nV, PRIMME_INT ldV,
   PRIMME_COMPLEX_DOUBLE *h, int nh, int ldh, double *hVals,
   PRIMME_COMPLEX_DOUBLE *X0, int nX0b, int nX0e, PRIMME_INT ldX0,
   PRIMME_COMPLEX_DOUBLE *X1, int nX1b, int nX1e, PRIMME_INT ldX1,
   PRIMME_COMPLEX_DOUBLE *evecs, int evecsSize, int nX2b, int nX2e, PRIMME_INT ldevecs,
   PRIMME_COMPLEX_DOUBLE *Wo, int nWob, int nWoe, PRIMME_INT ldWo,
   PRIMME_COMPLEX_DOUBLE *R, int nRb, int nRe, PRIMME_INT ldR, double *Rnorms,
   double *rnorms, int nrb, int nre,
   int reset, double machEps, PRIMME_COMPLEX_DOUBLE *rwork, size_t *lrwork,
   primme_params *primme);
int retain_previous_coefficients_zprimme(PRIMME_COMPLEX_DOUBLE *hVecs, int ldhVecs,
   PRIMME_COMPLEX_DOUBLE *hU, int ldhU, PRIMME_COMPLEX_DOUBLE *previousHVecs, int ldpreviousHVecs,
   int mprevious, int basisSize, int *iev, int blockSize, int *flags,
   int *numPrevRetained, int *iwork, int iworkSize, primme_params *primme);
int restart_sprimme(float *V, float *W, PRIMME_INT nLocal, int basisSize,
       PRIMME_INT ldV, float *hVals, float *hSVals, int *flags, int *iev,
       int *ievSize, float *blockNorms, float *evecs, PRIMME_INT ldevecs,
       int *evecsPerm, float *evals, float *resNorms, float *evecsHat,
       PRIMME_INT ldevecsHat, float *M, int ldM, float *UDU, int ldUDU,
       int *ipivot, int *numConverged, int *numLocked, int *lockedFlags,
       int *numConvergedStored, float *previousHVecs, int *numPrevRetained,
       int ldpreviousHVecs, int numGuesses, float *prevRitzVals,
       int *numPrevRitzVals, float *H, int ldH, float *VtBV, int ldVtBV,
       float *Q, PRIMME_INT ldQ, float *R, int ldR, float* QtV, int ldQtV,
       float *hU, int ldhU, int newldhU, float *hVecs, int ldhVecs,
       int newldhVecs, int *restartSizeOutput, int *targetShiftIndex,
       int *numArbitraryVecs, float *hVecsRot, int ldhVecsRot,
       int *restartsSinceReset, int *reset, double machEps, float *rwork,
       size_t *rworkSize, int *iwork, int iworkSize, primme_params *primme);
int Num_reset_update_VWXR_sprimme(float *V, float *W, PRIMME_INT mV,
   int nV, PRIMME_INT ldV,
   float *h, int nh, int ldh, float *hVals,
   float *X0, int nX0b, int nX0e, PRIMME_INT ldX0,
   float *X1, int nX1b, int nX1e, PRIMME_INT ldX1,
   float *evecs, int evecsSize, int nX2b, int nX2e, PRIMME_INT ldevecs,
   float *Wo, int nWob, int nWoe, PRIMME_INT ldWo,
   float *R, int nRb, int nRe, PRIMME_INT ldR, float *Rnorms,
   float *rnorms, int nrb, int nre,
   int reset, double machEps, float *rwork, size_t *lrwork,
   primme_params *primme);
int retain_previous_coefficients_sprimme(float *hVecs, int ldhVecs,
   float *hU, int ldhU, float *previousHVecs, int ldpreviousHVecs,
   int mprevious, int basisSize, int *iev, int blockSize, int *flags,
   int *numPrevRetained, int *iwork, int iworkSize, primme_params *primme);
int restart_cprimme(PRIMME_COMPLEX_FLOAT *V, PRIMME_COMPLEX_FLOAT *W, PRIMME_INT nLocal, int basisSize,
       PRIMME_INT ldV, float *hVals, float *hSVals, int *flags, int *iev,
       int *ievSize, float *blockNorms, PRIMME_COMPLEX_FLOAT *evecs, PRIMME_INT ldevecs,
       int *evecsPerm, float *evals, float *resNorms, PRIMME_COMPLEX_FLOAT *evecsHat,
       PRIMME_INT ldevecsHat, PRIMME_COMPLEX_FLOAT *M, int ldM, PRIMME_COMPLEX_FLOAT *UDU, int ldUDU,
       int *ipivot, int *numConverged, int *numLocked, int *lockedFlags,
       int *numConvergedStored, PRIMME_COMPLEX_FLOAT *previousHVecs, int *numPrevRetained,
       int ldpreviousHVecs, int numGuesses, float *prevRitzVals,
       int *numPrevRitzVals, PRIMME_COMPLEX_FLOAT *H, int ldH, PRIMME_COMPLEX_FLOAT *VtBV, int ldVtBV,
       PRIMME_COMPLEX_FLOAT *Q, PRIMME_INT ldQ, PRIMME_COMPLEX_FLOAT *R, int ldR, PRIMME_COMPLEX_FLOAT* QtV, int ldQtV,
       PRIMME_COMPLEX_FLOAT *hU, int ldhU, int newldhU, PRIMME_COMPLEX_FLOAT *hVecs, int ldhVecs,
       int newldhVecs, int *restartSizeOutput, int *targetShiftIndex,
       int *numArbitraryVecs, PRIMME_COMPLEX_FLOAT *hVecsRot, int ldhVecsRot,
       int *restartsSinceReset, int *reset, double machEps, PRIMME_COMPLEX_FLOAT *rwork,
       size_t *rworkSize, int *iwork, int iworkSize, primme_params *primme);
int Num_reset_update_VWXR_cprimme(PRIMME_COMPLEX_FLOAT *V, PRIMME_COMPLEX_FLOAT *W, PRIMME_INT mV,
   int nV, PRIMME_INT ldV,
   PRIMME_COMPLEX_FLOAT *h, int nh, int ldh, float *hVals,
   PRIMME_COMPLEX_FLOAT *X0, int nX0b, int nX0e, PRIMME_INT ldX0,
   PRIMME_COMPLEX_FLOAT *X1, int nX1b, int nX1e, PRIMME_INT ldX1,
   PRIMME_COMPLEX_FLOAT *evecs, int evecsSize, int nX2b, int nX2e, PRIMME_INT ldevecs,
   PRIMME_COMPLEX_FLOAT *Wo, int nWob, int nWoe, PRIMME_INT ldWo,
   PRIMME_COMPLEX_FLOAT *R, int nRb, int nRe, PRIMME_INT ldR, float *Rnorms,
   float *rnorms, int nrb, int nre,
   int reset, double machEps, PRIMME_COMPLEX_FLOAT *rwork, size_t *lrwork,
   primme_params *primme);
int retain_previous_coefficients_cprimme(PRIMME_COMPLEX_FLOAT *hVecs, int ldhVecs,
   PRIMME_COMPLEX_FLOAT *hU, int ldhU, PRIMME_COMPLEX_FLOAT *previousHVecs, int ldpreviousHVecs,
   int mprevious, int basisSize, int *iev, int blockSize, int *flags,
   int *numPrevRetained, int *iwork, int iworkSize, primme_params *primme);
#endif
