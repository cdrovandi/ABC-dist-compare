/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * esim.c
 *
 * Code generation for function 'esim'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "esim.h"
#include "randsample.h"
#include "rdivide.h"
#include "esim_emxutil.h"
#include "eml_int_forloop_overflow_check.h"
#include "relop.h"
#include "sqrt.h"
#include "power.h"
#include "cos.h"
#include "sin.h"
#include "unifrnd.h"
#include "rand.h"
#include "poissrnd.h"
#include "esim_data.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = { 7,     /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo b_emlrtRSI = { 9,   /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo c_emlrtRSI = { 11,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo d_emlrtRSI = { 13,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo e_emlrtRSI = { 14,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo f_emlrtRSI = { 16,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo g_emlrtRSI = { 18,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo h_emlrtRSI = { 25,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo i_emlrtRSI = { 28,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo j_emlrtRSI = { 29,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo k_emlrtRSI = { 30,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo l_emlrtRSI = { 31,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo m_emlrtRSI = { 32,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo n_emlrtRSI = { 35,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo o_emlrtRSI = { 36,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo p_emlrtRSI = { 37,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo q_emlrtRSI = { 38,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo r_emlrtRSI = { 39,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo s_emlrtRSI = { 40,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo t_emlrtRSI = { 43,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo u_emlrtRSI = { 46,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo v_emlrtRSI = { 47,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo w_emlrtRSI = { 48,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo x_emlrtRSI = { 49,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo y_emlrtRSI = { 54,  /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo ab_emlrtRSI = { 55, /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo bb_emlrtRSI = { 64, /* lineNo */
  "esim",                              /* fcnName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pathName */
};

static emlrtRSInfo yb_emlrtRSI = { 20, /* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo ac_emlrtRSI = { 100,/* lineNo */
  "cat",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pathName */
};

static emlrtRSInfo dc_emlrtRSI = { 13, /* lineNo */
  "max",                               /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\datafun\\max.m"/* pathName */
};

static emlrtRSInfo ec_emlrtRSI = { 19, /* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo fc_emlrtRSI = { 213,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo gc_emlrtRSI = { 214,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo hc_emlrtRSI = { 376,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo ic_emlrtRSI = { 348,/* lineNo */
  "minOrMax",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax.m"/* pathName */
};

static emlrtRSInfo mc_emlrtRSI = { 10, /* lineNo */
  "atan",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\elfun\\atan.m"/* pathName */
};

static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  16,                                  /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtRTEInfo b_emlrtRTEI = { 9, /* lineNo */
  1,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtRTEInfo c_emlrtRTEI = { 11,/* lineNo */
  1,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtRTEInfo d_emlrtRTEI = { 13,/* lineNo */
  1,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtRTEInfo e_emlrtRTEI = { 14,/* lineNo */
  1,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtRTEInfo f_emlrtRTEI = { 16,/* lineNo */
  1,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtRTEInfo g_emlrtRTEI = { 25,/* lineNo */
  1,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtRTEInfo h_emlrtRTEI = { 28,/* lineNo */
  1,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtRTEInfo i_emlrtRTEI = { 29,/* lineNo */
  1,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtRTEInfo j_emlrtRTEI = { 30,/* lineNo */
  1,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtRTEInfo k_emlrtRTEI = { 31,/* lineNo */
  1,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtRTEInfo l_emlrtRTEI = { 36,/* lineNo */
  1,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtRTEInfo m_emlrtRTEI = { 38,/* lineNo */
  1,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtRTEInfo n_emlrtRTEI = { 54,/* lineNo */
  1,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtRTEInfo o_emlrtRTEI = { 55,/* lineNo */
  1,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo emlrtECI = { -1,    /* nDims */
  13,                                  /* lineNo */
  3,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo b_emlrtECI = { -1,  /* nDims */
  14,                                  /* lineNo */
  4,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtRTEInfo u_emlrtRTEI = { 17,/* lineNo */
  9,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtBCInfo emlrtBCI = { -1,    /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  22,                                  /* colNo */
  "pars",                              /* aName */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  18,                                  /* lineNo */
  10,                                  /* colNo */
  "pars",                              /* aName */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m",/* pName */
  0                                    /* checkKind */
};

static emlrtECInfo c_emlrtECI = { -1,  /* nDims */
  31,                                  /* lineNo */
  3,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo d_emlrtECI = { -1,  /* nDims */
  32,                                  /* lineNo */
  3,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo e_emlrtECI = { -1,  /* nDims */
  35,                                  /* lineNo */
  5,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo f_emlrtECI = { -1,  /* nDims */
  36,                                  /* lineNo */
  4,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo g_emlrtECI = { -1,  /* nDims */
  37,                                  /* lineNo */
  4,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo h_emlrtECI = { -1,  /* nDims */
  38,                                  /* lineNo */
  4,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo i_emlrtECI = { -1,  /* nDims */
  43,                                  /* lineNo */
  16,                                  /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo j_emlrtECI = { -1,  /* nDims */
  46,                                  /* lineNo */
  4,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo k_emlrtECI = { -1,  /* nDims */
  46,                                  /* lineNo */
  21,                                  /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo l_emlrtECI = { -1,  /* nDims */
  46,                                  /* lineNo */
  44,                                  /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo m_emlrtECI = { -1,  /* nDims */
  47,                                  /* lineNo */
  4,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo n_emlrtECI = { -1,  /* nDims */
  47,                                  /* lineNo */
  21,                                  /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo o_emlrtECI = { -1,  /* nDims */
  47,                                  /* lineNo */
  44,                                  /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo p_emlrtECI = { -1,  /* nDims */
  48,                                  /* lineNo */
  4,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo q_emlrtECI = { -1,  /* nDims */
  48,                                  /* lineNo */
  16,                                  /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo r_emlrtECI = { -1,  /* nDims */
  49,                                  /* lineNo */
  4,                                   /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo s_emlrtECI = { -1,  /* nDims */
  49,                                  /* lineNo */
  17,                                  /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo t_emlrtECI = { -1,  /* nDims */
  54,                                  /* lineNo */
  40,                                  /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo u_emlrtECI = { -1,  /* nDims */
  54,                                  /* lineNo */
  19,                                  /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo v_emlrtECI = { -1,  /* nDims */
  55,                                  /* lineNo */
  27,                                  /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtECInfo w_emlrtECI = { -1,  /* nDims */
  55,                                  /* lineNo */
  19,                                  /* colNo */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m"/* pName */
};

static emlrtBCInfo c_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  66,                                  /* lineNo */
  7,                                   /* colNo */
  "dm",                                /* aName */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo v_emlrtRTEI = { 281,/* lineNo */
  27,                                  /* colNo */
  "cat",                               /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\eml\\+coder\\+internal\\cat.m"/* pName */
};

static emlrtRTEInfo w_emlrtRTEI = { 19,/* lineNo */
  19,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2017a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtBCInfo d_emlrtBCI = { -1,  /* iFirst */
  -1,                                  /* iLast */
  67,                                  /* lineNo */
  11,                                  /* colNo */
  "res",                               /* aName */
  "esim",                              /* fName */
  "C:\\Users\\drovandi\\Dropbox\\Research\\ABC Research\\Bayesian Synthetic Likelihood\\BSL High Dim Cov\\Code\\Stereo2\\esim.m",/* pName */
  0                                    /* checkKind */
};

/* Function Definitions */
void esim(const emlrtStack *sp, const real_T theta[3], real_T u,
          emxArray_creal_T *res)
{
  emxArray_real_T *z;
  emxArray_real_T *r0;
  emxArray_real_T *r1;
  boolean_T overflow;
  real_T nn;
  int32_T a;
  int32_T vstride;
  emxArray_real_T *b_a;
  emxArray_real_T *b;
  emxArray_real_T *cc;
  boolean_T b0;
  emxArray_real_T *pars;
  int32_T ixstop;
  real_T dv0[3];
  real_T dv1[3];
  real_T b_pars[3];
  emxArray_real_T *dm;
  int32_T j;
  emxArray_real_T *th;
  int32_T partialTrueCount;
  emxArray_real_T *ph;
  real_T mtmp;
  emxArray_real_T *r2;
  boolean_T exitg1;
  emxArray_real_T *p;
  emxArray_real_T *r3;
  emxArray_real_T *r4;
  emxArray_real_T *q;
  emxArray_real_T *b_ph;
  emxArray_real_T *A1;
  emxArray_real_T *b_p;
  emxArray_real_T *C1;
  emxArray_real_T *c_p;
  emxArray_real_T *b_q;
  emxArray_real_T *r5;
  emxArray_real_T *b_A1;
  emxArray_real_T *b_z;
  emxArray_creal_T *A3;
  emxArray_real_T *c_z;
  emxArray_creal_T *B3;
  emxArray_creal_T *varargin_1;
  creal_T b_mtmp;
  creal_T b_varargin_1;
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
  emxInit_real_T(sp, &z, 1, &b_emlrtRTEI, true);
  emxInit_real_T(sp, &r0, 1, &emlrtRTEI, true);
  emxInit_real_T(sp, &r1, 1, &emlrtRTEI, true);
  overflow = false;
  st.site = &emlrtRSI;
  nn = poissrnd(&st, theta[0] * 100.0);
  st.site = &b_emlrtRSI;
  unifrnd(&st, nn, z);
  st.site = &c_emlrtRSI;
  e_rand(&st, nn, r0);
  a = r1->size[0];
  r1->size[0] = r0->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r1, a, sizeof(real_T), &emlrtRTEI);
  vstride = r0->size[0];
  for (a = 0; a < vstride; a++) {
    r1->data[a] = 1.0 - r0->data[a];
  }

  emxInit_real_T(sp, &b_a, 1, &c_emlrtRTEI, true);
  st.site = &c_emlrtRSI;
  power(&st, r1, -theta[2], b_a);
  a = b_a->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_a, a, sizeof(real_T), &emlrtRTEI);
  vstride = b_a->size[0];
  emxFree_real_T(&r1);
  for (a = 0; a < vstride; a++) {
    b_a->data[a]--;
  }

  a = b_a->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_a, a, sizeof(real_T), &emlrtRTEI);
  vstride = b_a->size[0];
  for (a = 0; a < vstride; a++) {
    b_a->data[a] = (u + theta[1] * b_a->data[a] / theta[2]) / 2.0;
  }

  emxInit_real_T(sp, &b, 1, &d_emlrtRTEI, true);
  st.site = &d_emlrtRSI;
  e_rand(&st, nn, b);
  a = b->size[0];
  vstride = b_a->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &emlrtECI, sp);
  }

  a = b->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b, a, sizeof(real_T), &emlrtRTEI);
  vstride = b->size[0];
  for (a = 0; a < vstride; a++) {
    b->data[a] *= b_a->data[a];
  }

  emxInit_real_T(sp, &cc, 1, &e_emlrtRTEI, true);
  st.site = &e_emlrtRSI;
  e_rand(&st, nn, cc);
  a = cc->size[0];
  vstride = b_a->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &b_emlrtECI, sp);
  }

  a = cc->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)cc, a, sizeof(real_T), &emlrtRTEI);
  vstride = cc->size[0];
  for (a = 0; a < vstride; a++) {
    cc->data[a] *= b_a->data[a];
  }

  st.site = &f_emlrtRSI;
  b_st.site = &yb_emlrtRSI;
  c_st.site = &ac_emlrtRSI;
  b0 = true;
  if (b->size[0] != b_a->size[0]) {
    b0 = false;
  }

  if (!b0) {
    emlrtErrorWithMessageIdR2012b(&c_st, &v_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  if (cc->size[0] != b_a->size[0]) {
    b0 = false;
  }

  if (!b0) {
    emlrtErrorWithMessageIdR2012b(&c_st, &v_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_real_T1(&c_st, &pars, 2, &f_emlrtRTEI, true);
  a = pars->size[0] * pars->size[1];
  pars->size[0] = b_a->size[0];
  pars->size[1] = 3;
  emxEnsureCapacity(&b_st, (emxArray__common *)pars, a, sizeof(real_T),
                    &emlrtRTEI);
  vstride = b_a->size[0];
  for (a = 0; a < vstride; a++) {
    pars->data[a] = b_a->data[a];
  }

  vstride = b->size[0];
  for (a = 0; a < vstride; a++) {
    pars->data[a + pars->size[0]] = b->data[a];
  }

  vstride = cc->size[0];
  for (a = 0; a < vstride; a++) {
    pars->data[a + (pars->size[0] << 1)] = cc->data[a];
  }

  emlrtForLoopVectorCheckR2012b(1.0, 1.0, nn, mxDOUBLE_CLASS, (int32_T)nn,
    &u_emlrtRTEI, sp);
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

  vstride = pars->size[0];
  a = b_a->size[0];
  b_a->size[0] = vstride;
  emxEnsureCapacity(sp, (emxArray__common *)b_a, a, sizeof(real_T), &emlrtRTEI);
  for (a = 0; a < vstride; a++) {
    b_a->data[a] = pars->data[a];
  }

  vstride = pars->size[0];
  a = b->size[0];
  b->size[0] = vstride;
  emxEnsureCapacity(sp, (emxArray__common *)b, a, sizeof(real_T), &emlrtRTEI);
  for (a = 0; a < vstride; a++) {
    b->data[a] = pars->data[a + pars->size[0]];
  }

  vstride = pars->size[0];
  a = cc->size[0];
  cc->size[0] = vstride;
  emxEnsureCapacity(sp, (emxArray__common *)cc, a, sizeof(real_T), &emlrtRTEI);
  for (a = 0; a < vstride; a++) {
    cc->data[a] = pars->data[a + (pars->size[0] << 1)];
  }

  st.site = &h_emlrtRSI;
  b_st.site = &yb_emlrtRSI;
  c_st.site = &ac_emlrtRSI;
  overflow = true;
  a = pars->size[0];
  vstride = pars->size[0];
  if (a != vstride) {
    overflow = false;
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2012b(&c_st, &v_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  a = pars->size[0];
  vstride = pars->size[0];
  if (a != vstride) {
    overflow = false;
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2012b(&c_st, &v_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  a = pars->size[0] * pars->size[1];
  pars->size[0] = b_a->size[0];
  pars->size[1] = 3;
  emxEnsureCapacity(&b_st, (emxArray__common *)pars, a, sizeof(real_T),
                    &emlrtRTEI);
  vstride = b_a->size[0];
  for (a = 0; a < vstride; a++) {
    pars->data[a] = b_a->data[a];
  }

  vstride = b->size[0];
  for (a = 0; a < vstride; a++) {
    pars->data[a + pars->size[0]] = b->data[a];
  }

  vstride = cc->size[0];
  for (a = 0; a < vstride; a++) {
    pars->data[a + (pars->size[0] << 1)] = cc->data[a];
  }

  emxInit_real_T(&b_st, &dm, 1, &g_emlrtRTEI, true);
  st.site = &h_emlrtRSI;
  b_st.site = &dc_emlrtRSI;
  c_st.site = &ec_emlrtRSI;
  a = dm->size[0];
  dm->size[0] = pars->size[0];
  emxEnsureCapacity(&c_st, (emxArray__common *)dm, a, sizeof(real_T), &emlrtRTEI);
  vstride = pars->size[0];
  d_st.site = &fc_emlrtRSI;
  overflow = ((!(1 > pars->size[0])) && (pars->size[0] > 2147483646));
  if (overflow) {
    e_st.site = &xb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (j = 1; j <= vstride; j++) {
    d_st.site = &gc_emlrtRSI;
    partialTrueCount = j;
    ixstop = j + (vstride << 1);
    mtmp = pars->data[j - 1];
    if (muDoubleScalarIsNaN(pars->data[j - 1])) {
      a = j + vstride;
      e_st.site = &ic_emlrtRSI;
      if ((vstride == 0) || (a > ixstop)) {
        overflow = false;
      } else {
        overflow = (ixstop > MAX_int32_T - vstride);
      }

      if (vstride == 0) {
        emlrtErrorWithMessageIdR2012b(&e_st, &w_emlrtRTEI,
          "Coder:builtins:VectorStride", 0);
      }

      if (overflow) {
        f_st.site = &xb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      exitg1 = false;
      while ((!exitg1) && (a <= ixstop)) {
        partialTrueCount = a;
        if (!muDoubleScalarIsNaN(pars->data[a - 1])) {
          mtmp = pars->data[a - 1];
          exitg1 = true;
        } else {
          a += vstride;
        }
      }
    }

    if (partialTrueCount < ixstop) {
      a = partialTrueCount + vstride;
      e_st.site = &hc_emlrtRSI;
      if ((vstride == 0) || (a > ixstop)) {
        overflow = false;
      } else {
        overflow = (ixstop > MAX_int32_T - vstride);
      }

      if (vstride == 0) {
        emlrtErrorWithMessageIdR2012b(&e_st, &w_emlrtRTEI,
          "Coder:builtins:VectorStride", 0);
      }

      if (overflow) {
        f_st.site = &xb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      while (a <= ixstop) {
        if (pars->data[a - 1] > mtmp) {
          mtmp = pars->data[a - 1];
        }

        a += vstride;
      }
    }

    dm->data[j - 1] = mtmp;
  }

  emxFree_real_T(&pars);
  emxInit_real_T(&c_st, &th, 1, &h_emlrtRTEI, true);
  emxInit_real_T(&c_st, &ph, 1, &i_emlrtRTEI, true);
  st.site = &i_emlrtRSI;
  b_unifrnd(&st, nn, th);
  st.site = &j_emlrtRSI;
  b_unifrnd(&st, nn, ph);
  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r0, a, sizeof(real_T), &emlrtRTEI);
  vstride = ph->size[0];
  for (a = 0; a < vstride; a++) {
    r0->data[a] = ph->data[a];
  }

  emxInit_real_T(sp, &r2, 1, &emlrtRTEI, true);
  st.site = &k_emlrtRSI;
  b_sin(&st, r0);
  a = r2->size[0];
  r2->size[0] = r0->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r2, a, sizeof(real_T), &emlrtRTEI);
  vstride = r0->size[0];
  for (a = 0; a < vstride; a++) {
    r2->data[a] = -r0->data[a];
  }

  emxInit_real_T(sp, &p, 1, &j_emlrtRTEI, true);
  st.site = &k_emlrtRSI;
  rdivide(&st, r2, z, p);
  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r0, a, sizeof(real_T), &emlrtRTEI);
  vstride = ph->size[0];
  emxFree_real_T(&r2);
  for (a = 0; a < vstride; a++) {
    r0->data[a] = ph->data[a];
  }

  emxInit_real_T(sp, &r3, 1, &emlrtRTEI, true);
  st.site = &l_emlrtRSI;
  b_cos(&st, r0);
  a = r3->size[0];
  r3->size[0] = th->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r3, a, sizeof(real_T), &emlrtRTEI);
  vstride = th->size[0];
  for (a = 0; a < vstride; a++) {
    r3->data[a] = th->data[a];
  }

  emxInit_real_T(sp, &r4, 1, &emlrtRTEI, true);
  st.site = &l_emlrtRSI;
  b_sin(&st, r3);
  a = r0->size[0];
  vstride = r3->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &c_emlrtECI, sp);
  }

  a = r4->size[0];
  r4->size[0] = r0->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r4, a, sizeof(real_T), &emlrtRTEI);
  vstride = r0->size[0];
  for (a = 0; a < vstride; a++) {
    r4->data[a] = r0->data[a] * r3->data[a];
  }

  emxInit_real_T(sp, &q, 1, &k_emlrtRTEI, true);
  emxInit_real_T(sp, &b_ph, 1, &emlrtRTEI, true);
  st.site = &l_emlrtRSI;
  rdivide(&st, r4, z, q);
  st.site = &m_emlrtRSI;
  b_cos(&st, ph);
  st.site = &m_emlrtRSI;
  b_cos(&st, th);
  a = ph->size[0];
  vstride = th->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &d_emlrtECI, sp);
  }

  a = b_ph->size[0];
  b_ph->size[0] = ph->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_ph, a, sizeof(real_T), &emlrtRTEI);
  vstride = ph->size[0];
  emxFree_real_T(&r4);
  for (a = 0; a < vstride; a++) {
    b_ph->data[a] = ph->data[a] * th->data[a];
  }

  st.site = &m_emlrtRSI;
  rdivide(&st, b_ph, z, th);
  st.site = &n_emlrtRSI;
  b_power(&st, th, ph);
  st.site = &n_emlrtRSI;
  b_power(&st, cc, r0);
  a = ph->size[0];
  vstride = r0->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &e_emlrtECI, sp);
  }

  a = ph->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ph, a, sizeof(real_T), &emlrtRTEI);
  vstride = ph->size[0];
  emxFree_real_T(&b_ph);
  for (a = 0; a < vstride; a++) {
    ph->data[a] *= r0->data[a];
  }

  emxInit_real_T(sp, &A1, 1, &l_emlrtRTEI, true);

  /*  cc */
  st.site = &o_emlrtRSI;
  c_power(&st, b_a, A1);
  st.site = &o_emlrtRSI;
  b_power(&st, p, r0);
  st.site = &o_emlrtRSI;
  rdivide(&st, r0, ph, r3);
  a = A1->size[0];
  vstride = r3->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &f_emlrtECI, sp);
  }

  a = A1->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)A1, a, sizeof(real_T), &emlrtRTEI);
  vstride = A1->size[0];
  for (a = 0; a < vstride; a++) {
    A1->data[a] += r3->data[a];
  }

  emxInit_real_T(sp, &b_p, 1, &emlrtRTEI, true);
  a = p->size[0];
  vstride = q->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &g_emlrtECI, sp);
  }

  a = b_p->size[0];
  b_p->size[0] = p->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_p, a, sizeof(real_T), &emlrtRTEI);
  vstride = p->size[0];
  for (a = 0; a < vstride; a++) {
    b_p->data[a] = p->data[a] * q->data[a];
  }

  emxInit_real_T(sp, &C1, 1, &m_emlrtRTEI, true);
  st.site = &p_emlrtRSI;
  rdivide(&st, b_p, ph, th);
  st.site = &q_emlrtRSI;
  c_power(&st, b, C1);
  st.site = &q_emlrtRSI;
  b_power(&st, q, r0);
  st.site = &q_emlrtRSI;
  rdivide(&st, r0, ph, r3);
  a = C1->size[0];
  vstride = r3->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &h_emlrtECI, sp);
  }

  a = C1->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)C1, a, sizeof(real_T), &emlrtRTEI);
  vstride = C1->size[0];
  emxFree_real_T(&b_p);
  for (a = 0; a < vstride; a++) {
    C1->data[a] += r3->data[a];
  }

  emxInit_real_T(sp, &c_p, 1, &emlrtRTEI, true);
  a = c_p->size[0];
  c_p->size[0] = p->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)c_p, a, sizeof(real_T), &emlrtRTEI);
  vstride = p->size[0];
  for (a = 0; a < vstride; a++) {
    c_p->data[a] = -p->data[a];
  }

  emxInit_real_T(sp, &b_q, 1, &emlrtRTEI, true);
  st.site = &r_emlrtRSI;
  rdivide(&st, c_p, ph, b);
  a = b_q->size[0];
  b_q->size[0] = q->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_q, a, sizeof(real_T), &emlrtRTEI);
  vstride = q->size[0];
  emxFree_real_T(&c_p);
  for (a = 0; a < vstride; a++) {
    b_q->data[a] = -q->data[a];
  }

  emxFree_real_T(&q);
  st.site = &s_emlrtRSI;
  rdivide(&st, b_q, ph, cc);
  b_rdivide(sp, ph, p);
  a = p->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)p, a, sizeof(real_T), &emlrtRTEI);
  vstride = p->size[0];
  emxFree_real_T(&b_q);
  for (a = 0; a < vstride; a++) {
    p->data[a]--;
  }

  emxInit_real_T(sp, &r5, 1, &emlrtRTEI, true);
  a = A1->size[0];
  vstride = C1->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &i_emlrtECI, sp);
  }

  a = r5->size[0];
  r5->size[0] = th->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r5, a, sizeof(real_T), &emlrtRTEI);
  vstride = th->size[0];
  for (a = 0; a < vstride; a++) {
    r5->data[a] = 2.0 * th->data[a];
  }

  emxInit_real_T(sp, &b_A1, 1, &emlrtRTEI, true);
  a = b_A1->size[0];
  b_A1->size[0] = A1->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_A1, a, sizeof(real_T), &emlrtRTEI);
  vstride = A1->size[0];
  for (a = 0; a < vstride; a++) {
    b_A1->data[a] = A1->data[a] - C1->data[a];
  }

  st.site = &t_emlrtRSI;
  rdivide(&st, r5, b_A1, ph);
  st.site = &t_emlrtRSI;
  b_st.site = &mc_emlrtRSI;
  vstride = ph->size[0];
  c_st.site = &kc_emlrtRSI;
  emxFree_real_T(&b_A1);
  emxFree_real_T(&r5);
  overflow = ((!(1 > ph->size[0])) && (ph->size[0] > 2147483646));
  if (overflow) {
    d_st.site = &xb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }

  for (j = 0; j + 1 <= vstride; j++) {
    ph->data[j] = muDoubleScalarAtan(ph->data[j]);
  }

  a = ph->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)ph, a, sizeof(real_T), &emlrtRTEI);
  vstride = ph->size[0];
  for (a = 0; a < vstride; a++) {
    ph->data[a] /= 2.0;
  }

  /* tt(isnan(tt)) = 0; */
  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r0, a, sizeof(real_T), &emlrtRTEI);
  vstride = ph->size[0];
  for (a = 0; a < vstride; a++) {
    r0->data[a] = ph->data[a];
  }

  st.site = &u_emlrtRSI;
  b_cos(&st, r0);
  st.site = &u_emlrtRSI;
  b_power(&st, r0, z);
  a = A1->size[0];
  vstride = z->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &j_emlrtECI, sp);
  }

  a = r0->size[0];
  r0->size[0] = th->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r0, a, sizeof(real_T), &emlrtRTEI);
  vstride = th->size[0];
  for (a = 0; a < vstride; a++) {
    r0->data[a] = 2.0 * th->data[a];
  }

  a = r3->size[0];
  r3->size[0] = ph->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r3, a, sizeof(real_T), &emlrtRTEI);
  vstride = ph->size[0];
  for (a = 0; a < vstride; a++) {
    r3->data[a] = ph->data[a];
  }

  st.site = &u_emlrtRSI;
  b_sin(&st, r3);
  a = r0->size[0];
  vstride = r3->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &k_emlrtECI, sp);
  }

  a = r0->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r0, a, sizeof(real_T), &emlrtRTEI);
  vstride = r0->size[0];
  for (a = 0; a < vstride; a++) {
    r0->data[a] *= r3->data[a];
  }

  a = r3->size[0];
  r3->size[0] = ph->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r3, a, sizeof(real_T), &emlrtRTEI);
  vstride = ph->size[0];
  for (a = 0; a < vstride; a++) {
    r3->data[a] = ph->data[a];
  }

  st.site = &u_emlrtRSI;
  b_cos(&st, r3);
  a = r0->size[0];
  vstride = r3->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &k_emlrtECI, sp);
  }

  a = z->size[0];
  z->size[0] = A1->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, a, sizeof(real_T), &emlrtRTEI);
  vstride = A1->size[0];
  for (a = 0; a < vstride; a++) {
    z->data[a] *= A1->data[a];
  }

  a = r0->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r0, a, sizeof(real_T), &emlrtRTEI);
  vstride = r0->size[0];
  for (a = 0; a < vstride; a++) {
    r0->data[a] *= r3->data[a];
  }

  a = z->size[0];
  vstride = r0->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &j_emlrtECI, sp);
  }

  a = r3->size[0];
  r3->size[0] = ph->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r3, a, sizeof(real_T), &emlrtRTEI);
  vstride = ph->size[0];
  for (a = 0; a < vstride; a++) {
    r3->data[a] = ph->data[a];
  }

  st.site = &u_emlrtRSI;
  b_sin(&st, r3);
  st.site = &u_emlrtRSI;
  b_power(&st, r3, b_a);
  a = C1->size[0];
  vstride = b_a->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &l_emlrtECI, sp);
  }

  a = b_a->size[0];
  b_a->size[0] = C1->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_a, a, sizeof(real_T), &emlrtRTEI);
  vstride = C1->size[0];
  for (a = 0; a < vstride; a++) {
    b_a->data[a] *= C1->data[a];
  }

  a = z->size[0];
  vstride = b_a->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &j_emlrtECI, sp);
  }

  a = z->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)z, a, sizeof(real_T), &emlrtRTEI);
  vstride = z->size[0];
  for (a = 0; a < vstride; a++) {
    z->data[a] = (z->data[a] + r0->data[a]) + b_a->data[a];
  }

  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r0, a, sizeof(real_T), &emlrtRTEI);
  vstride = ph->size[0];
  for (a = 0; a < vstride; a++) {
    r0->data[a] = ph->data[a];
  }

  st.site = &v_emlrtRSI;
  b_sin(&st, r0);
  st.site = &v_emlrtRSI;
  b_power(&st, r0, r3);
  a = A1->size[0];
  vstride = r3->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &m_emlrtECI, sp);
  }

  a = th->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)th, a, sizeof(real_T), &emlrtRTEI);
  vstride = th->size[0];
  for (a = 0; a < vstride; a++) {
    th->data[a] *= 2.0;
  }

  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r0, a, sizeof(real_T), &emlrtRTEI);
  vstride = ph->size[0];
  for (a = 0; a < vstride; a++) {
    r0->data[a] = ph->data[a];
  }

  st.site = &v_emlrtRSI;
  b_sin(&st, r0);
  a = th->size[0];
  vstride = r0->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &n_emlrtECI, sp);
  }

  a = th->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)th, a, sizeof(real_T), &emlrtRTEI);
  vstride = th->size[0];
  for (a = 0; a < vstride; a++) {
    th->data[a] *= r0->data[a];
  }

  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r0, a, sizeof(real_T), &emlrtRTEI);
  vstride = ph->size[0];
  for (a = 0; a < vstride; a++) {
    r0->data[a] = ph->data[a];
  }

  st.site = &v_emlrtRSI;
  b_cos(&st, r0);
  a = th->size[0];
  vstride = r0->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &n_emlrtECI, sp);
  }

  a = A1->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)A1, a, sizeof(real_T), &emlrtRTEI);
  vstride = A1->size[0];
  for (a = 0; a < vstride; a++) {
    A1->data[a] *= r3->data[a];
  }

  a = th->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)th, a, sizeof(real_T), &emlrtRTEI);
  vstride = th->size[0];
  for (a = 0; a < vstride; a++) {
    th->data[a] *= r0->data[a];
  }

  a = A1->size[0];
  vstride = th->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &m_emlrtECI, sp);
  }

  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r0, a, sizeof(real_T), &emlrtRTEI);
  vstride = ph->size[0];
  for (a = 0; a < vstride; a++) {
    r0->data[a] = ph->data[a];
  }

  st.site = &v_emlrtRSI;
  b_cos(&st, r0);
  st.site = &v_emlrtRSI;
  b_power(&st, r0, r3);
  a = C1->size[0];
  vstride = r3->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &o_emlrtECI, sp);
  }

  a = C1->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)C1, a, sizeof(real_T), &emlrtRTEI);
  vstride = C1->size[0];
  for (a = 0; a < vstride; a++) {
    C1->data[a] *= r3->data[a];
  }

  a = A1->size[0];
  vstride = C1->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &m_emlrtECI, sp);
  }

  a = A1->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)A1, a, sizeof(real_T), &emlrtRTEI);
  vstride = A1->size[0];
  for (a = 0; a < vstride; a++) {
    A1->data[a] = (A1->data[a] - th->data[a]) + C1->data[a];
  }

  emxFree_real_T(&C1);
  a = th->size[0];
  th->size[0] = ph->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)th, a, sizeof(real_T), &emlrtRTEI);
  vstride = ph->size[0];
  for (a = 0; a < vstride; a++) {
    th->data[a] = ph->data[a];
  }

  st.site = &w_emlrtRSI;
  b_cos(&st, th);
  a = b->size[0];
  vstride = th->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &p_emlrtECI, sp);
  }

  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r0, a, sizeof(real_T), &emlrtRTEI);
  vstride = ph->size[0];
  for (a = 0; a < vstride; a++) {
    r0->data[a] = ph->data[a];
  }

  st.site = &w_emlrtRSI;
  b_sin(&st, r0);
  a = cc->size[0];
  vstride = r0->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &q_emlrtECI, sp);
  }

  a = th->size[0];
  th->size[0] = b->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)th, a, sizeof(real_T), &emlrtRTEI);
  vstride = b->size[0];
  for (a = 0; a < vstride; a++) {
    th->data[a] *= b->data[a];
  }

  a = r0->size[0];
  r0->size[0] = cc->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r0, a, sizeof(real_T), &emlrtRTEI);
  vstride = cc->size[0];
  for (a = 0; a < vstride; a++) {
    r0->data[a] *= cc->data[a];
  }

  a = th->size[0];
  vstride = r0->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &p_emlrtECI, sp);
  }

  a = th->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)th, a, sizeof(real_T), &emlrtRTEI);
  vstride = th->size[0];
  for (a = 0; a < vstride; a++) {
    th->data[a] += r0->data[a];
  }

  a = b->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b, a, sizeof(real_T), &emlrtRTEI);
  vstride = b->size[0];
  for (a = 0; a < vstride; a++) {
    b->data[a] = -b->data[a];
  }

  a = r0->size[0];
  r0->size[0] = ph->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)r0, a, sizeof(real_T), &emlrtRTEI);
  vstride = ph->size[0];
  for (a = 0; a < vstride; a++) {
    r0->data[a] = ph->data[a];
  }

  st.site = &x_emlrtRSI;
  b_sin(&st, r0);
  a = b->size[0];
  vstride = r0->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &r_emlrtECI, sp);
  }

  st.site = &x_emlrtRSI;
  b_cos(&st, ph);
  a = cc->size[0];
  vstride = ph->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &s_emlrtECI, sp);
  }

  a = b->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b, a, sizeof(real_T), &emlrtRTEI);
  vstride = b->size[0];
  for (a = 0; a < vstride; a++) {
    b->data[a] *= r0->data[a];
  }

  a = cc->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)cc, a, sizeof(real_T), &emlrtRTEI);
  vstride = cc->size[0];
  for (a = 0; a < vstride; a++) {
    cc->data[a] *= ph->data[a];
  }

  emxFree_real_T(&ph);
  a = b->size[0];
  vstride = cc->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &r_emlrtECI, sp);
  }

  a = b->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b, a, sizeof(real_T), &emlrtRTEI);
  vstride = b->size[0];
  for (a = 0; a < vstride; a++) {
    b->data[a] += cc->data[a];
  }

  emxFree_real_T(&cc);
  emxInit_real_T(sp, &b_z, 1, &emlrtRTEI, true);

  /*  A3=2*sqrt(D2.^2./A2.^2+E2.^2./(A2.*B2)-F2./A2); */
  /*  B3=2*sqrt(D2.^2./(A2.*B2)+E2.^2./B2.^2-F2./B2); */
  a = z->size[0];
  vstride = A1->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &t_emlrtECI, sp);
  }

  st.site = &y_emlrtRSI;
  b_power(&st, th, r0);
  st.site = &y_emlrtRSI;
  b_power(&st, z, r3);
  st.site = &y_emlrtRSI;
  rdivide(&st, r0, r3, b_a);
  st.site = &y_emlrtRSI;
  b_power(&st, b, r0);
  a = b_z->size[0];
  b_z->size[0] = z->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)b_z, a, sizeof(real_T), &emlrtRTEI);
  vstride = z->size[0];
  for (a = 0; a < vstride; a++) {
    b_z->data[a] = z->data[a] * A1->data[a];
  }

  emxInit_creal_T(sp, &A3, 1, &n_emlrtRTEI, true);
  st.site = &y_emlrtRSI;
  rdivide(&st, r0, b_z, r3);
  a = b_a->size[0];
  vstride = r3->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &u_emlrtECI, sp);
  }

  st.site = &y_emlrtRSI;
  rdivide(&st, p, z, r0);
  a = b_a->size[0];
  vstride = r0->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &u_emlrtECI, sp);
  }

  a = A3->size[0];
  A3->size[0] = b_a->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)A3, a, sizeof(creal_T), &emlrtRTEI);
  vstride = b_a->size[0];
  emxFree_real_T(&b_z);
  for (a = 0; a < vstride; a++) {
    A3->data[a].re = (b_a->data[a] + r3->data[a]) - r0->data[a];
    A3->data[a].im = 0.0;
  }

  st.site = &y_emlrtRSI;
  b_sqrt(&st, A3);
  a = A3->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)A3, a, sizeof(creal_T), &emlrtRTEI);
  vstride = A3->size[0];
  for (a = 0; a < vstride; a++) {
    A3->data[a].re *= 2.0;
    A3->data[a].im *= 2.0;
  }

  emxInit_real_T(sp, &c_z, 1, &emlrtRTEI, true);
  a = z->size[0];
  vstride = A1->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &v_emlrtECI, sp);
  }

  st.site = &ab_emlrtRSI;
  b_power(&st, th, r0);
  a = c_z->size[0];
  c_z->size[0] = z->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)c_z, a, sizeof(real_T), &emlrtRTEI);
  vstride = z->size[0];
  for (a = 0; a < vstride; a++) {
    c_z->data[a] = z->data[a] * A1->data[a];
  }

  emxFree_real_T(&z);
  emxInit_creal_T(sp, &B3, 1, &o_emlrtRTEI, true);
  st.site = &ab_emlrtRSI;
  rdivide(&st, r0, c_z, r3);
  st.site = &ab_emlrtRSI;
  b_power(&st, b, r0);
  st.site = &ab_emlrtRSI;
  b_power(&st, A1, b_a);
  st.site = &ab_emlrtRSI;
  rdivide(&st, r0, b_a, th);
  a = r3->size[0];
  vstride = th->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &w_emlrtECI, sp);
  }

  st.site = &ab_emlrtRSI;
  rdivide(&st, p, A1, r0);
  a = r3->size[0];
  vstride = r0->size[0];
  if (a != vstride) {
    emlrtSizeEqCheck1DR2012b(a, vstride, &w_emlrtECI, sp);
  }

  a = B3->size[0];
  B3->size[0] = r3->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)B3, a, sizeof(creal_T), &emlrtRTEI);
  vstride = r3->size[0];
  emxFree_real_T(&c_z);
  emxFree_real_T(&A1);
  emxFree_real_T(&p);
  emxFree_real_T(&b);
  emxFree_real_T(&b_a);
  for (a = 0; a < vstride; a++) {
    B3->data[a].re = (r3->data[a] + th->data[a]) - r0->data[a];
    B3->data[a].im = 0.0;
  }

  emxFree_real_T(&r0);
  emxFree_real_T(&r3);
  emxFree_real_T(&th);
  st.site = &ab_emlrtRSI;
  b_sqrt(&st, B3);
  a = B3->size[0];
  emxEnsureCapacity(sp, (emxArray__common *)B3, a, sizeof(creal_T), &emlrtRTEI);
  vstride = B3->size[0];
  for (a = 0; a < vstride; a++) {
    B3->data[a].re *= 2.0;
    B3->data[a].im *= 2.0;
  }

  /*  A3=2*real(sqrt(D2.^2./A2.^2+E2.^2./(A2.*B2)-F2./A2)); */
  /*  B3=2*real(sqrt(D2.^2./(A2.*B2)+E2.^2./B2.^2-F2./B2)); */
  /*  temp1 = D2.^2./A2.^2+E2.^2./(A2.*B2)-F2./A2; */
  /*  temp2 = D2.^2./(A2.*B2)+E2.^2./B2.^2-F2./B2; */
  /*  A3=2*sqrt(temp1(temp1>=0.*temp2>=0)); */
  /*  B3=2*sqrt(temp2(temp1>=0.*temp2>=0)); */
  st.site = &bb_emlrtRSI;
  b_st.site = &yb_emlrtRSI;
  c_st.site = &ac_emlrtRSI;
  overflow = true;
  if (B3->size[0] != A3->size[0]) {
    overflow = false;
  }

  if (!overflow) {
    emlrtErrorWithMessageIdR2012b(&c_st, &v_emlrtRTEI,
      "MATLAB:catenate:matrixDimensionMismatch", 0);
  }

  emxInit_creal_T1(&c_st, &varargin_1, 2, &emlrtRTEI, true);
  a = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = A3->size[0];
  varargin_1->size[1] = 2;
  emxEnsureCapacity(&b_st, (emxArray__common *)varargin_1, a, sizeof(creal_T),
                    &emlrtRTEI);
  vstride = A3->size[0];
  for (a = 0; a < vstride; a++) {
    varargin_1->data[a] = A3->data[a];
  }

  emxFree_creal_T(&A3);
  vstride = B3->size[0];
  for (a = 0; a < vstride; a++) {
    varargin_1->data[a + varargin_1->size[0]] = B3->data[a];
  }

  emxFree_creal_T(&B3);
  st.site = &bb_emlrtRSI;
  b_st.site = &dc_emlrtRSI;
  c_st.site = &ec_emlrtRSI;
  a = res->size[0];
  res->size[0] = varargin_1->size[0];
  emxEnsureCapacity(&c_st, (emxArray__common *)res, a, sizeof(creal_T),
                    &emlrtRTEI);
  vstride = varargin_1->size[0];
  d_st.site = &fc_emlrtRSI;
  overflow = ((!(1 > varargin_1->size[0])) && (varargin_1->size[0] > 2147483646));
  if (overflow) {
    e_st.site = &xb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }

  for (j = 1; j <= vstride; j++) {
    d_st.site = &gc_emlrtRSI;
    partialTrueCount = j;
    ixstop = j + vstride;
    b_mtmp = varargin_1->data[j - 1];
    if (muDoubleScalarIsNaN(varargin_1->data[j - 1].re) || muDoubleScalarIsNaN
        (varargin_1->data[j - 1].im)) {
      a = j + vstride;
      e_st.site = &ic_emlrtRSI;
      if ((vstride == 0) || (a > ixstop)) {
        overflow = false;
      } else {
        overflow = (ixstop > MAX_int32_T - vstride);
      }

      if (vstride == 0) {
        emlrtErrorWithMessageIdR2012b(&e_st, &w_emlrtRTEI,
          "Coder:builtins:VectorStride", 0);
      }

      if (overflow) {
        f_st.site = &xb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      exitg1 = false;
      while ((!exitg1) && (a <= ixstop)) {
        partialTrueCount = a;
        if (!(muDoubleScalarIsNaN(varargin_1->data[a - 1].re) ||
              muDoubleScalarIsNaN(varargin_1->data[a - 1].im))) {
          b_mtmp = varargin_1->data[a - 1];
          exitg1 = true;
        } else {
          a += vstride;
        }
      }
    }

    if (partialTrueCount < ixstop) {
      a = partialTrueCount + vstride;
      e_st.site = &hc_emlrtRSI;
      if ((vstride == 0) || (a > ixstop)) {
        overflow = false;
      } else {
        overflow = (ixstop > MAX_int32_T - vstride);
      }

      if (vstride == 0) {
        emlrtErrorWithMessageIdR2012b(&e_st, &w_emlrtRTEI,
          "Coder:builtins:VectorStride", 0);
      }

      if (overflow) {
        f_st.site = &xb_emlrtRSI;
        check_forloop_overflow_error(&f_st);
      }

      while (a <= ixstop) {
        b_varargin_1 = varargin_1->data[a - 1];
        if (relop(b_varargin_1, b_mtmp)) {
          b_mtmp = varargin_1->data[a - 1];
        }

        a += vstride;
      }
    }

    res->data[j - 1] = b_mtmp;
  }

  emxFree_creal_T(&varargin_1);
  vstride = res->size[0];
  for (ixstop = 0; ixstop < vstride; ixstop++) {
    if (res->data[ixstop].re > u) {
      a = dm->size[0];
      if (!((ixstop + 1 >= 1) && (ixstop + 1 <= a))) {
        emlrtDynamicBoundsCheckR2012b(ixstop + 1, 1, a, &c_emlrtBCI, sp);
      }
    }
  }

  emxFree_real_T(&dm);
  vstride = res->size[0] - 1;
  j = 0;
  for (ixstop = 0; ixstop <= vstride; ixstop++) {
    if (res->data[ixstop].re > u) {
      j++;
    }
  }

  partialTrueCount = 0;
  for (ixstop = 0; ixstop <= vstride; ixstop++) {
    if (res->data[ixstop].re > u) {
      a = res->size[0];
      if (!((ixstop + 1 >= 1) && (ixstop + 1 <= a))) {
        emlrtDynamicBoundsCheckR2012b(ixstop + 1, 1, a, &d_emlrtBCI, sp);
      }

      res->data[partialTrueCount].re = res->data[ixstop].re;
      a = res->size[0];
      if (!((ixstop + 1 >= 1) && (ixstop + 1 <= a))) {
        emlrtDynamicBoundsCheckR2012b(ixstop + 1, 1, a, &d_emlrtBCI, sp);
      }

      res->data[partialTrueCount].im = res->data[ixstop].im;
      partialTrueCount++;
    }
  }

  a = res->size[0];
  res->size[0] = j;
  emxEnsureCapacity(sp, (emxArray__common *)res, a, sizeof(creal_T), &emlrtRTEI);

  /*  if (max(res)>20) */
  /*      error('an extreme value of res detected') */
  /*  end */
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/* End of code generation (esim.c) */
