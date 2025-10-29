//
// File: CONSCALE_CON_TBATT_CONPARA_VECTOR_types.h
//
// Code generated for Simulink model 'CONSCALE_CON_TBATT_CONPARA_VECTOR'.
//
// Model version                  : 1.679
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sun Sep 14 15:28:53 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_CONSCALE_CON_TBATT_CONPARA_VECTOR_types_h_
#define RTW_HEADER_CONSCALE_CON_TBATT_CONPARA_VECTOR_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_STATES_ROT_
#define DEFINED_TYPEDEF_FOR_STATES_ROT_

struct STATES_ROT
{
  real_T P_RADPS;
  real_T Q_RADPS;
  real_T R_RADPS;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_STATES_ATT_
#define DEFINED_TYPEDEF_FOR_STATES_ATT_

struct STATES_ATT
{
  real_T PHI_RAD;
  real_T THETA_RAD;
  real_T PSI_RAD;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Y6SJe1l9Y285ZFG9DLtEH_
#define DEFINED_TYPEDEF_FOR_struct_Y6SJe1l9Y285ZFG9DLtEH_

struct struct_Y6SJe1l9Y285ZFG9DLtEH
{
  real_T W_TRIM_RPM[20];
  real_T DF_DEG[20];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_einuNJoLREoCNUfBV8iuFH_
#define DEFINED_TYPEDEF_FOR_struct_einuNJoLREoCNUfBV8iuFH_

struct struct_einuNJoLREoCNUfBV8iuFH
{
  real_T LON;
  real_T LAT;
  real_T YAW;
  real_T THR;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_0wkhvCIvUmDd0W0JNp358C_
#define DEFINED_TYPEDEF_FOR_struct_0wkhvCIvUmDd0W0JNp358C_

struct struct_0wkhvCIvUmDd0W0JNp358C
{
  real_T KP;
  real_T KI;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_nR8tVaqGVwznTtVWsHIkqH_
#define DEFINED_TYPEDEF_FOR_struct_nR8tVaqGVwznTtVWsHIkqH_

struct struct_nR8tVaqGVwznTtVWsHIkqH
{
  real_T ZETA;
  real_T W0_RADPS;
  real_T K1;
  real_T K2;
  real_T K3;
  real_T KFF;
  real_T DOTMAX;
  real_T DOTMIN;
  real_T DDOTMAX;
  real_T DDOTMIN;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_c0F0qh63r8b9g7BdK7slC_
#define DEFINED_TYPEDEF_FOR_struct_c0F0qh63r8b9g7BdK7slC_

struct struct_c0F0qh63r8b9g7BdK7slC
{
  struct_0wkhvCIvUmDd0W0JNp358C ERRCON;
  struct_nR8tVaqGVwznTtVWsHIkqH REF;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_vdaI5JLKoTJFgq9rUcD07D_
#define DEFINED_TYPEDEF_FOR_struct_vdaI5JLKoTJFgq9rUcD07D_

struct struct_vdaI5JLKoTJFgq9rUcD07D
{
  real_T T1_NUM;
  real_T T2_NUM;
  real_T T1_DEN;
  real_T T2_DEN;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_gaAuGXlVxCnZOIcYuRcCi_
#define DEFINED_TYPEDEF_FOR_struct_gaAuGXlVxCnZOIcYuRcCi_

struct struct_gaAuGXlVxCnZOIcYuRcCi
{
  struct_0wkhvCIvUmDd0W0JNp358C ERRCON;
  struct_vdaI5JLKoTJFgq9rUcD07D LEADLAG;
  struct_nR8tVaqGVwznTtVWsHIkqH REF;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_tPGwc284GQBW9WRmUpSPUD_
#define DEFINED_TYPEDEF_FOR_struct_tPGwc284GQBW9WRmUpSPUD_

struct struct_tPGwc284GQBW9WRmUpSPUD
{
  struct_c0F0qh63r8b9g7BdK7slC ATT;
  struct_gaAuGXlVxCnZOIcYuRcCi RATE;
  struct_c0F0qh63r8b9g7BdK7slC ACC;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_i273HMPJ3ar65CAUrHiR3G_
#define DEFINED_TYPEDEF_FOR_struct_i273HMPJ3ar65CAUrHiR3G_

struct struct_i273HMPJ3ar65CAUrHiR3G
{
  struct_gaAuGXlVxCnZOIcYuRcCi RATE;
  struct_c0F0qh63r8b9g7BdK7slC ACC;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_fnVfaQNUPImLlAYZLZQPt_
#define DEFINED_TYPEDEF_FOR_struct_fnVfaQNUPImLlAYZLZQPt_

struct struct_fnVfaQNUPImLlAYZLZQPt
{
  real_T KP;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Pa5dCEh4OUAgFIwnPOkwFE_
#define DEFINED_TYPEDEF_FOR_struct_Pa5dCEh4OUAgFIwnPOkwFE_

struct struct_Pa5dCEh4OUAgFIwnPOkwFE
{
  struct_fnVfaQNUPImLlAYZLZQPt ERRCON;
  struct_vdaI5JLKoTJFgq9rUcD07D LEADLAG;
  struct_nR8tVaqGVwznTtVWsHIkqH REF;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_BXysS30lSwOi4L1jeGgsOD_
#define DEFINED_TYPEDEF_FOR_struct_BXysS30lSwOi4L1jeGgsOD_

struct struct_BXysS30lSwOi4L1jeGgsOD
{
  struct_Y6SJe1l9Y285ZFG9DLtEH CA;
  struct_einuNJoLREoCNUfBV8iuFH STICK;
  struct_tPGwc284GQBW9WRmUpSPUD ROLL;
  struct_tPGwc284GQBW9WRmUpSPUD PITCH;
  struct_i273HMPJ3ar65CAUrHiR3G YAW;
  struct_Pa5dCEh4OUAgFIwnPOkwFE HDOT;
};

#endif
#endif                 // RTW_HEADER_CONSCALE_CON_TBATT_CONPARA_VECTOR_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
