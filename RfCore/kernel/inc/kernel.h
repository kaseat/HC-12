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

#ifndef __KERNEL__
#define __KERNEL__
#include <stdint.h>

/**
 * \brief Init MCU kernel.
 */
void kernel_init();

/**
 * \brief Returns number of milliseconds from MCU start.
 * \return number of milliseconds from MCU start.
 */
uint32_t millis();

/**
 * \brief delay function.
 * \param ms delay duration.
 */
void delay(uint32_t ms);

#endif
