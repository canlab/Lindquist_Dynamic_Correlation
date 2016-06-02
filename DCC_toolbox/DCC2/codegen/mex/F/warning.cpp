/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * warning.cpp
 *
 * Code generation for function 'warning'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "F.h"
#include "warning.h"
#include "blas.h"

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = { 14, 25, "warning",
  "/Applications/MATLAB_R2016a.app/toolbox/shared/coder/coder/+coder/+internal/warning.m"
};

static emlrtMCInfo b_emlrtMCI = { 14, 9, "warning",
  "/Applications/MATLAB_R2016a.app/toolbox/shared/coder/coder/+coder/+internal/warning.m"
};

static emlrtRSInfo bb_emlrtRSI = { 14, "warning",
  "/Applications/MATLAB_R2016a.app/toolbox/shared/coder/coder/+coder/+internal/warning.m"
};

/* Function Declarations */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location);
static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location);

/* Function Definitions */
static void b_feval(const emlrtStack *sp, const mxArray *b, const mxArray *c,
                    emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  pArrays[0] = b;
  pArrays[1] = c;
  emlrtCallMATLABR2012b(sp, 0, NULL, 2, pArrays, "feval", true, location);
}

static const mxArray *feval(const emlrtStack *sp, const mxArray *b, const
  mxArray *c, emlrtMCInfo *location)
{
  const mxArray *pArrays[2];
  const mxArray *m2;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(sp, 1, &m2, 2, pArrays, "feval", true, location);
}

void warning(const emlrtStack *sp)
{
  int32_T i4;
  const mxArray *y;
  char_T u[7];
  static const char_T cv0[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  const mxArray *m0;
  static const int32_T iv8[2] = { 1, 7 };

  const mxArray *b_y;
  char_T b_u[7];
  static const char_T cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  static const int32_T iv9[2] = { 1, 7 };

  const mxArray *c_y;
  char_T c_u[27];
  static const char_T msgID[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T',
    'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a', 't',
    'r', 'i', 'x' };

  static const int32_T iv10[2] = { 1, 27 };

  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  for (i4 = 0; i4 < 7; i4++) {
    u[i4] = cv0[i4];
  }

  y = NULL;
  m0 = emlrtCreateCharArray(2, iv8);
  emlrtInitCharArrayR2013a(sp, 7, m0, &u[0]);
  emlrtAssign(&y, m0);
  for (i4 = 0; i4 < 7; i4++) {
    b_u[i4] = cv1[i4];
  }

  b_y = NULL;
  m0 = emlrtCreateCharArray(2, iv9);
  emlrtInitCharArrayR2013a(sp, 7, m0, &b_u[0]);
  emlrtAssign(&b_y, m0);
  for (i4 = 0; i4 < 27; i4++) {
    c_u[i4] = msgID[i4];
  }

  c_y = NULL;
  m0 = emlrtCreateCharArray(2, iv10);
  emlrtInitCharArrayR2013a(sp, 27, m0, &c_u[0]);
  emlrtAssign(&c_y, m0);
  st.site = &bb_emlrtRSI;
  b_feval(&st, y, feval(&st, b_y, c_y, (emlrtMCInfo *)&emlrtMCI), (emlrtMCInfo *)
          &b_emlrtMCI);
}

/* End of code generation (warning.cpp) */
