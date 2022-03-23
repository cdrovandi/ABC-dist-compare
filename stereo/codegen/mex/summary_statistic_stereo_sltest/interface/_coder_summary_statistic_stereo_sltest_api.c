/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_summary_statistic_stereo_sltest_api.c
 *
 * Code generation for function '_coder_summary_statistic_stereo_sltest_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "summary_statistic_stereo_sltest.h"
#include "_coder_summary_statistic_stereo_sltest_api.h"
#include "summary_statistic_stereo_sltest_emxutil.h"
#include "summary_statistic_stereo_sltest_data.h"

/* Variable Definitions */
static emlrtRTEInfo emlrtRTEI = { 1,   /* lineNo */
  1,                                   /* colNo */
  "_coder_summary_statistic_stereo_sltest_api",/* fName */
  ""                                   /* pName */
};

/* Function Declarations */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *useLog,
  const char_T *identifier);
static real_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *y, const
  char_T *identifier, emxArray_real_T *b_y);
static const mxArray *emlrt_marshallOut(const real_T u[4]);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);

/* Function Definitions */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  e_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *useLog,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(useLog), &thisId);
  emlrtDestroyArray(&useLog);
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

static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[1] = { -1 };

  const boolean_T bv0[1] = { true };

  int32_T iv3[1];
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv0[0],
    iv3);
  ret->size[0] = iv3[0];
  ret->allocatedSize = ret->size[0];
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *y, const
  char_T *identifier, emxArray_real_T *b_y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(y), &thisId, b_y);
  emlrtDestroyArray(&y);
}

static const mxArray *emlrt_marshallOut(const real_T u[4])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv1[2] = { 0, 0 };

  static const int32_T iv2[2] = { 1, 4 };

  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv1, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m0, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m0, iv2, 2);
  emlrtAssign(&y, m0);
  return y;
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void summary_statistic_stereo_sltest_api(const mxArray * const prhs[2], const
  mxArray *plhs[1])
{
  real_T (*ss)[4];
  emxArray_real_T *y;
  real_T useLog;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  ss = (real_T (*)[4])mxMalloc(sizeof(real_T [4]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &y, 1, &emlrtRTEI, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "y", y);
  useLog = c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "useLog");

  /* Invoke the target function */
  summary_statistic_stereo_sltest(&st, y, useLog, *ss);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*ss);
  y->canFreeData = false;
  emxFree_real_T(&y);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_summary_statistic_stereo_sltest_api.c) */
