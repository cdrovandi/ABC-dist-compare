/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * summary_statistic_stereo_sltest.c
 *
 * Code generation for function 'summary_statistic_stereo_sltest'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "summary_statistic_stereo_sltest.h"
#include "error.h"
#include "eml_int_forloop_overflow_check.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 14,    /* lineNo */
  "summary_statistic_stereo_sltest",   /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/summary_statistic_stereo_sltest.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 15,  /* lineNo */
  "summary_statistic_stereo_sltest",   /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/summary_statistic_stereo_sltest.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 16,  /* lineNo */
  "summary_statistic_stereo_sltest",   /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/summary_statistic_stereo_sltest.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 18,  /* lineNo */
  "summary_statistic_stereo_sltest",   /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/summary_statistic_stereo_sltest.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 19,  /* lineNo */
  "summary_statistic_stereo_sltest",   /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/summary_statistic_stereo_sltest.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 13,  /* lineNo */
  "min",                               /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/datafun/min.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 19,  /* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 140, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 376, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 348, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 21,  /* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 38,  /* lineNo */
  "mean",                              /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/datafun/mean.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 106, /* lineNo */
  "combineVectorElements",             /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 166, /* lineNo */
  "combineVectorElements",             /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/datafun/private/combineVectorElements.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 13,  /* lineNo */
  "max",                               /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 12,  /* lineNo */
  "toLogicalCheck",                    /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/toLogicalCheck.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 13,  /* lineNo */
  "log",                               /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/elfun/log.m"/* pathName */
};

/* Function Definitions */
void summary_statistic_stereo_sltest(const emlrtStack *sp, const emxArray_real_T
  *y, real_T useLog, real_T ss[4])
{
  int32_T ixstart;
  int32_T n;
  real_T mtmp;
  boolean_T overflow;
  int32_T ix;
  boolean_T exitg1;
  real_T x[2];
  static const int8_T iv0[2] = { 2, 3 };

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
  for (ixstart = 0; ixstart < 4; ixstart++) {
    ss[ixstart] = 0.0;
  }

  if (y->size[0] != 0) {
    /*  compute the summary statistics */
    ss[0] = y->size[0];
    st.site = &emlrtRSI;
    b_st.site = &f_emlrtRSI;
    c_st.site = &g_emlrtRSI;
    d_st.site = &h_emlrtRSI;
    ixstart = 1;
    n = y->size[0];
    mtmp = y->data[0];
    if (y->size[0] > 1) {
      if (muDoubleScalarIsNaN(y->data[0])) {
        e_st.site = &j_emlrtRSI;
        overflow = (y->size[0] > 2147483646);
        if (overflow) {
          f_st.site = &k_emlrtRSI;
          g_st.site = &k_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        ix = 2;
        exitg1 = false;
        while ((!exitg1) && (ix <= n)) {
          ixstart = ix;
          if (!muDoubleScalarIsNaN(y->data[ix - 1])) {
            mtmp = y->data[ix - 1];
            exitg1 = true;
          } else {
            ix++;
          }
        }
      }

      if (ixstart < y->size[0]) {
        e_st.site = &i_emlrtRSI;
        overflow = ((!(ixstart + 1 > y->size[0])) && (y->size[0] > 2147483646));
        if (overflow) {
          f_st.site = &k_emlrtRSI;
          g_st.site = &k_emlrtRSI;
          check_forloop_overflow_error(&g_st);
        }

        while (ixstart + 1 <= n) {
          if (y->data[ixstart] < mtmp) {
            mtmp = y->data[ixstart];
          }

          ixstart++;
        }
      }
    }

    ss[1] = mtmp;
    st.site = &b_emlrtRSI;
    b_st.site = &l_emlrtRSI;
    c_st.site = &m_emlrtRSI;
    mtmp = y->data[0];
    d_st.site = &n_emlrtRSI;
    overflow = ((!(2 > y->size[0])) && (y->size[0] > 2147483646));
    if (overflow) {
      e_st.site = &k_emlrtRSI;
      f_st.site = &k_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }

    for (ixstart = 2; ixstart <= y->size[0]; ixstart++) {
      mtmp += y->data[ixstart - 1];
    }

    ss[2] = mtmp / (real_T)y->size[0];
    st.site = &c_emlrtRSI;
    b_st.site = &o_emlrtRSI;
    c_st.site = &g_emlrtRSI;
    d_st.site = &h_emlrtRSI;
    ixstart = 1;
    n = y->size[0];
    mtmp = y->data[0];
    if (y->size[0] > 1) {
      if (muDoubleScalarIsNaN(y->data[0])) {
        e_st.site = &j_emlrtRSI;
        ix = 2;
        exitg1 = false;
        while ((!exitg1) && (ix <= n)) {
          ixstart = ix;
          if (!muDoubleScalarIsNaN(y->data[ix - 1])) {
            mtmp = y->data[ix - 1];
            exitg1 = true;
          } else {
            ix++;
          }
        }
      }

      if (ixstart < y->size[0]) {
        e_st.site = &i_emlrtRSI;
        while (ixstart + 1 <= n) {
          if (y->data[ixstart] > mtmp) {
            mtmp = y->data[ixstart];
          }

          ixstart++;
        }
      }
    }

    ss[3] = mtmp;
    st.site = &d_emlrtRSI;
    if (muDoubleScalarIsNaN(useLog)) {
      b_st.site = &p_emlrtRSI;
      c_st.site = &p_emlrtRSI;
      error(&c_st);
    }

    if (useLog != 0.0) {
      st.site = &e_emlrtRSI;
      overflow = false;
      for (ixstart = 0; ixstart < 2; ixstart++) {
        x[ixstart] = ss[2 + ixstart];
        if (overflow || (ss[iv0[ixstart]] < 0.0)) {
          overflow = true;
        } else {
          overflow = false;
        }
      }

      if (overflow) {
        b_st.site = &q_emlrtRSI;
        c_st.site = &q_emlrtRSI;
        b_error(&c_st);
      }

      for (ixstart = 0; ixstart < 2; ixstart++) {
        x[ixstart] = muDoubleScalarLog(x[ixstart]);
      }

      for (ixstart = 0; ixstart < 2; ixstart++) {
        ss[2 + ixstart] = x[ixstart];
      }
    }
  }
}

/* End of code generation (summary_statistic_stereo_sltest.c) */
