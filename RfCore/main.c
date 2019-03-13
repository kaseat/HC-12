#include "kernel.h"
#include "hc-12.h"


int main(void)
{
	kernel_init();
	hc12_init();
	hc12_set_baudrate(baudrate_1200);

	while (1)
	{
		//hc12_send_byte(0x55);
		//delay(1000);
	}
}
