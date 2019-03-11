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

#include "clock.h"
#include "STM8S003F3.h"

static cpu_freq actual_freq = cpu_freq_2_mhz;

cpu_freq get_cpu_freq()
{
	return actual_freq;
}

void set_cpu_freq(const cpu_freq freq)
{
	actual_freq = freq;
	switch (freq)
	{
	case cpu_freq_2_mhz:
		CLK->CKDIVR = 3;
		break;
	case cpu_freq_4_mhz:
		CLK->CKDIVR = 2;
		break;
	case cpu_freq_8_mhz:
		CLK->CKDIVR = 1;
		break;
	case cpu_freq_16_mhz:
		CLK->CKDIVR = 0;
		break;
	default:
		break;
	}
}