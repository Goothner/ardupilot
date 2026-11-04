/*
 * This file is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Author: Oliver Walters / Currawong Engineering Pty Ltd
 */

#pragma once

#include <AP_HAL/AP_HAL.h>
#include <AP_CANManager/AP_CANDriver.h>

#include <AP_Param/AP_Param.h>
#include <AP_ESC_Telem/AP_ESC_Telem_Backend.h>

#include "AP_PiccoloCAN_Device.h"
#include "AP_PiccoloCAN_ESC.h"
#include "AP_PiccoloCAN_ECU.h"
#include "AP_PiccoloCAN_Servo.h"
#include <AP_EFI/AP_EFI_Currawong_ECU.h>

#if HAL_PICCOLO_CAN_ENABLE

#define PICCOLO_MSG_RATE_HZ_MIN 1
#define PICCOLO_MSG_RATE_HZ_MAX 500
#define PICCOLO_MSG_RATE_HZ_DEFAULT 50

class AP_PiccoloCAN : public AP_CANDriver, public AP_ESC_Telem_Backend
{
public:
    AP_PiccoloCAN();
    ~AP_PiccoloCAN();

    /* Do not allow copies */
    CLASS_NO_COPY(AP_PiccoloCAN);

    static const struct AP_Param::GroupInfo var_info[];

    // Return PiccoloCAN from @driver_index or nullptr if it's not ready or doesn't exist
    static AP_PiccoloCAN *get_pcan(uint8_t driver_index);

    // initialize PiccoloCAN bus
    void init(uint8_t driver_index, bool enable_filters) override;
    bool add_interface(AP_HAL::CANIface* can_iface) override;

    // called from SRV_Channels
    void update();

    // send ESC telemetry messages over MAVLink
    void send_esc_telemetry_mavlink(uint8_t mav_chan);

    // return true if a particular servo is 'active' on the Piccolo interface
    bool is_servo_channel_active(uint8_t chan);

    // return true if a particular ESC is 'active' on the Piccolo interface
    bool is_esc_channel_active(uint8_t chan);

    // return true if a particular servo has been detected on the CAN interface
    bool is_servo_present(uint8_t chan, uint64_t timeout_ms = 2000);

    // return true if a particular ESC has been detected on the CAN interface
    bool is_esc_present(uint8_t chan, uint64_t timeout_ms = 2000);

    // return true if a particular servo is enabled
    bool is_servo_enabled(uint8_t chan);

    // return true if a particular ESC is enabled
    bool is_esc_enabled(uint8_t chan);

    // test if the Piccolo CAN driver is ready to be armed
    bool pre_arm_check(char* reason, uint8_t reason_len);

private:

    // loop to send output to ESCs in background thread
    void loop();

    // write frame on CAN bus, returns true on success
    bool write_frame(AP_HAL::CANFrame &out_frame, uint32_t timeout_us);

    // read frame on CAN bus, returns true on succses
    bool read_frame(AP_HAL::CANFrame &recv_frame, uint32_t timeout_us);

    uint8_t CRC8_07(uint8_t *data, uint16_t len);

    // send ESC commands over CAN
    void send_esc_messages(void);

    // interpret an ESC message received over CAN
    bool handle_esc_message(AP_HAL::CANFrame &frame);

    // send servo commands over CAN
    void send_servo_messages(void);

    // interpret a servo message received over CAN
    bool handle_servo_message(AP_HAL::CANFrame &frame);

#if AP_EFI_CURRAWONG_ECU_ENABLED
    void send_ecu_messages(void);

    // interpret an ECU message received over CAN
    bool handle_ecu_message(AP_HAL::CANFrame &frame);
#endif

    bool _initialized;
    char _thread_name[20];
    uint8_t _driver_index;
    AP_HAL::CANIface* _can_iface;
    HAL_BinarySemaphore sem_handle;

    AP_PiccoloCAN_Servo _servos[PICCOLO_CAN_MAX_NUM_SERVO];
    AP_PiccoloCAN_ESC _escs[PICCOLO_CAN_MAX_NUM_ESC/2];

    struct CurrawongECU_Info_t {
        float command;
        bool newCommand;
    } _ecu_info;

    // Piccolo CAN parameters
    AP_Int32 _esc_bm;       //! ESC selection bitmask
    AP_Int16 _esc_hz;       //! ESC update rate (Hz)

    AP_Int32 _srv_bm;       //! Servo selection bitmask
    AP_Int16 _srv_hz;       //! Servo update rate (Hz)

    AP_Int16 _ecu_id;        //! ECU Node ID
    AP_Int16 _ecu_hz;       //! ECU update rate (Hz)

    uint8_t uni_counter = 0;
    uint8_t servo_counter = 0;
    HAL_Semaphore _telem_sem;
};
//                 if(ii+motor_num_start==1) txFrame.id = 0x9F310000;//1A
//                 if(ii+motor_num_start==2) txFrame.id = 0x9F410010;//1B
//                 if(ii+motor_num_start==3) txFrame.id = 0x9F110020;//2A
//                 if(ii+motor_num_start==4) txFrame.id = 0x9F510030;//2B
//                 if(ii+motor_num_start==5) txFrame.id = 0x9F110040;//3A
//                 if(ii+motor_num_start==6) txFrame.id = 0x9F410050;//3B
//                 if(ii+motor_num_start==7) txFrame.id = 0x9F510060;//4A
//                 if(ii+motor_num_start==8) txFrame.id = 0x9F610070;//4B
//                 if(ii+motor_num_start==9) txFrame.id = 0x9F210080;//5A
//                 if(ii+motor_num_start==10)txFrame.id = 0x9F310090;//5B
//                 if(ii+motor_num_start==11)txFrame.id = 0x9F2100A0;//6A
//                 if(ii+motor_num_start==12)txFrame.id = 0x9F5100B0;//6B
//                 if(ii+motor_num_start==13)txFrame.id = 0x9F2100C0;//7A
//                 if(ii+motor_num_start==14)txFrame.id = 0x9F6100D0;//7B
//                 if(ii+motor_num_start==15)txFrame.id = 0x9F3100E0;//8A
//                 if(ii+motor_num_start==16)txFrame.id = 0x9F6100F0;//8B
//                 if(ii+motor_num_start==17)txFrame.id = 0x9F110100;//9A
//                 if(ii+motor_num_start==18)txFrame.id = 0x9F610110;//9B
//                 if(ii+motor_num_start==19)txFrame.id = 0x9F410120;//10A
//                 if(ii+motor_num_start==20)txFrame.id = 0x9F510130;//10B
//                 if(ii+motor_num_start==21)txFrame.id = 0x9F110140;//11A
//                 if(ii+motor_num_start==22)txFrame.id = 0x9F310150;//11B
//                 if(ii+motor_num_start==23)txFrame.id = 0x9F110160;//12A
//                 if(ii+motor_num_start==24)txFrame.id = 0x9F410170;//12B
//                 if(ii+motor_num_start==25)txFrame.id = 0x9F310180;//13A
//                 if(ii+motor_num_start==26)txFrame.id = 0x9F510190;//13B
//                 if(ii+motor_num_start==27)txFrame.id = 0x9F2101A0;//14A
//                 if(ii+motor_num_start==28)txFrame.id = 0x9F6101B0;//14B
//                 if(ii+motor_num_start==29)txFrame.id = 0x9F1101C0;//15A
//                 if(ii+motor_num_start==30)txFrame.id = 0x9F6101D0;//15B
//                 if(ii+motor_num_start==31)txFrame.id = 0x9F2101E0;//16A
//                 if(ii+motor_num_start==32)txFrame.id = 0x9F5101F0;//16B
//                 if(ii+motor_num_start==33)txFrame.id = 0x9F110200;//17A
//                 if(ii+motor_num_start==34)txFrame.id = 0x9F210210;//17B
//                 if(ii+motor_num_start==35)txFrame.id = 0x9F310220;//18A
//                 if(ii+motor_num_start==36)txFrame.id = 0x9F510230;//18B
//                 if(ii+motor_num_start==37)txFrame.id = 0x9F410240;//19A
//                 if(ii+motor_num_start==38)txFrame.id = 0x9F610250;//19B
//                 if(ii+motor_num_start==39)txFrame.id = 0x9F210260;//20A
//                 if(ii+motor_num_start==40)txFrame.id = 0x9F410270;//20B

#endif // HAL_PICCOLO_CAN_ENABLE
