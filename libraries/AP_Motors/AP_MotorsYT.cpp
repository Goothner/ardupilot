/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <AP_HAL/AP_HAL.h>
#include <AP_Math/AP_Math.h>
#include "AP_MotorsYT.h"
#include <AP_Vehicle/AP_Vehicle_Type.h>
#include <cmath>

extern const AP_HAL::HAL& hal;

// init
void AP_MotorsYT::init(motor_frame_class frame_class, motor_frame_type frame_type)
{
    // record requested frame class and type
    _active_frame_class = frame_class;
    _active_frame_type = frame_type;

    if (frame_class == MOTOR_FRAME_SCRIPTING_MATRIX) {
        // if Scripting frame class, do nothing scripting must call its own dedicated init function
        return;
    }

    // setup the motors
    setup_motors(frame_class, frame_type);

    // enable fast channels or instant pwm
    set_update_rate(_speed_hz);
}

#if AP_SCRIPTING_ENABLED
// dedicated init for lua scripting
bool AP_MotorsYT::init(uint8_t expected_num_motors)
{
    if (_active_frame_class != MOTOR_FRAME_SCRIPTING_MATRIX) {
        // not the correct class
        return false;
    }

    // Make sure the correct number of motors have been added
    uint8_t num_motors = 0;
    for (uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
        if (motor_enabled[i]) {
            num_motors++;
        }
    }

    set_initialised_ok(expected_num_motors == num_motors);

    if (!initialised_ok()) {
        _mav_type = MAV_TYPE_GENERIC;
        return false;
    }

    switch (num_motors) {
        case 3:
            _mav_type = MAV_TYPE_TRICOPTER;
            break;
        case 4:
            _mav_type = MAV_TYPE_QUADROTOR;
            break;
        case 6:
            _mav_type = MAV_TYPE_HEXAROTOR;
            break;
        case 8:
            _mav_type = MAV_TYPE_OCTOROTOR;
            break;
        case 10:
            _mav_type = MAV_TYPE_DECAROTOR;
            break;
        case 12:
            _mav_type = MAV_TYPE_DODECAROTOR;
            break;
        default:
            _mav_type = MAV_TYPE_GENERIC;
    }

    normalise_rpy_factors();

    set_update_rate(_speed_hz);

    return true;
}

// Set throttle factor from scripting
bool AP_MotorsYT::set_throttle_factor(int8_t motor_num, float throttle_factor)
{
    if ((_active_frame_class != MOTOR_FRAME_SCRIPTING_MATRIX) ) {
        // not the correct class
        return false;
    }

    if (initialised_ok() || !motor_enabled[motor_num]) {
        // Already setup or given motor is not enabled
        return false;
    }

    _throttle_factor[motor_num] = throttle_factor;
    return true;
}

#endif // AP_SCRIPTING_ENABLED

// set update rate to motors - a value in hertz
void AP_MotorsYT::set_update_rate(uint16_t speed_hz)
{
    // record requested speed
    _speed_hz = speed_hz;

    uint32_t mask = 0;
    for (uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
        if (motor_enabled[i]) {
            mask |= 1U << i;
        }
    }
    rc_set_freq(mask, _speed_hz);
}

// set frame class (i.e. quad, hexa, heli) and type (i.e. x, plus)
void AP_MotorsYT::set_frame_class_and_type(motor_frame_class frame_class, motor_frame_type frame_type)
{
    // exit immediately if armed or no change
    if (armed() || (frame_class == _active_frame_class && _active_frame_type == frame_type)) {
        return;
    }
    _active_frame_class = frame_class;
    _active_frame_type = frame_type;

    init(frame_class, frame_type);

}

void AP_MotorsYT::output_to_motors()
{
    int8_t i;

    switch (_spool_state) {
        case SpoolState::SHUT_DOWN: {
            // no output
            for (i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
                if (motor_enabled_mask(i)) {
                    _actuator[i] = 0.0f;
                }
            }
            break;
        }
        case SpoolState::GROUND_IDLE:
            // sends output to motors when armed but not flying
            for (i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
                if (motor_enabled[i]) {
                    set_actuator_with_slew(_actuator[i], actuator_spin_up_to_ground_idle());
                }
            }
            break;
        case SpoolState::SPOOLING_UP:
        case SpoolState::THROTTLE_UNLIMITED: 
        // {// set motor output based on thrust requests
        //     for (i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
        //         if (motor_enabled[i]) {
        //             set_actuator_with_slew(_actuator[i], thr_lin.thrust_to_actuator(_thrust_rpyt_out[i]));
        //         }
        //     }
        //     break;
        // }
            
        case SpoolState::SPOOLING_DOWN:
            // set motor output based on thrust requests
            for (i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
                if (motor_enabled[i]) {
                    set_actuator_with_slew(_actuator[i], thr_lin.thrust_to_actuator(_thrust_rpyt_out[i]));
                }
            }
            break;
    }

    //hal.console->printf("\n\n Output M_%.u = %.2f \n\n", i+1, _thrust_rpyt_out[i]);
    //hal.console->printf("\n\n SpoolState = %.d \n\n", (int)_spool_state);
    // convert output to PWM and send to each motor
    for (i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
        if (motor_enabled[i]) {
            rc_write(i, output_to_pwm(_actuator[i]));
        }
    }
}

// get_motor_mask - returns a bitmask of which outputs are being used for motors (1 means being used)
//  this can be used to ensure other pwm outputs (i.e. for servos) do not conflict
uint32_t AP_MotorsYT::get_motor_mask()
{
    uint32_t motor_mask = 0;
    for (uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
        if (motor_enabled[i]) {
            motor_mask |= 1U << i;
        }
    }
    uint32_t mask = motor_mask_to_srv_channel_mask(motor_mask);

    // add parent's mask
    mask |= AP_MotorsMulticopter::get_motor_mask();

    return mask;
}

// helper to return value scaled between boost and normal based on the value of _thrust_boost_ratio
// _thrust_boost_ratio of 1 -> return = boost_value
// _thrust_boost_ratio of 0 -> return = normal_value
float AP_MotorsYT::boost_ratio(float boost_value, float normal_value) const
{
    return _thrust_boost_ratio * boost_value + (1.0 - _thrust_boost_ratio) * normal_value;
}

//output_armed - sends commands to the motors
//includes new scaling stability patch
void AP_MotorsYT::output_armed_stabilizing()
{
    float B[88];
    int iU;
    float rtb_CTz_Lookup[22];
    float rtb_CTx_Lookup[22];
    float rtb_Binv[88];
    int i;
    //_weight_diag
    //float tmp[484];//float==double
    // _B_0
    //float B_0[484];
    float B_1[88];
    int i_0;
    float rtb_CTx_Lookup_a;
    float rtb_CTz_Lookup_p;
    float ly_m;
    int rtb_Binv_tmp;
    int c_tmp;
    int B_tmp;
    int B_tmp_0;
    int B_tmp_1;
    // _weight
    // static const float b[22] = { 1.0, 1.0, 1.0, 1.0, 2.5, 1.0, 1.0, 1.0, 1.0, 2.5,
    //     1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 };

    static const uint8_T c[16] = { 1U, 0U, 0U, 0U, 0U, 1U, 0U, 0U, 0U, 0U, 1U, 0U,
        0U, 0U, 0U, 144U };

    // MATLAB Function: '<S1>/MATLAB Function'
    //diag(b, tmp);
    // for (uint8_t j = 0; j < 22; j++) {
    //     tmp[j + 22 * j] = _weight[j];
    // }
    for (iU = 0; iU < 22; iU++) {
        // Lookup_n-D: '<S1>/CTx_Lookup' incorporates:
        //   Constant: '<Root>/DF_DEG'

        rtb_CTx_Lookup_a = look1_iflf_binlxpw
        (_DF_DEG_Value[iU],
        _CTx_Lookup_bp01Data,
        _CTx_Lookup_tableData, 3U);

        // Lookup_n-D: '<S1>/CTz_Lookup' incorporates:
        //   Constant: '<Root>/DF_DEG'

        rtb_CTz_Lookup_p = look1_iflf_binlxpw
        (_DF_DEG_Value[iU],
        _CTz_Lookup_bp01Data,
        _CTz_Lookup_tableData, 3U);

        // MATLAB Function: '<S1>/MATLAB Function' incorporates:
        //   Constant: '<Root>/DF_DEG'
        //   Constant: '<S1>/Constant'
        //   Constant: '<S1>/Constant1'
        //   Lookup_n-D: '<S1>/CQ_Lookup'

        ly_m = static_cast<float>
        (_vehicle_DUCT_LeverArm_m[3 * iU + 1]);
        i = iU << 2;
        B[i] = -rtb_CTz_Lookup_p;
        B_tmp = i + 1;
        B[B_tmp] = -rtb_CTz_Lookup_p * ly_m + static_cast<float>
        (_vehicle_DUCT_RotDir[iU]) *
        look1_iflf_binlxpw(_DF_DEG_Value[iU],
                            _CQ_Lookup_bp01Data,
                            _CQ_Lookup_tableData, 3U);
        B_tmp_0 = i + 2;
        B[B_tmp_0] = static_cast<float>
        (_vehicle_DUCT_LeverArm_m[3 * iU + 2]) *
        rtb_CTx_Lookup_a + static_cast<float>
        (_vehicle_DUCT_LeverArm_m[3 * iU]) *
        rtb_CTz_Lookup_p;
        B_tmp_1 = i + 3;
        B[B_tmp_1] = -rtb_CTx_Lookup_a * ly_m;
        for (i_0 = 0; i_0 < 4; i_0++) {
        rtb_Binv_tmp = iU + 22 * i_0;
        rtb_Binv[rtb_Binv_tmp] = 0.0F;
        B_1[rtb_Binv_tmp] = 0.0F;
        c_tmp = i_0 << 2;
        rtb_CTx_Lookup_a = B[i] * static_cast<float>(c[c_tmp]);
        rtb_Binv[rtb_Binv_tmp] += rtb_CTx_Lookup_a;
        B_1[rtb_Binv_tmp] += rtb_CTx_Lookup_a;
        rtb_CTx_Lookup_a = B[B_tmp] * static_cast<float>(c[c_tmp + 1]);
        rtb_Binv[rtb_Binv_tmp] += rtb_CTx_Lookup_a;
        B_1[rtb_Binv_tmp] += rtb_CTx_Lookup_a;
        rtb_CTx_Lookup_a = B[B_tmp_0] * static_cast<float>(c[c_tmp + 2]);
        rtb_Binv[rtb_Binv_tmp] += rtb_CTx_Lookup_a;
        B_1[rtb_Binv_tmp] += rtb_CTx_Lookup_a;
        rtb_CTx_Lookup_a = B[B_tmp_1] * static_cast<float>(c[c_tmp + 3]);
        rtb_Binv[rtb_Binv_tmp] += rtb_CTx_Lookup_a;
        B_1[rtb_Binv_tmp] += rtb_CTx_Lookup_a;
        }

        // Lookup_n-D: '<S1>/CTz_Lookup'
        rtb_CTz_Lookup[iU] = rtb_CTz_Lookup_p;
    }

    // MATLAB Function: '<S1>/MATLAB Function'
    for (i_0 = 0; i_0 < 22; i_0++) {
        for (iU = 0; iU < 22; iU++) {
        i = i_0 << 2;
        B_tmp = 22 * i_0 + iU;
        _B_0[B_tmp] = (((B[i + 1] * B_1[iU + 22] + B[i] * B_1[iU]) + B[i + 2] * B_1[iU + 44]) + B[i + 3] * B_1[iU + 66]) + static_cast<float>(_weight_diag[B_tmp]);
        }
    }

    // for (int ii = 0; ii < 484; ii++) {
    //     _B_1[ii] = _B_0[ii];
    // }
    //std::memcpy(&_B_1[0], &_B_0[0], 484U * sizeof(float));
    mldivide(_B_0, rtb_Binv);

    // apply voltage and air pressure compensation
    const float compensation_gain = thr_lin.get_compensation_gain(); // compensation for battery voltage and altitude

    // pitch thrust input value, +/- 1.0
    const float roll_thrust = (_roll_in + _roll_in_ff) * compensation_gain;

    // pitch thrust input value, +/- 1.0
    const float pitch_thrust = (_pitch_in + _pitch_in_ff) * compensation_gain;

    // yaw thrust input value, +/- 1.0
    float yaw_thrust = (_yaw_in + _yaw_in_ff) * compensation_gain;

    // throttle thrust input value, 0.0 - 1.0
    float throttle_thrust = get_throttle() * compensation_gain;

    // throttle thrust average maximum value, 0.0 - 1.0
    float throttle_avg_max = _throttle_avg_max * compensation_gain;

    // throttle thrust maximum value, 0.0 - 1.0, If thrust boost is active then do not limit maximum thrust
    const float throttle_thrust_max = boost_ratio(1.0, _throttle_thrust_max * compensation_gain);

    // sanity check throttle is above zero and below current limited throttle
    if (throttle_thrust <= 0.0f) {
        throttle_thrust = 0.0f;
        limit.throttle_lower = true;
    }
    if (throttle_thrust >= throttle_thrust_max) {
        throttle_thrust = throttle_thrust_max;
        limit.throttle_upper = true;
    }

    // ensure that throttle_avg_max is between the input throttle and the maximum throttle
    throttle_avg_max = constrain_float(throttle_avg_max, throttle_thrust, throttle_thrust_max);

    // throttle providing maximum roll, pitch and yaw range
    // calculate the highest allowed average thrust that will provide maximum control range
    float throttle_thrust_best_rpy = MIN(0.5f, throttle_avg_max);

    float arg_L_NM = roll_thrust * radians(_P_DOT_max_degss) * _JXX_kgm2;
    float arg_M_NM = pitch_thrust * radians(_Q_DOT_max_degss) * _JYY_kgm2;
    float arg_N_NM = yaw_thrust * radians(_R_DOT_max_degss) * _JZZ_kgm2;
    //float arg_F_Z_N = -1.0 * _Mass_kg * 9.8F;
    float arg_F_Z_N = -1.731F;

    //hal.console->printf("\n\n Input r= %.2f, p= %.2f, y= %.2f, t= %.2f \n\n", roll_thrust, pitch_thrust, yaw_thrust, throttle_thrust);

   
    if(throttle_thrust < _throttle_trim)
    {
        for (i_0 = 0; i_0 < 22; i_0++)
        {
            // Product: '<S1>/Matrix Multiply' incorporates:
            //   Inport: '<Root>/F_Z_N'
            //   Inport: '<Root>/L_NM'
            //   Inport: '<Root>/M_NM'
            //   Inport: '<Root>/N_NM'

            rtb_CTz_Lookup_p = rtb_Binv[i_0 + 66] * arg_N_NM + (rtb_Binv[i_0 + 44] * arg_M_NM + (rtb_Binv[i_0 + 22] * arg_L_NM + rtb_Binv[i_0] * arg_F_Z_N));

            // Sqrt: '<Root>/Sqrt' incorporates:
            //   Constant: '<Root>/Constant'
            //   Gain: '<S1>/Gain3'
            //   Math: '<Root>/Square'
            //   Sum: '<Root>/Sum'

            
            //rtb_CTx_Lookup[i_0] = safe_sqrt(_Gain3_Gain * rtb_CTz_Lookup_p + _W_TRIM_RPM[i_0] * _W_TRIM_RPM[i_0] * (throttle_thrust/_throttle_trim));
            rtb_CTx_Lookup[i_0] = safe_sqrt(_Gain3_Gain * rtb_CTz_Lookup_p + _W_TRIM_RPM[i_0] * _W_TRIM_RPM[i_0]);
        }
    }
    else//throttle_thrust > _throttle_trim
    { 
        for (i_0 = 0; i_0 < 22; i_0++)
        {
            // Product: '<S1>/Matrix Multiply' incorporates:
            //   Inport: '<Root>/F_Z_N'
            //   Inport: '<Root>/L_NM'
            //   Inport: '<Root>/M_NM'
            //   Inport: '<Root>/N_NM'

            rtb_CTz_Lookup_p = rtb_Binv[i_0 + 66] * arg_N_NM + (rtb_Binv[i_0 + 44] * arg_M_NM + (rtb_Binv[i_0 + 22] * arg_L_NM + rtb_Binv[i_0] * arg_F_Z_N));

            // Sqrt: '<Root>/Sqrt' incorporates:
            //   Constant: '<Root>/Constant'
            //   Gain: '<S1>/Gain3'
            //   Math: '<Root>/Square'
            //   Sum: '<Root>/Sum'

            if(i_0==0||i_0==1||i_0==2||i_0==3||i_0==5||i_0==6||i_0==7||i_0==8)rtb_CTx_Lookup[i_0] = safe_sqrt(_Gain3_Gain * rtb_CTz_Lookup_p + _W_TRIM_RPM[i_0] * _W_TRIM_RPM[i_0] + 4.05F * (throttle_thrust-_throttle_trim) / (1-_throttle_trim) );
            else if(i_0==4||i_0==9)rtb_CTx_Lookup[i_0] = safe_sqrt(_Gain3_Gain * rtb_CTz_Lookup_p + _W_TRIM_RPM[i_0] * _W_TRIM_RPM[i_0] + 2.55852938F * (throttle_thrust-_throttle_trim) / (1-_throttle_trim) );
            else rtb_CTx_Lookup[i_0] = safe_sqrt(_Gain3_Gain * rtb_CTz_Lookup_p + _W_TRIM_RPM[i_0] * _W_TRIM_RPM[i_0] + 3.44697F * (throttle_thrust-_throttle_trim) / (1-_throttle_trim) );
        }
    }
               
    for (i_0 = 0; i_0 < 22; i_0++) {
        // Product: '<S1>/Matrix Multiply' incorporates:
        //   Inport: '<Root>/F_Z_N'
        //   Inport: '<Root>/L_NM'
        //   Inport: '<Root>/M_NM'
        //   Inport: '<Root>/N_NM'

        rtb_CTz_Lookup_p = rtb_Binv[i_0 + 66] * arg_N_NM + (rtb_Binv[i_0 + 44] * arg_M_NM + (rtb_Binv[i_0 + 22] * arg_L_NM + rtb_Binv[i_0] * arg_F_Z_N));

        // Sqrt: '<Root>/Sqrt' incorporates:
        //   Constant: '<Root>/Constant'
        //   Gain: '<S1>/Gain3'
        //   Math: '<Root>/Square'
        //   Sum: '<Root>/Sum'

        rtb_CTx_Lookup[i_0] = safe_sqrt(_Gain3_Gain * rtb_CTz_Lookup_p + _W_TRIM_RPM[i_0] * _W_TRIM_RPM[i_0]);
    }

    // SignalConversion generated from: '<Root>/RPM2PWM'
    rtb_CTz_Lookup[0] = rtb_CTx_Lookup[8];
    rtb_CTz_Lookup[1] = rtb_CTx_Lookup[7];
    rtb_CTz_Lookup[2] = rtb_CTx_Lookup[6];
    rtb_CTz_Lookup[3] = rtb_CTx_Lookup[5];
    rtb_CTz_Lookup[4] = rtb_CTx_Lookup[0];
    rtb_CTz_Lookup[5] = rtb_CTx_Lookup[1];
    rtb_CTz_Lookup[6] = rtb_CTx_Lookup[2];
    rtb_CTz_Lookup[7] = rtb_CTx_Lookup[3];
    rtb_CTz_Lookup[8] = rtb_CTx_Lookup[15];
    rtb_CTz_Lookup[9] = rtb_CTx_Lookup[14];
    rtb_CTz_Lookup[10] = rtb_CTx_Lookup[13];
    rtb_CTz_Lookup[11] = rtb_CTx_Lookup[12];
    rtb_CTz_Lookup[12] = rtb_CTx_Lookup[11];
    rtb_CTz_Lookup[13] = rtb_CTx_Lookup[10];
    for (i = 0; i < 6; i++) {
        rtb_CTz_Lookup[i + 14] = rtb_CTx_Lookup[i + 16];
    }

    rtb_CTz_Lookup[20] = rtb_CTx_Lookup[9];
    rtb_CTz_Lookup[21] = rtb_CTx_Lookup[4];

    // End of SignalConversion generated from: '<Root>/RPM2PWM'

    // // Lookup_n-D: '<Root>/RPM2PWM'
    // for (vcol = 0; vcol < 20; vcol++) {
    //     CONSCALE_CON_TBATT_CONPARA_CA_Y.THROTTLE[vcol] = look1_iflf_binlxpw(rtb_CTz_Lookup[vcol], CONSCALE_CON_TBATT_CONPARA_CA_P.RPM2PWM_bp01Data, CONSCALE_CON_TBATT_CONPARA_CA_P.RPM2PWM_tableData, 10U);
    // }

    // End of Lookup_n-D: '<Root>/RPM2PWM'

    

    
    // calculate amount of yaw we can fit into the throttle range
    // this is always equal to or less than the requested yaw from the pilot or rate controller
    float yaw_allowed = 1.0f; // amount of yaw we can fit in
    for (uint8_t ii = 0; ii < AP_MOTORS_MAX_NUM_MOTORS; ii++) {
        if (motor_enabled[ii]) {
            // calculate the thrust outputs for roll and pitch
            _thrust_rpyt_out[ii] = roll_thrust * _roll_factor[ii] + pitch_thrust * _pitch_factor[ii];

            // Check the maximum yaw control that can be used on this channel
            // Exclude any lost motors if thrust boost is enabled
            if (!is_zero(_yaw_factor[ii]) && (!_thrust_boost || ii != _motor_lost_index)) {
                const float thrust_rp_best_throttle = throttle_thrust_best_rpy + _thrust_rpyt_out[ii];
                float motor_room;
                if (is_positive(yaw_thrust * _yaw_factor[ii])) {
                    // room to upper limit
                    motor_room = 1.0 - thrust_rp_best_throttle;
                } else {
                    // room to lower limit
                    motor_room = thrust_rp_best_throttle;
                }
                const float motor_yaw_allowed = MAX(motor_room, 0.0)/fabsf(_yaw_factor[ii]);
                yaw_allowed = MIN(yaw_allowed, motor_yaw_allowed);
            }
        }
    }

    // calculate the maximum yaw control that can be used
    // todo: make _yaw_headroom 0 to 1
    float yaw_allowed_min = (float)_yaw_headroom * 0.001f;

    // increase yaw headroom to 50% if thrust boost enabled
    yaw_allowed_min = boost_ratio(0.5, yaw_allowed_min);

    // Let yaw access minimum amount of head room
    yaw_allowed = MAX(yaw_allowed, yaw_allowed_min);

    // Include the lost motor scaled by _thrust_boost_ratio to smoothly transition this motor in and out of the calculation
    if (_thrust_boost && motor_enabled[_motor_lost_index]) {
        // Check the maximum yaw control that can be used on this channel
        // Exclude any lost motors if thrust boost is enabled
        if (!is_zero(_yaw_factor[_motor_lost_index])){
            const float thrust_rp_best_throttle = throttle_thrust_best_rpy + _thrust_rpyt_out[_motor_lost_index];
            float motor_room;
            if (is_positive(yaw_thrust * _yaw_factor[_motor_lost_index])) {
                motor_room = 1.0 - thrust_rp_best_throttle;
            } else {
                motor_room = thrust_rp_best_throttle;
            }
            const float motor_yaw_allowed = MAX(motor_room, 0.0)/fabsf(_yaw_factor[_motor_lost_index]);
            yaw_allowed = boost_ratio(yaw_allowed, MIN(yaw_allowed, motor_yaw_allowed));
        }
    }

    if (fabsf(yaw_thrust) > yaw_allowed) {
        // not all commanded yaw can be used
        yaw_thrust = constrain_float(yaw_thrust, -yaw_allowed, yaw_allowed);
        limit.yaw = true;
    }

    // add yaw control to thrust outputs
    float rpy_low = 1.0f;   // lowest thrust value
    float rpy_high = -1.0f; // highest thrust value
    for (uint8_t ii = 0; ii < AP_MOTORS_MAX_NUM_MOTORS; ii++) {
        if (motor_enabled[ii]) {
            _thrust_rpyt_out[ii] = _thrust_rpyt_out[ii] + yaw_thrust * _yaw_factor[ii];

            // record lowest roll + pitch + yaw command
            if (_thrust_rpyt_out[ii] < rpy_low) {
                rpy_low = _thrust_rpyt_out[ii];
            }
            // record highest roll + pitch + yaw command
            // Exclude any lost motors if thrust boost is enabled
            if (_thrust_rpyt_out[ii] > rpy_high && (!_thrust_boost || ii != _motor_lost_index)) {
                rpy_high = _thrust_rpyt_out[ii];
            }
        }
    }
    // Include the lost motor scaled by _thrust_boost_ratio to smoothly transition this motor in and out of the calculation
    if (_thrust_boost) {
        // record highest roll + pitch + yaw command
        if (_thrust_rpyt_out[_motor_lost_index] > rpy_high && motor_enabled[_motor_lost_index]) {
            rpy_high = boost_ratio(rpy_high, _thrust_rpyt_out[_motor_lost_index]);
        }
    }

    // calculate any scaling needed to make the combined thrust outputs fit within the output range
    float rpy_scale = 1.0f;
    if (rpy_high - rpy_low > 1.0f) {
        rpy_scale = 1.0f / (rpy_high - rpy_low);
    }
    if (throttle_avg_max + rpy_low < 0) {
        rpy_scale = MIN(rpy_scale, -throttle_avg_max / rpy_low);
    }

    // calculate how close the motors can come to the desired throttle
    rpy_high *= rpy_scale;
    rpy_low *= rpy_scale;
    throttle_thrust_best_rpy = -rpy_low;
    float thr_adj = throttle_thrust - throttle_thrust_best_rpy;
    if (rpy_scale < 1.0f) {
        // Full range is being used by roll, pitch, and yaw.
        limit.roll = true;
        limit.pitch = true;
        limit.yaw = true;
        if (thr_adj > 0.0f) {
            limit.throttle_upper = true;
        }
        thr_adj = 0.0f;
    } else if (thr_adj < 0.0f) {
        // Throttle can't be reduced to desired value
        // todo: add lower limit flag and ensure it is handled correctly in altitude controller
        thr_adj = 0.0f;
    } else if (thr_adj > 1.0f - (throttle_thrust_best_rpy + rpy_high)) {
        // Throttle can't be increased to desired value
        thr_adj = 1.0f - (throttle_thrust_best_rpy + rpy_high);
        limit.throttle_upper = true;
    }

    // add scaled roll, pitch, constrained yaw and throttle for each motor
    const float throttle_thrust_best_plus_adj = throttle_thrust_best_rpy + thr_adj;
    for (uint8_t r = 0; r < AP_MOTORS_MAX_NUM_MOTORS; r++) {
        if (motor_enabled[r]) {
            if(throttle_thrust < _throttle_trim){
                _thrust_rpyt_out[r] = (throttle_thrust_best_plus_adj * _throttle_factor[r]) + (rpy_scale * _thrust_rpyt_out[r]);
                _thrust_rpyt_out[r] = constrain_float( look1_iflf_binlxpw(rtb_CTz_Lookup[r], _RPM2PWM_bp01Data, _RPM2PWM_tableData, 10U) * (throttle_thrust/_throttle_trim), 0.0F, 1.0F);
            }
            else{
                _thrust_rpyt_out[r] = constrain_float( look1_iflf_binlxpw(rtb_CTz_Lookup[r], _RPM2PWM_bp01Data, _RPM2PWM_tableData, 10U), 0.0F, 1.0F);
            }
        }
    }

    //           0 1 2 3 || 4 5 6 7 
    //  19 18 17 16 15 14||13 12 11 10 9 8
    //20                                    21
    //           0 1 2 3 || 4 5 6 7 
    //  17 16 15 14 13 13||12 12 11 10 9 8
    //18                                    19
    _thrust_rpyt_out[13] = _thrust_rpyt_out[14];
    _thrust_rpyt_out[14] = _thrust_rpyt_out[16];
    _thrust_rpyt_out[15] = _thrust_rpyt_out[17];
    _thrust_rpyt_out[16] = _thrust_rpyt_out[18];
    _thrust_rpyt_out[17] = _thrust_rpyt_out[19];
    _thrust_rpyt_out[18] = _thrust_rpyt_out[20];
    _thrust_rpyt_out[19] = _thrust_rpyt_out[21];
    

    // determine throttle thrust for harmonic notch
    // compensation_gain can never be zero
    _throttle_out = throttle_thrust_best_plus_adj / compensation_gain;

    // check for failed motor
    check_for_failed_motor(throttle_thrust_best_plus_adj);
}

// // output_armed - sends commands to the motors
// // includes new scaling stability patch
// void AP_MotorsYT::output_armed_stabilizing()
// {
//     // apply voltage and air pressure compensation
//     const float compensation_gain = thr_lin.get_compensation_gain(); // compensation for battery voltage and altitude

//     // pitch thrust input value, +/- 1.0
//     const float roll_thrust = (_roll_in + _roll_in_ff) * compensation_gain;

//     // pitch thrust input value, +/- 1.0
//     const float pitch_thrust = (_pitch_in + _pitch_in_ff) * compensation_gain;

//     // yaw thrust input value, +/- 1.0
//     float yaw_thrust = (_yaw_in + _yaw_in_ff) * compensation_gain;

//     // throttle thrust input value, 0.0 - 1.0
//     float throttle_thrust = get_throttle() * compensation_gain;

//     // throttle thrust average maximum value, 0.0 - 1.0
//     float throttle_avg_max = _throttle_avg_max * compensation_gain;

//     // throttle thrust maximum value, 0.0 - 1.0, If thrust boost is active then do not limit maximum thrust
//     const float throttle_thrust_max = boost_ratio(1.0, _throttle_thrust_max * compensation_gain);

//     // sanity check throttle is above zero and below current limited throttle
//     if (throttle_thrust <= 0.0f) {
//         throttle_thrust = 0.0f;
//         limit.throttle_lower = true;
//     }
//     if (throttle_thrust >= throttle_thrust_max) {
//         throttle_thrust = throttle_thrust_max;
//         limit.throttle_upper = true;
//     }

//     // ensure that throttle_avg_max is between the input throttle and the maximum throttle
//     throttle_avg_max = constrain_float(throttle_avg_max, throttle_thrust, throttle_thrust_max);

//     // throttle providing maximum roll, pitch and yaw range
//     // calculate the highest allowed average thrust that will provide maximum control range
//     float throttle_thrust_best_rpy = MIN(0.5f, throttle_avg_max);

//     // calculate throttle that gives most possible room for yaw which is the lower of:
//     //      1. 0.5f - (rpy_low+rpy_high)/2.0 - this would give the maximum possible margin above the highest motor and below the lowest
//     //      2. the higher of:
//     //            a) the pilot's throttle input
//     //            b) the point _throttle_rpy_mix between the pilot's input throttle and hover-throttle
//     //      Situation #2 ensure we never increase the throttle above hover throttle unless the pilot has commanded this.
//     //      Situation #2b allows us to raise the throttle above what the pilot commanded but not so far that it would actually cause the copter to rise.
//     //      We will choose #1 (the best throttle for yaw control) if that means reducing throttle to the motors (i.e. we favor reducing throttle *because* it provides better yaw control)
//     //      We will choose #2 (a mix of pilot and hover throttle) only when the throttle is quite low.  We favor reducing throttle instead of better yaw control because the pilot has commanded it

//     // Under the motor lost condition we remove the highest motor output from our calculations and let that motor go greater than 1.0
//     // To ensure control and maximum righting performance Hex and Octo have some optimal settings that should be used
//     // Y6               : MOT_YAW_HEADROOM = 350, ATC_RAT_RLL_IMAX = 1.0,   ATC_RAT_PIT_IMAX = 1.0,   ATC_RAT_YAW_IMAX = 0.5
//     // Octo-Quad (x8) x : MOT_YAW_HEADROOM = 300, ATC_RAT_RLL_IMAX = 0.375, ATC_RAT_PIT_IMAX = 0.375, ATC_RAT_YAW_IMAX = 0.375
//     // Octo-Quad (x8) + : MOT_YAW_HEADROOM = 300, ATC_RAT_RLL_IMAX = 0.75,  ATC_RAT_PIT_IMAX = 0.75,  ATC_RAT_YAW_IMAX = 0.375
//     // Usable minimums below may result in attitude offsets when motors are lost. Hex aircraft are only marginal and must be handles with care
//     // Hex              : MOT_YAW_HEADROOM = 0,   ATC_RAT_RLL_IMAX = 1.0,   ATC_RAT_PIT_IMAX = 1.0,   ATC_RAT_YAW_IMAX = 0.5
//     // Octo-Quad (x8) x : MOT_YAW_HEADROOM = 300, ATC_RAT_RLL_IMAX = 0.25,  ATC_RAT_PIT_IMAX = 0.25,  ATC_RAT_YAW_IMAX = 0.25
//     // Octo-Quad (x8) + : MOT_YAW_HEADROOM = 300, ATC_RAT_RLL_IMAX = 0.5,   ATC_RAT_PIT_IMAX = 0.5,   ATC_RAT_YAW_IMAX = 0.25
//     // Quads cannot make use of motor loss handling because it doesn't have enough degrees of freedom.

//     // calculate amount of yaw we can fit into the throttle range
//     // this is always equal to or less than the requested yaw from the pilot or rate controller
//     float yaw_allowed = 1.0f; // amount of yaw we can fit in
//     for (uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
//         if (motor_enabled[i]) {
//             // calculate the thrust outputs for roll and pitch
//             _thrust_rpyt_out[i] = roll_thrust * _roll_factor[i] + pitch_thrust * _pitch_factor[i];

//             // Check the maximum yaw control that can be used on this channel
//             // Exclude any lost motors if thrust boost is enabled
//             if (!is_zero(_yaw_factor[i]) && (!_thrust_boost || i != _motor_lost_index)) {
//                 const float thrust_rp_best_throttle = throttle_thrust_best_rpy + _thrust_rpyt_out[i];
//                 float motor_room;
//                 if (is_positive(yaw_thrust * _yaw_factor[i])) {
//                     // room to upper limit
//                     motor_room = 1.0 - thrust_rp_best_throttle;
//                 } else {
//                     // room to lower limit
//                     motor_room = thrust_rp_best_throttle;
//                 }
//                 const float motor_yaw_allowed = MAX(motor_room, 0.0)/fabsf(_yaw_factor[i]);
//                 yaw_allowed = MIN(yaw_allowed, motor_yaw_allowed);
//             }
//         }
//     }

//     // calculate the maximum yaw control that can be used
//     // todo: make _yaw_headroom 0 to 1
//     float yaw_allowed_min = (float)_yaw_headroom * 0.001f;

//     // increase yaw headroom to 50% if thrust boost enabled
//     yaw_allowed_min = boost_ratio(0.5, yaw_allowed_min);

//     // Let yaw access minimum amount of head room
//     yaw_allowed = MAX(yaw_allowed, yaw_allowed_min);

//     // Include the lost motor scaled by _thrust_boost_ratio to smoothly transition this motor in and out of the calculation
//     if (_thrust_boost && motor_enabled[_motor_lost_index]) {
//         // Check the maximum yaw control that can be used on this channel
//         // Exclude any lost motors if thrust boost is enabled
//         if (!is_zero(_yaw_factor[_motor_lost_index])){
//             const float thrust_rp_best_throttle = throttle_thrust_best_rpy + _thrust_rpyt_out[_motor_lost_index];
//             float motor_room;
//             if (is_positive(yaw_thrust * _yaw_factor[_motor_lost_index])) {
//                 motor_room = 1.0 - thrust_rp_best_throttle;
//             } else {
//                 motor_room = thrust_rp_best_throttle;
//             }
//             const float motor_yaw_allowed = MAX(motor_room, 0.0)/fabsf(_yaw_factor[_motor_lost_index]);
//             yaw_allowed = boost_ratio(yaw_allowed, MIN(yaw_allowed, motor_yaw_allowed));
//         }
//     }

//     if (fabsf(yaw_thrust) > yaw_allowed) {
//         // not all commanded yaw can be used
//         yaw_thrust = constrain_float(yaw_thrust, -yaw_allowed, yaw_allowed);
//         limit.yaw = true;
//     }

//     // add yaw control to thrust outputs
//     float rpy_low = 1.0f;   // lowest thrust value
//     float rpy_high = -1.0f; // highest thrust value
//     for (uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
//         if (motor_enabled[i]) {
//             _thrust_rpyt_out[i] = _thrust_rpyt_out[i] + yaw_thrust * _yaw_factor[i];

//             // record lowest roll + pitch + yaw command
//             if (_thrust_rpyt_out[i] < rpy_low) {
//                 rpy_low = _thrust_rpyt_out[i];
//             }
//             // record highest roll + pitch + yaw command
//             // Exclude any lost motors if thrust boost is enabled
//             if (_thrust_rpyt_out[i] > rpy_high && (!_thrust_boost || i != _motor_lost_index)) {
//                 rpy_high = _thrust_rpyt_out[i];
//             }
//         }
//     }
//     // Include the lost motor scaled by _thrust_boost_ratio to smoothly transition this motor in and out of the calculation
//     if (_thrust_boost) {
//         // record highest roll + pitch + yaw command
//         if (_thrust_rpyt_out[_motor_lost_index] > rpy_high && motor_enabled[_motor_lost_index]) {
//             rpy_high = boost_ratio(rpy_high, _thrust_rpyt_out[_motor_lost_index]);
//         }
//     }

//     // calculate any scaling needed to make the combined thrust outputs fit within the output range
//     float rpy_scale = 1.0f;
//     if (rpy_high - rpy_low > 1.0f) {
//         rpy_scale = 1.0f / (rpy_high - rpy_low);
//     }
//     if (throttle_avg_max + rpy_low < 0) {
//         rpy_scale = MIN(rpy_scale, -throttle_avg_max / rpy_low);
//     }

//     // calculate how close the motors can come to the desired throttle
//     rpy_high *= rpy_scale;
//     rpy_low *= rpy_scale;
//     throttle_thrust_best_rpy = -rpy_low;
//     float thr_adj = throttle_thrust - throttle_thrust_best_rpy;
//     if (rpy_scale < 1.0f) {
//         // Full range is being used by roll, pitch, and yaw.
//         limit.roll = true;
//         limit.pitch = true;
//         limit.yaw = true;
//         if (thr_adj > 0.0f) {
//             limit.throttle_upper = true;
//         }
//         thr_adj = 0.0f;
//     } else if (thr_adj < 0.0f) {
//         // Throttle can't be reduced to desired value
//         // todo: add lower limit flag and ensure it is handled correctly in altitude controller
//         thr_adj = 0.0f;
//     } else if (thr_adj > 1.0f - (throttle_thrust_best_rpy + rpy_high)) {
//         // Throttle can't be increased to desired value
//         thr_adj = 1.0f - (throttle_thrust_best_rpy + rpy_high);
//         limit.throttle_upper = true;
//     }

//     // add scaled roll, pitch, constrained yaw and throttle for each motor
//     const float throttle_thrust_best_plus_adj = throttle_thrust_best_rpy + thr_adj;
//     for (uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
//         if (motor_enabled[i]) {
//             _thrust_rpyt_out[i] = (throttle_thrust_best_plus_adj * _throttle_factor[i]) + (rpy_scale * _thrust_rpyt_out[i]);
//             //hal.console->printf("\n\n Output M_%.u = %.2f \n\n", i+1, _thrust_rpyt_out[i]);

//         }
//     }

//     // determine throttle thrust for harmonic notch
//     // compensation_gain can never be zero
//     _throttle_out = throttle_thrust_best_plus_adj / compensation_gain;

//     // check for failed motor
//     check_for_failed_motor(throttle_thrust_best_plus_adj);
// }

// check for failed motor
//   should be run immediately after output_armed_stabilizing
//   first argument is the sum of:
//      a) throttle_thrust_best_rpy : throttle level (from 0 to 1) providing maximum roll, pitch and yaw range without climbing
//      b) thr_adj: the difference between the pilot's desired throttle and throttle_thrust_best_rpy
//   records filtered motor output values in _thrust_rpyt_out_filt array
//   sets thrust_balanced to true if motors are balanced, false if a motor failure is detected
//   sets _motor_lost_index to index of failed motor
void AP_MotorsYT::check_for_failed_motor(float throttle_thrust_best_plus_adj)
{
    // record filtered and scaled thrust output for motor loss monitoring purposes
    float alpha = _dt / (_dt + 0.5f);
    for (uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
        if (motor_enabled[i]) {
            _thrust_rpyt_out_filt[i] += alpha * (_thrust_rpyt_out[i] - _thrust_rpyt_out_filt[i]);
        }
    }

    float rpyt_high = 0.0f;
    float rpyt_sum = 0.0f;
    uint8_t number_motors = 0.0f;
    for (uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
        if (motor_enabled[i]) {
            number_motors += 1;
            rpyt_sum += _thrust_rpyt_out_filt[i];
            // record highest filtered thrust command
            if (_thrust_rpyt_out_filt[i] > rpyt_high) {
                rpyt_high = _thrust_rpyt_out_filt[i];
                // hold motor lost index constant while thrust boost is active
                if (!_thrust_boost) {
                    _motor_lost_index = i;
                }
            }
        }
    }

    float thrust_balance = 1.0f;
    if (rpyt_sum > 0.1f) {
        thrust_balance = rpyt_high * number_motors / rpyt_sum;
    }
    // ensure thrust balance does not activate for multirotors with less than 6 motors
    if (number_motors >= 6 && thrust_balance >= 1.5f && _thrust_balanced) {
        _thrust_balanced = false;
    }
    if (thrust_balance <= 1.25f && !_thrust_balanced) {
        _thrust_balanced = true;
    }

    // check to see if thrust boost is using more throttle than _throttle_thrust_max
    if ((_throttle_thrust_max * thr_lin.get_compensation_gain() > throttle_thrust_best_plus_adj) && (rpyt_high < 0.9f) && _thrust_balanced) {
        _thrust_boost = false;
    }
}

// output_test_seq - spin a motor at the pwm value specified
//  motor_seq is the motor's sequence number from 1 to the number of motors on the frame
//  pwm value is an actual pwm value that will be output, normally in the range of 1000 ~ 2000
void AP_MotorsYT::_output_test_seq(uint8_t motor_seq, int16_t pwm)
{
    // loop through all the possible orders spinning any motors that match that description
    for (uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
        if (motor_enabled[i] && _test_order[i] == motor_seq) {
            // turn on this motor
            rc_write(i, pwm);
        }
    }
}

// output_test_num - spin a motor connected to the specified output channel
//  (should only be performed during testing)
//  If a motor output channel is remapped, the mapped channel is used.
//  Returns true if motor output is set, false otherwise
//  pwm value is an actual pwm value that will be output, normally in the range of 1000 ~ 2000
bool AP_MotorsYT::output_test_num(uint8_t output_channel, int16_t pwm)
{
    if (!armed()) {
        return false;
    }

    // Is channel in supported range?
    if (output_channel > AP_MOTORS_MAX_NUM_MOTORS - 1) {
        return false;
    }

    // Is motor enabled?
    if (!motor_enabled[output_channel]) {
        return false;
    }

    rc_write(output_channel, pwm); // output
    return true;
}

// add_motor
void AP_MotorsYT::add_motor_raw(int8_t motor_num, float roll_fac, float pitch_fac, float yaw_fac, uint8_t testing_order, float throttle_factor)
{
    if (initialised_ok()) {
        // do not allow motors to be set if the current frame type has init correctly
        return;
    }

    // ensure valid motor number is provided
    if (motor_num >= 0 && motor_num < AP_MOTORS_MAX_NUM_MOTORS) {

        //hal.console->printf("\n\n MAX YTChannel %u", AP_MOTORS_MAX_NUM_MOTORS);
        // enable motor
        motor_enabled[motor_num] = true;

        // set roll, pitch, yaw and throttle factors
        _roll_factor[motor_num] = roll_fac;
        _pitch_factor[motor_num] = pitch_fac;
        _yaw_factor[motor_num] = yaw_fac;
        _throttle_factor[motor_num] = throttle_factor;

        // set order that motor appears in test
        _test_order[motor_num] = testing_order;

        //hal.console->printf("\n\n line896 add_motor_raw, motor_num= %u \n\n", motor_num+1);

        // call parent class method
        add_motor_num(motor_num);
    }
}

// add_motor using just position and prop direction - assumes that for each motor, roll and pitch factors are equal
void AP_MotorsYT::add_motor(int8_t motor_num, float angle_degrees, float yaw_factor, uint8_t testing_order)
{
    add_motor(motor_num, angle_degrees, angle_degrees, yaw_factor, testing_order);
}

// add_motor using position and prop direction. Roll and Pitch factors can differ (for asymmetrical frames)
void AP_MotorsYT::add_motor(int8_t motor_num, float roll_factor_in_degrees, float pitch_factor_in_degrees, float yaw_factor, uint8_t testing_order)
{
    add_motor_raw(
        motor_num,
        cosf(radians(roll_factor_in_degrees + 90)),
        cosf(radians(pitch_factor_in_degrees)),
        yaw_factor,
        testing_order);
}

// remove_motor - disabled motor and clears all roll, pitch, throttle factors for this motor
void AP_MotorsYT::remove_motor(int8_t motor_num)
{
    // ensure valid motor number is provided
    if (motor_num >= 0 && motor_num < AP_MOTORS_MAX_NUM_MOTORS) {
        // disable the motor, set all factors to zero
        motor_enabled[motor_num] = false;
        _roll_factor[motor_num] = 0.0f;
        _pitch_factor[motor_num] = 0.0f;
        _yaw_factor[motor_num] = 0.0f;
        _throttle_factor[motor_num] = 0.0f;
    }
}

void AP_MotorsYT::add_motors(const struct DuctDef *motors, uint8_t num_motors)
{
    for (uint8_t i=0; i<num_motors; i++) {
        const auto &motor = motors[i];
        add_motor(i, motor.angle_degrees, motor.yaw_factor, motor.testing_order);
    }
}
void AP_MotorsYT::add_motors_raw(const struct DuctDefRaw *motors, uint8_t num_motors)
{
    for (uint8_t i=0; i<num_motors; i++) {
        const auto &m = motors[i];
        add_motor_raw(i, m.roll_fac, m.pitch_fac, m.yaw_fac, m.testing_order);
    }
}


#if AP_MOTORS_FRAME_OCTAQUAD_ENABLED
bool AP_MotorsYT::setup_yt_matrix(motor_frame_type frame_type)
{
    _mav_type = MAV_TYPE_VTOL_RESERVED2;
    _frame_class_string = "YT";
    switch (frame_type) {
    case MOTOR_FRAME_TYPE_PLUS: {
        _frame_type_string = "PLUS";
        static const AP_MotorsYT::DuctDefRaw motors[] {
            {  0.83f,  0.34f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  1 },
            { -0.67f, -0.32f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  2 },
            {  0.67f, -0.32f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 3 },
            { -0.50f, -1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 4 },
            {  1.00f,  1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 5 },
            { -0.83f,  0.34f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 6 },
            { -1.00f,  1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  7 },
            {  0.50f, -1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  8 },
            {  0.83f,  0.34f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  9 },
            { -0.67f, -0.32f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  10 },
            {  0.67f, -0.32f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 11 },
            { -0.50f, -1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 12 },
            {  1.00f,  1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 13 },
            { -0.83f,  0.34f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 14 },
            { -1.00f,  1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  15 },
            {  0.50f, -1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  16 },
            { -0.50f, -1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 17 },
            {  1.00f,  1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 18 },
            { -0.83f,  0.34f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 19 },
            { -1.00f,  1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  20 },
            { -0.83f,  0.34f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 21 },
            { -1.00f,  1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  22 },
        };
        add_motors_raw(motors, ARRAY_SIZE(motors));
        break;
    }
    case MOTOR_FRAME_TYPE_X: {
        _frame_type_string = "X";
        static const AP_MotorsYT::DuctDefRaw motors[] {
            {  0.83f,  0.34f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  1 },
            { -0.67f, -0.32f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  2 },
            {  0.67f, -0.32f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 3 },
            { -0.50f, -1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 4 },
            {  1.00f,  1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 5 },
            { -0.83f,  0.34f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 6 },
            { -1.00f,  1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  7 },
            {  0.50f, -1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  8 },
            {  0.83f,  0.34f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  9 },
            { -0.67f, -0.32f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  10 },
            {  0.67f, -0.32f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 11 },
            { -0.50f, -1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 12 },
            {  1.00f,  1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 13 },
            { -0.83f,  0.34f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 14 },
            { -1.00f,  1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  15 },
            {  0.50f, -1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  16 },
            { -0.50f, -1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 17 },
            {  1.00f,  1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 18 },
            { -0.83f,  0.34f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 19 },
            { -1.00f,  1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  20 },
            { -0.83f,  0.34f, AP_MOTORS_MATRIX_YAW_FACTOR_CCW, 21 },
            { -1.00f,  1.00f, AP_MOTORS_MATRIX_YAW_FACTOR_CW,  22 },
        };
        add_motors_raw(motors, ARRAY_SIZE(motors));
        break;
    }
    default:
        // octaquad frame class does not support this frame type
        return false;
    } //octaquad
    return true;
}
#endif // AP_MOTORS_FRAME_OCTAQUAD_ENABLED


void AP_MotorsYT::setup_motors(motor_frame_class frame_class, motor_frame_type frame_type)
{
    // remove existing motors
    for (int8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
        remove_motor(i);
    }
    set_initialised_ok(false);
    bool success = true;

    //
    success = setup_yt_matrix(frame_type);
    // normalise factors to magnitude 0.5
    normalise_rpy_factors();

    if (!success) {
        _frame_class_string = "UNSUPPORTED";
    }
    set_initialised_ok(success);
}

// normalizes the roll, pitch and yaw factors so maximum magnitude is 0.5
// normalizes throttle factors so max value is 1 and no value is less than 0
void AP_MotorsYT::normalise_rpy_factors()
{
    float roll_fac = 0.0f;
    float pitch_fac = 0.0f;
    float yaw_fac = 0.0f;
    float throttle_fac = 0.0f;

    // find maximum roll, pitch and yaw factors
    for (uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
        if (motor_enabled[i]) {
            roll_fac = MAX(roll_fac,fabsf(_roll_factor[i]));
            pitch_fac = MAX(pitch_fac,fabsf(_pitch_factor[i]));
            yaw_fac = MAX(yaw_fac,fabsf(_yaw_factor[i]));
            throttle_fac = MAX(throttle_fac,MAX(0.0f,_throttle_factor[i]));
        }
    }

    // scale factors back to -0.5 to +0.5 for each axis
    for (uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
        if (motor_enabled[i]) {
            if (!is_zero(roll_fac)) {
                _roll_factor[i] = 0.5f * _roll_factor[i] / roll_fac;
            }
            if (!is_zero(pitch_fac)) {
                _pitch_factor[i] = 0.5f * _pitch_factor[i] / pitch_fac;
            }
            if (!is_zero(yaw_fac)) {
                _yaw_factor[i] = 0.5f * _yaw_factor[i] / yaw_fac;
            }
            if (!is_zero(throttle_fac)) {
                _throttle_factor[i] = MAX(0.0f,_throttle_factor[i] / throttle_fac);
            }
        }
    }
}


/*
  call vehicle supplied thrust compensation if set. This allows
  vehicle code to compensate for vehicle specific motor arrangements
  such as tiltrotors or tiltwings
*/
void AP_MotorsYT::thrust_compensation(void)
{
    if (_thrust_compensation_callback) {
        _thrust_compensation_callback(_thrust_rpyt_out, AP_MOTORS_MAX_NUM_MOTORS);
    }
}

/*
  disable the use of motor torque to control yaw. Used when an
  external mechanism such as vectoring is used for yaw control
*/
void AP_MotorsYT::disable_yaw_torque(void)
{
    for (uint8_t i = 0; i < AP_MOTORS_MAX_NUM_MOTORS; i++) {
        _yaw_factor[i] = 0;
    }
}

#if APM_BUILD_TYPE(APM_BUILD_UNKNOWN)
// examples can pull values direct
float AP_MotorsYT::get_thrust_rpyt_out(uint8_t i) const
{
    if (i < AP_MOTORS_MAX_NUM_MOTORS) {
        return _thrust_rpyt_out[i];
    }
    return 0.0;
}

bool AP_MotorsYT::get_factors(uint8_t i, float &roll, float &pitch, float &yaw, float &throttle, uint8_t &testing_order) const
{
    if ((i < AP_MOTORS_MAX_NUM_MOTORS) && motor_enabled[i]) {
        roll = _roll_factor[i];
        pitch = _pitch_factor[i];
        yaw = _yaw_factor[i];
        throttle = _throttle_factor[i];
        testing_order = _test_order[i];
        return true;
    }
    return false;
}
#endif

// singleton instance
AP_MotorsYT *AP_MotorsYT::_singleton;
