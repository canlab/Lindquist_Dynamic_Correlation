/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sqrt.cpp
 *
 * Code generation for function 'sqrt'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "G.h"
#include "sqrt.h"
#include "error.h"
#include "eml_int_forloop_overflow_check.h"
#include "G_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo h_emlrtRSI = { 12, "sqrt",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/elfun/sqrt.m" };

static emlrtRSInfo i_emlrtRSI = { 15, "sqrt",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/elfun/sqrt.m" };

static emlrtRSInfo j_emlrtRSI = { 24, "applyScalarFunctionInPlace",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/applyScalarFunctionInPlace.m"
};

/* Function Definitions */
void b_sqrt(real_T *x)
{
  *x = muDoubleScalarSqrt(*x);
}

void c_sqrt(const emlrtStack *sp, emxArray_real_T *x)
{
  boolean_T p;
  int32_T nx;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  p = false;
  nx = x->size[0] * x->size[1];
  for (k = 0; k < nx; k++) {
    if (p || (x->data[k] < 0.0)) {
      p = true;
    } else {
      p = false;
    }
  }

  if (p) {
    st.site = &h_emlrtRSI;
    error(&st);
  }

  st.site = &i_emlrtRSI;
  nx = x->size[0] * x->size[1];
  b_st.site = &j_emlrtRSI;
  if ((!(1 > nx)) && (nx > 2147483646)) {
    c_st.site = &k_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k + 1 <= nx; k++) {
    x->data[k] = muDoubleScalarSqrt(x->data[k]);
  }
}

/* End of code generation (sqrt.cpp) */
