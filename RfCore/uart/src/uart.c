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

#include "uart.h"
#include "STM8S003F3.h"
#include "platform.h"
#include "clock.h"
#include <string.h>

static void(*reception_handler) (uint8_t) = 0;
static uint32_t actual_baudrate;

void uart_init(uint32_t baudrate)
{
	// Configure GPIOs
	GPIOD->ODR |= 1 << 5;
	GPIOD->DDR |= 1 << 5;
	GPIOD->DDR &= ~(1 << 6);
	GPIOD->CR1 &= ~(1 << 6);
	GPIOD->CR2 &= ~(1 << 6);

	// Baudrate configuration.
	uart_set_baudrate(baudrate);

	// UART configuration.
	UART1->CR1 = 0;
	UART1->CR2 = UART_CR2_TEN | UART_CR2_REN;
	UART1->CR3 = 0;
}

void uart_set_baudrate(uint32_t baudrate)
{
	actual_baudrate = baudrate;
	const uint32_t brr = get_cpu_freq() / baudrate;
	UART1->BRR2 = brr & 0x000F;
	UART1->BRR2 |= (brr >> 8) & 0x00F0;
	UART1->BRR1 = (brr >> 4) & 0x00FF;
}

uint32_t uart_get_baudrate()
{
	return actual_baudrate;
}

void uart_send_byte(uint8_t data)
{
	while (!(UART1->SR & UART_SR_TXE))
		;
	UART1->DR = data;
}

void uart_send_data(uint8_t* data, uint8_t len)
{
	while (len--) uart_send_byte(*data++);
}

void uart_send_string(char* s)
{
	uart_send_data((uint8_t*)s, strlen(s));
}

void uart_subscribe_byte_reception(void(*handler) (uint8_t))
{
	reception_handler = handler;
	UART1->CR2 |= UART_CR2_RIEN;
}

void uart_unsubscribe_byte_reception()
{
	reception_handler = 0;
	UART1->CR2 |= UART_CR2_RIEN;
}

#pragma vector = UART1_R_RXNE_ISR
__interrupt void uart_byte_received()
{
	if (reception_handler != 0)
		reception_handler(UART1->DR);
}