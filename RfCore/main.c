#include "kernel.h"
#include "hc-12.h"

int main(void)
{
	kernel_init();
	hc12_init();
	
	bool res = hc12_set_transmission_mode(transmitter_fu3);
	res = hc12_set_channel(channel_001);
	res = hc12_set_baudrate(baudrate_9600);
	res = hc12_set_power(power_5);

	transmitter_speed s = hc12_get_baudrate();
	transmitter_channel c = hc12_get_channel();
	transmitter_power p = hc12_get_power();
	transmitter_mode m = hc12_get_transmission_mode();
	while (1)
	{
		//res = hc12_set_power(power_11);
		//delay(1000);
	}
}
