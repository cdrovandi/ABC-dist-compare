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
#include "esim.h"
#include "poissrnd.h"
#include "rand.h"
#include "randn.h"
#include "error.h"
#include "warning.h"
#include "esim_data.h"

/* Variable Definitions */
static emlrtRSInfo cb_emlrtRSI = { 27, /* lineNo */
  "poissrnd",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\stats\\eml\\poissrnd.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 30, /* lineNo */
  "poissrnd",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\stats\\eml\\poissrnd.m"/* pathName */
};

static emlrtRSInfo eb_emlrtRSI = { 37, /* lineNo */
  "poissrnd",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\stats\\eml\\poissrnd.m"/* pathName */
};

static emlrtRSInfo fb_emlrtRSI = { 42, /* lineNo */
  "poissrnd",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\stats\\eml\\poissrnd.m"/* pathName */
};

static emlrtRSInfo gb_emlrtRSI = { 16, /* lineNo */
  "randg",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\stats\\eml\\randg.m"/* pathName */
};

static emlrtRSInfo ib_emlrtRSI = { 1,  /* lineNo */
  "randg",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\private\\randg.p"/* pathName */
};

static emlrtRSInfo jb_emlrtRSI = { 13, /* lineNo */
  "log",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\elfun\\log.m"/* pathName */
};

static emlrtRSInfo nb_emlrtRSI = { 16, /* lineNo */
  "binornd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\stats\\eml\\binornd.m"/* pathName */
};

static emlrtRSInfo ob_emlrtRSI = { 1,  /* lineNo */
  "binornd",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\private\\binornd.p"/* pathName */
};

static emlrtRSInfo pb_emlrtRSI = { 54, /* lineNo */
  "poissrnd",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\stats\\eml\\poissrnd.m"/* pathName */
};

static emlrtRSInfo qb_emlrtRSI = { 57, /* lineNo */
  "poissrnd",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\stats\\eml\\poissrnd.m"/* pathName */
};

static emlrtRTEInfo x_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "binornd",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\private\\binornd.p"/* pName */
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
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  r = 0.0;
  st.site = &pb_emlrtRSI;
  x = b_rand();
  st.site = &pb_emlrtRSI;
  if (x < 0.0) {
    b_st.site = &jb_emlrtRSI;
    error(&b_st);
  }

  for (p = -muDoubleScalarLog(x); p < lambda; p -= muDoubleScalarLog(x)) {
    r++;
    st.site = &qb_emlrtRSI;
    x = b_rand();
    st.site = &qb_emlrtRSI;
    if (x < 0.0) {
      b_st.site = &jb_emlrtRSI;
      error(&b_st);
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
  lk = lambda;
  if (lambda >= 0.0) {
    if (muDoubleScalarIsInf(lambda)) {
      r = rtInf;
    } else if (lambda >= 15.0) {
      r = 0.0;
      do {
        exitg1 = 0;
        m = muDoubleScalarFloor(0.875 * lk);
        st.site = &cb_emlrtRSI;
        b_st.site = &gb_emlrtRSI;
        c_st.site = &hb_emlrtRSI;
        d_st.site = &ib_emlrtRSI;
        if ((!muDoubleScalarIsInf(m)) && (!muDoubleScalarIsNaN(m))) {
          if (m >= 1.0) {
            d = m - 0.33333333333333331;
            e_st.site = &ib_emlrtRSI;
            u = b_rand();
            p = 1.0;
          } else {
            d = rtNaN;
            e_st.site = &ib_emlrtRSI;
            c_rand(ur);
            u = ur[0];
            e_st.site = &ib_emlrtRSI;
            p = rtNaN;
          }

          e_st.site = &ib_emlrtRSI;
          c = 1.0 / muDoubleScalarSqrt(9.0 * d);
          iter = 0;
          v = 0.0;
          x = 0.0;
          reject = true;
          while (reject) {
            for (v = -1.0; v <= 0.0; v = 1.0 + c * x) {
              e_st.site = &ib_emlrtRSI;
              x = randn();
            }

            v *= v * v;
            x *= x;
            if (u < 1.0 - 0.0331 * x * x) {
              reject = false;
            } else {
              e_st.site = &ib_emlrtRSI;
              if (u < 0.0) {
                f_st.site = &jb_emlrtRSI;
                error(&f_st);
              }

              e_st.site = &ib_emlrtRSI;
              if (muDoubleScalarLog(u) < 0.5 * x + d * ((1.0 - v) +
                   muDoubleScalarLog(v))) {
                reject = false;
              } else {
                iter++;
                if (iter > 1000000) {
                  e_st.site = &ib_emlrtRSI;
                  warning(&e_st);
                  reject = false;
                } else {
                  e_st.site = &ib_emlrtRSI;
                  u = b_rand();
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
            st.site = &db_emlrtRSI;
            b_st.site = &nb_emlrtRSI;
            c_st.site = &hb_emlrtRSI;
            if ((0.0 <= p) && (p <= 1.0) && (m - 1.0 == m - 1.0)) {
              lk = 0.0;
              emlrtForLoopVectorCheckR2012b(1.0, 1.0, m - 1.0, mxDOUBLE_CLASS,
                (int32_T)(m - 1.0), &x_emlrtRTEI, &c_st);
              for (iter = 0; iter < (int32_T)(m - 1.0); iter++) {
                d_st.site = &ob_emlrtRSI;
                if (b_rand() < p) {
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
            st.site = &eb_emlrtRSI;
            r += poissrnd_small_lambda(&st, lk);
            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    } else {
      st.site = &fb_emlrtRSI;
      r = poissrnd_small_lambda(&st, lambda);
    }
  } else {
    r = rtNaN;
  }

  return r;
}

/* End of code generation (poissrnd.c) */
