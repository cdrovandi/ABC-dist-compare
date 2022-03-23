/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * esim_initialize.c
 *
 * Code generation for function 'esim_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "esim.h"
#include "esim_initialize.h"
#include "eml_randn.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "eml_rand_shr3cong_stateful.h"
#include "eml_rand_mcg16807_stateful.h"
#include "eml_rand.h"
#include "_coder_esim_mex.h"
#include "esim_data.h"

/* Function Declarations */
static void esim_once(void);

/* Function Definitions */
static void esim_once(void)
{
  d_state_not_empty_init();
  b_method_not_empty_init();
  c_state_not_empty_init();
  b_state_not_empty_init();
  state_not_empty_init();
  method_not_empty_init();
  eml_rand_init();
  eml_rand_mcg16807_stateful_init();
  eml_rand_shr3cong_stateful_init();
  c_eml_rand_mt19937ar_stateful_i();
  eml_randn_init();
}

void esim_initialize(void)
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
  emlrtLicenseCheckR2012b(&st, "Statistics_Toolbox", 2);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    esim_once();
  }
}

/* End of code generation (esim_initialize.c) */
