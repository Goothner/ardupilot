//
// File: CONSCALE_CON_TBATT_CONPARA_VECTOR.cpp
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

static void rate_scheduler(RT_MODEL_CONSCALE_CON_TBATT_C_T *const
  CONSCALE_CON_TBATT_CONPARA_V_M);

//
//   This function updates active task flag for each subrate.
// The function is called at model base rate, hence the
// generated code self-manages all its subrates.
//
static void rate_scheduler(RT_MODEL_CONSCALE_CON_TBATT_C_T *const
  CONSCALE_CON_TBATT_CONPARA_V_M)
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
void CONFULL_CON_TBATT_CONPARA_VECTORModelClass::step(const real32_T * const arg_DF_FRR_DEG, real32_T *arg_P_RADPS,
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
            &arg_P_DOT_CMD_DEGPS2, real32_T &arg_Q_DOT_CMD_DEGPS2, real32_T &arg_R_DOT_CMD_DEGPS2, real32_T
            &arg_G_B_MPS2)
{
  // local block i/o variables
  real32_T rtb_Product_i;
  real32_T rtb_Product_b;
  real32_T rtb_Product_d;
  real32_T rtb_Product_e;
  real32_T rtb_DiscreteZeroPole;
  real32_T rtb_REF_K3;
  real32_T rtb_Cos3;
  real32_T rtb_CMD_DDOT_DES;
  real32_T rtb_VectorConcatenate2_h[9];
  real32_T rtb_REF_K1;
  real32_T rtb_Product7_b;
  real32_T rtb_CMD_DDOT_REF;
  real32_T rtb_REF_K1_e;
  real32_T rtb_Product7_aq;
  real32_T rtb_CMD_DDOT_REF_h;
  real32_T rtb_CMD_DDOT_REF_l;
  real32_T rtb_Product_hb;
  real32_T rtb_VectorConcatenate2[3];
  real32_T rtb_Cos_k[3];
  real32_T rtb_CMD_DOT_REF;
  real32_T rtb_CMD_DOT_REF_cm;
  real32_T rtb_CMD_DOT_REF_e;
  int32_T i;
  real32_T rtb_VectorConcatenate_idx_0;
  real32_T rtb_VectorConcatenate_idx_1;
  real32_T rtb_Sin_idx_0_tmp;
  real32_T rtb_VectorConcatenate2_tmp;
  real32_T rtb_DiscreteZeroPole_tmp;
  if ((&CONSCALE_CON_TBATT_CONPARA_V_M)->Timing.TaskCounters.TID[1] == 0) {
    // Trigonometry: '<S18>/Sin' incorporates:
    //   Inport: '<Root>/PHI_RAD'
    //   Trigonometry: '<S19>/Sin3'
    //   Trigonometry: '<S20>/Sin'

    rtb_CMD_DDOT_REF_l = std::sin(*arg_PHI_RAD);

    // Trigonometry: '<S18>/Cos' incorporates:
    //   Inport: '<Root>/PHI_RAD'
    //   Inport: '<Root>/THETA_RAD'
    //   Trigonometry: '<S11>/Cos'
    //   Trigonometry: '<S19>/Sin1'
    //   Trigonometry: '<S19>/Sin2'
    //   Trigonometry: '<S20>/Cos'

    rtb_Sin_idx_0_tmp = std::cos(*arg_PHI_RAD);
    rtb_VectorConcatenate2_tmp = std::cos
      (*arg_THETA_RAD);

    // Trigonometry: '<S18>/Sin' incorporates:
    //   Inport: '<Root>/THETA_RAD'
    //   Trigonometry: '<S19>/Sin'
    //   Trigonometry: '<S20>/Sin'

    rtb_Product_hb = std::sin(*arg_THETA_RAD);

    // Fcn: '<S18>/dot phi' incorporates:
    //   Inport: '<Root>/P_RADPS'
    //   Inport: '<Root>/Q_RADPS'
    //   Inport: '<Root>/R_RADPS'
    //   Trigonometry: '<S18>/Cos'
    //   Trigonometry: '<S18>/Sin'

    rtb_VectorConcatenate2[0] = (*arg_Q_RADPS *
      rtb_CMD_DDOT_REF_l + *arg_R_RADPS *
      rtb_Sin_idx_0_tmp) * (rtb_Product_hb / rtb_VectorConcatenate2_tmp) +
      *arg_P_RADPS;

    // Fcn: '<S18>/dot theta' incorporates:
    //   Inport: '<Root>/Q_RADPS'
    //   Inport: '<Root>/R_RADPS'
    //   Trigonometry: '<S18>/Cos'
    //   Trigonometry: '<S18>/Sin'

    rtb_VectorConcatenate2[1] = *arg_Q_RADPS *
      rtb_Sin_idx_0_tmp - *arg_R_RADPS *
      rtb_CMD_DDOT_REF_l;

    // Constant: '<S10>/Constant'
    rtb_VectorConcatenate2_h[0] =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Constant_Value[0];
    rtb_VectorConcatenate2_h[1] =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Constant_Value[1];
    rtb_VectorConcatenate2_h[2] =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Constant_Value[2];

    // Product: '<S12>/Product1' incorporates:
    //   Product: '<S14>/Product3'
    //   Product: '<S16>/Product3'

    rtb_CMD_DOT_REF = rtb_VectorConcatenate2[0] * rtb_Sin_idx_0_tmp;
    rtb_DiscreteZeroPole_tmp = rtb_CMD_DOT_REF * rtb_VectorConcatenate2_tmp;
    rtb_DiscreteZeroPole = rtb_DiscreteZeroPole_tmp * rtb_Product_hb;

    // Product: '<S12>/Product3' incorporates:
    //   Product: '<S14>/Product1'

    rtb_Cos3 = rtb_VectorConcatenate2[1] * rtb_CMD_DDOT_REF_l;

    // Math: '<S12>/Square' incorporates:
    //   Math: '<S14>/Square'
    //   Math: '<S15>/Square'
    //   Math: '<S17>/Square'

    rtb_CMD_DOT_REF_cm = rtb_VectorConcatenate2_tmp * rtb_VectorConcatenate2_tmp;

    // Product: '<S12>/Product2' incorporates:
    //   Math: '<S12>/Square'
    //   Product: '<S12>/Product3'
    //   Sum: '<S12>/Sum'

    rtb_VectorConcatenate2_h[3] = (rtb_Cos3 + rtb_DiscreteZeroPole) /
      rtb_CMD_DOT_REF_cm;

    // Product: '<S13>/Product3'
    rtb_DiscreteZeroPole = rtb_VectorConcatenate2[0] * rtb_CMD_DDOT_REF_l;

    // Gain: '<S13>/Gain'
    rtb_VectorConcatenate2_h[4] = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain *
      rtb_DiscreteZeroPole;

    // Product: '<S14>/Product3'
    rtb_DiscreteZeroPole = rtb_DiscreteZeroPole_tmp;

    // Product: '<S14>/Product2' incorporates:
    //   Product: '<S14>/Product1'
    //   Sum: '<S14>/Sum'

    rtb_VectorConcatenate2_h[5] = (rtb_Cos3 * rtb_Product_hb +
      rtb_DiscreteZeroPole) / rtb_CMD_DOT_REF_cm;

    // Product: '<S15>/Product3' incorporates:
    //   Product: '<S17>/Product1'

    rtb_DiscreteZeroPole_tmp = rtb_VectorConcatenate2[1] * rtb_Sin_idx_0_tmp;
    rtb_DiscreteZeroPole = rtb_DiscreteZeroPole_tmp;

    // Product: '<S15>/Product1' incorporates:
    //   Product: '<S17>/Product3'

    rtb_Cos3 = rtb_VectorConcatenate2[0] * rtb_VectorConcatenate2_tmp *
      rtb_CMD_DDOT_REF_l;

    // Product: '<S15>/Product2' incorporates:
    //   Product: '<S15>/Product1'
    //   Sum: '<S15>/Sum'

    rtb_VectorConcatenate2_h[6] = (rtb_DiscreteZeroPole - rtb_Cos3 *
      rtb_Product_hb) / rtb_CMD_DOT_REF_cm;

    // Product: '<S16>/Product3'
    rtb_DiscreteZeroPole = rtb_CMD_DOT_REF;

    // Gain: '<S16>/Gain'
    rtb_VectorConcatenate2_h[7] = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_d *
      rtb_DiscreteZeroPole;

    // Gain: '<S17>/Gain' incorporates:
    //   Product: '<S17>/Product1'
    //   Product: '<S17>/Product2'
    //   Sum: '<S17>/Sum'

    rtb_VectorConcatenate2_h[8] = (rtb_Cos3 - rtb_DiscreteZeroPole_tmp *
      rtb_Product_hb) / rtb_CMD_DOT_REF_cm *
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_i;

    // Product: '<S9>/Matrix Multiply' incorporates:
    //   Inport: '<Root>/P_RADPS'
    //   Inport: '<Root>/Q_RADPS'
    //   Inport: '<Root>/R_RADPS'

    for (i = 0; i < 3; i++) {
      rtb_VectorConcatenate2[i] = rtb_VectorConcatenate2_h[i + 6] *
        *arg_R_RADPS + (rtb_VectorConcatenate2_h[i +
        3] * *arg_Q_RADPS +
        rtb_VectorConcatenate2_h[i] * *arg_P_RADPS);
    }

    // End of Product: '<S9>/Matrix Multiply'

    // DiscreteIntegrator: '<S43>/Integrator1'
    rtb_CMD_DOT_REF = CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE;

    // Gain: '<S43>/Gain2' incorporates:
    //   Inport: '<Root>/ROLL_ANGLE_REF_ZETA'

    rtb_DiscreteZeroPole = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain2_Gain *
      CONSCALE_CON_TBATT_CONPARA_VE_U.ROLL_ANGLE_REF_ZETA;

    // Gain: '<S43>/Gain3' incorporates:
    //   Inport: '<Root>/ROLL_ANGLE_REF_W0_RADPS'

    rtb_CMD_DDOT_DES = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain3_Gain *
      CONSCALE_CON_TBATT_CONPARA_VE_U.ROLL_ANGLE_REF_W0_RADPS;

    // Product: '<S43>/Product5' incorporates:
    //   Gain: '<S43>/Gain1'

    rtb_Cos3 = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain * rtb_DiscreteZeroPole
      * rtb_CMD_DDOT_DES;

    // Product: '<S43>/Product6'
    rtb_REF_K3 = 1.0F / rtb_Cos3;

    // Product: '<S43>/Product4' incorporates:
    //   Gain: '<S43>/Gain'

    rtb_REF_K1 = 1.0F / rtb_DiscreteZeroPole *
      (CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_c * rtb_CMD_DDOT_DES);

    // DiscreteIntegrator: '<S39>/Integrator1'
    rtb_CMD_DOT_REF_cm = CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_n;

    // Product: '<S39>/Product5' incorporates:
    //   Gain: '<S39>/Gain1'
    //   Inport: '<Root>/ROLL_ANGLE_REF_W0_RADPS'
    //   Inport: '<Root>/ROLL_ANGLE_REF_ZETA'

    rtb_DiscreteZeroPole = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_h *
      CONSCALE_CON_TBATT_CONPARA_VE_U.ROLL_ANGLE_REF_ZETA *
      CONSCALE_CON_TBATT_CONPARA_VE_U.ROLL_ANGLE_REF_W0_RADPS;

    // Product: '<S39>/Product7' incorporates:
    //   Inport: '<Root>/ROLL_ANGLE_REF_K3'
    //   Product: '<S39>/Product6'

    rtb_Product7_b = 1.0F / rtb_DiscreteZeroPole *
      CONSCALE_CON_TBATT_CONPARA_VE_U.ROLL_ANGLE_REF_K3;

    // Product: '<S39>/Product1' incorporates:
    //   DiscreteIntegrator: '<S39>/Integrator'
    //   Gain: '<Root>/Gain'
    //   Gain: '<Root>/Gain3'
    //   Gain: '<S39>/Gain'
    //   Inport: '<Root>/ROLL_ANGLE_REF_W0_RADPS'
    //   Inport: '<Root>/ROLL_ANGLE_REF_ZETA'
    //   Inport: '<Root>/STICK.PWM.LAT'
    //   Product: '<S39>/Product4'
    //   Sum: '<S39>/Sum'

    rtb_CMD_DDOT_DES = (CONSCALE_CON_TBATT_CONPARA_VE_P.Gain3_Gain_i *
                        CONSCALE_CON_TBATT_CONPARA_VE_U.STICKPWMLAT *
                        CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_m -
                        CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE) *
      (1.0F / CONSCALE_CON_TBATT_CONPARA_VE_U.ROLL_ANGLE_REF_ZETA *
       (CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_cl *
        CONSCALE_CON_TBATT_CONPARA_VE_U.ROLL_ANGLE_REF_W0_RADPS));

    // Saturate: '<S39>/Saturation'
    if (rtb_CMD_DDOT_DES > CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_UpperSat)
    {
      rtb_CMD_DDOT_DES = CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_UpperSat;
    } else {
      if (rtb_CMD_DDOT_DES < CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_LowerSat)
      {
        rtb_CMD_DDOT_DES = CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_LowerSat;
      }
    }

    // End of Saturate: '<S39>/Saturation'

    // Product: '<S39>/Product2' incorporates:
    //   DiscreteIntegrator: '<S39>/Integrator1'
    //   Sum: '<S39>/Sum1'

    rtb_DiscreteZeroPole *= rtb_CMD_DDOT_DES -
      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_n;

    // Saturate: '<S39>/Saturation1'
    if (rtb_DiscreteZeroPole >
        CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_UpperSat) {
      rtb_CMD_DDOT_REF = CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_UpperSat;
    } else if (rtb_DiscreteZeroPole <
               CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_LowerSat) {
      rtb_CMD_DDOT_REF = CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_LowerSat;
    } else {
      rtb_CMD_DDOT_REF = rtb_DiscreteZeroPole;
    }

    // End of Saturate: '<S39>/Saturation1'

    // Product: '<S43>/Product1' incorporates:
    //   DiscreteIntegrator: '<S39>/Integrator'
    //   DiscreteIntegrator: '<S39>/Integrator1'
    //   DiscreteIntegrator: '<S43>/Integrator'
    //   Gain: '<S37>/Gain'
    //   Inport: '<Root>/PHI_RAD'
    //   Inport: '<Root>/ROLL_ANGLE_ERR_Kp 1'
    //   Inport: '<Root>/ROLL_ANGLE_REF_KFF'
    //   Product: '<S38>/Product'
    //   Product: '<S39>/Product'
    //   Product: '<S39>/Product3'
    //   Sum: '<S35>/Sum'
    //   Sum: '<S38>/Sum'
    //   Sum: '<S39>/Sum2'
    //   Sum: '<S43>/Sum'

    rtb_DiscreteZeroPole = (((rtb_Product7_b * rtb_CMD_DDOT_REF +
      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_n) *
      CONSCALE_CON_TBATT_CONPARA_VE_U.ROLL_ANGLE_REF_KFF +
      (CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE -
       CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_c0 *
       *arg_PHI_RAD) *
      *arg_ROLL_ANGLE_ERR_Kp) -
      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_f) * rtb_REF_K1;

    // Saturate: '<S43>/Saturation'
    if (rtb_DiscreteZeroPole >
        CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_UpperSat_c) {
      rtb_DiscreteZeroPole =
        CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_UpperSat_c;
    } else {
      if (rtb_DiscreteZeroPole <
          CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_LowerSat_d) {
        rtb_DiscreteZeroPole =
          CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_LowerSat_d;
      }
    }

    // End of Saturate: '<S43>/Saturation'

    // Product: '<S43>/Product2' incorporates:
    //   DiscreteIntegrator: '<S43>/Integrator1'
    //   Sum: '<S43>/Sum1'

    rtb_Cos3 *= rtb_DiscreteZeroPole -
      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE;

    // Saturate: '<S43>/Saturation1'
    if (rtb_Cos3 > CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_UpperSat_m) {
      rtb_REF_K1 = CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_UpperSat_m;
    } else if (rtb_Cos3 < CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_LowerSat_m)
    {
      rtb_REF_K1 = CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_LowerSat_m;
    } else {
      rtb_REF_K1 = rtb_Cos3;
    }

    // End of Saturate: '<S43>/Saturation1'

    // Fcn: '<S20>/dot phi' incorporates:
    //   Fcn: '<S20>/dot psi'
    //   Inport: '<Root>/Q_RADPS'
    //   Inport: '<Root>/R_RADPS'

    rtb_DiscreteZeroPole_tmp = *arg_Q_RADPS *
      rtb_CMD_DDOT_REF_l + *arg_R_RADPS *
      rtb_Sin_idx_0_tmp;

    // Gain: '<S44>/Gain' incorporates:
    //   Fcn: '<S20>/dot phi'
    //   Inport: '<Root>/P_RADPS'

    rtb_DiscreteZeroPole = (rtb_DiscreteZeroPole_tmp * (rtb_Product_hb /
      rtb_VectorConcatenate2_tmp) + *arg_P_RADPS) *
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_a;

    // Product: '<S41>/Product' incorporates:
    //   DiscreteIntegrator: '<S43>/Integrator'
    //   Inport: '<Root>/ROLL_ANGULAR_RATE_ERR_Kp '
    //   Sum: '<S41>/Sum'

    rtb_Product_i = (CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_f -
                     rtb_DiscreteZeroPole) *
      *arg_ROLL_ANGULAR_RATE_ERR_Kp;

    // DiscreteZeroPole: '<S45>/Discrete Zero-Pole'
    {
      rtb_DiscreteZeroPole = CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_D*
        rtb_Product_i;
    }

    // Gain: '<S40>/Gain1' incorporates:
    //   DiscreteIntegrator: '<S43>/Integrator1'
    //   Inport: '<Root>/ROLL_ANGUALR_RATE_REF_KFF'
    //   Inport: '<Root>/ROLL_ANGULAR_RATE_REF_K3'
    //   Product: '<S43>/Product'
    //   Product: '<S43>/Product3'
    //   Product: '<S43>/Product7'
    //   Sum: '<S36>/Sum'
    //   Sum: '<S43>/Sum2'

    rtb_VectorConcatenate_idx_0 =
      ((CONSCALE_CON_TBATT_CONPARA_VE_U.ROLL_ANGULAR_RATE_REF_K3 * rtb_REF_K3 *
        rtb_REF_K1 + CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE) *
       CONSCALE_CON_TBATT_CONPARA_VE_U.ROLL_ANGULAR_RATE_REF_KFF +
       rtb_DiscreteZeroPole) * CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_k;

    // DiscreteIntegrator: '<S32>/Integrator1'
    rtb_Product7_b = CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_e;

    // Gain: '<S32>/Gain2' incorporates:
    //   Inport: '<Root>/PITCH_ANGLE_REF_ZETA'

    rtb_DiscreteZeroPole = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain2_Gain_p *
      CONSCALE_CON_TBATT_CONPARA_VE_U.PITCH_ANGLE_REF_ZETA;

    // Gain: '<S32>/Gain3' incorporates:
    //   Inport: '<Root>/PITCH_ANGLE_REF_W0_RADPS'

    rtb_CMD_DDOT_DES = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain3_Gain_i5 *
      CONSCALE_CON_TBATT_CONPARA_VE_U.PITCH_ANGLE_REF_W0_RADPS;

    // Product: '<S32>/Product5' incorporates:
    //   Gain: '<S32>/Gain1'

    rtb_Cos3 = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_d *
      rtb_DiscreteZeroPole * rtb_CMD_DDOT_DES;

    // Product: '<S32>/Product6'
    rtb_REF_K3 = 1.0F / rtb_Cos3;

    // Product: '<S32>/Product4' incorporates:
    //   Gain: '<S32>/Gain'

    rtb_REF_K1_e = 1.0F / rtb_DiscreteZeroPole *
      (CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_h * rtb_CMD_DDOT_DES);

    // DiscreteIntegrator: '<S28>/Integrator1'
    rtb_CMD_DOT_REF_e = CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_a;

    // Product: '<S28>/Product5' incorporates:
    //   Gain: '<S28>/Gain1'
    //   Inport: '<Root>/PITCH_ANGLE_REF_W0_RADPS'
    //   Inport: '<Root>/PITCH_ANGLE_REF_ZETA'

    rtb_DiscreteZeroPole = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_p *
      CONSCALE_CON_TBATT_CONPARA_VE_U.PITCH_ANGLE_REF_ZETA *
      CONSCALE_CON_TBATT_CONPARA_VE_U.PITCH_ANGLE_REF_W0_RADPS;

    // Product: '<S28>/Product7' incorporates:
    //   Inport: '<Root>/PITCH_ANGLE_REF_K3'
    //   Product: '<S28>/Product6'

    rtb_Product7_aq = 1.0F / rtb_DiscreteZeroPole *
      CONSCALE_CON_TBATT_CONPARA_VE_U.PITCH_ANGLE_REF_K3;

    // Product: '<S28>/Product1' incorporates:
    //   DiscreteIntegrator: '<S28>/Integrator'
    //   Gain: '<Root>/Gain2'
    //   Gain: '<S28>/Gain'
    //   Inport: '<Root>/PITCH_ANGLE_REF_W0_RADPS'
    //   Inport: '<Root>/PITCH_ANGLE_REF_ZETA'
    //   Inport: '<Root>/STICK.PWM.LON'
    //   Product: '<S28>/Product4'
    //   Sum: '<S28>/Sum'

    rtb_CMD_DDOT_DES = 1.0F /
      CONSCALE_CON_TBATT_CONPARA_VE_U.PITCH_ANGLE_REF_ZETA *
      (CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_l *
       CONSCALE_CON_TBATT_CONPARA_VE_U.PITCH_ANGLE_REF_W0_RADPS) *
      (CONSCALE_CON_TBATT_CONPARA_VE_P.Gain2_Gain_e *
       CONSCALE_CON_TBATT_CONPARA_VE_U.STICKPWMLON -
       CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_o);

    // Saturate: '<S28>/Saturation'
    if (rtb_CMD_DDOT_DES > CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_UpperSat_d)
    {
      rtb_CMD_DDOT_DES = CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_UpperSat_d;
    } else {
      if (rtb_CMD_DDOT_DES <
          CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_LowerSat_n) {
        rtb_CMD_DDOT_DES = CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_LowerSat_n;
      }
    }

    // End of Saturate: '<S28>/Saturation'

    // Product: '<S28>/Product2' incorporates:
    //   DiscreteIntegrator: '<S28>/Integrator1'
    //   Sum: '<S28>/Sum1'

    rtb_DiscreteZeroPole *= rtb_CMD_DDOT_DES -
      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_a;

    // Saturate: '<S28>/Saturation1'
    if (rtb_DiscreteZeroPole >
        CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_UpperSat_h) {
      rtb_CMD_DDOT_REF_h =
        CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_UpperSat_h;
    } else if (rtb_DiscreteZeroPole <
               CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_LowerSat_d) {
      rtb_CMD_DDOT_REF_h =
        CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_LowerSat_d;
    } else {
      rtb_CMD_DDOT_REF_h = rtb_DiscreteZeroPole;
    }

    // End of Saturate: '<S28>/Saturation1'

    // Product: '<S32>/Product1' incorporates:
    //   DiscreteIntegrator: '<S28>/Integrator'
    //   DiscreteIntegrator: '<S28>/Integrator1'
    //   DiscreteIntegrator: '<S32>/Integrator'
    //   Gain: '<S26>/Gain'
    //   Inport: '<Root>/PITCH_ANGLE_ERR_Kp 2'
    //   Inport: '<Root>/PITCH_ANGLE_REF_KFF'
    //   Inport: '<Root>/THETA_RAD'
    //   Product: '<S27>/Product'
    //   Product: '<S28>/Product'
    //   Product: '<S28>/Product3'
    //   Sum: '<S24>/Sum'
    //   Sum: '<S27>/Sum'
    //   Sum: '<S28>/Sum2'
    //   Sum: '<S32>/Sum'

    rtb_DiscreteZeroPole = (((rtb_Product7_aq * rtb_CMD_DDOT_REF_h +
      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_a) *
      CONSCALE_CON_TBATT_CONPARA_VE_U.PITCH_ANGLE_REF_KFF +
      (CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_o -
       CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_n *
       *arg_THETA_RAD) *
      *arg_PITCH_ANGLE_ERR_Kp) -
      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_d) * rtb_REF_K1_e;

    // Saturate: '<S32>/Saturation'
    if (rtb_DiscreteZeroPole >
        CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_UpperSat_e) {
      rtb_DiscreteZeroPole =
        CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_UpperSat_e;
    } else {
      if (rtb_DiscreteZeroPole <
          CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_LowerSat_h) {
        rtb_DiscreteZeroPole =
          CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_LowerSat_h;
      }
    }

    // End of Saturate: '<S32>/Saturation'

    // Product: '<S32>/Product2' incorporates:
    //   DiscreteIntegrator: '<S32>/Integrator1'
    //   Sum: '<S32>/Sum1'

    rtb_Cos3 *= rtb_DiscreteZeroPole -
      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_e;

    // Saturate: '<S32>/Saturation1'
    if (rtb_Cos3 > CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_UpperSat_a) {
      rtb_REF_K1_e = CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_UpperSat_a;
    } else if (rtb_Cos3 < CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_LowerSat_c)
    {
      rtb_REF_K1_e = CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_LowerSat_c;
    } else {
      rtb_REF_K1_e = rtb_Cos3;
    }

    // End of Saturate: '<S32>/Saturation1'

    // Gain: '<S33>/Gain' incorporates:
    //   Fcn: '<S20>/dot theta'
    //   Inport: '<Root>/Q_RADPS'
    //   Inport: '<Root>/R_RADPS'

    rtb_DiscreteZeroPole = (*arg_Q_RADPS *
      rtb_Sin_idx_0_tmp - *arg_R_RADPS *
      rtb_CMD_DDOT_REF_l) * CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_ct;

    // Product: '<S30>/Product' incorporates:
    //   DiscreteIntegrator: '<S32>/Integrator'
    //   Inport: '<Root>/PITCH_ANGULAR_RATE_ERR_Kp '
    //   Sum: '<S30>/Sum'

    rtb_Product_b = (CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_d -
                     rtb_DiscreteZeroPole) *
      *arg_PITCH_ANGULAR_RATE_ERR_Kp;

    // DiscreteZeroPole: '<S34>/Discrete Zero-Pole'
    {
      rtb_DiscreteZeroPole =
        (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_C_d[0])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_l[0]
        + (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_C_d[1])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_l[1];
      rtb_DiscreteZeroPole +=
        CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_D_g*rtb_Product_b;
    }

    // Gain: '<S29>/Gain1' incorporates:
    //   DiscreteIntegrator: '<S32>/Integrator1'
    //   Inport: '<Root>/PITCH_ANGULAR_RATE_REF_K3'
    //   Inport: '<Root>/PITCH_ANGULAR_RATE_REF_KFF'
    //   Product: '<S32>/Product'
    //   Product: '<S32>/Product3'
    //   Product: '<S32>/Product7'
    //   Sum: '<S25>/Sum'
    //   Sum: '<S32>/Sum2'

    rtb_VectorConcatenate_idx_1 =
      ((CONSCALE_CON_TBATT_CONPARA_VE_U.PITCH_ANGULAR_RATE_REF_K3 * rtb_REF_K3 *
        rtb_REF_K1_e + CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_e) *
       CONSCALE_CON_TBATT_CONPARA_VE_U.PITCH_ANGULAR_RATE_REF_KFF +
       rtb_DiscreteZeroPole) * CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_b;

    // DiscreteIntegrator: '<S49>/Integrator1'
    rtb_Product7_aq = CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_g;

    // Gain: '<S49>/Gain2' incorporates:
    //   Inport: '<Root>/YAW_ANGULAR_RATE_REF_ZETA'

    rtb_DiscreteZeroPole = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain2_Gain_g *
      CONSCALE_CON_TBATT_CONPARA_VE_U.YAW_ANGULAR_RATE_REF_ZETA;

    // Gain: '<S49>/Gain3' incorporates:
    //   Inport: '<Root>/YAW_ANGULAR_RATE_REF_W0_RADPS'

    rtb_CMD_DDOT_DES = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain3_Gain_o *
      CONSCALE_CON_TBATT_CONPARA_VE_U.YAW_ANGULAR_RATE_REF_W0_RADPS;

    // Product: '<S49>/Product5' incorporates:
    //   Gain: '<S49>/Gain1'

    rtb_Cos3 = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_g *
      rtb_DiscreteZeroPole * rtb_CMD_DDOT_DES;

    // Product: '<S49>/Product6'
    rtb_REF_K3 = 1.0F / rtb_Cos3;

    // Product: '<S49>/Product1' incorporates:
    //   DiscreteIntegrator: '<S49>/Integrator'
    //   Gain: '<Root>/Gain4'
    //   Gain: '<S49>/Gain'
    //   Inport: '<Root>/STICK.PWM.YAW'
    //   Product: '<S49>/Product4'
    //   Sum: '<S49>/Sum'

    rtb_DiscreteZeroPole = 1.0F / rtb_DiscreteZeroPole *
      (CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_i2 * rtb_CMD_DDOT_DES) *
      (CONSCALE_CON_TBATT_CONPARA_VE_P.Gain4_Gain *
       CONSCALE_CON_TBATT_CONPARA_VE_U.STICKPWMYAW -
       CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_g);

    // Saturate: '<S49>/Saturation'
    if (rtb_DiscreteZeroPole >
        CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_UpperSat_a) {
      rtb_DiscreteZeroPole =
        CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_UpperSat_a;
    } else {
      if (rtb_DiscreteZeroPole <
          CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_LowerSat_e) {
        rtb_DiscreteZeroPole =
          CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_LowerSat_e;
      }
    }

    // End of Saturate: '<S49>/Saturation'

    // Product: '<S49>/Product2' incorporates:
    //   DiscreteIntegrator: '<S49>/Integrator1'
    //   Sum: '<S49>/Sum1'

    rtb_Cos3 *= rtb_DiscreteZeroPole -
      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_g;

    // Saturate: '<S49>/Saturation1'
    if (rtb_Cos3 > CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_UpperSat_g) {
      rtb_Cos3 = CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_UpperSat_g;
    } else {
      if (rtb_Cos3 < CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_LowerSat_j) {
        rtb_Cos3 = CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_LowerSat_j;
      }
    }

    // End of Saturate: '<S49>/Saturation1'

    // Gain: '<S50>/Gain' incorporates:
    //   Fcn: '<S20>/dot psi'

    rtb_DiscreteZeroPole = rtb_DiscreteZeroPole_tmp / rtb_VectorConcatenate2_tmp
      * CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_lj;

    // Product: '<S47>/Product' incorporates:
    //   DiscreteIntegrator: '<S49>/Integrator'
    //   Inport: '<Root>/YAW_ANGULAR_RATE_ERR_Kp 2'
    //   Sum: '<S47>/Sum'

    rtb_Product_d = (CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_g -
                     rtb_DiscreteZeroPole) *
      *arg_YAW_ANGULAR_RATE_ERR_Kp;

    // DiscreteZeroPole: '<S51>/Discrete Zero-Pole'
    {
      rtb_DiscreteZeroPole =
        (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_C_i[0])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_g[0]
        + (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_C_i[1])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_g[1];
      rtb_DiscreteZeroPole +=
        CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_D_e*rtb_Product_d;
    }

    // Constant: '<S11>/Constant'
    rtb_VectorConcatenate2_h[0] =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Constant_Value_h[0];

    // Sum: '<S9>/Sum'
    rtb_VectorConcatenate2[0] = rtb_VectorConcatenate_idx_0 -
      rtb_VectorConcatenate2[0];

    // Constant: '<S11>/Constant'
    rtb_VectorConcatenate2_h[1] =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Constant_Value_h[1];

    // Sum: '<S9>/Sum' incorporates:
    //   DiscreteIntegrator: '<S49>/Integrator1'
    //   Gain: '<S46>/Gain1'
    //   Inport: '<Root>/YAW_ANGULAR_RATE_REF_K3'
    //   Inport: '<Root>/YAW_ANGULAR_RATE_REF_KFF'
    //   Product: '<S49>/Product'
    //   Product: '<S49>/Product3'
    //   Product: '<S49>/Product7'
    //   Sum: '<S23>/Sum'
    //   Sum: '<S49>/Sum2'

    rtb_VectorConcatenate2[1] = rtb_VectorConcatenate_idx_1 -
      rtb_VectorConcatenate2[1];
    rtb_CMD_DDOT_DES = ((CONSCALE_CON_TBATT_CONPARA_VE_U.YAW_ANGULAR_RATE_REF_K3
                         * rtb_REF_K3 * rtb_Cos3 +
                         CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_g) *
                        CONSCALE_CON_TBATT_CONPARA_VE_U.YAW_ANGULAR_RATE_REF_KFF
                        + rtb_DiscreteZeroPole) *
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_a - rtb_VectorConcatenate2[2];

    // Constant: '<S11>/Constant'
    rtb_VectorConcatenate2_h[2] =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Constant_Value_h[2];

    // Constant: '<S11>/Constant1'
    rtb_VectorConcatenate2_h[3] =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Constant1_Value;

    // Trigonometry: '<S11>/Cos'
    rtb_DiscreteZeroPole = rtb_Sin_idx_0_tmp;

    // SignalConversion generated from: '<S11>/Vector Concatenate'
    rtb_VectorConcatenate2_h[4] = rtb_DiscreteZeroPole;

    // Gain: '<S11>/Gain'
    rtb_VectorConcatenate2_h[5] = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_dm *
      rtb_CMD_DDOT_REF_l;

    // Gain: '<S11>/Gain1'
    rtb_VectorConcatenate2_h[6] = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_j *
      rtb_Product_hb;

    // Product: '<S11>/Product'
    rtb_VectorConcatenate2_h[7] = rtb_CMD_DDOT_REF_l *
      rtb_VectorConcatenate2_tmp;

    // Product: '<S11>/Product1'
    rtb_VectorConcatenate2_h[8] = rtb_DiscreteZeroPole *
      rtb_VectorConcatenate2_tmp;

    // Product: '<S9>/Matrix Multiply1'
    for (i = 0; i < 3; i++) {
      rtb_Cos_k[i] = rtb_VectorConcatenate2_h[i + 6] * rtb_CMD_DDOT_DES +
        (rtb_VectorConcatenate2_h[i + 3] * rtb_VectorConcatenate2[1] +
         rtb_VectorConcatenate2_h[i] * rtb_VectorConcatenate2[0]);
    }

    // End of Product: '<S9>/Matrix Multiply1'

    // Outport: '<Root>/P_DOT_CMD_DEGPS2' incorporates:
    //   Gain: '<S2>/Gain'

    CONSCALE_CON_TBATT_CONPARA_VE_Y.P_DOT_CMD_DEGPS2 =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_a3 * rtb_Cos_k[0];

    arg_P_DOT_CMD_DEGPS2 = CONSCALE_CON_TBATT_CONPARA_VE_Y.P_DOT_CMD_DEGPS2;
    

    // Outport: '<Root>/Q_DOT_CMD_DEGPS2' incorporates:
    //   Gain: '<S3>/Gain'

    CONSCALE_CON_TBATT_CONPARA_VE_Y.Q_DOT_CMD_DEGPS2 =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_p * rtb_Cos_k[1];

    arg_Q_DOT_CMD_DEGPS2 = CONSCALE_CON_TBATT_CONPARA_VE_Y.Q_DOT_CMD_DEGPS2;
    

    // Outport: '<Root>/R_DOT_CMD_DEGPS2' incorporates:
    //   Gain: '<S4>/Gain'

    CONSCALE_CON_TBATT_CONPARA_VE_Y.R_DOT_CMD_DEGPS2 =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_g * rtb_Cos_k[2];

    arg_R_DOT_CMD_DEGPS2 = CONSCALE_CON_TBATT_CONPARA_VE_Y.R_DOT_CMD_DEGPS2;
    

    // Outport: '<Root>/DF_FRR_DEGLIN' incorporates:
    //   Gain: '<Root>/Gain1'
    //   Inport: '<Root>/DF_FRR_DEG'

    CONSCALE_CON_TBATT_CONPARA_VE_Y.DF_FRR_DEGLIN =
      CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_m *
      CONSCALE_CON_TBATT_CONPARA_VE_U.DF_FRR_DEG;

    // Product: '<S54>/Product5' incorporates:
    //   Gain: '<S54>/Gain1'
    //   Inport: '<Root>/VER_VEL_REF_W0_RADPS'
    //   Inport: '<Root>/VER_VEL_REF_ZETA'

    rtb_DiscreteZeroPole = CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_o *
      CONSCALE_CON_TBATT_CONPARA_VE_U.VER_VEL_REF_ZETA *
      CONSCALE_CON_TBATT_CONPARA_VE_U.VER_VEL_REF_W0_RADPS;

    // RateLimiter: '<Root>/Rate Limiter' incorporates:
    //   Inport: '<Root>/STICK.PWM.THR'

    rtb_CMD_DDOT_REF_l = CONSCALE_CON_TBATT_CONPARA_VE_U.STICKPWMTHR -
      CONSCALE_CON_TBATT_CONPARA_V_DW.PrevY;
    if (rtb_CMD_DDOT_REF_l >
        CONSCALE_CON_TBATT_CONPARA_VE_P.RateLimiter_RisingLim) {
      rtb_CMD_DDOT_DES = CONSCALE_CON_TBATT_CONPARA_V_DW.PrevY +
        CONSCALE_CON_TBATT_CONPARA_VE_P.RateLimiter_RisingLim;
    } else if (rtb_CMD_DDOT_REF_l <
               CONSCALE_CON_TBATT_CONPARA_VE_P.RateLimiter_FallingLim) {
      rtb_CMD_DDOT_DES = CONSCALE_CON_TBATT_CONPARA_V_DW.PrevY +
        CONSCALE_CON_TBATT_CONPARA_VE_P.RateLimiter_FallingLim;
    } else {
      rtb_CMD_DDOT_DES = CONSCALE_CON_TBATT_CONPARA_VE_U.STICKPWMTHR;
    }

    CONSCALE_CON_TBATT_CONPARA_V_DW.PrevY = rtb_CMD_DDOT_DES;

    // End of RateLimiter: '<Root>/Rate Limiter'

    // Product: '<S54>/Product1' incorporates:
    //   DiscreteIntegrator: '<S54>/Integrator'
    //   Gain: '<Root>/Gain6'
    //   Gain: '<S54>/Gain'
    //   Inport: '<Root>/VER_VEL_REF_W0_RADPS'
    //   Inport: '<Root>/VER_VEL_REF_ZETA'
    //   Product: '<S54>/Product4'
    //   Sum: '<S54>/Sum'

    rtb_CMD_DDOT_DES = 1.0F / CONSCALE_CON_TBATT_CONPARA_VE_U.VER_VEL_REF_ZETA *
      (CONSCALE_CON_TBATT_CONPARA_VE_P.Gain_Gain_f *
       CONSCALE_CON_TBATT_CONPARA_VE_U.VER_VEL_REF_W0_RADPS) *
      (CONSCALE_CON_TBATT_CONPARA_VE_P.Gain6_Gain * rtb_CMD_DDOT_DES -
       CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_d0);

    // Saturate: '<S54>/Saturation'
    if (rtb_CMD_DDOT_DES > CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_UpperSat_i)
    {
      rtb_CMD_DDOT_DES = CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_UpperSat_i;
    } else {
      if (rtb_CMD_DDOT_DES <
          CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_LowerSat_k) {
        rtb_CMD_DDOT_DES = CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation_LowerSat_k;
      }
    }

    // End of Saturate: '<S54>/Saturation'

    // Product: '<S54>/Product2' incorporates:
    //   DiscreteIntegrator: '<S54>/Integrator1'
    //   Sum: '<S54>/Sum1'

    rtb_CMD_DDOT_REF_l = (rtb_CMD_DDOT_DES -
                          CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_p) *
      rtb_DiscreteZeroPole;

    // Saturate: '<S54>/Saturation1'
    if (rtb_CMD_DDOT_REF_l >
        CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_UpperSat_j) {
      rtb_CMD_DDOT_REF_l =
        CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_UpperSat_j;
    } else {
      if (rtb_CMD_DDOT_REF_l <
          CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_LowerSat_m0) {
        rtb_CMD_DDOT_REF_l =
          CONSCALE_CON_TBATT_CONPARA_VE_P.Saturation1_LowerSat_m0;
      }
    }

    // End of Saturate: '<S54>/Saturation1'

    // Product: '<S54>/Product6'
    rtb_DiscreteZeroPole = 1.0F / rtb_DiscreteZeroPole;

    // Product: '<S54>/Product' incorporates:
    //   DiscreteIntegrator: '<S54>/Integrator1'
    //   Inport: '<Root>/VER_VEL_REF_K3'
    //   Inport: '<Root>/VER_VEL_REF_KFF'
    //   Product: '<S54>/Product3'
    //   Product: '<S54>/Product7'
    //   Sum: '<S54>/Sum2'

    rtb_Product_hb = (CONSCALE_CON_TBATT_CONPARA_VE_U.VER_VEL_REF_K3 *
                      rtb_DiscreteZeroPole * rtb_CMD_DDOT_REF_l +
                      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_p) *
      CONSCALE_CON_TBATT_CONPARA_VE_U.VER_VEL_REF_KFF;

    // Product: '<S52>/Product' incorporates:
    //   DiscreteIntegrator: '<S54>/Integrator'
    //   Inport: '<Root>/H_DOT_MPS'
    //   Inport: '<Root>/VER_VEL_ERR_Kp '
    //   Sum: '<S52>/Sum'

    rtb_Product_e = (CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_d0 -
                     CONSCALE_CON_TBATT_CONPARA_VE_U.H_DOT_MPS) *
      CONSCALE_CON_TBATT_CONPARA_VE_U.VER_VEL_ERR_Kp;

    // DiscreteZeroPole: '<S55>/Discrete Zero-Pole'
    {
      rtb_DiscreteZeroPole =
        (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_C_ig[0])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_o[0]
        + (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_C_ig[1])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_o[1];
      rtb_DiscreteZeroPole +=
        CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_D_i*rtb_Product_e;
    }

    // Outport: '<Root>/ZDDOT_CMD_MPS2' incorporates:
    //   Gain: '<S7>/Gain1'
    //   Product: '<S7>/Product'
    //   Product: '<S7>/Product1'
    //   Sum: '<S8>/Sum'

    CONSCALE_CON_TBATT_CONPARA_VE_Y.ZDDOT_CMD_MPS2 = (rtb_Product_hb +
      rtb_DiscreteZeroPole) * CONSCALE_CON_TBATT_CONPARA_VE_P.Gain1_Gain_oj *
      (1.0F / rtb_Sin_idx_0_tmp / rtb_VectorConcatenate2_tmp);

    arg_G_B_MPS2 = CONSCALE_CON_TBATT_CONPARA_VE_Y.ZDDOT_CMD_MPS2;

    // Update for DiscreteIntegrator: '<S43>/Integrator1'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_gainval * rtb_REF_K1;

    // Update for DiscreteIntegrator: '<S39>/Integrator1'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_n +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_gainval_d * rtb_CMD_DDOT_REF;

    // Update for DiscreteIntegrator: '<S39>/Integrator'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_gainval * rtb_CMD_DOT_REF_cm;

    // Update for DiscreteIntegrator: '<S43>/Integrator'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_f +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_gainval_e * rtb_CMD_DOT_REF;

    // Update for DiscreteZeroPole: '<S45>/Discrete Zero-Pole'
    {
      real32_T xnew[2];
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
         sizeof(real32_T)*2);
    }

    // Update for DiscreteIntegrator: '<S32>/Integrator1'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_e +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_gainval_c * rtb_REF_K1_e;

    // Update for DiscreteIntegrator: '<S28>/Integrator1'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_a +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_gainval_l * rtb_CMD_DDOT_REF_h;

    // Update for DiscreteIntegrator: '<S28>/Integrator'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_o +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_gainval_n * rtb_CMD_DOT_REF_e;

    // Update for DiscreteIntegrator: '<S32>/Integrator'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_d +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_gainval_nw * rtb_Product7_b;

    // Update for DiscreteZeroPole: '<S34>/Discrete Zero-Pole'
    {
      real32_T xnew[2];
      xnew[0] = (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_e[0])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_l[0]
        + (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_e[1])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_l[1];
      xnew[0] += CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_B_n*
        rtb_Product_b;
      xnew[1] = (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_e[2])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_l[0];
      (void) std::memcpy
        (&CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_l[0], xnew,
         sizeof(real32_T)*2);
    }

    // Update for DiscreteIntegrator: '<S49>/Integrator1'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_g +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_gainval_a * rtb_Cos3;

    // Update for DiscreteIntegrator: '<S49>/Integrator'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_g +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_gainval_d * rtb_Product7_aq;

    // Update for DiscreteZeroPole: '<S51>/Discrete Zero-Pole'
    {
      real32_T xnew[2];
      xnew[0] = (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_b[0])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_g[0]
        + (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_b[1])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_g[1];
      xnew[0] += CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_B_f*
        rtb_Product_d;
      xnew[1] = (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_b[2])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_g[0];
      (void) std::memcpy
        (&CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_g[0], xnew,
         sizeof(real32_T)*2);
    }

    // Update for DiscreteIntegrator: '<S54>/Integrator' incorporates:
    //   DiscreteIntegrator: '<S54>/Integrator1'

    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_d0 +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_gainval_a *
      CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_p;

    // Update for DiscreteIntegrator: '<S54>/Integrator1'
    CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_p +=
      CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_gainval_b * rtb_CMD_DDOT_REF_l;

    // Update for DiscreteZeroPole: '<S55>/Discrete Zero-Pole'
    {
      real32_T xnew[2];
      xnew[0] = (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_p[0])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_o[0]
        + (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_p[1])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_o[1];
      xnew[0] += CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_B_k*
        rtb_Product_e;
      xnew[1] = (CONSCALE_CON_TBATT_CONPARA_VE_P.DiscreteZeroPole_A_p[2])*
        CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_o[0];
      (void) std::memcpy
        (&CONSCALE_CON_TBATT_CONPARA_V_DW.DiscreteZeroPole_DSTATE_o[0], xnew,
         sizeof(real32_T)*2);
    }
  }

  rate_scheduler((&CONSCALE_CON_TBATT_CONPARA_V_M));
}

// Model initialize function
void CONFULL_CON_TBATT_CONPARA_VECTORModelClass::initialize()
{
  // Registration code

  // states (dwork)
  (void) std::memset(static_cast<void *>(&CONSCALE_CON_TBATT_CONPARA_V_DW), 0,
                     sizeof(DW_CONSCALE_CON_TBATT_CONPARA_T));

  // external inputs
  (void)std::memset(&CONSCALE_CON_TBATT_CONPARA_VE_U, 0, sizeof
                    (ExtU_CONSCALE_CON_TBATT_CONPA_T));

  // external outputs
  (void) std::memset(static_cast<void *>(&CONSCALE_CON_TBATT_CONPARA_VE_Y), 0,
                     sizeof(ExtY_CONSCALE_CON_TBATT_CONPA_T));

  // InitializeConditions for DiscreteIntegrator: '<S43>/Integrator1'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_IC;

  // InitializeConditions for DiscreteIntegrator: '<S39>/Integrator1'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_n =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_IC_p;

  // InitializeConditions for DiscreteIntegrator: '<S39>/Integrator'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_IC;

  // InitializeConditions for DiscreteIntegrator: '<S43>/Integrator'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_f =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_IC_d;

  // InitializeConditions for DiscreteIntegrator: '<S32>/Integrator1'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_e =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_IC_k;

  // InitializeConditions for DiscreteIntegrator: '<S28>/Integrator1'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_a =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_IC_d;

  // InitializeConditions for DiscreteIntegrator: '<S28>/Integrator'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_o =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_IC_p;

  // InitializeConditions for DiscreteIntegrator: '<S32>/Integrator'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_d =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_IC_n;

  // InitializeConditions for DiscreteIntegrator: '<S49>/Integrator1'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_g =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_IC_pz;

  // InitializeConditions for DiscreteIntegrator: '<S49>/Integrator'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_g =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_IC_c;

  // InitializeConditions for RateLimiter: '<Root>/Rate Limiter'
  CONSCALE_CON_TBATT_CONPARA_V_DW.PrevY =
    CONSCALE_CON_TBATT_CONPARA_VE_P.RateLimiter_IC;

  // InitializeConditions for DiscreteIntegrator: '<S54>/Integrator'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator_DSTATE_d0 =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator_IC_j;

  // InitializeConditions for DiscreteIntegrator: '<S54>/Integrator1'
  CONSCALE_CON_TBATT_CONPARA_V_DW.Integrator1_DSTATE_p =
    CONSCALE_CON_TBATT_CONPARA_VE_P.Integrator1_IC_g;
}

// Model terminate function
void CONFULL_CON_TBATT_CONPARA_VECTORModelClass::terminate()
{
  // (no terminate code required)
}

// Constructor
CONFULL_CON_TBATT_CONPARA_VECTORModelClass::
  CONFULL_CON_TBATT_CONPARA_VECTORModelClass() : CONSCALE_CON_TBATT_CONPARA_V_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
CONFULL_CON_TBATT_CONPARA_VECTORModelClass::
  ~CONFULL_CON_TBATT_CONPARA_VECTORModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_CONSCALE_CON_TBATT_C_T * CONFULL_CON_TBATT_CONPARA_VECTORModelClass::
  getRTM()
{
  return (&CONSCALE_CON_TBATT_CONPARA_V_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
