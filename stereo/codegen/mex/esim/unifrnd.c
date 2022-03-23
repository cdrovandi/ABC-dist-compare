/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * unifrnd.c
 *
 * Code generation for function 'unifrnd'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "esim.h"
#include "unifrnd.h"
#include "esim_emxutil.h"
#include "rand.h"
#include "scalexpAlloc.h"
#include "esim_data.h"

/* Variable Definitions */
static emlrtRSInfo rb_emlrtRSI = { 11, /* lineNo */
  "unifrnd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\stats\\eml\\unifrnd.m"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 1,  /* lineNo */
  "unifrnd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\private\\unifrnd.p"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 47, /* lineNo */
  "sxalloc",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\sxalloc.m"/* pathName */
};

static emlrtRTEInfo q_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "unifrnd",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\stats\\eml\\unifrnd.m"/* pName */
};

static emlrtDCInfo emlrtDCI = { 47,    /* lineNo */
  63,                                  /* colNo */
  "sxalloc",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\sxalloc.m",/* pName */
  4                                    /* checkKind */
};

/* Function Definitions */
void b_unifrnd(const emlrtStack *sp, real_T varargin_1, emxArray_real_T *r)
{
  emxArray_boolean_T *r7;
  int32_T i7;
  int32_T loop_ub;
  emxArray_real_T *b;
  real_T dv3[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &r7, 1, &q_emlrtRTEI, true);
  st.site = &rb_emlrtRSI;
  b_st.site = &hb_emlrtRSI;
  c_st.site = &sb_emlrtRSI;
  d_st.site = &tb_emlrtRSI;
  if (!(varargin_1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1, &emlrtDCI, &d_st);
  }

  i7 = r->size[0];
  r->size[0] = (int32_T)varargin_1;
  emxEnsureCapacity(&d_st, (emxArray__common *)r, i7, sizeof(real_T),
                    &p_emlrtRTEI);
  i7 = r7->size[0];
  r7->size[0] = (int32_T)varargin_1;
  emxEnsureCapacity(&d_st, (emxArray__common *)r7, i7, sizeof(boolean_T),
                    &q_emlrtRTEI);
  loop_ub = (int32_T)varargin_1;
  for (i7 = 0; i7 < loop_ub; i7++) {
    r7->data[i7] = false;
  }

  if (!dimagree(r, r7)) {
    emlrtErrorWithMessageIdR2012b(&d_st, &ab_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  emxFree_boolean_T(&r7);
  emxInit_real_T1(&d_st, &b, 2, &q_emlrtRTEI, true);
  dv3[0] = (int32_T)varargin_1;
  dv3[1] = 1.0;
  c_st.site = &sb_emlrtRSI;
  d_rand(&c_st, dv3, b);
  i7 = r->size[0];
  r->size[0] = (int32_T)varargin_1;
  emxEnsureCapacity(&b_st, (emxArray__common *)r, i7, sizeof(real_T),
                    &q_emlrtRTEI);
  loop_ub = (int32_T)varargin_1;
  for (i7 = 0; i7 < loop_ub; i7++) {
    r->data[i7] = 2.0 * b->data[i7] - 1.0;
  }

  emxFree_real_T(&b);
  i7 = r->size[0];
  for (loop_ub = 0; loop_ub < i7; loop_ub++) {
    r->data[loop_ub] = 3.1415926535897931 + 3.1415926535897931 * r->data[loop_ub];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void unifrnd(const emlrtStack *sp, real_T varargin_1, emxArray_real_T *r)
{
  emxArray_boolean_T *r6;
  int32_T i0;
  int32_T loop_ub;
  emxArray_real_T *b;
  real_T dv2[2];
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_boolean_T(sp, &r6, 1, &q_emlrtRTEI, true);
  st.site = &rb_emlrtRSI;
  b_st.site = &hb_emlrtRSI;
  c_st.site = &sb_emlrtRSI;
  d_st.site = &tb_emlrtRSI;
  if (!(varargin_1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1, &emlrtDCI, &d_st);
  }

  i0 = r->size[0];
  r->size[0] = (int32_T)varargin_1;
  emxEnsureCapacity(&d_st, (emxArray__common *)r, i0, sizeof(real_T),
                    &p_emlrtRTEI);
  i0 = r6->size[0];
  r6->size[0] = (int32_T)varargin_1;
  emxEnsureCapacity(&d_st, (emxArray__common *)r6, i0, sizeof(boolean_T),
                    &q_emlrtRTEI);
  loop_ub = (int32_T)varargin_1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    r6->data[i0] = false;
  }

  if (!dimagree(r, r6)) {
    emlrtErrorWithMessageIdR2012b(&d_st, &ab_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  emxFree_boolean_T(&r6);
  emxInit_real_T1(&d_st, &b, 2, &q_emlrtRTEI, true);
  dv2[0] = (int32_T)varargin_1;
  dv2[1] = 1.0;
  c_st.site = &sb_emlrtRSI;
  d_rand(&c_st, dv2, b);
  i0 = r->size[0];
  r->size[0] = (int32_T)varargin_1;
  emxEnsureCapacity(&b_st, (emxArray__common *)r, i0, sizeof(real_T),
                    &q_emlrtRTEI);
  loop_ub = (int32_T)varargin_1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    r->data[i0] = 2.0 * b->data[i0] - 1.0;
  }

  emxFree_real_T(&b);
  i0 = r->size[0];
  for (loop_ub = 0; loop_ub < i0; loop_ub++) {
    r->data[loop_ub] *= 50.0;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (unifrnd.c) */
