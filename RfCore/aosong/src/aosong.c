#include "aosong.h"
#include "clock.h"
#include "platform.h"

//================================================================================
//                  Aosong tempertaure/humidity sesors protocol
//================================================================================
//          Tbe      Tgo   Trel      Treh    Tlow  Th0  Tlow    Th1    Ten
// ___               ___           ________        ___        _______        ____
//    \____________ /   \________ /        \_____ /   \_____ /       \_____ /
//================================================================================
#define Tbe 800
#define Tgo (30+10)
#define Trel 80
#define Treh 80
#define Tlow 50
#define Th0 (26+10)
#define Th1 70
#define Ten 50

//================================================================================
//                           Aosong sensor data map
//              hhhh hhhh hhhh hhhh tttt tttt tttt tttt cccc cccc
// h - humidity bit
// t - temperature bit
// c - checksum bit
//================================================================================
#define TEMPERATURE_OFFSET 8
#define HUMIDITY_OFFSET 24
#define NEGATIVE_TEMPERATURE_BIT 0x8000
#define pin_state(port, pin) ((port)->IDR >> (pin) & 1)

typedef enum { pin_high = 0, pin_low = 1 } required_state;
static void wait_for_pin_state(required_state state, GpioPort* port, GpioPin pin);
uint_fast32_t bin2_ascii(uint_fast16_t input);
static uint64_t aosong_sensor_raw_data;

aosong_status aosong_read_sensor()
{
	GpioPinConfig(port, pin, GpioModeGpoPushPullLowSpeed);
	GpioPinWrite(port, pin, GpioValueLo);
	__delay_us(Tbe);

	__disable_interrupts();
	GpioPinConfig(port, pin, GpioModeInputPullUp);

	__delay_us(Tgo);

	if (pin_state(port, pin))
	{
		__enable_interrupts();
		return aosong_no_response;
	}

	wait_for_pin_state(pin_high, port, pin);

	for (uint_fast8_t t = 0; t < 40; t++)
	{
		wait_for_pin_state(pin_low, port, pin);
		wait_for_pin_state(pin_high, port, pin);
		__delay_us(Th0);
		aosong_sensor_raw_data <<= 1;
		if (pin_state(port, pin))
			aosong_sensor_raw_data |= 1;
	}

	__enable_interrupts();

	uint8_t* d_pt = (uint8_t*)&aosong_sensor_raw_data;
	if (*d_pt != (uint8_t)(d_pt[1] + d_pt[2] + d_pt[3] + d_pt[4]))
		return aosong_invalid_checksum;

	return aosong_ok;
}

void wait_for_pin_state(required_state state, GpioPort* port, GpioPin pin)
{
	uint32_t timeout_counter = 0;
	while (pin_state(port, pin) == state)
	{
		timeout_counter++;
		if (timeout_counter > TIMEOUT)
			return;
	}
}

uint32_t aosong_get_raw_data()
{
	return aosong_sensor_raw_data >> 8;
}

uint_fast16_t aosong_get_temperature(void)
{
	uint8_t* ptr = (uint8_t*)&aosong_sensor_raw_data;
	return *(ptr + 2) << 8 | *(ptr + 1);
}

uint_fast16_t aosong_get_humidity(void)
{
	uint8_t* ptr = (uint8_t*)&aosong_sensor_raw_data;
	return *(ptr + 4) << 8 | *(ptr + 3);
}

uint32_t aosong_get_temperature_ascii(void)
{
	const uint_fast16_t input = aosong_sensor_raw_data >> TEMPERATURE_OFFSET;
	if ((input & NEGATIVE_TEMPERATURE_BIT) != 0)
		return 0;
	return bin2_ascii(input);
}

uint32_t aosong_get_humidity_ascii(void)
{
	const uint_fast16_t input = aosong_sensor_raw_data >> HUMIDITY_OFFSET;
	return bin2_ascii(input);
}

uint_fast32_t bin2_ascii(uint_fast16_t input)
{
	uint8_t rArr[4];
	uint32_t* rPtr = (uint32_t*)rArr;
	input = (uint16_t)input;
	*rPtr = input / 100;
	input -= *rPtr * 100;
	rArr[1] = input / 10;
	input -= rArr[1] * 10;
	rArr[3] = input;
	*rPtr |= 0x302E3030;
	return *rPtr;
}
