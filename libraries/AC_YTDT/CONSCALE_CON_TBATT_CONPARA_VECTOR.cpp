//
// File: CONSCALE_CON_TBATT_CONPARA_VECTOR.cpp
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
#include "CONSCALE_CON_TBATT_CONPARA_VECTOR.h"
#include "rtwtypes.h"


static void rate_scheduler(CONFULL_CON_TBATT_CONPARA_VECTORModelClass::
  RT_MODEL_CONSCALE_CON_TBATT_C_T *const CONSCALE_CON_TBATT_CONPARA_V_M);

//
//         This function updates active task flag for each subrate.
//         The function is called at model base rate, hence the
//         generated code self-manages all its subrates.
//
static void rate_scheduler(CONFULL_CON_TBATT_CONPARA_VECTORModelClass::
  RT_MODEL_CONSCALE_CON_TBATT_C_T *const CONSCALE_CON_TBATT_CONPARA_V_M)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (CONSCALE_CON_TBATT_CONPARA_V_M->Timing.TaskCounters.TID[1])++;
  if ((CONSCALE_CON_TBATT_CONPARA_V_M->Timing.TaskCounters.TID[1]) > 7) {// Sample time: [0.02s, 0.0s] 
    CONSCALE_CON_TBATT_CONPARA_V_M->Timing.TaskCounters.TID[1] = 0;
  }
}

// Model step function
void CONFULL_CON_TBATT_CONPARA_VECTORModelClass::step(const real32_T *const
  arg_DF_FRR_DEG, real32_T *arg_P_RADPS, real32_T *arg_Q_RADPS, real32_T
  *arg_R_RADPS, real32_T *arg_PHI_RAD, real32_T *arg_THETA_RAD, real32_T
  *arg_PSI_RAD, real32_T *arg_H_DOT_MPS, real32_T *arg_ROLL_ATT_CMD_DEG,
  real32_T *arg_PITCH_ATT_CMD_DEG, real32_T *arg_YAW_RATE_CMD_DEGPS, real32_T
  *arg_HDOT_CMD_MPS, const real32_T *const arg_VER_VEL_ERR_Kp_, const real32_T *
  const arg_VER_VEL_REF_KFF, const real32_T *const arg_VER_VEL_REF_ZETA, const
  real32_T *const arg_VER_VEL_REF_W0_RADPS, const real32_T *const
  arg_VER_VEL_REF_K3, const real32_T *const arg_ROLL_ANGLE_ERR_Kp_1, const
  real32_T *const arg_ROLL_ANGLE_REF_KFF, const real32_T *const
  arg_ROLL_ANGLE_REF_ZETA, const real32_T *const arg_ROLL_ANGLE_REF_W0_RADPS,
  const real32_T *const arg_ROLL_ANGLE_REF_K3, const real32_T *const
  arg_ROLL_ANGULAR_RATE_ERR_Kp_, const real32_T *const
  arg_ROLL_ANGUALR_RATE_REF_KFF, const real32_T *const
  arg_ROLL_ANGULAR_RATE_REF_K3, const real32_T *const arg_PITCH_ANGLE_ERR_Kp_2,
  const real32_T *const arg_PITCH_ANGLE_REF_KFF, const real32_T *const
  arg_PITCH_ANGLE_REF_ZETA, const real32_T *const arg_PITCH_ANGLE_REF_W0_RADPS,
  const real32_T *const arg_PITCH_ANGLE_REF_K3, const real32_T *const
  arg_PITCH_ANGULAR_RATE_ERR_Kp_, const real32_T *const
  arg_PITCH_ANGULAR_RATE_REF_KFF, const real32_T *const
  arg_PITCH_ANGULAR_RATE_REF_K3, const real32_T *const
  arg_YAW_ANGULAR_RATE_ERR_Kp_2, const real32_T *const
  arg_YAW_ANGULAR_RATE_REF_KFF, const real32_T *const
  arg_YAW_ANGULAR_RATE_REF_ZETA, const real32_T *const
  arg_YAW_ANGULAR_RATE_REF_W0_RADPS, const real32_T *const
  arg_YAW_ANGULAR_RATE_REF_K3, real_T &arg_DF_FRR_DEGLIN, real32_T
  &arg_P_DOT_CMD, real32_T &arg_Q_DOT_CMD, real32_T &arg_R_DOT_CMD, real32_T
  &arg_G_B_MPS2)
{
  // local block i/o variables
  real_T rtb_Product_i;
  real_T rtb_Product_f;
  real_T rtb_Product_p0;
  real_T rtb_Product_d;
  real_T rtb_DataTypeConversion6;
  real_T rtb_VectorConcatenate2_f[9];
  real_T rtb_Sum_hp[3];
  real_T rtb_CMD_DDOT_DES;
  real_T rtb_CMD_DDOT_DES_o;
  real_T rtb_CMD_DDOT_REF;
  real_T rtb_CMD_DDOT_REF_c;
  real_T rtb_CMD_DOT_DES_SAT;
  real_T rtb_CMD_DOT_REF;
  real_T rtb_CMD_DOT_REF_az;
  real_T rtb_Product7;
  real_T rtb_Product_pm;
  real_T rtb_REF_K1;
  real_T rtb_REF_K1_k;
  real_T rtb_REF_K3;
  real_T rtb_REF_K3_i;
  real_T rtb_Sum_ct;
  real_T rtb_Sum_g;
  real_T rtb_Sum_h;
  real_T rtb_Sum_ir;
  real_T rtb_VER_VEL_REF_W0_RADPS;
  real_T rtb_Z_DDOT_MPS2;
  int32_T i;
  real32_T rtb_DataTypeConversion25[3];
  UNUSED_PARAMETER(arg_PSI_RAD);
  if ((&CONSCALE_CON_TBATT_CONPARA_V_M)->Timing.TaskCounters.TID[1] == 0) {
    // Trigonometry: '<S15>/Sin' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion3'
    //   Inport: '<Root>/PHI_RAD'
    //   Trigonometry: '<S16>/Sin3'
    //   Trigonometry: '<S17>/Sin'

    rtb_CMD_DOT_REF_az = std::sin(static_cast<real_T>(*arg_PHI_RAD));

    // Trigonometry: '<S15>/Cos' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion3'
    //   DataTypeConversion: '<Root>/Data Type Conversion4'
    //   Inport: '<Root>/PHI_RAD'
    //   Inport: '<Root>/THETA_RAD'
    //   Trigonometry: '<S16>/Sin1'
    //   Trigonometry: '<S16>/Sin2'
    //   Trigonometry: '<S17>/Cos'
    //   Trigonometry: '<S4>/Cos'
    //   Trigonometry: '<S8>/Cos'

    rtb_Z_DDOT_MPS2 = std::cos(static_cast<real_T>(*arg_PHI_RAD));
    rtb_CMD_DDOT_REF_c = std::cos(static_cast<real_T>(*arg_THETA_RAD));

    // Trigonometry: '<S15>/Sin' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion4'
    //   Inport: '<Root>/THETA_RAD'
    //   Trigonometry: '<S16>/Sin'

    rtb_Product_pm = std::sin(static_cast<real_T>(*arg_THETA_RAD));

    // Fcn: '<S15>/dot phi' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion'
    //   DataTypeConversion: '<Root>/Data Type Conversion1'
    //   DataTypeConversion: '<Root>/Data Type Conversion2'
    //   Fcn: '<S17>/dot phi'
    //   Fcn: '<S17>/dot psi'
    //   Inport: '<Root>/P_RADPS'
    //   Inport: '<Root>/Q_RADPS'
    //   Inport: '<Root>/R_RADPS'
    //   Trigonometry: '<S15>/Cos'
    //   Trigonometry: '<S15>/Sin'

    rtb_Sum_ir = rtb_CMD_DOT_REF_az * *arg_Q_RADPS + rtb_Z_DDOT_MPS2 *
      *arg_R_RADPS;
    rtb_Sum_g = rtb_Product_pm / rtb_CMD_DDOT_REF_c * rtb_Sum_ir + *arg_P_RADPS;

    // Fcn: '<S15>/dot theta' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion1'
    //   DataTypeConversion: '<Root>/Data Type Conversion2'
    //   Fcn: '<S17>/dot theta'
    //   Inport: '<Root>/Q_RADPS'
    //   Inport: '<Root>/R_RADPS'
    //   Trigonometry: '<S15>/Cos'
    //   Trigonometry: '<S15>/Sin'

    rtb_Sum_ct = rtb_Z_DDOT_MPS2 * *arg_Q_RADPS - rtb_CMD_DOT_REF_az *
      *arg_R_RADPS;

    // Constant: '<S7>/Constant'
    rtb_VectorConcatenate2_f[0] =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Constant_Value[0];
    rtb_VectorConcatenate2_f[1] =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Constant_Value[1];
    rtb_VectorConcatenate2_f[2] =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Constant_Value[2];

    // Product: '<S9>/Product1' incorporates:
    //   Fcn: '<S15>/dot phi'
    //   Product: '<S11>/Product3'
    //   Product: '<S13>/Product3'

    rtb_CMD_DOT_REF = rtb_Sum_g * rtb_Z_DDOT_MPS2;
    rtb_REF_K3 = rtb_CMD_DOT_REF * rtb_CMD_DDOT_REF_c;

    // Product: '<S9>/Product3' incorporates:
    //   Fcn: '<S15>/dot theta'
    //   Product: '<S11>/Product1'

    rtb_CMD_DDOT_REF = rtb_Sum_ct * rtb_CMD_DOT_REF_az;

    // Math: '<S9>/Square' incorporates:
    //   Math: '<S11>/Square'
    //   Math: '<S12>/Square'
    //   Math: '<S14>/Square'

    rtb_CMD_DOT_DES_SAT = rtb_CMD_DDOT_REF_c * rtb_CMD_DDOT_REF_c;

    // Product: '<S9>/Product2' incorporates:
    //   Math: '<S9>/Square'
    //   Product: '<S9>/Product1'
    //   Product: '<S9>/Product3'
    //   Sum: '<S9>/Sum'

    rtb_VectorConcatenate2_f[3] = (rtb_REF_K3 * rtb_Product_pm +
      rtb_CMD_DDOT_REF) / rtb_CMD_DOT_DES_SAT;

    // Gain: '<S10>/Gain' incorporates:
    //   Fcn: '<S15>/dot phi'
    //   Product: '<S10>/Product3'

    rtb_VectorConcatenate2_f[4] = rtb_Sum_g * rtb_CMD_DOT_REF_az *
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain;

    // Product: '<S11>/Product2' incorporates:
    //   Product: '<S11>/Product1'
    //   Sum: '<S11>/Sum'

    rtb_VectorConcatenate2_f[5] = (rtb_CMD_DDOT_REF * rtb_Product_pm +
      rtb_REF_K3) / rtb_CMD_DOT_DES_SAT;

    // Product: '<S12>/Product1' incorporates:
    //   Fcn: '<S15>/dot phi'
    //   Product: '<S14>/Product3'

    rtb_REF_K3 = rtb_Sum_g * rtb_CMD_DDOT_REF_c * rtb_CMD_DOT_REF_az;

    // Product: '<S12>/Product3' incorporates:
    //   Fcn: '<S15>/dot theta'
    //   Product: '<S14>/Product1'

    rtb_CMD_DDOT_REF = rtb_Sum_ct * rtb_Z_DDOT_MPS2;

    // Product: '<S12>/Product2' incorporates:
    //   Product: '<S12>/Product1'
    //   Product: '<S12>/Product3'
    //   Sum: '<S12>/Sum'

    rtb_VectorConcatenate2_f[6] = (rtb_CMD_DDOT_REF - rtb_REF_K3 *
      rtb_Product_pm) / rtb_CMD_DOT_DES_SAT;

    // Gain: '<S13>/Gain'
    rtb_VectorConcatenate2_f[7] = rtb_CMD_DOT_REF *
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_n;

    // Gain: '<S14>/Gain' incorporates:
    //   Product: '<S14>/Product1'
    //   Product: '<S14>/Product2'
    //   Sum: '<S14>/Sum'

    rtb_VectorConcatenate2_f[8] = (rtb_REF_K3 - rtb_CMD_DDOT_REF *
      rtb_Product_pm) / rtb_CMD_DOT_DES_SAT *
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_f;

    // Product: '<S6>/Matrix Multiply' incorporates:
    //   Concatenate: '<S8>/Vector Concatenate2'
    //   DataTypeConversion: '<Root>/Data Type Conversion'
    //   DataTypeConversion: '<Root>/Data Type Conversion1'
    //   DataTypeConversion: '<Root>/Data Type Conversion2'
    //   Inport: '<Root>/P_RADPS'
    //   Inport: '<Root>/Q_RADPS'
    //   Inport: '<Root>/R_RADPS'

    for (i = 0; i < 3; i++) {
      rtb_Sum_hp[i] = (rtb_VectorConcatenate2_f[i + 3] * *arg_Q_RADPS +
                       rtb_VectorConcatenate2_f[i] * *arg_P_RADPS) +
        rtb_VectorConcatenate2_f[i + 6] * *arg_R_RADPS;
    }

    // End of Product: '<S6>/Matrix Multiply'

    // DiscreteIntegrator: '<S40>/Integrator1'
    rtb_CMD_DOT_REF = CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE;

    // Gain: '<S40>/Gain2' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion20'
    //   Inport: '<Root>/ROLL_ANGLE_REF_ZETA'

    rtb_REF_K3_i = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain2_Gain *
      *arg_ROLL_ANGLE_REF_ZETA;

    // Gain: '<S40>/Gain3' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion22'
    //   Inport: '<Root>/ROLL_ANGLE_REF_W0_RADPS'

    rtb_REF_K3 = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain3_Gain *
      *arg_ROLL_ANGLE_REF_W0_RADPS;

    // Product: '<S40>/Product5' incorporates:
    //   Gain: '<S40>/Gain1'

    rtb_CMD_DOT_DES_SAT = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain *
      rtb_REF_K3_i * rtb_REF_K3;

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   Product: '<S40>/Product6'

    rtb_DataTypeConversion6 = 1.0 / rtb_CMD_DOT_DES_SAT;

    // Product: '<S40>/Product7' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion26'
    //   Inport: '<Root>/ROLL_ANGULAR_RATE_REF_K3'

    rtb_Product7 = *arg_ROLL_ANGULAR_RATE_REF_K3 * rtb_DataTypeConversion6;

    // Product: '<S40>/Product4' incorporates:
    //   Gain: '<S40>/Gain'

    rtb_REF_K1 = 1.0 / rtb_REF_K3_i *
      (CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_m * rtb_REF_K3);

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion19'
    //   Inport: '<Root>/ROLL_ANGLE_REF_KFF'

    rtb_DataTypeConversion6 = *arg_ROLL_ANGLE_REF_KFF;

    // DiscreteIntegrator: '<S36>/Integrator1'
    rtb_REF_K3 = CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_l;

    // Product: '<S36>/Product5' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion20'
    //   DataTypeConversion: '<Root>/Data Type Conversion22'
    //   Gain: '<S36>/Gain1'
    //   Inport: '<Root>/ROLL_ANGLE_REF_W0_RADPS'
    //   Inport: '<Root>/ROLL_ANGLE_REF_ZETA'

    rtb_REF_K3_i = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_m *
      *arg_ROLL_ANGLE_REF_ZETA * *arg_ROLL_ANGLE_REF_W0_RADPS;

    // Product: '<S36>/Product1' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion20'
    //   DataTypeConversion: '<Root>/Data Type Conversion22'
    //   DataTypeConversion: '<Root>/Data Type Conversion8'
    //   DiscreteIntegrator: '<S36>/Integrator'
    //   Gain: '<S36>/Gain'
    //   Inport: '<Root>/ROLL_ANGLE_REF_W0_RADPS'
    //   Inport: '<Root>/ROLL_ANGLE_REF_ZETA'
    //   Inport: '<Root>/ROLL_ATT_CMD_DEG'
    //   Product: '<S36>/Product4'
    //   Sum: '<S36>/Sum'

    rtb_VER_VEL_REF_W0_RADPS = 1.0 / *arg_ROLL_ANGLE_REF_ZETA *
      (CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_l *
       *arg_ROLL_ANGLE_REF_W0_RADPS) * (*arg_ROLL_ATT_CMD_DEG -
      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE);

    // Saturate: '<S36>/Saturation'
    if (rtb_VER_VEL_REF_W0_RADPS >
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.ROLL.ATT.REF.DOTMAX) {
      rtb_VER_VEL_REF_W0_RADPS =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.ROLL.ATT.REF.DOTMAX;
    } else if (rtb_VER_VEL_REF_W0_RADPS <
               CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.ROLL.ATT.REF.DOTMIN) {
      rtb_VER_VEL_REF_W0_RADPS =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.ROLL.ATT.REF.DOTMIN;
    }

    // Product: '<S36>/Product2' incorporates:
    //   DiscreteIntegrator: '<S36>/Integrator1'
    //   Saturate: '<S36>/Saturation'
    //   Sum: '<S36>/Sum1'

    rtb_CMD_DDOT_REF = (rtb_VER_VEL_REF_W0_RADPS -
                        CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_l) *
      rtb_REF_K3_i;

    // Saturate: '<S36>/Saturation1'
    if (rtb_CMD_DDOT_REF >
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.ROLL.ATT.REF.DDOTMAX) {
      rtb_CMD_DDOT_REF =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.ROLL.ATT.REF.DDOTMAX;
    } else if (rtb_CMD_DDOT_REF <
               CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.ROLL.ATT.REF.DDOTMIN) {
      rtb_CMD_DDOT_REF =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.ROLL.ATT.REF.DDOTMIN;
    }

    // End of Saturate: '<S36>/Saturation1'

    // Product: '<S36>/Product' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion21'
    //   DiscreteIntegrator: '<S36>/Integrator1'
    //   Inport: '<Root>/ROLL_ANGLE_REF_K3'
    //   Product: '<S36>/Product3'
    //   Product: '<S36>/Product6'
    //   Product: '<S36>/Product7'
    //   Sum: '<S36>/Sum2'

    rtb_REF_K3_i = (1.0 / rtb_REF_K3_i * *arg_ROLL_ANGLE_REF_K3 *
                    rtb_CMD_DDOT_REF +
                    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_l) *
      rtb_DataTypeConversion6;

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion3'
    //   Gain: '<S34>/Gain'
    //   Inport: '<Root>/PHI_RAD'

    rtb_DataTypeConversion6 = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_o *
      *arg_PHI_RAD;

    // Sum: '<S35>/Sum' incorporates:
    //   DiscreteIntegrator: '<S36>/Integrator'

    rtb_Sum_h = CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE -
      rtb_DataTypeConversion6;

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion18'
    //   DiscreteIntegrator: '<S40>/Integrator'
    //   Inport: '<Root>/ROLL_ANGLE_ERR_Kp 1'
    //   Product: '<S35>/Product'
    //   Product: '<S40>/Product1'
    //   Sum: '<S32>/Sum'
    //   Sum: '<S40>/Sum'

    rtb_DataTypeConversion6 = *arg_ROLL_ANGLE_ERR_Kp_1;
    rtb_DataTypeConversion6 = ((rtb_Sum_h * rtb_DataTypeConversion6 +
      rtb_REF_K3_i) - CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_e) *
      rtb_REF_K1;

    // Saturate: '<S40>/Saturation'
    if (rtb_DataTypeConversion6 >
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.ROLL.ATT.REF.DOTMAX) {
      // DataTypeConversion: '<Root>/Data Type Conversion6'
      rtb_DataTypeConversion6 =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.ROLL.ATT.REF.DOTMAX;
    } else if (rtb_DataTypeConversion6 <
               CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.ROLL.ATT.REF.DOTMIN) {
      // DataTypeConversion: '<Root>/Data Type Conversion6'
      rtb_DataTypeConversion6 =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.ROLL.ATT.REF.DOTMIN;
    }

    // End of Saturate: '<S40>/Saturation'

    // Product: '<S40>/Product2' incorporates:
    //   DiscreteIntegrator: '<S40>/Integrator1'
    //   Sum: '<S40>/Sum1'

    rtb_CMD_DOT_DES_SAT *= rtb_DataTypeConversion6 -
      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE;

    // Saturate: '<S40>/Saturation1'
    if (rtb_CMD_DOT_DES_SAT >
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.ROLL.ATT.REF.DDOTMAX) {
      rtb_CMD_DOT_DES_SAT =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.ROLL.ATT.REF.DDOTMAX;
    } else if (rtb_CMD_DOT_DES_SAT <
               CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.ROLL.ATT.REF.DDOTMIN) {
      rtb_CMD_DOT_DES_SAT =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.ROLL.ATT.REF.DDOTMIN;
    }

    // End of Saturate: '<S40>/Saturation1'

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   Gain: '<S41>/Gain'

    rtb_DataTypeConversion6 = rtb_Sum_g *
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_i;

    // Sum: '<S38>/Sum' incorporates:
    //   DiscreteIntegrator: '<S40>/Integrator'

    rtb_Sum_g = CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_e -
      rtb_DataTypeConversion6;

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion23'
    //   Inport: '<Root>/ROLL_ANGULAR_RATE_ERR_Kp '

    rtb_DataTypeConversion6 = *arg_ROLL_ANGULAR_RATE_ERR_Kp_;

    // Product: '<S38>/Product'
    rtb_Product_i = rtb_Sum_g * rtb_DataTypeConversion6;

    // DiscreteZeroPole: '<S42>/Discrete Zero-Pole'
    {
      rtb_DataTypeConversion6 =
        CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_D*rtb_Product_i;
    }

    // Gain: '<S37>/Gain1' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion24'
    //   DiscreteIntegrator: '<S40>/Integrator1'
    //   Inport: '<Root>/ROLL_ANGUALR_RATE_REF_KFF'
    //   Product: '<S40>/Product'
    //   Product: '<S40>/Product3'
    //   Sum: '<S33>/Sum'
    //   Sum: '<S40>/Sum2'

    rtb_Sum_h = ((rtb_Product7 * rtb_CMD_DOT_DES_SAT +
                  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE) *
                 *arg_ROLL_ANGUALR_RATE_REF_KFF + rtb_DataTypeConversion6) *
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_c;

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion34'
    //   Inport: '<Root>/PITCH_ANGULAR_RATE_REF_KFF'

    rtb_DataTypeConversion6 = *arg_PITCH_ANGULAR_RATE_REF_KFF;

    // DiscreteIntegrator: '<S29>/Integrator1'
    rtb_Sum_g = CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_m;

    // Gain: '<S29>/Gain2' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion30'
    //   Inport: '<Root>/PITCH_ANGLE_REF_ZETA'

    rtb_VER_VEL_REF_W0_RADPS = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain2_Gain_e *
      *arg_PITCH_ANGLE_REF_ZETA;

    // Gain: '<S29>/Gain3' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion32'
    //   Inport: '<Root>/PITCH_ANGLE_REF_W0_RADPS'

    rtb_REF_K3_i = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain3_Gain_i *
      *arg_PITCH_ANGLE_REF_W0_RADPS;

    // Product: '<S29>/Product5' incorporates:
    //   Gain: '<S29>/Gain1'

    rtb_CMD_DDOT_DES_o = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_m2 *
      rtb_VER_VEL_REF_W0_RADPS * rtb_REF_K3_i;

    // Product: '<S29>/Product4' incorporates:
    //   Gain: '<S29>/Gain'

    rtb_REF_K1_k = 1.0 / rtb_VER_VEL_REF_W0_RADPS *
      (CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_f1 * rtb_REF_K3_i);

    // DiscreteIntegrator: '<S25>/Integrator1'
    rtb_Product7 = CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_j;

    // Product: '<S25>/Product5' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion30'
    //   DataTypeConversion: '<Root>/Data Type Conversion32'
    //   Gain: '<S25>/Gain1'
    //   Inport: '<Root>/PITCH_ANGLE_REF_W0_RADPS'
    //   Inport: '<Root>/PITCH_ANGLE_REF_ZETA'

    rtb_REF_K3_i = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_c5 *
      *arg_PITCH_ANGLE_REF_ZETA * *arg_PITCH_ANGLE_REF_W0_RADPS;

    // Product: '<S25>/Product1' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion30'
    //   DataTypeConversion: '<Root>/Data Type Conversion32'
    //   DataTypeConversion: '<Root>/Data Type Conversion9'
    //   DiscreteIntegrator: '<S25>/Integrator'
    //   Gain: '<S25>/Gain'
    //   Inport: '<Root>/PITCH_ANGLE_REF_W0_RADPS'
    //   Inport: '<Root>/PITCH_ANGLE_REF_ZETA'
    //   Inport: '<Root>/PITCH_ATT_CMD_DEG'
    //   Product: '<S25>/Product4'
    //   Sum: '<S25>/Sum'

    rtb_VER_VEL_REF_W0_RADPS = 1.0 / *arg_PITCH_ANGLE_REF_ZETA *
      (CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_d *
       *arg_PITCH_ANGLE_REF_W0_RADPS) * (*arg_PITCH_ATT_CMD_DEG -
      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_m);

    // Saturate: '<S25>/Saturation'
    if (rtb_VER_VEL_REF_W0_RADPS >
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.PITCH.ATT.REF.DOTMAX) {
      rtb_VER_VEL_REF_W0_RADPS =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.PITCH.ATT.REF.DOTMAX;
    } else if (rtb_VER_VEL_REF_W0_RADPS <
               CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.PITCH.ATT.REF.DOTMIN) {
      rtb_VER_VEL_REF_W0_RADPS =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.PITCH.ATT.REF.DOTMIN;
    }

    // Product: '<S25>/Product2' incorporates:
    //   DiscreteIntegrator: '<S25>/Integrator1'
    //   Saturate: '<S25>/Saturation'
    //   Sum: '<S25>/Sum1'

    rtb_REF_K1 = (rtb_VER_VEL_REF_W0_RADPS -
                  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_j) *
      rtb_REF_K3_i;

    // Saturate: '<S25>/Saturation1'
    if (rtb_REF_K1 >
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.PITCH.ATT.REF.DDOTMAX) {
      rtb_REF_K1 =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.PITCH.ATT.REF.DDOTMAX;
    } else if (rtb_REF_K1 <
               CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.PITCH.ATT.REF.DDOTMIN) {
      rtb_REF_K1 =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.PITCH.ATT.REF.DDOTMIN;
    }

    // End of Saturate: '<S25>/Saturation1'

    // Product: '<S29>/Product1' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion28'
    //   DataTypeConversion: '<Root>/Data Type Conversion29'
    //   DataTypeConversion: '<Root>/Data Type Conversion31'
    //   DataTypeConversion: '<Root>/Data Type Conversion4'
    //   DiscreteIntegrator: '<S25>/Integrator'
    //   DiscreteIntegrator: '<S25>/Integrator1'
    //   DiscreteIntegrator: '<S29>/Integrator'
    //   Gain: '<S23>/Gain'
    //   Inport: '<Root>/PITCH_ANGLE_ERR_Kp 2'
    //   Inport: '<Root>/PITCH_ANGLE_REF_K3'
    //   Inport: '<Root>/PITCH_ANGLE_REF_KFF'
    //   Inport: '<Root>/THETA_RAD'
    //   Product: '<S24>/Product'
    //   Product: '<S25>/Product'
    //   Product: '<S25>/Product3'
    //   Product: '<S25>/Product6'
    //   Product: '<S25>/Product7'
    //   Sum: '<S21>/Sum'
    //   Sum: '<S24>/Sum'
    //   Sum: '<S25>/Sum2'
    //   Sum: '<S29>/Sum'

    rtb_VER_VEL_REF_W0_RADPS = (((1.0 / rtb_REF_K3_i * *arg_PITCH_ANGLE_REF_K3 *
      rtb_REF_K1 + CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_j) *
      *arg_PITCH_ANGLE_REF_KFF +
      (CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_m -
       CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_b * *arg_THETA_RAD) *
      *arg_PITCH_ANGLE_ERR_Kp_2) -
      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_mg) * rtb_REF_K1_k;

    // Saturate: '<S29>/Saturation'
    if (rtb_VER_VEL_REF_W0_RADPS >
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.PITCH.ATT.REF.DOTMAX) {
      rtb_VER_VEL_REF_W0_RADPS =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.PITCH.ATT.REF.DOTMAX;
    } else if (rtb_VER_VEL_REF_W0_RADPS <
               CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.PITCH.ATT.REF.DOTMIN) {
      rtb_VER_VEL_REF_W0_RADPS =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.PITCH.ATT.REF.DOTMIN;
    }

    // Product: '<S29>/Product2' incorporates:
    //   DiscreteIntegrator: '<S29>/Integrator1'
    //   Saturate: '<S29>/Saturation'
    //   Sum: '<S29>/Sum1'

    rtb_REF_K3_i = (rtb_VER_VEL_REF_W0_RADPS -
                    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_m) *
      rtb_CMD_DDOT_DES_o;

    // Saturate: '<S29>/Saturation1'
    if (rtb_REF_K3_i >
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.PITCH.ATT.REF.DDOTMAX) {
      rtb_REF_K3_i =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.PITCH.ATT.REF.DDOTMAX;
    } else if (rtb_REF_K3_i <
               CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.PITCH.ATT.REF.DDOTMIN) {
      rtb_REF_K3_i =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.PITCH.ATT.REF.DDOTMIN;
    }

    // End of Saturate: '<S29>/Saturation1'

    // Product: '<S29>/Product' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion36'
    //   DiscreteIntegrator: '<S29>/Integrator1'
    //   Inport: '<Root>/PITCH_ANGULAR_RATE_REF_K3'
    //   Product: '<S29>/Product3'
    //   Product: '<S29>/Product6'
    //   Product: '<S29>/Product7'
    //   Sum: '<S29>/Sum2'

    rtb_VER_VEL_REF_W0_RADPS = (1.0 / rtb_CMD_DDOT_DES_o *
      *arg_PITCH_ANGULAR_RATE_REF_K3 * rtb_REF_K3_i +
      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_m) *
      rtb_DataTypeConversion6;

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   Gain: '<S30>/Gain'

    rtb_DataTypeConversion6 = rtb_Sum_ct *
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_f2;

    // Sum: '<S27>/Sum' incorporates:
    //   DiscreteIntegrator: '<S29>/Integrator'

    rtb_Sum_ct = CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_mg -
      rtb_DataTypeConversion6;

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion33'
    //   Inport: '<Root>/PITCH_ANGULAR_RATE_ERR_Kp '

    rtb_DataTypeConversion6 = *arg_PITCH_ANGULAR_RATE_ERR_Kp_;

    // Product: '<S27>/Product'
    rtb_Product_f = rtb_Sum_ct * rtb_DataTypeConversion6;

    // DiscreteZeroPole: '<S31>/Discrete Zero-Pole'
    {
      rtb_DataTypeConversion6 =
        (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_C_j[0])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_f[0]
        + (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_C_j[1])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_f[1];
      rtb_DataTypeConversion6 +=
        CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_D_f*rtb_Product_f;
    }

    // Gain: '<S26>/Gain1' incorporates:
    //   Sum: '<S22>/Sum'

    rtb_REF_K1_k = (rtb_VER_VEL_REF_W0_RADPS + rtb_DataTypeConversion6) *
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_l;

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion39'
    //   Inport: '<Root>/YAW_ANGULAR_RATE_REF_KFF'

    rtb_DataTypeConversion6 = *arg_YAW_ANGULAR_RATE_REF_KFF;

    // DiscreteIntegrator: '<S46>/Integrator1'
    rtb_Sum_ct = CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_i;

    // Gain: '<S46>/Gain2' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion40'
    //   Inport: '<Root>/YAW_ANGULAR_RATE_REF_ZETA'

    rtb_CMD_DDOT_DES_o = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain2_Gain_k *
      *arg_YAW_ANGULAR_RATE_REF_ZETA;

    // Gain: '<S46>/Gain3' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion42'
    //   Inport: '<Root>/YAW_ANGULAR_RATE_REF_W0_RADPS'

    rtb_VER_VEL_REF_W0_RADPS = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain3_Gain_o *
      *arg_YAW_ANGULAR_RATE_REF_W0_RADPS;

    // Product: '<S46>/Product5' incorporates:
    //   Gain: '<S46>/Gain1'

    rtb_CMD_DDOT_DES = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_o *
      rtb_CMD_DDOT_DES_o * rtb_VER_VEL_REF_W0_RADPS;

    // Product: '<S46>/Product1' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion10'
    //   DiscreteIntegrator: '<S46>/Integrator'
    //   Gain: '<S46>/Gain'
    //   Inport: '<Root>/YAW_RATE_CMD_DEGPS'
    //   Product: '<S46>/Product4'
    //   Sum: '<S46>/Sum'

    rtb_VER_VEL_REF_W0_RADPS = 1.0 / rtb_CMD_DDOT_DES_o *
      (CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_oc * rtb_VER_VEL_REF_W0_RADPS) *
      (*arg_YAW_RATE_CMD_DEGPS -
       CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_d);

    // Saturate: '<S46>/Saturation'
    if (rtb_VER_VEL_REF_W0_RADPS >
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.YAW.ACC.REF.DOTMAX) {
      rtb_VER_VEL_REF_W0_RADPS =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.YAW.ACC.REF.DOTMAX;
    } else if (rtb_VER_VEL_REF_W0_RADPS <
               CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.YAW.ACC.REF.DOTMIN) {
      rtb_VER_VEL_REF_W0_RADPS =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.YAW.ACC.REF.DOTMIN;
    }

    // Product: '<S46>/Product2' incorporates:
    //   DiscreteIntegrator: '<S46>/Integrator1'
    //   Saturate: '<S46>/Saturation'
    //   Sum: '<S46>/Sum1'

    rtb_CMD_DDOT_DES_o = (rtb_VER_VEL_REF_W0_RADPS -
                          CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_i) *
      rtb_CMD_DDOT_DES;

    // Saturate: '<S46>/Saturation1'
    if (rtb_CMD_DDOT_DES_o >
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.YAW.ACC.REF.DDOTMAX) {
      rtb_CMD_DDOT_DES_o =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.YAW.ACC.REF.DDOTMAX;
    } else if (rtb_CMD_DDOT_DES_o <
               CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.YAW.ACC.REF.DDOTMIN) {
      rtb_CMD_DDOT_DES_o =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.YAW.ACC.REF.DDOTMIN;
    }

    // End of Saturate: '<S46>/Saturation1'

    // Product: '<S46>/Product' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion41'
    //   DiscreteIntegrator: '<S46>/Integrator1'
    //   Inport: '<Root>/YAW_ANGULAR_RATE_REF_K3'
    //   Product: '<S46>/Product3'
    //   Product: '<S46>/Product6'
    //   Product: '<S46>/Product7'
    //   Sum: '<S46>/Sum2'

    rtb_VER_VEL_REF_W0_RADPS = (1.0 / rtb_CMD_DDOT_DES *
      *arg_YAW_ANGULAR_RATE_REF_K3 * rtb_CMD_DDOT_DES_o +
      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_i) *
      rtb_DataTypeConversion6;

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   Fcn: '<S17>/dot psi'
    //   Gain: '<S47>/Gain'

    rtb_DataTypeConversion6 = rtb_Sum_ir / rtb_CMD_DDOT_REF_c *
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_a;

    // Sum: '<S44>/Sum' incorporates:
    //   DiscreteIntegrator: '<S46>/Integrator'

    rtb_Sum_ir = CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_d -
      rtb_DataTypeConversion6;

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion38'
    //   Inport: '<Root>/YAW_ANGULAR_RATE_ERR_Kp 2'

    rtb_DataTypeConversion6 = *arg_YAW_ANGULAR_RATE_ERR_Kp_2;

    // Product: '<S44>/Product'
    rtb_Product_p0 = rtb_Sum_ir * rtb_DataTypeConversion6;

    // DiscreteZeroPole: '<S48>/Discrete Zero-Pole'
    {
      rtb_DataTypeConversion6 =
        (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_C_l[0])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_b[0]
        + (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_C_l[1])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_b[1];
      rtb_DataTypeConversion6 +=
        CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_D_e*rtb_Product_p0;
    }

    // Gain: '<S43>/Gain1' incorporates:
    //   Sum: '<S20>/Sum'

    rtb_Sum_ir = (rtb_VER_VEL_REF_W0_RADPS + rtb_DataTypeConversion6) *
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_j;

    // Constant: '<S8>/Constant1'
    rtb_VectorConcatenate2_f[3] =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Constant1_Value_d;

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   Trigonometry: '<S8>/Cos'

    rtb_DataTypeConversion6 = rtb_Z_DDOT_MPS2;

    // SignalConversion generated from: '<S8>/Vector Concatenate'
    rtb_VectorConcatenate2_f[4] = rtb_DataTypeConversion6;

    // Gain: '<S8>/Gain'
    rtb_VectorConcatenate2_f[5] = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_h *
      rtb_CMD_DOT_REF_az;

    // Gain: '<S8>/Gain1'
    rtb_VectorConcatenate2_f[6] = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_cj *
      rtb_Product_pm;

    // Product: '<S8>/Product'
    rtb_VectorConcatenate2_f[7] = rtb_CMD_DOT_REF_az * rtb_CMD_DDOT_REF_c;

    // Product: '<S8>/Product1'
    rtb_VectorConcatenate2_f[8] = rtb_DataTypeConversion6 * rtb_CMD_DDOT_REF_c;

    // Constant: '<S8>/Constant'
    rtb_VectorConcatenate2_f[0] =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Constant_Value_p[0];

    // Sum: '<S6>/Sum'
    rtb_Sum_h -= rtb_Sum_hp[0];

    // Constant: '<S8>/Constant'
    rtb_VectorConcatenate2_f[1] =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Constant_Value_p[1];

    // Sum: '<S6>/Sum'
    rtb_REF_K1_k -= rtb_Sum_hp[1];

    // Constant: '<S8>/Constant'
    rtb_VectorConcatenate2_f[2] =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Constant_Value_p[2];

    // Sum: '<S6>/Sum'
    rtb_Sum_ir -= rtb_Sum_hp[2];

    // DataTypeConversion: '<Root>/Data Type Conversion25' incorporates:
    //   Concatenate: '<S8>/Vector Concatenate2'
    //   Product: '<S6>/Matrix Multiply1'

    for (i = 0; i < 3; i++) {
      rtb_DataTypeConversion25[i] = static_cast<real32_T>
        ((rtb_VectorConcatenate2_f[i + 3] * rtb_REF_K1_k +
          rtb_VectorConcatenate2_f[i] * rtb_Sum_h) + rtb_VectorConcatenate2_f[i
         + 6] * rtb_Sum_ir);
    }

    // End of DataTypeConversion: '<Root>/Data Type Conversion25'

    // Outport: '<Root>/P_DOT_CMD'
    CONSCALE_CON_TBATT_CONPARA_VE_Y.P_DOT_CMD = rtb_DataTypeConversion25[0];

    // Outport: '<Root>/Q_DOT_CMD'
    CONSCALE_CON_TBATT_CONPARA_VE_Y.Q_DOT_CMD = rtb_DataTypeConversion25[1];

    // Outport: '<Root>/R_DOT_CMD'
    CONSCALE_CON_TBATT_CONPARA_VE_Y.R_DOT_CMD = rtb_DataTypeConversion25[2];

    // Product: '<S4>/Product1'
    rtb_Z_DDOT_MPS2 = 1.0 / rtb_DataTypeConversion6 / rtb_CMD_DDOT_REF_c;

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion14'
    //   Inport: '<Root>/VER_VEL_REF_KFF'

    rtb_DataTypeConversion6 = *arg_VER_VEL_REF_KFF;

    // DiscreteIntegrator: '<S51>/Integrator1'
    rtb_CMD_DOT_REF_az = CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_g;

    // Product: '<S51>/Product5' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion15'
    //   DataTypeConversion: '<Root>/Data Type Conversion17'
    //   Gain: '<S51>/Gain1'
    //   Inport: '<Root>/VER_VEL_REF_W0_RADPS'
    //   Inport: '<Root>/VER_VEL_REF_ZETA'

    rtb_CMD_DDOT_DES = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_cp *
      *arg_VER_VEL_REF_ZETA * *arg_VER_VEL_REF_W0_RADPS;

    // Product: '<S51>/Product1' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion11'
    //   DataTypeConversion: '<Root>/Data Type Conversion15'
    //   DataTypeConversion: '<Root>/Data Type Conversion17'
    //   DiscreteIntegrator: '<S51>/Integrator'
    //   Gain: '<S51>/Gain'
    //   Inport: '<Root>/HDOT_CMD_MPS'
    //   Inport: '<Root>/VER_VEL_REF_W0_RADPS'
    //   Inport: '<Root>/VER_VEL_REF_ZETA'
    //   Product: '<S51>/Product4'
    //   Sum: '<S51>/Sum'

    rtb_VER_VEL_REF_W0_RADPS = 1.0 / *arg_VER_VEL_REF_ZETA *
      (CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_nl * *arg_VER_VEL_REF_W0_RADPS)
      * (*arg_HDOT_CMD_MPS - CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_n);

    // Saturate: '<S51>/Saturation'
    if (rtb_VER_VEL_REF_W0_RADPS >
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.HDOT.REF.DOTMAX) {
      rtb_VER_VEL_REF_W0_RADPS =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.HDOT.REF.DOTMAX;
    } else if (rtb_VER_VEL_REF_W0_RADPS <
               CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.HDOT.REF.DOTMIN) {
      rtb_VER_VEL_REF_W0_RADPS =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.HDOT.REF.DOTMIN;
    }

    // Product: '<S51>/Product2' incorporates:
    //   DiscreteIntegrator: '<S51>/Integrator1'
    //   Saturate: '<S51>/Saturation'
    //   Sum: '<S51>/Sum1'

    rtb_CMD_DDOT_REF_c = (rtb_VER_VEL_REF_W0_RADPS -
                          CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_g) *
      rtb_CMD_DDOT_DES;

    // Saturate: '<S51>/Saturation1'
    if (rtb_CMD_DDOT_REF_c >
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.HDOT.REF.DDOTMAX) {
      rtb_CMD_DDOT_REF_c =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.HDOT.REF.DDOTMAX;
    } else if (rtb_CMD_DDOT_REF_c <
               CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.HDOT.REF.DDOTMIN) {
      rtb_CMD_DDOT_REF_c =
        CONSCALE_CON_TBATT_CONPARA_VE_P.CONTBATT.HDOT.REF.DDOTMIN;
    }

    // End of Saturate: '<S51>/Saturation1'

    // Product: '<S51>/Product' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion16'
    //   DiscreteIntegrator: '<S51>/Integrator1'
    //   Inport: '<Root>/VER_VEL_REF_K3'
    //   Product: '<S51>/Product3'
    //   Product: '<S51>/Product6'
    //   Product: '<S51>/Product7'
    //   Sum: '<S51>/Sum2'

    rtb_Product_pm = (1.0 / rtb_CMD_DDOT_DES * *arg_VER_VEL_REF_K3 *
                      rtb_CMD_DDOT_REF_c +
                      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_g) *
      rtb_DataTypeConversion6;

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion7'
    //   Inport: '<Root>/H_DOT_MPS'

    rtb_DataTypeConversion6 = *arg_H_DOT_MPS;

    // Sum: '<S49>/Sum' incorporates:
    //   DiscreteIntegrator: '<S51>/Integrator'

    rtb_Sum_ir = CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_n -
      rtb_DataTypeConversion6;

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion13'
    //   Inport: '<Root>/VER_VEL_ERR_Kp '

    rtb_DataTypeConversion6 = *arg_VER_VEL_ERR_Kp_;

    // Product: '<S49>/Product'
    rtb_Product_d = rtb_Sum_ir * rtb_DataTypeConversion6;

    // DiscreteZeroPole: '<S52>/Discrete Zero-Pole'
    {
      rtb_DataTypeConversion6 =
        (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_C_d[0])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_h[0]
        + (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_C_d[1])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_h[1];
      rtb_DataTypeConversion6 +=
        CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_D_l*rtb_Product_d;
    }

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   Gain: '<S4>/Gain1'
    //   Product: '<S4>/Product'
    //   Sum: '<S5>/Sum'

    rtb_DataTypeConversion6 = (rtb_Product_pm + rtb_DataTypeConversion6) *
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_k * rtb_Z_DDOT_MPS2;

    // Outport: '<Root>/G_B_MPS2' incorporates:
    //   DataTypeConversion: '<Root>/Data Type Conversion12'

    CONSCALE_CON_TBATT_CONPARA_VE_Y.G_B_MPS2 = static_cast<real32_T>
      (rtb_DataTypeConversion6);

    // DataTypeConversion: '<Root>/Data Type Conversion6' incorporates:
    //   Inport: '<Root>/DF_FRR_DEG'

    rtb_DataTypeConversion6 = *arg_DF_FRR_DEG;

    // Outport: '<Root>/DF_FRR_DEGLIN' incorporates:
    //   Gain: '<Root>/Gain1'

    CONSCALE_CON_TBATT_CONPARA_VE_Y.DF_FRR_DEGLIN =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_mq * rtb_DataTypeConversion6;

    // Update for DiscreteIntegrator: '<S40>/Integrator1'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_gainval * rtb_CMD_DOT_DES_SAT;

    // Update for DiscreteIntegrator: '<S36>/Integrator1'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_l +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_gainval_j * rtb_CMD_DDOT_REF;

    // Update for DiscreteIntegrator: '<S36>/Integrator'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_gainval * rtb_REF_K3;

    // Update for DiscreteIntegrator: '<S40>/Integrator'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_e +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_gainval_p * rtb_CMD_DOT_REF;

    // Update for DiscreteZeroPole: '<S42>/Discrete Zero-Pole'
    {
      real_T xnew[2];
      xnew[0] = (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A[0])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE[0]
        + (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A[1])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE[1];
      xnew[0] += CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_B*
        rtb_Product_i;
      xnew[1] = (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A[2])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE[0];
      (void) std::memcpy
        (&CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE[0], xnew,
         sizeof(real_T)*2);
    }

    // Update for DiscreteIntegrator: '<S29>/Integrator1'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_m +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_gainval_a * rtb_REF_K3_i;

    // Update for DiscreteIntegrator: '<S25>/Integrator1'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_j +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_gainval_au * rtb_REF_K1;

    // Update for DiscreteIntegrator: '<S25>/Integrator'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_m +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_gainval_f * rtb_Product7;

    // Update for DiscreteIntegrator: '<S29>/Integrator'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_mg +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_gainval_g * rtb_Sum_g;

    // Update for DiscreteZeroPole: '<S31>/Discrete Zero-Pole'
    {
      real_T xnew[2];
      xnew[0] = (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_f[0])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_f[0]
        + (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_f[1])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_f[1];
      xnew[0] += CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_B_j*
        rtb_Product_f;
      xnew[1] = (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_f[2])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_f[0];
      (void) std::memcpy
        (&CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_f[0], xnew,
         sizeof(real_T)*2);
    }

    // Update for DiscreteIntegrator: '<S46>/Integrator1'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_i +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_gainval_e * rtb_CMD_DDOT_DES_o;

    // Update for DiscreteIntegrator: '<S46>/Integrator'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_d +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_gainval_b * rtb_Sum_ct;

    // Update for DiscreteZeroPole: '<S48>/Discrete Zero-Pole'
    {
      real_T xnew[2];
      xnew[0] = (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_m[0])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_b[0]
        + (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_m[1])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_b[1];
      xnew[0] += CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_B_p*
        rtb_Product_p0;
      xnew[1] = (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_m[2])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_b[0];
      (void) std::memcpy
        (&CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_b[0], xnew,
         sizeof(real_T)*2);
    }

    // Update for DiscreteIntegrator: '<S51>/Integrator1'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_g +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_gainval_l * rtb_CMD_DDOT_REF_c;

    // Update for DiscreteIntegrator: '<S51>/Integrator'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_n +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_gainval_m * rtb_CMD_DOT_REF_az;

    // Update for DiscreteZeroPole: '<S52>/Discrete Zero-Pole'
    {
      real_T xnew[2];
      xnew[0] = (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_l[0])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_h[0]
        + (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_l[1])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_h[1];
      xnew[0] += CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_B_e*
        rtb_Product_d;
      xnew[1] = (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_l[2])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_h[0];
      (void) std::memcpy
        (&CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_h[0], xnew,
         sizeof(real_T)*2);
    }
  }

  rate_scheduler((&CONSCALE_CON_TBATT_CONPARA_V_M));

  // Copy value for root outport '<Root>/DF_FRR_DEGLIN' since it is accessed globally 
  arg_DF_FRR_DEGLIN = CONSCALE_CON_TBATT_CONPARA_VE_Y.DF_FRR_DEGLIN;

  // Copy value for root outport '<Root>/P_DOT_CMD' since it is accessed globally 
  arg_P_DOT_CMD = CONSCALE_CON_TBATT_CONPARA_VE_Y.P_DOT_CMD;

  // Copy value for root outport '<Root>/Q_DOT_CMD' since it is accessed globally 
  arg_Q_DOT_CMD = CONSCALE_CON_TBATT_CONPARA_VE_Y.Q_DOT_CMD;

  // Copy value for root outport '<Root>/R_DOT_CMD' since it is accessed globally 
  arg_R_DOT_CMD = CONSCALE_CON_TBATT_CONPARA_VE_Y.R_DOT_CMD;

  // Copy value for root outport '<Root>/G_B_MPS2' since it is accessed globally 
  arg_G_B_MPS2 = CONSCALE_CON_TBATT_CONPARA_VE_Y.G_B_MPS2;
}

// Model initialize function
void CONFULL_CON_TBATT_CONPARA_VECTORModelClass::initialize()
{
  // InitializeConditions for DiscreteIntegrator: '<S40>/Integrator1'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_IC;

  // InitializeConditions for DiscreteIntegrator: '<S36>/Integrator1'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_l =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_IC_c;

  // InitializeConditions for DiscreteIntegrator: '<S36>/Integrator'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_IC;

  // InitializeConditions for DiscreteIntegrator: '<S40>/Integrator'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_e =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_IC_n;

  // InitializeConditions for DiscreteIntegrator: '<S29>/Integrator1'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_m =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_IC_e;

  // InitializeConditions for DiscreteIntegrator: '<S25>/Integrator1'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_j =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_IC_l;

  // InitializeConditions for DiscreteIntegrator: '<S25>/Integrator'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_m =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_IC_c;

  // InitializeConditions for DiscreteIntegrator: '<S29>/Integrator'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_mg =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_IC_i;

  // InitializeConditions for DiscreteIntegrator: '<S46>/Integrator1'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_i =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_IC_i;

  // InitializeConditions for DiscreteIntegrator: '<S46>/Integrator'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_d =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_IC_h;

  // InitializeConditions for DiscreteIntegrator: '<S51>/Integrator1'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_g =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_IC_lz;

  // InitializeConditions for DiscreteIntegrator: '<S51>/Integrator'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_n =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_IC_e;
}

// Model terminate function
void CONFULL_CON_TBATT_CONPARA_VECTORModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
CONFULL_CON_TBATT_CONPARA_VECTORModelClass::
  CONFULL_CON_TBATT_CONPARA_VECTORModelClass() :
  CONSCALE_CON_TBATT_CONPARA_VE_Y(),
  CONSCALE_CON_TBATT_CONPARA_V_DW(),
  CONSCALE_CON_TBATT_CONPARA_V_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
// Currently there is no destructor body generated.
CONFULL_CON_TBATT_CONPARA_VECTORModelClass::
  ~CONFULL_CON_TBATT_CONPARA_VECTORModelClass() = default;

// Real-Time Model get method
CONFULL_CON_TBATT_CONPARA_VECTORModelClass::RT_MODEL_CONSCALE_CON_TBATT_C_T
  * CONFULL_CON_TBATT_CONPARA_VECTORModelClass::getRTM()
{
  return (&CONSCALE_CON_TBATT_CONPARA_V_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
