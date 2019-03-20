// Copyright 2019 Oleg Petrochenko
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <stdlib.h>
#include "helpers.h"
#include "hc-12.h"
#include "hc-12_hal.h"

#define TIMEOUT 200U
#define CFG_BAUDRATE 9600U
#define DELAY_BEFORE_TRANSMIT 50U
#define DELAY_AFTER_TRANSMIT 10U

#define NULL_STRING7 { 0x00,0x00,0x00,0x00,0x00,0x00,0x00 }
#define NULL_STRING5 { 0x00,0x00,0x00,0x00,0x00 }

#define BAUDRATE_CHAR 'B'
#define CHANNEL_CHAR 'C'
#define FUNC_CHAR 'F'
#define POWER_CHAR 'P'
#define RESPONSE_CHAR 'R'
#define ERROR_CHAR 'E'

#define CMD_PING "AT"
#define CMD_FUNC "AT+FU"
#define CMD_PWR "AT+P"
#define CMD_BR "AT+B"
#define CMD_CH "AT+C"
#define GET_ALL "AT+RX"
#define INPUT_BUFFER_LENGTH 16U

#define READ_BEGIN 0x01
#define READ_END 0x02
#define NULL_N 0x00

static uint8_t input_buffer[INPUT_BUFFER_LENGTH];
static uint8_t input_buffer_ptr;
static uint32_t speeds[9] = { 1200U,2400U,4800U,9600U,19200U,38400U,57600U,115200U,9600U };
static uint8_t sreg ;
static uint32_t context_baudrate;

static char* power_map = "0102050811141720";
static char raw_baudrate[2];
static char raw_mode;
static char raw_channel[4];
static char raw_power[2];
static uint8_t cnt;

void input_decode(void)
{
	cnt++;
	if (input_buffer[2] == (char)NULL_N) return;
	if(input_buffer[0] == ERROR_CHAR) return;
	switch (input_buffer[3])
	{
	case BAUDRATE_CHAR:
		*(uint16_t*)raw_baudrate = *(uint16_t*)&input_buffer[4];
		break;
	case FUNC_CHAR:
		raw_mode = (char)input_buffer[5];
		break;
	case RESPONSE_CHAR:
		if (input_buffer[4] == CHANNEL_CHAR)
		{
			*(uint32_t*)raw_channel = *(uint32_t*)&input_buffer[5];
			raw_channel[3] = (char)NULL_N;
		}
		if (input_buffer[4] == POWER_CHAR)
		{
			*(uint16_t*)raw_power = *(uint16_t*)&input_buffer[7];
		}
		break;
	case POWER_CHAR:
		*(uint16_t*)raw_power = *(uint16_t*)&power_map[(input_buffer[4] - '0' - 1) * 2];
		break;
	case CHANNEL_CHAR:
		*(uint32_t*)raw_channel = *(uint32_t*)&input_buffer[4];
		raw_channel[3] = (char)NULL_N;
		break;
	default:
		break;
	}
}

void handle_uart(const uint8_t dat)
{
	if (dat == 'O' && sreg != READ_BEGIN)
	{
		sreg = READ_BEGIN;
		input_buffer_ptr = 0;
	}

	if (dat == '\r' && sreg == READ_BEGIN)
	{
		sreg = READ_END;
		if (input_buffer_ptr + 1 < INPUT_BUFFER_LENGTH)
		{
			input_buffer[input_buffer_ptr++] = dat;
			input_buffer[input_buffer_ptr] = NULL_N;
			input_decode();
		}
	}

	if (sreg == READ_BEGIN && input_buffer_ptr < INPUT_BUFFER_LENGTH)
	{
		input_buffer[input_buffer_ptr++] = dat;
	}
}

void set_cfg_pin_low(void)
{
	hc12_set_cfg_pin_low();
	hc12_delay(DELAY_BEFORE_TRANSMIT);
}

void set_cfg_pin_hi(void)
{
	hc12_set_cfg_pin_hi();
	hc12_delay(DELAY_AFTER_TRANSMIT);
}

void enter_cfg_mode()
{
	sreg = NULL_N;
	set_cfg_pin_low();
	context_baudrate  = hc12_transmitter_get_baudrate();
	hc12_transmitter_set_baudrate(CFG_BAUDRATE);
}

void exit_cfg_mode(void)
{
	sreg = NULL_N;
	hc12_transmitter_set_baudrate(context_baudrate);
	set_cfg_pin_hi();
}

bool wait_for_response(void)
{
	bool result = true;
	const uint32_t current = hc12_millis();
	while (sreg != READ_END)
	{
		if (hc12_millis() - current > TIMEOUT)
		{
			result = false;
			break;
		}
	}
	return result;
}

bool hc12_get_all_info(void)
{
	enter_cfg_mode();

	hc12_transmitter_send_string(GET_ALL);

	cnt = 0;
	bool result = true;
	const uint32_t current = hc12_millis();
	while (cnt < 4)
	{
		if (hc12_millis() - current > TIMEOUT)
		{
			result = false;
			break;
		}
	}

	exit_cfg_mode();
	return result;
}

bool hc12_init(void)
{
	hc12_transmitter_init(CFG_BAUDRATE);
	hc12_transmitter_subscribe_byte_reception(handle_uart);
	hc12_get_all_info();

	bool result = false;
	const transmitter_speed br = hc12_get_baudrate();
	if (br != baudrate_9600)
		result = hc12_set_baudrate(br);
	return result;
}

bool hc12_send_ping(void)
{
	enter_cfg_mode();

	hc12_transmitter_send_string(CMD_PING);
	const bool result = wait_for_response();
	
	exit_cfg_mode();
	return result;
}

void hc12_send_byte(uint8_t data)
{
	hc12_transmitter_send_byte(data);
}

bool hc12_set_transmission_mode(transmitter_mode m)
{
	enter_cfg_mode();

	hc12_transmitter_send_string(CMD_FUNC);
	hc12_transmitter_send_byte(m);

	bool result = wait_for_response();
	const transmitter_mode actual = hc12_get_transmission_mode();
	result = result ? actual == m : false;

	exit_cfg_mode();
	return result;
}

transmitter_mode hc12_get_transmission_mode(void)
{
	return (transmitter_mode)raw_mode;
}

bool hc12_set_channel(const transmitter_channel ch)
{
	enter_cfg_mode();

	char channel[5] = NULL_STRING5;
	itoa_(ch, channel);
	hc12_transmitter_send_string(CMD_CH);
	if (ch < 100) hc12_transmitter_send_byte('0');
	if (ch < 10) hc12_transmitter_send_byte('0');
	hc12_transmitter_send_string(channel);

	bool result = wait_for_response();

	const uint8_t actual = hc12_get_channel();
	result = result ? actual == ch : false;

	exit_cfg_mode();
	return result;
}

transmitter_channel hc12_get_channel()
{
	return (transmitter_channel)atoi(raw_channel);
}

bool hc12_set_power(transmitter_power pwr)
{
	enter_cfg_mode();

	hc12_transmitter_send_string(CMD_PWR);
	hc12_transmitter_send_byte(pwr);

	bool result = wait_for_response();
	const transmitter_power actual = hc12_get_power();
	result = result ? actual == pwr : false;

	exit_cfg_mode();
	return result;
}

transmitter_power hc12_get_power()
{
	transmitter_power pl;
	switch (*(uint16_t*)raw_power)
	{
	case 0x3031:
		pl = power_0;
		break;
	case 0x3032:
		pl = power_2;
		break;
	case 0x3035:
		pl = power_5;
		break;
	case 0x3038:
		pl = power_8;
		break;
	case 0x3131:
		pl = power_11;
		break;
	case 0x3134:
		pl = power_14;
		break;
	case 0x3137:
		pl = power_17;
		break;
	case 0x3230:
		pl = power_20;
		break;
	default:
		pl = power_err;
		break;
	}
	return pl;
}

bool hc12_set_baudrate(transmitter_speed br)
{
	enter_cfg_mode();

	char baudrate[7] = NULL_STRING7;
	itoa_(speeds[br], baudrate);
	hc12_transmitter_send_string(CMD_BR);
	hc12_transmitter_send_string(baudrate);

	bool result = wait_for_response();

	const transmitter_speed actual = hc12_get_baudrate();
	result = result ? actual == br : false;
	if (result) context_baudrate = speeds[br];

	exit_cfg_mode();
	return result;
}

transmitter_speed hc12_get_baudrate()
{
	transmitter_speed br;
	switch (*(uint16_t*)raw_baudrate)
	{
	case 0x3231:
		br = baudrate_1200;
		break;
	case 0x3432:
		br = baudrate_2400;
		break;
	case 0x3834:
		br = baudrate_4800;
		break;
	case 0x3936:
		br = baudrate_9600;
		break;
	case 0x3931:
		br = baudrate_19200;
		break;
	case 0x3833:
		br = baudrate_38400;
		break;
	case 0x3735:
		br = baudrate_57600;
		break;
	case 0x3131:
		br = baudrate_115200;
		break;
	default:
		br = baudrate_err;
		break;
	}
	return br;
}