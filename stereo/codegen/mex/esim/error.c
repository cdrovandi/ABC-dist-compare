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
#include "esim.h"
#include "error.h"

/* Variable Definitions */
static emlrtRTEInfo y_emlrtRTEI = { 17,/* lineNo */
  9,                                   /* colNo */
  "error",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\error.m"/* pName */
};

/* Function Definitions */
void b_error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &y_emlrtRTEI,
    "Coder:toolbox:power_domainError", 0);
}

void error(const emlrtStack *sp)
{
  emlrtErrorWithMessageIdR2012b(sp, &y_emlrtRTEI,
    "Coder:toolbox:ElFunDomainError", 3, 4, 3, "log");
}

/* End of code generation (error.c) */
