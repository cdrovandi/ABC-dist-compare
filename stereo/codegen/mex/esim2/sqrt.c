/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sqrt.c
 *
 * Code generation for function 'sqrt'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "esim2.h"
#include "sqrt.h"
#include "eml_int_forloop_overflow_check.h"
#include "error.h"
#include "esim2_data.h"

/* Variable Definitions */
static emlrtRSInfo pb_emlrtRSI = { 12, /* lineNo */
  "sqrt",                              /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pathName */
};

static emlrtRSInfo vc_emlrtRSI = { 15, /* lineNo */
  "sqrt",                              /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/elfun/sqrt.m"/* pathName */
};

/* Function Definitions */
void b_sqrt(const emlrtStack *sp, emxArray_real_T *x)
{
  boolean_T overflow;
  int32_T k;
  int32_T nx;
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
  overflow = false;
  for (k = 0; k < x->size[0]; k++) {
    if (overflow || (x->data[k] < 0.0)) {
      overflow = true;
    } else {
      overflow = false;
    }
  }

  if (overflow) {
    st.site = &pb_emlrtRSI;
    b_st.site = &pb_emlrtRSI;
    c_error(&b_st);
  }

  st.site = &vc_emlrtRSI;
  nx = x->size[0];
  b_st.site = &sc_emlrtRSI;
  overflow = ((!(1 > x->size[0])) && (x->size[0] > 2147483646));
  if (overflow) {
    c_st.site = &dc_emlrtRSI;
    d_st.site = &dc_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (k = 0; k + 1 <= nx; k++) {
    x->data[k] = muDoubleScalarSqrt(x->data[k]);
  }
}

/* End of code generation (sqrt.c) */
