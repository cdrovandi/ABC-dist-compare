/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * poissrnd.h
 *
 * Code generation for function 'poissrnd'
 *
 */

#ifndef POISSRND_H
#define POISSRND_H

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
extern real_T poissrnd(const emlrtStack *sp, real_T lambda);

#ifdef __WATCOMC__

#pragma aux poissrnd value [8087];

#endif
#endif

/* End of code generation (poissrnd.h) */
