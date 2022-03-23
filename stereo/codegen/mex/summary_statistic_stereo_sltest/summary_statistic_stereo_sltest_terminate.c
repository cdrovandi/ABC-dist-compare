/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * summary_statistic_stereo_sltest_terminate.c
 *
 * Code generation for function 'summary_statistic_stereo_sltest_terminate'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "summary_statistic_stereo_sltest.h"
#include "summary_statistic_stereo_sltest_terminate.h"
#include "_coder_summary_statistic_stereo_sltest_mex.h"
#include "summary_statistic_stereo_sltest_data.h"

/* Function Definitions */
void summary_statistic_stereo_sltest_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void summary_statistic_stereo_sltest_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/* End of code generation (summary_statistic_stereo_sltest_terminate.c) */
