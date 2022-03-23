/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_summary_statistic_stereo_sltest_mex.c
 *
 * Code generation for function '_coder_summary_statistic_stereo_sltest_mex'
 *
 */

/* Include files */
#include "summary_statistic_stereo_sltest.h"
#include "_coder_summary_statistic_stereo_sltest_mex.h"
#include "summary_statistic_stereo_sltest_terminate.h"
#include "_coder_summary_statistic_stereo_sltest_api.h"
#include "summary_statistic_stereo_sltest_initialize.h"
#include "summary_statistic_stereo_sltest_data.h"

/* Function Declarations */
static void c_summary_statistic_stereo_slte(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[2]);

/* Function Definitions */
static void c_summary_statistic_stereo_slte(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[2])
{
  int32_T n;
  const mxArray *inputs[2];
  const mxArray *outputs[1];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        31, "summary_statistic_stereo_sltest");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 31,
                        "summary_statistic_stereo_sltest");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
  }

  /* Call the function. */
  summary_statistic_stereo_sltest_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  summary_statistic_stereo_sltest_terminate();
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(summary_statistic_stereo_sltest_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  summary_statistic_stereo_sltest_initialize();

  /* Dispatch the entry-point. */
  c_summary_statistic_stereo_slte(nlhs, plhs, nrhs, prhs);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_summary_statistic_stereo_sltest_mex.c) */
