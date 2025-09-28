//
// File: rt_nonfinite.cpp
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
//       Function to initialize non-finites,
//       (Inf, NaN and -Inf).
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rtGetInf.h"
#define NumBitsPerChar                 8U

extern "C" {
  // double rtInf;
  // double rtMinusInf;
  // float rtNaN;
  float rtInfF;
  float rtMinusInfF;
  float rtNaNF;
}
  extern "C"
{
  //
  // Initialize the rtInf, rtMinusInf, and rtNaN needed by the
  // generated code. NaN is initialized as non-signaling. Assumes IEEE.
  //
  void rt_InitInfAndNaN(size_t realSize)
  {
    (void) (realSize);
    // rtNaN = rtGetNaN();
    rtNaNF = rtGetNaNF();
    // rtInf = rtGetInf();
    rtInfF = rtGetInfF();
    // rtMinusInf = rtGetMinusInf();
    rtMinusInfF = rtGetMinusInfF();
  }

  // // Test if value is infinite
  // bool rtIsInf(float value)
  // {
  //   return (bool)((is_equal(value, rtInf) || is_equal(value, rtMinusInf)) ? 1U : 0U);//is_equal
  // }

  // Test if single-precision value is infinite
  bool rtIsInfF(float value)
  {
    return (bool)((is_equal(value, rtInfF) || is_equal(value, rtMinusInfF)) ? 1U : 0U);
  }

  // // Test if value is not a number
  // bool rtIsNaN(float value)
  // {
  //   bool result = (bool) 0;
  //   size_t bitsPerReal = sizeof(float) * (NumBitsPerChar);
  //   if (bitsPerReal == 32U) {
  //     result = rtIsNaNF((float)value);
  //   } else {
  //     union {
  //       LittleEndianIEEEDouble bitVal;
  //       float fltVal;
  //     } tmpVal;

  //     tmpVal.fltVal = value;
  //     result = (bool)((tmpVal.bitVal.words.wordH & 0x7FF00000) ==
  //                          0x7FF00000 &&
  //                          ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
  //                           (tmpVal.bitVal.words.wordL != 0) ));
  //   }

  //   return result;
  // }

  // Test if single-precision value is not a number
  bool rtIsNaNF(float value)
  {
    IEEESingle tmp;
    tmp.wordL.wordLreal = value;
    return (bool)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                       (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
