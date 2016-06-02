/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * epsilonToY.cpp
 *
 * Code generation for function 'epsilonToY'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "G.h"
#include "epsilonToY.h"
#include "G_emxutil.h"
#include "power.h"
#include "G_data.h"
#include "blas.h"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = { 19, "epsilonToY",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/epsilonToY.m" };

static emlrtRTEInfo i_emlrtRTEI = { 1, 18, "epsilonToY",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/epsilonToY.m" };

static emlrtBCInfo x_emlrtBCI = { -1, -1, 19, 25, "epsilon", "epsilonToY",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/epsilonToY.m", 0
};

static emlrtBCInfo y_emlrtBCI = { -1, -1, 19, 7, "Y", "epsilonToY",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/epsilonToY.m", 0
};

static emlrtBCInfo ab_emlrtBCI = { -1, -1, 19, 11, "Y", "epsilonToY",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/epsilonToY.m", 0
};

static emlrtECInfo n_emlrtECI = { -1, 19, 5, "epsilonToY",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/epsilonToY.m" };

static emlrtDCInfo d_emlrtDCI = { 15, 11, "epsilonToY",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/epsilonToY.m", 1
};

static emlrtBCInfo bb_emlrtBCI = { -1, -1, 24, 34, "epsilon", "epsilonToY",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/epsilonToY.m", 0
};

static emlrtBCInfo cb_emlrtBCI = { -1, -1, 24, 36, "epsilon", "epsilonToY",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/epsilonToY.m", 0
};

static emlrtBCInfo db_emlrtBCI = { -1, -1, 24, 47, "epsilon", "epsilonToY",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/epsilonToY.m", 0
};

static emlrtBCInfo eb_emlrtBCI = { -1, -1, 24, 49, "epsilon", "epsilonToY",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/epsilonToY.m", 0
};

static emlrtBCInfo fb_emlrtBCI = { -1, -1, 24, 15, "Y", "epsilonToY",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/epsilonToY.m", 0
};

static emlrtBCInfo gb_emlrtBCI = { -1, -1, 24, 21, "Y", "epsilonToY",
  "/Users/xuyuting/Dropbox/YutingMartin/20160518 toolboxes/DCC2/epsilonToY.m", 0
};

/* Function Definitions */
void epsilonToY(const emlrtStack *sp, const emxArray_real_T *epsilon,
                emxArray_real_T *Y)
{
  int32_T K;
  real_T y;
  int32_T i1;
  int32_T loop_ub;
  int32_T t;
  emxArray_int32_T *r4;
  emxArray_real_T *r5;
  emxArray_real_T *r6;
  emxArray_real_T *b_epsilon;
  int32_T iv7[1];
  int32_T count;
  int32_T i;
  int32_T j;
  int32_T i2;
  int32_T i3;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);

  /* Auxiliary function */
  /*    Input:  */
  /*        epsilon: T-by-K residual time series */
  /*    Output: */
  /*        Y: K*(K+1)/2-by-T matrix, vecterized outer product time series */
  /*    Used by: */
  /*        F.m */
  K = epsilon->size[1];
  y = (real_T)((uint32_T)epsilon->size[1] * (epsilon->size[1] + 1)) / 2.0;
  i1 = Y->size[0] * Y->size[1];
  if (y != muDoubleScalarFloor(y)) {
    emlrtIntegerCheckR2012b(y, (emlrtDCInfo *)&d_emlrtDCI, sp);
  }

  Y->size[0] = (int32_T)y;
  Y->size[1] = epsilon->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)Y, i1, (int32_T)sizeof(real_T),
                    &i_emlrtRTEI);
  if (y != muDoubleScalarFloor(y)) {
    emlrtIntegerCheckR2012b(y, (emlrtDCInfo *)&d_emlrtDCI, sp);
  }

  loop_ub = (int32_T)y * epsilon->size[0];
  for (i1 = 0; i1 < loop_ub; i1++) {
    Y->data[i1] = 0.0;
  }

  t = 1;
  emxInit_int32_T(sp, &r4, 1, &i_emlrtRTEI, true);
  emxInit_real_T1(sp, &r5, 1, &i_emlrtRTEI, true);
  emxInit_real_T(sp, &r6, 2, &i_emlrtRTEI, true);
  emxInit_real_T(sp, &b_epsilon, 2, &i_emlrtRTEI, true);
  while (t - 1 <= epsilon->size[0] - 1) {
    if (1 > K) {
      loop_ub = 0;
    } else {
      i1 = Y->size[0];
      if (!(1 <= i1)) {
        emlrtDynamicBoundsCheckR2012b(1, 1, i1, (emlrtBCInfo *)&y_emlrtBCI, sp);
      }

      i1 = Y->size[0];
      if (!(K <= i1)) {
        emlrtDynamicBoundsCheckR2012b(K, 1, i1, (emlrtBCInfo *)&y_emlrtBCI, sp);
      }

      loop_ub = K;
    }

    i1 = r4->size[0];
    r4->size[0] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)r4, i1, (int32_T)sizeof(int32_T),
                      &i_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r4->data[i1] = i1;
    }

    i1 = Y->size[1];
    loop_ub = (t - 1) + 1;
    if (!((loop_ub >= 1) && (loop_ub <= i1))) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 1, i1, (emlrtBCInfo *)&ab_emlrtBCI,
        sp);
    }

    loop_ub = epsilon->size[1];
    i1 = epsilon->size[0];
    if (!((t >= 1) && (t <= i1))) {
      emlrtDynamicBoundsCheckR2012b(t, 1, i1, (emlrtBCInfo *)&x_emlrtBCI, sp);
    }

    i1 = b_epsilon->size[0] * b_epsilon->size[1];
    b_epsilon->size[0] = 1;
    b_epsilon->size[1] = loop_ub;
    emxEnsureCapacity(sp, (emxArray__common *)b_epsilon, i1, (int32_T)sizeof
                      (real_T), &i_emlrtRTEI);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_epsilon->data[b_epsilon->size[0] * i1] = epsilon->data[(t +
        epsilon->size[0] * i1) - 1];
    }

    st.site = &l_emlrtRSI;
    power(&st, b_epsilon, r6);
    i1 = r5->size[0];
    r5->size[0] = r6->size[1];
    emxEnsureCapacity(sp, (emxArray__common *)r5, i1, (int32_T)sizeof(real_T),
                      &i_emlrtRTEI);
    loop_ub = r6->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      r5->data[i1] = r6->data[r6->size[0] * i1];
    }

    iv7[0] = r4->size[0];
    emlrtSubAssignSizeCheckR2012b(iv7, 1, *(int32_T (*)[1])r5->size, 1,
      (emlrtECInfo *)&n_emlrtECI, sp);
    loop_ub = r5->size[0];
    for (i1 = 0; i1 < loop_ub; i1++) {
      Y->data[r4->data[i1] + Y->size[0] * (t - 1)] = r5->data[i1];
    }

    count = K;
    i = 2;
    while (i - 2 <= K - 1) {
      i1 = K - i;
      j = 0;
      while (j <= i1) {
        count++;
        loop_ub = epsilon->size[0];
        if (!((t >= 1) && (t <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(t, 1, loop_ub, (emlrtBCInfo *)
            &bb_emlrtBCI, sp);
        }

        loop_ub = epsilon->size[1];
        i2 = i - 1;
        if (!((i2 >= 1) && (i2 <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(i2, 1, loop_ub, (emlrtBCInfo *)
            &cb_emlrtBCI, sp);
        }

        loop_ub = epsilon->size[0];
        if (!((t >= 1) && (t <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(t, 1, loop_ub, (emlrtBCInfo *)
            &db_emlrtBCI, sp);
        }

        loop_ub = epsilon->size[1];
        i3 = i + j;
        if (!((i3 >= 1) && (i3 <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(i3, 1, loop_ub, (emlrtBCInfo *)
            &eb_emlrtBCI, sp);
        }

        loop_ub = Y->size[0];
        if (!((count >= 1) && (count <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(count, 1, loop_ub, (emlrtBCInfo *)
            &fb_emlrtBCI, sp);
        }

        loop_ub = Y->size[1];
        if (!((t >= 1) && (t <= loop_ub))) {
          emlrtDynamicBoundsCheckR2012b(t, 1, loop_ub, (emlrtBCInfo *)
            &gb_emlrtBCI, sp);
        }

        Y->data[(count + Y->size[0] * (t - 1)) - 1] = epsilon->data[(t +
          epsilon->size[0] * (i2 - 1)) - 1] * epsilon->data[(t + epsilon->size[0]
          * (i3 - 1)) - 1];
        j++;
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(sp);
        }
      }

      i++;
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b(sp);
      }
    }

    t++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  emxFree_real_T(&b_epsilon);
  emxFree_real_T(&r6);
  emxFree_real_T(&r5);
  emxFree_int32_T(&r4);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (epsilonToY.cpp) */
