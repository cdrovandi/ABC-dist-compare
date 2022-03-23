/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_esim_api.c
 *
 * Code generation for function '_coder_esim_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "esim.h"
#include "_coder_esim_api.h"
#include "esim_emxutil.h"
#include "esim_data.h"

/* Variable Definitions */
static emlrtRTEInfo t_emlrtRTEI = { 1, /* lineNo */
  1,                                   /* colNo */
  "_coder_esim_api",                   /* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3];
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  char_T *identifier);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *theta,
  const char_T *identifier))[3];
static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const
  emxArray_creal_T *u);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[3]
{
  real_T (*y)[3];
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(u), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[3]
{
  real_T (*ret)[3];
  static const int32_T dims[2] = { 1, 3 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[3])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *theta,
  const char_T *identifier))[3]
{
  real_T (*y)[3];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(theta), &thisId);
  emlrtDestroyArray(&theta);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp, const
  emxArray_creal_T *u)
{
  const mxArray *y;
  const mxArray *m1;
  y = NULL;
  m1 = emlrtCreateNumericArray(1, *(int32_T (*)[1])u->size, mxDOUBLE_CLASS,
    mxCOMPLEX);
  emlrtExportNumericArrayR2013b(sp, m1, (void *)&u->data[0], 8);
  emlrtAssign(&y, m1);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void esim_api(const mxArray * const prhs[2], const mxArray *plhs[1])
{
  emxArray_creal_T *res;
  real_T (*theta)[3];
  real_T u;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_creal_T(&st, &res, 1, &t_emlrtRTEI, true);

  /* Marshall function inputs */
  theta = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "theta");
  u = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "u");

  /* Invoke the target function */
  esim(&st, *theta, u, res);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&st, res);
  emxFree_creal_T(&res);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_esim_api.c) */
