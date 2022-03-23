/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * esim2.h
 *
 * Code generation for function 'esim2'
 *
 */

#ifndef ESIM2_H
#define ESIM2_H

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
#include "esim2_types.h"

/* Function Declarations */
extern void esim2(const emlrtStack *sp, const real_T theta[3], real_T u,
                  emxArray_real_T *res);

#endif

/* End of code generation (esim2.h) */