/// @file	AP_MotorsYT.h
/// @brief	Motor control class for Matrixcopters
#pragma once

#include <AP_Common/AP_Common.h>
#include <AP_Math/AP_Math.h>        // ArduPilot Mega Vector/Matrix math Library
#include <RC_Channel/RC_Channel.h>     // RC Channel Library
#include "AP_MotorsMulticopter.h"
#include "rt_nonfinite.h"
#include <cmath>

#define AP_MOTORS_MATRIX_YAW_FACTOR_CW   -1
#define AP_MOTORS_MATRIX_YAW_FACTOR_CCW   1

/// @class      AP_MotorsYT
class AP_MotorsYT : public AP_MotorsMulticopter {
public:

    /// Constructor
    AP_MotorsYT(uint16_t speed_hz = AP_MOTORS_SPEED_DEFAULT) :
        AP_MotorsMulticopter(speed_hz)
    {
        if (_singleton != nullptr) {
            AP_HAL::panic("AP_MotorsYT must be singleton");
        }
        _singleton = this;
    };

    // get singleton instance
    static AP_MotorsYT *get_singleton() {
        return _singleton;
    }

    // init
    virtual void        init(motor_frame_class frame_class, motor_frame_type frame_type) override;

#if AP_SCRIPTING_ENABLED
    // Init to be called from scripting
    virtual bool        init(uint8_t expected_num_motors);

    // Set throttle factor from scripting
    bool                set_throttle_factor(int8_t motor_num, float throttle_factor);

#endif // AP_SCRIPTING_ENABLED

    // set frame class (i.e. quad, hexa, heli) and type (i.e. x, plus)
    void                set_frame_class_and_type(motor_frame_class frame_class, motor_frame_type frame_type) override;

    // set update rate to motors - a value in hertz
    // you must have setup_motors before calling this
    void                set_update_rate(uint16_t speed_hz) override;

    // output_test_num - spin a motor connected to the specified output channel
    //  (should only be performed during testing)
    //  If a motor output channel is remapped, the mapped channel is used.
    //  Returns true if motor output is set, false otherwise
    //  pwm value is an actual pwm value that will be output, normally in the range of 1000 ~ 2000
    bool                output_test_num(uint8_t motor, int16_t pwm);

    // output_to_motors - sends minimum values out to the motors
    virtual void        output_to_motors() override;

    // get_motor_mask - returns a bitmask of which outputs are being used for motors (1 means being used)
    //  this can be used to ensure other pwm outputs (i.e. for servos) do not conflict
    uint32_t            get_motor_mask() override;

    // return number of motor that has failed.  Should only be called if get_thrust_boost() returns true
    uint8_t             get_lost_motor() const override { return _motor_lost_index; }

    // return the roll factor of any motor, this is used for tilt rotors and tail sitters
    // using copter motors for forward flight
    float               get_roll_factor(uint8_t i) override { return _roll_factor[i]; }
    // return the pitch factor of any motor
    float               get_pitch_factor(uint8_t i) override { return _pitch_factor[i]; }

    // disable the use of motor torque to control yaw. Used when an external mechanism such
    // as vectoring is used for yaw control
    void                disable_yaw_torque(void) override;

    // add_motor using raw roll, pitch, throttle and yaw factors
    void                add_motor_raw(int8_t motor_num, float roll_fac, float pitch_fac, float yaw_fac, uint8_t testing_order, float throttle_factor = 1.0f);

    // same structure, but with floats.
    struct DuctDef {
        float angle_degrees;
        float yaw_factor;
        uint8_t testing_order;
    };

    // method to add many motors specified in a structure:
    void add_motors(const struct DuctDef *motors, uint8_t num_motors);

    // structure used for initialising motors that add have separate
    // roll/pitch/yaw factors.  Note that this does *not* include
    // the final parameter for the add_motor_raw call - throttle
    // factor as that is only used in the scripting binding, not in
    // the static motors at the moment.
    struct DuctDefRaw {
        float roll_fac;
        float pitch_fac;
        float yaw_fac;
        uint8_t testing_order;
    };
    void add_motors_raw(const struct DuctDefRaw *motors, uint8_t num_motors);

    // pull values direct, (examples only)
    float get_thrust_rpyt_out(uint8_t i) const;
    bool get_factors(uint8_t i, float &roll, float &pitch, float &yaw, float &throttle, uint8_t &testing_order) const;

protected:
    // output - sends commands to the motors
    void                output_armed_stabilizing() override;

    // check for failed motor
    void                check_for_failed_motor(float throttle_thrust_best);

    // add_motor using just position and yaw_factor (or prop direction)
    void                add_motor(int8_t motor_num, float angle_degrees, float yaw_factor, uint8_t testing_order);

    // add_motor using separate roll and pitch factors (for asymmetrical frames) and prop direction
    void                add_motor(int8_t motor_num, float roll_factor_in_degrees, float pitch_factor_in_degrees, float yaw_factor, uint8_t testing_order);

    // remove_motor
    void                remove_motor(int8_t motor_num);

    // configures the motors for the defined frame_class and frame_type
    virtual void        setup_motors(motor_frame_class frame_class, motor_frame_type frame_type);

    // normalizes the roll, pitch and yaw factors so maximum magnitude is 0.5
    void                normalise_rpy_factors();

    // call vehicle supplied thrust compensation if set
    void                thrust_compensation(void) override;

    const char*         _get_frame_string() const override { return _frame_class_string; }
    const char*         get_type_string() const override { return _frame_type_string; }

    // output_test_seq - spin a motor at the pwm value specified
    //  motor_seq is the motor's sequence number from 1 to the number of motors on the frame
    //  pwm value is an actual pwm value that will be output, normally in the range of 1000 ~ 2000
    virtual void        _output_test_seq(uint8_t motor_seq, int16_t pwm) override;

    float               _roll_factor[AP_MOTORS_MAX_NUM_MOTORS]; // each motors contribution to roll
    float               _pitch_factor[AP_MOTORS_MAX_NUM_MOTORS]; // each motors contribution to pitch
    float               _yaw_factor[AP_MOTORS_MAX_NUM_MOTORS];  // each motors contribution to yaw (normally 1 or -1)
    float               _throttle_factor[AP_MOTORS_MAX_NUM_MOTORS];  // each motors contribution to throttle 0~1
    float               _thrust_rpyt_out[AP_MOTORS_MAX_NUM_MOTORS]; // combined roll, pitch, yaw and throttle outputs to motors in 0~1 range
    uint8_t             _test_order[AP_MOTORS_MAX_NUM_MOTORS];  // order of the motors in the test sequence

    // motor failure handling
    float               _thrust_rpyt_out_filt[AP_MOTORS_MAX_NUM_MOTORS];    // filtered thrust outputs with 1 second time constant
    uint8_t             _motor_lost_index;  // index number of the lost motor

    motor_frame_class   _active_frame_class; // active frame class (i.e. quad, hexa, octa, etc)
    motor_frame_type    _active_frame_type;  // active frame type (i.e. plus, x, v, etc)

    const char*         _frame_class_string = ""; // string representation of frame class
    const char*         _frame_type_string = "";  //  string representation of frame type

private:

    // helper to return value scaled between boost and normal based on the value of _thrust_boost_ratio
    float boost_ratio(float boost_value, float normal_value) const;

    // setup motors matrix
    bool setup_yt_matrix(motor_frame_type frame_type);

    // YTMath functions
    //void diag(const float *v, float *d);
    float look1_iflf_binlxpw(float u0, const float bp0[], const float table[], uint32_t maxIndex);
    void mldivide(const float *A, float *B);
    void xgetrf(float *A, int *ipiv, int *info);
    // float xnrm2(int32_t n, const float *x, int32_t ix0);//float xnrm2(int32_t n, const float x[80], int32_t ix0);
    // float xnrm2_j(int32_t n, const float *x, int32_t ix0);//float xnrm2_j(int32_t n, const float x[4], int32_t ix0);
    // void xaxpy_m0(int32_t n, float a, const float *x, int32_t ix0, float *y, int32_t iy0);//void xaxpy_m0(int32_t n, float a, const float x[20], int32_t ix0, float y[80], int32_t iy0);
    // void xaxpy_m(int32_t n, float a, const float *x, int32_t ix0, float *y, int32_t iy0);//void AP_MotorsYT::xaxpy_m(int32_t n, float a, const float x[80], int32_t ix0, float y[20], int32_t iy0)
    // float xdotc(int32_t n, const float x[80], int32_t ix0, const float y[80], int32_t iy0);//float xdotc(int32_t n, const float x[80], int32_t ix0, const float y[80], int32_t iy0);
    // void xaxpy(int32_t n, float a, int32_t ix0, float y[80], int32_t iy0);//void xaxpy(int32_t n, float a, int32_t ix0, float y[80], int32_t iy0);
    // float xdotc_e(int32_t n, const float x[16], int32_t ix0,const float y[16], int32_t iy0);//float xdotc_e(int32_t n, const float x[16], int32_t ix0,const float y[16], int32_t iy0);
    // void xaxpy_m0a(int32_t n, float a, int32_t ix0, float y[16], int32_t iy0);//void xaxpy_m0a(int32_t n, float a, int32_t ix0, float y[16], int32_t iy0);
    // void xscal(float a, float x[80], int32_t ix0);//void xscal(float a, float x[80], int32_t ix0);
    // void xscal_c(float a, float x[16], int32_t ix0);//void xscal_c(float a, float x[16], int32_t ix0);
    // void xswap(float x[16], int32_t ix0, int32_t iy0);//void xswap(float x[16], int32_t ix0, int32_t iy0);
    // void xswap_m(float x[80], int32_t ix0, int32_t iy0);//void xswap_m(float x[80], int32_t ix0, int32_t iy0);
    // void xrotg(float *a, float *b, float *c, float *s);
    // void xrot(float x[16], int32_t ix0, int32_t iy0, float c, float s);//void xrot(float x[16], int32_t ix0, int32_t iy0, float c, float s);
    // void xrot_f(float x[80], int32_t ix0, int32_t iy0, float c, float s);//void xrot_f(float x[80], int32_t ix0, int32_t iy0, float c, float s);
    // void _svd(const float A[80], float U[80], float s[4], float V[16]);// void _svd(const float A[80], float U[80], float s[4], float V[16]);

    // YTscaled parameters
    const float _P_DOT_max_degss = 8.8F;//7.1
    const float _Q_DOT_max_degss = 22.0F;//19.2
    const float _R_DOT_max_degss = 5.59F;//2.236
    const float _JXX_kgm2 = 541.35F;//0.54135186
    const float _JYY_kgm2 = 190.0F;//0.950637144
    const float _JZZ_kgm2 = 143.5F;//1.435035916
    const float _Mass_kg = 12.9F;
    const float _H_DDOT_Max_mps2 = -0.47F;

    const float _DF_DEG_Value[22] {               30.0F, 30.0F, 30.0F, 30.0F, 180.0F, 
        30.0F, 30.0F, 30.0F, 30.0F, 180.0F,
                                            30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 
    30.0F, 30.0F, 30.0F, 30.0F, 30.0F, 30.0F };

    // float _DF_DEG_Value[20] { 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F,
    //      10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F, 10.0F };
    const float _CTx_Lookup_bp01Data[4]   // Computed Parameter: CTx_Lookup_bp01Data
                                    //  Referenced by: '<S1>/CTx_Lookup'
                                     { 0.0F, 30.0F, 40.0F, 180.0F };
    const float _CTx_Lookup_tableData[4]  // Computed Parameter: CTx_Lookup_tableData
                                    //  Referenced by: '<S1>/CTx_Lookup'
                                    { 0.1824F, 0.04253F, -0.1824F, -0.9622 };
    const float _CTz_Lookup_bp01Data[4]   // Computed Parameter: CTz_Lookup_bp01Data
                                    //  Referenced by: '<S1>/CTz_Lookup'
                                    { 0.0F, 30.0F, 40.0F, 180.0F };
    const float _CTz_Lookup_tableData[4]  // Computed Parameter: CTz_Lookup_tableData
                                    //  Referenced by: '<S1>/CTz_Lookup'
                                    { 0.4392F, 0.4661F, 0.4392F, 0.0F };
    const float _CQ_Lookup_bp01Data[4]    // Computed Parameter: CQ_Lookup_bp01Data
                                    //  Referenced by: '<S1>/CQ_Lookup'
                                    { 0.0F, 30.0F, 40.0F, 180.0F };
    const float _CQ_Lookup_tableData[4]   // Computed Parameter: CQ_Lookup_tableData
                                    //  Referenced by: '<S1>/CQ_Lookup'
                                    { 0.01164F, 0.01356F, 0.01164F, 0.01164F };
    //10-27 
    const float _vehicle_DUCT_RotDir[22] { 1.0F, -1.0F, 1.0F, -1.0F, 1.0F, -1.0F, 1.0F, -1.0F, 1.0F, -1.0F, 1.0F, -1.0F, 1.0F,
        -1.0F, 1.0F, -1.0F, -1.0F, 1.0F, -1.0F, 1.0F, -1.0F, 1.0F };
    //10-24 update:
    // const float _vehicle_DUCT_LeverArm_m[66]{ 0.443F, 0.176F, 0.0F, 0.443F, 0.251F, 0.0F, 0.443F, 0.326F, 0.0F, 0.443F, 0.401F, 0.0F, 
    //     0.443F, 0.496F, -0.03F, 
    //     0.443F, -0.176F, 0.0F, 0.443F, -0.251F, 0.0F, 0.443F, -0.326F, 0.0F, 0.443F, -0.401F, 0.0F, 
    //     0.443F, -0.496F, -0.03F, 
    //     -0.34700000000000003F, 0.125F, -0.08F, -0.34700000000000003F, 0.2F, -0.08F, 
    //     -0.34700000000000003F, 0.275F, -0.08F, -0.34700000000000003F, 0.35000000000000003F, -0.08F, 
    //     -0.34700000000000003F, 0.425F, -0.08F, -0.34700000000000003F, 0.5F, -0.08F, 
    //     -0.34700000000000003F, -0.125F, -0.08F, -0.34700000000000003F, -0.2F, -0.08F, -0.34700000000000003F, -0.275F, -0.08F,
    //     -0.34700000000000003F, -0.35000000000000003F, -0.08F, -0.34700000000000003F,
    //     -0.425F, -0.08F, -0.34700000000000003F, -0.5F, -0.08F };
    // //10-26 merge motor 13&14 motor 15&16:
    const float _vehicle_DUCT_LeverArm_m[66]{ 0.443F, 0.176F, 0.0F, 0.443F, 0.251F, 0.0F, 0.443F, 0.326F, 0.0F, 0.443F, 0.401F, 0.0F, 
        0.443F, 0.496F, -0.03F, 
        0.443F, -0.176F, 0.0F, 0.443F, -0.251F, 0.0F, 0.443F, -0.326F, 0.0F, 0.443F, -0.401F, 0.0F, 
        0.443F, -0.496F, -0.03F, 
        -0.347F, 0.1625F, -0.08F, -0.347F, 0.1625F, -0.08F, 
        -0.347F, 0.275F, -0.08F, -0.347F, 0.35F, -0.08F, 
        -0.347F, 0.425F, -0.08F, -0.347F, 0.5F, -0.08F, 
        -0.347F, -0.1625F, -0.08F, -0.347F, -0.1625F, -0.08F, 
        -0.347F, -0.275F, -0.08F, -0.347F, -0.35F, -0.08F, 
        -0.347F, -0.425F, -0.08F, -0.347F, -0.5F, -0.08F };
    const float _Gain3_Gain = 1.0E+8F;
    const float _W_TRIM_RPM[22] { 37920.7656F, 37920.7656F, 37920.7656F, 37920.7656F, 23919.2482F, 37920.7656F,
    37920.7656F, 37920.7656F, 37920.7656F, 23919.2482F, 34621.6641F, 34621.6641F,
    34621.6641F, 34621.6641F, 34621.6641F, 34621.6641F, 34621.6641F, 34621.6641F,
    34621.6641F, 34621.6641F, 34621.6641F, 34621.6641F }; 
    const float _thrust_trim [20] { 0.6152F, 0.6152F, 0.6152F, 0.6152F, 0.6152F, 0.6152F, 0.6152F, 0.6152F, 
        0.6833F, 0.6833F, 0.8018F, 0.8018F, 0.8018F, 0.8018F,
        0.8018F, 0.8018F, 0.8018F, 0.8018F, 0.6833F, 0.6833F };
    const float _throttle_trim = 0.5F;
    const float _throttle_takeoff = 0.1536F;
    const float _throttle_transition1 = 0.3F;
    const float _throttle_transition2 = 0.35F;
    const float _boost_max = 1.2F;
    const float _boost_min = 0.2F;
    const float _boost_normal = 1.0F;
    
    const float _RPM2PWM_tableData[11]    // Computed Parameter: RPM2PWM_tableData
                                    //  Referenced by: '<Root>/RPM2PWM'
    { 0.0F, 0.1F, 0.2F, 0.3F, 0.4F, 0.5F, 0.6F, 0.7F, 0.8F, 0.9F, 1.0F };

    const float _RPM2PWM_bp01Data[11]     // Computed Parameter: RPM2PWM_bp01Data
                                    //  Referenced by: '<Root>/RPM2PWM'
    { 0.0F, 9021.5F, 14953.5F, 19127.0F, 23068.5F, 26649.0F, 31687.5F, 35064.5F,
    38347.5F, 41460.5F, 43682.0F };
    const float _weight[22]  { 1.0F, 1.0F, 1.0F, 1.0F, 3.5F, 1.0F, 1.0F, 1.0F, 1.0F, 3.5F,
        1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F, 1.0F };

    const float _weight_diag[484]   {1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 3.5F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 3.5F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F,
                                    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F,
                                };
    float _B_0[484];
    float _B_1[484];//copy of _B_0

    //
    float _thrust_rpyt_out_22t[22];

    static AP_MotorsYT *_singleton;
};
