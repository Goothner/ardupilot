//
// File: rt_nonfinite.h
//
// Code generated for Simulink model 'CONSCALE_CON_TBATT_CONPARA_CA'.
//
// Model version                  : 1.716
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Sat Sep 27 10:27:13 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_rt_nonfinite_h_
#define RTW_HEADER_rt_nonfinite_h_
#include <stddef.h>
#include "rtwtypes.h"
#ifdef __cplusplus

extern "C" {

#endif

  extern float rtInf;
  extern float rtMinusInf;
  extern float rtNaN;
  // extern float rtInfF;
  // extern float rtMinusInfF;
  // extern float rtNaNF;
  extern void rt_InitInfAndNaN(size_t realSize);
  // extern bool rtIsInf(float value);
  extern bool rtIsInfF(float value);
  // extern bool rtIsNaN(float value);
  extern bool rtIsNaNF(float value);
  typedef struct {
    struct {
      uint32_t wordH;
      uint32_t wordL;
    } words;
  } BigEndianIEEEDouble;

  typedef struct {
    struct {
      uint32_t wordL;
      uint32_t wordH;
    } words;
  } LittleEndianIEEEDouble;

  typedef struct {
    union {
      float wordLreal;
      uint32_t wordLuint;
    } wordL;
  } IEEESingle;

#ifdef __cplusplus

}                                      // extern "C"
#endif
#endif                                 // RTW_HEADER_rt_nonfinite_h_

//
// File trailer for generated code.
//
// [EOF]
//
