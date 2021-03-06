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

#include "helpers.h"
#include <string.h>

void reverse(char* s)
{
	for (int i = 0, j = strlen(s) - 1; i < j; i++, j--)
	{
		const char c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

void itoa_(uint32_t n, char* s)
{
	uint32_t  i = 0;
	do
	{
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	s[i] = '\0';
	reverse(s);
}
