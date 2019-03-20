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

#ifndef __HC_12__
#define __HC_12__

#include <stdbool.h>
#include <stdint.h>

typedef enum
{
	transmitter_err = '0',
	transmitter_fu1 = '1',
	transmitter_fu2 = '2',
	transmitter_fu3 = '3',
	transmitter_fu4 = '4'
}transmitter_mode;

typedef enum
{
	power_err = '0',
	power_0 = '1',
	power_2 = '2',
	power_5 = '3',
	power_8 = '4',
	power_11 = '5',
	power_14 = '6',
	power_17 = '7',
	power_20 = '8'
} transmitter_power;

typedef enum
{
	baudrate_1200 = 0,
	baudrate_2400 = 1,
	baudrate_4800 = 2,
	baudrate_9600 = 3,
	baudrate_19200 = 4,
	baudrate_38400 = 5,
	baudrate_57600 = 6,
	baudrate_115200 = 7,
	baudrate_err = 8
}transmitter_speed;

typedef enum
{
	channel_err = 0,
	channel_001 = 1,
	channel_002 = 2,
	channel_003 = 3,
	channel_004 = 4,
	channel_005 = 5,
	channel_006 = 6,
	channel_007 = 7,
	channel_008 = 8,
	channel_009 = 9,
	channel_010 = 10,
	channel_011 = 11,
	channel_012 = 12,
	channel_013 = 13,
	channel_014 = 14,
	channel_015 = 15,
	channel_016 = 16,
	channel_017 = 17,
	channel_018 = 18,
	channel_019 = 19,
	channel_020 = 20,
	channel_021 = 21,
	channel_022 = 22,
	channel_023 = 23,
	channel_024 = 24,
	channel_025 = 25,
	channel_026 = 26,
	channel_027 = 27,
	channel_028 = 28,
	channel_029 = 29,
	channel_030 = 30,
	channel_031 = 31,
	channel_032 = 32,
	channel_033 = 33,
	channel_034 = 34,
	channel_035 = 35,
	channel_036 = 36,
	channel_037 = 37,
	channel_038 = 38,
	channel_039 = 39,
	channel_040 = 40,
	channel_041 = 41,
	channel_042 = 42,
	channel_043 = 43,
	channel_044 = 44,
	channel_045 = 45,
	channel_046 = 46,
	channel_047 = 47,
	channel_048 = 48,
	channel_049 = 49,
	channel_050 = 50,
	channel_051 = 51,
	channel_052 = 52,
	channel_053 = 53,
	channel_054 = 54,
	channel_055 = 55,
	channel_056 = 56,
	channel_057 = 57,
	channel_058 = 58,
	channel_059 = 59,
	channel_060 = 60,
	channel_061 = 61,
	channel_062 = 62,
	channel_063 = 63,
	channel_064 = 64,
	channel_065 = 65,
	channel_066 = 66,
	channel_067 = 67,
	channel_068 = 68,
	channel_069 = 69,
	channel_070 = 70,
	channel_071 = 71,
	channel_072 = 72,
	channel_073 = 73,
	channel_074 = 74,
	channel_075 = 75,
	channel_076 = 76,
	channel_077 = 77,
	channel_078 = 78,
	channel_079 = 79,
	channel_080 = 80,
	channel_081 = 81,
	channel_082 = 82,
	channel_083 = 83,
	channel_084 = 84,
	channel_085 = 85,
	channel_086 = 86,
	channel_087 = 87,
	channel_088 = 88,
	channel_089 = 89,
	channel_090 = 90,
	channel_091 = 91,
	channel_092 = 92,
	channel_093 = 93,
	channel_094 = 94,
	channel_095 = 95,
	channel_096 = 96,
	channel_097 = 97,
	channel_098 = 98,
	channel_099 = 99,
	channel_100 = 100
}transmitter_channel;

/**
 * \brief Initialize hc-12 transmitter.
 * \return Returns 'true' if hc-12 module has initialized, otherwise returns 'false'.
 */
bool hc12_init(void);

/**
 * \brief Check if hc-12 module is available.
 * \return Returns 'true' if hc-12 module is available, otherwise returns 'false'.
 */
bool hc12_send_ping(void);

/**
 * \brief Send byte using hc-12 transmitter.
 * \param data Data.
 */
void hc12_send_byte(uint8_t data);

/**
 * \brief Set transmission mode.
 * \param m Transmission mode.
 * \return Returns 'true' if transmission mode has changed successfully, otherwise returns 'false'.
 */
bool hc12_set_transmission_mode(transmitter_mode m);

/**
 * \brief Get actual hc-12 transmission mode.
 * \return Returns actual hc-12 transmission mode.
 */
transmitter_mode hc12_get_transmission_mode(void);

/**
 * \brief Set channel #.
 * \param ch Channel.
 * \return Returns 'true' if channel # has changed successfully, otherwise returns 'false'.
 */
bool hc12_set_channel(transmitter_channel ch);

/**
 * \brief Get channel #.
 * \return Returns actual hc-12 channel #.
 */
transmitter_channel hc12_get_channel(void);

/**
 * \brief Set hc-12 transmission power.
 * \param pwr Power level.
 * \return Returns 'true' if hc-12 transmission power has changed successfully, otherwise returns 'false'.
 */
bool hc12_set_power(transmitter_power pwr);

/**
 * \brief Get actual hc-12 transmission power.
 * \return Returns actual hc-12 transmission power.
 */
transmitter_power hc12_get_power(void);

/**
 * \brief Set hc-12 transmission speed.
 * \param br Transmission baudrate.
 * \return Returns 'true' if baudrate has changed successfully, otherwise returns 'false'.
 */
bool hc12_set_baudrate(transmitter_speed br);

/**
 * \brief Get actual hc-12 transmission speed.
 * \return Returns actual hc-12 transmission speed.
 */
transmitter_speed hc12_get_baudrate(void);

#endif
