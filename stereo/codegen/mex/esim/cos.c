/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cos.c
 *
 * Code generation for function 'cos'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "esim.h"
#include "cos.h"
#include "eml_int_forloop_overflow_check.h"
#include "esim_data.h"

/* Variable Definitions */
static emlrtRSInfo lc_emlrtRSI = { 10, /* lineNo */
  "cos",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\elfun\\cos.m"/* pathName */
};

/* Function Definitions */
void b_cos(const emlrtStack *sp, emxArray_real_T *x)
{
  int32_T nx;
  boolean_T overflow;
  int32_T k;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &lc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  nx = x->size[0];
  b_st.site = &kc_emlrtRSI;
  overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
  if (overflow) {
    c_st.site = &xb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }

  for (k = 0; k + 1 <= nx; k++) {
    x->data[k] = muDoubleScalarCos(x->data[k]);
  }
}

/* End of code generation (cos.c) */
