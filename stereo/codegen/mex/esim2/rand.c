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
#include "esim2.h"
#include "rand.h"
#include "esim2_emxutil.h"

/* Variable Definitions */
static emlrtRTEInfo q_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "rand",                              /* fName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/randfun/rand.m"/* pName */
};

static emlrtDCInfo b_emlrtDCI = { 100, /* lineNo */
  34,                                  /* colNo */
  "rand",                              /* fName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/randfun/rand.m",/* pName */
  4                                    /* checkKind */
};

/* Function Definitions */
void b_rand(const emlrtStack *sp, real_T varargin_1, emxArray_real_T *r)
{
  int32_T i3;
  i3 = r->size[0];
  if (!(varargin_1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1, &b_emlrtDCI, sp);
  }

  r->size[0] = (int32_T)varargin_1;
  emxEnsureCapacity_real_T(sp, r, i3, &q_emlrtRTEI);
  if (!(r->size[0] == 0)) {
    emlrtRandu(&r->data[0], r->size[0]);
  }
}

/* End of code generation (rand.c) */
