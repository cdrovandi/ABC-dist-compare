/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * randn.c
 *
 * Code generation for function 'randn'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "esim.h"
#include "randn.h"

/* Function Definitions */
real_T randn(void)
{
  real_T r;
  emlrtRandn(&r, 1);
  return r;
}

/* End of code generation (randn.c) */
