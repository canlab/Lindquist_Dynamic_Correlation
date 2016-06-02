/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sqrt.h
 *
 * Code generation for function 'sqrt'
 *
 */

#ifndef SQRT_H
#define SQRT_H

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
extern void b_sqrt(real_T *x);
extern void c_sqrt(const emlrtStack *sp, emxArray_real_T *x);

#endif

/* End of code generation (sqrt.h) */
