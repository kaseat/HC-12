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
	power_0 = 0x31,
	power_2 = 0x32,
	power_5 = 0x33,
	power_8 = 0x34,
	power_11 = 0x35,
	power_14 = 0x36,
	power_17 = 0x37,
	power_20 = 0x38
}power_levels;

typedef enum
{
	baudrate_1200 = 0,
	baudrate_2400 = 4,
	baudrate_4800 = 8,
	baudrate_9600 = 12,
	baudrate_19200 = 16,
	baudrate_38400 = 20,
	baudrate_57600 = 24,
	baudrate_115200 = 28,
}transmission_speed;

/**
 * \brief Initialize hc-12 transmitter.
 */
void hc12_init(void);

/**
 * \brief Send byte using hc-12 transmitter. 
 * \param data Data.
 */
void hc12_send_byte(uint8_t data);

/**
 * \brief Check if hc-12 module is available.
 * \return Returns 'true' if hc-12 module is available, otherwise returns 'false'.
 */
bool hc12_send_ping(void);

/**
 * \brief Set hc-12 transmission speed.
 * \param br Transmission baudrate.
 * \return Returns 'true' if baudrate has changed successfully, otherwise returns 'false'.
 */
bool hc12_set_baudrate(transmission_speed br);

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
