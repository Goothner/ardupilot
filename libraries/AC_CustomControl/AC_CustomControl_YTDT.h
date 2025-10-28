#pragma once

#include "AC_CustomControl_Backend.h"
#include "AC_YTDT/CONSCALE_CON_TBATT_CONPARA_VECTOR.h"
#include <AP_Math/AP_Math.h>

#ifndef CUSTOMCONTROL_YTDT_ENABLED
    #define CUSTOMCONTROL_YTDT_ENABLED AP_CUSTOMCONTROL_ENABLED
#endif

#if CUSTOMCONTROL_YTDT_ENABLED

class AC_CustomControl_YTDT : public AC_CustomControl_Backend {
public:
    AC_CustomControl_YTDT(AC_CustomControl& frontend, AP_AHRS_View*& ahrs, AC_AttitudeControl*& att_control, AP_MotorsMulticopter*& motors, float dt);


    Vector3f update(void) override;
    void reset(void) override;

    CONFULL_CON_TBATT_CONPARA_VECTORModelClass YTDY_controller;
    // user settable parameters
    static const struct AP_Param::GroupInfo var_info[];

protected:
    // declare parameters here
    AP_Float _roll_angl_err_kp;
    AP_Float _roll_rate_err_kp;
    AP_Float _pitch_angl_err_kp;
    AP_Float _pitch_rate_err_kp;
    AP_Float _yaw_rate_err_kp;
    // '<Root>/DF_FRR_DEG'
    float arg_DF_FRR_DEG{ 30.0F };

    // '<Root>/P_RADPS'
    float arg_P_RADPS{ 0.0F };

    // '<Root>/Q_RADPS'
    float arg_Q_RADPS{ 0.0F  };

    // '<Root>/R_RADPS'
    float arg_R_RADPS{ 0.0F  };

      // '<Root>/PHI_RAD'
    float arg_PHI_RAD{0.0F };

    // '<Root>/THETA_RAD'
    float arg_THETA_RAD{ 0.0F };

    // '<Root>/PSI_RAD'
    float arg_PSI_RAD{ 0.0F };

    // '<Root>/H_DOT_MPS'
    float arg_H_DOT_MPS{ 0.0F };

     // '<Root>/ROLL_ATT_CMD_DEG'
    float arg_ROLL_ATT_CMD_DEG{ 0.0F };

    // '<Root>/PITCH_ATT_CMD_DEG'
    float arg_PITCH_ATT_CMD_DEG{ 0.0F };

    // '<Root>/YAW_RATE_CMD_DEGPS'
    float arg_YAW_RATE_CMD_DEGPS{ 0.0F };

    // '<Root>/HDOT_CMD_MPS'
    float arg_HDOT_CMD_MPS{ 0.0F };

     // '<Root>/ROLL_ANGLE_ERR_Kp 1'
    float arg_ROLL_ANGLE_ERR_Kp = 0.0F;

     // '<Root>/ROLL_ANGULAR_RATE_ERR_Kp '
    float arg_ROLL_ANGULAR_RATE_ERR_Kp = 0.0F;

     // '<Root>/PITCH_ANGLE_ERR_Kp 2'
    float arg_PITCH_ANGLE_ERR_Kp = 0.0F;

    // '<Root>/PITCH_ANGULAR_RATE_ERR_Kp '
    float arg_PITCH_ANGULAR_RATE_ERR_Kp = 0.0F;

     // '<Root>/YAW_ANGULAR_RATE_ERR_Kp 2'
    float arg_YAW_ANGULAR_RATE_ERR_Kp = 0.0F;

     // '<Root>/P_DOT_CMD'
    float arg_P_DOT_CMD_DEGPS2 = 0;

    // '<Root>/Q_DOT_CMD'
    float arg_Q_DOT_CMD_DEGPS2 = 0;

    // '<Root>/R_DOT_CMD'
    float arg_R_DOT_CMD_DEGPS2 = 0;

    // '<Root>/G_B_MPS2'
    float arg_G_B_MPS2 = 0;
    
    // YTscaled parameters
    float _P_DOT_max_degss = 8.8F;//7.1
    float _Q_DOT_max_degss = 22.0F;//19.2
    float _R_DOT_max_degss = 5.59F;//2.236
};

#endif
