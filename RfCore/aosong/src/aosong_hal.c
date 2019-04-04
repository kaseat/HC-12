#include "aosong_hal.h"
#include "STM8S003F3.h"
#include "platform.h"

void aosong_set_sensor_pin_low()
{
	SENSOR_PORT->ODR &= ~(1 << SENSOR_PIN);
}

void aosong_set_sensor_pin_as_input_pullup()
{
	SENSOR_PORT->DDR &= ~(1 << SENSOR_PIN);
	SENSOR_PORT->CR1 |= 1 << SENSOR_PIN;
}

void aosong_set_sensor_pin_as_output_push_pull()
{
	SENSOR_PORT->CR1 &= ~(1 << SENSOR_PIN);
	SENSOR_PORT->DDR |= 1 << SENSOR_PIN;
}

bool aosong_sensor_pin_is_high()
{
	return SENSOR_PORT->IDR & (1 << SENSOR_PIN);
}

void aosong_enable_irq()
{
	__enable_interrupts();
}

void aosong_disable_irq()
{
	__disable_interrupts();
}

void aosong_delay_us(const uint16_t us)
{
	__delay_us(us);
}

void aosong_wait_for_sensor_pin_high()
{
	uint16_t counter = 0;
	while (!(SENSOR_PORT->IDR & (1 << SENSOR_PIN)))
	{
		if(counter++ >0xFFF)
		{
			break;
		}
	}
}

void aosong_wait_for_sensor_pin_low()
{
	uint16_t counter = 0;
	while (SENSOR_PORT->IDR & (1 << SENSOR_PIN))
	{
		if(counter++ >0xFFF)
		{
			break;
		}
	}
}
