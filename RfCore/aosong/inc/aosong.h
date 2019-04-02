#ifndef __AOSOSNG__
#define __AOSOSNG__

#include <stdint.h>

	typedef enum { aosong_ok = 0x30, aosong_no_response = 0x31, aosong_invalid_checksum = 0x32 } aosong_status;
	aosong_status aosong_read_sensor(void);
	uint32_t aosong_get_raw_data(void);
	uint_fast16_t aosong_get_temperature(void);
	uint_fast16_t aosong_get_humidity(void);
	uint32_t aosong_get_temperature_ascii(void);
	uint32_t aosong_get_humidity_ascii(void);

#endif
