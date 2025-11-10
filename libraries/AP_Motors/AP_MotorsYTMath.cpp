#include <AP_HAL/AP_HAL.h>
//#include <AP_Math/AP_Math.h>
#include "AP_MotorsYT.h"
#include <AP_Vehicle/AP_Vehicle_Type.h>

#include <cmath>
#include <cstring>
#include "rtwtypes.h"

#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

//extern const AP_HAL::HAL& hal;


float AP_MotorsYT::look1_iflf_binlxpw(float u0, const float bp0[], const float table[], uint32_t maxIndex)
{
  float frac;
  uint32_t iRght;
  uint32_t iLeft;
  uint32_t bpIdx;

  // Column-major Lookup 1-D
  // Search method: 'binary'
  // Use previous index: 'off'
  // Interpolation method: 'Linear point-slope'
  // Extrapolation method: 'Linear'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  // Prelookup - Index and Fraction
  // Index Search method: 'binary'
  // Extrapolation method: 'Linear'
  // Use previous index: 'off'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Remove protection against out-of-range input in generated code: 'off'

  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    // Binary Search
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  // Column-major Interpolation 1-D
  // Interpolation method: 'Linear point-slope'
  // Use last breakpoint for index at or above upper limit: 'off'
  // Overflow mode: 'portable wrapping'

  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

// Function for MATLAB Function: '<S1>/MATLAB Function'
float AP_MotorsYT::xnrm2(int32_t n, const float* x, int32_t ix0)
{
  float y;
  float scale;
  int32_t kend;
  float absxk;
  float t;
  int32_t k;
  y = 0.0F;
  if (n >= 1) {
    if (n == 1) {
      y = fabsf(x[ix0 - 1]);
    } else {
      scale = 1.29246971E-26F;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = fabsf(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0F;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * safe_sqrt(y);
    }
  }

  return y;
}

// // Function for MATLAB Function: '<S1>/MATLAB Function'
// float AP_MotorsYT::xnrm2_j(int32_t n, const float* x, int32_t ix0)
// {
//   float y;
//   float scale;
//   int32_t kend;
//   float absxk;
//   float t;
//   int32_t k;
//   y = 0.0F;
//   if (n >= 1) {
//     if (n == 1) {
//       y = fabsf(x[ix0 - 1]);
//     } else {
//       scale = 1.29246971E-26F;
//       kend = (ix0 + n) - 1;
//       for (k = ix0; k <= kend; k++) {
//         absxk = fabsf(x[k - 1]);
//         if (absxk > scale) {
//           t = scale / absxk;
//           y = y * t * t + 1.0F;
//           scale = absxk;
//         } else {
//           t = absxk / scale;
//           y += t * t;
//         }
//       }

//       y = scale * safe_sqrt(y);
//     }
//   }

//   return y;
// }

// // Function for MATLAB Function: '<S1>/MATLAB Function'
// void AP_MotorsYT::xaxpy_m0(int32_t n, float a, const float* x, int32_t ix0, float* y, int32_t iy0)
// {
//   int32_t ix;
//   int32_t iy;
//   int32_t k;
//   if ((n >= 1) && !is_zero(a)) {//(!(a == 0.0F))
//     ix = ix0 - 1;
//     iy = iy0 - 1;
//     for (k = 0; k < n; k++) {
//       y[iy] += a * x[ix];
//       ix++;
//       iy++;
//     }
//   }
// }

// Function for MATLAB Function: '<S1>/MATLAB Function'
void AP_MotorsYT::xaxpy_m(int32_t n, float a, const float* x, int32_t ix0, float* y, int32_t iy0)
{
  int32_t ix;
  int32_t iy;
  int32_t k;
  if ((n >= 1) && !is_zero(a)) {//(!(a == 0.0F))
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<S1>/MATLAB Function'
float AP_MotorsYT::xdotc(int32_t n, const float* x, int32_t ix0, const float* y, int32_t iy0)
{
  float d;
  int32_t ix;
  int32_t iy;
  int32_t k;
  d = 0.0F;
  if (n >= 1) {
    ix = ix0;
    iy = iy0;
    for (k = 0; k < n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

// // Function for MATLAB Function: '<S1>/MATLAB Function'
// float AP_MotorsYT::xdotc_e(int32_t n, const float* x, int32_t ix0,const float* y, int32_t iy0)
// {
//   float d;
//   int32_t ix;
//   int32_t iy;
//   int32_t k;
//   d = 0.0F;
//   if (n >= 1) {
//     ix = ix0;
//     iy = iy0;
//     for (k = 0; k < n; k++) {
//       d += x[ix - 1] * y[iy - 1];
//       ix++;
//       iy++;
//     }
//   }

//   return d;
// }

// Function for MATLAB Function: '<S1>/MATLAB Function'
void AP_MotorsYT::xaxpy(int32_t n, float a, int32_t ix0, float* y, int32_t iy0)
{
  int32_t ix;
  int32_t iy;
  int32_t k;
  if ((n >= 1) && !is_zero(a)) {//(!(a == 0.0F))
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

// // Function for MATLAB Function: '<S1>/MATLAB Function'
// void AP_MotorsYT::xaxpy_m0a(int32_t n, float a, int32_t ix0, float* y, int32_t iy0)
// {
//   int32_t ix;
//   int32_t iy;
//   int32_t k;
//   if ((n >= 1) && !is_zero(a)) {//(!(a == 0.0F))
//     ix = ix0 - 1;
//     iy = iy0 - 1;
//     for (k = 0; k < n; k++) {
//       y[iy] += a * y[ix];
//       ix++;
//       iy++;
//     }
//   }
// }

// Function for MATLAB Function: '<S1>/MATLAB Function'
void AP_MotorsYT::xscal(float a, float* x, int32_t len, int32_t ix0)
{
  int32_t k;
  int32_t count = (len/4) -1;
  for (k = ix0; k <= ix0 + count; k++) {
    x[k - 1] *= a;
  }
}

// Function for MATLAB Function: '<S1>/MATLAB Function'
void AP_MotorsYT::xscal_c(float a, float* x, int32_t len, int32_t ix0)
{
  int32_t k;
  int32_t count = (len/4) -1;
  for (k = ix0; k <= ix0 + count; k++) {
    x[k - 1] *= a;
  }
}

// Function for MATLAB Function: '<S1>/MATLAB Function'
void AP_MotorsYT::xswap(float x[16], int32_t ix0, int32_t iy0)
{
  int32_t ix;
  int32_t iy;
  float temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  temp = x[ix];
  x[ix] = x[iy];
  x[iy] = temp;
  ix++;
  iy++;
  temp = x[ix];
  x[ix] = x[iy];
  x[iy] = temp;
  ix++;
  iy++;
  temp = x[ix];
  x[ix] = x[iy];
  x[iy] = temp;
  ix++;
  iy++;
  temp = x[ix];
  x[ix] = x[iy];
  x[iy] = temp;
}

// Function for MATLAB Function: '<S1>/MATLAB Function'
void AP_MotorsYT::xswap_m(float x[80], int32_t ix0, int32_t iy0)
{
  int32_t ix;
  int32_t iy;
  float temp;
  int32_t k;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 20; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix++;
    iy++;
  }
}

// Function for MATLAB Function: '<S1>/MATLAB Function'
void AP_MotorsYT::xrotg(float *a, float *b, float *c, float *s)
{
  float roe;
  float absa;
  float absb;
  float scale;
  float ads;
  float bds;
  roe = *b;
  absa = fabsf(*a);
  absb = fabsf(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (is_zero(scale)) {//(scale == 0.0F)
    *s = 0.0F;
    *c = 1.0F;
    scale = 0.0F;
    *b = 0.0F;
  } else {
    ads = absa / scale;
    bds = absb / scale;
    scale *= safe_sqrt(ads * ads + bds * bds);
    if (roe < 0.0F) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      *b = *s;
    } else if (!is_zero(*c)) {//(*c != 0.0F)
      *b = 1.0F / *c;
    } else {
      *b = 1.0F;
    }
  }

  *a = scale;
}

// Function for MATLAB Function: '<S1>/MATLAB Function'
void AP_MotorsYT::xrot(float x[16], int32_t ix0, int32_t iy0, float c, float s)
{
  int32_t ix;
  int32_t iy;
  float temp;
  ix = ix0 - 1;
  iy = iy0 - 1;
  temp = c * x[ix] + s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = temp;
  iy++;
  ix++;
  temp = c * x[ix] + s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = temp;
  iy++;
  ix++;
  temp = c * x[ix] + s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = temp;
  iy++;
  ix++;
  temp = c * x[ix] + s * x[iy];
  x[iy] = c * x[iy] - s * x[ix];
  x[ix] = temp;
}

// Function for MATLAB Function: '<S1>/MATLAB Function'
void AP_MotorsYT::xrot_f(float x[80], int32_t ix0, int32_t iy0, float c, float s)
{
  int32_t ix;
  int32_t iy;
  float temp;
  int32_t k;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 20; k++) {
    temp = c * x[ix] + s * x[iy];
    x[iy] = c * x[iy] - s * x[ix];
    x[ix] = temp;
    iy++;
    ix++;
  }
}

// Function for MATLAB Function: '<S1>/MATLAB Function'
void AP_MotorsYT::_svd(const float A[80], float U[80], float s[4], float V[16])
{
  float b_A[80];
  float b_s[4];
  float e[4];
  float work[20];
  float Vf[16];
  int32_t qq;
  bool apply_transform;
  float nrm;
  int32_t qjj;
  int32_t qp1jj;
  int32_t m;
  float rt;
  float ztest0;
  float smm1;
  float emm1;
  float sqds;
  float shift;
  int32_t c_q;
  bool exitg1;
  std::memcpy(&b_A[0], &A[0], 80U * sizeof(float));
  e[0] = 0.0F;
  e[1] = 0.0F;
  e[2] = 0.0F;
  e[3] = 0.0F;
  std::memset(&work[0], 0, 20U * sizeof(float));
  std::memset(&U[0], 0, 80U * sizeof(float));
  std::memset(&Vf[0], 0, sizeof(float) << 4U);
  apply_transform = false;
  nrm = xnrm2(20, b_A, 1);
  if (nrm > 0.0F) {
    apply_transform = true;
    if (b_A[0] < 0.0F) {
      b_s[0] = -nrm;
    } else {
      b_s[0] = nrm;
    }

    if (fabsf(b_s[0]) >= 9.86076132E-32F) {
      nrm = 1.0F / b_s[0];
      for (m = 0; m < 20; m++) {
        b_A[m] *= nrm;
      }
    } else {
      for (m = 0; m < 20; m++) {
        b_A[m] /= b_s[0];
      }
    }

    b_A[0]++;
    b_s[0] = -b_s[0];
  } else {
    b_s[0] = 0.0F;
  }

  for (m = 1; m + 1 < 5; m++) {
    qjj = 20 * m;
    if (apply_transform) {
      xaxpy(20, -(xdotc(20,
        b_A, 1, b_A, qjj + 1) / b_A[0]), 1, b_A, qjj + 1);
    }

    e[m] = b_A[qjj];
  }

  for (m = 0; m + 1 < 21; m++) {
    U[m] = b_A[m];
  }

  nrm = xnrm2(3, e, 2);//xnrm2_j
  if (is_zero(nrm)) {
    e[0] = 0.0F;
  } else {
    if (e[1] < 0.0F) {
      e[0] = -nrm;
    } else {
      e[0] = nrm;
    }

    nrm = e[0];
    if (fabsf(e[0]) >= 9.86076132E-32F) {
      nrm = 1.0F / e[0];
      for (m = 1; m < 4; m++) {
        e[m] *= nrm;
      }
    } else {
      for (m = 1; m < 4; m++) {
        e[m] /= nrm;
      }
    }

    e[1]++;
    e[0] = -e[0];
    for (m = 1; m + 1 < 21; m++) {
      work[m] = 0.0F;
    }

    for (m = 1; m + 1 < 5; m++) {
      xaxpy_m(19, e[m], b_A, 20 * m + 2, work, 2);
    }

    for (m = 1; m + 1 < 5; m++) {
      xaxpy_m(19, -e[m] / e[1], work, 2, b_A, 20 * m + 2);//xaxpy_m0
    }
  }

  for (m = 1; m + 1 < 5; m++) {
    Vf[m] = e[m];
  }

  apply_transform = false;
  nrm = xnrm2(19, b_A, 22);
  if (nrm > 0.0F) {
    apply_transform = true;
    if (b_A[21] < 0.0F) {
      b_s[1] = -nrm;
    } else {
      b_s[1] = nrm;
    }

    if (fabsf(b_s[1]) >= 9.86076132E-32F) {
      nrm = 1.0F / b_s[1];
      for (m = 21; m < 40; m++) {
        b_A[m] *= nrm;
      }
    } else {
      for (m = 21; m < 40; m++) {
        b_A[m] /= b_s[1];
      }
    }

    b_A[21]++;
    b_s[1] = -b_s[1];
  } else {
    b_s[1] = 0.0F;
  }

  for (m = 2; m + 1 < 5; m++) {
    qjj = 20 * m + 1;
    if (apply_transform) {
      xaxpy(19, -(xdotc(19,
        b_A, 22, b_A, qjj + 1) / b_A[21]), 22, b_A, qjj + 1);
    }

    e[m] = b_A[qjj];
  }

  for (m = 1; m + 1 < 21; m++) {
    U[m + 20] = b_A[m + 20];
  }

  nrm = xnrm2(2, e, 3);//xnrm2_j
  if (is_zero(nrm)) {//(nrm == 0.0F)
    e[1] = 0.0F;
  } else {
    if (e[2] < 0.0F) {
      e[1] = -nrm;
    } else {
      e[1] = nrm;
    }

    nrm = e[1];
    if (fabsf(e[1]) >= 9.86076132E-32F) {
      nrm = 1.0F / e[1];
      for (m = 2; m < 4; m++) {
        e[m] *= nrm;
      }
    } else {
      for (m = 2; m < 4; m++) {
        e[m] /= nrm;
      }
    }

    e[2]++;
    e[1] = -e[1];
    for (m = 2; m + 1 < 21; m++) {
      work[m] = 0.0F;
    }

    for (m = 2; m + 1 < 5; m++) {
      xaxpy_m(18, e[m], b_A, 20 * m + 3, work, 3);
    }

    for (m = 2; m + 1 < 5; m++) {
      xaxpy_m(18, -e[m] / e[2], work, 3, b_A, 20 * m + 3);//xaxpy_m0
    }
  }

  for (m = 2; m + 1 < 5; m++) {
    Vf[m + 4] = e[m];
  }

  apply_transform = false;
  nrm = xnrm2(18, b_A, 43);
  if (nrm > 0.0F) {
    apply_transform = true;
    if (b_A[42] < 0.0F) {
      b_s[2] = -nrm;
    } else {
      b_s[2] = nrm;
    }

    if (fabsf(b_s[2]) >= 9.86076132E-32F) {
      nrm = 1.0F / b_s[2];
      for (m = 42; m < 60; m++) {
        b_A[m] *= nrm;
      }
    } else {
      for (m = 42; m < 60; m++) {
        b_A[m] /= b_s[2];
      }
    }

    b_A[42]++;
    b_s[2] = -b_s[2];
  } else {
    b_s[2] = 0.0F;
  }

  for (m = 3; m + 1 < 5; m++) {
    qjj = 20 * m + 2;
    if (apply_transform) {
      xaxpy(18, -(xdotc(18,
        b_A, 43, b_A, qjj + 1) / b_A[42]), 43, b_A, qjj + 1);
    }

    e[m] = b_A[qjj];
  }

  for (m = 2; m + 1 < 21; m++) {
    U[m + 40] = b_A[m + 40];
  }

  nrm = xnrm2(17, b_A, 64);
  if (nrm > 0.0F) {
    if (b_A[63] < 0.0F) {
      b_s[3] = -nrm;
    } else {
      b_s[3] = nrm;
    }

    if (fabsf(b_s[3]) >= 9.86076132E-32F) {
      nrm = 1.0F / b_s[3];
      for (m = 63; m < 80; m++) {
        b_A[m] *= nrm;
      }
    } else {
      for (m = 63; m < 80; m++) {
        b_A[m] /= b_s[3];
      }
    }

    b_A[63]++;
    b_s[3] = -b_s[3];
  } else {
    b_s[3] = 0.0F;
  }

  for (m = 3; m + 1 < 21; m++) {
    U[m + 60] = b_A[m + 60];
  }

  m = 2;
  e[2] = b_A[62];
  e[3] = 0.0F;
  for (c_q = 3; c_q >= 0; c_q--) {
    qq = 20 * c_q + c_q;
    if (!is_zero(b_s[c_q])) {//(b_s[c_q] != 0.0F)
      for (qp1jj = c_q + 1; qp1jj + 1 < 5; qp1jj++) {
        qjj = (20 * qp1jj + c_q) + 1;
        xaxpy(20 - c_q,
          -(xdotc(20 - c_q, U, qq + 1, U, qjj) / U[qq]),
          qq + 1, U, qjj);
      }

      for (qjj = c_q; qjj + 1 < 21; qjj++) {
        qp1jj = 20 * c_q + qjj;
        U[qp1jj] = -U[qp1jj];
      }

      U[qq]++;
      for (qq = 0; qq < c_q; qq++) {
        U[qq + 20 * c_q] = 0.0F;
      }
    } else {
      std::memset(&U[c_q * 20], 0, 20U * sizeof(float));
      U[qq] = 1.0F;
    }
  }

  for (c_q = 3; c_q >= 0; c_q--) {
    if ((c_q + 1 <= 2) && !is_zero(e[c_q])) {//(e[c_q] != 0.0F)
      qq = ((c_q << 2) + c_q) + 2;
      for (qjj = c_q + 1; qjj + 1 < 5; qjj++) {
        qp1jj = ((qjj << 2) + c_q) + 2;
        xaxpy(3 - c_q,//xaxpy_m0a
          -(xdotc(3 - c_q, Vf, qq, Vf, qp1jj) / Vf[qq//xdotc_e
            - 1]), qq, Vf, qp1jj);
      }
    }

    qq = c_q << 2;
    Vf[qq] = 0.0F;
    Vf[qq + 1] = 0.0F;
    Vf[qq + 2] = 0.0F;
    Vf[qq + 3] = 0.0F;
    Vf[c_q + (c_q << 2)] = 1.0F;
  }

  ztest0 = e[0];
  if (!is_zero(b_s[0])) {//(b_s[0] != 0.0F)
    rt = fabsf(b_s[0]);
    nrm = b_s[0] / rt;
    b_s[0] = rt;
    ztest0 = e[0] / nrm;
    xscal(nrm, U, 80, 1);
  }

  if (!is_zero(ztest0)) {//(ztest0 != 0.0F) 
    rt = fabsf(ztest0);
    nrm = rt / ztest0;
    ztest0 = rt;
    b_s[1] *= nrm;
    xscal(nrm, Vf, 16, 5);//xscal_c
  }

  e[0] = ztest0;
  ztest0 = e[1];
  if (!is_zero(b_s[1])) {//(b_s[1] != 0.0F)
    rt = fabsf(b_s[1]);
    nrm = b_s[1] / rt;
    b_s[1] = rt;
    ztest0 = e[1] / nrm;
    xscal(nrm, U, 80, 21);
  }

  if (!is_zero(ztest0)) { //(ztest0 != 0.0F)
    rt = fabsf(ztest0);
    nrm = rt / ztest0;
    ztest0 = rt;
    b_s[2] *= nrm;
    xscal(nrm, Vf, 16, 9);//xscal_c
  }

  e[1] = ztest0;
  ztest0 = b_A[62];
  if (!is_zero(b_s[2])) {//(b_s[2] != 0.0F)
    rt = fabsf(b_s[2]);
    nrm = b_s[2] / rt;
    b_s[2] = rt;
    ztest0 = b_A[62] / nrm;
    xscal(nrm, U, 80, 41);
  }

  if (!is_zero(ztest0)) {// (ztest0 != 0.0F)
    rt = fabsf(ztest0);
    nrm = rt / ztest0;
    ztest0 = rt;
    b_s[3] *= nrm;
    xscal(nrm, Vf, 16, 13);//xscal_c
  }

  e[2] = ztest0;
  if (!is_zero(b_s[3])) {//(b_s[3] != 0.0F)
    rt = fabsf(b_s[3]);
    nrm = b_s[3] / rt;
    b_s[3] = rt;
    xscal(nrm, U, 80 ,61);
  }

  e[3] = 0.0F;
  qq = 0;
  if ((b_s[0] > e[0]) || rtIsNaNF(e[0])) {
    nrm = b_s[0];
  } else {
    nrm = e[0];
  }

  if ((b_s[1] > e[1]) || rtIsNaNF(e[1])) {
    rt = b_s[1];
  } else {
    rt = e[1];
  }

  if ((!(nrm > rt)) && (!rtIsNaNF(rt))) {
    nrm = rt;
  }

  if ((b_s[2] > ztest0) || rtIsNaNF(ztest0)) {
    ztest0 = b_s[2];
  }

  if ((!(nrm > ztest0)) && (!rtIsNaNF(ztest0))) {
    nrm = ztest0;
  }

  if (b_s[3] > 0.0F) {
    rt = b_s[3];
  } else {
    rt = 0.0F;
  }

  if ((!(nrm > rt)) && (!rtIsNaNF(rt))) {
    nrm = rt;
  }

  while ((m + 2 > 0) && (qq < 75)) {
    c_q = m + 1;
    exitg1 = false;
    while (!(exitg1 || (c_q == 0))) {
      ztest0 = fabsf(e[c_q - 1]);
      if (ztest0 <= (fabsf(b_s[c_q - 1]) + fabsf(b_s[c_q])) *
          1.1920929E-7F) {
        e[c_q - 1] = 0.0F;
        exitg1 = true;
      } else if ((ztest0 <= 9.86076132E-32F) || ((qq > 20) && (ztest0 <=
                   1.1920929E-7F * nrm))) {
        e[c_q - 1] = 0.0F;
        exitg1 = true;
      } else {
        c_q--;
      }
    }

    if (m + 1 == c_q) {
      qp1jj = 4;
    } else {
      qjj = m + 2;
      qp1jj = m + 2;
      exitg1 = false;
      while ((!exitg1) && (qp1jj >= c_q)) {
        qjj = qp1jj;
        if (qp1jj == c_q) {
          exitg1 = true;
        } else {
          ztest0 = 0.0F;
          if (qp1jj < m + 2) {
            ztest0 = fabsf(e[qp1jj - 1]);
          }

          if (qp1jj > c_q + 1) {
            ztest0 += fabsf(e[qp1jj - 2]);
          }

          rt = fabsf(b_s[qp1jj - 1]);
          if ((rt <= 1.1920929E-7F * ztest0) || (rt <= 9.86076132E-32F)) {
            b_s[qp1jj - 1] = 0.0F;
            exitg1 = true;
          } else {
            qp1jj--;
          }
        }
      }

      if (qjj == c_q) {
        qp1jj = 3;
      } else if (m + 2 == qjj) {
        qp1jj = 1;
      } else {
        qp1jj = 2;
        c_q = qjj;
      }
    }

    switch (qp1jj) {
     case 1:
      ztest0 = e[m];
      e[m] = 0.0F;
      for (qjj = m; qjj + 1 >= c_q + 1; qjj--) {
        xrotg(&b_s[qjj], &ztest0, &rt, &sqds);
        if (qjj + 1 > c_q + 1) {
          smm1 = e[qjj - 1];
          ztest0 = smm1 * -sqds;
          e[qjj - 1] = smm1 * rt;
        }

        xrot(Vf, (qjj << 2) + 1, ((m + 1) << 2) + 1,
          rt, sqds);
      }
      break;

     case 2:
      ztest0 = e[c_q - 1];
      e[c_q - 1] = 0.0F;
      for (qjj = c_q; qjj < m + 2; qjj++) {
        xrotg(&b_s[qjj], &ztest0, &rt, &sqds);
        ztest0 = -sqds * e[qjj];
        e[qjj] *= rt;
        xrot_f(U, 20 * qjj + 1, 20 * (c_q - 1) + 1, rt,
          sqds);
      }
      break;

     case 3:
      ztest0 = b_s[m + 1];
      rt = fabsf(ztest0);
      sqds = fabsf(b_s[m]);
      if ((rt > sqds) || rtIsNaNF(sqds)) {
        sqds = rt;
      }

      rt = fabsf(e[m]);
      if ((sqds > rt) || rtIsNaNF(rt)) {
        rt = sqds;
      }

      sqds = fabsf(b_s[c_q]);
      if ((rt > sqds) || rtIsNaNF(sqds)) {
        sqds = rt;
      }

      rt = fabsf(e[c_q]);
      if ((sqds > rt) || rtIsNaNF(rt)) {
        rt = sqds;
      }

      ztest0 /= rt;
      smm1 = b_s[m] / rt;
      emm1 = e[m] / rt;
      sqds = b_s[c_q] / rt;
      smm1 = ((smm1 + ztest0) * (smm1 - ztest0) + emm1 * emm1) / 2.0F;
      emm1 *= ztest0;
      emm1 *= emm1;
      if (!is_zero(smm1) || !is_zero(emm1)) {//((smm1 != 0.0F) || (emm1 != 0.0F))
        shift = safe_sqrt(smm1 * smm1 + emm1);
        if (smm1 < 0.0F) {
          shift = -shift;
        }

        shift = emm1 / (smm1 + shift);
      } else {
        shift = 0.0F;
      }

      ztest0 = (sqds + ztest0) * (sqds - ztest0) + shift;
      smm1 = e[c_q] / rt * sqds;
      for (qjj = c_q + 1; qjj <= m + 1; qjj++) {
        xrotg(&ztest0, &smm1, &rt, &sqds);
        if (qjj > c_q + 1) {
          e[qjj - 2] = ztest0;
        }

        smm1 = e[qjj - 1];
        emm1 = b_s[qjj - 1];
        ztest0 = emm1 * rt + smm1 * sqds;
        e[qjj - 1] = smm1 * rt - emm1 * sqds;
        smm1 = sqds * b_s[qjj];
        b_s[qjj] *= rt;
        xrot(Vf, ((qjj - 1) << 2) + 1, (qjj << 2) + 1,
          rt, sqds);
        xrotg(&ztest0, &smm1, &rt, &sqds);
        b_s[qjj - 1] = ztest0;
        ztest0 = e[qjj - 1] * rt + sqds * b_s[qjj];
        b_s[qjj] = e[qjj - 1] * -sqds + rt * b_s[qjj];
        smm1 = sqds * e[qjj];
        e[qjj] *= rt;
        xrot_f(U, 20 * (qjj - 1) + 1, 20 * qjj + 1, rt,
          sqds);
      }

      e[m] = ztest0;
      qq++;
      break;

     default:
      if (b_s[c_q] < 0.0F) {
        b_s[c_q] = -b_s[c_q];
        xscal(-1.0F, Vf, 16, (c_q << 2) + 1);//xscal_c
      }

      qq = c_q + 1;
      while ((c_q + 1 < 4) && (b_s[c_q] < b_s[qq])) {
        rt = b_s[c_q];
        b_s[c_q] = b_s[qq];
        b_s[qq] = rt;
        xswap(Vf, (c_q << 2) + 1, ((c_q + 1) << 2) + 1);
        xswap_m(U, 20 * c_q + 1, 20 * (c_q + 1) + 1);
        c_q = qq;
        qq++;
      }

      qq = 0;
      m--;
      break;
    }
  }

  for (m = 0; m < 4; m++) {
    s[m] = b_s[m];
    c_q = m << 2;
    V[c_q] = Vf[c_q];
    qq = c_q + 1;
    V[qq] = Vf[qq];
    qq = c_q + 2;
    V[qq] = Vf[qq];
    c_q += 3;
    V[c_q] = Vf[c_q];
  }
}
