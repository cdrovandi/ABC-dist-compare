/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * scalexpAlloc.c
 *
 * Code generation for function 'scalexpAlloc'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "esim.h"
#include "scalexpAlloc.h"

/* Function Definitions */
boolean_T b_dimagree(const emxArray_real_T *z, const emxArray_real_T *varargin_1)
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  boolean_T exitg1;
  int32_T i5;
  int32_T i6;
  p = true;
  b_p = true;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (k <= 1) {
      i5 = z->size[0];
      i6 = varargin_1->size[0];
    } else {
      i5 = 1;
      i6 = 1;
    }

    if (i5 != i6) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!b_p) {
    p = false;
  }

  return p;
}

boolean_T dimagree(const emxArray_real_T *z, const emxArray_boolean_T
                   *varargin_3)
{
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  boolean_T exitg1;
  int32_T i1;
  int32_T i2;
  p = true;
  b_p = true;
  k = 1;
  exitg1 = false;
  while ((!exitg1) && (k < 3)) {
    if (k <= 1) {
      i1 = z->size[0];
      i2 = varargin_3->size[0];
    } else {
      i1 = 1;
      i2 = 1;
    }

    if (i1 != i2) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (!b_p) {
    p = false;
  }

  return p;
}

/* End of code generation (scalexpAlloc.c) */
