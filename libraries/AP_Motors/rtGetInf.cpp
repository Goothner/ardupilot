//
// File: rtGetInf.cpp
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

//
//  Abstract:
//       Function to initialize non-finite, Inf
#include "rtGetInf.h"
#define NumBitsPerChar                 8U

extern "C" {
  //
  // Initialize rtInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  // float rtGetInf(void)
  // {
  //   size_t bitsPerReal = sizeof(float) * (NumBitsPerChar);
  //   float inf = 0.0;
  //   if (bitsPerReal == 32U) {
  //     inf = rtGetInfF();
  //   } else {
  //     union {
  //       LittleEndianIEEEDouble bitVal;
  //       float fltVal;
  //     } tmpVal;

  //     tmpVal.bitVal.words.wordH = 0x7FF00000U;
  //     tmpVal.bitVal.words.wordL = 0x00000000U;
  //     inf = tmpVal.fltVal;
  //   }

  //   return inf;
  // }

  //
  // Initialize rtInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  float rtGetInfF(void)
  {
    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000U;
    return infF.wordL.wordLreal;
  }

  //
  // Initialize rtMinusInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  // float rtGetMinusInf(void)
  // {
  //   size_t bitsPerReal = sizeof(float) * (NumBitsPerChar);
  //   float minf = 0.0;
  //   if (bitsPerReal == 32U) {
  //     minf = rtGetMinusInfF();
  //   } else {
  //     union {
  //       LittleEndianIEEEDouble bitVal;
  //       float fltVal;
  //     } tmpVal;

  //     tmpVal.bitVal.words.wordH = 0xFFF00000U;
  //     tmpVal.bitVal.words.wordL = 0x00000000U;
  //     minf = tmpVal.fltVal;
  //   }

  //   return minf;
  // }

  //
  // Initialize rtMinusInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  float rtGetMinusInfF(void)
  {
    IEEESingle minfF;
    minfF.wordL.wordLuint = 0xFF800000U;
    return minfF.wordL.wordLreal;
  }
}
//
// File trailer for generated code.
//
// [EOF]
//
