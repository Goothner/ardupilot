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
    
    // YTscaled parameters
    float _P_DOT_max_degss = 7.0F;//7.1
    float _Q_DOT_max_degss = 19.0F;//19.2
    float _R_DOT_max_degss = 2.23F;//2.236
};

#endif
