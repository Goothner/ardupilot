//
// File: CONSCALE_CON_TBATT_CONPARA_VECTOR.h
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
#ifndef RTW_HEADER_CONSCALE_CON_TBATT_CONPARA_VECTOR_h_
#define RTW_HEADER_CONSCALE_CON_TBATT_CONPARA_VECTOR_h_
#include "rtwtypes.h"
#include "CONSCALE_CON_TBATT_CONPARA_VECTOR_types.h"
#include <cstring>
#include <cmath>
#include "rt_defines.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Class declaration for model CONSCALE_CON_TBATT_CONPARA_VECTOR
class CONFULL_CON_TBATT_CONPARA_VECTORModelClass final
{
  // public data and function members
 public:
  // Block states (default storage) for system '<Root>'
  struct DW_CONSCALE_CON_TBATT_CONPARA_T {
    real_T Integrator1_DSTATE;         // '<S40>/Integrator1'
    real_T Integrator1_DSTATE_l;       // '<S36>/Integrator1'
    real_T Integrator_DSTATE;          // '<S36>/Integrator'
    real_T Integrator_DSTATE_e;        // '<S40>/Integrator'
    real_T DiscreteZeroPole_DSTATE[2]; // '<S42>/Discrete Zero-Pole'
    real_T Integrator1_DSTATE_m;       // '<S29>/Integrator1'
    real_T Integrator1_DSTATE_j;       // '<S25>/Integrator1'
    real_T Integrator_DSTATE_m;        // '<S25>/Integrator'
    real_T Integrator_DSTATE_mg;       // '<S29>/Integrator'
    real_T DiscreteZeroPole_DSTATE_f[2];// '<S31>/Discrete Zero-Pole'
    real_T Integrator1_DSTATE_i;       // '<S46>/Integrator1'
    real_T Integrator_DSTATE_d;        // '<S46>/Integrator'
    real_T DiscreteZeroPole_DSTATE_b[2];// '<S48>/Discrete Zero-Pole'
    real_T Integrator1_DSTATE_g;       // '<S51>/Integrator1'
    real_T Integrator_DSTATE_n;        // '<S51>/Integrator'
    real_T DiscreteZeroPole_DSTATE_h[2];// '<S52>/Discrete Zero-Pole'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_CONSCALE_CON_TBATT_CONPA_T {
    real_T DF_FRR_DEGLIN;              // '<Root>/DF_FRR_DEGLIN'
    real32_T P_DOT_CMD;                // '<Root>/P_DOT_CMD'
    real32_T Q_DOT_CMD;                // '<Root>/Q_DOT_CMD'
    real32_T R_DOT_CMD;                // '<Root>/R_DOT_CMD'
    real32_T G_B_MPS2;                 // '<Root>/G_B_MPS2'
  };

  // Parameters (default storage)
  struct P_CONSCALE_CON_TBATT_CONPARA__T {
    struct_BXysS30lSwOi4L1jeGgsOD CONTBATT;// Variable: CONTBATT
                                              //  Referenced by:
                                              //    '<S51>/Saturation'
                                              //    '<S51>/Saturation1'
                                              //    '<S46>/Saturation'
                                              //    '<S46>/Saturation1'
                                              //    '<S25>/Saturation'
                                              //    '<S25>/Saturation1'
                                              //    '<S29>/Saturation'
                                              //    '<S29>/Saturation1'
                                              //    '<S36>/Saturation'
                                              //    '<S36>/Saturation1'
                                              //    '<S40>/Saturation'
                                              //    '<S40>/Saturation1'

    STATES_ATT Constant1_Value;        // Computed Parameter: Constant1_Value
                                          //  Referenced by: '<Root>/Constant1'

    STATES_ROT Constant2_Value;        // Computed Parameter: Constant2_Value
                                          //  Referenced by: '<Root>/Constant2'

    real_T Constant_Value[3];          // Expression: [0;0;0]
                                          //  Referenced by: '<S7>/Constant'

    real_T Gain_Gain;                  // Expression: -1
                                          //  Referenced by: '<S10>/Gain'

    real_T Gain_Gain_n;                // Expression: -1
                                          //  Referenced by: '<S13>/Gain'

    real_T Gain_Gain_f;                // Expression: -1
                                          //  Referenced by: '<S14>/Gain'

    real_T Integrator1_gainval;       // Computed Parameter: Integrator1_gainval
                                         //  Referenced by: '<S40>/Integrator1'

    real_T Integrator1_IC;             // Expression: 0
                                          //  Referenced by: '<S40>/Integrator1'

    real_T Gain2_Gain;                 // Expression: 0.8
                                          //  Referenced by: '<S40>/Gain2'

    real_T Gain1_Gain;                 // Expression: 2
                                          //  Referenced by: '<S40>/Gain1'

    real_T Gain3_Gain;                 // Expression: 4
                                          //  Referenced by: '<S40>/Gain3'

    real_T Gain_Gain_m;                // Expression: 1/2
                                          //  Referenced by: '<S40>/Gain'

    real_T Integrator1_gainval_j;   // Computed Parameter: Integrator1_gainval_j
                                       //  Referenced by: '<S36>/Integrator1'

    real_T Integrator1_IC_c;           // Expression: 0
                                          //  Referenced by: '<S36>/Integrator1'

    real_T Gain1_Gain_m;               // Expression: 2
                                          //  Referenced by: '<S36>/Gain1'

    real_T Gain_Gain_l;                // Expression: 1/2
                                          //  Referenced by: '<S36>/Gain'

    real_T Integrator_gainval;         // Computed Parameter: Integrator_gainval
                                          //  Referenced by: '<S36>/Integrator'

    real_T Integrator_IC;              // Expression: 0
                                          //  Referenced by: '<S36>/Integrator'

    real_T Gain_Gain_o;                // Expression: 180/pi
                                          //  Referenced by: '<S34>/Gain'

    real_T Integrator_gainval_p;     // Computed Parameter: Integrator_gainval_p
                                        //  Referenced by: '<S40>/Integrator'

    real_T Integrator_IC_n;            // Expression: 0
                                          //  Referenced by: '<S40>/Integrator'

    real_T Gain_Gain_i;                // Expression: 180/pi
                                          //  Referenced by: '<S41>/Gain'

    real_T DiscreteZeroPole_A[3];      // Computed Parameter: DiscreteZeroPole_A
                                          //  Referenced by: '<S42>/Discrete Zero-Pole'

    real_T DiscreteZeroPole_B;         // Computed Parameter: DiscreteZeroPole_B
                                          //  Referenced by: '<S42>/Discrete Zero-Pole'

    real_T DiscreteZeroPole_D;         // Computed Parameter: DiscreteZeroPole_D
                                          //  Referenced by: '<S42>/Discrete Zero-Pole'

    real_T Gain1_Gain_c;               // Expression: pi/180
                                          //  Referenced by: '<S37>/Gain1'

    real_T Integrator1_gainval_a;   // Computed Parameter: Integrator1_gainval_a
                                       //  Referenced by: '<S29>/Integrator1'

    real_T Integrator1_IC_e;           // Expression: 0
                                          //  Referenced by: '<S29>/Integrator1'

    real_T Gain2_Gain_e;               // Expression: 1
                                          //  Referenced by: '<S29>/Gain2'

    real_T Gain1_Gain_m2;              // Expression: 2
                                          //  Referenced by: '<S29>/Gain1'

    real_T Gain3_Gain_i;               // Expression: 5
                                          //  Referenced by: '<S29>/Gain3'

    real_T Gain_Gain_f1;               // Expression: 1/2
                                          //  Referenced by: '<S29>/Gain'

    real_T Integrator1_gainval_au; // Computed Parameter: Integrator1_gainval_au
                                      //  Referenced by: '<S25>/Integrator1'

    real_T Integrator1_IC_l;           // Expression: 0
                                          //  Referenced by: '<S25>/Integrator1'

    real_T Gain1_Gain_c5;              // Expression: 2
                                          //  Referenced by: '<S25>/Gain1'

    real_T Gain_Gain_d;                // Expression: 1/2
                                          //  Referenced by: '<S25>/Gain'

    real_T Integrator_gainval_f;     // Computed Parameter: Integrator_gainval_f
                                        //  Referenced by: '<S25>/Integrator'

    real_T Integrator_IC_c;            // Expression: 0
                                          //  Referenced by: '<S25>/Integrator'

    real_T Gain_Gain_b;                // Expression: 180/pi
                                          //  Referenced by: '<S23>/Gain'

    real_T Integrator_gainval_g;     // Computed Parameter: Integrator_gainval_g
                                        //  Referenced by: '<S29>/Integrator'

    real_T Integrator_IC_i;            // Expression: 0
                                          //  Referenced by: '<S29>/Integrator'

    real_T Gain_Gain_f2;               // Expression: 180/pi
                                          //  Referenced by: '<S30>/Gain'

    real_T DiscreteZeroPole_A_f[3];  // Computed Parameter: DiscreteZeroPole_A_f
                                        //  Referenced by: '<S31>/Discrete Zero-Pole'

    real_T DiscreteZeroPole_B_j;     // Computed Parameter: DiscreteZeroPole_B_j
                                        //  Referenced by: '<S31>/Discrete Zero-Pole'

    real_T DiscreteZeroPole_C_j[2];  // Computed Parameter: DiscreteZeroPole_C_j
                                        //  Referenced by: '<S31>/Discrete Zero-Pole'

    real_T DiscreteZeroPole_D_f;     // Computed Parameter: DiscreteZeroPole_D_f
                                        //  Referenced by: '<S31>/Discrete Zero-Pole'

    real_T Gain1_Gain_l;               // Expression: pi/180
                                          //  Referenced by: '<S26>/Gain1'

    real_T Integrator1_gainval_e;   // Computed Parameter: Integrator1_gainval_e
                                       //  Referenced by: '<S46>/Integrator1'

    real_T Integrator1_IC_i;           // Expression: 0
                                          //  Referenced by: '<S46>/Integrator1'

    real_T Gain2_Gain_k;               // Expression: 1
                                          //  Referenced by: '<S46>/Gain2'

    real_T Gain1_Gain_o;               // Expression: 2
                                          //  Referenced by: '<S46>/Gain1'

    real_T Gain3_Gain_o;               // Expression: 1
                                          //  Referenced by: '<S46>/Gain3'

    real_T Gain_Gain_oc;               // Expression: 1/2
                                          //  Referenced by: '<S46>/Gain'

    real_T Integrator_gainval_b;     // Computed Parameter: Integrator_gainval_b
                                        //  Referenced by: '<S46>/Integrator'

    real_T Integrator_IC_h;            // Expression: 0
                                          //  Referenced by: '<S46>/Integrator'

    real_T Gain_Gain_a;                // Expression: 180/pi
                                          //  Referenced by: '<S47>/Gain'

    real_T DiscreteZeroPole_A_m[3];  // Computed Parameter: DiscreteZeroPole_A_m
                                        //  Referenced by: '<S48>/Discrete Zero-Pole'

    real_T DiscreteZeroPole_B_p;     // Computed Parameter: DiscreteZeroPole_B_p
                                        //  Referenced by: '<S48>/Discrete Zero-Pole'

    real_T DiscreteZeroPole_C_l[2];  // Computed Parameter: DiscreteZeroPole_C_l
                                        //  Referenced by: '<S48>/Discrete Zero-Pole'

    real_T DiscreteZeroPole_D_e;     // Computed Parameter: DiscreteZeroPole_D_e
                                        //  Referenced by: '<S48>/Discrete Zero-Pole'

    real_T Gain1_Gain_j;               // Expression: pi/180
                                          //  Referenced by: '<S43>/Gain1'

    real_T Constant_Value_p[3];        // Expression: [1;0;0]
                                          //  Referenced by: '<S8>/Constant'

    real_T Constant1_Value_d;          // Expression: 0
                                          //  Referenced by: '<S8>/Constant1'

    real_T Gain_Gain_h;                // Expression: -1
                                          //  Referenced by: '<S8>/Gain'

    real_T Gain1_Gain_cj;              // Expression: -1
                                          //  Referenced by: '<S8>/Gain1'

    real_T Integrator1_gainval_l;   // Computed Parameter: Integrator1_gainval_l
                                       //  Referenced by: '<S51>/Integrator1'

    real_T Integrator1_IC_lz;          // Expression: 0
                                          //  Referenced by: '<S51>/Integrator1'

    real_T Gain1_Gain_cp;              // Expression: 2
                                          //  Referenced by: '<S51>/Gain1'

    real_T Gain_Gain_nl;               // Expression: 1/2
                                          //  Referenced by: '<S51>/Gain'

    real_T Integrator_gainval_m;     // Computed Parameter: Integrator_gainval_m
                                        //  Referenced by: '<S51>/Integrator'

    real_T Integrator_IC_e;            // Expression: 0
                                          //  Referenced by: '<S51>/Integrator'

    real_T DiscreteZeroPole_A_l[3];  // Computed Parameter: DiscreteZeroPole_A_l
                                        //  Referenced by: '<S52>/Discrete Zero-Pole'

    real_T DiscreteZeroPole_B_e;     // Computed Parameter: DiscreteZeroPole_B_e
                                        //  Referenced by: '<S52>/Discrete Zero-Pole'

    real_T DiscreteZeroPole_C_d[2];  // Computed Parameter: DiscreteZeroPole_C_d
                                        //  Referenced by: '<S52>/Discrete Zero-Pole'

    real_T DiscreteZeroPole_D_l;     // Computed Parameter: DiscreteZeroPole_D_l
                                        //  Referenced by: '<S52>/Discrete Zero-Pole'

    real_T Gain1_Gain_k;               // Expression: -1
                                          //  Referenced by: '<S4>/Gain1'

    real_T Gain1_Gain_mq;              // Expression: 2
                                          //  Referenced by: '<Root>/Gain1'

  };

  // Real-time Model Data Structure
  struct RT_MODEL_CONSCALE_CON_TBATT_C_T {
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

  // Copy Constructor
  CONFULL_CON_TBATT_CONPARA_VECTORModelClass
    (CONFULL_CON_TBATT_CONPARA_VECTORModelClass const&) = delete;

  // Assignment Operator
  CONFULL_CON_TBATT_CONPARA_VECTORModelClass& operator=
    (CONFULL_CON_TBATT_CONPARA_VECTORModelClass const&) & = delete;

  // Move Constructor
  CONFULL_CON_TBATT_CONPARA_VECTORModelClass
    (CONFULL_CON_TBATT_CONPARA_VECTORModelClass &&) = delete;

  // Move Assignment Operator
  CONFULL_CON_TBATT_CONPARA_VECTORModelClass& operator=
    (CONFULL_CON_TBATT_CONPARA_VECTORModelClass &&) = delete;

  // Real-Time Model get method
  CONFULL_CON_TBATT_CONPARA_VECTORModelClass::RT_MODEL_CONSCALE_CON_TBATT_C_T
    * getRTM();

  // External outputs
  ExtY_CONSCALE_CON_TBATT_CONPA_T CONSCALE_CON_TBATT_CONPARA_VE_Y;

  // Tunable parameters
  static P_CONSCALE_CON_TBATT_CONPARA__T CONSCALE_CON_TBATT_CONPARA_VE_P;

  // model initialize function
  void initialize();

  // model step function
  void step(const real32_T * const arg_DF_FRR_DEG, real32_T *arg_P_RADPS,
            real32_T *arg_Q_RADPS, real32_T *arg_R_RADPS, real32_T *arg_PHI_RAD,
            real32_T *arg_THETA_RAD, real32_T *arg_PSI_RAD, real32_T
            *arg_H_DOT_MPS, real32_T *arg_ROLL_ATT_CMD_DEG, real32_T
            *arg_PITCH_ATT_CMD_DEG, real32_T *arg_YAW_RATE_CMD_DEGPS, real32_T
            *arg_HDOT_CMD_MPS, const real32_T * const arg_VER_VEL_ERR_Kp_, const
            real32_T * const arg_VER_VEL_REF_KFF, const real32_T * const
            arg_VER_VEL_REF_ZETA, const real32_T * const
            arg_VER_VEL_REF_W0_RADPS, const real32_T * const arg_VER_VEL_REF_K3,
            const real32_T * const arg_ROLL_ANGLE_ERR_Kp_1, const real32_T *
            const arg_ROLL_ANGLE_REF_KFF, const real32_T * const
            arg_ROLL_ANGLE_REF_ZETA, const real32_T * const
            arg_ROLL_ANGLE_REF_W0_RADPS, const real32_T * const
            arg_ROLL_ANGLE_REF_K3, const real32_T * const
            arg_ROLL_ANGULAR_RATE_ERR_Kp_, const real32_T * const
            arg_ROLL_ANGUALR_RATE_REF_KFF, const real32_T * const
            arg_ROLL_ANGULAR_RATE_REF_K3, const real32_T * const
            arg_PITCH_ANGLE_ERR_Kp_2, const real32_T * const
            arg_PITCH_ANGLE_REF_KFF, const real32_T * const
            arg_PITCH_ANGLE_REF_ZETA, const real32_T * const
            arg_PITCH_ANGLE_REF_W0_RADPS, const real32_T * const
            arg_PITCH_ANGLE_REF_K3, const real32_T * const
            arg_PITCH_ANGULAR_RATE_ERR_Kp_, const real32_T * const
            arg_PITCH_ANGULAR_RATE_REF_KFF, const real32_T * const
            arg_PITCH_ANGULAR_RATE_REF_K3, const real32_T * const
            arg_YAW_ANGULAR_RATE_ERR_Kp_2, const real32_T * const
            arg_YAW_ANGULAR_RATE_REF_KFF, const real32_T * const
            arg_YAW_ANGULAR_RATE_REF_ZETA, const real32_T * const
            arg_YAW_ANGULAR_RATE_REF_W0_RADPS, const real32_T * const
            arg_YAW_ANGULAR_RATE_REF_K3, real32_T &arg_DF_FRR_DEGLIN, real32_T
            &arg_P_DOT_CMD, real32_T &arg_Q_DOT_CMD, real32_T &arg_R_DOT_CMD,
            real32_T &arg_G_B_MPS2);

  // model terminate function
  static void terminate();

  // Constructor
  CONFULL_CON_TBATT_CONPARA_VECTORModelClass();

  // Destructor
  ~CONFULL_CON_TBATT_CONPARA_VECTORModelClass();

  // private data and function members
 private:
  // Block states
  DW_CONSCALE_CON_TBATT_CONPARA_T CONSCALE_CON_TBATT_CONPARA_V_DW;

  // Real-Time Model
  RT_MODEL_CONSCALE_CON_TBATT_C_T CONSCALE_CON_TBATT_CONPARA_V_M;
};

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
//  '<S2>'   : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION'
//  '<S3>'   : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER'
//  '<S4>'   : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/HDDOT_EARTH2BODY'
//  '<S5>'   : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/VERTICAL_VELOCITY_CONTROLLER'
//  '<S6>'   : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT'
//  '<S7>'   : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative'
//  '<S8>'   : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Inverse'
//  '<S9>'   : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative/A12'
//  '<S10>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative/A22'
//  '<S11>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative/A23'
//  '<S12>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative/A31'
//  '<S13>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative/A32'
//  '<S14>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative/A33'
//  '<S15>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative/ATTITUDE_DOT_ESTIMATION'
//  '<S16>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/ANGULAR_DYNAMIC_INVERSION/ANGULAR_ACC2RATEDOT/Generate_Strapdown_Derivative/EULER_TRIGONOMETRIC'
//  '<S17>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATTITUDE_DOT_ESTIMATION'
//  '<S18>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH'
//  '<S19>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL'
//  '<S20>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/YAW_EULER_ANGLE_RATE_CONTROLLER'
//  '<S21>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/ATTITUDE_CONTROLLER'
//  '<S22>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/EULER_ANGLE_RATE_CONTROLLER'
//  '<S23>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/Radians to Degrees'
//  '<S24>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/ATTITUDE_CONTROLLER/ERROR_CONTROLLER'
//  '<S25>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/ATTITUDE_CONTROLLER/REF_MDL_2NDORDER'
//  '<S26>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/EULER_ANGLE_RATE_CONTROLLER/Degrees to Radians'
//  '<S27>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/EULER_ANGLE_RATE_CONTROLLER/ERROR_CONTROLLER'
//  '<S28>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/EULER_ANGLE_RATE_CONTROLLER/LEAD_LAG_FILTER'
//  '<S29>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/EULER_ANGLE_RATE_CONTROLLER/REF_MDL_2NDORDER1'
//  '<S30>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/EULER_ANGLE_RATE_CONTROLLER/Radians to Degrees'
//  '<S31>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_PITCH/EULER_ANGLE_RATE_CONTROLLER/LEAD_LAG_FILTER/Zero-Pole'
//  '<S32>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/ATTITUDE_CONTROLLER'
//  '<S33>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/EULER_ANGLE_RATE_CONTROLLER'
//  '<S34>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/Radians to Degrees'
//  '<S35>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/ATTITUDE_CONTROLLER/ERROR_CONTROLLER'
//  '<S36>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/ATTITUDE_CONTROLLER/REF_MDL_2NDORDER'
//  '<S37>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/EULER_ANGLE_RATE_CONTROLLER/Degrees to Radians'
//  '<S38>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/EULER_ANGLE_RATE_CONTROLLER/ERROR_CONTROLLER'
//  '<S39>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/EULER_ANGLE_RATE_CONTROLLER/LEAD_LAG_FILTER'
//  '<S40>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/EULER_ANGLE_RATE_CONTROLLER/REF_MDL_2NDORDER1'
//  '<S41>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/EULER_ANGLE_RATE_CONTROLLER/Radians to Degrees'
//  '<S42>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/ATT_MODE_CONTROLLER_ROLL/EULER_ANGLE_RATE_CONTROLLER/LEAD_LAG_FILTER/Zero-Pole'
//  '<S43>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/YAW_EULER_ANGLE_RATE_CONTROLLER/Degrees to Radians'
//  '<S44>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/YAW_EULER_ANGLE_RATE_CONTROLLER/ERROR_CONTROLLER'
//  '<S45>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/YAW_EULER_ANGLE_RATE_CONTROLLER/LEAD_LAG_FILTER'
//  '<S46>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/YAW_EULER_ANGLE_RATE_CONTROLLER/REF_MDL_2NDORDER1'
//  '<S47>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/YAW_EULER_ANGLE_RATE_CONTROLLER/Radians to Degrees'
//  '<S48>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/FULL_ATT_MODE_CONTROLLER/YAW_EULER_ANGLE_RATE_CONTROLLER/LEAD_LAG_FILTER/Zero-Pole'
//  '<S49>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/VERTICAL_VELOCITY_CONTROLLER/ERROR_CONTROLLER'
//  '<S50>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/VERTICAL_VELOCITY_CONTROLLER/LEAD_LAG_FILTER'
//  '<S51>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/VERTICAL_VELOCITY_CONTROLLER/REF_MDL_2NDORDER'
//  '<S52>'  : 'CONSCALE_CON_TBATT_CONPARA_VECTOR/CONTROLLER_THRUSTBORNE_ATT/VERTICAL_VELOCITY_CONTROLLER/LEAD_LAG_FILTER/Zero-Pole'

#endif                       // RTW_HEADER_CONSCALE_CON_TBATT_CONPARA_VECTOR_h_

//
// File trailer for generated code.
//
// [EOF]
//
