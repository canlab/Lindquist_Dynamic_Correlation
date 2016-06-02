/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean.cpp
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "F.h"
#include "mean.h"
#include "eml_int_forloop_overflow_check.h"
#include "F_emxutil.h"
#include "F_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo q_emlrtRSI = { 40, "mean",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/datafun/mean.m" };

static emlrtRSInfo r_emlrtRSI = { 102, "combine_vector_elements",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"
};

static emlrtRSInfo s_emlrtRSI = { 113, "combine_vector_elements",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"
};

static emlrtRTEInfo k_emlrtRTEI = { 1, 14, "mean",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/datafun/mean.m" };

/* Function Definitions */
void mean(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  int32_T j;
  int32_T vlen;
  int32_T vstride;
  real_T s;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &q_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  j = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity(&st, (emxArray__common *)y, j, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    vlen = y->size[0];
    j = y->size[0];
    y->size[0] = vlen;
    emxEnsureCapacity(&st, (emxArray__common *)y, j, (int32_T)sizeof(real_T),
                      &k_emlrtRTEI);
    for (j = 0; j < vlen; j++) {
      y->data[j] = 0.0;
    }
  } else {
    vlen = x->size[1];
    vstride = x->size[0];
    b_st.site = &r_emlrtRSI;
    for (j = 0; j + 1 <= vstride; j++) {
      s = x->data[j];
      b_st.site = &s_emlrtRSI;
      if ((!(2 > vlen)) && (vlen > 2147483646)) {
        c_st.site = &j_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }

      for (k = 2; k <= vlen; k++) {
        s += x->data[j + (k - 1) * vstride];
      }

      y->data[j] = s;
    }
  }

  vlen = x->size[1];
  j = y->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)y, j, (int32_T)sizeof(real_T),
                    &k_emlrtRTEI);
  vstride = y->size[0];
  for (j = 0; j < vstride; j++) {
    y->data[j] /= (real_T)vlen;
  }
}

/* End of code generation (mean.cpp) */
