/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * poissrnd.c
 *
 * Code generation for function 'poissrnd'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "esim2.h"
#include "poissrnd.h"
#include "error.h"
#include "warning.h"
#include "esim2_data.h"

/* Variable Definitions */
static emlrtRSInfo eb_emlrtRSI = { 27, /* lineNo */
  "poissrnd",                          /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/stats/eml/poissrnd.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 30, /* lineNo */
  "poissrnd",                          /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/stats/eml/poissrnd.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 37, /* lineNo */
  "poissrnd",                          /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/stats/eml/poissrnd.m"/* pathName */
};

static emlrtRSInfo hb_emlrtRSI = { 42, /* lineNo */
  "poissrnd",                          /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/stats/eml/poissrnd.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 16, /* lineNo */
  "randg",                             /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/stats/eml/randg.m"/* pathName */
};

static emlrtRSInfo kb_emlrtRSI = { 1,  /* lineNo */
  "randg",                             /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/private/randg.p"/* pathName */
};

static emlrtRSInfo lb_emlrtRSI = { 13, /* lineNo */
  "log",                               /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/elfun/log.m"/* pathName */
};

static emlrtRSInfo mb_emlrtRSI = { 40, /* lineNo */
  "mpower",                            /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/ops/mpower.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 16, /* lineNo */
  "binornd",                           /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/stats/eml/binornd.m"/* pathName */
};

static emlrtRSInfo rb_emlrtRSI = { 1,  /* lineNo */
  "binornd",                           /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/private/binornd.p"/* pathName */
};

static emlrtRSInfo sb_emlrtRSI = { 54, /* lineNo */
  "poissrnd",                          /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/stats/eml/poissrnd.m"/* pathName */
};

static emlrtRSInfo tb_emlrtRSI = { 57, /* lineNo */
  "poissrnd",                          /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/stats/eml/poissrnd.m"/* pathName */
};

static emlrtRTEInfo bb_emlrtRTEI = { 1,/* lineNo */
  1,                                   /* colNo */
  "binornd",                           /* fName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/private/binornd.p"/* pName */
};

/* Function Declarations */
static real_T poissrnd_small_lambda(const emlrtStack *sp, real_T lambda);

/* Function Definitions */
static real_T poissrnd_small_lambda(const emlrtStack *sp, real_T lambda)
{
  real_T r;
  real_T x;
  real_T p;
  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  r = 0.0;
  st.site = &sb_emlrtRSI;
  emlrtRandu(&x, 1);
  st.site = &sb_emlrtRSI;
  if (x < 0.0) {
    b_st.site = &lb_emlrtRSI;
    c_st.site = &lb_emlrtRSI;
    error(&c_st);
  }

  for (p = -muDoubleScalarLog(x); p < lambda; p -= muDoubleScalarLog(x)) {
    r++;
    st.site = &tb_emlrtRSI;
    emlrtRandu(&x, 1);
    st.site = &tb_emlrtRSI;
    if (x < 0.0) {
      b_st.site = &lb_emlrtRSI;
      c_st.site = &lb_emlrtRSI;
      error(&c_st);
    }
  }

  return r;
}

real_T poissrnd(const emlrtStack *sp, real_T lambda)
{
  real_T r;
  real_T lk;
  int32_T exitg1;
  real_T m;
  real_T x;
  real_T d;
  real_T ur[2];
  real_T u;
  real_T p;
  real_T c;
  int32_T iter;
  real_T v;
  boolean_T reject;
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
  lk = lambda;
  if (lambda >= 0.0) {
    if (muDoubleScalarIsInf(lambda)) {
      r = rtInf;
    } else if (lambda >= 15.0) {
      r = 0.0;
      do {
        exitg1 = 0;
        m = muDoubleScalarFloor(0.875 * lk);
        st.site = &eb_emlrtRSI;
        b_st.site = &ib_emlrtRSI;
        c_st.site = &jb_emlrtRSI;
        d_st.site = &kb_emlrtRSI;
        if ((!muDoubleScalarIsInf(m)) && (!muDoubleScalarIsNaN(m))) {
          if (m >= 1.0) {
            d = m - 0.33333333333333331;
            e_st.site = &kb_emlrtRSI;
            emlrtRandu(&u, 1);
            p = 1.0;
          } else {
            d = rtNaN;
            e_st.site = &kb_emlrtRSI;
            emlrtRandu(&ur[0], 2);
            u = ur[0];
            e_st.site = &kb_emlrtRSI;
            f_st.site = &mb_emlrtRSI;
            p = rtNaN;
          }

          e_st.site = &kb_emlrtRSI;
          c = 1.0 / muDoubleScalarSqrt(9.0 * d);
          iter = 0;
          v = 0.0;
          x = 0.0;
          reject = true;
          while (reject) {
            for (v = -1.0; v <= 0.0; v = 1.0 + c * x) {
              e_st.site = &kb_emlrtRSI;
              emlrtRandn(&x, 1);
            }

            v *= v * v;
            x *= x;
            if (u < 1.0 - 0.0331 * x * x) {
              reject = false;
            } else {
              e_st.site = &kb_emlrtRSI;
              if (u < 0.0) {
                f_st.site = &lb_emlrtRSI;
                g_st.site = &lb_emlrtRSI;
                error(&g_st);
              }

              e_st.site = &kb_emlrtRSI;
              if (muDoubleScalarLog(u) < 0.5 * x + d * ((1.0 - v) +
                   muDoubleScalarLog(v))) {
                reject = false;
              } else {
                iter++;
                if (iter > 1000000) {
                  e_st.site = &kb_emlrtRSI;
                  warning(&e_st);
                  reject = false;
                } else {
                  e_st.site = &kb_emlrtRSI;
                  emlrtRandu(&u, 1);
                }
              }
            }
          }

          x = d * v * p;
        } else {
          x = m;
        }

        if (lk < x) {
          if (m > 1.0) {
            p = lk / x;
            st.site = &fb_emlrtRSI;
            b_st.site = &qb_emlrtRSI;
            c_st.site = &jb_emlrtRSI;
            if ((p <= 1.0) && (m - 1.0 == m - 1.0)) {
              lk = 0.0;
              emlrtForLoopVectorCheckR2012b(1.0, 1.0, m - 1.0, mxDOUBLE_CLASS,
                (int32_T)(m - 1.0), &bb_emlrtRTEI, &c_st);
              for (iter = 0; iter < (int32_T)(m - 1.0); iter++) {
                d_st.site = &rb_emlrtRSI;
                emlrtRandu(&x, 1);
                if (x < p) {
                  lk++;
                }
              }
            } else {
              lk = rtNaN;
            }

            r += lk;
          }

          exitg1 = 1;
        } else {
          lk -= x;
          r += m;
          if (lk < 15.0) {
            st.site = &gb_emlrtRSI;
            r += poissrnd_small_lambda(&st, lk);
            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    } else {
      st.site = &hb_emlrtRSI;
      r = poissrnd_small_lambda(&st, lambda);
    }
  } else {
    r = rtNaN;
  }

  return r;
}

/* End of code generation (poissrnd.c) */
