/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_int_forloop_overflow_check.cpp
 *
 * Code generation for function 'eml_int_forloop_overflow_check'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "F.h"
#include "eml_int_forloop_overflow_check.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRTEInfo p_emlrtRTEI = { 86, 15, "eml_int_forloop_overflow_check",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"
};

/* Function Definitions */
void check_forloop_overflow_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &p_emlrtRTEI,
    "Coder:toolbox:int_forloop_overflow", 3, 4, 5, "int32");
}

/* End of code generation (eml_int_forloop_overflow_check.cpp) */
