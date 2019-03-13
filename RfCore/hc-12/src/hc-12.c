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

#include <string.h>

#include "helpers.h"
#include "hc-12.h"
#include "uart.h"
#include "kernel.h"
#include "STM8S003F3.h"



#define DEFAULT 0x00
#define SET_BR_OK 0x09

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

#define TIMEOUT 150U

#define CFG_BAUDRATE 9600U

static uint8_t actual_state;
static uint8_t desired_state;
static char* cmd_ping = "AT";
static char* cmd_pwr = "AT+P";
static char* cmd_br = "AT+B";
static char* cmd_ch = "AT+C";
static char baudrate_income[5]={0x00,0x00,0x00,0x00,0x00};
static char power_income[3];
static uint8_t income_ptr;
static uint32_t speeds[8] = { 1200,2400,4800,9600,19200,38400,57600,115200 };
static bool success = 0;
static uint8_t transmitter_power = 0;
static uint8_t func_mode = 0;

static uint8_t sreg = 0;

void set_cfg_pin_low(void)
{
	GPIOD->DDR |= 1 << 4;
	delay(50);
}

void set_cfg_pin_hi(void)
{
	GPIOD->DDR &= ~(1 << 4);
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
			power_income[income_ptr] = dat;
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

void hc12_init()
{
	uart_init(9600);
	uart_subscribe_byte_reception(handle_byte);
}

bool hc12_set_transmission_mode(transmitter_mode m)
{
	//todo: implement hc12_set_transmission_mode
	return false;
}

bool hc12_set_channel(uint8_t ch)
{
	//todo: implement hc12_set_channel
	return false;
}

uint8_t hc12_get_channel()
{
	//todo: implement hc12_get_channel
	return 0;
}

transmitter_mode hc12_get_transmission_mode()
{
	//todo: implement hc12_get_transmission_mode
	return transmitter_fu1;
}

void hc12_send_byte(uint8_t data)
{
	uart_send_byte(data);
}

bool hc12_send_ping(void)
{
	desired_state = PING_OK;

	set_cfg_pin_low();
	const uint32_t br = uart_get_baudrate();
	uart_set_baudrate(CFG_BAUDRATE);
	uart_send_data((uint8_t*)cmd_ping, 2);

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

	uart_set_baudrate(br);
	set_cfg_pin_hi();
	return result;
}

bool hc12_set_power(power_levels pwr)
{
	desired_state = POWER_OK;

	set_cfg_pin_low();
	const uint32_t br = uart_get_baudrate();
	uart_set_baudrate(CFG_BAUDRATE);
	uart_send_data((uint8_t*)cmd_pwr, 4);
	uart_send_byte(pwr);

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

	uart_set_baudrate(br);
	set_cfg_pin_hi();
	return result;
}

bool hc12_set_baudrate(transmission_speed speed)
{
	desired_state = SET_BR_OK;

	set_cfg_pin_low();
	const uint32_t br = uart_get_baudrate();

	uart_set_baudrate(CFG_BAUDRATE);

	char baudrate[7] = NULL_STRING7;

	itoa(speeds[speed], baudrate);
	uart_send_data((uint8_t*)cmd_br, strlen(cmd_br));
	uart_send_data((uint8_t*)baudrate, strlen(baudrate));

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
	uart_set_baudrate(result ? br : speeds[speed]);
	set_cfg_pin_hi();
	return result;
}

transmission_speed hc12_get_baudrate()
{
	//todo: implement hc12_get_baudrate
	return baudrate_1200;
}

power_levels hc12_get_power()
{
	return (power_levels)transmitter_power;
}
