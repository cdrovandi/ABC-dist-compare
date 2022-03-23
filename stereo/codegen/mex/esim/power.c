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
#include "esim.h"
#include "power.h"
#include "esim_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "error.h"
#include "scalexpAlloc.h"
#include "esim_data.h"

/* Variable Definitions */
static emlrtRSInfo lb_emlrtRSI = { 49, /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 61, /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo ub_emlrtRSI = { 58, /* lineNo */
  "power",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\ops\\power.m"/* pathName */
};

static emlrtRSInfo vb_emlrtRSI = { 73, /* lineNo */
  "applyScalarFunction",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"/* pathName */
};

static emlrtRSInfo wb_emlrtRSI = { 146,/* lineNo */
  "applyScalarFunction",               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\applyScalarFunction.m"/* pathName */
};

/* Function Declarations */
static boolean_T fltpower_domain_error(const emxArray_real_T *a, real_T b);

/* Function Definitions */
static boolean_T fltpower_domain_error(const emxArray_real_T *a, real_T b)
{
  boolean_T p;
  boolean_T b1;
  int32_T k;
  p = false;
  if (a->size[0] == 1) {
    if (a->data[0] < 0.0) {
      if (muDoubleScalarIsNaN(b) || (muDoubleScalarFloor(b) == b)) {
        b1 = true;
      } else {
        b1 = false;
      }

      p = !b1;
    }
  } else {
    if (muDoubleScalarIsNaN(b) || (muDoubleScalarFloor(b) == b)) {
      b1 = true;
    } else {
      b1 = false;
    }

    if (!b1) {
      for (k = 0; k < a->size[0]; k++) {
        if (p || (a->data[k] < 0.0)) {
          p = true;
        } else {
          p = false;
        }
      }
    }
  }

  return p;
}

void b_power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  uint32_T a_idx_0;
  int32_T k;
  boolean_T overflow;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &lb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &ub_emlrtRSI;
  c_st.site = &vb_emlrtRSI;
  a_idx_0 = (uint32_T)a->size[0];
  k = y->size[0];
  y->size[0] = (int32_T)a_idx_0;
  emxEnsureCapacity(&c_st, (emxArray__common *)y, k, sizeof(real_T),
                    &p_emlrtRTEI);
  if (!b_dimagree(y, a)) {
    emlrtErrorWithMessageIdR2012b(&c_st, &ab_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  c_st.site = &wb_emlrtRSI;
  overflow = ((!(1 > a->size[0])) && (a->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &xb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k + 1 <= a->size[0]; k++) {
    y->data[k] = a->data[k] * a->data[k];
  }

  if (fltpower_domain_error(a, 2.0)) {
    b_st.site = &mb_emlrtRSI;
    b_error(&b_st);
  }
}

void c_power(const emlrtStack *sp, const emxArray_real_T *a, emxArray_real_T *y)
{
  uint32_T a_idx_0;
  int32_T k;
  boolean_T overflow;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &lb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &ub_emlrtRSI;
  c_st.site = &vb_emlrtRSI;
  a_idx_0 = (uint32_T)a->size[0];
  k = y->size[0];
  y->size[0] = (int32_T)a_idx_0;
  emxEnsureCapacity(&c_st, (emxArray__common *)y, k, sizeof(real_T),
                    &p_emlrtRTEI);
  if (!b_dimagree(y, a)) {
    emlrtErrorWithMessageIdR2012b(&c_st, &ab_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  c_st.site = &wb_emlrtRSI;
  overflow = ((!(1 > a->size[0])) && (a->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &xb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k + 1 <= a->size[0]; k++) {
    y->data[k] = muDoubleScalarPower(a->data[k], -2.0);
  }

  if (fltpower_domain_error(a, -2.0)) {
    b_st.site = &mb_emlrtRSI;
    b_error(&b_st);
  }
}

void power(const emlrtStack *sp, const emxArray_real_T *a, real_T b,
           emxArray_real_T *y)
{
  uint32_T a_idx_0;
  int32_T k;
  boolean_T overflow;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &lb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &ub_emlrtRSI;
  c_st.site = &vb_emlrtRSI;
  a_idx_0 = (uint32_T)a->size[0];
  k = y->size[0];
  y->size[0] = (int32_T)a_idx_0;
  emxEnsureCapacity(&c_st, (emxArray__common *)y, k, sizeof(real_T),
                    &p_emlrtRTEI);
  if (!b_dimagree(y, a)) {
    emlrtErrorWithMessageIdR2012b(&c_st, &ab_emlrtRTEI, "MATLAB:dimagree", 0);
  }

  c_st.site = &wb_emlrtRSI;
  overflow = ((!(1 > a->size[0])) && (a->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &xb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k + 1 <= a->size[0]; k++) {
    y->data[k] = muDoubleScalarPower(a->data[k], b);
  }

  if (fltpower_domain_error(a, b)) {
    b_st.site = &mb_emlrtRSI;
    b_error(&b_st);
  }
}

/* End of code generation (power.c) */
