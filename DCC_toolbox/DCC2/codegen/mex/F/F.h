/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * F.h
 *
 * Code generation for function 'F'
 *
 */

#ifndef F_H
#define F_H

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
#include "F_types.h"

/* Function Declarations */
extern void F(const emlrtStack *sp, const real_T para[2], const emxArray_real_T *
              Y0, const emxArray_real_T *vecS0, real_T para_new[2]);

#endif

/* End of code generation (F.h) */
