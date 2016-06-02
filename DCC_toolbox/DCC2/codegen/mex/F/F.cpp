/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * F.cpp
 *
 * Code generation for function 'F'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "F.h"
#include "sqrt.h"
#include "F_emxutil.h"
#include "warning.h"
#include "mean.h"
#include "epsilonToY.h"
#include "F_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 13, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtRSInfo b_emlrtRSI = { 29, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtRSInfo c_emlrtRSI = { 32, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtRSInfo d_emlrtRSI = { 51, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtRSInfo e_emlrtRSI = { 52, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtRSInfo f_emlrtRSI = { 58, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtRSInfo t_emlrtRSI = { 68, "eml_mtimes_helper",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"
};

static emlrtRSInfo u_emlrtRSI = { 21, "eml_mtimes_helper",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"
};

static emlrtRSInfo v_emlrtRSI = { 85, "xgemm",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/+blas/xgemm.m"
};

static emlrtRSInfo w_emlrtRSI = { 1, "mldivide",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/ops/mldivide.p" };

static emlrtRSInfo x_emlrtRSI = { 54, "lusolve",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/lusolve.m" };

static emlrtRSInfo y_emlrtRSI = { 169, "lusolve",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/lusolve.m" };

static emlrtRSInfo ab_emlrtRSI = { 76, "lusolve",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/eml/+coder/+internal/lusolve.m" };

static emlrtRTEInfo emlrtRTEI = { 1, 25, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtRTEInfo b_emlrtRTEI = { 18, 1, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtRTEInfo c_emlrtRTEI = { 21, 1, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtRTEInfo d_emlrtRTEI = { 22, 1, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtRTEInfo e_emlrtRTEI = { 29, 1, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtRTEInfo f_emlrtRTEI = { 32, 1, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtRTEInfo g_emlrtRTEI = { 35, 1, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtRTEInfo h_emlrtRTEI = { 37, 1, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtRTEInfo m_emlrtRTEI = { 103, 23, "eml_mtimes_helper",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"
};

static emlrtRTEInfo n_emlrtRTEI = { 98, 23, "eml_mtimes_helper",
  "/Applications/MATLAB_R2016a.app/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"
};

static emlrtBCInfo emlrtBCI = { -1, -1, 52, 31, "X", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtBCInfo b_emlrtBCI = { -1, -1, 52, 19, "X", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtBCInfo c_emlrtBCI = { -1, -1, 51, 29, "Y", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtBCInfo d_emlrtBCI = { -1, -1, 51, 19, "X", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtECInfo emlrtECI = { -1, 43, 5, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtBCInfo e_emlrtBCI = { -1, -1, 43, 11, "X", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtECInfo b_emlrtECI = { -1, 42, 5, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtBCInfo f_emlrtBCI = { -1, -1, 42, 11, "X", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtECInfo c_emlrtECI = { -1, 38, 20, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtBCInfo g_emlrtBCI = { -1, -1, 38, 26, "X", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtECInfo d_emlrtECI = { -1, 38, 1, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtBCInfo h_emlrtBCI = { -1, -1, 38, 7, "X", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtBCInfo i_emlrtBCI = { -1, -1, 43, 20, "U", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtBCInfo j_emlrtBCI = { -1, -1, 42, 20, "Y", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtECInfo e_emlrtECI = { -1, 41, 5, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtBCInfo k_emlrtBCI = { -1, -1, 41, 9, "U", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtECInfo f_emlrtECI = { -1, 41, 14, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtBCInfo l_emlrtBCI = { -1, -1, 41, 45, "U", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtBCInfo m_emlrtBCI = { -1, -1, 41, 26, "Y", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtBCInfo n_emlrtBCI = { -1, -1, 38, 36, "U", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtECInfo g_emlrtECI = { -1, 36, 1, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtBCInfo o_emlrtBCI = { -1, -1, 36, 5, "U", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtBCInfo p_emlrtBCI = { -1, -1, 38, 16, "Y", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtECInfo h_emlrtECI = { -1, 36, 10, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtECInfo i_emlrtECI = { 2, 33, 5, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtECInfo j_emlrtECI = { 2, 31, 5, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtECInfo k_emlrtECI = { -1, 26, 5, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtBCInfo q_emlrtBCI = { -1, -1, 26, 13, "Qdiag", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtECInfo l_emlrtECI = { -1, 26, 18, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtBCInfo r_emlrtBCI = { -1, -1, 26, 63, "Qdiag", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtECInfo m_emlrtECI = { -1, 25, 12, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m" };

static emlrtBCInfo s_emlrtBCI = { -1, -1, 25, 34, "Qdiag", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtBCInfo t_emlrtBCI = { -1, -1, 19, 9, "Qdiag", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtBCInfo u_emlrtBCI = { -1, -1, 25, 20, "Ydiag", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtBCInfo v_emlrtBCI = { -1, -1, 22, 19, "vecS0", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtBCInfo w_emlrtBCI = { -1, -1, 22, 15, "vecS0", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 21, 12, "Y0", "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 0 };

static emlrtDCInfo emlrtDCI = { 35, 11, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 1 };

static emlrtDCInfo b_emlrtDCI = { 36, 29, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 1 };

static emlrtDCInfo c_emlrtDCI = { 36, 29, "F",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/F.m", 4 };

/* Function Definitions */
void F(const emlrtStack *sp, const real_T para[2], const emxArray_real_T *Y0,
       const emxArray_real_T *vecS0, real_T para_new[2])
{
  int32_T T;
  int32_T r1;
  emxArray_real_T *Qdiag;
  real_T K;
  real_T a21;
  int32_T i0;
  int32_T r2;
  emxArray_real_T *Ydiag;
  int32_T itmp;
  emxArray_real_T *Sdiag;
  int32_T t;
  emxArray_real_T *vecS;
  emxArray_int32_T *r0;
  emxArray_real_T *b_r1;
  emxArray_real_T *y;
  emxArray_real_T *b_r2;
  emxArray_real_T *VU;
  int32_T b_Y0[2];
  int32_T b_VU[2];
  emxArray_real_T *U;
  int32_T c_VU[2];
  int32_T b_U[2];
  int32_T iv0[1];
  real_T a22;
  real_T d0;
  emxArray_int32_T *r3;
  int32_T iv1[1];
  emxArray_real_T *X;
  emxArray_real_T *d_VU;
  int32_T iv2[1];
  int32_T e_VU[1];
  emxArray_real_T *c_U;
  int32_T iv3[1];
  int32_T d_U[1];
  emxArray_real_T *f_VU;
  emxArray_real_T *e_U;
  real_T b[2];
  real_T A[4];
  emxArray_real_T *a;
  emxArray_real_T *b_b;
  int32_T iv4[1];
  real_T Y[2];
  boolean_T guard2 = false;
  real_T b_y[2];
  boolean_T b0;
  real_T p1;
  int32_T iv5[1];
  char_T TRANSB;
  char_T TRANSA;
  real_T paraAtBoundary[6];
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  real_T p2;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  int32_T g_VU[1];
  ptrdiff_t ldc_t;
  real_T obj[3];
  int32_T k;
  boolean_T guard1 = false;
  int32_T iv6[1];
  real_T c_y[2];
  boolean_T exitg1;
  real_T d_y[4];
  int32_T f_U[1];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /*  Calculate mapping F */
  /*    Input:  */
  /*        para: 1-by-2 DCC parameters */
  /*        Y0,vecS0: a series of vecterized outer product from standardized residual time series */
  /*    Output: */
  /*        para_new: mapping F(para,Y0,vecS0) */
  /*    Function dependency: */
  /*        epsilonToY.m */
  /* % initialization */
  T = Y0->size[1] - 2;
  if ((vecS0->size[0] == 0) || (vecS0->size[1] == 0)) {
    r1 = 0;
  } else {
    r1 = muIntScalarMax_sint32(vecS0->size[0], 1);
  }

  emxInit_real_T(sp, &Qdiag, 2, &b_emlrtRTEI, true);
  K = (real_T)r1 * 2.0;
  st.site = &emlrtRSI;
  b_sqrt(&K);
  K = muDoubleScalarFloor(K);
  a21 = para[0] + para[1];

  /* % update the design matrix via DCC formular with old para */
  i0 = Qdiag->size[0] * Qdiag->size[1];
  Qdiag->size[0] = (int32_T)K;
  Qdiag->size[1] = Y0->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)Qdiag, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  r2 = (int32_T)K * Y0->size[1];
  for (i0 = 0; i0 < r2; i0++) {
    Qdiag->data[i0] = 0.0;
  }

  r1 = Y0->size[1];
  if (!(1 <= r1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, r1, (emlrtBCInfo *)&t_emlrtBCI, sp);
  }

  r2 = (int32_T)K;
  for (i0 = 0; i0 < r2; i0++) {
    Qdiag->data[i0] = 1.0;
  }

  if (1.0 > K) {
    r2 = 0;
  } else {
    i0 = Y0->size[0];
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    i0 = Y0->size[0];
    r2 = (int32_T)K;
    if (!((r2 >= 1) && (r2 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(r2, 1, i0, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }
  }

  emxInit_real_T(sp, &Ydiag, 2, &c_emlrtRTEI, true);
  r1 = Y0->size[1];
  i0 = Ydiag->size[0] * Ydiag->size[1];
  Ydiag->size[0] = r2;
  Ydiag->size[1] = r1;
  emxEnsureCapacity(sp, (emxArray__common *)Ydiag, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  for (i0 = 0; i0 < r1; i0++) {
    for (itmp = 0; itmp < r2; itmp++) {
      Ydiag->data[itmp + Ydiag->size[0] * i0] = Y0->data[itmp + Y0->size[0] * i0];
    }
  }

  if (1.0 > K) {
    r1 = 0;
  } else {
    i0 = vecS0->size[0];
    if (!(1 <= i0)) {
      emlrtDynamicBoundsCheckR2012b(1, 1, i0, (emlrtBCInfo *)&w_emlrtBCI, sp);
    }

    i0 = vecS0->size[0];
    r1 = (int32_T)K;
    if (!((r1 >= 1) && (r1 <= i0))) {
      emlrtDynamicBoundsCheckR2012b(r1, 1, i0, (emlrtBCInfo *)&w_emlrtBCI, sp);
    }
  }

  emxInit_real_T1(sp, &Sdiag, 1, &d_emlrtRTEI, true);
  i0 = vecS0->size[1];
  if (!(1 <= i0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, (emlrtBCInfo *)&v_emlrtBCI, sp);
  }

  i0 = Sdiag->size[0];
  Sdiag->size[0] = r1;
  emxEnsureCapacity(sp, (emxArray__common *)Sdiag, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  for (i0 = 0; i0 < r1; i0++) {
    Sdiag->data[i0] = vecS0->data[i0];
  }

  t = 0;
  emxInit_real_T1(sp, &vecS, 1, &f_emlrtRTEI, true);
  emxInit_int32_T(sp, &r0, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &b_r1, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &y, 1, &emlrtRTEI, true);
  while (t <= T) {
    i0 = Y0->size[1];
    itmp = (int32_T)((2.0 + (real_T)t) - 1.0);
    if (!((itmp >= 1) && (itmp <= i0))) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, i0, (emlrtBCInfo *)&u_emlrtBCI, sp);
    }

    i0 = Qdiag->size[1];
    itmp = (int32_T)((2.0 + (real_T)t) - 1.0);
    if (!((itmp >= 1) && (itmp <= i0))) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, i0, (emlrtBCInfo *)&s_emlrtBCI, sp);
    }

    i0 = Qdiag->size[0];
    if (r2 != i0) {
      emlrtSizeEqCheck1DR2012b(r2, i0, (emlrtECInfo *)&m_emlrtECI, sp);
    }

    i0 = vecS->size[0];
    vecS->size[0] = Sdiag->size[0];
    emxEnsureCapacity(sp, (emxArray__common *)vecS, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    r1 = Sdiag->size[0];
    for (i0 = 0; i0 < r1; i0++) {
      vecS->data[i0] = (1.0 - a21) * Sdiag->data[i0];
    }

    i0 = y->size[0];
    y->size[0] = r2;
    emxEnsureCapacity(sp, (emxArray__common *)y, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < r2; i0++) {
      y->data[i0] = para[0] * (Ydiag->data[i0 + Ydiag->size[0] * t] *
        Qdiag->data[i0 + Qdiag->size[0] * t]);
    }

    i0 = vecS->size[0];
    itmp = y->size[0];
    if (i0 != itmp) {
      emlrtSizeEqCheck1DR2012b(i0, itmp, (emlrtECInfo *)&l_emlrtECI, sp);
    }

    i0 = Qdiag->size[1];
    itmp = (int32_T)((2.0 + (real_T)t) - 1.0);
    if (!((itmp >= 1) && (itmp <= i0))) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, i0, (emlrtBCInfo *)&r_emlrtBCI, sp);
    }

    r1 = Qdiag->size[0];
    i0 = b_r1->size[0];
    b_r1->size[0] = r1;
    emxEnsureCapacity(sp, (emxArray__common *)b_r1, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < r1; i0++) {
      b_r1->data[i0] = para[1] * Qdiag->data[i0 + Qdiag->size[0] * t];
    }

    i0 = vecS->size[0];
    itmp = b_r1->size[0];
    if (i0 != itmp) {
      emlrtSizeEqCheck1DR2012b(i0, itmp, (emlrtECInfo *)&l_emlrtECI, sp);
    }

    r1 = Qdiag->size[0];
    i0 = r0->size[0];
    r0->size[0] = r1;
    emxEnsureCapacity(sp, (emxArray__common *)r0, i0, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < r1; i0++) {
      r0->data[i0] = i0;
    }

    i0 = Qdiag->size[1];
    itmp = (int32_T)(2.0 + (real_T)t);
    if (!((itmp >= 1) && (itmp <= i0))) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, i0, (emlrtBCInfo *)&q_emlrtBCI, sp);
    }

    iv0[0] = r0->size[0];
    emlrtSubAssignSizeCheckR2012b(iv0, 1, *(int32_T (*)[1])vecS->size, 1,
      (emlrtECInfo *)&k_emlrtECI, sp);
    r1 = vecS->size[0];
    for (i0 = 0; i0 < r1; i0++) {
      Qdiag->data[r0->data[i0] + Qdiag->size[0] * (t + 1)] = (vecS->data[i0] +
        y->data[i0]) + b_r1->data[i0];
    }

    t++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&y);
  emxFree_int32_T(&r0);
  emxFree_real_T(&Sdiag);
  emxFree_real_T(&Ydiag);
  emxInit_real_T(sp, &b_r2, 2, &emlrtRTEI, true);
  i0 = b_r2->size[0] * b_r2->size[1];
  b_r2->size[0] = Qdiag->size[1];
  b_r2->size[1] = Qdiag->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_r2, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  r2 = Qdiag->size[0];
  for (i0 = 0; i0 < r2; i0++) {
    r1 = Qdiag->size[1];
    for (itmp = 0; itmp < r1; itmp++) {
      b_r2->data[itmp + b_r2->size[0] * i0] = Qdiag->data[i0 + Qdiag->size[0] *
        itmp];
    }
  }

  emxFree_real_T(&Qdiag);
  emxInit_real_T(sp, &VU, 2, &e_emlrtRTEI, true);
  st.site = &b_emlrtRSI;
  c_sqrt(&st, b_r2);
  st.site = &b_emlrtRSI;
  epsilonToY(&st, b_r2, VU);
  emxFree_real_T(&b_r2);
  for (i0 = 0; i0 < 2; i0++) {
    b_Y0[i0] = Y0->size[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    b_VU[i0] = VU->size[i0];
  }

  if ((b_Y0[0] != b_VU[0]) || (b_Y0[1] != b_VU[1])) {
    emlrtSizeEqCheckNDR2012b(&b_Y0[0], &b_VU[0], (emlrtECInfo *)&j_emlrtECI, sp);
  }

  i0 = VU->size[0] * VU->size[1];
  VU->size[0] = Y0->size[0];
  VU->size[1] = Y0->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VU, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  r2 = Y0->size[0] * Y0->size[1];
  for (i0 = 0; i0 < r2; i0++) {
    VU->data[i0] *= Y0->data[i0];
  }

  emxInit_real_T(sp, &U, 2, &g_emlrtRTEI, true);
  st.site = &c_emlrtRSI;
  mean(&st, VU, vecS);
  r1 = Y0->size[1];
  i0 = U->size[0] * U->size[1];
  U->size[0] = vecS->size[0];
  U->size[1] = r1;
  emxEnsureCapacity(sp, (emxArray__common *)U, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  r2 = vecS->size[0];
  for (i0 = 0; i0 < r2; i0++) {
    for (itmp = 0; itmp < r1; itmp++) {
      U->data[i0 + U->size[0] * itmp] = vecS->data[i0];
    }
  }

  for (i0 = 0; i0 < 2; i0++) {
    c_VU[i0] = VU->size[i0];
  }

  for (i0 = 0; i0 < 2; i0++) {
    b_U[i0] = U->size[i0];
  }

  if ((c_VU[0] != b_U[0]) || (c_VU[1] != b_U[1])) {
    emlrtSizeEqCheckNDR2012b(&c_VU[0], &b_U[0], (emlrtECInfo *)&i_emlrtECI, sp);
  }

  i0 = VU->size[0] * VU->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)VU, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  r1 = VU->size[0];
  r2 = VU->size[1];
  r2 *= r1;
  for (i0 = 0; i0 < r2; i0++) {
    VU->data[i0] -= U->data[i0];
  }

  a21 = K * (K + 1.0) / 2.0;
  i0 = U->size[0] * U->size[1];
  if (a21 != (int32_T)muDoubleScalarFloor(a21)) {
    emlrtIntegerCheckR2012b(a21, (emlrtDCInfo *)&emlrtDCI, sp);
  }

  U->size[0] = (int32_T)a21;
  U->size[1] = Y0->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)U, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  if (a21 != (int32_T)muDoubleScalarFloor(a21)) {
    emlrtIntegerCheckR2012b(a21, (emlrtDCInfo *)&emlrtDCI, sp);
  }

  r2 = (int32_T)a21 * Y0->size[1];
  for (i0 = 0; i0 < r2; i0++) {
    U->data[i0] = 0.0;
  }

  a22 = K * (K - 1.0) / 2.0;
  d0 = K * (K - 1.0) / 2.0;
  if (!(d0 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(d0, (emlrtDCInfo *)&c_emlrtDCI, sp);
  }

  if (d0 != (int32_T)muDoubleScalarFloor(d0)) {
    emlrtIntegerCheckR2012b(d0, (emlrtDCInfo *)&b_emlrtDCI, sp);
  }

  i0 = b_r1->size[0];
  b_r1->size[0] = (int32_T)K + (int32_T)a22;
  emxEnsureCapacity(sp, (emxArray__common *)b_r1, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  r2 = (int32_T)K;
  for (i0 = 0; i0 < r2; i0++) {
    b_r1->data[i0] = 1.0;
  }

  r2 = (int32_T)a22;
  for (i0 = 0; i0 < r2; i0++) {
    b_r1->data[i0 + (int32_T)K] = 0.0;
  }

  emxInit_int32_T(sp, &r3, 1, &emlrtRTEI, true);
  i0 = b_r1->size[0];
  itmp = vecS->size[0];
  if (i0 != itmp) {
    emlrtSizeEqCheck1DR2012b(i0, itmp, (emlrtECInfo *)&h_emlrtECI, sp);
  }

  r2 = (int32_T)a21;
  i0 = r3->size[0];
  r3->size[0] = (int32_T)a21;
  emxEnsureCapacity(sp, (emxArray__common *)r3, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  for (i0 = 0; i0 < r2; i0++) {
    r3->data[i0] = i0;
  }

  r1 = Y0->size[1];
  if (!(1 <= r1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, r1, (emlrtBCInfo *)&o_emlrtBCI, sp);
  }

  iv1[0] = r3->size[0];
  emlrtSubAssignSizeCheckR2012b(iv1, 1, *(int32_T (*)[1])b_r1->size, 1,
    (emlrtECInfo *)&g_emlrtECI, sp);
  r2 = b_r1->size[0];
  for (i0 = 0; i0 < r2; i0++) {
    U->data[r3->data[i0]] = b_r1->data[i0] - vecS->data[i0];
  }

  emxInit_real_T2(sp, &X, 3, &h_emlrtRTEI, true);
  i0 = X->size[0] * X->size[1] * X->size[2];
  X->size[0] = Y0->size[0];
  X->size[1] = 2;
  X->size[2] = Y0->size[1];
  emxEnsureCapacity(sp, (emxArray__common *)X, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  r2 = (Y0->size[0] << 1) * Y0->size[1];
  for (i0 = 0; i0 < r2; i0++) {
    X->data[i0] = 0.0;
  }

  r1 = Y0->size[0];
  i0 = r3->size[0];
  r3->size[0] = r1;
  emxEnsureCapacity(sp, (emxArray__common *)r3, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  for (i0 = 0; i0 < r1; i0++) {
    r3->data[i0] = i0;
  }

  emxInit_real_T1(sp, &d_VU, 1, &emlrtRTEI, true);
  r1 = Y0->size[1];
  if (!(1 <= r1)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, r1, (emlrtBCInfo *)&h_emlrtBCI, sp);
  }

  i0 = VU->size[1];
  if (!(1 <= i0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, (emlrtBCInfo *)&p_emlrtBCI, sp);
  }

  iv2[0] = r3->size[0];
  r2 = VU->size[0];
  i0 = d_VU->size[0];
  d_VU->size[0] = r2;
  emxEnsureCapacity(sp, (emxArray__common *)d_VU, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  for (i0 = 0; i0 < r2; i0++) {
    d_VU->data[i0] = VU->data[i0];
  }

  e_VU[0] = d_VU->size[0];
  emlrtSubAssignSizeCheckR2012b(iv2, 1, e_VU, 1, (emlrtECInfo *)&d_emlrtECI, sp);
  r2 = VU->size[0] - 1;
  emxFree_real_T(&d_VU);
  for (i0 = 0; i0 <= r2; i0++) {
    X->data[r3->data[i0]] = VU->data[i0];
  }

  r2 = X->size[0];
  i0 = r3->size[0];
  r3->size[0] = r2;
  emxEnsureCapacity(sp, (emxArray__common *)r3, i0, (int32_T)sizeof(int32_T),
                    &emlrtRTEI);
  for (i0 = 0; i0 < r2; i0++) {
    r3->data[i0] = i0;
  }

  emxInit_real_T1(sp, &c_U, 1, &emlrtRTEI, true);
  i0 = X->size[2];
  if (!(1 <= i0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, (emlrtBCInfo *)&g_emlrtBCI, sp);
  }

  i0 = U->size[1];
  if (!(1 <= i0)) {
    emlrtDynamicBoundsCheckR2012b(1, 1, i0, (emlrtBCInfo *)&n_emlrtBCI, sp);
  }

  iv3[0] = r3->size[0];
  r2 = U->size[0];
  i0 = c_U->size[0];
  c_U->size[0] = r2;
  emxEnsureCapacity(sp, (emxArray__common *)c_U, i0, (int32_T)sizeof(real_T),
                    &emlrtRTEI);
  for (i0 = 0; i0 < r2; i0++) {
    c_U->data[i0] = U->data[i0];
  }

  d_U[0] = c_U->size[0];
  emlrtSubAssignSizeCheckR2012b(iv3, 1, d_U, 1, (emlrtECInfo *)&c_emlrtECI, sp);
  r2 = U->size[0] - 1;
  emxFree_real_T(&c_U);
  for (i0 = 0; i0 <= r2; i0++) {
    X->data[r3->data[i0] + X->size[0]] = U->data[i0];
  }

  t = 0;
  emxInit_real_T1(sp, &f_VU, 1, &emlrtRTEI, true);
  emxInit_real_T1(sp, &e_U, 1, &emlrtRTEI, true);
  while (t <= T) {
    i0 = VU->size[1];
    itmp = (int32_T)(t + 1U);
    if (!(itmp <= i0)) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, i0, (emlrtBCInfo *)&m_emlrtBCI, sp);
    }

    r2 = VU->size[0];
    i0 = b_r1->size[0];
    b_r1->size[0] = r2;
    emxEnsureCapacity(sp, (emxArray__common *)b_r1, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < r2; i0++) {
      b_r1->data[i0] = para[0] * VU->data[i0 + VU->size[0] * t];
    }

    i0 = U->size[1];
    itmp = (int32_T)(t + 1U);
    if (!(itmp <= i0)) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, i0, (emlrtBCInfo *)&l_emlrtBCI, sp);
    }

    r2 = U->size[0];
    i0 = vecS->size[0];
    vecS->size[0] = r2;
    emxEnsureCapacity(sp, (emxArray__common *)vecS, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < r2; i0++) {
      vecS->data[i0] = para[1] * U->data[i0 + U->size[0] * t];
    }

    i0 = b_r1->size[0];
    itmp = vecS->size[0];
    if (i0 != itmp) {
      emlrtSizeEqCheck1DR2012b(i0, itmp, (emlrtECInfo *)&f_emlrtECI, sp);
    }

    r2 = U->size[0];
    i0 = r3->size[0];
    r3->size[0] = r2;
    emxEnsureCapacity(sp, (emxArray__common *)r3, i0, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < r2; i0++) {
      r3->data[i0] = i0;
    }

    i0 = U->size[1];
    itmp = (int32_T)(2.0 + (real_T)t);
    if (!((itmp >= 1) && (itmp <= i0))) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, i0, (emlrtBCInfo *)&k_emlrtBCI, sp);
    }

    iv4[0] = r3->size[0];
    emlrtSubAssignSizeCheckR2012b(iv4, 1, *(int32_T (*)[1])b_r1->size, 1,
      (emlrtECInfo *)&e_emlrtECI, sp);
    r2 = b_r1->size[0];
    for (i0 = 0; i0 < r2; i0++) {
      U->data[r3->data[i0] + U->size[0] * (t + 1)] = b_r1->data[i0] + vecS->
        data[i0];
    }

    r2 = X->size[0];
    i0 = r3->size[0];
    r3->size[0] = r2;
    emxEnsureCapacity(sp, (emxArray__common *)r3, i0, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < r2; i0++) {
      r3->data[i0] = i0;
    }

    i0 = X->size[2];
    itmp = (int32_T)(2.0 + (real_T)t);
    if (!((itmp >= 1) && (itmp <= i0))) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, i0, (emlrtBCInfo *)&f_emlrtBCI, sp);
    }

    i0 = VU->size[1];
    itmp = (int32_T)(2.0 + (real_T)t);
    if (!((itmp >= 1) && (itmp <= i0))) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, i0, (emlrtBCInfo *)&j_emlrtBCI, sp);
    }

    iv5[0] = r3->size[0];
    r2 = VU->size[0];
    i0 = f_VU->size[0];
    f_VU->size[0] = r2;
    emxEnsureCapacity(sp, (emxArray__common *)f_VU, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < r2; i0++) {
      f_VU->data[i0] = VU->data[i0 + VU->size[0] * (t + 1)];
    }

    g_VU[0] = f_VU->size[0];
    emlrtSubAssignSizeCheckR2012b(iv5, 1, g_VU, 1, (emlrtECInfo *)&b_emlrtECI,
      sp);
    r2 = VU->size[0] - 1;
    for (i0 = 0; i0 <= r2; i0++) {
      X->data[r3->data[i0] + X->size[0] * X->size[1] * (t + 1)] = VU->data[i0 +
        VU->size[0] * (t + 1)];
    }

    r2 = X->size[0];
    i0 = r3->size[0];
    r3->size[0] = r2;
    emxEnsureCapacity(sp, (emxArray__common *)r3, i0, (int32_T)sizeof(int32_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < r2; i0++) {
      r3->data[i0] = i0;
    }

    i0 = X->size[2];
    itmp = (int32_T)(2.0 + (real_T)t);
    if (!((itmp >= 1) && (itmp <= i0))) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, i0, (emlrtBCInfo *)&e_emlrtBCI, sp);
    }

    i0 = U->size[1];
    itmp = (int32_T)(2.0 + (real_T)t);
    if (!((itmp >= 1) && (itmp <= i0))) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, i0, (emlrtBCInfo *)&i_emlrtBCI, sp);
    }

    iv6[0] = r3->size[0];
    r2 = U->size[0];
    i0 = e_U->size[0];
    e_U->size[0] = r2;
    emxEnsureCapacity(sp, (emxArray__common *)e_U, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < r2; i0++) {
      e_U->data[i0] = U->data[i0 + U->size[0] * (t + 1)];
    }

    f_U[0] = e_U->size[0];
    emlrtSubAssignSizeCheckR2012b(iv6, 1, f_U, 1, (emlrtECInfo *)&emlrtECI, sp);
    r2 = U->size[0] - 1;
    for (i0 = 0; i0 <= r2; i0++) {
      X->data[(r3->data[i0] + X->size[0]) + X->size[0] * X->size[1] * (t + 1)] =
        U->data[i0 + U->size[0] * (t + 1)];
    }

    t++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&e_U);
  emxFree_real_T(&f_VU);
  emxFree_int32_T(&r3);
  emxFree_real_T(&b_r1);
  emxFree_real_T(&U);

  /* % convex optimization step */
  for (r1 = 0; r1 < 2; r1++) {
    b[r1] = 0.0;
  }

  for (i0 = 0; i0 < 4; i0++) {
    A[i0] = 0.0;
  }

  t = 1;
  emxInit_real_T(sp, &a, 2, &emlrtRTEI, true);
  emxInit_real_T(sp, &b_b, 2, &emlrtRTEI, true);
  while (t - 1 <= T) {
    st.site = &d_emlrtRSI;
    r2 = X->size[0];
    i0 = X->size[2];
    if (!((t >= 1) && (t <= i0))) {
      emlrtDynamicBoundsCheckR2012b(t, 1, i0, (emlrtBCInfo *)&d_emlrtBCI, &st);
    }

    i0 = a->size[0] * a->size[1];
    a->size[0] = 2;
    a->size[1] = r2;
    emxEnsureCapacity(&st, (emxArray__common *)a, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < r2; i0++) {
      for (itmp = 0; itmp < 2; itmp++) {
        a->data[itmp + a->size[0] * i0] = X->data[(i0 + X->size[0] * itmp) +
          X->size[0] * X->size[1] * (t - 1)];
      }
    }

    r2 = VU->size[0];
    i0 = VU->size[1];
    itmp = 1 + t;
    if (!((itmp >= 1) && (itmp <= i0))) {
      emlrtDynamicBoundsCheckR2012b(itmp, 1, i0, (emlrtBCInfo *)&c_emlrtBCI, &st);
    }

    i0 = vecS->size[0];
    vecS->size[0] = r2;
    emxEnsureCapacity(&st, (emxArray__common *)vecS, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < r2; i0++) {
      vecS->data[i0] = VU->data[i0 + VU->size[0] * (itmp - 1)];
    }

    b_st.site = &u_emlrtRSI;
    i0 = VU->size[0];
    if (!(a->size[1] == i0)) {
      i0 = VU->size[0];
      if (i0 == 1) {
        emlrtErrorWithMessageIdR2012b(&b_st, &n_emlrtRTEI,
          "Coder:toolbox:mtimes_noDynamicScalarExpansion", 0);
      } else {
        emlrtErrorWithMessageIdR2012b(&b_st, &m_emlrtRTEI,
          "Coder:MATLAB:innerdim", 0);
      }
    }

    guard2 = false;
    if (a->size[1] == 1) {
      guard2 = true;
    } else {
      i0 = VU->size[0];
      if (i0 == 1) {
        guard2 = true;
      } else {
        b_st.site = &t_emlrtRSI;
        for (r1 = 0; r1 < 2; r1++) {
          b_y[r1] = 0.0;
        }

        if (a->size[1] < 1) {
        } else {
          c_st.site = &v_emlrtRSI;
          a21 = 1.0;
          a22 = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          m_t = (ptrdiff_t)2;
          n_t = (ptrdiff_t)1;
          k_t = (ptrdiff_t)a->size[1];
          lda_t = (ptrdiff_t)2;
          ldb_t = (ptrdiff_t)a->size[1];
          ldc_t = (ptrdiff_t)2;
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &a21, &a->data[0], &lda_t,
                &vecS->data[0], &ldb_t, &a22, &b_y[0], &ldc_t);
        }
      }
    }

    if (guard2) {
      for (i0 = 0; i0 < 2; i0++) {
        b_y[i0] = 0.0;
        r2 = a->size[1];
        for (itmp = 0; itmp < r2; itmp++) {
          a21 = b_y[i0] + a->data[i0 + a->size[0] * itmp] * vecS->data[itmp];
          b_y[i0] = a21;
        }
      }
    }

    for (i0 = 0; i0 < 2; i0++) {
      b[i0] += b_y[i0];
    }

    st.site = &e_emlrtRSI;
    r2 = X->size[0];
    i0 = X->size[2];
    if (!((t >= 1) && (t <= i0))) {
      emlrtDynamicBoundsCheckR2012b(t, 1, i0, (emlrtBCInfo *)&b_emlrtBCI, &st);
    }

    i0 = a->size[0] * a->size[1];
    a->size[0] = 2;
    a->size[1] = r2;
    emxEnsureCapacity(&st, (emxArray__common *)a, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < r2; i0++) {
      for (itmp = 0; itmp < 2; itmp++) {
        a->data[itmp + a->size[0] * i0] = X->data[(i0 + X->size[0] * itmp) +
          X->size[0] * X->size[1] * (t - 1)];
      }
    }

    r2 = X->size[0];
    i0 = X->size[2];
    if (!((t >= 1) && (t <= i0))) {
      emlrtDynamicBoundsCheckR2012b(t, 1, i0, (emlrtBCInfo *)&emlrtBCI, &st);
    }

    i0 = b_b->size[0] * b_b->size[1];
    b_b->size[0] = r2;
    b_b->size[1] = 2;
    emxEnsureCapacity(&st, (emxArray__common *)b_b, i0, (int32_T)sizeof(real_T),
                      &emlrtRTEI);
    for (i0 = 0; i0 < 2; i0++) {
      for (itmp = 0; itmp < r2; itmp++) {
        b_b->data[itmp + b_b->size[0] * i0] = X->data[(itmp + X->size[0] * i0) +
          X->size[0] * X->size[1] * (t - 1)];
      }
    }

    b_st.site = &u_emlrtRSI;
    i0 = X->size[0];
    if (!(a->size[1] == i0)) {
      emlrtErrorWithMessageIdR2012b(&b_st, &m_emlrtRTEI, "Coder:MATLAB:innerdim",
        0);
    }

    guard1 = false;
    if (a->size[1] == 1) {
      guard1 = true;
    } else {
      i0 = X->size[0];
      if (i0 == 1) {
        guard1 = true;
      } else {
        b_st.site = &t_emlrtRSI;
        for (i0 = 0; i0 < 4; i0++) {
          d_y[i0] = 0.0;
        }

        if (a->size[1] < 1) {
        } else {
          c_st.site = &v_emlrtRSI;
          a21 = 1.0;
          a22 = 0.0;
          TRANSB = 'N';
          TRANSA = 'N';
          m_t = (ptrdiff_t)2;
          n_t = (ptrdiff_t)2;
          k_t = (ptrdiff_t)a->size[1];
          lda_t = (ptrdiff_t)2;
          ldb_t = (ptrdiff_t)a->size[1];
          ldc_t = (ptrdiff_t)2;
          dgemm(&TRANSA, &TRANSB, &m_t, &n_t, &k_t, &a21, &a->data[0], &lda_t,
                &b_b->data[0], &ldb_t, &a22, &d_y[0], &ldc_t);
        }
      }
    }

    if (guard1) {
      for (i0 = 0; i0 < 2; i0++) {
        for (itmp = 0; itmp < 2; itmp++) {
          d_y[i0 + (itmp << 1)] = 0.0;
          r2 = a->size[1];
          for (r1 = 0; r1 < r2; r1++) {
            d_y[i0 + (itmp << 1)] += a->data[i0 + a->size[0] * r1] * b_b->
              data[r1 + b_b->size[0] * itmp];
          }
        }
      }
    }

    for (i0 = 0; i0 < 4; i0++) {
      A[i0] += d_y[i0];
    }

    t++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_b);
  emxFree_real_T(&a);
  emxFree_real_T(&X);
  emxFree_real_T(&vecS);
  emxFree_real_T(&VU);
  r1 = Y0->size[1];
  for (i0 = 0; i0 < 4; i0++) {
    A[i0] /= (real_T)r1;
  }

  r1 = Y0->size[1];
  for (i0 = 0; i0 < 2; i0++) {
    b[i0] /= (real_T)r1;
  }

  /* para_new = (inv(A)*b)';  */
  st.site = &f_emlrtRSI;
  b_st.site = &w_emlrtRSI;
  c_st.site = &x_emlrtRSI;
  if (muDoubleScalarAbs(A[1]) > muDoubleScalarAbs(A[0])) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }

  a21 = A[r2] / A[r1];
  a22 = A[2 + r2] - a21 * A[2 + r1];
  if ((a22 == 0.0) || (A[r1] == 0.0)) {
    d_st.site = &y_emlrtRSI;
    e_st.site = &ab_emlrtRSI;
    warning(&e_st);
  }

  Y[1] = (b[r2] - b[r1] * a21) / a22;
  Y[0] = (b[r1] - Y[1] * A[2 + r1]) / A[r1];
  for (i0 = 0; i0 < 2; i0++) {
    para_new[i0] = Y[i0];
  }

  if ((Y[0] >= 0.0) && (Y[1] >= 0.0) && (Y[0] + Y[1] < 1.0)) {
    b0 = true;
  } else {
    b0 = false;
  }

  if (!b0) {
    /*  case 1) para = [?, 0] */
    p1 = b[0] / A[0];
    if (p1 < 0.0) {
      p1 = 9.9999999999999991E-6;
    } else {
      if (p1 > 1.0) {
        p1 = 0.99999;
      }
    }

    paraAtBoundary[0] = p1;
    paraAtBoundary[3] = 0.0;

    /*  case 2) para = [0, ?] */
    p2 = b[1] / A[3];
    if (p2 < 0.0) {
      p2 = 9.9999999999999991E-6;
    } else {
      if (p2 > 1.0) {
        p2 = 0.99999;
      }
    }

    paraAtBoundary[1] = p2;
    paraAtBoundary[4] = 0.0;

    /*  case 3) para(1)+para(2) = 1 */
    p1 = (((b[0] - b[1]) / 2.0 + A[3]) - A[2]) / ((A[0] - 2.0 * A[2]) + A[3]);
    if (p1 < 0.0) {
      p1 = 9.9999999999999991E-6;
    } else {
      if (p1 > 1.0) {
        p1 = 0.99999;
      }
    }

    paraAtBoundary[2] = p1;
    paraAtBoundary[5] = (1.0 - p1) - 9.9999999999999991E-6;
    k = 0;
    while (k < 3) {
      a21 = 0.0;
      a22 = 0.0;
      for (r1 = 0; r1 < 2; r1++) {
        c_y[r1] = 0.0;
        for (i0 = 0; i0 < 2; i0++) {
          c_y[r1] += paraAtBoundary[k + 3 * i0] * A[i0 + (r1 << 1)];
        }

        a21 += c_y[r1] * paraAtBoundary[k + 3 * r1];
        c_y[r1] = 2.0 * paraAtBoundary[k + 3 * r1];
        a22 += c_y[r1] * b[r1];
      }

      obj[k] = a21 - a22;
      k++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    r1 = 1;
    a21 = obj[0];
    itmp = 0;
    if (muDoubleScalarIsNaN(obj[0])) {
      r2 = 2;
      exitg1 = false;
      while ((!exitg1) && (r2 < 4)) {
        r1 = r2;
        if (!muDoubleScalarIsNaN(obj[r2 - 1])) {
          a21 = obj[r2 - 1];
          itmp = r2 - 1;
          exitg1 = true;
        } else {
          r2++;
        }
      }
    }

    if (r1 < 3) {
      while (r1 + 1 < 4) {
        if (obj[r1] < a21) {
          a21 = obj[r1];
          itmp = r1;
        }

        r1++;
      }
    }

    if (a21 < 0.0) {
      for (i0 = 0; i0 < 2; i0++) {
        para_new[i0] = paraAtBoundary[itmp + 3 * i0];
      }
    } else {
      for (i0 = 0; i0 < 2; i0++) {
        para_new[i0] = 0.0;
      }
    }
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (F.cpp) */
