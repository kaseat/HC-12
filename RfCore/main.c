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
	while (1)
	{
		delay(5000);
		if(aosong_read_sensor() == aosong_ok)
		{
			uint32_t temp = aosong_get_raw_data();
			//uart_send_data((uint8_t*)&temp, 4);
			uint32_t t = temp;
		}
	}
}