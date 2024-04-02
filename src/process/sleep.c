// SPDX-License-Identifier: BSD-3-Clause

#include <internal/syscall.h>
#include <stdlib.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
	struct timespec t1, t2;
	t1.tv_sec = seconds;
	t1.tv_nsec = 0;

	t2.tv_nsec = 0;
	t2.tv_sec = 0;

	while (nanosleep(&t1, &t2) == -1 && t2.tv_sec > 0) {
		t1 = t2;
		t2.tv_sec = 0;
		t2.tv_nsec = 0;
	}
	return 0;
}
