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
#include "uart.h"
#include "kernel.h"
#include "STM8S003F3.h"

#define DEFAULT 0x00

#define PING_INCOME 0x01
#define PING_OK 0x02
#define PARAM_INCOME 0x03

#define BAUDRATE_INCOME 0x04
#define BAUDRATE_OK 0x05

#define POWER_INCOME 0x06
#define POWER_OK 0x07

#define FUNC_INCOME 0x08
#define FUNC_OK 0x09

#define CHANNEL_INCOME 0x0A
#define CHANNEL_OK 0x0B

#define BAUDRATE_CHAR 'B'
#define CHANNEL_CHAR 'C'
#define FUNC_CHAR_0 'F'
#define FUNC_CHAR_1 'U'
#define POWER_CHAR 'P'
#define PING_CHAR_0 'O'
#define PING_CHAR_1 'K'
#define PARAM_CHAR '+'

#define NULL_STRING7 { 0x00,0x00,0x00,0x00,0x00,0x00,0x00 }
#define NULL_STRING5 { 0x00,0x00,0x00,0x00,0x00 }
#define NULL_STRING4 { 0x00,0x00,0x00,0x00 }

#define TIMEOUT 150U
#define CFG_BAUDRATE 9600U

#define CMD_PING "AT"
#define CMD_FUNC "AT+FU"
#define CMD_PWR "AT+P"
#define CMD_BR "AT+B"
#define CMD_CH "AT+C"

#define GET_BR "AT+RB"
#define GET_CH "AT+RC"
#define GET_FUNC "AT+RF"
#define GET_PWR "AT+RP"

static uint8_t input_buffer[15];
static uint8_t input_buffer_ptr;

static uint8_t income_ptr;
static uint8_t actual_state;
static uint8_t desired_state;

static char channel_income[4] = NULL_STRING4;
static char baudrate_income[5] = NULL_STRING5;
static uint32_t speeds[8] = { 1200,2400,4800,9600,19200,38400,57600,115200 };

static bool success = 0;
static char transmitter_power = 'z';
static uint8_t func_mode = 0;

static uint8_t sreg = 0;
static uint32_t context_baudrate;

#define read_begin 0x01
#define read_end 0x02


void handle_uart(const uint8_t dat)
{
	if (dat == 'O' && sreg != read_begin)
	{
		sreg = read_begin;
		input_buffer_ptr = 0;
	}

	if (dat == '\n' && sreg == read_begin)
	{
		sreg = read_end;
		if (input_buffer_ptr + 1 < 16)
		{
			input_buffer[input_buffer_ptr++] = dat;
			input_buffer[input_buffer_ptr] = 0;
		}
	}

	if (sreg == read_begin && input_buffer_ptr < 16)
	{
		input_buffer[input_buffer_ptr++] = dat;
	}
}


void set_cfg_pin_low(void)
{
	GPIOD->DDR |= 1 << 4;
	delay(50);
}

void set_cfg_pin_hi(void)
{
	GPIOD->DDR &= ~(1 << 4);
	delay(10);
}

void enter_cfg_mode(const uint8_t ds)
{
	desired_state = ds;
	set_cfg_pin_low();
	context_baudrate  = uart_get_baudrate();
	uart_set_baudrate(CFG_BAUDRATE);
}

void exit_cfg_mode(void)
{
	uart_set_baudrate(context_baudrate);
	set_cfg_pin_hi();
}

bool wait_for_response(void)
{
	bool result = true;
	const uint32_t current = millis();
	while (!success)
	{
		if (millis() - current > TIMEOUT)
		{
			result = false;
			break;
		}
	}
	return result;
}

void handle_byte(const uint8_t dat)
{
	switch (actual_state)
	{
	case DEFAULT:
		actual_state = dat == PING_CHAR_0 ? PING_INCOME : DEFAULT;
		break;
	case PING_INCOME:
		actual_state = dat == PING_CHAR_1 ? PING_OK : DEFAULT;
		break;
	case PING_OK:
		actual_state = dat == PARAM_CHAR ? PARAM_INCOME : DEFAULT;
		break;
	case PARAM_INCOME:
		switch (dat)
		{
		case POWER_CHAR:
			actual_state = POWER_INCOME;
			break;
		case BAUDRATE_CHAR:
			actual_state = BAUDRATE_INCOME;
			*(uint32_t*)baudrate_income = 0;
			income_ptr = 0;
			break;
		case FUNC_CHAR_0:
			sreg = 1;
			break;
		case FUNC_CHAR_1:
			actual_state = sreg ? FUNC_INCOME : DEFAULT;
			sreg = 0;
			break;
		case CHANNEL_CHAR:
			actual_state = CHANNEL_INCOME;
			*(uint32_t*)channel_income = 0;
			income_ptr = 0;
			break;
		default:
			actual_state = DEFAULT;
			break;
		}
		break;
	case CHANNEL_INCOME:
		if (income_ptr < 3)
		{
			channel_income[income_ptr] = dat;
			income_ptr++;
		}
		else
		{
			actual_state = CHANNEL_OK;
		}
		break;
	case FUNC_INCOME:
		func_mode = dat;
		actual_state = FUNC_OK;
		break;
	case POWER_INCOME:
		transmitter_power = dat;
		actual_state = POWER_OK;
		break;
	case BAUDRATE_INCOME:
		if (income_ptr < 4)
		{
			baudrate_income[income_ptr] = dat;
			income_ptr++;
		}
		else
		{
			actual_state = BAUDRATE_OK;
		}
		break;
	default:
		break;
	}

	if (desired_state == actual_state)
	{
		success = true;
		actual_state = DEFAULT;
	}
	else
	{
		success = false;
	}
}

void hc12_init(void)
{
	uart_init(9600);
	uart_subscribe_byte_reception(handle_uart);
}

bool hc12_send_ping(void)
{
	enter_cfg_mode(PING_OK);

	uart_send_string(CMD_PING);
	const bool result = wait_for_response();
	
	exit_cfg_mode();
	return result;
}

void hc12_send_byte(uint8_t data)
{
	uart_send_byte(data);
}

bool hc12_set_transmission_mode(transmitter_mode m)
{
	enter_cfg_mode(FUNC_OK);

	uart_send_string(CMD_FUNC);
	uart_send_byte(m);

	bool result = wait_for_response();

	result = result ? func_mode == m : false;

	exit_cfg_mode();
	return result;
}

transmitter_mode hc12_get_transmission_mode(void)
{
	enter_cfg_mode(FUNC_OK);

	uart_send_string(GET_FUNC);

	const char result = wait_for_response() ? func_mode : transmitter_err;

	exit_cfg_mode();
	return (transmitter_mode)result;
}

bool hc12_set_channel(const uint8_t ch)
{
	enter_cfg_mode(CHANNEL_OK);

	char channel[5] = NULL_STRING5;
	itoa_(ch, channel);
	uart_send_string(CMD_CH);
	if (ch < 100) uart_send_byte('0');
	if (ch < 10) uart_send_byte('0');
	uart_send_string(channel);

	bool result = wait_for_response();

	const uint8_t actual = atoi(channel_income);
	result = result ? actual == ch : false;

	exit_cfg_mode();
	return result;
}

uint8_t hc12_get_channel()
{
	enter_cfg_mode(CHANNEL_OK);

	uart_send_string(GET_CH);
	const uint8_t result = wait_for_response() ? atoi(channel_income) : 0;
	exit_cfg_mode();
	return (transmitter_mode)result;
}

bool hc12_set_power(power_levels pwr)
{
	enter_cfg_mode(POWER_OK);

	uart_send_string(CMD_PWR);
	uart_send_byte(pwr);

	bool result = wait_for_response();

	result = result ? pwr == transmitter_power : false;

	exit_cfg_mode();
	return result;
}

power_levels hc12_get_power()
{
	enter_cfg_mode(POWER_OK);

	uart_send_string(GET_PWR);
	const power_levels result = wait_for_response() ? (power_levels)transmitter_power : power_err;

	exit_cfg_mode();
	return result;
}


bool hc12_set_baudrate(transmission_speed br)
{
	enter_cfg_mode(BAUDRATE_OK);

	char baudrate[7] = NULL_STRING7;
	itoa_(speeds[br], baudrate);
	uart_send_string(CMD_BR);
	uart_send_string(baudrate);

	bool result = wait_for_response();

	uint32_t* actual = (uint32_t*)baudrate_income;
	uint32_t* expected = (uint32_t*)baudrate;
	result = result ? &actual == &expected : false;
	if (result) context_baudrate = speeds[br];

	exit_cfg_mode();
	return result;
}

transmission_speed hc12_get_baudrate()
{
	enter_cfg_mode(BAUDRATE_OK);

	uart_send_string(GET_BR);

	transmission_speed br = baudrate_err;
	if (wait_for_response())
	{
		switch (*(uint16_t*)baudrate_income)
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
	}
	exit_cfg_mode();
	return br;
}