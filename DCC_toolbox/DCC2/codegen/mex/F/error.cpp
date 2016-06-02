/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * error.cpp
 *
 * Code generation for function 'error'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "F.h"
#include "error.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRTEInfo o_emlrtRTEI = { 17, 9, "error",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/error.m" };

/* Function Definitions */
void b_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &o_emlrtRTEI,
    "Coder:toolbox:power_domainError", 0);
}

void error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &o_emlrtRTEI,
    "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
}

/* End of code generation (error.cpp) */
