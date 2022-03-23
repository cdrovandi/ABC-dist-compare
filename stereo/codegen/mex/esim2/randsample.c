/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * randsample.c
 *
 * Code generation for function 'randsample'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "esim2.h"
#include "randsample.h"

/* Function Definitions */
void randsample(const real_T varargin_1[3], real_T y[3])
{
  real_T rp[3];
  boolean_T p;
  int8_T idx[3];
  int32_T j;
  emlrtRandu(&rp[0], 3);
  if ((rp[0] <= rp[1]) || muDoubleScalarIsNaN(rp[1])) {
    p = true;
  } else {
    p = false;
  }

  if (p) {
    if ((rp[1] <= rp[2]) || muDoubleScalarIsNaN(rp[2])) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      idx[0] = 1;
      idx[1] = 2;
      idx[2] = 3;
    } else {
      if ((rp[0] <= rp[2]) || muDoubleScalarIsNaN(rp[2])) {
        p = true;
      } else {
        p = false;
      }

      if (p) {
        idx[0] = 1;
        idx[1] = 3;
        idx[2] = 2;
      } else {
        idx[0] = 3;
        idx[1] = 1;
        idx[2] = 2;
      }
    }
  } else {
    if ((rp[0] <= rp[2]) || muDoubleScalarIsNaN(rp[2])) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      idx[0] = 2;
      idx[1] = 1;
      idx[2] = 3;
    } else {
      if ((rp[1] <= rp[2]) || muDoubleScalarIsNaN(rp[2])) {
        p = true;
      } else {
        p = false;
      }

      if (p) {
        idx[0] = 2;
        idx[1] = 3;
        idx[2] = 1;
      } else {
        idx[0] = 3;
        idx[1] = 2;
        idx[2] = 1;
      }
    }
  }

  for (j = 0; j < 3; j++) {
    rp[j] = idx[j];
  }

  for (j = 0; j < 3; j++) {
    y[j] = varargin_1[(int32_T)rp[j] - 1];
  }
}

/* End of code generation (randsample.c) */
