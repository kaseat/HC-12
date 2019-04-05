#include "kernel.h"
#include "aosong.h"
#include "hc-12.h"

int main(void)
{
	kernel_init();
	hc12_init();

	while (1)
	{
		delay(5000);
		if(aosong_read_sensor() == aosong_ok)
		{
			uint32_t sensor_raw_data = aosong_get_raw_data();
			hc12_send_data((uint8_t*)& sensor_raw_data, 4);
		}
	}
}