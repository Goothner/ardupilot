#include "AC_CustomControl_YTDT.h"

#if CUSTOMCONTROL_YTDT_ENABLED

#include <GCS_MAVLink/GCS.h>


//#include <AP_HAL/AP_HAL.h>
//const AP_HAL::HAL& hal = AP_HAL::get_HAL();

// table of user settable parameters
const AP_Param::GroupInfo AC_CustomControl_YTDT::var_info[] = {
    // @Param: PARAM1
    // @DisplayName: YTDT param1
    // @Description: Dummy parameter for YTDT custom controller backend
    // @User: Advanced
    AP_GROUPINFO("YT_ROL_ANG_P", 1, AC_CustomControl_YTDT, _roll_angl_err_kp, 2.0f),

    // @Param: PARAM2
    // @DisplayName: YTDT param2
    // @Description: Dummy parameter for YTDT custom controller backend
    // @User: Advanced
    AP_GROUPINFO("YT_ROL_RAT_P", 2, AC_CustomControl_YTDT, _roll_rate_err_kp, 2.2f),

    // @Param: PARAM3
    // @DisplayName: YTDT param3
    // @Description: Dummy parameter for YTDT custom controller backend
    // @User: Advanced
    AP_GROUPINFO("YT_PIT_ANG_P", 3, AC_CustomControl_YTDT, _pitch_angl_err_kp, 3.8f),

    // @Param: PARAM4
    // @DisplayName: YTDT param3
    // @Description: Dummy parameter for YTDT custom controller backend
    // @User: Advanced
    AP_GROUPINFO("YT_PIT_RAT_P", 4, AC_CustomControl_YTDT, _pitch_rate_err_kp, 5.0f),

    // @Param: PARAM5
    // @DisplayName: YTDT param3
    // @Description: Dummy parameter for YTDT custom controller backend
    // @User: Advanced
    AP_GROUPINFO("YT_YAW_RAT_P", 5, AC_CustomControl_YTDT, _yaw_rate_err_kp, 1.5f),

    AP_GROUPEND
};

// initialize in the constructor
AC_CustomControl_YTDT::AC_CustomControl_YTDT(AC_CustomControl& frontend, AP_AHRS_View*& ahrs, AC_AttitudeControl*& att_control, AP_MotorsMulticopter*& motors, float dt) :
    AC_CustomControl_Backend(frontend, ahrs, att_control, motors, dt)
{
    AP_Param::setup_object_defaults(this, var_info);

    YTDY_controller.initialize();
}

// update controller
// return roll, pitch, yaw controller output
Vector3f AC_CustomControl_YTDT::update(void)
{
    // reset controller based on spool state
    switch (_motors->get_spool_state()) {
        case AP_Motors::SpoolState::SHUT_DOWN:
        case AP_Motors::SpoolState::GROUND_IDLE:
            // We are still at the ground. Reset custom controller to avoid
            // build up, ex: integrator
            reset();
            break;

        case AP_Motors::SpoolState::THROTTLE_UNLIMITED:
        case AP_Motors::SpoolState::SPOOLING_UP:
        case AP_Motors::SpoolState::SPOOLING_DOWN:
            // we are off the ground
            break;
    }

    // arducopter main attitude controller already ran
    // we don't need to do anything else

    // run custom controller after here
     Quaternion attitude_body, attitude_target;
    _ahrs->get_quat_body_to_ned(attitude_body);

    // '<Root>/DF_FRR_DEG'
    float arg_DF_FRR_DEG{ 30.0F };

    // '<Root>/P_RADPS'
    float arg_P_RADPS{ _ahrs->get_gyro().x };

    // '<Root>/Q_RADPS'
    float arg_Q_RADPS{ _ahrs->get_gyro().y };

    // '<Root>/R_RADPS'
    float arg_R_RADPS{ _ahrs->get_gyro().z };

    // '<Root>/PHI_RAD'
    float arg_PHI_RAD{ attitude_body.get_euler_roll() };

    // '<Root>/THETA_RAD'
    float arg_THETA_RAD{ attitude_body.get_euler_pitch() };

    // '<Root>/PSI_RAD'
    float arg_PSI_RAD{ attitude_body.get_euler_yaw() };

    // '<Root>/H_DOT_MPS'
    float arg_H_DOT_MPS{ 0.0F };

    // Return 321-intrinsic euler angles in centidegrees representing the rotation from NED earth frame to the
    // attitude controller's target attitude.
    // **NOTE** Using vector3f*deg(100) is more efficient than deg(vector3f)*100 or deg(vector3d*100) because it gives the
    // same result with the fewest multiplications. Even though it may look like a bug, it is intentional. See issue 4895.
        // Vector3f get_att_target_euler_cd() const { return _euler_angle_target * degrees(100.0f); }
        // const Vector3f & get_att_target_euler_rad() const { return _euler_angle_target; }

    // return the angular velocity of the target (setpoint) attitude rad/s
        // const Vector3f& get_rate_ef_targets() const { return _euler_rate_target; }

    // '<Root>/ROLL_ATT_CMD_DEG'
    float arg_ROLL_ATT_CMD_DEG{ _att_control->get_att_target_euler_cd().x/100.0F};

    // '<Root>/PITCH_ATT_CMD_DEG'
    float arg_PITCH_ATT_CMD_DEG{ _att_control->get_att_target_euler_cd().y/100.0F};

    // '<Root>/YAW_RATE_CMD_DEGPS'
    float arg_YAW_RATE_CMD_DEGPS{ degrees(_att_control->get_rate_ef_targets().z)};

    // '<Root>/HDOT_CMD_MPS'
    float arg_HDOT_CMD_MPS{ 0.0F };

    // '<Root>/VER_VEL_ERR_Kp '
    float arg_VER_VEL_ERR_Kp_{ 1.5F };

    // '<Root>/VER_VEL_REF_KFF'
    float arg_VER_VEL_REF_KFF{ 0.0F };

    // '<Root>/VER_VEL_REF_ZETA'
    float arg_VER_VEL_REF_ZETA{ 0.94F };

    // '<Root>/VER_VEL_REF_W0_RADPS'
    float arg_VER_VEL_REF_W0_RADPS{ 1.1F };

    // '<Root>/VER_VEL_REF_K3'
    float arg_VER_VEL_REF_K3{ 0.483558994F };

    // '<Root>/ROLL_ANGLE_ERR_Kp 1'
    float arg_ROLL_ANGLE_ERR_Kp_1 = _roll_angl_err_kp;

    // '<Root>/ROLL_ANGLE_REF_KFF'
    float arg_ROLL_ANGLE_REF_KFF{ 1.0F };

    // '<Root>/ROLL_ANGLE_REF_ZETA'
    float arg_ROLL_ANGLE_REF_ZETA{ 0.947F };

    // '<Root>/ROLL_ANGLE_REF_W0_RADPS'
    float arg_ROLL_ANGLE_REF_W0_RADPS{ 1.1F };

    // '<Root>/ROLL_ANGLE_REF_K3'
    float arg_ROLL_ANGLE_REF_K3{ 0.001F };

    // '<Root>/ROLL_ANGULAR_RATE_ERR_Kp '
    float arg_ROLL_ANGULAR_RATE_ERR_Kp_ = _roll_rate_err_kp;

    // '<Root>/ROLL_ANGUALR_RATE_REF_KFF'
    float arg_ROLL_ANGUALR_RATE_REF_KFF{ 0.0F };

    // '<Root>/ROLL_ANGULAR_RATE_REF_K3'
    float arg_ROLL_ANGULAR_RATE_REF_K3{ 0.01F };

    // '<Root>/PITCH_ANGLE_ERR_Kp 2'
    float arg_PITCH_ANGLE_ERR_Kp_2 = _pitch_angl_err_kp;

    // '<Root>/PITCH_ANGLE_REF_KFF'
    float arg_PITCH_ANGLE_REF_KFF{ 0.0F };

    // '<Root>/PITCH_ANGLE_REF_ZETA'
    float arg_PITCH_ANGLE_REF_ZETA{ 0.937F };

    // '<Root>/PITCH_ANGLE_REF_W0_RADPS'
    float arg_PITCH_ANGLE_REF_W0_RADPS{ 1.81F };

    // '<Root>/PITCH_ANGLE_REF_K3'
    float arg_PITCH_ANGLE_REF_K3{ 0.01F };

    // '<Root>/PITCH_ANGULAR_RATE_ERR_Kp '
    float arg_PITCH_ANGULAR_RATE_ERR_Kp_ = _pitch_rate_err_kp;

    // '<Root>/PITCH_ANGULAR_RATE_REF_KFF'
    float arg_PITCH_ANGULAR_RATE_REF_KFF{ 0.0F };

    // '<Root>/PITCH_ANGULAR_RATE_REF_K3'
    float arg_PITCH_ANGULAR_RATE_REF_K3{ 1.0F };

    // '<Root>/YAW_ANGULAR_RATE_ERR_Kp 2'
    float arg_YAW_ANGULAR_RATE_ERR_Kp_2 = _yaw_rate_err_kp;

    // '<Root>/YAW_ANGULAR_RATE_REF_KFF'
    float arg_YAW_ANGULAR_RATE_REF_KFF{ 0.0F };

    // '<Root>/YAW_ANGULAR_RATE_REF_ZETA'
    float arg_YAW_ANGULAR_RATE_REF_ZETA{ 0.707F };

    // '<Root>/YAW_ANGULAR_RATE_REF_W0_RADPS'
    float arg_YAW_ANGULAR_RATE_REF_W0_RADPS{ 1.01F };

    // '<Root>/YAW_ANGULAR_RATE_REF_K3'
    float arg_YAW_ANGULAR_RATE_REF_K3{ 0.00001F };

    // '<Root>/DF_FRR_DEGLIN'
    double arg_DF_FRR_DEGLIN = 30.0F;

    // '<Root>/P_DOT_CMD'
    float arg_P_DOT_CMD;

    // '<Root>/Q_DOT_CMD'
    float arg_Q_DOT_CMD;

    // '<Root>/R_DOT_CMD'
    float arg_R_DOT_CMD;

    // '<Root>/G_B_MPS2'
    float arg_G_B_MPS2;

    
    // run controller
    YTDY_controller.step(&arg_DF_FRR_DEG, &arg_P_RADPS,
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

    // YTscaled parameters
    // float _P_DOT_max_degss = 7.0F;//7.1
    // float _Q_DOT_max_degss = 19.0F;//19.2
    // float _R_DOT_max_degss = 2.23F;//2.236

    //
    //gcs().send_text(MAV_SEVERITY_INFO, "YTDT controller working");
    //gcs().send_text(MAV_SEVERITY_INFO, "get_dt = %.4f ", _att_control->get_dt());
    gcs().send_text(MAV_SEVERITY_INFO, "YT-10:33 input deg: R= %.2f,P= %.2f,Y= %.2f ",arg_ROLL_ATT_CMD_DEG, arg_PITCH_ATT_CMD_DEG, arg_YAW_RATE_CMD_DEGPS);
    //hal.console->printf("\n\n NFCY test! %.2f \n\n", 1.234f);
    //hal.console->printf("\n\n NFCY test! %.2f \n\n", nfcytest)

    // return what arducopter main controller outputted
    return Vector3f(constrain_float(arg_P_DOT_CMD/_P_DOT_max_degss, -1.0F, 1.0F), constrain_float(arg_Q_DOT_CMD/_Q_DOT_max_degss, -1.0F, 1.0F), constrain_float(arg_R_DOT_CMD/_R_DOT_max_degss, -1.0F, 1.0F));
}

// reset controller to avoid build up on the ground
// or to provide bumpless transfer from arducopter main controller
void AC_CustomControl_YTDT::reset(void)
{
}

#endif
