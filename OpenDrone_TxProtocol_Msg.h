// MIT License

// Copyright (c) 2024 phonght32

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef __OPENDRONE_TXPROTOCOL_MSG_H__
#define __OPENDRONE_TXPROTOCOL_MSG_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"

typedef enum {
	OPENDRONE_TXPROTOCOL_MSG_ID_INVALID = 0,
	OPENDRONE_TXPROTOCOL_MSG_ID_SYS_STATUS,
	OPENDRONE_TXPROTOCOL_MSG_ID_RAW_OPERATOR_CONTROL,
	OPENDRONE_TXPROTOCOL_MSG_ID_OPERATOR_CONTROL,
	OPENDRONE_TXPROTOCOL_MSG_ID_STABILIZER_CONTROL,
	OPENDRONE_TXPROTOCOL_MSG_ID_SET_MODE,
	OPENDRONE_TXPROTOCOL_MSG_ID_AUTH,
	OPENDRONE_TXPROTOCOL_MSG_ID_SET_PARAM,
	OPENDRONE_TXPROTOCOL_MSG_ID_GET_PARAM,
	OPENDRONE_TXPROTOCOL_MSG_ID_DEBUG
} OpenDrone_TxProtocol_Msg_Id_t;

typedef struct {
	uint8_t joystick1_pos_x;
	uint8_t joystick1_pos_y;
	uint8_t joystick2_pos_x;
	uint8_t joystick2_pos_y;
	uint8_t switch1;
	uint8_t switch2;
	uint8_t switch3;
	uint8_t switch4;
	uint8_t volume1;
	uint8_t volume2;
	uint8_t button1;
	uint8_t button2;
	uint8_t button3;
	uint8_t button4;
} OpenDrone_TxProtocol_Msg_RawOprCtrl_t;

typedef struct {
	uint8_t throttle;
    uint8_t rudder;
    uint8_t elevator;
    uint8_t aileron;
} OpenDrone_TxProtocol_Msg_OprCtrl_t;

typedef struct {
	uint8_t throttle;
	uint8_t roll;
	uint8_t pitch;
	uint8_t yaw;
} OpenDrone_TxProtocol_Msg_StabilizerCtrl_t;

typedef union {
	OpenDrone_TxProtocol_Msg_OprCtrl_t OprCtrl;
	OpenDrone_TxProtocol_Msg_RawOprCtrl_t RawOprCtrl;
	OpenDrone_TxProtocol_Msg_StabilizerCtrl_t StabilizerCtrl;
} OpenDrone_TxProtocol_Payload_t;

typedef struct {
	uint8_t 					StartInd;
	uint8_t 					PktLen;
	uint8_t 					PktSeq;
	uint8_t 					SrcId;
	uint8_t 					DesId;
	OpenDrone_TxProtocol_Msg_Id_t 	MsgId;
	OpenDrone_TxProtocol_Payload_t Payload;
	uint8_t 					Crc;
} OpenDrone_TxProtocol_Msg_t;

#ifdef __cplusplus
}
#endif

#endif /* __OPENDRONE_TXPROTOCOL_MSG_H__ */