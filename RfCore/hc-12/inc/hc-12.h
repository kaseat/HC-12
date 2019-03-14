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
	transmitter_fu1 = '1',
	transmitter_fu2 = '2',
	transmitter_fu3 = '3',
	transmitter_fu4 = '4'
}transmitter_mode;

typedef enum
{
	power_0 = '1',
	power_2 = '2',
	power_5 = '3',
	power_8 = '4',
	power_11 = '5',
	power_14 = '6',
	power_17 = '7',
	power_20 = '8'
} power_levels;

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
}transmission_speed;

/**
 * \brief Initialize hc-12 transmitter.
 */
void hc12_init(void);


/**
 * \brief Check if hc-12 module is available.
 * \return Returns 'true' if hc-12 module is available, otherwise returns 'false'.
 */
bool hc12_send_ping(void);


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
bool hc12_set_channel(uint8_t ch);

/**
 * \brief Get channel #.
 * \return Returns actual hc-12 channel #.
 */
uint8_t hc12_get_channel(void);

/**
 * \brief Send byte using hc-12 transmitter. 
 * \param data Data.
 */
void hc12_send_byte(uint8_t data);

/**
 * \brief Set hc-12 transmission speed.
 * \param br Transmission baudrate.
 * \return Returns 'true' if baudrate has changed successfully, otherwise returns 'false'.
 */
bool hc12_set_baudrate(transmission_speed br);

/**
 * \brief Get actual hc-12 transmission speed.
 * \return Returns actual hc-12 transmission speed.
 */
transmission_speed hc12_get_baudrate(void);

/**
 * \brief Set hc-12 transmission power.
 * \param pwr Power level.
 * \return Returns 'true' if hc-12 transmission power has changed successfully, otherwise returns 'false'.
 */
bool hc12_set_power(power_levels pwr);

/**
 * \brief Get actual hc-12 transmission power.
 * \return Returns actual hc-12 transmission power.
 */
power_levels hc12_get_power(void);

#endif
