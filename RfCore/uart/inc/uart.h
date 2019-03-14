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

#ifndef __UART__
#define __UART__

#include <stdint.h>

/**
* \brief Initialize UART with specified baud rate and cpu frequency.
* \param baudrate Target baud rate.
*/
void uart_init(uint32_t baudrate);

/**
 * \brief Set transmission speed.
 * \param baudrate Baudrate.
 */
void uart_set_baudrate(uint32_t baudrate);

/**
 * \brief Get actual baudrate.
 * \return Returns transmitter baudrate.
 */
uint32_t uart_get_baudrate(void);

/**
* \brief Send byte through the UART.
* \param data Data to be sent.
*/
void uart_send_byte(uint8_t data);

/**
* \brief Send byte array through the UART.
* \param data Byte array pointer.
* \param len Number of bytes to send.
*/
void uart_send_data(uint8_t* data, uint8_t len);

/**
* \brief Send null terminated string to UART.
* \param s Null terminated string.
*/
void uart_send_string(char* s);

/**
* \brief Add callback function on byte received.
* \param handler Callback function.
*/
void uart_subscribe_byte_reception(void(*handler) (uint8_t));

/**
 * \brief Remove callback function on byte received.
 */
void uart_unsubscribe_byte_reception();

#endif
