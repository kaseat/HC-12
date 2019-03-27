#include "kernel.h"
#include "hc-12.h"
#include "STM8S003F3.h"
#include "platform.h"
#include "clock.h"

int main(void)
{
	kernel_init();
	//hc12_init();
	//
	//bool res = hc12_set_transmission_mode(transmitter_fu3);
	//res = hc12_set_channel(channel_001);
	//res = hc12_set_baudrate(baudrate_9600);
	//res = hc12_set_power(power_5);

	//transmitter_speed s = hc12_get_baudrate();
	//transmitter_channel c = hc12_get_channel();
	//transmitter_power p = hc12_get_power();
	//transmitter_mode m = hc12_get_transmission_mode();
        GPIOD->DDR = 1 << 3;
        GPIOD->CR1 = 1 << 3;
        GPIOD->CR2 = 1 << 3;
	while (1)
	{
		__delay_us(2);
		GPIOD->ODR ^= 1 << 3;
		//res = hc12_set_power(power_11);
		//delay(1000);
	}
}