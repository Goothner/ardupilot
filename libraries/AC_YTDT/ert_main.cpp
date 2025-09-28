//
// File: ert_main.cpp
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
#include <stdio.h>              // This example main program uses printf/fflush
#include "CONSCALE_CON_TBATT_CONPARA_VECTOR.h" // Model header file

static CONFULL_CON_TBATT_CONPARA_VECTORModelClass
  CONSCALE_CON_TBATT_CONPARA__Obj;     // Instance of model class

// '<Root>/DF_FRR_DEG'
static real32_T arg_DF_FRR_DEG{ 0.0F };

// '<Root>/P_RADPS'
static real32_T arg_P_RADPS{ 0.0F };

// '<Root>/Q_RADPS'
static real32_T arg_Q_RADPS{ 0.0F };

// '<Root>/R_RADPS'
static real32_T arg_R_RADPS{ 0.0F };

// '<Root>/PHI_RAD'
static real32_T arg_PHI_RAD{ 0.0F };

// '<Root>/THETA_RAD'
static real32_T arg_THETA_RAD{ 0.0F };

// '<Root>/PSI_RAD'
static real32_T arg_PSI_RAD{ 0.0F };

// '<Root>/H_DOT_MPS'
static real32_T arg_H_DOT_MPS{ 0.0F };

// '<Root>/ROLL_ATT_CMD_DEG'
static real32_T arg_ROLL_ATT_CMD_DEG{ 0.0F };

// '<Root>/PITCH_ATT_CMD_DEG'
static real32_T arg_PITCH_ATT_CMD_DEG{ 0.0F };

// '<Root>/YAW_RATE_CMD_DEGPS'
static real32_T arg_YAW_RATE_CMD_DEGPS{ 0.0F };

// '<Root>/HDOT_CMD_MPS'
static real32_T arg_HDOT_CMD_MPS{ 0.0F };

// '<Root>/VER_VEL_ERR_Kp '
static real32_T arg_VER_VEL_ERR_Kp_{ 0.0F };

// '<Root>/VER_VEL_REF_KFF'
static real32_T arg_VER_VEL_REF_KFF{ 0.0F };

// '<Root>/VER_VEL_REF_ZETA'
static real32_T arg_VER_VEL_REF_ZETA{ 0.0F };

// '<Root>/VER_VEL_REF_W0_RADPS'
static real32_T arg_VER_VEL_REF_W0_RADPS{ 0.0F };

// '<Root>/VER_VEL_REF_K3'
static real32_T arg_VER_VEL_REF_K3{ 0.0F };

// '<Root>/ROLL_ANGLE_ERR_Kp 1'
static real32_T arg_ROLL_ANGLE_ERR_Kp_1{ 0.0F };

// '<Root>/ROLL_ANGLE_REF_KFF'
static real32_T arg_ROLL_ANGLE_REF_KFF{ 0.0F };

// '<Root>/ROLL_ANGLE_REF_ZETA'
static real32_T arg_ROLL_ANGLE_REF_ZETA{ 0.0F };

// '<Root>/ROLL_ANGLE_REF_W0_RADPS'
static real32_T arg_ROLL_ANGLE_REF_W0_RADPS{ 0.0F };

// '<Root>/ROLL_ANGLE_REF_K3'
static real32_T arg_ROLL_ANGLE_REF_K3{ 0.0F };

// '<Root>/ROLL_ANGULAR_RATE_ERR_Kp '
static real32_T arg_ROLL_ANGULAR_RATE_ERR_Kp_{ 0.0F };

// '<Root>/ROLL_ANGUALR_RATE_REF_KFF'
static real32_T arg_ROLL_ANGUALR_RATE_REF_KFF{ 0.0F };

// '<Root>/ROLL_ANGULAR_RATE_REF_K3'
static real32_T arg_ROLL_ANGULAR_RATE_REF_K3{ 0.0F };

// '<Root>/PITCH_ANGLE_ERR_Kp 2'
static real32_T arg_PITCH_ANGLE_ERR_Kp_2{ 0.0F };

// '<Root>/PITCH_ANGLE_REF_KFF'
static real32_T arg_PITCH_ANGLE_REF_KFF{ 0.0F };

// '<Root>/PITCH_ANGLE_REF_ZETA'
static real32_T arg_PITCH_ANGLE_REF_ZETA{ 0.0F };

// '<Root>/PITCH_ANGLE_REF_W0_RADPS'
static real32_T arg_PITCH_ANGLE_REF_W0_RADPS{ 0.0F };

// '<Root>/PITCH_ANGLE_REF_K3'
static real32_T arg_PITCH_ANGLE_REF_K3{ 0.0F };

// '<Root>/PITCH_ANGULAR_RATE_ERR_Kp '
static real32_T arg_PITCH_ANGULAR_RATE_ERR_Kp_{ 0.0F };

// '<Root>/PITCH_ANGULAR_RATE_REF_KFF'
static real32_T arg_PITCH_ANGULAR_RATE_REF_KFF{ 0.0F };

// '<Root>/PITCH_ANGULAR_RATE_REF_K3'
static real32_T arg_PITCH_ANGULAR_RATE_REF_K3{ 0.0F };

// '<Root>/YAW_ANGULAR_RATE_ERR_Kp 2'
static real32_T arg_YAW_ANGULAR_RATE_ERR_Kp_2{ 0.0F };

// '<Root>/YAW_ANGULAR_RATE_REF_KFF'
static real32_T arg_YAW_ANGULAR_RATE_REF_KFF{ 0.0F };

// '<Root>/YAW_ANGULAR_RATE_REF_ZETA'
static real32_T arg_YAW_ANGULAR_RATE_REF_ZETA{ 0.0F };

// '<Root>/YAW_ANGULAR_RATE_REF_W0_RADPS'
static real32_T arg_YAW_ANGULAR_RATE_REF_W0_RADPS{ 0.0F };

// '<Root>/YAW_ANGULAR_RATE_REF_K3'
static real32_T arg_YAW_ANGULAR_RATE_REF_K3{ 0.0F };

// '<Root>/DF_FRR_DEGLIN'
static real_T arg_DF_FRR_DEGLIN;

// '<Root>/P_DOT_CMD'
static real32_T arg_P_DOT_CMD;

// '<Root>/Q_DOT_CMD'
static real32_T arg_Q_DOT_CMD;

// '<Root>/R_DOT_CMD'
static real32_T arg_R_DOT_CMD;

// '<Root>/G_B_MPS2'
static real32_T arg_G_B_MPS2;

//
// Associating rt_OneStep with a real-time clock or interrupt service routine
// is what makes the generated code "real-time".  The function rt_OneStep is
// always associated with the base rate of the model.  Subrates are managed
// by the base rate from inside the generated code.  Enabling/disabling
// interrupts and floating point context switches are target specific.  This
// example code indicates where these should take place relative to executing
// the generated code step function.  Overrun behavior should be tailored to
// your application needs.  This example simply sets an error status in the
// real-time model and returns from rt_OneStep.
//
void rt_OneStep(void);
void rt_OneStep(void)
{
  static boolean_T OverrunFlag{ false };

  // Disable interrupts here

  // Check for overrun
  if (OverrunFlag) {
    rtmSetErrorStatus(CONSCALE_CON_TBATT_CONPARA__Obj.getRTM(), "Overrun");
    return;
  }

  OverrunFlag = true;

  // Save FPU context here (if necessary)
  // Re-enable timer or interrupt here
  // Set model inputs here

  // Step the model
  CONSCALE_CON_TBATT_CONPARA__Obj.step(&arg_DF_FRR_DEG, &arg_P_RADPS,
    &arg_Q_RADPS, &arg_R_RADPS, &arg_PHI_RAD, &arg_THETA_RAD, &arg_PSI_RAD,
    &arg_H_DOT_MPS, &arg_ROLL_ATT_CMD_DEG, &arg_PITCH_ATT_CMD_DEG,
    &arg_YAW_RATE_CMD_DEGPS, &arg_HDOT_CMD_MPS, &arg_VER_VEL_ERR_Kp_,
    &arg_VER_VEL_REF_KFF, &arg_VER_VEL_REF_ZETA, &arg_VER_VEL_REF_W0_RADPS,
    &arg_VER_VEL_REF_K3, &arg_ROLL_ANGLE_ERR_Kp_1, &arg_ROLL_ANGLE_REF_KFF,
    &arg_ROLL_ANGLE_REF_ZETA, &arg_ROLL_ANGLE_REF_W0_RADPS,
    &arg_ROLL_ANGLE_REF_K3, &arg_ROLL_ANGULAR_RATE_ERR_Kp_,
    &arg_ROLL_ANGUALR_RATE_REF_KFF, &arg_ROLL_ANGULAR_RATE_REF_K3,
    &arg_PITCH_ANGLE_ERR_Kp_2, &arg_PITCH_ANGLE_REF_KFF,
    &arg_PITCH_ANGLE_REF_ZETA, &arg_PITCH_ANGLE_REF_W0_RADPS,
    &arg_PITCH_ANGLE_REF_K3, &arg_PITCH_ANGULAR_RATE_ERR_Kp_,
    &arg_PITCH_ANGULAR_RATE_REF_KFF, &arg_PITCH_ANGULAR_RATE_REF_K3,
    &arg_YAW_ANGULAR_RATE_ERR_Kp_2, &arg_YAW_ANGULAR_RATE_REF_KFF,
    &arg_YAW_ANGULAR_RATE_REF_ZETA, &arg_YAW_ANGULAR_RATE_REF_W0_RADPS,
    &arg_YAW_ANGULAR_RATE_REF_K3, arg_DF_FRR_DEGLIN, arg_P_DOT_CMD,
    arg_Q_DOT_CMD, arg_R_DOT_CMD, arg_G_B_MPS2);

  // Get model outputs here

  // Indicate task complete
  OverrunFlag = false;

  // Disable interrupts here
  // Restore FPU context here (if necessary)
  // Enable interrupts here
}

//
// The example main function illustrates what is required by your
// application code to initialize, execute, and terminate the generated code.
// Attaching rt_OneStep to a real-time clock is target specific. This example
// illustrates how you do this relative to initializing the model.
//
int_T main(int_T argc, const char *argv[])
{
  // Unused arguments
  (void)(argc);
  (void)(argv);

  // Initialize model
  CONSCALE_CON_TBATT_CONPARA__Obj.initialize();

  // Attach rt_OneStep to a timer or interrupt service routine with
  //  period 0.0025 seconds (base rate of the model) here.
  //  The call syntax for rt_OneStep is
  //
  //   rt_OneStep();

  printf("Warning: The simulation will run forever. "
         "Generated ERT main won't simulate model step behavior. "
         "To change this behavior select the 'MAT-file logging' option.\n");
  fflush((nullptr));
  while (rtmGetErrorStatus(CONSCALE_CON_TBATT_CONPARA__Obj.getRTM()) == (nullptr))
  {
    //  Perform application tasks here
  }

  // Terminate model
  CONSCALE_CON_TBATT_CONPARA__Obj.terminate();
  return 0;
}

//
// File trailer for generated code.
//
// [EOF]
//
