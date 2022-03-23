/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rand.h
 *
 * Code generation for function 'rand'
 *
 */

#ifndef RAND_H
#define RAND_H

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
#include "esim_types.h"

/* Function Declarations */
extern real_T b_rand(void);

#ifdef __WATCOMC__

#pragma aux b_rand value [8087];

#endif

extern void c_rand(real_T r[2]);
extern void d_rand(const emlrtStack *sp, const real_T varargin_1[2],
                   emxArray_real_T *r);
extern void e_rand(const emlrtStack *sp, real_T varargin_1, emxArray_real_T *r);
extern void f_rand(real_T r[3]);

#endif

/* End of code generation (rand.h) */
