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

#ifndef __STM8_CLOCK__
#define __STM8_CLOCK__
#include <stdint.h>

typedef enum 
{
	cpu_freq_2_mhz = 2000000U,
	cpu_freq_4_mhz = 4000000U,
	cpu_freq_8_mhz = 8000000U,
	cpu_freq_16_mhz = 16000000U
} cpu_freq;

/**
 * \brief Get current CPU frequency.
 * \return Returns current CPU frequency.
 */
cpu_freq get_cpu_freq();

/**
 * \brief Set CPU frequency.
 * \param freq Frequency we wanna set.
 */
void set_cpu_freq(cpu_freq freq);

/**
 * \brief Delay us.
 * \param us Delay, us.
 */
extern void __delay_us(uint16_t us);

#endif
