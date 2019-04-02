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

#pragma once

#ifdef __ICCSTM8__
#define __enable_interrupts() asm("RIM")
#define __disable_interrupts() asm("SIM")
#define __no_operation() asm("NOP")
#else
#define __interrupt
#define __enable_interrupts()
#define __disable_interrupts()
#define __no_operation()
#endif