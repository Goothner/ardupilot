//
// File: CONSCALE_CON_TBATT_CONPARA_VECTOR.h
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
#ifndef RTW_HEADER_CONSCALE_CON_TBATT_CONPARA_VECTOR_h_
#define RTW_HEADER_CONSCALE_CON_TBATT_CONPARA_VECTOR_h_
#include <cstring>
#include <cmath>
#ifndef CONSCALE_CON_TBATT_CONPARA_VECTOR_COMMON_INCLUDES_
# define CONSCALE_CON_TBATT_CONPARA_VECTOR_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                    // CONSCALE_CON_TBATT_CONPARA_VECTOR_COMMON_INCLUDES_

#include "CONSCALE_CON_TBATT_CONPARA_VECTOR_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block states (default storage) for system '<Root>'
typedef struct {
  real32_T Integrator1_DSTATE;         // '<S43>/Integrator1'
  real32_T Integrator1_DSTATE_n;       // '<S39>/Integrator1'
  real32_T Integrator_DSTATE;          // '<S39>/Integrator'
  real32_T Integrator_DSTATE_f;        // '<S43>/Integrator'
  real32_T DiscreteZeroPole_DSTATE[2]; // '<S45>/Discrete Zero-Pole'
  real32_T Integrator1_DSTATE_e;       // '<S32>/Integrator1'
  real32_T Integrator1_DSTATE_a;       // '<S28>/Integrator1'
  real32_T Integrator_DSTATE_o;        // '<S28>/Integrator'
  real32_T Integrator_DSTATE_d;        // '<S32>/Integrator'
  real32_T DiscreteZeroPole_DSTATE_l[2];// '<S34>/Discrete Zero-Pole'
  real32_T Integrator1_DSTATE_g;       // '<S49>/Integrator1'
  real32_T Integrator_DSTATE_g;        // '<S49>/Integrator'
  real32_T DiscreteZeroPole_DSTATE_g[2];// '<S51>/Discrete Zero-Pole'
  real32_T Integrator_DSTATE_d0;       // '<S54>/Integrator'
  real32_T Integrator1_DSTATE_p;       // '<S54>/Integrator1'
  real32_T DiscreteZeroPole_DSTATE_o[2];// '<S55>/Discrete Zero-Pole'
  real32_T PrevY;                      // '<Root>/Rate Limiter'
} DW_CONSCALE_CON_TBATT_CONPARA_T;

// External inputs (root inport signals with default storage)
typedef struct {
  real32_T DF_FRR_DEG;                 // '<Root>/DF_FRR_DEG'
  real32_T P_RADPS;                    // '<Root>/P_RADPS'
  real32_T Q_RADPS;                    // '<Root>/Q_RADPS'
  real32_T R_RADPS;                    // '<Root>/R_RADPS'
  real32_T PHI_RAD;                    // '<Root>/PHI_RAD'
  real32_T THETA_RAD;                  // '<Root>/THETA_RAD'
  real32_T PSI_RAD;                    // '<Root>/PSI_RAD'
  real32_T H_DOT_MPS;                  // '<Root>/H_DOT_MPS'
  real32_T VER_VEL_ERR_Kp;             // '<Root>/VER_VEL_ERR_Kp '
  real32_T VER_VEL_REF_KFF;            // '<Root>/VER_VEL_REF_KFF'
  real32_T VER_VEL_REF_ZETA;           // '<Root>/VER_VEL_REF_ZETA'
  real32_T VER_VEL_REF_W0_RADPS;       // '<Root>/VER_VEL_REF_W0_RADPS'
  real32_T VER_VEL_REF_K3;             // '<Root>/VER_VEL_REF_K3'
  real32_T ROLL_ANGLE_ERR_Kp;          // '<Root>/ROLL_ANGLE_ERR_Kp 1'
  real32_T ROLL_ANGLE_REF_KFF;         // '<Root>/ROLL_ANGLE_REF_KFF'
  real32_T ROLL_ANGLE_REF_ZETA;        // '<Root>/ROLL_ANGLE_REF_ZETA'
  real32_T ROLL_ANGLE_REF_W0_RADPS;    // '<Root>/ROLL_ANGLE_REF_W0_RADPS'
  real32_T ROLL_ANGLE_REF_K3;          // '<Root>/ROLL_ANGLE_REF_K3'
  real32_T ROLL_ANGULAR_RATE_ERR_Kp;   // '<Root>/ROLL_ANGULAR_RATE_ERR_Kp '
  real32_T ROLL_ANGULAR_RATE_REF_KFF;  // '<Root>/ROLL_ANGUALR_RATE_REF_KFF'
  real32_T ROLL_ANGULAR_RATE_REF_K3;   // '<Root>/ROLL_ANGULAR_RATE_REF_K3'
  real32_T PITCH_ANGLE_ERR_Kp;         // '<Root>/PITCH_ANGLE_ERR_Kp 2'
  real32_T PITCH_ANGLE_REF_KFF;        // '<Root>/PITCH_ANGLE_REF_KFF'
  real32_T PITCH_ANGLE_REF_ZETA;       // '<Root>/PITCH_ANGLE_REF_ZETA'
  real32_T PITCH_ANGLE_REF_W0_RADPS;   // '<Root>/PITCH_ANGLE_REF_W0_RADPS'
  real32_T PITCH_ANGLE_REF_K3;         // '<Root>/PITCH_ANGLE_REF_K3'
  real32_T PITCH_ANGULAR_RATE_ERR_Kp;  // '<Root>/PITCH_ANGULAR_RATE_ERR_Kp '
  real32_T PITCH_ANGULAR_RATE_REF_KFF; // '<Root>/PITCH_ANGULAR_RATE_REF_KFF'
  real32_T PITCH_ANGULAR_RATE_REF_K3;  // '<Root>/PITCH_ANGULAR_RATE_REF_K3'
  real32_T YAW_ANGULAR_RATE_ERR_Kp;    // '<Root>/YAW_ANGULAR_RATE_ERR_Kp 2'
  real32_T YAW_ANGULAR_RATE_REF_KFF;   // '<Root>/YAW_ANGULAR_RATE_REF_KFF'
  real32_T YAW_ANGULAR_RATE_REF_ZETA;  // '<Root>/YAW_ANGULAR_RATE_REF_ZETA'
  real32_T YAW_ANGULAR_RATE_REF_W0_RADPS;
                                      // '<Root>/YAW_ANGULAR_RATE_REF_W0_RADPS'
  real32_T YAW_ANGULAR_RATE_REF_K3;    // '<Root>/YAW_ANGULAR_RATE_REF_K3'
  real32_T STICKPWMLAT;                // '<Root>/STICK.PWM.LAT'
  real32_T STICKPWMLON;                // '<Root>/STICK.PWM.LON'
  real32_T STICKPWMYAW;                // '<Root>/STICK.PWM.YAW'
  real32_T STICKPWMTHR;                // '<Root>/STICK.PWM.THR'
} ExtU_CONSCALE_CON_TBATT_CONPA_T;

// External outputs (root outports fed by signals with default storage)
typedef struct {
  real32_T DF_FRR_DEGLIN;              // '<Root>/DF_FRR_DEGLIN'
  real32_T ZDDOT_CMD_MPS2;             // '<Root>/ZDDOT_CMD_MPS2'
  real32_T P_DOT_CMD_DEGPS2;           // '<Root>/P_DOT_CMD_DEGPS2'
  real32_T Q_DOT_CMD_DEGPS2;           // '<Root>/Q_DOT_CMD_DEGPS2'
  real32_T R_DOT_CMD_DEGPS2;           // '<Root>/R_DOT_CMD_DEGPS2'
} ExtY_CONSCALE_CON_TBATT_CONPA_T;

// Parameters (default storage)
struct P_CONSCALE_CON_TBATT_CONPARA__T_ {
  real32_T Constant_Value[3];          // Computed Parameter: Constant_Value
                                          //  Referenced by: '<S10>/Constant'

  real32_T Gain_Gain;                  // Computed Parameter: Gain_Gain
                                          //  Referenced by: '<S13>/Gain'

  real32_T Gain_Gain_d;                // Computed Parameter: Gain_Gain_d
                                          //  Referenced by: '<S16>/Gain'

  real32_T Gain_Gain_i;                // Computed Parameter: Gain_Gain_i
                                          //  Referenced by: '<S17>/Gain'

  real32_T Integrator1_gainval;       // Computed Parameter: Integrator1_gainval
                                         //  Referenced by: '<S43>/Integrator1'

  real32_T Integrator1_IC;             // Computed Parameter: Integrator1_IC
                                          //  Referenced by: '<S43>/Integrator1'

  real32_T Gain2_Gain;                 // Computed Parameter: Gain2_Gain
                                          //  Referenced by: '<S43>/Gain2'

  real32_T Gain1_Gain;                 // Computed Parameter: Gain1_Gain
                                          //  Referenced by: '<S43>/Gain1'

  real32_T Gain3_Gain;                 // Computed Parameter: Gain3_Gain
                                          //  Referenced by: '<S43>/Gain3'

  real32_T Gain_Gain_c;                // Computed Parameter: Gain_Gain_c
                                          //  Referenced by: '<S43>/Gain'

  real32_T Integrator1_gainval_d;   // Computed Parameter: Integrator1_gainval_d
                                       //  Referenced by: '<S39>/Integrator1'

  real32_T Integrator1_IC_p;           // Computed Parameter: Integrator1_IC_p
                                          //  Referenced by: '<S39>/Integrator1'

  real32_T Gain1_Gain_h;               // Computed Parameter: Gain1_Gain_h
                                          //  Referenced by: '<S39>/Gain1'

  real32_T Gain_Gain_cl;               // Computed Parameter: Gain_Gain_cl
                                          //  Referenced by: '<S39>/Gain'

  real32_T Gain3_Gain_i;               // Computed Parameter: Gain3_Gain_i
                                          //  Referenced by: '<Root>/Gain3'

  real32_T Gain_Gain_m;                // Expression: CONTBATT.STICK.LAT
                                          //  Referenced by: '<Root>/Gain'

  real32_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S39>/Integrator'

  real32_T Integrator_IC;              // Computed Parameter: Integrator_IC
                                          //  Referenced by: '<S39>/Integrator'

  real32_T Saturation_UpperSat;      // Expression: CONTBATT.ROLL.ATT.REF.DOTMAX
                                        //  Referenced by: '<S39>/Saturation'

  real32_T Saturation_LowerSat;      // Expression: CONTBATT.ROLL.ATT.REF.DOTMIN
                                        //  Referenced by: '<S39>/Saturation'

  real32_T Saturation1_UpperSat;    // Expression: CONTBATT.ROLL.ATT.REF.DDOTMAX
                                       //  Referenced by: '<S39>/Saturation1'

  real32_T Saturation1_LowerSat;    // Expression: CONTBATT.ROLL.ATT.REF.DDOTMIN
                                       //  Referenced by: '<S39>/Saturation1'

  real32_T Gain_Gain_c0;               // Computed Parameter: Gain_Gain_c0
                                          //  Referenced by: '<S37>/Gain'

  real32_T Integrator_gainval_e;     // Computed Parameter: Integrator_gainval_e
                                        //  Referenced by: '<S43>/Integrator'

  real32_T Integrator_IC_d;            // Computed Parameter: Integrator_IC_d
                                          //  Referenced by: '<S43>/Integrator'

  real32_T Saturation_UpperSat_c;    // Expression: CONTBATT.ROLL.ATT.REF.DOTMAX
                                        //  Referenced by: '<S43>/Saturation'

  real32_T Saturation_LowerSat_d;    // Expression: CONTBATT.ROLL.ATT.REF.DOTMIN
                                        //  Referenced by: '<S43>/Saturation'

  real32_T Saturation1_UpperSat_m;  // Expression: CONTBATT.ROLL.ATT.REF.DDOTMAX
                                       //  Referenced by: '<S43>/Saturation1'

  real32_T Saturation1_LowerSat_m;  // Expression: CONTBATT.ROLL.ATT.REF.DDOTMIN
                                       //  Referenced by: '<S43>/Saturation1'

  real32_T Gain_Gain_a;                // Computed Parameter: Gain_Gain_a
                                          //  Referenced by: '<S44>/Gain'

  real32_T DiscreteZeroPole_A[3];      // Computed Parameter: DiscreteZeroPole_A
                                          //  Referenced by: '<S45>/Discrete Zero-Pole'

  real32_T DiscreteZeroPole_B;         // Computed Parameter: DiscreteZeroPole_B
                                          //  Referenced by: '<S45>/Discrete Zero-Pole'

  real32_T DiscreteZeroPole_D;         // Computed Parameter: DiscreteZeroPole_D
                                          //  Referenced by: '<S45>/Discrete Zero-Pole'

  real32_T Gain1_Gain_k;               // Computed Parameter: Gain1_Gain_k
                                          //  Referenced by: '<S40>/Gain1'

  real32_T Integrator1_gainval_c;   // Computed Parameter: Integrator1_gainval_c
                                       //  Referenced by: '<S32>/Integrator1'

  real32_T Integrator1_IC_k;           // Computed Parameter: Integrator1_IC_k
                                          //  Referenced by: '<S32>/Integrator1'

  real32_T Gain2_Gain_p;               // Computed Parameter: Gain2_Gain_p
                                          //  Referenced by: '<S32>/Gain2'

  real32_T Gain1_Gain_d;               // Computed Parameter: Gain1_Gain_d
                                          //  Referenced by: '<S32>/Gain1'

  real32_T Gain3_Gain_i5;              // Computed Parameter: Gain3_Gain_i5
                                          //  Referenced by: '<S32>/Gain3'

  real32_T Gain_Gain_h;                // Computed Parameter: Gain_Gain_h
                                          //  Referenced by: '<S32>/Gain'

  real32_T Integrator1_gainval_l;   // Computed Parameter: Integrator1_gainval_l
                                       //  Referenced by: '<S28>/Integrator1'

  real32_T Integrator1_IC_d;           // Computed Parameter: Integrator1_IC_d
                                          //  Referenced by: '<S28>/Integrator1'

  real32_T Gain1_Gain_p;               // Computed Parameter: Gain1_Gain_p
                                          //  Referenced by: '<S28>/Gain1'

  real32_T Gain_Gain_l;                // Computed Parameter: Gain_Gain_l
                                          //  Referenced by: '<S28>/Gain'

  real32_T Gain2_Gain_e;               // Expression: CONTBATT.STICK.LON
                                          //  Referenced by: '<Root>/Gain2'

  real32_T Integrator_gainval_n;     // Computed Parameter: Integrator_gainval_n
                                        //  Referenced by: '<S28>/Integrator'

  real32_T Integrator_IC_p;            // Computed Parameter: Integrator_IC_p
                                          //  Referenced by: '<S28>/Integrator'

  real32_T Saturation_UpperSat_d;   // Expression: CONTBATT.PITCH.ATT.REF.DOTMAX
                                       //  Referenced by: '<S28>/Saturation'

  real32_T Saturation_LowerSat_n;   // Expression: CONTBATT.PITCH.ATT.REF.DOTMIN
                                       //  Referenced by: '<S28>/Saturation'

  real32_T Saturation1_UpperSat_h; // Expression: CONTBATT.PITCH.ATT.REF.DDOTMAX
                                      //  Referenced by: '<S28>/Saturation1'

  real32_T Saturation1_LowerSat_d; // Expression: CONTBATT.PITCH.ATT.REF.DDOTMIN
                                      //  Referenced by: '<S28>/Saturation1'

  real32_T Gain_Gain_n;                // Computed Parameter: Gain_Gain_n
                                          //  Referenced by: '<S26>/Gain'

  real32_T Integrator_gainval_nw;   // Computed Parameter: Integrator_gainval_nw
                                       //  Referenced by: '<S32>/Integrator'

  real32_T Integrator_IC_n;            // Computed Parameter: Integrator_IC_n
                                          //  Referenced by: '<S32>/Integrator'

  real32_T Saturation_UpperSat_e;   // Expression: CONTBATT.PITCH.ATT.REF.DOTMAX
                                       //  Referenced by: '<S32>/Saturation'

  real32_T Saturation_LowerSat_h;   // Expression: CONTBATT.PITCH.ATT.REF.DOTMIN
                                       //  Referenced by: '<S32>/Saturation'

  real32_T Saturation1_UpperSat_a; // Expression: CONTBATT.PITCH.ATT.REF.DDOTMAX
                                      //  Referenced by: '<S32>/Saturation1'

  real32_T Saturation1_LowerSat_c; // Expression: CONTBATT.PITCH.ATT.REF.DDOTMIN
                                      //  Referenced by: '<S32>/Saturation1'

  real32_T Gain_Gain_ct;               // Computed Parameter: Gain_Gain_ct
                                          //  Referenced by: '<S33>/Gain'

  real32_T DiscreteZeroPole_A_e[3];  // Computed Parameter: DiscreteZeroPole_A_e
                                        //  Referenced by: '<S34>/Discrete Zero-Pole'

  real32_T DiscreteZeroPole_B_n;     // Computed Parameter: DiscreteZeroPole_B_n
                                        //  Referenced by: '<S34>/Discrete Zero-Pole'

  real32_T DiscreteZeroPole_C_d[2];  // Computed Parameter: DiscreteZeroPole_C_d
                                        //  Referenced by: '<S34>/Discrete Zero-Pole'

  real32_T DiscreteZeroPole_D_g;     // Computed Parameter: DiscreteZeroPole_D_g
                                        //  Referenced by: '<S34>/Discrete Zero-Pole'

  real32_T Gain1_Gain_b;               // Computed Parameter: Gain1_Gain_b
                                          //  Referenced by: '<S29>/Gain1'

  real32_T Integrator1_gainval_a;   // Computed Parameter: Integrator1_gainval_a
                                       //  Referenced by: '<S49>/Integrator1'

  real32_T Integrator1_IC_pz;          // Computed Parameter: Integrator1_IC_pz
                                          //  Referenced by: '<S49>/Integrator1'

  real32_T Gain2_Gain_g;               // Computed Parameter: Gain2_Gain_g
                                          //  Referenced by: '<S49>/Gain2'

  real32_T Gain1_Gain_g;               // Computed Parameter: Gain1_Gain_g
                                          //  Referenced by: '<S49>/Gain1'

  real32_T Gain3_Gain_o;               // Computed Parameter: Gain3_Gain_o
                                          //  Referenced by: '<S49>/Gain3'

  real32_T Gain_Gain_i2;               // Computed Parameter: Gain_Gain_i2
                                          //  Referenced by: '<S49>/Gain'

  real32_T Gain4_Gain;                 // Expression: CONTBATT.STICK.YAW
                                          //  Referenced by: '<Root>/Gain4'

  real32_T Integrator_gainval_d;     // Computed Parameter: Integrator_gainval_d
                                        //  Referenced by: '<S49>/Integrator'

  real32_T Integrator_IC_c;            // Computed Parameter: Integrator_IC_c
                                          //  Referenced by: '<S49>/Integrator'

  real32_T Saturation_UpperSat_a;     // Expression: CONTBATT.YAW.ACC.REF.DOTMAX
                                         //  Referenced by: '<S49>/Saturation'

  real32_T Saturation_LowerSat_e;     // Expression: CONTBATT.YAW.ACC.REF.DOTMIN
                                         //  Referenced by: '<S49>/Saturation'

  real32_T Saturation1_UpperSat_g;   // Expression: CONTBATT.YAW.ACC.REF.DDOTMAX
                                        //  Referenced by: '<S49>/Saturation1'

  real32_T Saturation1_LowerSat_j;   // Expression: CONTBATT.YAW.ACC.REF.DDOTMIN
                                        //  Referenced by: '<S49>/Saturation1'

  real32_T Gain_Gain_lj;               // Computed Parameter: Gain_Gain_lj
                                          //  Referenced by: '<S50>/Gain'

  real32_T DiscreteZeroPole_A_b[3];  // Computed Parameter: DiscreteZeroPole_A_b
                                        //  Referenced by: '<S51>/Discrete Zero-Pole'

  real32_T DiscreteZeroPole_B_f;     // Computed Parameter: DiscreteZeroPole_B_f
                                        //  Referenced by: '<S51>/Discrete Zero-Pole'

  real32_T DiscreteZeroPole_C_i[2];  // Computed Parameter: DiscreteZeroPole_C_i
                                        //  Referenced by: '<S51>/Discrete Zero-Pole'

  real32_T DiscreteZeroPole_D_e;     // Computed Parameter: DiscreteZeroPole_D_e
                                        //  Referenced by: '<S51>/Discrete Zero-Pole'

  real32_T Gain1_Gain_a;               // Computed Parameter: Gain1_Gain_a
                                          //  Referenced by: '<S46>/Gain1'

  real32_T Constant_Value_h[3];        // Computed Parameter: Constant_Value_h
                                          //  Referenced by: '<S11>/Constant'

  real32_T Constant1_Value;            // Computed Parameter: Constant1_Value
                                          //  Referenced by: '<S11>/Constant1'

  real32_T Gain_Gain_dm;               // Computed Parameter: Gain_Gain_dm
                                          //  Referenced by: '<S11>/Gain'

  real32_T Gain1_Gain_j;               // Computed Parameter: Gain1_Gain_j
                                          //  Referenced by: '<S11>/Gain1'

  real32_T Gain_Gain_a3;               // Computed Parameter: Gain_Gain_a3
                                          //  Referenced by: '<S2>/Gain'

  real32_T Gain_Gain_p;                // Computed Parameter: Gain_Gain_p
                                          //  Referenced by: '<S3>/Gain'

  real32_T Gain_Gain_g;                // Computed Parameter: Gain_Gain_g
                                          //  Referenced by: '<S4>/Gain'

  real32_T Gain1_Gain_m;               // Computed Parameter: Gain1_Gain_m
                                          //  Referenced by: '<Root>/Gain1'

  real32_T Gain1_Gain_o;               // Computed Parameter: Gain1_Gain_o
                                          //  Referenced by: '<S54>/Gain1'

  real32_T Gain_Gain_f;                // Computed Parameter: Gain_Gain_f
                                          //  Referenced by: '<S54>/Gain'

  real32_T RateLimiter_RisingLim;   // Computed Parameter: RateLimiter_RisingLim
                                       //  Referenced by: '<Root>/Rate Limiter'

  real32_T RateLimiter_FallingLim; // Computed Parameter: RateLimiter_FallingLim
                                      //  Referenced by: '<Root>/Rate Limiter'

  real32_T RateLimiter_IC;             // Computed Parameter: RateLimiter_IC
                                          //  Referenced by: '<Root>/Rate Limiter'

  real32_T Gain6_Gain;                 // Expression: CONTBATT.STICK.THR
                                          //  Referenced by: '<Root>/Gain6'

  real32_T Integrator_gainval_a;     // Computed Parameter: Integrator_gainval_a
                                        //  Referenced by: '<S54>/Integrator'

  real32_T Integrator_IC_j;            // Computed Parameter: Integrator_IC_j
                                          //  Referenced by: '<S54>/Integrator'

  real32_T Saturation_UpperSat_i;      // Expression: CONTBATT.HDOT.REF.DOTMAX
                                          //  Referenced by: '<S54>/Saturation'

  real32_T Saturation_LowerSat_k;      // Expression: CONTBATT.HDOT.REF.DOTMIN
                                          //  Referenced by: '<S54>/Saturation'

  real32_T Integrator1_gainval_b;   // Computed Parameter: Integrator1_gainval_b
                                       //  Referenced by: '<S54>/Integrator1'

  real32_T Integrator1_IC_g;           // Computed Parameter: Integrator1_IC_g
                                          //  Referenced by: '<S54>/Integrator1'

  real32_T Saturation1_UpperSat_j;     // Expression: CONTBATT.HDOT.REF.DDOTMAX
                                          //  Referenced by: '<S54>/Saturation1'

  real32_T Saturation1_LowerSat_m0;    // Expression: CONTBATT.HDOT.REF.DDOTMIN
                                          //  Referenced by: '<S54>/Saturation1'

  real32_T DiscreteZeroPole_A_p[3];  // Computed Parameter: DiscreteZeroPole_A_p
                                        //  Referenced by: '<S55>/Discrete Zero-Pole'

  real32_T DiscreteZeroPole_B_k;     // Computed Parameter: DiscreteZeroPole_B_k
                                        //  Referenced by: '<S55>/Discrete Zero-Pole'

  real32_T DiscreteZeroPole_C_ig[2];// Computed Parameter: DiscreteZeroPole_C_ig
                                       //  Referenced by: '<S55>/Discrete Zero-Pole'

  real32_T DiscreteZeroPole_D_i;     // Computed Parameter: DiscreteZeroPole_D_i
                                        //  Referenced by: '<S55>/Discrete Zero-Pole'

  real32_T Gain1_Gain_oj;              // Computed Parameter: Gain1_Gain_oj
                                          //  Referenced by: '<S7>/Gain1'

};

// Real-time Model Data Structure
struct tag_RTM_CONSCALE_CON_TBATT_CO_T {
  const char_T * volatile errorStatus;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

// Class declaration for model CONSCALE_CON_TBATT_CONPARA_VECTOR
class CONFULL_CON_TBATT_CONPARA_VECTORModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_CONSCALE_CON_TBATT_CONPA_T CONSCALE_CON_TBATT_CONPARA_VE_U;

  // External outputs
  ExtY_CONSCALE_CON_TBATT_CONPA_T CONSCALE_CON_TBATT_CONPARA_VE_Y;

  // model initialize function
  void initialize();

  // model step function
  void step(const real32_T * const arg_DF_FRR_DEG, real32_T *arg_P_RADPS,
            real32_T *arg_Q_RADPS, real32_T *arg_R_RADPS, real32_T *arg_PHI_RAD,
            real32_T *arg_THETA_RAD, real32_T *arg_PSI_RAD, real32_T
            *arg_H_DOT_MPS, real32_T *arg_ROLL_ATT_CMD_DEG, real32_T
            *arg_PITCH_ATT_CMD_DEG, real32_T *arg_YAW_RATE_CMD_DEGPS, real32_T
            *arg_HDOT_CMD_MPS,
            const real32_T * const arg_ROLL_ANGLE_ERR_Kp, const real32_T * const
            arg_ROLL_ANGULAR_RATE_ERR_Kp, const real32_T * const
            arg_PITCH_ANGLE_ERR_Kp, const real32_T * const
            arg_PITCH_ANGULAR_RATE_ERR_Kp, const real32_T * const
            arg_YAW_ANGULAR_RATE_ERR_Kp, real32_T
            &arg_P_DOT_CMD, real32_T &arg_Q_DOT_CMD, real32_T &arg_R_DOT_CMD, real32_T
            &arg_G_B_MPS2);

  // model terminate function
  void terminate();

  // Constructor
  CONFULL_CON_TBATT_CONPARA_VECTORModelClass();

  // Destructor
  ~CONFULL_CON_TBATT_CONPARA_VECTORModelClass();

  // Real-Time Model get method
  RT_MODEL_CONSCALE_CON_TBATT_C_T * getRTM();

  // private data and function members
 private:
  // Tunable parameters
  static P_CONSCALE_CON_TBATT_CONPARA__T CONSCALE_CON_TBATT_CONPARA_VE_P;

  // Block states
  DW_CONSCALE_CON_TBATT_CONPARA_T CONSCALE_CON_TBATT_CONPARA_V_DW;

  // Real-Time Model
  RT_MODEL_CONSCALE_CON_TBATT_C_T CONSCALE_CON_TBATT_CONPARA_V_M;
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'CONSCALE_CON_TBATT_CONPARA_VECTOR'
//  '<S1>'   : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT'
//  '<S2>'   : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/Radians to Degrees'
//  '<S3>'   : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/Radians to Degrees1'
//  '<S4>'   : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/Radians to Degrees2'
//  '<S5>'   : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION'
//  '<S6>'   : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER'
//  '<S7>'   : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/HDDOT_EARTH2BODY'
//  '<S8>'   : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/VERTICAL_VELOCITY_CONTROLLER'
//  '<S9>'   : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT'
//  '<S10>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative'
//  '<S11>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Inverse'
//  '<S12>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative/A12'
//  '<S13>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative/A22'
//  '<S14>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative/A23'
//  '<S15>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative/A31'
//  '<S16>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative/A32'
//  '<S17>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative/A33'
//  '<S18>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative/ATTITUDE_DOT_ESTIMATION'
//  '<S19>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative/EULER_TRIGONOMETRIC'
//  '<S20>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATTITUDE_DOT_ESTIMATION'
//  '<S21>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH'
//  '<S22>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL'
//  '<S23>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/YAW_EULER_ANGLE_RATE_CONTROLLER'
//  '<S24>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/ATTITUDE_CONTROLLER'
//  '<S25>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/EULER_ANGLE_RATE_CONTROLLER'
//  '<S26>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/Radians to Degrees'
//  '<S27>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/ATTITUDE_CONTROLLER/ERROR_CONTROLLER'
//  '<S28>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/ATTITUDE_CONTROLLER/REF_MDL_2NDORDER'
//  '<S29>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/EULER_ANGLE_RATE_CONTROLLER/Degrees to Radians'
//  '<S30>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/EULER_ANGLE_RATE_CONTROLLER/ERROR_CONTROLLER'
//  '<S31>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/EULER_ANGLE_RATE_CONTROLLER/LEAD_LAG_FILTER'
//  '<S32>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/EULER_ANGLE_RATE_CONTROLLER/REF_MDL_2NDORDER1'
//  '<S33>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/EULER_ANGLE_RATE_CONTROLLER/Radians to Degrees'
//  '<S34>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/EULER_ANGLE_RATE_CONTROLLER/LEAD_LAG_FILTER/Zero-Pole'
//  '<S35>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/ATTITUDE_CONTROLLER'
//  '<S36>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/EULER_ANGLE_RATE_CONTROLLER'
//  '<S37>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/Radians to Degrees'
//  '<S38>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/ATTITUDE_CONTROLLER/ERROR_CONTROLLER'
//  '<S39>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/ATTITUDE_CONTROLLER/REF_MDL_2NDORDER'
//  '<S40>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/EULER_ANGLE_RATE_CONTROLLER/Degrees to Radians'
//  '<S41>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/EULER_ANGLE_RATE_CONTROLLER/ERROR_CONTROLLER'
//  '<S42>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/EULER_ANGLE_RATE_CONTROLLER/LEAD_LAG_FILTER'
//  '<S43>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/EULER_ANGLE_RATE_CONTROLLER/REF_MDL_2NDORDER1'
//  '<S44>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/EULER_ANGLE_RATE_CONTROLLER/Radians to Degrees'
//  '<S45>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/EULER_ANGLE_RATE_CONTROLLER/LEAD_LAG_FILTER/Zero-Pole'
//  '<S46>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/YAW_EULER_ANGLE_RATE_CONTROLLER/Degrees to Radians'
//  '<S47>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/YAW_EULER_ANGLE_RATE_CONTROLLER/ERROR_CONTROLLER'
//  '<S48>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/YAW_EULER_ANGLE_RATE_CONTROLLER/LEAD_LAG_FILTER'
//  '<S49>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/YAW_EULER_ANGLE_RATE_CONTROLLER/REF_MDL_2NDORDER1'
//  '<S50>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/YAW_EULER_ANGLE_RATE_CONTROLLER/Radians to Degrees'
//  '<S51>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/YAW_EULER_ANGLE_RATE_CONTROLLER/LEAD_LAG_FILTER/Zero-Pole'
//  '<S52>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/VERTICAL_VELOCITY_CONTROLLER/ERROR_CONTROLLER'
//  '<S53>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/VERTICAL_VELOCITY_CONTROLLER/LEAD_LAG_FILTER'
//  '<S54>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/VERTICAL_VELOCITY_CONTROLLER/REF_MDL_2NDORDER'
//  '<S55>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/VERTICAL_VELOCITY_CONTROLLER/LEAD_LAG_FILTER/Zero-Pole'

#endif                       // RTW_HEADER_CONSCALE_CON_TBATT_CONPARA_VECTOR_h_

//
// File trailer for generated code.
//
// [EOF]
//
