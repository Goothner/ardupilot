//
// File: CONSCALE_CON_TBATT_CONPARA_VECTOR_types.h
//
// Code generated for Simulink model 'CONSCALE_CON_TBATT_CONPARA_VECTOR'.
//
// Model version                  : 1.687
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Thu Oct 23 14:30:22 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_CONSCALE_CON_TBATT_CONPARA_VECTOR_types_h_
#define RTW_HEADER_CONSCALE_CON_TBATT_CONPARA_VECTOR_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_CMD_ATT_
#define DEFINED_TYPEDEF_FOR_CMD_ATT_

typedef struct {
  real32_T ROLL_ATT_CMD_DEG;
  real32_T PITCH_ATT_CMD_DEG;
  real32_T YAW_RATE_CMD_DEGPS;
  real32_T HDOT_CMD_MPS;
} CMD_ATT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_STATES_ROT_
#define DEFINED_TYPEDEF_FOR_STATES_ROT_

typedef struct {
  real32_T P_RADPS;
  real32_T Q_RADPS;
  real32_T R_RADPS;
} STATES_ROT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_STATES_ATT_
#define DEFINED_TYPEDEF_FOR_STATES_ATT_

typedef struct {
  real32_T PHI_RAD;
  real32_T THETA_RAD;
  real32_T PSI_RAD;
} STATES_ATT;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Y6SJe1l9Y285ZFG9DLtEH_
#define DEFINED_TYPEDEF_FOR_struct_Y6SJe1l9Y285ZFG9DLtEH_

typedef struct {
  real_T W_TRIM_RPM[20];
  real_T DF_DEG[20];
} struct_Y6SJe1l9Y285ZFG9DLtEH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_einuNJoLREoCNUfBV8iuFH_
#define DEFINED_TYPEDEF_FOR_struct_einuNJoLREoCNUfBV8iuFH_

typedef struct {
  real_T LON;
  real_T LAT;
  real_T YAW;
  real_T THR;
} struct_einuNJoLREoCNUfBV8iuFH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_0wkhvCIvUmDd0W0JNp358C_
#define DEFINED_TYPEDEF_FOR_struct_0wkhvCIvUmDd0W0JNp358C_

typedef struct {
  real_T KP;
  real_T KI;
} struct_0wkhvCIvUmDd0W0JNp358C;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_nR8tVaqGVwznTtVWsHIkqH_
#define DEFINED_TYPEDEF_FOR_struct_nR8tVaqGVwznTtVWsHIkqH_

typedef struct {
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
} struct_nR8tVaqGVwznTtVWsHIkqH;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_c0F0qh63r8b9g7BdK7slC_
#define DEFINED_TYPEDEF_FOR_struct_c0F0qh63r8b9g7BdK7slC_

typedef struct {
  struct_0wkhvCIvUmDd0W0JNp358C ERRCON;
  struct_nR8tVaqGVwznTtVWsHIkqH REF;
} struct_c0F0qh63r8b9g7BdK7slC;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_vdaI5JLKoTJFgq9rUcD07D_
#define DEFINED_TYPEDEF_FOR_struct_vdaI5JLKoTJFgq9rUcD07D_

typedef struct {
  real_T T1_NUM;
  real_T T2_NUM;
  real_T T1_DEN;
  real_T T2_DEN;
} struct_vdaI5JLKoTJFgq9rUcD07D;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_gaAuGXlVxCnZOIcYuRcCi_
#define DEFINED_TYPEDEF_FOR_struct_gaAuGXlVxCnZOIcYuRcCi_

typedef struct {
  struct_0wkhvCIvUmDd0W0JNp358C ERRCON;
  struct_vdaI5JLKoTJFgq9rUcD07D LEADLAG;
  struct_nR8tVaqGVwznTtVWsHIkqH REF;
} struct_gaAuGXlVxCnZOIcYuRcCi;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_tPGwc284GQBW9WRmUpSPUD_
#define DEFINED_TYPEDEF_FOR_struct_tPGwc284GQBW9WRmUpSPUD_

typedef struct {
  struct_c0F0qh63r8b9g7BdK7slC ATT;
  struct_gaAuGXlVxCnZOIcYuRcCi RATE;
  struct_c0F0qh63r8b9g7BdK7slC ACC;
} struct_tPGwc284GQBW9WRmUpSPUD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_i273HMPJ3ar65CAUrHiR3G_
#define DEFINED_TYPEDEF_FOR_struct_i273HMPJ3ar65CAUrHiR3G_

typedef struct {
  struct_gaAuGXlVxCnZOIcYuRcCi RATE;
  struct_c0F0qh63r8b9g7BdK7slC ACC;
} struct_i273HMPJ3ar65CAUrHiR3G;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_fnVfaQNUPImLlAYZLZQPt_
#define DEFINED_TYPEDEF_FOR_struct_fnVfaQNUPImLlAYZLZQPt_

typedef struct {
  real_T KP;
} struct_fnVfaQNUPImLlAYZLZQPt;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_Pa5dCEh4OUAgFIwnPOkwFE_
#define DEFINED_TYPEDEF_FOR_struct_Pa5dCEh4OUAgFIwnPOkwFE_

typedef struct {
  struct_fnVfaQNUPImLlAYZLZQPt ERRCON;
  struct_vdaI5JLKoTJFgq9rUcD07D LEADLAG;
  struct_nR8tVaqGVwznTtVWsHIkqH REF;
} struct_Pa5dCEh4OUAgFIwnPOkwFE;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_BXysS30lSwOi4L1jeGgsOD_
#define DEFINED_TYPEDEF_FOR_struct_BXysS30lSwOi4L1jeGgsOD_

typedef struct {
  struct_Y6SJe1l9Y285ZFG9DLtEH CA;
  struct_einuNJoLREoCNUfBV8iuFH STICK;
  struct_tPGwc284GQBW9WRmUpSPUD ROLL;
  struct_tPGwc284GQBW9WRmUpSPUD PITCH;
  struct_i273HMPJ3ar65CAUrHiR3G YAW;
  struct_Pa5dCEh4OUAgFIwnPOkwFE HDOT;
} struct_BXysS30lSwOi4L1jeGgsOD;

#endif

// Parameters (default storage)
typedef struct P_CONSCALE_CON_TBATT_CONPARA__T_ P_CONSCALE_CON_TBATT_CONPARA__T;

// Forward declaration for rtModel
typedef struct tag_RTM_CONSCALE_CON_TBATT_CO_T RT_MODEL_CONSCALE_CON_TBATT_C_T;

#endif                 // RTW_HEADER_CONSCALE_CON_TBATT_CONPARA_VECTOR_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
