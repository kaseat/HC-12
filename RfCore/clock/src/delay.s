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

	NAME delay
	EXTERN actual_freq_delay

	PUBLIC __delay_us

	#define f16mhz 0x02
	#define adj_cycle 0x06

	SECTION `.far_func.text`:CODE:REORDER:NOROOT(0)
	CODE

__delay_us:
	LD A, actual_freq_delay
	JRMI __delay_us_divide_2
	JREQ __delay_us_begin
	SLLW X
	CP A, #f16mhz
	JRNE __delay_us_begin
	SLLW X
	JRA __delay_us_begin
__delay_us_divide_2:
	SRLW X
__delay_us_begin:
	SUBW X, #adj_cycle
__delay_us_cycles_c:
	NOP
	DECW X
	JRNE __delay_us_cycles_c
	RET

	SECTION VREGS:DATA:REORDER:NOROOT(0)
	END
