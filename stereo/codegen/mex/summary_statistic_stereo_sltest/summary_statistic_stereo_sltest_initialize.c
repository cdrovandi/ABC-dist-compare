/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * summary_statistic_stereo_sltest_initialize.c
 *
 * Code generation for function 'summary_statistic_stereo_sltest_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "summary_statistic_stereo_sltest.h"
#include "summary_statistic_stereo_sltest_initialize.h"
#include "_coder_summary_statistic_stereo_sltest_mex.h"
#include "summary_statistic_stereo_sltest_data.h"

/* Function Definitions */
void summary_statistic_stereo_sltest_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (summary_statistic_stereo_sltest_initialize.c) */
