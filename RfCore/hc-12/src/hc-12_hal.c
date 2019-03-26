#include "hc-12_hal.h"
#include "STM8S003F3.h"
#include "uart.h"
#include "kernel.h"

#define CFG_PORT GPIOD
#define CFG_PIN 4

void hc12_delay(uint32_t ms)
{
	delay(ms);
}

uint32_t hc12_millis()
{
	return millis();
}

void hc12_set_cfg_pin_low()
{
	CFG_PORT->DDR |= 1 << CFG_PIN;
}

void hc12_set_cfg_pin_hi()
{
	CFG_PORT->DDR &= ~(1 << CFG_PIN);
}

void hc12_transmitter_init(const uint32_t baudrate)
{
	uart_init(baudrate);
}

void hc12_transmitter_set_baudrate(const uint32_t baudrate)
{
	uart_set_baudrate(baudrate);
}

uint32_t hc12_transmitter_get_baudrate()
{
	return uart_get_baudrate();
}

void hc12_transmitter_send_byte(const uint8_t data)
{
	uart_send_byte(data);
}

void hc12_transmitter_send_string(char* s)
{
	uart_send_string(s);
}

void hc12_transmitter_subscribe_byte_reception(void(* handler)(uint8_t))
{
	uart_subscribe_byte_reception(handler);
}
