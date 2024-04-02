// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	int err = syscall(__NR_close, fd);

	if (err < 0) {
		return -1;
	}
	return err;
}
