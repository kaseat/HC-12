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

#ifndef __HC_12_HAL__
#define __HC_12_HAL__

#include <stdint.h>

/**
 * \brief Interface. Delay function.
 * \param ms Delay duration.
 */
void hc12_delay(uint32_t ms);

/**
 * \brief Interface. Returns number of milliseconds.
 * \return Number of milliseconds.
 */
uint32_t hc12_millis(void);

/**
 * \brief Interface. Set hc-12 configuration pin low.
 */
void hc12_set_cfg_pin_low(void);

/**
 * \brief Interface. Set hc-12 configuration pin high.
 */
void hc12_set_cfg_pin_hi(void);

/**
* \brief Initialize data transfer interface.
* \param baudrate Target baud rate.
*/
void hc12_transmitter_init(uint32_t baudrate);

/**
 * \brief Data transfer interface. Set transmission speed.
 * \param baudrate Baudrate.
 */
void hc12_transmitter_set_baudrate(uint32_t baudrate);

/**
 * \brief Data transfer interface. Get actual baudrate.
 * \return Returns transmitter baudrate.
 */
uint32_t hc12_transmitter_get_baudrate(void);

/**
* \brief Data transfer interface. Send byte.
* \param data Data to be sent.
*/
void hc12_transmitter_send_byte(uint8_t data);

/**
* \brief Data transfer interface. Send null terminated string.
* \param s Null terminated string.
*/
void hc12_transmitter_send_string(char* s);

/**
* \brief Data transfer interface. Add callback function on byte received.
* \param handler Callback function.
*/
void hc12_transmitter_subscribe_byte_reception(void(*handler) (uint8_t));

#endif
