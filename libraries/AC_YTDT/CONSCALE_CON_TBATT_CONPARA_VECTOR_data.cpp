//
// File: CONSCALE_CON_TBATT_CONPARA_VECTOR_data.cpp
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
#include "CONSCALE_CON_TBATT_CONPARA_VECTOR.h"
#include "CONSCALE_CON_TBATT_CONPARA_VECTOR_private.h"

// Block parameters (default storage)
P_CONSCALE_CON_TBATT_CONPARA__T CONFULL_CON_TBATT_CONPARA_VECTORModelClass::
  CONSCALE_CON_TBATT_CONPARA_VE_P = {
  // Computed Parameter: Constant_Value
  //  Referenced by: '<S10>/Constant'

  { 0.0F, 0.0F, 0.0F },

  // Computed Parameter: Gain_Gain
  //  Referenced by: '<S13>/Gain'

  -1.0F,

  // Computed Parameter: Gain_Gain_d
  //  Referenced by: '<S16>/Gain'

  -1.0F,

  // Computed Parameter: Gain_Gain_i
  //  Referenced by: '<S17>/Gain'

  -1.0F,

  // Computed Parameter: Integrator1_gainval
  //  Referenced by: '<S43>/Integrator1'

  0.02F,

  // Computed Parameter: Integrator1_IC
  //  Referenced by: '<S43>/Integrator1'

  0.0F,

  // Computed Parameter: Gain2_Gain
  //  Referenced by: '<S43>/Gain2'

  0.8F,

  // Computed Parameter: Gain1_Gain
  //  Referenced by: '<S43>/Gain1'

  2.0F,

  // Computed Parameter: Gain3_Gain
  //  Referenced by: '<S43>/Gain3'

  4.0F,

  // Computed Parameter: Gain_Gain_c
  //  Referenced by: '<S43>/Gain'

  0.5F,

  // Computed Parameter: Integrator1_gainval_d
  //  Referenced by: '<S39>/Integrator1'

  0.02F,

  // Computed Parameter: Integrator1_IC_p
  //  Referenced by: '<S39>/Integrator1'

  0.0F,

  // Computed Parameter: Gain1_Gain_h
  //  Referenced by: '<S39>/Gain1'

  2.0F,

  // Computed Parameter: Gain_Gain_cl
  //  Referenced by: '<S39>/Gain'

  0.5F,

  // Computed Parameter: Gain3_Gain_i
  //  Referenced by: '<Root>/Gain3'

  -1.0F,

  // Expression: CONTBATT.STICK.LAT
  //  Referenced by: '<Root>/Gain'

  30.0F,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S39>/Integrator'

  0.02F,

  // Computed Parameter: Integrator_IC
  //  Referenced by: '<S39>/Integrator'

  0.0F,

  // Expression: CONTBATT.ROLL.ATT.REF.DOTMAX
  //  Referenced by: '<S39>/Saturation'

  90.0F,

  // Expression: CONTBATT.ROLL.ATT.REF.DOTMIN
  //  Referenced by: '<S39>/Saturation'

  -90.0F,

  // Expression: CONTBATT.ROLL.ATT.REF.DDOTMAX
  //  Referenced by: '<S39>/Saturation1'

  360.0F,

  // Expression: CONTBATT.ROLL.ATT.REF.DDOTMIN
  //  Referenced by: '<S39>/Saturation1'

  -360.0F,

  // Computed Parameter: Gain_Gain_c0
  //  Referenced by: '<S37>/Gain'

  57.2957802F,

  // Computed Parameter: Integrator_gainval_e
  //  Referenced by: '<S43>/Integrator'

  0.02F,

  // Computed Parameter: Integrator_IC_d
  //  Referenced by: '<S43>/Integrator'

  0.0F,

  // Expression: CONTBATT.ROLL.ATT.REF.DOTMAX
  //  Referenced by: '<S43>/Saturation'

  90.0F,

  // Expression: CONTBATT.ROLL.ATT.REF.DOTMIN
  //  Referenced by: '<S43>/Saturation'

  -90.0F,

  // Expression: CONTBATT.ROLL.ATT.REF.DDOTMAX
  //  Referenced by: '<S43>/Saturation1'

  360.0F,

  // Expression: CONTBATT.ROLL.ATT.REF.DDOTMIN
  //  Referenced by: '<S43>/Saturation1'

  -360.0F,

  // Computed Parameter: Gain_Gain_a
  //  Referenced by: '<S44>/Gain'

  57.2957802F,

  // Computed Parameter: DiscreteZeroPole_A
  //  Referenced by: '<S45>/Discrete Zero-Pole'

  { 1.5F, -0.724355817F, 0.724355817F },

  // Computed Parameter: DiscreteZeroPole_B
  //  Referenced by: '<S45>/Discrete Zero-Pole'

  1.0F,

  // Computed Parameter: DiscreteZeroPole_D
  //  Referenced by: '<S45>/Discrete Zero-Pole'

  1.0F,

  // Computed Parameter: Gain1_Gain_k
  //  Referenced by: '<S40>/Gain1'

  0.0174532924F,

  // Computed Parameter: Integrator1_gainval_c
  //  Referenced by: '<S32>/Integrator1'

  0.02F,

  // Computed Parameter: Integrator1_IC_k
  //  Referenced by: '<S32>/Integrator1'

  0.0F,

  // Computed Parameter: Gain2_Gain_p
  //  Referenced by: '<S32>/Gain2'

  1.0F,

  // Computed Parameter: Gain1_Gain_d
  //  Referenced by: '<S32>/Gain1'

  2.0F,

  // Computed Parameter: Gain3_Gain_i5
  //  Referenced by: '<S32>/Gain3'

  5.0F,

  // Computed Parameter: Gain_Gain_h
  //  Referenced by: '<S32>/Gain'

  0.5F,

  // Computed Parameter: Integrator1_gainval_l
  //  Referenced by: '<S28>/Integrator1'

  0.02F,

  // Computed Parameter: Integrator1_IC_d
  //  Referenced by: '<S28>/Integrator1'

  0.0F,

  // Computed Parameter: Gain1_Gain_p
  //  Referenced by: '<S28>/Gain1'

  2.0F,

  // Computed Parameter: Gain_Gain_l
  //  Referenced by: '<S28>/Gain'

  0.5F,

  // Expression: CONTBATT.STICK.LON
  //  Referenced by: '<Root>/Gain2'

  30.0F,

  // Computed Parameter: Integrator_gainval_n
  //  Referenced by: '<S28>/Integrator'

  0.02F,

  // Computed Parameter: Integrator_IC_p
  //  Referenced by: '<S28>/Integrator'

  0.0F,

  // Expression: CONTBATT.PITCH.ATT.REF.DOTMAX
  //  Referenced by: '<S28>/Saturation'

  90.0F,

  // Expression: CONTBATT.PITCH.ATT.REF.DOTMIN
  //  Referenced by: '<S28>/Saturation'

  -90.0F,

  // Expression: CONTBATT.PITCH.ATT.REF.DDOTMAX
  //  Referenced by: '<S28>/Saturation1'

  360.0F,

  // Expression: CONTBATT.PITCH.ATT.REF.DDOTMIN
  //  Referenced by: '<S28>/Saturation1'

  -360.0F,

  // Computed Parameter: Gain_Gain_n
  //  Referenced by: '<S26>/Gain'

  57.2957802F,

  // Computed Parameter: Integrator_gainval_nw
  //  Referenced by: '<S32>/Integrator'

  0.02F,

  // Computed Parameter: Integrator_IC_n
  //  Referenced by: '<S32>/Integrator'

  0.0F,

  // Expression: CONTBATT.PITCH.ATT.REF.DOTMAX
  //  Referenced by: '<S32>/Saturation'

  90.0F,

  // Expression: CONTBATT.PITCH.ATT.REF.DOTMIN
  //  Referenced by: '<S32>/Saturation'

  -90.0F,

  // Expression: CONTBATT.PITCH.ATT.REF.DDOTMAX
  //  Referenced by: '<S32>/Saturation1'

  360.0F,

  // Expression: CONTBATT.PITCH.ATT.REF.DDOTMIN
  //  Referenced by: '<S32>/Saturation1'

  -360.0F,

  // Computed Parameter: Gain_Gain_ct
  //  Referenced by: '<S33>/Gain'

  57.2957802F,

  // Computed Parameter: DiscreteZeroPole_A_e
  //  Referenced by: '<S34>/Discrete Zero-Pole'

  { 1.573861F, -0.769589961F, 0.769589961F },

  // Computed Parameter: DiscreteZeroPole_B_n
  //  Referenced by: '<S34>/Discrete Zero-Pole'

  1.0F,

  // Computed Parameter: DiscreteZeroPole_C_d
  //  Referenced by: '<S34>/Discrete Zero-Pole'

  { -0.150394306F, 0.180721894F },

  // Computed Parameter: DiscreteZeroPole_D_g
  //  Referenced by: '<S34>/Discrete Zero-Pole'

  0.908571F,

  // Computed Parameter: Gain1_Gain_b
  //  Referenced by: '<S29>/Gain1'

  0.0174532924F,

  // Computed Parameter: Integrator1_gainval_a
  //  Referenced by: '<S49>/Integrator1'

  0.02F,

  // Computed Parameter: Integrator1_IC_pz
  //  Referenced by: '<S49>/Integrator1'

  0.0F,

  // Computed Parameter: Gain2_Gain_g
  //  Referenced by: '<S49>/Gain2'

  1.0F,

  // Computed Parameter: Gain1_Gain_g
  //  Referenced by: '<S49>/Gain1'

  2.0F,

  // Computed Parameter: Gain3_Gain_o
  //  Referenced by: '<S49>/Gain3'

  1.0F,

  // Computed Parameter: Gain_Gain_i2
  //  Referenced by: '<S49>/Gain'

  0.5F,

  // Expression: CONTBATT.STICK.YAW
  //  Referenced by: '<Root>/Gain4'

  15.0F,

  // Computed Parameter: Integrator_gainval_d
  //  Referenced by: '<S49>/Integrator'

  0.02F,

  // Computed Parameter: Integrator_IC_c
  //  Referenced by: '<S49>/Integrator'

  0.0F,

  // Expression: CONTBATT.YAW.ACC.REF.DOTMAX
  //  Referenced by: '<S49>/Saturation'

  90.0F,

  // Expression: CONTBATT.YAW.ACC.REF.DOTMIN
  //  Referenced by: '<S49>/Saturation'

  -90.0F,

  // Expression: CONTBATT.YAW.ACC.REF.DDOTMAX
  //  Referenced by: '<S49>/Saturation1'

  360.0F,

  // Expression: CONTBATT.YAW.ACC.REF.DDOTMIN
  //  Referenced by: '<S49>/Saturation1'

  -360.0F,

  // Computed Parameter: Gain_Gain_lj
  //  Referenced by: '<S50>/Gain'

  57.2957802F,

  // Computed Parameter: DiscreteZeroPole_A_b
  //  Referenced by: '<S51>/Discrete Zero-Pole'

  { 1.310606F, -0.600925207F, 0.600925207F },

  // Computed Parameter: DiscreteZeroPole_B_f
  //  Referenced by: '<S51>/Discrete Zero-Pole'

  1.0F,

  // Computed Parameter: DiscreteZeroPole_C_i
  //  Referenced by: '<S51>/Discrete Zero-Pole'

  { -0.259605944F, 0.384780228F },

  // Computed Parameter: DiscreteZeroPole_D_e
  //  Referenced by: '<S51>/Discrete Zero-Pole'

  0.816286683F,

  // Computed Parameter: Gain1_Gain_a
  //  Referenced by: '<S46>/Gain1'

  0.0174532924F,

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S11>/Constant'

  { 1.0F, 0.0F, 0.0F },

  // Computed Parameter: Constant1_Value
  //  Referenced by: '<S11>/Constant1'

  0.0F,

  // Computed Parameter: Gain_Gain_dm
  //  Referenced by: '<S11>/Gain'

  -1.0F,

  // Computed Parameter: Gain1_Gain_j
  //  Referenced by: '<S11>/Gain1'

  -1.0F,

  // Computed Parameter: Gain_Gain_a3
  //  Referenced by: '<S2>/Gain'

  57.2957802F,

  // Computed Parameter: Gain_Gain_p
  //  Referenced by: '<S3>/Gain'

  57.2957802F,

  // Computed Parameter: Gain_Gain_g
  //  Referenced by: '<S4>/Gain'

  57.2957802F,

  // Computed Parameter: Gain1_Gain_m
  //  Referenced by: '<Root>/Gain1'

  2.0F,

  // Computed Parameter: Gain1_Gain_o
  //  Referenced by: '<S54>/Gain1'

  2.0F,

  // Computed Parameter: Gain_Gain_f
  //  Referenced by: '<S54>/Gain'

  0.5F,

  // Computed Parameter: RateLimiter_RisingLim
  //  Referenced by: '<Root>/Rate Limiter'

  0.1F,

  // Computed Parameter: RateLimiter_FallingLim
  //  Referenced by: '<Root>/Rate Limiter'

  -0.02F,

  // Computed Parameter: RateLimiter_IC
  //  Referenced by: '<Root>/Rate Limiter'

  0.0F,

  // Expression: CONTBATT.STICK.THR
  //  Referenced by: '<Root>/Gain6'

  5.0F,

  // Computed Parameter: Integrator_gainval_a
  //  Referenced by: '<S54>/Integrator'

  0.02F,

  // Computed Parameter: Integrator_IC_j
  //  Referenced by: '<S54>/Integrator'

  0.0F,

  // Expression: CONTBATT.HDOT.REF.DOTMAX
  //  Referenced by: '<S54>/Saturation'

  10.0F,

  // Expression: CONTBATT.HDOT.REF.DOTMIN
  //  Referenced by: '<S54>/Saturation'

  -10.0F,

  // Computed Parameter: Integrator1_gainval_b
  //  Referenced by: '<S54>/Integrator1'

  0.02F,

  // Computed Parameter: Integrator1_IC_g
  //  Referenced by: '<S54>/Integrator1'

  0.0F,

  // Expression: CONTBATT.HDOT.REF.DDOTMAX
  //  Referenced by: '<S54>/Saturation1'

  10.0F,

  // Expression: CONTBATT.HDOT.REF.DDOTMIN
  //  Referenced by: '<S54>/Saturation1'

  -10.0F,

  // Computed Parameter: DiscreteZeroPole_A_p
  //  Referenced by: '<S55>/Discrete Zero-Pole'

  { 1.74089634F, -0.864001513F, 0.864001513F },

  // Computed Parameter: DiscreteZeroPole_B_k
  //  Referenced by: '<S55>/Discrete Zero-Pole'

  1.0F,

  // Computed Parameter: DiscreteZeroPole_C_ig
  //  Referenced by: '<S55>/Discrete Zero-Pole'

  { 0.441271126F, -0.484460592F },

  // Computed Parameter: DiscreteZeroPole_D_i
  //  Referenced by: '<S55>/Discrete Zero-Pole'

  1.24655819F,

  // Computed Parameter: Gain1_Gain_oj
  //  Referenced by: '<S7>/Gain1'

  -1.0F
};

//
// File trailer for generated code.
//
// [EOF]
//
