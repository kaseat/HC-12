// Copyright 2019 Oleg Petrochenko
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef __AOSOSNG__
#define __AOSOSNG__

#include <stdint.h>

	typedef enum { aosong_ok = 0x30, aosong_no_response = 0x31, aosong_invalid_checksum = 0x32 } aosong_status;
	aosong_status aosong_read_sensor(void);
	uint32_t aosong_get_raw_data(void);
	int16_t aosong_get_temperature(void);
	int16_t aosong_get_humidity(void);

#endif
