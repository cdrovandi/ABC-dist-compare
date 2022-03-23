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
#include "esim.h"
#include "sqrt.h"
#include "eml_int_forloop_overflow_check.h"
#include "esim_data.h"

/* Variable Definitions */
static emlrtRSInfo nc_emlrtRSI = { 15, /* lineNo */
  "sqrt",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pathName */
};

/* Function Definitions */
void b_sqrt(const emlrtStack *sp, emxArray_creal_T *x)
{
  int32_T nx;
  boolean_T overflow;
  int32_T k;
  real_T xr;
  real_T xi;
  real_T absxi;
  real_T absxr;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &nc_emlrtRSI;
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
    xr = x->data[k].re;
    xi = x->data[k].im;
    if (xi == 0.0) {
      if (xr < 0.0) {
        absxi = 0.0;
        xr = muDoubleScalarSqrt(-xr);
      } else {
        absxi = muDoubleScalarSqrt(xr);
        xr = 0.0;
      }
    } else if (xr == 0.0) {
      if (xi < 0.0) {
        absxi = muDoubleScalarSqrt(-xi / 2.0);
        xr = -absxi;
      } else {
        absxi = muDoubleScalarSqrt(xi / 2.0);
        xr = absxi;
      }
    } else if (muDoubleScalarIsNaN(xr)) {
      absxi = xr;
    } else if (muDoubleScalarIsNaN(xi)) {
      absxi = xi;
      xr = xi;
    } else if (muDoubleScalarIsInf(xi)) {
      absxi = muDoubleScalarAbs(xi);
      xr = xi;
    } else if (muDoubleScalarIsInf(xr)) {
      if (xr < 0.0) {
        absxi = 0.0;
        xr = xi * -xr;
      } else {
        absxi = xr;
        xr = 0.0;
      }
    } else {
      absxr = muDoubleScalarAbs(xr);
      absxi = muDoubleScalarAbs(xi);
      if ((absxr > 4.4942328371557893E+307) || (absxi > 4.4942328371557893E+307))
      {
        absxr *= 0.5;
        absxi *= 0.5;
        absxi = muDoubleScalarHypot(absxr, absxi);
        if (absxi > absxr) {
          absxi = muDoubleScalarSqrt(absxi) * muDoubleScalarSqrt(1.0 + absxr /
            absxi);
        } else {
          absxi = muDoubleScalarSqrt(absxi) * 1.4142135623730951;
        }
      } else {
        absxi = muDoubleScalarSqrt((muDoubleScalarHypot(absxr, absxi) + absxr) *
          0.5);
      }

      if (xr > 0.0) {
        xr = 0.5 * (xi / absxi);
      } else {
        if (xi < 0.0) {
          xr = -absxi;
        } else {
          xr = absxi;
        }

        absxi = 0.5 * (xi / xr);
      }
    }

    x->data[k].re = absxi;
    x->data[k].im = xr;
  }
}

/* End of code generation (sqrt.c) */
