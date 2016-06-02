/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.cpp
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "G.h"
#include "power.h"
#include "error.h"
#include "G_emxutil.h"
#include "scalexpAlloc.h"
#include "G_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo n_emlrtRSI = { 58, "power",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/ops/power.m" };

static emlrtRSInfo o_emlrtRSI = { 61, "power",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/ops/power.m" };

static emlrtRSInfo p_emlrtRSI = { 73, "applyScalarFunction",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"
};

static emlrtRSInfo q_emlrtRSI = { 132, "applyScalarFunction",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/applyScalarFunction.m"
};

static emlrtRTEInfo j_emlrtRTEI = { 16, 9, "scalexpAlloc",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"
};

static emlrtRTEInfo q_emlrtRTEI = { 17, 19, "scalexpAlloc",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/scalexpAlloc.m"
};

/* Function Declarations */
static boolean_T fltpower_domain_error();

/* Function Definitions */
static boolean_T fltpower_domain_error()
{
  return false;
}

void power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &m_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &n_emlrtRSI;
  c_st.site = &p_emlrtRSI;
  k = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = (uint16_T)a->size[1];
  emxEnsureCapacity(&c_st, (emxArray__common *)y, k, (int32_T)sizeof(real_T),
                    &j_emlrtRTEI);
  if (dimagree(y, a)) {
  } else {
    emlrtErrorWithMessageIdR2012b(&c_st, &q_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  c_st.site = &q_emlrtRSI;
  for (k = 0; k + 1 <= a->size[1]; k++) {
    y->data[k] = a->data[k] * a->data[k];
  }

  if (fltpower_domain_error()) {
    b_st.site = &o_emlrtRSI;
    b_error(&b_st);
  }
}

/* End of code generation (power.cpp) */
