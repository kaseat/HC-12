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
	EXTERN ?sll16_x_x_a
        
	PUBLIC __delay_cycles
	PUBLIC __delay_us

	SECTION `.far_func.text`:CODE:REORDER:NOROOT(0)
	CODE

__delay_us:
        LD A, actual_freq_delay ; 1
        CALL ?sll16_x_x_a
        CALL __delay_cycles
	RET
        
	SECTION `.far_func.text`:CODE:REORDER:NOROOT(0)
	CODE

// Min delay 14 cycles
__delay_cycles:
	SUBW X, #0x0D
__delay_cycles_cycle:
	DECW X
	JRNE __delay_cycles_cycle
	RET

	SECTION VREGS:DATA:REORDER:NOROOT(0)
	END
