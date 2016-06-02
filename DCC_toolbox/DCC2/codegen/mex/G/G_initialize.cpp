/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * G_initialize.cpp
 *
 * Code generation for function 'G_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "G.h"
#include "G_initialize.h"
#include "_coder_G_mex.h"
#include "G_data.h"
#include "blas.h"

/* Function Definitions */
void G_initialize()
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (G_initialize.cpp) */
