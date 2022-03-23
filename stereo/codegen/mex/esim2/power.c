/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * power.c
 *
 * Code generation for function 'power'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "esim2.h"
#include "power.h"
#include "esim2_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "scalexpAlloc.h"
#include "error.h"
#include "esim2_data.h"

/* Variable Definitions */
static emlrtRSInfo nb_emlrtRSI = { 49, /* lineNo */
  "power",                             /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 61, /* lineNo */
  "power",                             /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo xb_emlrtRSI = { 58, /* lineNo */
  "power",                             /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 60, /* lineNo */
  "power",                             /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 45, /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo bc_emlrtRSI = { 65, /* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo cc_emlrtRSI = { 189,/* lineNo */
  "applyBinaryScalarFunction",         /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 80, /* lineNo */
  "power",                             /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/ops/power.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 36, /* lineNo */
  "vAllOrAny",                         /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/vAllOrAny.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 96, /* lineNo */
  "vAllOrAny",                         /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/vAllOrAny.m"/* pathName */
};

static emlrtRTEInfo r_emlrtRTEI = { 19,/* lineNo */
  24,                                  /* colNo */
  "scalexpAllocNoCheck",               /* fName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/scalexpAllocNoCheck.m"/* pName */
};

static emlrtRTEInfo s_emlrtRTEI = { 45,/* lineNo */
  6,                                   /* colNo */
  "applyBinaryScalarFunction",         /* fName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/applyBinaryScalarFunction.m"/* pName */
};

static emlrtRTEInfo t_emlrtRTEI = { 58,/* lineNo */
  5,                                   /* colNo */
  "power",                             /* fName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 1, /* lineNo */
  14,                                  /* colNo */
  "power",                             /* fName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/ops/power.m"/* pName */
};

/* Function Definitions */
void b_power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  emxArray_real_T *z;
  emxArray_real_T *b_z;
  uint32_T a_idx_0;
  int32_T k;
  uint32_T b_a_idx_0;
  boolean_T overflow;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &z, 1, &u_emlrtRTEI, true);
  emxInit_real_T(sp, &b_z, 1, &u_emlrtRTEI, true);
  st.site = &nb_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &ac_emlrtRSI;
  a_idx_0 = (uint32_T)a->size[0];
  k = b_z->size[0];
  b_z->size[0] = (int32_T)a_idx_0;
  emxEnsureCapacity_real_T(&c_st, b_z, k, &r_emlrtRTEI);
  a_idx_0 = (uint32_T)a->size[0];
  b_a_idx_0 = (uint32_T)a->size[0];
  k = z->size[0];
  z->size[0] = (int32_T)b_a_idx_0;
  emxEnsureCapacity_real_T(&c_st, z, k, &s_emlrtRTEI);
  if (!b_dimagree(z, a)) {
    emlrtErrorWithMessageIdR2012b(&c_st, &db_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  emxFree_real_T(&z);
  b_a_idx_0 = (uint32_T)a->size[0];
  k = y->size[0];
  y->size[0] = (int32_T)b_a_idx_0;
  emxEnsureCapacity_real_T(&b_st, y, k, &t_emlrtRTEI);
  c_st.site = &bc_emlrtRSI;
  d_st.site = &cc_emlrtRSI;
  overflow = ((!(1 > b_z->size[0])) && (b_z->size[0] > 2147483646));
  emxFree_real_T(&b_z);
  if (overflow) {
    e_st.site = &dc_emlrtRSI;
    f_st.site = &dc_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (k = 0; k + 1 <= (int32_T)a_idx_0; k++) {
    y->data[k] = muDoubleScalarPower(a->data[k], 2.0);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void c_power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  emxArray_real_T *z;
  emxArray_real_T *b_z;
  uint32_T a_idx_0;
  int32_T k;
  uint32_T b_a_idx_0;
  boolean_T overflow;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &z, 1, &u_emlrtRTEI, true);
  emxInit_real_T(sp, &b_z, 1, &u_emlrtRTEI, true);
  st.site = &nb_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &ac_emlrtRSI;
  a_idx_0 = (uint32_T)a->size[0];
  k = b_z->size[0];
  b_z->size[0] = (int32_T)a_idx_0;
  emxEnsureCapacity_real_T(&c_st, b_z, k, &r_emlrtRTEI);
  a_idx_0 = (uint32_T)a->size[0];
  b_a_idx_0 = (uint32_T)a->size[0];
  k = z->size[0];
  z->size[0] = (int32_T)b_a_idx_0;
  emxEnsureCapacity_real_T(&c_st, z, k, &s_emlrtRTEI);
  if (!b_dimagree(z, a)) {
    emlrtErrorWithMessageIdR2012b(&c_st, &db_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  emxFree_real_T(&z);
  b_a_idx_0 = (uint32_T)a->size[0];
  k = y->size[0];
  y->size[0] = (int32_T)b_a_idx_0;
  emxEnsureCapacity_real_T(&b_st, y, k, &t_emlrtRTEI);
  c_st.site = &bc_emlrtRSI;
  d_st.site = &cc_emlrtRSI;
  overflow = ((!(1 > b_z->size[0])) && (b_z->size[0] > 2147483646));
  emxFree_real_T(&b_z);
  if (overflow) {
    e_st.site = &dc_emlrtRSI;
    f_st.site = &dc_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (k = 0; k + 1 <= (int32_T)a_idx_0; k++) {
    y->data[k] = muDoubleScalarPower(a->data[k], -2.0);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

void power(const emlrtStack *sp, const emxArray_real_T *a, real_T b,
           emxArray_real_T *y)
{
  emxArray_real_T *z;
  emxArray_real_T *b_z;
  uint32_T a_idx_0;
  int32_T k;
  uint32_T b_a_idx_0;
  boolean_T overflow;
  boolean_T p;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_real_T(sp, &z, 1, &u_emlrtRTEI, true);
  emxInit_real_T(sp, &b_z, 1, &u_emlrtRTEI, true);
  st.site = &nb_emlrtRSI;
  b_st.site = &xb_emlrtRSI;
  c_st.site = &ac_emlrtRSI;
  a_idx_0 = (uint32_T)a->size[0];
  k = b_z->size[0];
  b_z->size[0] = (int32_T)a_idx_0;
  emxEnsureCapacity_real_T(&c_st, b_z, k, &r_emlrtRTEI);
  a_idx_0 = (uint32_T)a->size[0];
  b_a_idx_0 = (uint32_T)a->size[0];
  k = z->size[0];
  z->size[0] = (int32_T)b_a_idx_0;
  emxEnsureCapacity_real_T(&c_st, z, k, &s_emlrtRTEI);
  if (!b_dimagree(z, a)) {
    emlrtErrorWithMessageIdR2012b(&c_st, &db_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  emxFree_real_T(&z);
  b_a_idx_0 = (uint32_T)a->size[0];
  k = y->size[0];
  y->size[0] = (int32_T)b_a_idx_0;
  emxEnsureCapacity_real_T(&b_st, y, k, &t_emlrtRTEI);
  c_st.site = &bc_emlrtRSI;
  d_st.site = &cc_emlrtRSI;
  overflow = ((!(1 > b_z->size[0])) && (b_z->size[0] > 2147483646));
  emxFree_real_T(&b_z);
  if (overflow) {
    e_st.site = &dc_emlrtRSI;
    f_st.site = &dc_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (k = 0; k + 1 <= (int32_T)a_idx_0; k++) {
    y->data[k] = muDoubleScalarPower(a->data[k], b);
  }

  b_st.site = &yb_emlrtRSI;
  if (a->size[0] == 1) {
    if (a->data[0] < 0.0) {
      if ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarFloor(b) != b)) {
        p = true;
      } else {
        p = false;
      }

      if (p) {
        p = true;
      } else {
        p = false;
      }
    } else {
      p = false;
    }
  } else {
    if ((!muDoubleScalarIsNaN(b)) && (muDoubleScalarFloor(b) != b)) {
      p = true;
    } else {
      p = false;
    }

    if (p) {
      c_st.site = &ec_emlrtRSI;
      d_st.site = &fc_emlrtRSI;
      p = false;
      e_st.site = &gc_emlrtRSI;
      overflow = ((!(1 > a->size[0])) && (a->size[0] > 2147483646));
      if (overflow) {
        f_st.site = &dc_emlrtRSI;
        g_st.site = &dc_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      for (k = 1; k <= a->size[0]; k++) {
        if (p || (a->data[k - 1] < 0.0)) {
          p = true;
        } else {
          p = false;
        }
      }
    } else {
      p = false;
    }
  }

  if (p) {
    b_st.site = &ob_emlrtRSI;
    c_st.site = &ob_emlrtRSI;
    b_error(&c_st);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (power.c) */
