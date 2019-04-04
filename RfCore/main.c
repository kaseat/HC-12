#include "kernel.h"
#include "aosong.h"
#include "uart.h"
#include "STM8S003F3.h"

int main(void)
{
	kernel_init();
	//uart_init(9600);
	GPIOD->DDR = 1 << 3;
	GPIOD->CR1 = 1 << 3;
	GPIOD->CR2 = 1 << 3;
	GPIOD->ODR |= 1 << 3;
	while (1)
	{
		delay(5000);
		if(aosong_read_sensor() == aosong_ok)
		{
			uint32_t temp = aosong_get_raw_data();
			uint16_t h = aosong_get_humidity();
			uint16_t t = aosong_get_temperature();
			//uart_send_data((uint8_t*)&temp, 4);
			uint32_t ts = temp;
			uint32_t ts2 = h;
			uint32_t ts3 = t;
		}
	}
}