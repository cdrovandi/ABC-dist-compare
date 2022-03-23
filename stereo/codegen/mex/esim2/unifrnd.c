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
#include "esim2.h"
#include "unifrnd.h"
#include "esim2_emxutil.h"
#include "scalexpAlloc.h"
#include "esim2_data.h"

/* Variable Definitions */
static emlrtRSInfo ub_emlrtRSI = { 11, /* lineNo */
  "unifrnd",                           /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/stats/eml/unifrnd.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 1,  /* lineNo */
  "unifrnd",                           /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/private/unifrnd.p"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 47, /* lineNo */
  "sxalloc",                           /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/sxalloc.m"/* pathName */
};

static emlrtRTEInfo n_emlrtRTEI = { 47,/* lineNo */
  9,                                   /* colNo */
  "sxalloc",                           /* fName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/sxalloc.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "unifrnd",                           /* fName */
  "/Applications/MATLAB_R2017b.app/toolbox/stats/eml/unifrnd.m"/* pName */
};

static emlrtRTEInfo p_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "unifrnd",                           /* fName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/private/unifrnd.p"/* pName */
};

static emlrtDCInfo emlrtDCI = { 47,    /* lineNo */
  63,                                  /* colNo */
  "sxalloc",                           /* fName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/sxalloc.m",/* pName */
  4                                    /* checkKind */
};

/* Function Definitions */
void b_unifrnd(const emlrtStack *sp, real_T varargin_1, emxArray_real_T *r)
{
  emxArray_real_T *z;
  emxArray_boolean_T *r8;
  int32_T i6;
  int32_T loop_ub;
  emxArray_real_T *b_r;
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
  emxInit_real_T(sp, &z, 1, &o_emlrtRTEI, true);
  emxInit_boolean_T(sp, &r8, 1, &o_emlrtRTEI, true);
  st.site = &ub_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  c_st.site = &vb_emlrtRSI;
  d_st.site = &wb_emlrtRSI;
  if (!(varargin_1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1, &emlrtDCI, &d_st);
  }

  i6 = z->size[0];
  z->size[0] = (int32_T)varargin_1;
  emxEnsureCapacity_real_T(&d_st, z, i6, &n_emlrtRTEI);
  i6 = r8->size[0];
  r8->size[0] = (int32_T)varargin_1;
  emxEnsureCapacity_boolean_T(&d_st, r8, i6, &o_emlrtRTEI);
  loop_ub = (int32_T)varargin_1;
  for (i6 = 0; i6 < loop_ub; i6++) {
    r8->data[i6] = false;
  }

  if (!dimagree(z, r8)) {
    emlrtErrorWithMessageIdR2012b(&d_st, &db_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  emxFree_boolean_T(&r8);
  emxFree_real_T(&z);
  emxInit_real_T1(&d_st, &b_r, 2, &o_emlrtRTEI, true);
  c_st.site = &vb_emlrtRSI;
  i6 = b_r->size[0] * b_r->size[1];
  b_r->size[0] = (int32_T)varargin_1;
  b_r->size[1] = 1;
  emxEnsureCapacity_real_T1(&c_st, b_r, i6, &p_emlrtRTEI);
  if (!(b_r->size[0] == 0)) {
    emlrtRandu(&b_r->data[0], b_r->size[0]);
  }

  i6 = r->size[0];
  r->size[0] = (int32_T)varargin_1;
  emxEnsureCapacity_real_T(&b_st, r, i6, &o_emlrtRTEI);
  loop_ub = (int32_T)varargin_1;
  for (i6 = 0; i6 < loop_ub; i6++) {
    r->data[i6] = 2.0 * b_r->data[i6] - 1.0;
  }

  emxFree_real_T(&b_r);
  i6 = r->size[0];
  for (loop_ub = 0; loop_ub < i6; loop_ub++) {
    r->data[loop_ub] = 3.1415926535897931 + 3.1415926535897931 * r->data[loop_ub];
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void unifrnd(const emlrtStack *sp, real_T varargin_1, emxArray_real_T *r)
{
  emxArray_real_T *z;
  emxArray_boolean_T *r7;
  int32_T i0;
  int32_T loop_ub;
  emxArray_real_T *b_r;
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
  emxInit_real_T(sp, &z, 1, &o_emlrtRTEI, true);
  emxInit_boolean_T(sp, &r7, 1, &o_emlrtRTEI, true);
  st.site = &ub_emlrtRSI;
  b_st.site = &jb_emlrtRSI;
  c_st.site = &vb_emlrtRSI;
  d_st.site = &wb_emlrtRSI;
  if (!(varargin_1 >= 0.0)) {
    emlrtNonNegativeCheckR2012b(varargin_1, &emlrtDCI, &d_st);
  }

  i0 = z->size[0];
  z->size[0] = (int32_T)varargin_1;
  emxEnsureCapacity_real_T(&d_st, z, i0, &n_emlrtRTEI);
  i0 = r7->size[0];
  r7->size[0] = (int32_T)varargin_1;
  emxEnsureCapacity_boolean_T(&d_st, r7, i0, &o_emlrtRTEI);
  loop_ub = (int32_T)varargin_1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    r7->data[i0] = false;
  }

  if (!dimagree(z, r7)) {
    emlrtErrorWithMessageIdR2012b(&d_st, &db_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  emxFree_boolean_T(&r7);
  emxFree_real_T(&z);
  emxInit_real_T1(&d_st, &b_r, 2, &o_emlrtRTEI, true);
  c_st.site = &vb_emlrtRSI;
  i0 = b_r->size[0] * b_r->size[1];
  b_r->size[0] = (int32_T)varargin_1;
  b_r->size[1] = 1;
  emxEnsureCapacity_real_T1(&c_st, b_r, i0, &p_emlrtRTEI);
  if (!(b_r->size[0] == 0)) {
    emlrtRandu(&b_r->data[0], b_r->size[0]);
  }

  i0 = r->size[0];
  r->size[0] = (int32_T)varargin_1;
  emxEnsureCapacity_real_T(&b_st, r, i0, &o_emlrtRTEI);
  loop_ub = (int32_T)varargin_1;
  for (i0 = 0; i0 < loop_ub; i0++) {
    r->data[i0] = 2.0 * b_r->data[i0] - 1.0;
  }

  emxFree_real_T(&b_r);
  i0 = r->size[0];
  for (loop_ub = 0; loop_ub < i0; loop_ub++) {
    r->data[loop_ub] *= 50.0;
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (unifrnd.c) */
