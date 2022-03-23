/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sin.c
 *
 * Code generation for function 'sin'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "esim2.h"
#include "sin.h"
#include "eml_int_forloop_overflow_check.h"
#include "esim2_data.h"

/* Variable Definitions */
static emlrtRSInfo rc_emlrtRSI = { 10, /* lineNo */
  "sin",                               /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/elfun/sin.m"/* pathName */
};

/* Function Definitions */
void b_sin(const emlrtStack *sp, emxArray_real_T *x)
{
  int32_T nx;
  boolean_T overflow;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  nx = x->size[0];
  b_st.site = &sc_emlrtRSI;
  overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
  if (overflow) {
    c_st.site = &dc_emlrtRSI;
    d_st.site = &dc_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k + 1 <= nx; k++) {
    x->data[k] = muDoubleScalarSin(x->data[k]);
  }
}

/* End of code generation (sin.c) */
