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

#include "kernel.h"
#include "STM8S003F3.h"
#include "platform.h"
#include "clock.h"

#define ARR_VAL 0x7C
#define PRSC_VAL 0x07

volatile static uint32_t counter;

void kernel_init()
{
	counter = 0;

	set_cpu_freq(cpu_freq_16_mhz);

	// Set TIM4 overflow interrupt every 1 ms.
	// This values calculated for 16 MHz clock.
	//TIM4->ARR = ARR_VAL;
	//TIM4->PSCR = PRSC_VAL;

	// Enable overflow interrupts and run the timer.
	//TIM4->IER = TIM4_IER_UIE;
	//TIM4->CR1 = TIM4_CR1_CEN;

	__enable_irq();
}

#pragma vector = TIM4_OVR_UIF_ISR
__interrupt void OnTim4Overflow(void)
{
	TIM4->SR = 0;
	counter++;
}

uint32_t millis()
{
	return counter;
}

void delay(uint32_t ms)
{
	const uint32_t current = counter;
	while (counter - current < ms) {}
}