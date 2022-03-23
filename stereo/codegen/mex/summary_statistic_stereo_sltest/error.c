/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * error.c
 *
 * Code generation for function 'error'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "summary_statistic_stereo_sltest.h"
#include "error.h"

/* Variable Definitions */
static emlrtRTEInfo c_emlrtRTEI = { 19,/* lineNo */
  5,                                   /* colNo */
  "error",                             /* fName */
  "/Applications/MATLAB_R2017b.app/toolbox/shared/coder/coder/+coder/+internal/error.m"/* pName */
};

/* Function Definitions */
void b_error(const emlrtStack *sp)
{
  static const char_T varargin_1[3] = { 'l', 'o', 'g' };

  emlrtErrorWithMessageIdR2012b(sp, &c_emlrtRTEI,
    "Coder:toolbox:ElFunDomainError", 3, 4, 3, varargin_1);
}

void error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &c_emlrtRTEI, "MATLAB:nologicalnan", 0);
}

/* End of code generation (error.c) */
