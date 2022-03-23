/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * randn.h
 *
 * Code generation for function 'randn'
 *
 */

#ifndef RANDN_H
#define RANDN_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mwmathutil.h"
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "esim_types.h"

/* Function Declarations */
extern real_T randn(void);

#ifdef __WATCOMC__

#pragma aux randn value [8087];

#endif
#endif

/* End of code generation (randn.h) */
