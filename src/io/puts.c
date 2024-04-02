// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int puts(const char *str)
{
	char *s = (char *)str;
	int len = 0;
	while(*s) {
		len++;
		s++;
	}

	int bytes_write = write(1, str, len);
	bytes_write += write(1, "\n", 1);

	return bytes_write;
}
