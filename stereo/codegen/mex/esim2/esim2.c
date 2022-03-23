/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * esim2.c
 *
 * Code generation for function 'esim2'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "esim2.h"
#include "randsample.h"
#include "rdivide.h"
#include "esim2_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "sqrt.h"
#include "power.h"
#include "cos.h"
#include "sin.h"
#include "atan.h"
#include "unifrnd.h"
#include "rand.h"
#include "poissrnd.h"
#include "esim2_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 7,     /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 9,   /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 11,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 13,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 14,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 16,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 18,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 25,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 28,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 29,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 30,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 31,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 32,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 35,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 36,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 37,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 38,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 39,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 40,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 43,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 46,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 47,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 48,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 49,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 56,  /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 57, /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 59, /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo cb_emlrtRSI = { 60, /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo db_emlrtRSI = { 63, /* lineNo */
  "esim2",                             /* fcnName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 20, /* lineNo */
  "cat",                               /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 100,/* lineNo */
  "cat",                               /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/cat.m"/* pathName */
};

static emlrtRSInfo lc_emlrtRSI = { 13, /* lineNo */
  "max",                               /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/datafun/max.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 19, /* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo nc_emlrtRSI = { 213,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo oc_emlrtRSI = { 214,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo pc_emlrtRSI = { 376,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRSInfo qc_emlrtRSI = { 348,/* lineNo */
  "minOrMax",                          /* fcnName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  16,                                  /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 19,/* lineNo */
  16,                                  /* colNo */
  "minOrMax",                          /* fName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/minOrMax.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 9, /* lineNo */
  1,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 11,/* lineNo */
  1,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 14,/* lineNo */
  1,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 16,/* lineNo */
  1,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 25,/* lineNo */
  1,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 28,/* lineNo */
  1,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 29,/* lineNo */
  1,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 30,/* lineNo */
  1,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 31,/* lineNo */
  1,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 36,/* lineNo */
  1,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  13,                                  /* lineNo */
  3,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  14,                                  /* lineNo */
  4,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtRTEInfo x_emlrtRTEI = { 17,/* lineNo */
  9,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  22,                                  /* colNo */
  "pars",                              /* aName */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  10,                                  /* colNo */
  "pars",                              /* aName */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  31,                                  /* lineNo */
  3,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  32,                                  /* lineNo */
  3,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo e_emlrtECI = { -1,  /* nDims */
  35,                                  /* lineNo */
  5,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo f_emlrtECI = { -1,  /* nDims */
  36,                                  /* lineNo */
  4,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  37,                                  /* lineNo */
  4,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo h_emlrtECI = { -1,  /* nDims */
  38,                                  /* lineNo */
  4,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo i_emlrtECI = { -1,  /* nDims */
  43,                                  /* lineNo */
  16,                                  /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo j_emlrtECI = { -1,  /* nDims */
  46,                                  /* lineNo */
  4,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo k_emlrtECI = { -1,  /* nDims */
  46,                                  /* lineNo */
  21,                                  /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo l_emlrtECI = { -1,  /* nDims */
  46,                                  /* lineNo */
  44,                                  /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo m_emlrtECI = { -1,  /* nDims */
  47,                                  /* lineNo */
  4,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo n_emlrtECI = { -1,  /* nDims */
  47,                                  /* lineNo */
  21,                                  /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo o_emlrtECI = { -1,  /* nDims */
  47,                                  /* lineNo */
  44,                                  /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo p_emlrtECI = { -1,  /* nDims */
  48,                                  /* lineNo */
  4,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo q_emlrtECI = { -1,  /* nDims */
  48,                                  /* lineNo */
  16,                                  /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo r_emlrtECI = { -1,  /* nDims */
  49,                                  /* lineNo */
  4,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo s_emlrtECI = { -1,  /* nDims */
  49,                                  /* lineNo */
  17,                                  /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo t_emlrtECI = { -1,  /* nDims */
  56,                                  /* lineNo */
  30,                                  /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo u_emlrtECI = { -1,  /* nDims */
  56,                                  /* lineNo */
  9,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo v_emlrtECI = { -1,  /* nDims */
  57,                                  /* lineNo */
  17,                                  /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo w_emlrtECI = { -1,  /* nDims */
  57,                                  /* lineNo */
  9,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtECInfo x_emlrtECI = { -1,  /* nDims */
  58,                                  /* lineNo */
  7,                                   /* colNo */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m"/* pName */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  65,                                  /* lineNo */
  7,                                   /* colNo */
  "dm",                                /* aName */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo y_emlrtRTEI = { 281,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/eml/+coder/+internal/cat.m"/* pName */
};

static emlrtRTEInfo ab_emlrtRTEI = { 19,/* lineNo */
  19,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "/Applications/MATLAB_R2017b.app/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  59,                                  /* lineNo */
  17,                                  /* colNo */
  "temp1",                             /* aName */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  60,                                  /* lineNo */
  17,                                  /* colNo */
  "temp2",                             /* aName */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  11,                                  /* colNo */
  "res",                               /* aName */
  "esim2",                             /* fName */
  "/Users/ziwen/Dropbox/BSL High Dim Cov/Code/Stereo/esim2.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void esim2(const emlrtStack *sp, const real_T theta[3], real_T u,
           emxArray_real_T *res)
{
  emxArray_real_T *z;
  emxArray_real_T *r0;
  emxArray_real_T *r1;
  boolean_T overflow;
  real_T nn;
  int32_T a;
  int32_T loop_ub;
  emxArray_real_T *b_a;
  emxArray_real_T *b;
  int32_T trueCount;
  emxArray_real_T *cc;
  boolean_T b0;
  emxArray_real_T *pars;
  int32_T ixstop;
  real_T dv0[3];
  real_T dv1[3];
  int32_T vstride;
  real_T b_pars[3];
  emxArray_real_T *dm;
  emxArray_real_T *th;
  emxArray_real_T *ph;
  real_T mtmp;
  boolean_T exitg1;
  emxArray_real_T *p;
  emxArray_real_T *r2;
  emxArray_real_T *q;
  emxArray_real_T *b_ph;
  emxArray_real_T *A1;
  emxArray_boolean_T *r3;
  emxArray_boolean_T *r4;
  emxArray_int32_T *r5;
  emxArray_int32_T *r6;
  emxArray_real_T *varargin_1;
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
  emxInit_real_T(sp, &z, 1, &c_emlrtRTEI, true);
  emxInit_real_T(sp, &r0, 1, &emlrtRTEI, true);
  emxInit_real_T(sp, &r1, 1, &emlrtRTEI, true);
  overflow = false;
  st.site = &emlrtRSI;
  nn = poissrnd(&st, theta[0] * 100.0);
  st.site = &b_emlrtRSI;
  unifrnd(&st, nn, z);
  st.site = &c_emlrtRSI;
  b_rand(&st, nn, r0);
  a = r1->size[0];
  r1->size[0] = r0->size[0];
  emxEnsureCapacity_real_T(sp, r1, a, &emlrtRTEI);
  loop_ub = r0->size[0];
  for (a = 0; a < loop_ub; a++) {
    r1->data[a] = 1.0 - r0->data[a];
  }

  emxInit_real_T(sp, &b_a, 1, &d_emlrtRTEI, true);
  st.site = &c_emlrtRSI;
  power(&st, r1, -theta[2], b_a);
  a = b_a->size[0];
  emxEnsureCapacity_real_T(sp, b_a, a, &emlrtRTEI);
  loop_ub = b_a->size[0];
  for (a = 0; a < loop_ub; a++) {
    b_a->data[a]--;
  }

  a = b_a->size[0];
  emxEnsureCapacity_real_T(sp, b_a, a, &emlrtRTEI);
  loop_ub = b_a->size[0];
  for (a = 0; a < loop_ub; a++) {
    b_a->data[a] = (u + theta[1] * b_a->data[a] / theta[2]) / 2.0;
  }

  emxInit_real_T(sp, &b, 1, &e_emlrtRTEI, true);
  st.site = &d_emlrtRSI;
  b_rand(&st, nn, b);
  a = b->size[0];
  trueCount = b_a->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &emlrtECI, sp);
  }

  a = b->size[0];
  emxEnsureCapacity_real_T(sp, b, a, &emlrtRTEI);
  loop_ub = b->size[0];
  for (a = 0; a < loop_ub; a++) {
    b->data[a] *= b_a->data[a];
  }

  emxInit_real_T(sp, &cc, 1, &f_emlrtRTEI, true);
  st.site = &e_emlrtRSI;
  b_rand(&st, nn, cc);
  a = cc->size[0];
  trueCount = b_a->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &b_emlrtECI, sp);
  }

  a = cc->size[0];
  emxEnsureCapacity_real_T(sp, cc, a, &emlrtRTEI);
  loop_ub = cc->size[0];
  for (a = 0; a < loop_ub; a++) {
    cc->data[a] *= b_a->data[a];
  }

  st.site = &f_emlrtRSI;
  b_st.site = &hc_emlrtRSI;
  c_st.site = &ic_emlrtRSI;
  b0 = true;
  if (b->size[0] != b_a->size[0]) {
    b0 = false;
  }

  if (!b0) {
    emlrtErrorWithMessageIdR2012b(&c_st, &y_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if (cc->size[0] != b_a->size[0]) {
    b0 = false;
  }

  if (!b0) {
    emlrtErrorWithMessageIdR2012b(&c_st, &y_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_real_T1(&c_st, &pars, 2, &g_emlrtRTEI, true);
  a = pars->size[0] * pars->size[1];
  pars->size[0] = b_a->size[0];
  pars->size[1] = 3;
  emxEnsureCapacity_real_T1(&b_st, pars, a, &emlrtRTEI);
  loop_ub = b_a->size[0];
  for (a = 0; a < loop_ub; a++) {
    pars->data[a] = b_a->data[a];
  }

  loop_ub = b->size[0];
  for (a = 0; a < loop_ub; a++) {
    pars->data[a + pars->size[0]] = b->data[a];
  }

  loop_ub = cc->size[0];
  for (a = 0; a < loop_ub; a++) {
    pars->data[a + (pars->size[0] << 1)] = cc->data[a];
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nn, mxDOUBLE_CLASS, (int32_T)nn,
    &x_emlrtRTEI, sp);
  ixstop = 1;
  while (ixstop - 1 <= (int32_T)nn - 1) {
    if (!overflow) {
      for (a = 0; a < 3; a++) {
        dv0[a] = 1.0 + (real_T)a;
      }

      overflow = true;
    }

    st.site = &g_emlrtRSI;
    randsample(dv0, dv1);
    vstride = pars->size[0];
    if (!((ixstop >= 1) && (ixstop <= vstride))) {
      emlrtDynamicBoundsCheckR2012b(ixstop, 1, vstride, &emlrtBCI, sp);
    }

    vstride = pars->size[0];
    if (!((ixstop >= 1) && (ixstop <= vstride))) {
      emlrtDynamicBoundsCheckR2012b(ixstop, 1, vstride, &b_emlrtBCI, sp);
    }

    for (a = 0; a < 3; a++) {
      b_pars[a] = pars->data[(ixstop + pars->size[0] * ((int32_T)dv1[a] - 1)) -
        1];
    }

    for (a = 0; a < 3; a++) {
      pars->data[(ixstop + pars->size[0] * a) - 1] = b_pars[a];
    }

    ixstop++;
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(sp);
    }
  }

  loop_ub = pars->size[0];
  a = b_a->size[0];
  b_a->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_a, a, &emlrtRTEI);
  for (a = 0; a < loop_ub; a++) {
    b_a->data[a] = pars->data[a];
  }

  loop_ub = pars->size[0];
  a = b->size[0];
  b->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, b, a, &emlrtRTEI);
  for (a = 0; a < loop_ub; a++) {
    b->data[a] = pars->data[a + pars->size[0]];
  }

  loop_ub = pars->size[0];
  a = cc->size[0];
  cc->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, cc, a, &emlrtRTEI);
  for (a = 0; a < loop_ub; a++) {
    cc->data[a] = pars->data[a + (pars->size[0] << 1)];
  }

  st.site = &h_emlrtRSI;
  b_st.site = &hc_emlrtRSI;
  c_st.site = &ic_emlrtRSI;
  overflow = true;
  a = pars->size[0];
  trueCount = pars->size[0];
  if (a != trueCount) {
    overflow = false;
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2012b(&c_st, &y_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  a = pars->size[0];
  trueCount = pars->size[0];
  if (a != trueCount) {
    overflow = false;
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2012b(&c_st, &y_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  a = pars->size[0] * pars->size[1];
  pars->size[0] = b_a->size[0];
  pars->size[1] = 3;
  emxEnsureCapacity_real_T1(&b_st, pars, a, &emlrtRTEI);
  loop_ub = b_a->size[0];
  for (a = 0; a < loop_ub; a++) {
    pars->data[a] = b_a->data[a];
  }

  loop_ub = b->size[0];
  for (a = 0; a < loop_ub; a++) {
    pars->data[a + pars->size[0]] = b->data[a];
  }

  loop_ub = cc->size[0];
  for (a = 0; a < loop_ub; a++) {
    pars->data[a + (pars->size[0] << 1)] = cc->data[a];
  }

  emxInit_real_T(&b_st, &dm, 1, &h_emlrtRTEI, true);
  st.site = &h_emlrtRSI;
  b_st.site = &lc_emlrtRSI;
  c_st.site = &mc_emlrtRSI;
  a = dm->size[0];
  dm->size[0] = pars->size[0];
  emxEnsureCapacity_real_T(&c_st, dm, a, &b_emlrtRTEI);
  vstride = pars->size[0];
  d_st.site = &nc_emlrtRSI;
  overflow = ((!(1 > pars->size[0])) && (pars->size[0] > 2147483646));
  if (overflow) {
    e_st.site = &dc_emlrtRSI;
    f_st.site = &dc_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (loop_ub = 1; loop_ub <= vstride; loop_ub++) {
    d_st.site = &oc_emlrtRSI;
    trueCount = loop_ub;
    ixstop = loop_ub + (vstride << 1);
    mtmp = pars->data[loop_ub - 1];
    if (muDoubleScalarIsNaN(pars->data[loop_ub - 1])) {
      a = loop_ub + vstride;
      e_st.site = &qc_emlrtRSI;
      if ((vstride == 0) || (a > ixstop)) {
        overflow = false;
      } else {
        overflow = (ixstop > MAX_int32_T - vstride);
      }

      if (vstride == 0) {
        emlrtErrorWithMessageIdR2012b(&e_st, &ab_emlrtRTEI,
          "Coder:builtins:VectorStride", 0);
      }

      if (overflow) {
        f_st.site = &dc_emlrtRSI;
        g_st.site = &dc_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      exitg1 = false;
      while ((!exitg1) && (a <= ixstop)) {
        trueCount = a;
        if (!muDoubleScalarIsNaN(pars->data[a - 1])) {
          mtmp = pars->data[a - 1];
          exitg1 = true;
        } else {
          a += vstride;
        }
      }
    }

    if (trueCount < ixstop) {
      a = trueCount + vstride;
      e_st.site = &pc_emlrtRSI;
      if ((vstride == 0) || (a > ixstop)) {
        overflow = false;
      } else {
        overflow = (ixstop > MAX_int32_T - vstride);
      }

      if (vstride == 0) {
        emlrtErrorWithMessageIdR2012b(&e_st, &ab_emlrtRTEI,
          "Coder:builtins:VectorStride", 0);
      }

      if (overflow) {
        f_st.site = &dc_emlrtRSI;
        g_st.site = &dc_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      while (a <= ixstop) {
        if (pars->data[a - 1] > mtmp) {
          mtmp = pars->data[a - 1];
        }

        a += vstride;
      }
    }

    dm->data[loop_ub - 1] = mtmp;
  }

  emxFree_real_T(&pars);
  emxInit_real_T(&c_st, &th, 1, &i_emlrtRTEI, true);
  emxInit_real_T(&c_st, &ph, 1, &j_emlrtRTEI, true);
  st.site = &i_emlrtRSI;
  b_unifrnd(&st, nn, th);
  st.site = &j_emlrtRSI;
  b_unifrnd(&st, nn, ph);
  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity_real_T(sp, r0, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  for (a = 0; a < loop_ub; a++) {
    r0->data[a] = ph->data[a];
  }

  st.site = &k_emlrtRSI;
  b_sin(&st, r0);
  a = r1->size[0];
  r1->size[0] = r0->size[0];
  emxEnsureCapacity_real_T(sp, r1, a, &emlrtRTEI);
  loop_ub = r0->size[0];
  for (a = 0; a < loop_ub; a++) {
    r1->data[a] = -r0->data[a];
  }

  emxInit_real_T(sp, &p, 1, &k_emlrtRTEI, true);
  st.site = &k_emlrtRSI;
  rdivide(&st, r1, z, p);
  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity_real_T(sp, r0, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  for (a = 0; a < loop_ub; a++) {
    r0->data[a] = ph->data[a];
  }

  emxInit_real_T(sp, &r2, 1, &emlrtRTEI, true);
  st.site = &l_emlrtRSI;
  b_cos(&st, r0);
  a = r2->size[0];
  r2->size[0] = th->size[0];
  emxEnsureCapacity_real_T(sp, r2, a, &emlrtRTEI);
  loop_ub = th->size[0];
  for (a = 0; a < loop_ub; a++) {
    r2->data[a] = th->data[a];
  }

  st.site = &l_emlrtRSI;
  b_sin(&st, r2);
  a = r0->size[0];
  trueCount = r2->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &c_emlrtECI, sp);
  }

  a = r1->size[0];
  r1->size[0] = r0->size[0];
  emxEnsureCapacity_real_T(sp, r1, a, &emlrtRTEI);
  loop_ub = r0->size[0];
  for (a = 0; a < loop_ub; a++) {
    r1->data[a] = r0->data[a] * r2->data[a];
  }

  emxInit_real_T(sp, &q, 1, &l_emlrtRTEI, true);
  emxInit_real_T(sp, &b_ph, 1, &emlrtRTEI, true);
  st.site = &l_emlrtRSI;
  rdivide(&st, r1, z, q);
  st.site = &m_emlrtRSI;
  b_cos(&st, ph);
  st.site = &m_emlrtRSI;
  b_cos(&st, th);
  a = ph->size[0];
  trueCount = th->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &d_emlrtECI, sp);
  }

  a = b_ph->size[0];
  b_ph->size[0] = ph->size[0];
  emxEnsureCapacity_real_T(sp, b_ph, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  for (a = 0; a < loop_ub; a++) {
    b_ph->data[a] = ph->data[a] * th->data[a];
  }

  st.site = &m_emlrtRSI;
  rdivide(&st, b_ph, z, th);
  st.site = &n_emlrtRSI;
  b_power(&st, th, ph);
  st.site = &n_emlrtRSI;
  b_power(&st, cc, r0);
  a = ph->size[0];
  trueCount = r0->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &e_emlrtECI, sp);
  }

  a = ph->size[0];
  emxEnsureCapacity_real_T(sp, ph, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  for (a = 0; a < loop_ub; a++) {
    ph->data[a] *= r0->data[a];
  }

  emxInit_real_T(sp, &A1, 1, &m_emlrtRTEI, true);
  st.site = &o_emlrtRSI;
  c_power(&st, b_a, A1);
  st.site = &o_emlrtRSI;
  b_power(&st, p, r0);
  st.site = &o_emlrtRSI;
  rdivide(&st, r0, ph, r2);
  a = A1->size[0];
  trueCount = r2->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &f_emlrtECI, sp);
  }

  a = A1->size[0];
  emxEnsureCapacity_real_T(sp, A1, a, &emlrtRTEI);
  loop_ub = A1->size[0];
  for (a = 0; a < loop_ub; a++) {
    A1->data[a] += r2->data[a];
  }

  a = p->size[0];
  trueCount = q->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &g_emlrtECI, sp);
  }

  a = b_ph->size[0];
  b_ph->size[0] = p->size[0];
  emxEnsureCapacity_real_T(sp, b_ph, a, &emlrtRTEI);
  loop_ub = p->size[0];
  for (a = 0; a < loop_ub; a++) {
    b_ph->data[a] = p->data[a] * q->data[a];
  }

  st.site = &p_emlrtRSI;
  rdivide(&st, b_ph, ph, th);
  st.site = &q_emlrtRSI;
  c_power(&st, b, b_a);
  st.site = &q_emlrtRSI;
  b_power(&st, q, r0);
  st.site = &q_emlrtRSI;
  rdivide(&st, r0, ph, r2);
  a = b_a->size[0];
  trueCount = r2->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &h_emlrtECI, sp);
  }

  a = b_a->size[0];
  emxEnsureCapacity_real_T(sp, b_a, a, &emlrtRTEI);
  loop_ub = b_a->size[0];
  for (a = 0; a < loop_ub; a++) {
    b_a->data[a] += r2->data[a];
  }

  a = b_ph->size[0];
  b_ph->size[0] = p->size[0];
  emxEnsureCapacity_real_T(sp, b_ph, a, &emlrtRTEI);
  loop_ub = p->size[0];
  for (a = 0; a < loop_ub; a++) {
    b_ph->data[a] = -p->data[a];
  }

  st.site = &r_emlrtRSI;
  rdivide(&st, b_ph, ph, b);
  a = b_ph->size[0];
  b_ph->size[0] = q->size[0];
  emxEnsureCapacity_real_T(sp, b_ph, a, &emlrtRTEI);
  loop_ub = q->size[0];
  for (a = 0; a < loop_ub; a++) {
    b_ph->data[a] = -q->data[a];
  }

  st.site = &s_emlrtRSI;
  rdivide(&st, b_ph, ph, z);
  b_rdivide(sp, ph, p);
  a = p->size[0];
  emxEnsureCapacity_real_T(sp, p, a, &emlrtRTEI);
  loop_ub = p->size[0];
  for (a = 0; a < loop_ub; a++) {
    p->data[a]--;
  }

  a = A1->size[0];
  trueCount = b_a->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &i_emlrtECI, sp);
  }

  a = r1->size[0];
  r1->size[0] = th->size[0];
  emxEnsureCapacity_real_T(sp, r1, a, &emlrtRTEI);
  loop_ub = th->size[0];
  for (a = 0; a < loop_ub; a++) {
    r1->data[a] = 2.0 * th->data[a];
  }

  a = b_ph->size[0];
  b_ph->size[0] = A1->size[0];
  emxEnsureCapacity_real_T(sp, b_ph, a, &emlrtRTEI);
  loop_ub = A1->size[0];
  for (a = 0; a < loop_ub; a++) {
    b_ph->data[a] = A1->data[a] - b_a->data[a];
  }

  st.site = &t_emlrtRSI;
  rdivide(&st, r1, b_ph, ph);
  st.site = &t_emlrtRSI;
  b_atan(&st, ph);
  a = ph->size[0];
  emxEnsureCapacity_real_T(sp, ph, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  emxFree_real_T(&r1);
  for (a = 0; a < loop_ub; a++) {
    ph->data[a] /= 2.0;
  }

  /* tt(isnan(tt)) = 0; */
  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity_real_T(sp, r0, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  for (a = 0; a < loop_ub; a++) {
    r0->data[a] = ph->data[a];
  }

  st.site = &u_emlrtRSI;
  b_cos(&st, r0);
  st.site = &u_emlrtRSI;
  b_power(&st, r0, cc);
  a = A1->size[0];
  trueCount = cc->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &j_emlrtECI, sp);
  }

  a = r0->size[0];
  r0->size[0] = th->size[0];
  emxEnsureCapacity_real_T(sp, r0, a, &emlrtRTEI);
  loop_ub = th->size[0];
  for (a = 0; a < loop_ub; a++) {
    r0->data[a] = 2.0 * th->data[a];
  }

  a = r2->size[0];
  r2->size[0] = ph->size[0];
  emxEnsureCapacity_real_T(sp, r2, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  for (a = 0; a < loop_ub; a++) {
    r2->data[a] = ph->data[a];
  }

  st.site = &u_emlrtRSI;
  b_sin(&st, r2);
  a = r0->size[0];
  trueCount = r2->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &k_emlrtECI, sp);
  }

  a = r0->size[0];
  emxEnsureCapacity_real_T(sp, r0, a, &emlrtRTEI);
  loop_ub = r0->size[0];
  for (a = 0; a < loop_ub; a++) {
    r0->data[a] *= r2->data[a];
  }

  a = r2->size[0];
  r2->size[0] = ph->size[0];
  emxEnsureCapacity_real_T(sp, r2, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  for (a = 0; a < loop_ub; a++) {
    r2->data[a] = ph->data[a];
  }

  st.site = &u_emlrtRSI;
  b_cos(&st, r2);
  a = r0->size[0];
  trueCount = r2->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &k_emlrtECI, sp);
  }

  a = cc->size[0];
  cc->size[0] = A1->size[0];
  emxEnsureCapacity_real_T(sp, cc, a, &emlrtRTEI);
  loop_ub = A1->size[0];
  for (a = 0; a < loop_ub; a++) {
    cc->data[a] *= A1->data[a];
  }

  a = r0->size[0];
  emxEnsureCapacity_real_T(sp, r0, a, &emlrtRTEI);
  loop_ub = r0->size[0];
  for (a = 0; a < loop_ub; a++) {
    r0->data[a] *= r2->data[a];
  }

  a = cc->size[0];
  trueCount = r0->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &j_emlrtECI, sp);
  }

  a = r2->size[0];
  r2->size[0] = ph->size[0];
  emxEnsureCapacity_real_T(sp, r2, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  for (a = 0; a < loop_ub; a++) {
    r2->data[a] = ph->data[a];
  }

  st.site = &u_emlrtRSI;
  b_sin(&st, r2);
  st.site = &u_emlrtRSI;
  b_power(&st, r2, q);
  a = b_a->size[0];
  trueCount = q->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &l_emlrtECI, sp);
  }

  a = q->size[0];
  q->size[0] = b_a->size[0];
  emxEnsureCapacity_real_T(sp, q, a, &emlrtRTEI);
  loop_ub = b_a->size[0];
  for (a = 0; a < loop_ub; a++) {
    q->data[a] *= b_a->data[a];
  }

  a = cc->size[0];
  trueCount = q->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &j_emlrtECI, sp);
  }

  a = cc->size[0];
  emxEnsureCapacity_real_T(sp, cc, a, &emlrtRTEI);
  loop_ub = cc->size[0];
  for (a = 0; a < loop_ub; a++) {
    cc->data[a] = (cc->data[a] + r0->data[a]) + q->data[a];
  }

  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity_real_T(sp, r0, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  for (a = 0; a < loop_ub; a++) {
    r0->data[a] = ph->data[a];
  }

  st.site = &v_emlrtRSI;
  b_sin(&st, r0);
  st.site = &v_emlrtRSI;
  b_power(&st, r0, r2);
  a = A1->size[0];
  trueCount = r2->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &m_emlrtECI, sp);
  }

  a = th->size[0];
  emxEnsureCapacity_real_T(sp, th, a, &emlrtRTEI);
  loop_ub = th->size[0];
  for (a = 0; a < loop_ub; a++) {
    th->data[a] *= 2.0;
  }

  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity_real_T(sp, r0, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  for (a = 0; a < loop_ub; a++) {
    r0->data[a] = ph->data[a];
  }

  st.site = &v_emlrtRSI;
  b_sin(&st, r0);
  a = th->size[0];
  trueCount = r0->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &n_emlrtECI, sp);
  }

  a = th->size[0];
  emxEnsureCapacity_real_T(sp, th, a, &emlrtRTEI);
  loop_ub = th->size[0];
  for (a = 0; a < loop_ub; a++) {
    th->data[a] *= r0->data[a];
  }

  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity_real_T(sp, r0, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  for (a = 0; a < loop_ub; a++) {
    r0->data[a] = ph->data[a];
  }

  st.site = &v_emlrtRSI;
  b_cos(&st, r0);
  a = th->size[0];
  trueCount = r0->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &n_emlrtECI, sp);
  }

  a = A1->size[0];
  emxEnsureCapacity_real_T(sp, A1, a, &emlrtRTEI);
  loop_ub = A1->size[0];
  for (a = 0; a < loop_ub; a++) {
    A1->data[a] *= r2->data[a];
  }

  a = th->size[0];
  emxEnsureCapacity_real_T(sp, th, a, &emlrtRTEI);
  loop_ub = th->size[0];
  for (a = 0; a < loop_ub; a++) {
    th->data[a] *= r0->data[a];
  }

  a = A1->size[0];
  trueCount = th->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &m_emlrtECI, sp);
  }

  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity_real_T(sp, r0, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  for (a = 0; a < loop_ub; a++) {
    r0->data[a] = ph->data[a];
  }

  st.site = &v_emlrtRSI;
  b_cos(&st, r0);
  st.site = &v_emlrtRSI;
  b_power(&st, r0, r2);
  a = b_a->size[0];
  trueCount = r2->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &o_emlrtECI, sp);
  }

  a = b_a->size[0];
  emxEnsureCapacity_real_T(sp, b_a, a, &emlrtRTEI);
  loop_ub = b_a->size[0];
  for (a = 0; a < loop_ub; a++) {
    b_a->data[a] *= r2->data[a];
  }

  a = A1->size[0];
  trueCount = b_a->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &m_emlrtECI, sp);
  }

  a = A1->size[0];
  emxEnsureCapacity_real_T(sp, A1, a, &emlrtRTEI);
  loop_ub = A1->size[0];
  for (a = 0; a < loop_ub; a++) {
    A1->data[a] = (A1->data[a] - th->data[a]) + b_a->data[a];
  }

  a = th->size[0];
  th->size[0] = ph->size[0];
  emxEnsureCapacity_real_T(sp, th, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  for (a = 0; a < loop_ub; a++) {
    th->data[a] = ph->data[a];
  }

  st.site = &w_emlrtRSI;
  b_cos(&st, th);
  a = b->size[0];
  trueCount = th->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &p_emlrtECI, sp);
  }

  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity_real_T(sp, r0, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  for (a = 0; a < loop_ub; a++) {
    r0->data[a] = ph->data[a];
  }

  st.site = &w_emlrtRSI;
  b_sin(&st, r0);
  a = z->size[0];
  trueCount = r0->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &q_emlrtECI, sp);
  }

  a = th->size[0];
  th->size[0] = b->size[0];
  emxEnsureCapacity_real_T(sp, th, a, &emlrtRTEI);
  loop_ub = b->size[0];
  for (a = 0; a < loop_ub; a++) {
    th->data[a] *= b->data[a];
  }

  a = r0->size[0];
  r0->size[0] = z->size[0];
  emxEnsureCapacity_real_T(sp, r0, a, &emlrtRTEI);
  loop_ub = z->size[0];
  for (a = 0; a < loop_ub; a++) {
    r0->data[a] *= z->data[a];
  }

  a = th->size[0];
  trueCount = r0->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &p_emlrtECI, sp);
  }

  a = th->size[0];
  emxEnsureCapacity_real_T(sp, th, a, &emlrtRTEI);
  loop_ub = th->size[0];
  for (a = 0; a < loop_ub; a++) {
    th->data[a] += r0->data[a];
  }

  a = b->size[0];
  emxEnsureCapacity_real_T(sp, b, a, &emlrtRTEI);
  loop_ub = b->size[0];
  for (a = 0; a < loop_ub; a++) {
    b->data[a] = -b->data[a];
  }

  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity_real_T(sp, r0, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  for (a = 0; a < loop_ub; a++) {
    r0->data[a] = ph->data[a];
  }

  st.site = &x_emlrtRSI;
  b_sin(&st, r0);
  a = b->size[0];
  trueCount = r0->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &r_emlrtECI, sp);
  }

  st.site = &x_emlrtRSI;
  b_cos(&st, ph);
  a = z->size[0];
  trueCount = ph->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &s_emlrtECI, sp);
  }

  a = b->size[0];
  emxEnsureCapacity_real_T(sp, b, a, &emlrtRTEI);
  loop_ub = b->size[0];
  for (a = 0; a < loop_ub; a++) {
    b->data[a] *= r0->data[a];
  }

  a = z->size[0];
  emxEnsureCapacity_real_T(sp, z, a, &emlrtRTEI);
  loop_ub = z->size[0];
  for (a = 0; a < loop_ub; a++) {
    z->data[a] *= ph->data[a];
  }

  a = b->size[0];
  trueCount = z->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &r_emlrtECI, sp);
  }

  a = b->size[0];
  emxEnsureCapacity_real_T(sp, b, a, &emlrtRTEI);
  loop_ub = b->size[0];
  for (a = 0; a < loop_ub; a++) {
    b->data[a] += z->data[a];
  }

  /*  A3=2*sqrt(D2.^2./A2.^2+E2.^2./(A2.*B2)-F2./A2); */
  /*  B3=2*sqrt(D2.^2./(A2.*B2)+E2.^2./B2.^2-F2./B2); */
  /*  A3=2*sqrt(complex(D2.^2./A2.^2+E2.^2./(A2.*B2)-F2./A2)); */
  /*  B3=2*sqrt(complex(D2.^2./(A2.*B2)+E2.^2./B2.^2-F2./B2)); */
  a = cc->size[0];
  trueCount = A1->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &t_emlrtECI, sp);
  }

  st.site = &y_emlrtRSI;
  b_power(&st, th, r0);
  st.site = &y_emlrtRSI;
  b_power(&st, cc, r2);
  st.site = &y_emlrtRSI;
  rdivide(&st, r0, r2, q);
  st.site = &y_emlrtRSI;
  b_power(&st, b, r0);
  a = b_ph->size[0];
  b_ph->size[0] = cc->size[0];
  emxEnsureCapacity_real_T(sp, b_ph, a, &emlrtRTEI);
  loop_ub = cc->size[0];
  for (a = 0; a < loop_ub; a++) {
    b_ph->data[a] = cc->data[a] * A1->data[a];
  }

  st.site = &y_emlrtRSI;
  rdivide(&st, r0, b_ph, r2);
  a = q->size[0];
  trueCount = r2->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &u_emlrtECI, sp);
  }

  st.site = &y_emlrtRSI;
  rdivide(&st, p, cc, r0);
  a = q->size[0];
  trueCount = r0->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &u_emlrtECI, sp);
  }

  a = cc->size[0];
  trueCount = A1->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &v_emlrtECI, sp);
  }

  st.site = &ab_emlrtRSI;
  b_power(&st, th, b_a);
  a = b_ph->size[0];
  b_ph->size[0] = cc->size[0];
  emxEnsureCapacity_real_T(sp, b_ph, a, &emlrtRTEI);
  loop_ub = cc->size[0];
  for (a = 0; a < loop_ub; a++) {
    b_ph->data[a] = cc->data[a] * A1->data[a];
  }

  emxInit_boolean_T(sp, &r3, 1, &emlrtRTEI, true);
  st.site = &ab_emlrtRSI;
  rdivide(&st, b_a, b_ph, cc);
  st.site = &ab_emlrtRSI;
  b_power(&st, b, b_a);
  st.site = &ab_emlrtRSI;
  b_power(&st, A1, th);
  st.site = &ab_emlrtRSI;
  rdivide(&st, b_a, th, z);
  a = cc->size[0];
  trueCount = z->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &w_emlrtECI, sp);
  }

  st.site = &ab_emlrtRSI;
  rdivide(&st, p, A1, b_a);
  a = cc->size[0];
  trueCount = b_a->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &w_emlrtECI, sp);
  }

  a = r3->size[0];
  r3->size[0] = q->size[0];
  emxEnsureCapacity_boolean_T(sp, r3, a, &emlrtRTEI);
  loop_ub = q->size[0];
  emxFree_real_T(&A1);
  emxFree_real_T(&p);
  emxFree_real_T(&b);
  for (a = 0; a < loop_ub; a++) {
    r3->data[a] = ((q->data[a] + r2->data[a]) - r0->data[a] >= 0.0);
  }

  emxInit_boolean_T(sp, &r4, 1, &emlrtRTEI, true);
  a = r4->size[0];
  r4->size[0] = cc->size[0];
  emxEnsureCapacity_boolean_T(sp, r4, a, &emlrtRTEI);
  loop_ub = cc->size[0];
  for (a = 0; a < loop_ub; a++) {
    r4->data[a] = ((cc->data[a] + z->data[a]) - b_a->data[a] >= 0.0);
  }

  a = r3->size[0];
  trueCount = r4->size[0];
  if (a != trueCount) {
    emlrtSizeEqCheck1DR2012b(a, trueCount, &x_emlrtECI, sp);
  }

  loop_ub = r3->size[0] - 1;
  trueCount = 0;
  for (ixstop = 0; ixstop <= loop_ub; ixstop++) {
    if (r3->data[ixstop] && r4->data[ixstop]) {
      trueCount++;
    }
  }

  emxInit_int32_T(sp, &r5, 1, &emlrtRTEI, true);
  a = r5->size[0];
  r5->size[0] = trueCount;
  emxEnsureCapacity_int32_T(sp, r5, a, &emlrtRTEI);
  vstride = 0;
  for (ixstop = 0; ixstop <= loop_ub; ixstop++) {
    if (r3->data[ixstop] && r4->data[ixstop]) {
      r5->data[vstride] = ixstop + 1;
      vstride++;
    }
  }

  vstride = q->size[0];
  a = b_ph->size[0];
  b_ph->size[0] = q->size[0];
  emxEnsureCapacity_real_T(sp, b_ph, a, &emlrtRTEI);
  loop_ub = q->size[0];
  for (a = 0; a < loop_ub; a++) {
    b_ph->data[a] = (q->data[a] + r2->data[a]) - r0->data[a];
  }

  emxFree_real_T(&r0);
  emxFree_real_T(&r2);
  emxFree_real_T(&q);
  a = ph->size[0];
  ph->size[0] = r5->size[0];
  emxEnsureCapacity_real_T(sp, ph, a, &emlrtRTEI);
  loop_ub = r5->size[0];
  for (a = 0; a < loop_ub; a++) {
    trueCount = r5->data[a];
    if (!((trueCount >= 1) && (trueCount <= vstride))) {
      emlrtDynamicBoundsCheckR2012b(trueCount, 1, vstride, &d_emlrtBCI, sp);
    }

    ph->data[a] = b_ph->data[trueCount - 1];
  }

  emxFree_int32_T(&r5);
  st.site = &bb_emlrtRSI;
  b_sqrt(&st, ph);
  a = ph->size[0];
  emxEnsureCapacity_real_T(sp, ph, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  for (a = 0; a < loop_ub; a++) {
    ph->data[a] *= 2.0;
  }

  loop_ub = r3->size[0] - 1;
  trueCount = 0;
  for (ixstop = 0; ixstop <= loop_ub; ixstop++) {
    if (r3->data[ixstop] && r4->data[ixstop]) {
      trueCount++;
    }
  }

  emxInit_int32_T(sp, &r6, 1, &emlrtRTEI, true);
  a = r6->size[0];
  r6->size[0] = trueCount;
  emxEnsureCapacity_int32_T(sp, r6, a, &emlrtRTEI);
  vstride = 0;
  for (ixstop = 0; ixstop <= loop_ub; ixstop++) {
    if (r3->data[ixstop] && r4->data[ixstop]) {
      r6->data[vstride] = ixstop + 1;
      vstride++;
    }
  }

  emxFree_boolean_T(&r4);
  emxFree_boolean_T(&r3);
  vstride = cc->size[0];
  a = b_ph->size[0];
  b_ph->size[0] = cc->size[0];
  emxEnsureCapacity_real_T(sp, b_ph, a, &emlrtRTEI);
  loop_ub = cc->size[0];
  for (a = 0; a < loop_ub; a++) {
    b_ph->data[a] = (cc->data[a] + z->data[a]) - b_a->data[a];
  }

  emxFree_real_T(&cc);
  emxFree_real_T(&b_a);
  emxFree_real_T(&z);
  a = th->size[0];
  th->size[0] = r6->size[0];
  emxEnsureCapacity_real_T(sp, th, a, &emlrtRTEI);
  loop_ub = r6->size[0];
  for (a = 0; a < loop_ub; a++) {
    trueCount = r6->data[a];
    if (!((trueCount >= 1) && (trueCount <= vstride))) {
      emlrtDynamicBoundsCheckR2012b(trueCount, 1, vstride, &e_emlrtBCI, sp);
    }

    th->data[a] = b_ph->data[trueCount - 1];
  }

  emxFree_real_T(&b_ph);
  emxFree_int32_T(&r6);
  st.site = &cb_emlrtRSI;
  b_sqrt(&st, th);
  a = th->size[0];
  emxEnsureCapacity_real_T(sp, th, a, &emlrtRTEI);
  loop_ub = th->size[0];
  for (a = 0; a < loop_ub; a++) {
    th->data[a] *= 2.0;
  }

  st.site = &db_emlrtRSI;
  b_st.site = &hc_emlrtRSI;
  c_st.site = &ic_emlrtRSI;
  overflow = true;
  if (th->size[0] != ph->size[0]) {
    overflow = false;
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2012b(&c_st, &y_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_real_T1(&c_st, &varargin_1, 2, &emlrtRTEI, true);
  a = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = ph->size[0];
  varargin_1->size[1] = 2;
  emxEnsureCapacity_real_T1(&b_st, varargin_1, a, &emlrtRTEI);
  loop_ub = ph->size[0];
  for (a = 0; a < loop_ub; a++) {
    varargin_1->data[a] = ph->data[a];
  }

  emxFree_real_T(&ph);
  loop_ub = th->size[0];
  for (a = 0; a < loop_ub; a++) {
    varargin_1->data[a + varargin_1->size[0]] = th->data[a];
  }

  emxFree_real_T(&th);
  st.site = &db_emlrtRSI;
  b_st.site = &lc_emlrtRSI;
  c_st.site = &mc_emlrtRSI;
  a = res->size[0];
  res->size[0] = varargin_1->size[0];
  emxEnsureCapacity_real_T(&c_st, res, a, &b_emlrtRTEI);
  vstride = varargin_1->size[0];
  d_st.site = &nc_emlrtRSI;
  overflow = ((!(1 > varargin_1->size[0])) && (varargin_1->size[0] > 2147483646));
  if (overflow) {
    e_st.site = &dc_emlrtRSI;
    f_st.site = &dc_emlrtRSI;
    check_forloop_overflow_error(&f_st);
  }

  for (loop_ub = 1; loop_ub <= vstride; loop_ub++) {
    d_st.site = &oc_emlrtRSI;
    trueCount = loop_ub;
    ixstop = loop_ub + vstride;
    mtmp = varargin_1->data[loop_ub - 1];
    if (muDoubleScalarIsNaN(varargin_1->data[loop_ub - 1])) {
      a = loop_ub + vstride;
      e_st.site = &qc_emlrtRSI;
      if ((vstride == 0) || (a > ixstop)) {
        overflow = false;
      } else {
        overflow = (ixstop > MAX_int32_T - vstride);
      }

      if (vstride == 0) {
        emlrtErrorWithMessageIdR2012b(&e_st, &ab_emlrtRTEI,
          "Coder:builtins:VectorStride", 0);
      }

      if (overflow) {
        f_st.site = &dc_emlrtRSI;
        g_st.site = &dc_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      exitg1 = false;
      while ((!exitg1) && (a <= ixstop)) {
        trueCount = a;
        if (!muDoubleScalarIsNaN(varargin_1->data[a - 1])) {
          mtmp = varargin_1->data[a - 1];
          exitg1 = true;
        } else {
          a += vstride;
        }
      }
    }

    if (trueCount < ixstop) {
      a = trueCount + vstride;
      e_st.site = &pc_emlrtRSI;
      if ((vstride == 0) || (a > ixstop)) {
        overflow = false;
      } else {
        overflow = (ixstop > MAX_int32_T - vstride);
      }

      if (vstride == 0) {
        emlrtErrorWithMessageIdR2012b(&e_st, &ab_emlrtRTEI,
          "Coder:builtins:VectorStride", 0);
      }

      if (overflow) {
        f_st.site = &dc_emlrtRSI;
        g_st.site = &dc_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }

      while (a <= ixstop) {
        if (varargin_1->data[a - 1] > mtmp) {
          mtmp = varargin_1->data[a - 1];
        }

        a += vstride;
      }
    }

    res->data[loop_ub - 1] = mtmp;
  }

  emxFree_real_T(&varargin_1);
  loop_ub = res->size[0];
  for (ixstop = 0; ixstop < loop_ub; ixstop++) {
    if (res->data[ixstop] > u) {
      a = dm->size[0];
      if (!((ixstop + 1 >= 1) && (ixstop + 1 <= a))) {
        emlrtDynamicBoundsCheckR2012b(ixstop + 1, 1, a, &c_emlrtBCI, sp);
      }
    }
  }

  emxFree_real_T(&dm);
  loop_ub = res->size[0] - 1;
  trueCount = 0;
  for (ixstop = 0; ixstop <= loop_ub; ixstop++) {
    if (res->data[ixstop] > u) {
      trueCount++;
    }
  }

  vstride = 0;
  for (ixstop = 0; ixstop <= loop_ub; ixstop++) {
    if (res->data[ixstop] > u) {
      a = res->size[0];
      if (!((ixstop + 1 >= 1) && (ixstop + 1 <= a))) {
        emlrtDynamicBoundsCheckR2012b(ixstop + 1, 1, a, &f_emlrtBCI, sp);
      }

      res->data[vstride] = res->data[ixstop];
      vstride++;
    }
  }

  a = res->size[0];
  res->size[0] = trueCount;
  emxEnsureCapacity_real_T(sp, res, a, &emlrtRTEI);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (esim2.c) */
