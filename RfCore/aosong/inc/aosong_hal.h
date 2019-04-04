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

#ifndef __AOSONG_HAL__
#define __AOSONG_HAL__

#include <stdbool.h>
#include "clock.h"

#define SENSOR_PORT GPIOD
#define SENSOR_PIN 4

/**
 * \brief Interface. Set aosong sensor pin low.
 */
inline void aosong_set_sensor_pin_low(void);

/**
 * \brief Interface. Set aosong sensor pin as input pullup.
 */
inline void aosong_set_sensor_pin_as_input_pullup(void);

/**
 * \brief Interface. Set aosong sensor pin as output push-pull.
 */
inline void aosong_set_sensor_pin_as_output_push_pull(void);

/**
 * \brief Check whether sensor pin is high.
 * \return Returns true if sensor pin is high, otherwise returns false.
 */
inline bool aosong_sensor_pin_is_high(void);

/**
 * \brief Enable interrupts.
 */
inline void aosong_enable_irq(void);

/**
 * \brief Disable interrupts.
 */
inline void aosong_disable_irq(void);

/**
 * \brief Delay us.
 * \param us Delay, us.
 */
inline void aosong_delay_us(const uint16_t us);

/**
 * \brief Wait until sensor pin is high (timeout recommended).
 */
inline void aosong_wait_for_sensor_pin_high(void);

/**
 * \brief Wait until sensor pin is low (timeout recommended).
 */
inline void aosong_wait_for_sensor_pin_low(void);

#endif
