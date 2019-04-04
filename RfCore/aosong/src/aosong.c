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

#include "aosong.h"
#include "aosong_hal.h"

//================================================================================
//                  Aosong tempertaure/humidity sesors protocol
//================================================================================
//          Tbe      Tgo   Trel      Treh    Tlow  Th0  Tlow    Th1    Ten
// ___               ___           ________        ___        _______        ____
//    \____________ /   \________ /        \_____ /   \_____ /       \_____ /
//================================================================================
#define Tbe 800
#define Tgo (30+10)
#define Trel 80
#define Treh 80
#define Tlow 50
#define Th0 (26+10)
#define Th1 70
#define Ten 50

//================================================================================
//                           Aosong sensor data map
//              hhhh hhhh hhhh hhhh tttt tttt tttt tttt cccc cccc
// h - humidity bit
// t - temperature bit
// c - checksum bit
//================================================================================
#define TEMPERATURE_OFFSET 8U
#define HUMIDITY_OFFSET 24U
#define NEGATIVE_TEMPERATURE_BIT 0x8000U
#define RESPONSE_BIT_COUNT 40U

uint_fast32_t bin2_ascii(uint_fast16_t input);
static uint8_t aosong_sensor_raw_data[5];

aosong_status aosong_read_sensor()
{
	aosong_set_sensor_pin_as_output_push_pull();

	aosong_set_sensor_pin_low();
	aosong_delay_us(Tbe);

	aosong_disable_irq();

	aosong_set_sensor_pin_as_input_pullup();

	aosong_delay_us(Tgo);

	if (aosong_sensor_pin_is_high())
	{
		aosong_enable_irq();
		return aosong_no_response;
	}

	aosong_wait_for_sensor_pin_high();

	for (uint_fast8_t t = 0; t < RESPONSE_BIT_COUNT; t++)
	{
		aosong_wait_for_sensor_pin_low();
		aosong_wait_for_sensor_pin_high();
		aosong_delay_us(Th0);
		aosong_sensor_raw_data[t / 8] <<= 1;
		if (aosong_sensor_pin_is_high())
			aosong_sensor_raw_data[t / 8]++;
	}

	aosong_enable_irq();

	uint8_t* d_pt = (uint8_t*)&aosong_sensor_raw_data;
	if (*d_pt != (uint8_t)(d_pt[1] + d_pt[2] + d_pt[3] + d_pt[4]))
		return aosong_invalid_checksum;

	return aosong_ok;
}

uint32_t aosong_get_raw_data()
{
	return (uint32_t)&aosong_sensor_raw_data;
}

uint_fast16_t aosong_get_temperature(void)
{
	uint8_t* ptr = (uint8_t*)&aosong_sensor_raw_data;
	return *(ptr + 2) << 8 | *(ptr + 1);
}

uint_fast16_t aosong_get_humidity(void)
{
	uint8_t* ptr = (uint8_t*)&aosong_sensor_raw_data;
	return *(ptr + 4) << 8 | *(ptr + 3);
}

uint32_t aosong_get_temperature_ascii(void)
{
	//const uint_fast16_t input = aosong_sensor_raw_data >> TEMPERATURE_OFFSET;
	//if ((input & NEGATIVE_TEMPERATURE_BIT) != 0)
	//	return 0;
	return bin2_ascii(5);
}

uint32_t aosong_get_humidity_ascii(void)
{
	//const uint_fast16_t input = aosong_sensor_raw_data >> HUMIDITY_OFFSET;
	return bin2_ascii(5);
}

uint_fast32_t bin2_ascii(uint_fast16_t input)
{
	uint8_t r_arr[4];
	uint32_t* r_ptr = (uint32_t*)r_arr;
	input = (uint16_t)input;
	*r_ptr = input / 100;
	input -= *r_ptr * 100;
	r_arr[1] = input / 10;
	input -= r_arr[1] * 10;
	r_arr[3] = input;
	*r_ptr |= 0x302E3030;
	return *r_ptr;
}
