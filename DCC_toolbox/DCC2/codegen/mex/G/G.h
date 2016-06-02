/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * G.h
 *
 * Code generation for function 'G'
 *
 */

#ifndef G_H
#define G_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "G_types.h"

/* Function Declarations */
extern real_T G(const emlrtStack *sp, const real_T para[2], const
                emxArray_real_T *Y0, const emxArray_real_T *vecS0);

#ifdef __WATCOMC__

#pragma aux G value [8087];

#endif
#endif

/* End of code generation (G.h) */
