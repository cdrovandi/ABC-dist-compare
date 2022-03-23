/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rdivide.c
 *
 * Code generation for function 'rdivide'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "esim.h"
#include "rdivide.h"
#include "esim_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo s_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "rdivide",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m"/* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = { 13,/* lineNo */
  15,                                  /* colNo */
  "rdivide",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\rdivide.m"/* pName */
};

/* Function Definitions */
void b_rdivide(const emlrtStack *sp, const emxArray_real_T *y, emxArray_real_T
               *z)
{
  int32_T i8;
  int32_T loop_ub;
  i8 = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, i8, sizeof(real_T), &s_emlrtRTEI);
  loop_ub = y->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    z->data[i8] = 1.0 / y->data[i8];
  }
}

void rdivide(const emlrtStack *sp, const emxArray_real_T *x, const
             emxArray_real_T *y, emxArray_real_T *z)
{
  uint32_T varargin_1[2];
  uint32_T varargin_2[2];
  boolean_T p;
  boolean_T b_p;
  int32_T k;
  boolean_T exitg1;
  int32_T loop_ub;
  varargin_1[0] = (uint32_T)x->size[0];
  varargin_1[1] = 1U;
  varargin_2[0] = (uint32_T)y->size[0];
  varargin_2[1] = 1U;
  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!((int32_T)varargin_1[k] == (int32_T)varargin_2[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    emlrtErrorWithMessageIdR2012b(sp, &cb_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  k = z->size[0];
  z->size[0] = x->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, k, sizeof(real_T), &s_emlrtRTEI);
  loop_ub = x->size[0];
  for (k = 0; k < loop_ub; k++) {
    z->data[k] = x->data[k] / y->data[k];
  }
}

/* End of code generation (rdivide.c) */
