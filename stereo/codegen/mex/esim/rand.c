/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rand.c
 *
 * Code generation for function 'rand'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "esim.h"
#include "rand.h"
#include "esim_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo r_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "rand",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\randfun\\rand.m"/* pName */
};

static emlrtDCInfo b_emlrtDCI = { 100, /* lineNo */
  34,                                  /* colNo */
  "rand",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\randfun\\rand.m",/* pName */
  4                                    /* checkKind */
};

/* Function Definitions */
real_T b_rand(void)
{
  real_T r;
  emlrtRandu(&r, 1);
  return r;
}

void c_rand(real_T r[2])
{
  emlrtRandu(&r[0], 2);
}

void d_rand(const emlrtStack *sp, const real_T varargin_1[2], emxArray_real_T *r)
{
  int32_T i3;
  i3 = r->size[0] * r->size[1];
  r->size[0] = (int32_T)varargin_1[0];
  r->size[1] = 1;
  emxEnsureCapacity(sp, (emxArray__common *)r, i3, sizeof(real_T), &r_emlrtRTEI);
  if (!(r->size[0] == 0)) {
    emlrtRandu(&r->data[0], r->size[0]);
  }
}

void e_rand(const emlrtStack *sp, real_T varargin_1, emxArray_real_T *r)
{
  int32_T i4;
  i4 = r->size[0];
  if (!(varargin_1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1, &b_emlrtDCI, sp);
  }

  r->size[0] = (int32_T)varargin_1;
  emxEnsureCapacity(sp, (emxArray__common *)r, i4, sizeof(real_T), &r_emlrtRTEI);
  if (!(r->size[0] == 0)) {
    emlrtRandu(&r->data[0], r->size[0]);
  }
}

void f_rand(real_T r[3])
{
  emlrtRandu(&r[0], 3);
}

/* End of code generation (rand.c) */
